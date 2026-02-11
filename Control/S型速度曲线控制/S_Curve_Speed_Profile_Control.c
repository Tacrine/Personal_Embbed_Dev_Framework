#include "S_Curve_Speed_Profile_Control.h"

Tac_S_Curve_Controller S_Curve_Controller;

/// @brief 初始化S型速度曲线控制器
/// @param S_Curve_Controller S型速度曲线控制器结构体
void S_Curve_Controller_Init(Tac_S_Curve_Controller *S_Curve_Controller)
{
    S_Curve_Controller->Minus = 1.0;
    S_Curve_Controller->current = 0.0;
    S_Curve_Controller->target = 0.0;
    S_Curve_Controller->error = 0.0;
    S_Curve_Controller->step = 0.0;
}

/// @brief 更新并计算S型速度曲线控制器输出值
/// @param S_Curve_Controller S型速度曲线控制器结构体
/// @return S型速度曲线控制器输出值，该值为绝对值，需要根据目标做正负赋值处理
float S_Curve_Controller_Update(Tac_S_Curve_Controller *S_Curve_Controller) 
{
    S_Curve_Controller->error = S_Curve_Controller->target - S_Curve_Controller->current; //在该函数执行前需要外部传入结构体成员current
    S_Curve_Controller->step = expf(fabs(S_Curve_Controller->error) / S_Curve_Controller->Minus - 1.0f);
    return S_Curve_Controller->step;
}

/// @brief 全局初始化所有S型速度曲线控制器，位于主程序系统初始化部分
void S_Curve_Controller_ALL_Init(void)
{
    S_Curve_Controller_Init(&Voltage_Controll);
    S_Curve_Controller_Init(&Position_Controll);
}