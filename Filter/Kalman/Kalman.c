#include "Kalman.h"

FilteredData filtered_data;

void Kalman_Init(KalmanFilter *kf, float q, float r, float initial)
{
    kf->Q = q;
    kf->R = r;
    kf->X = initial;
    kf->P = 1.0f; // 初始估计协方差，可按需调整
    kf->K = 0.0f;
}

float Kalman_Update(KalmanFilter *kf, float measurement)
{
    // 预测步骤：更新估计协方差
    kf->P = kf->P + kf->Q;

    // 计算卡尔曼增益
    kf->K = kf->P / (kf->P + kf->R);

    // 更新估计值
    kf->X = kf->X + kf->K * (measurement - kf->X);

    // 更新估计协方差
    kf->P = (1 - kf->K) * kf->P;

    return kf->X;
}

void Kalman_All_Init(void)
{
    Kalman_Init(&filtered_data.AccX, 0.01f, 0.1f, 0.0f);
    Kalman_Init(&filtered_data.AccY, 0.01f, 0.1f, 0.0f);
    Kalman_Init(&filtered_data.AccZ, 0.01f, 0.1f, 0.0f);
    Kalman_Init(&filtered_data.GyroX, 0.01f, 0.1f, 0.0f);
    Kalman_Init(&filtered_data.GyroY, 0.01f, 0.1f, 0.0f);
    Kalman_Init(&filtered_data.GyroZ, 0.01f, 0.1f, 0.0f);
}
