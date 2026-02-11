#include "WaveGen_Sine.h"

float angle = 0.0f;

double WaveGen_Sine_Calculate(double x) {
    int i;
    double sum, a, b, s;
    sum = 0;
    a = x;     // 分子赋初值
    b = 1;     // 分母赋初值
    s = 1;
    for (i = 1; a / b >= 1e-6; i++) {
        sum = sum + s * a / b;    // 累加一项
        a = a * x * x;            // 求下一项分子
        b = b * 2 * i * (2 * i + 1);  // 求下一项分母
        s *= -1;                  // 符号变换
    }
    return sum;
}
