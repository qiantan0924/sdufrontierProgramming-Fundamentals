#include <iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<"please enter the number of distance"<<endl;
    long long int x;
    cin>>x;
    cout<<"please enter the number of velocity"<<endl;
    long long int v;
    cin>>v;
    float c=299792.458;
    cout<<"time spent on distance to spaceship is"<<(x*9.46*pow(10,12))/v<<"h"<<endl;
    cout<<"time spent on distance to earth is"<<(x*9.46*pow(10,12)/v)/sqrt(1-pow(v/c,2))<<"h"<<endl;
    return 0;
}//bywanghaoran202300141025