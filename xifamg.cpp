#include <iostream>
#include <cmath>
using namespace std;
const int N = 5;//点个数
double calculateChiSquare(double* x, double* y, double m, double c) {
    double chiSquare = 0.0;
    for (int i = 0; i < N; i++) {
        double yPredicted = m * (*(x + i)) + c; 
        chiSquare += pow((*(y + i)) - yPredicted, 2);
    }
    return chiSquare;
}

int main() {
    // 数据点，随便写的
    double x[N] = {1., 2., 3., 4., 5.};
    double y[N] = {0.0, 2.5, 3., 5., 7.};
    //四个循环找极限
    int A = sizeof(x) / sizeof(x[0]); 
    double maxValue = x[0];
    for (int i = 1; i < A; i++) {
        if (x[i] > maxValue) {
            maxValue = x[i];
        }
    }
    //
    int B = sizeof(y) / sizeof(y[0]); 
    double maxYalue = y[0];
    for (int i = 1; i < A; i++) {
        if (y[i] > maxYalue) {
            maxYalue = y[i];
        }
    }
    //
    int C = sizeof(x) / sizeof(x[0]); 
    double minValue = x[0];
    for (int i = 1; i < A; i++) {
        if (x[i] < minValue) {
            minValue = x[i];
        }
    }
    //
    int D = sizeof(y) / sizeof(y[0]); 
    double minYalue = y[0];
    for (int i = 1; i < A; i++) {
        if (y[i] < minYalue) {
            minYalue = y[i];
        }
    }
    //确定m最大范围
    // 定义m和c的区间
    double mStrt = (-1)*(maxYalue-minYalue)/(maxValue-minValue);
    double mEnd = (maxYalue-minYalue)/(maxValue-minValue);
    double cStrt = -10.0;
    double cEnd = 5.;

    double step = 0.001;
    double bestM = 0.0;
    double bestC = 0.0;
    double minChiSquare = 10;//希方太大会需要调整，大于这个值会MC是零，但也不能称之为直线
    // 两层循环
    for (double m = mStrt; m <= mEnd; m += step) {
        for (double c = cStrt; c <= cEnd; c += step) {
            double chiSquare = calculateChiSquare(x, y, m, c); 
            if (chiSquare < minChiSquare) {
                minChiSquare = chiSquare;
                bestM = m;
                bestC = c;
            }
        }
    }//有一说一，枚举法好暴力

    // 输出结果
    cout << " m: " << bestM << endl;
    cout << " c: " << bestC << endl;
    cout << " chisquare: " << minChiSquare << endl;
    cout << "y= " << bestM << "x+"<<bestC<<endl;
    return 0;
}