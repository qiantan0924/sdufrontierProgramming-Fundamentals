#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool num(char c) {
    return c >= '0' && c <= '9'; 
}
int main() {
    string str;
    cout << "enter str plz ";
    getline(cin, str); 
    vector<string> numberString; 
    string Numberchuan;

    for (char c : str) { 
        if (num(c)) { 
            Numberchuan += c; //我这里先组装串
        } else {
            if (!Numberchuan.empty()) { 
                numberString.push_back(Numberchuan);
                Numberchuan.clear(); 
            }
        }
    }
    if (!Numberchuan.empty()) {
        numberString.push_back(Numberchuan);
    }
    cout << "int number 1s:" << endl;
    for (const string& n : numberString) {
        cout << n << endl;
    }

    return 0;
}