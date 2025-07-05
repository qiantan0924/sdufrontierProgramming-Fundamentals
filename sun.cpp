#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
const double G = 6.6738e-11;       
const double M = 1.9891e30;       
//dingyiguidaohanshu
void calculateOrbit(double v1, double l1, double v2, double l2) 
{
     double E = 0.5 * v1 * v1 - G * M / l1;
     double A = 0.5;
     double B = -G * M / (l1 * v1);
     double C = -E;
     double discriminant = B * B - 4 * A * C;
    if (discriminant < 0) {
        cout<< "Error: No solution v2!" << endl;
        return;
    }
 v2 = (-B + sqrt(discriminant)) / (2 * A);
 l2 = l1 * v1 / v2;
}
//dingyizhouqiqiufa
double calculatePeriod(double l1, double l2, double v1)
{
    double a = 0.5 * (l1 + l2);          
    double b = sqrt(l1 * l2);       
    double T = (2 * M_PI * a * b) / (l1 * v1); 
    return T;
}
int main()
{
    double v1_earth = 3.0287e4;         
    double l1_earth = 1.4710e11;        
    double v2_earth, l2_earth;
    calculateOrbit(v1_earth, l1_earth, v2_earth, l2_earth);
    double T_earth = calculatePeriod(l1_earth, l2_earth, v1_earth);
    
    cout << "earth orbit" << endl;
    cout << "  (a): " << 0.5 * (l1_earth + l2_earth) << " m" << endl;
    cout << "  (b): " << sqrt(l1_earth * l2_earth) << " m" << endl;
    cout << "  (T): " << T_earth << " s (" << T_earth / (365.25 * 24 * 3600) << " years)" << endl;
    
    

//dairu  halley  yeke by wanghaoran202300141025


    double v1_halley = 5.4629e4;         
    double l1_halley = 8.7830e10;        
    double v2_halley, l2_halley;
    calculateOrbit(v1_halley, l1_halley, v2_halley, l2_halley);
    double T_h = calculatePeriod(l1_halley, l2_halley, v1_halley);
    
    cout << "halley orbit" << endl;
    cout << "  (a): " << 0.5 * (l1_halley + l2_halley) << " m" << endl;
    cout << "  (b): " << sqrt(l1_halley * l2_halley) << " m" << endl;
    cout << "  (T): " << T_h << " s (" << T_h / (365.25 * 24 * 3600) << " years)" << endl;
    
    return 0;
}