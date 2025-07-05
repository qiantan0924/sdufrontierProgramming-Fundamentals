#include <iostream>
#include <string>

using namespace std;

int find(const string& main, const string& sub) {
    int count = 0;
    int subLenth = sub.length();
    int mainLenth = main.length();
    
    for (int i = 0; i <= mainLenth - subLenth; ) {//i 是main串字符位数
        bool match = true;
        for (int j = 0; j < subLenth; j++) {
            if (main[i + j] != sub[j]) {//i向后数j位与子串一一匹配
                match = false;
                break;
            }
        }
        if (match) {
           
            count++;
            i += subLenth; 
        } else {
         //我要是不匹配就向后顺位
            i++;
        }
    }
    return count;
}

int main() {
    string mainString, subString;
    cout << "mianstring ";
    getline(cin, mainString);
    cout << "substring ";
    getline(cin, subString);
    int cishu = find(mainString, subString);
    cout << "times " << cishu << endl;
    
    return 0;
}