#include "PID.h"

// 初始化PID控制器
void PID_Init(PIDController *pid, float kp, float ki, float kd, float target) {
    pid->Kp = kp;
    pid->Ki = ki;
    pid->Kd = kd;
    pid->target = target;
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
    pid->output = 0.0f;
}

// 更新PID控制器
float PID_Update(PIDController *pid, float input) 
{
    float error = pid->target - input; // 计算误差
    pid->integral += error; // 积分误差

    // 计算PID输出值
    pid->output = pid->Kp * error + 
                  pid->Ki * pid->integral + 
                  pid->Kd * (error - pid->prev_error);

    pid->prev_error = error; // 更新上一次的误差

    return pid->output;
}

void PID_All_Init(void)
{
    PID_Init(&pid, 1.0f, 0.1f, 0.0f, 0.0f);
}
