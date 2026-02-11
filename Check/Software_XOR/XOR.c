#include "XOR.h"

// 计算结构体的 XOR 校验（不包含最后一个校验字段）
uint8_t Calculate_XOR(Config_t *cfg)
{
    uint8_t xor = 0;
    uint8_t *ptr = (uint8_t *)cfg;

    for (size_t i = 0; i < sizeof(Config_t) - 1; i++) {
        xor ^= ptr[i];
    }

    return xor;
}

