#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Entry {
    string name;
    int id;
};
class Dictionary {
private:
    vector<Entry> e; 

public:
    void addEntry(const string& name, int id) {
        e.push_back({name, id}); 
        cout << "added: " << name << " id: " << id  << endl;
    }
    void lookup(const string& name) {
        for (const auto& e : e) {
            if (e.name == name) {
                cout << "found: " << name << " id: " << e.id << endl;
                return; 
            }
        }
        cout << "not found: " << name << endl;
    }
};

int main() {
    Dictionary dict;
    dict.addEntry("a", 1);
    dict.addEntry("b", 2);
    dict.addEntry("e", 3);
    dict.lookup("b");     
    dict.lookup("d");   

    return 0;
}