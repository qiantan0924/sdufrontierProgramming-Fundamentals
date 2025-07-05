#include <iostream>
#include <cmath>
using namespace std;
int arr1[3][3]={1,3,6,9,9,7,1,4,2};
int arr2[3][3]={0};
int main(){
    int N=sizeof(arr1)/4;
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            arr2[i][k]=arr1[k][i];
            cout<<"  " <<arr2[i][k] ;
        }
        cout<<endl;
    }
    return 0;
}