#include <iostream>
#include <cmath>
using namespace std;
int main(){
    cout<<"plz enter the num a"<<endl;
    int a;
    cin>>a;
    cout<<"plz enter the num z"<<endl;
    int z;
    int a5;
    cin>>z;
    if(a<z){
        cout<<"wrong"<<endl;
    }
    else if(a%2!=0){
        a5=0;
    }
    else if(a%2==0&&z%2==0){
        a5=12;
    }
    else if(a%2==0&&z%2!=0){
        a5=-12;
    }
    double b;
    b=15.8*a-18.3*pow(a,(2./3.))-0.714*pow(z,2)/pow(a,(1./3.))-23.2*pow((a-2*z),2)/a+a5/(pow(a,0.5));
    cout<<"the   binding energy is  "<<b/a<<"mev"<<endl;
    //以下为循环
    double max_b=-5.0;
    int amax=z;
    for(int a=z;a<3*z+1;a++){
        
        if(a%2!=0){
            a5=0;
        }
        else if(a%2==0&&z%2==0){
            a5=12;
        }
        else if(a%2==0&&z%2!=0){
            a5=-12;
        }
        b=15.8*a-18.3*pow(a,(2./3.))-0.714*pow(z,2)/pow(a,(1./3.))-23.2*pow((a-2*z),2)/a+a5/(pow(a,0.5));
       
        if((b/a)>max_b)
        {
          max_b=(b/a);
          amax=a;
        }
        
    }
    cout<<"the  maximum binding energy is  "<<max_b<<" a= "<<a<<endl;
    return 0;
}
