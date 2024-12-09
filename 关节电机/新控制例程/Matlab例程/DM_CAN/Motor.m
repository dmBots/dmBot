classdef Motor < handle
    % Class to define a motor object
    properties
        Pd
        Vd
        state_q
        state_dq
        state_tau
        SlaveID
        MasterID
        MotorType
        temp_param_dict
    end
    methods
        function obj = Motor(MotorType, SlaveID, MasterID)
            % Constructor to initialize motor object
            % MotorType: Motor type
            % SlaveID: CANID motor ID
            % MasterID: Master ID, recommended not to set to 0
            obj.Pd = single(0);
            obj.Vd = single(0);
            obj.state_q = single(0);
            obj.state_dq = single(0);
            obj.state_tau = single(0);
            obj.SlaveID = uint32(SlaveID);
            obj.MasterID = uint32(MasterID);
            obj.MotorType = uint32(MotorType);
            obj.temp_param_dict=containers.Map('KeyType','uint32', 'ValueType','any');
        end
        
        function obj = recv_data(obj, q, dq, tau)
            % Method to receive data and update motor state
            obj.state_q = q;
            obj.state_dq = dq;
            obj.state_tau = tau;
        end
       
        function q = getPosition(obj)
            % Method to get the position of the motor
            q = obj.state_q;
        end
        
        function dq = getVelocity(obj)
            % Method to get the velocity of the motor
            dq = obj.state_dq;
        end
        
        function tau = getTorque(obj)
            % Method to get the torque of the motor
            tau = obj.state_tau;
        end
        
        function obj = saveParam(obj,RID,param)
            obj.temp_param_dict(RID)=param;
        end

        function param = getParam(obj, RID)
            % get the parameter of the motor 获取电机内部的参数，需要提前读取
            % :param RID: DM_variable 电机参数
            % :return: the parameter of the motor 电机参数
            if isKey(obj.temp_param_dict, RID)
                param = obj.temp_param_dict(RID);
            else
                param = [];
            end
        end



    end
end