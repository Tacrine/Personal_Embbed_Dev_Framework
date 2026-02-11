#ifndef __PID_H
#define __PID_H

#include "stdint.h"

// PID控制器结构体
typedef struct {
    float Kp;          // 比例增益
    float Ki;          // 积分增益
    float Kd;          // 微分增益

    float target;    // 设定值

    float integral;    // 积分值

    float prev_error;  // 上一次的误差
    float error;       // 当前的误差

    float output;      // 输出值
} PIDController;

// 函数声明
void PID_Init(PIDController *pid, float kp, float ki, float kd, float target); // 初始化PID控制器
float PID_Update(PIDController *pid, float input); // 更新PID控制器
void PID_All_Init(void); // 一键初始化

#endif
