#include "Forward_Feed.h"

Feed_Forward_t feed_forward;

void Forward_Feed_Init(Feed_Forward_t *feed_forward, float K, float target)
{
    feed_forward->input = 0;
    feed_forward->output = 0;

    feed_forward->K = K;
    feed_forward->target = target;
}

float Forward_Feed_Calculate(Feed_Forward_t *feed_forward, float input)
{
    float error = feed_forward->target - feed_forward->input;
    feed_forward->output = - ((feed_forward->K) * error * error * error * (1 / feed_forward->target));     // 输出值 = 经验因子 * 误差^`3 * 1/目标值
}

void Forward_Feed_All_Init(void)
{
    Forward_Feed_Init(&feed_forward, 0.01, 100);
}