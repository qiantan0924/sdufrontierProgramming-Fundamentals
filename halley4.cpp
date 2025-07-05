#define _USE_MATH_DEFINES // 放在 <cmath> 之前
#include <iostream>
#include <cmath>
using namespace std;

// 常量定义
const double G = 6.6738e-11;       // 万有引力常数 (m^3 kg^-1 s^-2)
const double M = 1.9891e30;        // 太阳质量 (kg)

// 定义轨道计算函数
void calculateOrbit(double v1, double l1, double& v2, double& l2) 
{
    // 总能量 E = 0.5 * v1^2 - G * M / l1
    double E = 0.5 * v1 * v1 - G * M / l1;

    // 利用能量守恒和开普勒第二定律求解 l2 和 v2
    // 0.5 * v2^2 - G * M / l2 = E
    // l2 = l1 * v1 / v2
    // 代入得到方程：0.5 * v2^2 - G * M * v2 / (l1 * v1) = E
    // 这是一个关于 v2 的二次方程：0.5 * v2^2 - (G * M / (l1 * v1)) * v2 - E = 0
    double A = 0.5;
    double B = -G * M / (l1 * v1);
    double C = -E;

    // 解二次方程：v2 = [-B ± sqrt(B^2 - 4AC)] / (2A)
    double discriminant = B * B - 4 * A * C;
    if (discriminant < 0) {
        cout << "Error: No real solution for v2!" << endl;
        return;
    }

    // 取正根（速度为正）
    v2 = (-B + sqrt(discriminant)) / (2 * A);

    // 计算 l2
    l2 = l1 * v1 / v2;
}

// 定义周期计算函数
double calculatePeriod(double l1, double l2, double v1)
{
    double a = 0.5 * (l1 + l2);          // 半长轴
    double b = sqrt(l1 * l2);            // 半短轴
    double T = (2 * M_PI * a * b) / (l1 * v1); // 周期
    return T;
}

int main()
{
    // 地球的数据
    double v1_earth = 3.0287e4;         // 近地点速度 (m/s)
    double l1_earth = 1.4710e11;        // 近地点距离 (m)

    // 计算地球的轨道
    double v2_earth, l2_earth;
    calculateOrbit(v1_earth, l1_earth, v2_earth, l2_earth);
    double T_earth = calculatePeriod(l1_earth, l2_earth, v1_earth);

    // 输出结果
    cout << "Earth's Orbit:" << endl;
    cout << "  Semi-major axis (a): " << 0.5 * (l1_earth + l2_earth) << " m" << endl;
    cout << "  Semi-minor axis (b): " << sqrt(l1_earth * l2_earth) << " m" << endl;
    cout << "  Period (T): " << T_earth << " s (" << T_earth / (365.25 * 24 * 3600) << " years)" << endl;

    return 0;
}