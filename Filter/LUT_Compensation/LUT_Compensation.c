#include "LUT_Compensation.h"

// 自动初始化LUT补偿表
void LUT_Compensation_Auto_Init(uint8_t compensation) 
{
    for (int i = 0; i < LUT_SIZE; i++) {
        lut_compensation_table[i] = compensation;
    }
}

// 手动初始化LUT补偿表
void LUT_Compensation_Manual_Init(void) 
{
    lut_compensation_table[0] = 0;
    lut_compensation_table[1] = 1;
    lut_compensation_table[2] = 2;
    lut_compensation_table[3] = 3;
    lut_compensation_table[4] = 4;
    lut_compensation_table[5] = 5;
    lut_compensation_table[6] = 6;
}

// 更新LUT补偿表并获取补偿后的值
uint8_t LUT_Compensation_Update(uint8_t input) {
    if(input >= lut_compensation_table[0]) 
        return input * 1;
    else if(input >= lut_compensation_table[1]) 
        return input * 2;
    else if(input >= lut_compensation_table[2]) 
        return input * 3;
    else if(input >= lut_compensation_table[3])     
        return input * 4;    
    else if(input >= lut_compensation_table[4]) 
        return input * 5;
    else if(input >= lut_compensation_table[5]) 
        return input * 6;
    else if(input >= lut_compensation_table[6]) 
        return input * 7;
}
