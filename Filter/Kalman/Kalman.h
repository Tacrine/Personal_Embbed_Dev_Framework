#ifndef __KALMAN_H
#define __KALMAN_H

typedef struct {
    float Q;     // 过程噪声协方差
    float R;     // 测量噪声协方差
    float X;     // 当前估计值
    float P;     // 估计协方差
    float K;     // 卡尔曼增益
} KalmanFilter;

typedef struct {
    KalmanFilter AccX;
    KalmanFilter AccY;
    KalmanFilter AccZ;
    KalmanFilter GyroX;
    KalmanFilter GyroY;
    KalmanFilter GyroZ;
} FilteredData;

// 初始化滤波器
void Kalman_Init(KalmanFilter *kf, float q, float r, float initial);

// 每次调用更新状态（传入测量值）
float Kalman_Update(KalmanFilter *kf, float measurement);

// 初始化所有轴滤波器
void Kalman_All_Init(void);

#endif
