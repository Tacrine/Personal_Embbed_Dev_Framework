#ifndef __DL_SOFTWARE_IIC_H
#define __DL_SOFTWARE_IIC_H

#include "stdint.h"
#include "ti_msp_dl_config.h"
#include "ti/driverlib/dl_gpio.h"

typedef struct
{
    uint32_t SDAPin;
    GPIO_Regs* SDAPort;
    uint32_t SCLPin;
    GPIO_Regs* SCLPort;
    uint32_t SDA_IOMUX;
}Tac_Software_IIC;
extern Tac_Software_IIC g_Tac_Software_IIC;

void DL_Software_IIC_Init(void);
void DL_Software_IIC_Start(void);

void SDA_Out(Tac_Software_IIC *iic_cfg_struct);
#endif //__DL_SOFTWARE_IIC_H