#include "PID.h"

PIDController pid_controller;

/// @brief 初始化PID控制器
/// @param pid PID控制器结构体的指针
/// @param kp 比例系数
/// @param ki 积分系数
/// @param kd 微分系数
/// @param target 目标值
/// @param target 
void PID_Init(PIDController *pid, float kp, float ki, float kd, float target) {
    pid->Kp = kp;
    pid->Ki = ki;
    pid->Kd = kd;
    pid->current = 0.0f;
    pid->target = target;
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
    pid->output = 0.0f;
}


/// @brief 计算并更新PID
/// @param pid PIDktor结构体的指针
/// @return PID输出的抽象值
float PID_Update(PIDController *pid)    //在该函数执行前需要外部传入结构体成员current
{
    pid->prev_error = pid->error;             // 更新上一次的误差
    float error = pid->target - pid->current; // 计算误差
    pid->integral += error;                   // 积分误差
    // 计算PID输出值
    pid->output = pid->Kp * error +
                  pid->Ki * pid->integral +
                  pid->Kd * (error - pid->prev_error);

    pid->prev_error = error; // 更新上一次的误差
    return pid->output;
}

/// @brief 全局初始化所有PID控制器，位于主程序系统初始化部分
void PID_All_Init(void)
{
    PID_Init(&Voltage, 1.0f, 0.1f, 0.0f, 0.0f);
    PID_Init(&Current, 1.0f, 0.1f, 0.0f, 0.0f);
}
