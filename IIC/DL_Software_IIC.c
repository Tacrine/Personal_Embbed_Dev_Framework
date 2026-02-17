#include "DL_Software_IIC.h"

Tac_Software_IIC g_Tac_Software_IIC;


/// @brief 设置SDA引脚属性为输出模式
/// @param iic_cfg_struct IIC配置结构体
void SDA_Out(Tac_Software_IIC *iic_cfg_struct)
{
	DL_GPIO_initDigitalOutput(iic_cfg_struct->SDA_IOMUX);
	DL_GPIO_setPins(iic_cfg_struct->SDAPort, iic_cfg_struct->SDAPin);
	DL_GPIO_enableOutput(iic_cfg_struct->SDAPort, iic_cfg_struct->SDAPin);
}

/// @brief 设置SDA引脚属性为输入模式
/// @param iic_cfg_struct IIC配置结构体
void SDA_In(Tac_Software_IIC *iic_cfg_struct)
{
	DL_GPIO_initDigitalInputFeatures(iic_cfg_struct->SDA_IOMUX,
									 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
									 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
}

void DL_Software_IIC_Init(void)
{
    SYSCFG_DL_GPIO_init();
	/*设置默认电平*/
	DL_GPIO_setPins(X_IIC.SDAPort, X_IIC.SDAPin |
		X_IIC.SCLPin);//设置PA8和PA9引脚初始化后默认为高电平（释放总线状态）
}

DL_Software_IIC_Start(void)
{

} 