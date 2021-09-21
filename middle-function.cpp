#include "RMM/rmm.hpp"

class middle_function
{

private:
    /* data */
    roboken::Servo servo1;
    roboken::Servo servo2;
    roboken::Encoder enc1;
    roboken::Encoder enc2;
    roboken::LPMotor motor1;
    roboken::LPMotor motor2;
    roboken::Switch switch1;
    roboken::Switch switch2;
    roboken::Switch switch3;
    roboken::Switch switch4;
    


public:
    middle_function(/* args */);//宣言
    ~middle_function();
    void rise();        //上昇
    void Descent();     //下降
    void Deployment();  //展開
    void Shrink();      //縮小
};

middle_function::middle_function(/* args */)
{
    servo1.Servo_cons(0x01,1);  servo1.init();
    servo2.Servo_cons(0x02,1);  servo2.init();
    motor1.LPMotor_cons(0x01,1);    motor1.init();
    motor2.LPMotor_cons(0x02,1);    motor2.init();
    switch1.Switch_cons(0x01,1);    switch1.init();
    switch2.Switch_cons(0x02,1);    switch2.init();
    switch3.Switch_cons(0x03,1);    switch3.init();
    switch4.Switch_cons(0x04,1);    switch4.init();
    enc1.Encoder_cons(0x01,1,1);    enc1.init();
    enc2.Encoder_cons(0x02,1,1);    enc2.init();
}

middle_function::~middle_function()
{
    
}



void middle_function::rise()
{
    while(true)
    {
        CSType_delay_ms(20);
        if(switch1.get()==1&&switch2.get()==1)
        {
            motor1.set_power(0);
            motor2.set_power(0);
            break;
        }
        if(switch1.get()==0)
        {
            motor1.set_power(50);
        }
        else
        {
            motor1.set_power(0);
        }
        if(switch2.get()==0)
        {
            motor2.set_power(50);
        }
        else
        {
            motor2.set_power(0);
        }
    }
}

void middle_function::Descent()
{
    while(true)
    {
        CSType_delay_ms(20);
        if(switch3.get()==1&&switch4.get()==1)
        {
            motor1.set_power(0);
            motor2.set_power(0);
            break;
        }
        if(switch3.get()==0)
        {
            motor1.set_power(-50);
        }
        else
        {
            motor1.set_power(0);
        }
        if(switch4.get()==0)
        {
            motor2.set_power(-50);
        }
        else
        {
            motor2.set_power(0);
        }
    }
}

void middle_function::Deployment()
{
    servo1.set_angle(80);
    servo2.set_angle(80);
}
void middle_function::Shrink()
{
    servo1.set_angle(0);
    servo2.set_angle(0);
}














