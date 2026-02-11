#ifndef __LUT_COMPENSATION_H
#define __LUT_COMPENSATION_H

#include "stdint.h"

// LUT补偿表
extern uint8_t lut_compensation_table[]; // 二维查找表

// 初始化LUT补偿表
void LUT_Compensation_Auto_Init(uint8_t compensation); 
void LUT_Compensation_Manual_Init(void) ;

// 更新LUT补偿表并获取补偿后的值
uint8_t LUT_Compensation_Update(uint8_t input); 
#endif //__LUT_COMPENSATION_H
