#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Student {
private:
    string name;
    unsigned int student_id;
    float hw_scores[10];
    float midterm_score;
    float final_score;
    float attendancescore;
    float maxscore;
    float minscore;
    float avgscore;

    void calculate() {
        
        float max = hw_scores[0];
        for (int i = 1; i < 10; i++) {
            if (hw_scores[i] > max) {
                max = hw_scores[i];
            }
        }
        float min = hw_scores[0];
        for (int i = 1; i < 10; i++) {
            if (hw_scores[i] < min) {
            min = hw_scores[i];
           }
        }
        maxscore = max;
        minscore = min;
        float sum = 0.0;
        for (int i = 0; i < 10; ++i) {
            sum += hw_scores[i];
        }
        avgscore = sum / 10.;
    }
    
    float maxScore() const { return maxscore; }
    float minScore() const { return minscore; }
    float average() const  { return avgscore; }
public:
    
    

    
    void rd(istream& n) {
        n >> name >> student_id;
        for (auto& score : hw_scores) {
            n >> score;
        }
        n >> attendancescore >> midterm_score >> final_score;
        calculate();
    }
    const string& get_name() const { return name; }
    float final() const { return final_score; }
    float max() const { return maxscore; }
    float min() const { return minscore; }
    float avg() const { return avgscore; }
    void s() const {
        cout << "name: " << name <<endl;
        cout << "maxscr: " << maxScore() << endl;
        cout << "minscr: " << minScore() << endl;
        cout << "aveghw: " << average() << endl;
        cout << "mdtermscr: " << midterm_score << endl;
        cout << "finalscr: " << final_score << endl;
    }
    static bool cfinal(const Student& a, const Student& b) {
        return a.final_score > b.final_score;
    }

    static bool cmax(const Student& a, const Student& b) {
        return a.maxscore > b.maxscore;
    }

    static bool cmin(const Student& a, const Student& b) {
        return a.minscore > b.minscore;
    }

    static bool cavg(const Student& a, const Student& b) {
        return a.avgscore > b.avgscore;
    }
};

class a {
private:
    vector<Student> students;

    void r(const string& title, float (Student::*n)() const) {
        cout << "  " << title << " rank  "<<endl;
        cout << "----------------------"<<endl;
        cout << "Name          Score"<<endl;
        for (const auto& s : students) {
            cout << s.get_name() << "     " << (s.*n)() << endl;
        }
        cout << "----------------------"<<endl;
    }

public:
    void b(const string& name) {
        ifstream file(name);
        if (!file.is_open()) {
            cout << "cannot open file" << endl;
        
        }

        string header;
        getline(file, header);

        Student s;
        while (!file.eof() ) {
            s.rd(file);
            students.push_back(s);
        }
    }

    void name(const string& name) {
        bool found = false;
        
        for (const auto& student : students) {
            if (student.get_name() == name) {
                student.s(); 
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "student not found: " << name << endl;
        }
    }
     

    void s(const string& word) {
        if (students.empty()) return;

        if (word == "final") {
            sort(students.begin(), students.end(), Student::cfinal);
            r("Final", &Student::final);
        }
        else if (word == "max") {
            sort(students.begin(), students.end(), Student::cmax);
            r("Max", &Student::max);
        }
        else if (word == "min") {
            sort(students.begin(), students.end(), Student::cmin);
            r("Min", &Student::min);
        }
        else if (word == "avg") {
            sort(students.begin(), students.end(), Student::cavg);
            r("Average", &Student::avg);
        }
    }
};

int main() {
    
        a m;
        m.b("Student_info.txt");
        m.name("Zeus");//这里人名
        m.s("final");
        m.s("max");
        m.s("min");
        m.s("avg");

     
    return 0;
}