classdef MotorControl < handle
    properties
        serial_
        motors_map
        send_data_frame
        Limit_param
        data_save
    end
    
    methods
        function obj = MotorControl(COM, baudrate)

            obj.motors_map = containers.Map('KeyType','uint32', 'ValueType','any');
            obj.data_save = [];
            %限制参数     PMAX VMAX TMAX  行为所代表的不同电机
            obj.Limit_param=[12.5,30,10; %DM4310
                         12.5,50,10; %DM4310_48V
                         12.5,8,28;  %DM4340
                         12.5,10,28; %DM4340_48V
                         12.5,45,20; %DM6006
                         12.5,45,40; %DM8006
                         12.5,45,54; %DM8009
                         12.5,25,200;%DM10010L
                         12.5,20,200;%DM10010
                         12.5,280,1; %H3510
                         12.5,45,10; %DMG6215
                         12.5,45,10; %DMH6220
                         ];
            obj.serial_ = serialport(COM,baudrate,"Timeout",0.5);
            obj.send_data_frame = uint8([0x55, 0xAA, 0x1e, 0x03, 0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0, 0, 0, 0, 0x00, 0x08, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0x00]);
            flush(obj.serial_);
        end
        
        function delete(obj)
            delete(obj.serial_)
        end 

        function controlMIT(obj, DM_Motor, kp, kd, q, dq, tau)
            % MIT Control Mode Function
            if ~isKey(obj.motors_map, DM_Motor.SlaveID)
                disp('Motor ID not found');
                return;
            end
            kp_uint = obj.float_to_uint(kp, 0, 500, 12);
            kd_uint = obj.float_to_uint(kd, 0, 5, 12);
            MotorType = DM_Motor.MotorType;
            q_uint = obj.float_to_uint(q, -obj.Limit_param(MotorType,1), obj.Limit_param(MotorType,1), 16);
            dq_uint = obj.float_to_uint(dq, -obj.Limit_param(MotorType,2), obj.Limit_param(MotorType,2), 12);
            tau_uint = obj.float_to_uint(tau, -obj.Limit_param(MotorType,3), obj.Limit_param(MotorType,3), 12);
            data_buf = uint8(zeros(1,8));
            data_buf(1) = bitand(bitshift(q_uint, -8),255);
            data_buf(2) = bitand(q_uint,255);
            data_buf(3) = bitshift(dq_uint, -4);
            data_buf(4) = bitor(bitshift(bitand(dq_uint, 15), 4),bitand(bitshift(kp_uint, -8), 15));
            data_buf(5) = bitand(kp_uint,255);
            data_buf(6) = bitshift(kd_uint, -4);
            data_buf(7) = bitor(bitshift(bitand(kd_uint, 15), 4), bitand(bitshift(tau_uint, -8), 15));
            data_buf(8) = bitand(tau_uint,255);
            obj.send_data(DM_Motor.SlaveID,data_buf);
            obj.recv();
        end
        
        
        function control_Pos_Vel(obj, Motor, P_desired, V_desired)
            % Control the motor in position and velocity control mode
            if ~isKey(obj.motors_map, Motor.SlaveID)
                disp('Motor ID not found');
                return;
            end
            temp_id=hex2dec('100')+Motor.SlaveID;% vel pos control need 0x100+canid
            data_buf = uint8(zeros(1, 8));
            P_desired_uint8s = obj.float_to_uint8s(P_desired);
            V_desired_uint8s = obj.float_to_uint8s(V_desired);
            data_buf(1:4) = P_desired_uint8s;
            data_buf(5:8) = V_desired_uint8s;
            obj.send_data(temp_id,data_buf);
            obj.recv();
        end

        function control_Vel(obj, Motor, Vel_desired)
            % control the motor in velocity control mode 电机速度控制模式
            % :param Motor: Motor object 电机对象
            % :param Vel_desired: desired velocity 期望速度
            if ~isKey(obj.motors_map, Motor.SlaveID)
                disp('Motor ID not found');
                return;
            end
            temp_id=hex2dec('200')+Motor.SlaveID; %vel control need 0x200+canid
            data_buf = uint8(zeros(1, 8));
            Vel_desired_uint8s = obj.float_to_uint8s(Vel_desired);
            data_buf(1:4) = Vel_desired_uint8s;
            obj.send_data(temp_id,data_buf);
            obj.recv(); % receive the data from serial port
        end
        
        function control_pos_force(obj, Motor, Pos_des, Vel_des, i_des)
            % control the motor in EMIT control mode 电机力位混合模式
            % :param Pos_des: desired position rad 期望位置 单位为rad
            % :param Vel_des: desired velocity rad/s 期望速度 为放大100倍
            % :param i_des: desired current rang 0-10000 期望电流标幺值放大10000倍
            % 电流标幺值：实际电流值除以最大电流值，最大电流见上电打印
            if ~isKey(obj.motors_map, Motor.SlaveID)
                disp('Motor ID not found');
                return;
            end
            temp_id=hex2dec('300')+Motor.SlaveID; %pos force model is 0x300
            data_buf = uint8(zeros(1, 8));
            Pos_desired_uint8s = obj.float_to_uint8s(Pos_des);
            data_buf(1:4) = Pos_desired_uint8s;
            Vel_uint = uint16(Vel_des);
            ides_uint = uint16(i_des);
            data_buf(5) = bitand(Vel_uint, 255);
            data_buf(6) = bitshift(Vel_uint, -8);
            data_buf(7) = bitand(ides_uint, 255);
            data_buf(8) = bitshift(ides_uint, -8);
            obj.send_data_frame(22:29) = data_buf;
            obj.send_data(temp_id,data_buf);
            obj.recv(); % receive the data from serial port
        end
        
        function enable(obj, Motor)
            % enable motor 使能电机
            % 最好在上电后几秒后再使能电机
            % :param Motor: Motor object 电机对象
            obj.control_cmd(Motor, uint8(0xFC));
            pause(0.1);
            obj.recv();
        end

        function enable_old(obj,Motor,ControlMode)
            % enable motor for old motor version 使能电机针对低版本固件的
            % 最好在上电后几秒后再使能电机
            % :param Motor: Motor object 电机对象
            data_buf = uint8([0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, cmd]);
            motor_id=bitshift(uint32(ControlMode)-1,2)+Motor.SlaveID;
            obj.send_data(motor_id,data_buf);
            pause(0.1);
            obj.recv();
        end
        
        function disable(obj, Motor)
            % disable motor 失能电机
            % :param Motor: Motor object 电机对象
            obj.control_cmd(Motor, uint8(0xFD));
            pause(0.1);
            obj.recv();
        end
        
        function set_zero_position(obj, Motor)
            % set the zero position of the motor 设置电机0位
            % :param Motor: Motor object 电机对象
            obj.control_cmd(Motor, uint8(0xFE));
            pause(0.1);
            obj.recv();
        end
        
        function recv(obj)
            read_num=obj.serial_.NumBytesAvailable;
            if read_num ~=0
                data_recv = [obj.data_save,read(obj.serial_, read_num ,"uint8")];
                packets = obj.extract_packets(data_recv);
                for i = 1:length(packets)
                    packet = packets{i};
                    data = packet(8:15);
                    CANID = bitor(bitshift(uint32(packet(7)), 24), bitor(bitshift(uint32(packet(6)), 16), bitor(bitshift(uint32(packet(5)), 8), uint32(packet(4)))));
                    CMD = packet(2);
                    obj.process_packet(data, CANID, CMD);
                end
            end
        end

        
        function addMotor(obj, Motor)
            % add motor to the motor control object 添加电机到电机控制对象
            % :param Motor: Motor object 电机对象
            obj.motors_map(Motor.SlaveID) = Motor;
            if Motor.MasterID ~= 0
                obj.motors_map(Motor.MasterID) = Motor;
            end
        end
        
        function read_RID_param(obj, Motor, RID)
            data_buf = uint8([uint8(Motor.SlaveID), 0, 51, uint8(RID), 0, 0, 0, 0]);
            obj.send_data(0x7FF,data_buf);
            pause(0.01);
        end

        function param = read_motor_param(obj, Motor, RID)
            % read only the RID of the motor 读取电机的内部信息例如 版本号等
            % :param Motor: Motor object 电机对象
            % :param RID: DM_variable 电机参数
            % :return: 电机参数的值
        
            obj.read_RID_param(Motor, uint8(RID));
            pause(0.1);
            obj.recv_set_param_data();
            Can_id=uint32(Motor.SlaveID);
            if isKey(obj.motors_map, Can_id)
               param=obj.motors_map(Can_id).getParam(uint8(RID));
            else
                param = [];
            end
        end
        
        function recv_set_param_data(obj)
            read_num=obj.serial_.NumBytesAvailable;
            if read_num ~=0
                data_recv = [obj.data_save,read(obj.serial_, read_num ,"uint8")];
                packets = obj.extract_packets(data_recv);
                for i = 1:length(packets)
                    packet = packets{i};
                    data = packet(8:15);
                    CANID = bitor(bitshift(uint32(packet(7)), 24), bitor(bitshift(uint32(packet(6)), 16), bitor(bitshift(uint32(packet(5)), 8), uint32(packet(4)))));
                    CMD = packet(2);
                    obj.process_set_param_packet(data, CANID, CMD);
                end
            end
        end
        
        function success = change_motor_param(obj, Motor, RID, data)
            % change the RID of the motor 改变电机的参数
            % :param Motor: Motor object 电机对象
            % :param RID: DM_variable 电机参数
            % :param data: 电机参数的值
            % :return: true or false ,true means success, false means fail
            RID_change=uint8(RID);
            max_retries = 10;
            retry_interval = 0.05; % retry times
            obj.write_motor_param(Motor, RID_change, data);
            for i = 1:max_retries
                pause(retry_interval);
                obj.recv_set_param_data();
                
                if isKey(obj.motors_map, Motor.SlaveID)
                    if abs(obj.motors_map(Motor.SlaveID).getParam(RID_change)-data)<0.1
                        success = true;
                        return;
                    else
                        success = false;
                        return;
                    end
                end
            end
        end


        function success=switchControlMode(obj, Motor, ControlMode)
            % switch the control mode of the motor 切换电机控制模式
            % :param Motor: Motor object 电机对象
            % :param ControlMode: Control_Type 电机控制模式 example:MIT:Control_Type.MIT MIT模式
            write_data = uint8([uint8(ControlMode), 0, 0, 0]);
            max_retries = 10;
            retry_interval = 0.05; % retry times
            RID = 10;
            obj.write_motor_param(Motor, RID, write_data);
            for i = 1:max_retries
                pause(retry_interval);
                obj.recv_set_param_data();
                
                if isKey(obj.motors_map, Motor.SlaveID)
                    if obj.motors_map(Motor.SlaveID).getParam(RID)==uint8(ControlMode)
                        success = true;
                        return;
                    else
                        success = false;
                        return;
                    end
                end
            end
        end

        
        function success = changeMasterID(obj, Motor, MasterID)
            % change the MasterID of the motor 改变电机主机ID
            % :param Motor: Motor object 电机对象
            % :param MasterID: MasterID 主机ID
            motorid = MasterID;
            RID=7;
            can_id_l = bitand(motorid, 255);
            can_id_h = bitshift(motorid, -8);
            max_retries = 10;
            retry_interval = 0.05; % retry times
            write_data = uint8([uint8(can_id_l), uint8(can_id_h), 0, 0]);
            obj.write_motor_param(Motor, 7, write_data);
            for i = 1:max_retries
                pause(retry_interval);
                obj.recv_set_param_data();
                
                if isKey(obj.motors_map, Motor.SlaveID)
                    if obj.motors_map(Motor.SlaveID).getParam(RID)==uint8(MasterID)
                        success = true;
                        return;
                    else
                        success = false;
                        return;
                    end
                end
            end
        end
        
        function save_motor_param(obj, Motor)
            % save the motor param to flash 保存寄存器参数进flash
            % :param Motor: Motor object 电机对象
            % :param MasterID: MasterID 主机ID

            % 获取电机的 ID 并计算 CAN 消息的高低字节
            motorid = Motor.SlaveID;
            can_id_l = bitand(motorid, 255);
            can_id_h = bitshift(motorid, -8);
            data_buf = uint8([can_id_l,can_id_h, 0xAA,1, 0, 0, 0, 0]);
            obj.send_data(0x7FF,data_buf);
            pause(0.1);
        end

        function refresh_motor_status(obj, Motor)
            % refresh_motor_status 获得电机此时的状态信息
            % :param Motor: Motor object 电机对象
            motorid = Motor.SlaveID;
            can_id_l = bitand(motorid, 255);
            can_id_h = bitshift(motorid, -8);
            data_buf = uint8([uint8(can_id_l),uint8(can_id_h), 0xCC, 0, 0, 0, 0, 0]);
            obj.send_data(0x7FF,data_buf);
            obj.recv();
        end
        
       

        function change_control_PMAX(obj,Motor_Type,new_PMAX)
            %这是修改MotorControl类中电机对应的PMAX，不修改电机内部的
            obj.Limit_param(uint32(Motor_Type),1)=new_PMAX;
        end

        function change_control_VMAX(obj,Motor_Type,new_VMAX)
            %这是修改MotorControl类中电机对应的VMAX，不修改电机内部的
            obj.Limit_param(uint32(Motor_Type),2)=new_VMAX;
        end

        function change_control_TMAX(obj,Motor_Type,new_TMAX)
            %这是修改MotorControl类中电机对应的TMAX，不修改电机内部的
            obj.Limit_param(uint32(Motor_Type),3)=new_TMAX;
        end
        
    end


    %====================================================================================================
    %下面为私有库函数
    %follow function is private
    methods (Access = private)

            function frames = extract_packets(obj,data)
                frames = {};
                header = hex2dec('AA');
                tail = hex2dec('55');
                frame_length = 16;
                i = 0;
                remainder_pos = 0;
            
                while i <= length(data) - frame_length
                    if data(i + 1) == header && data(i + frame_length) == tail
                        frame = data(i + 1:i + frame_length);
                        frames{end + 1} = frame;
                        i = i + frame_length;
                        remainder_pos = i;
                    else
                        i = i + 1;
                    end
                end
                obj.data_save=data(remainder_pos+1:end);
            end

        function uint_val = float_to_uint(obj,x, x_min, x_max, bits)
            span = x_max - x_min;
            data_norm = (x - x_min) / span;
            uint_val = uint16(data_norm * ((2^bits) - 1));
        end
        
        function float_val = uint_to_float(obj,x, min_val, max_val, bits)
            span = max_val - min_val;
            data_norm = double(x) / ((2^bits) - 1);
            float_val = single(data_norm * span + min_val);
        end
        
        function result = is_in_ranges(obj,number)
            % check if the number is in the range of uint32
            % :param number: The number to check
            % :return: true if the number is in the specified ranges, false otherwise
            if (number >= 7 && number <= 10) || (number >= 13 && number <= 16) || (number >= 35 && number <= 36)
                result = true;
            else
                result = false;
            end
        end

        function result = uint8s_to_uint32(obj,byte1, byte2, byte3, byte4)
            % Pack the four uint8 values into a single uint32 value in little-endian order
            result = uint32(byte1) + bitshift(uint32(byte2), 8) + bitshift(uint32(byte3), 16) + bitshift(uint32(byte4), 24);
        end

        function result = uint8s_to_float(obj,byte1, byte2, byte3, byte4)
            % Pack the four uint8 values into a single float value in little-endian order
            packed = typecast(uint8([byte1, byte2, byte3, byte4]), 'single');
            result = packed;
        end

        function uint8s = float_to_uint8s(obj,value)
            % Pack the float into 4 bytes
            packed = typecast(single(value), 'uint8');
            % Return the bytes as a row vector
            uint8s = reshape(packed, 1, []);
        end

        function uint8s = uint32_to_uint8s(obj,uint32_value)
            % Convert uint32 to 4 uint8 values in little-endian order
            uint8_array = typecast(uint32(uint32_value), 'uint8');
            % Ensure the array is in little-endian order
            uint8s = reshape(uint8_array, 1, []);
        end

        function send_data(obj, motorid, data)
            % send data to the motor 发送数据到电机
            % :param motorid:
            % :param data:
            % :return:
            obj.send_data_frame(14) = bitand(motorid, 255); % motorid & 0xff
            obj.send_data_frame(15) = bitshift(motorid, -8); % motorid >> 8
            obj.send_data_frame(22:29) = data;
            write(obj.serial_, obj.send_data_frame, 'uint8');
        end
        
        function process_set_param_packet(obj, data, CANID, CMD)
            if CMD == 0x11 && (data(3) == 0x33 || data(3) == 0x55)
                canid_temp = bitshift(data(2), 8) + data(1);
                canid=CANID;
                if(CANID==0)
                    canid=canid_temp;
                end

                if(~isKey(obj.motors_map, canid))
                    if(~isKey(obj.motors_map, canid_temp))
                        return;
                    else
                        canid=canid_temp;
                    end
                end

                RID = uint8(data(4));
                % 读取参数得到的数据
                if obj.is_in_ranges(RID)
                    % uint32类型
                    num_uint32 = obj.uint8s_to_uint32(data(5), data(6), data(7), data(8));
                    obj.motors_map(canid).saveParam(RID,num_uint32);
                else
                    % float类型
                    num_float = obj.uint8s_to_float(data(5), data(6), data(7), data(8));
                    obj.motors_map(canid).saveParam(RID,num_float);
                end
                
            end
        end

        function control_cmd(obj, Motor, cmd)
            data_buf = uint8([0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, cmd]);
            obj.send_data(uint16(Motor.SlaveID),data_buf);
        end


        function process_packet(obj, data, CANID, CMD)
            if CMD == 17
                if CANID ~= 0
                    if isKey(obj.motors_map, CANID)
                        q_uint = bitor(bitshift(uint16(data(2)), 8), uint16(data(3)));
                        dq_uint = bitor(bitshift(uint16(data(4)), 4), bitshift(uint16(data(5)), -4));
                        tau_uint = bitor(bitshift(bitand(uint16(data(5)), 15), 8), uint16(data(6)));
                        MotorType_recv = obj.motors_map(CANID).MotorType;
                        recv_q = obj.uint_to_float(q_uint, -obj.Limit_param(MotorType_recv,1), obj.Limit_param(MotorType_recv,1), 16);
                        recv_dq = obj.uint_to_float(dq_uint, -obj.Limit_param(MotorType_recv,2), obj.Limit_param(MotorType_recv,2), 12);
                        recv_tau = obj.uint_to_float(tau_uint, -obj.Limit_param(MotorType_recv,3), obj.Limit_param(MotorType_recv,3), 12);
                        obj.motors_map(CANID).recv_data(recv_q, recv_dq, recv_tau);
                    end
                else
                    MasterID = bitand(data(1),15);
                    if isKey(obj.motors_map, MasterID)
                        q_uint = bitor(bitshift(uint16(data(2)), 8), uint16(data(3)));
                        dq_uint = bitor(bitshift(uint16(data(4)), 4), bitshift(uint16(data(5)), -4));
                        tau_uint = bitor(bitshift(bitand(uint16(data(5)), 15), 8), uint16(data(6)));
                        MotorType_recv = obj.motors_map(MasterID).MotorType;
                        recv_q = obj.uint_to_float(q_uint, -obj.Limit_param(MotorType_recv,1), obj.Limit_param(MotorType_recv,1), 16);
                        recv_dq = obj.uint_to_float(dq_uint, -obj.Limit_param(MotorType_recv,2), obj.Limit_param(MotorType_recv,2), 12);
                        recv_tau = obj.uint_to_float(tau_uint, -obj.Limit_param(MotorType_recv,3), obj.Limit_param(MotorType_recv,3), 12);
                        obj.motors_map(MasterID).recv_data(recv_q, recv_dq, recv_tau);
                    end
                 end
             end
        end

        function write_motor_param(obj, Motor, RID, data)
            motorid = Motor.SlaveID;
            can_id_l = bitand(motorid, 255);
            can_id_h = bitshift(motorid, -8);
            data_buf = uint8([can_id_l,can_id_h, 0x55, RID, 0x00, 0x00, 0x00, 0x00]);
            if ~obj.is_in_ranges(RID)
                % data is float
                uint8s=obj.float_to_uint8s(data);
                data_buf(5:8)=uint8s(1:4);
            else
                % data is int
                uint8s=obj.uint32_to_uint8s(data);
                data_buf(5:8)=uint8s(1:4);
            end
            obj.send_data(0x7FF, data_buf);
        end

    end
end