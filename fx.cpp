#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double f;
    double n;
    cout<<"plz enter the number N"<<endl;
    cin>>n;
    double x;
    double sum=0.;
    double a=0.;
    double b=2.;
    
    int i;
    double h = (b - a) / n;
    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h; 
        f=pow(x,4)-2*x+1;
        sum = f+sum;
    }
    cout<<"juxingsum= "<<sum*h<<endl;
    cout<<"juxingerror= "<<(sum*h-4.4)/4.4<<endl;
    double sum2 = 0.5 * (pow(a, 4) - 2 * a + 1 + pow(b, 4) - 2 * b + 1);
    for (int i = 1; i <n; ++i) {
        double x = a + i * h;
        f=pow(x,4)-2*x+1;
        sum2 = f+sum2;
    }
    cout<<"tixingsum= "<<sum2*h<<endl;
    cout<<"tixingerror= "<<(sum2*h-4.4)/4.4<<endl;
    double sum3 =pow(a, 4) - 2 * a + 1 + pow(b, 4) - 2 * b + 1;
    for (int i = 1; i <= n / 2; ++i) {
        double x = a + (2 * i - 1) * h;
        f = pow(x, 4) - 2 * x + 1;
        sum3 =sum3+ 4 * f;
    }
    for (int i = 1; i <= n / 2 - 1; ++i) {
        double x = a + 2 * i * h;
        f = pow(x, 4) - 2 * x + 1;
        sum3 =sum3+ 2 * f;
    }
    cout<<"xpssum= "<<sum3*h/3<<endl;
    cout<<"xpserror= "<<((sum3*h/3)-4.4)/4.4<<endl;
    return 0;
}
