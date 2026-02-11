#ifndef __Feed_Forward_H
#define __Feed_Forward_H

typedef struct {
    float input;

    float K;    //经验因子，需要手动调整
    float target;

    float output;
} Feed_Forward_t;
extern Feed_Forward_t feed_forward;

void Forward_Feed_Init(Feed_Forward_t *feed_forward, float K, float target);

float Forward_Feed_Calculate(Feed_Forward_t *feed_forward, float input);

void Forward_Feed_All_Init(void);
#endif // __Feed_Forward_H 
