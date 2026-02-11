#include "Second_Order_Compensation.h"

float Second_Order_Compensation(float adc_value) {
    float x = adc_value;
    float value = -0.00000117f*x*x + 0.01598515f*x + 0.91093335f ;
    return value;
}