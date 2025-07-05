#include <iostream>
#include <cmath>
using namespace std;
double function1(double x){
    return pow(x,4)-2*x+1;
}
double function2(double x){
    return 3*pow(x,4)-5*exp(-x)+sin(x/4);
}
double function3(double x){
    return x*sin(3*x);
   
}
double SimpsonIntegral(double a, double b, int N, double (*function)(double)) {
    double h = (b - a) / N; 
    double sum = function(a)+function(b);
    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * function(x); // 偶数项
        } else {
            sum += 4 * function(x); // 奇数项
        }
    }
    return (h / 3.) * sum; 
}
int main() {
    double a = 0.0; 
    double b = 1.0; 
    int N = 10000;
    double result1 = SimpsonIntegral(a, b, N, function1);
    cout << "Integral of function1: " << result1 << endl;
    double result2 = SimpsonIntegral(a, b, N, function2);
    cout << "Integral of function2: " << result2 << endl;
    double result3 = SimpsonIntegral(a, b, N, function3);
    cout << "Integral of function3: " << result3 << endl;

    return 0;
}