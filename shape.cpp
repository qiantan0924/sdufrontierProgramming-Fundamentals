#include <iostream>
using namespace std;

class Shape {
public:
    virtual void printInfo() = 0; 
    virtual ~Shape() { 
        cout << "shape destruct" << endl;
    }
};

class Rectangle : public Shape {
public:
    void printInfo()  {
        cout << "This is a Rectangle" << endl;
    }
    ~Rectangle()  {
        cout << "rectangle destruct" << endl;
    }
};

class Circle : public Shape {
public:
    void printInfo()  {
        cout << "This is a Circle" << endl;
    }
    ~Circle()  {
        cout << "circle destruct" << endl;
    }
};

int main() {
    const int n = 2;
    Shape* s[n]; 
    s[0] = new Rectangle();
    s[1] = new Circle();
    
    for (int i = 0; i < n; ++i) {
        s[i]->printInfo();
    }
    for (int i = 0; i < n; ++i) {
        delete s[i];
    }
    
    return 0;
}