#define _USE_MATH_DEFINES
#include <iostream>
#include<cmath>
using namespace std;
int main()
{

    cout<<"please enter the number of seconds"<<endl;
    long long int s;
    cin>>s;
    double g=6.67*pow(10,(-11));
    
    double h;
    h=(g*5.97*pow(10,24)/(pow(M_PI,2)*4/pow(s,2)));
    cout<<"the height of satelite is"<<cbrt(h)-6371000<<"m"<<endl;
    double k;
    k=(g*5.97*pow(10,24)/(pow(M_PI,2)*4/pow(86400,2)));
    cout<<"the height of geostationary satelite is"<<cbrt(k)-6371000<<"m"<<endl;
    return 0;
}