#include <iostream>
using namespace std;


int gcd(int m, int n) {
    if (n == 0) {
        return m; 
    }
    return gcd(n, m % n); 
}

int main() {
    int m = 108;
    int n = 192;
    int result = gcd(m, n);
    cout << "The greatest common divisor of 108,192is: " << result << endl;

    return 0;
}