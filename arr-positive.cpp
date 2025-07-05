#include <iostream>
using namespace std;
int arr[] = {-1, 3, 5, -7, 9, -2, 4, 6, -8, 0};
int Positive(int array[], int size) {
    int totalnumber = 0; 
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            totalnumber++;
        }
    }
    return totalnumber;
}

int main() {
    int size = sizeof(arr) / sizeof(arr[0]);
    int positive = Positive(arr, size);

    cout << "The number of positive num in the array is: " << positive << endl;
    cout << "The number of size is: " << size<< endl;
    return 0;
}