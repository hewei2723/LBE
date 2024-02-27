#include <stdio.h>
#include <math.h>

// 定义机械臂参数
double l1, l2, l3, l4, l5, lzm;

// 计算速度和加速度的函数
void calculate_velocity_and_acceleration(double w1, double theta1, double w2, double theta2, double v, double theta3, double w_base)
{
    // 1. 计算1臂和2臂上l?米处的速度与加速度
    double v_1_arm = l4 * w1 * cos(theta1); // 1臂上l?米处的速度
    double a_1_arm = l4 * pow(w1, 2) * sin(theta1); // 1臂上l?米处的加速度
    double v_2_arm = -l4 * w2 * cos(theta2); // 2臂上l?米处的速度
    double a_2_arm = -l4 * pow(w2, 2) * sin(theta2); // 2臂上l?米处的加速度
    // 2. 当3臂以v向外伸展时，求3臂上l?米处的点的速度与加速度
    double v_3_arm = v * cos(theta3); // 3臂上l?米处的速度
    double a_3_arm = v * pow(cos(theta3), 2) * w1 + v * sin(theta3) * w_base; // 3臂上l?米处的加速度
    // 3. 若基座绕y轴以角速度 w_base 匀速转动时，计算末端的速度与加速度
    double v_base = l1 * w1 * cos(theta1) + l2 * w2 * cos(theta2) + l3 * v * cos(theta3) + lzm * w_base; // 基座末端的速度
    double a_base = -l1 * pow(w1, 2) * sin(theta1) - l2 * pow(w2, 2) * sin(theta2) - l3 * pow(v, 2) * sin(theta3) - lzm * pow(w_base, 2); // 基座末端的加速度
    // 输出结果
    printf("1臂上l?米处的速度：%lf\n", v_1_arm);
    printf("1臂上l?米处的加速度：%lf\n", a_1_arm);
    printf("2臂上l?米处的速度：%lf\n", v_2_arm);
    printf("2臂上l?米处的加速度：%lf\n", a_2_arm);
    printf("3臂上l?米处的速度：%lf\n", v_3_arm);
    printf("3臂上l?米处的加速度：%lf\n", a_3_arm);
    printf("基座末端的速度：%lf\n", v_base);
    printf("基座末端的加速度：%lf\n", a_base);
}
int main()
{
    // 设置机械臂参数
    l1 = 1.0;
    l2 = 1.0;
    l3 = 1.0;
    l4 = 1.0;
    l5 = 1.0;
    lzm = 1.0;
    // 设置角速度和角度
    double w1 = 0.1;
    double theta1 = 0.5;
    double w2 = 0.2;
    double theta2 = 0.8;
    double v = 0.3;
    double theta3 = 1.2;
    double w_base = 0.05;

    // 计算速度和加速度
    calculate_velocity_and_acceleration(w1, theta1, w2, theta2, v, theta3, w_base);
    return 0;
}