#include <stdio.h>
#include <math.h>

// �����е�۲���
double l1, l2, l3, l4, l5, lzm;

// �����ٶȺͼ��ٶȵĺ���
void calculate_velocity_and_acceleration(double w1, double theta1, double w2, double theta2, double v, double theta3, double w_base)
{
    // 1. ����1�ۺ�2����l?�״����ٶ�����ٶ�
    double v_1_arm = l4 * w1 * cos(theta1); // 1����l?�״����ٶ�
    double a_1_arm = l4 * pow(w1, 2) * sin(theta1); // 1����l?�״��ļ��ٶ�
    double v_2_arm = -l4 * w2 * cos(theta2); // 2����l?�״����ٶ�
    double a_2_arm = -l4 * pow(w2, 2) * sin(theta2); // 2����l?�״��ļ��ٶ�
    // 2. ��3����v������չʱ����3����l?�״��ĵ���ٶ�����ٶ�
    double v_3_arm = v * cos(theta3); // 3����l?�״����ٶ�
    double a_3_arm = v * pow(cos(theta3), 2) * w1 + v * sin(theta3) * w_base; // 3����l?�״��ļ��ٶ�
    // 3. ��������y���Խ��ٶ� w_base ����ת��ʱ������ĩ�˵��ٶ�����ٶ�
    double v_base = l1 * w1 * cos(theta1) + l2 * w2 * cos(theta2) + l3 * v * cos(theta3) + lzm * w_base; // ����ĩ�˵��ٶ�
    double a_base = -l1 * pow(w1, 2) * sin(theta1) - l2 * pow(w2, 2) * sin(theta2) - l3 * pow(v, 2) * sin(theta3) - lzm * pow(w_base, 2); // ����ĩ�˵ļ��ٶ�
    // ������
    printf("1����l?�״����ٶȣ�%lf\n", v_1_arm);
    printf("1����l?�״��ļ��ٶȣ�%lf\n", a_1_arm);
    printf("2����l?�״����ٶȣ�%lf\n", v_2_arm);
    printf("2����l?�״��ļ��ٶȣ�%lf\n", a_2_arm);
    printf("3����l?�״����ٶȣ�%lf\n", v_3_arm);
    printf("3����l?�״��ļ��ٶȣ�%lf\n", a_3_arm);
    printf("����ĩ�˵��ٶȣ�%lf\n", v_base);
    printf("����ĩ�˵ļ��ٶȣ�%lf\n", a_base);
}
int main()
{
    // ���û�е�۲���
    l1 = 1.0;
    l2 = 1.0;
    l3 = 1.0;
    l4 = 1.0;
    l5 = 1.0;
    lzm = 1.0;
    // ���ý��ٶȺͽǶ�
    double w1 = 0.1;
    double theta1 = 0.5;
    double w2 = 0.2;
    double theta2 = 0.8;
    double v = 0.3;
    double theta3 = 1.2;
    double w_base = 0.05;

    // �����ٶȺͼ��ٶ�
    calculate_velocity_and_acceleration(w1, theta1, w2, theta2, v, theta3, w_base);
    return 0;
}