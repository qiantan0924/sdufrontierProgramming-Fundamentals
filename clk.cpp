#include <iostream>
using namespace std;

class Clock {
private:
    int hour;
    int minute;
    int second;

public:
 
    Clock() : hour(0), minute(0), second(0) {
        cout << "Clock default ";
        display();   
        cout<<endl;
       
    }
    Clock(int h, int m, int s) : hour(h), minute(m), second(s) {
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;

        cout << "Clock created ";
        display();
        cout <<endl;
    }
    ~Clock() {
        cout << "Clock object destroyed ";
        display();
        cout << endl;
    }

    void display() const {
        cout << hour << ":" << minute << ":" << second;
    }
    Clock add(const Clock& c) const {
        int as = second +c.second;
        int am = minute + c.minute + as / 60;
        int ah = hour + c.hour + am/ 60;

        int nsecond = as % 60;
        int nminute = am % 60;
        int  nhour = ah % 24; 

        return Clock(nhour, nminute, nsecond);
    }
};

int main() {
    Clock k;
    Clock m (1,11,111);              
    Clock n (9, 99, 999);   
    Clock o = m.add(n);  

    return 0;
}