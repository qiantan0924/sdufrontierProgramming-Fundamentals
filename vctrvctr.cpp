#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

class MyVector : public vector<double> {
public:
    using vector<double>::vector; 
    
    double ave() const {
        if (empty()) return 0.0;
        double sum = 0.0;
        for (auto t = begin(); t != end(); ++t) {  
            sum += *t;
        }
        return sum / size();
    }

    double med() {
        if (empty()) return 0.0;
        sort(begin(), end());
        
        auto m = begin() + size() / 2; 
        
        if (size() % 2 == 1) {
            return *m; 
        } else {
            auto p = m - 1;
            return (*p + *m) / 2.0; 
        }
    }

    double stdev() const { 
        if (empty()) return 0.0;
        double m = ave();
        double sum = 0.0;
        for (auto t = begin(); t != end(); ++t) {
            sum += (*t - m) * (*t - m);
        }
        return sqrt(sum / size());
    }
};

int main() {
    MyVector vec = {1.0, 3.0, 2.0, 5.0, 4.0}; 

    cout << "ave: " << vec.ave() << endl;
    cout << "mid: " << vec.med() << endl; 
    cout << "std: " << vec.stdev() << endl;

    return 0;
}