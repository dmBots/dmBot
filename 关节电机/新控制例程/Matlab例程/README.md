# 达妙Matlab库

Matlab支持的地方都能用，爽用！

感谢苗总的大力支持！

**欢迎加入QQ群：677900232 进行达妙电机技术交流。欢迎进入达妙店铺进行点击选购**[首页-达妙智能控制企业店-淘宝网 (taobao.com)](https://shop290016675.taobao.com/?spm=pc_detail.29232929/evo365560b447259.shop_block.dshopinfo.59f47dd6w4Z4dX)

### 1.引用达妙库

达妙的相关我已经放在DM_CAN文件夹下，如果要使用的话，加上下面这句话在代码开头

```matlab
addpath('.\DM_CAN\');
clear;
```

此外如果出现串口报错串口被占用等问题，极有可能是上一次代码运行因为手动或者报错而中断，解决方法是推荐在代码开头加上clear;清除相关对象。或者重新插拔串口

### 2.定义控制对象

定义电机对象，有几个电机就定义几个每个电机的masterid和canid都要不一样。重要的事情：不要把masterid设为0x00

```matlab
motor1=Motor(DM_Motor_Type.DM4310, 0x01, 0x11);%设置电机id
motor2=Motor(DM_Motor_Type.DM4310, 0x05, 0x15);
```

第一个参数为电机类型，第二个是SlaveID即电机的CANID（电机的ID）,第三个参数是MasterID是主机ID，建议MasterID设置的都不一样，比SlaveID整体高一个。

例如Motor1的SlaveID是0x01，MasterID是0x11。这样是最好

**MasterID和SlaveID需要在达妙上位机进行设置！！如果出现问题请先检查MasterID是否不和SlaveID冲突，并且不为0x00**

**MasterID不要设置为0x00**

**MasterID不要设置为0x00**

**MasterID不要设置为0x00**

初始化电机控制对象。传入参数是串口参数，波特率是921600，串口进行选择。demo是windows所以是'COM8'

```matlab
MotorControl1 = MotorControl('COM8',921600);%串口号和波特率
```

### 3.电机状态

#### 3.1 添加电机

```python
MotorControl1.addMotor(motor1);
MotorControl1.addMotor(motor2);
```

#### 3.2 使能电机

**建议：如果要修改电机参数。建议使能放在最后**

```
MotorControl1.enable(motor1);
MotorControl1.enable(motor2);
```

此代码为兼容旧固件，关于旧版本电机固件，使能对应不同模式需要加上使能的模式（即需要使能电机对应的模式，并不能修改电机此时的模式）**注意需要使能电机此时对应的模式，并不能修改电机内部的模式**

```matlab
MotorControl1.enable_old(motor1,Control_Type.MIT);
MotorControl1.enable_old(motor1,Control_Type.POS_VEL);
MotorControl1.enable_old(motor1,Control_Type.VEL);
```

#### 3.3设置电机零点

将电机在失能状态下摆到需要设置为0点的位置，然后运行下面两行，电机将会将当前位置作为电机0点。

```matlab
MotorControl1.set_zero_position(Motor3);
MotorControl1.set_zero_position(Motor6);
```

#### 3.4 失能电机

```matlab
MotorControl1.disable(Motor3);
MotorControl1.disable(Motor6);
```

#### 3.5 电机状态获取

**达妙电机默认是需要每发送一帧控制指令才能获得当前电机力矩、位置、速度等信息。如果在没有发送控制指令的过程中想要获得电机此时的状态可以通过以下指令。**

```matlab
MotorControl1.refresh_motor_status(motor2);
disp(['Motor2--vel:',num2str(motor2.getVelocity()),'pos:',num2str(motor2.getPosition()),'tau:',num2str(motor2.getTorque())]);
```

通过**refresh_motor_status**这个函数可以获得当前电机的状态，并保存到对应的电机。

### 4.电机控制模式

**推荐在每帧控制完后延迟2ms或者1ms，usb转can默认有缓冲器没有延迟也可使用，但是推荐加上延迟。**

**目前库函数中都没有延迟，每如果控制6个电机用一个usb转can，建议在控制指令后再加2ms延迟**

#### 4.1MIT模式

使能电机后可以使用MIT模式控制，推荐用MIT模式控制。

第一个参数是电机对象，第二个参数是kp，第三个是kd，第四个是位置，第五个是速度，第六个是力矩大小。具体请参考达妙手册关于mit协议。

```matlab
MotorControl1.controlMIT(motor2,30,0.4,y*5,0,0);
```

#### 4.2 位置速度模式

位置速度模式，第一个参数是电机对象，第二个是位置，第三个是转动速度。具体的参数介绍已经写了函数文档。

例子如下

```matlab
y=sin(index/100);
MotorControl1.control_Pos_Vel(motor2,y*10,5);
```

#### 4.3 速度模式

例子如下，第一个是电机对象，第二个是电机速度

```matlab
y=sin(index/100);
MotorControl1.control_Vel(motor1, y*10);
```

目前达妙的新固件支持切换

#### 4.4 力位混合模式

第一个是电机对象，第二个是电机位置，第三个是电机速度范围是0-10000，第四个是电机电流范围为0-10000。具体详细请查看达妙文档

例子如下

```matlab
MotorControl1.control_pos_force(motor1, 10, 1000,100)
```

### 5.电机状态读取

电机的各个状态都保存在对应的电机对象中，需要调用可以用如下几个函数。

**请注意！达妙的电机状态是每次发了控制帧或者刷新状态(refresh_motor_status 函数)后才能刷新电机对象的当前各个信息。！！**

**达妙电机是一发一收模式，只有发送指令电机才会返回当前状态，电机才会更新**

```matlab
vel = motor1.getVelocity();    %获得电机速度
pos = motor1.getPosition();    %获得电机
tau = motor1.getTorque();      %获得电机此时输出力矩
```

```maltab
disp(['Motor2--vel:',num2str(motor2.getVelocity()),'pos:',num2str(motor2.getPosition()),'tau:',num2str(motor2.getTorque())]);
```

### 6.电机内部参数更改

达妙电机新固件支持使用can进行电机模式修改，以及修改其他参数等操作。要求版本号5013及以上。具体请咨询达妙客服。**请注意所有保存参数、修改参数。请在失能模式下修改！！**

#### 6.1电机控制模式更改

通过下面的函数可以对电机的控制模式进行修改。支持MIT,POS_VEL,VEL,Torque_Pos。四种控制模式在线修改。下面是修改的demo。并且代码会有返回值，如果是True那么说明设置成功了，如果不是也不一定没修改成功hhhh。**请注意这里模式修改只是当前有效，掉电后这个模式还是修改前的**

```matlab
if MotorControl1.switchControlMode(motor1,Control_Type.VEL)
    disp("change control type to VEL success!");
end
if MotorControl1.switchControlMode(motor2,Control_Type.POS_VEL)
    disp("change control type to POS_VEL success!");
end
```

**如果要保持电机控制模式，需要最后保存参数**

#### 6.2保存参数

默认电机修改模式等操作后参数不会保存到flash中，需要使用命令如下进行保存至电机的flash中。这一个例子如下。**请注意这一个代码就把所有修改的都保存到Motor1的flash中，并且请在失能模式下进行修改**，该函数内部有自动失能的代码，防止电机在使能模式下无法保存参数。

```matlab
MotorControl1.save_motor_param(motor1);
MotorControl1.save_motor_param(motor2);
```

#### 6.3 读取内部寄存器参数

内部寄存器有很多参数都是可以通过can线读取，具体参数列表请看达妙的手册。其中可以读的参数都已经在DM_variable这个枚举类里面了。可以通过read_motor_param进行读取，具体使用方法函数注释中都有写，第一个是电机对象，第二个参数是DM_Reg这个枚举类中定义的寄存器名字。

```matlab
motors = {motor1, motor2};
for i = 1:length(motors)
    motor = motors{i};
    disp("  ");
    fprintf('Motor%d:\n', i);
    
    if MotorControl1.change_motor_param(motor,DM_Reg.KP_APR,54)
        disp('change KP_APR success!!!!!');
    end
    disp(['KP_APR:',num2str(MotorControl1.read_motor_param(motor, DM_Reg.KP_APR))]);
    disp(['MST_ID:', num2str(MotorControl1.read_motor_param(motor, DM_Reg.MST_ID))]);
    disp(['VMAX:', num2str(MotorControl1.read_motor_param(motor, DM_Reg.VMAX))]);
    disp(['TMAX:', num2str(MotorControl1.read_motor_param(motor, DM_Reg.TMAX))]);
    disp(['sub_ver:', num2str(MotorControl1.read_motor_param(motor, DM_Reg.sub_ver))]);
    if MotorControl1.change_motor_param(motor,DM_Reg.UV_Value,12.6)
        disp('change UV_Value success!!!!');
    end
    disp(['UV_Value:', num2str(MotorControl1.read_motor_param(motor, DM_Reg.UV_Value))]);
end
```

并且每次读取参数后，当前的参数也会同时存在对应的电机类里面，通过getParam这个函数进行读取。

```matlab
disp(['PMAX',num2str(motor1.getParam(DM_variable.PMAX))]);
```

#### 6.4 改写内部寄存器参数

内部寄存器有一部分是支持修改的，一部分是只读的（无法修改）。通过调用change_motor_param这个函数可以进行寄存器内部值修改。并且也如同上面读寄存器的操作一样，他的寄存器的值也会同步到电机对象的内部值，可以通过Motor1.getParam这个函数进行读取。

**请注意这个修改内部寄存器参数，掉电后会恢复为修改前的，并没有保存**

```matlab
if MotorControl1.change_motor_param(motor,DM_Reg.UV_Value,12.6)
   disp('change UV_Value success!!!!');
end
```

