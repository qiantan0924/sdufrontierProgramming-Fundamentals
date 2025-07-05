#include <iostream>
#include <cmath>
using namespace std;
double newtonSqrt(double n, double eps) {
    
    double x0 = n;  
    double x1 = 0.0;

    while (true) {
        x1 = 0.5 * (x0 + n / x0); 
        if (abs(x1 - x0) < eps) {
            break;
        }

        x0 = x1; 
    }

    return x1;
}

int main() {
    double n ;
    double eps;
   cout<<"please enter the number n"<<endl;
   cin>>n;
   cout<<"please enter the number eps"<<endl;
   cin>>eps;
    double result = newtonSqrt(n, eps);
    cout << "The square root of " << n << " is approximately " << result << endl;

    return 0;
}