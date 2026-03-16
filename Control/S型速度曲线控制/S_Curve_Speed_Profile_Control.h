#ifndef __S_CURVE_SPEED_PROFILE_CONTROL_H
#define __S_CURVE_SPEED_PROFILE_CONTROL_H

#include "math.h"

// S型速度曲线控制器结构体
typedef struct {
    float Minus;         // 分母

    float current; // 当前值
    float target;    // 设定值

    float error;       // 当前的误差

    float step;      // 输出值，该值实际意义是速度，该算法的输出值应该直接累加到PWM占空比之类的输出上，是积分控制
} Tac_S_Curve_Controller;
extern Tac_S_Curve_Controller S_Curve_Controller;

void S_Curve_Controller_Init(Tac_S_Curve_Controller *S_Curve_Controller);
float S_Curve_Controller_Update(Tac_S_Curve_Controller *S_Curve_Controller);
void S_Curve_Controller_All_Init(void);
#endif //__S_CURVE_SPEED_PROFILE_CONTROL_H