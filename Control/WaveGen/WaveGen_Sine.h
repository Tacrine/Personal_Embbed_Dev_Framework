#ifndef __SINE_H__
#define __SINE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>  // 包含数学函数的头文件以使用 M_PI

// 定义外部变量 angle
extern float angle;

// 定义常量 PI 如果 M_PI 未定义
#define M_PI 3.14159265358979323846

double WaveGen_Sine_Calculate(double x);

#endif // _SINE_H
