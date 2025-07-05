#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>  
using namespace std;
struct Student {
    string name;
    unsigned int student_id;
    float hw_scores[10];
    
    float midterm_score;
    float final_score;
    float attendance_score;
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
};
void name(const vector<Student>& students, const string& name) {
    
    bool found = false;
    
    for (const auto& student : students) {
        if (student.name == name) {
            cout << "name: " << student.name <<endl;
            cout << "maxscr: " << student.maxScore() << endl;
            cout << "minscr: " << student.minScore() << endl;
            cout << "aveghw: " << student.average() << endl;
            cout << "mdtermscr: " << student.midterm_score << endl;
            cout << "finalscr: " << student.final_score << endl;
            found = true;
            break;  
        }
    }
    
    if (!found) {
        cout << "student not found: " << name << endl;
    }
}
 
bool compareFinal(const Student& a, const Student& b) {
    return a.final_score > b.final_score;
}
bool comparemax(const Student& a, const Student& b) {
    return a.maxscore > b.maxscore;
}
bool comparemin(const Student& a, const Student& b) {
    return a.minscore> b.minscore;
}
bool compareave(const Student& a, const Student& b) {
    return a.avgscore> b.avgscore;
}
int main() {
    ifstream file("Student_info.txt");
    if (!file.is_open()) {
        cout << "cannot open file" << endl;
        return 1;
    }
    vector<Student> students;
    
    
    string tmp;
    getline(file, tmp); 

    Student s;
    while (file >> s.name >> s.student_id) {
        for (int i = 0; i < 10; i++) 
            file >> s.hw_scores[i];
        file >> s.attendance_score >> s.midterm_score >> s.final_score;
        s.calculate(); 
        students.push_back(s);
    }
    name(students, "Zeus");//名字在这里,想找谁往引号里输!!!
    sort(students.begin(), students.end(), compareFinal);
    cout << "\npaiming:\n";
    cout <<  "name        " << "final score" << endl;
    cout << "---------------------" << endl;
    for (const auto& student : students) {
        cout <<student.name << "   "<<student.final_score << endl;
    }
    cout << "---------------------" << endl;
    sort(students.begin(), students.end(), comparemax);
    cout <<  "name       " << "max score" << endl;
    cout << "---------------------" << endl;
    for (const auto& student : students) {
        cout << student.name<<"   " << student.maxscore << endl;
    } 
    cout << "---------------------" << endl;
    sort(students.begin(), students.end(), comparemin);
    cout <<  "name       " << "min score" << endl;
    cout << "---------------------" << endl;
    for (const auto& student : students) {
        cout <<  student.name<<"   " << student.minscore << endl;
    }
    cout << "---------------------" << endl;
    sort(students.begin(), students.end(), compareave);
    cout  << "name      " << "ave score" << endl;
    cout << "---------------------" << endl;
    for (const auto& student : students) {
        cout << student.name<<"   " << student.avgscore << endl;
    }
    cout << "---------------------" << endl;

    return 0;
}