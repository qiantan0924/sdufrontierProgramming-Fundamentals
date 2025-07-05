#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
#include<iomanip>
#include  <sstream>
#include  <numeric>
using namespace std;

struct reslt{
    string name;
    double ave;
    double var;
};
vector <double> score(string&str){
    vector<double> scrs;
    stringstream ss(str);  
    string item;
    ss >> item; 
    while (ss >> item) {
        char* end;
        double score = strtod(item.c_str(), &end);
        if (end != item.c_str() && *end == '\0' && scrs.size() < 10) {
        scrs.push_back(score);
        }
    }
    return scrs;
}
reslt cal(string&k){
   reslt result;
   stringstream ss(k);
   if (!(ss >> result.name)) {
    result.name = "Unknown";
    return result;
} vector<double> scs = score(k);
    
double sum = accumulate(scs.begin(), scs.end(), 0.0);
result.ave = scs.empty() ? 0 : sum / scs.size();

double variance = 0.0;
for (double score : scs) {
    variance += pow(score - result.ave, 2);
}
result.var = scs.empty() ? 0 : sqrt(variance / scs.size());

return result;
}
int main() {
    ifstream inputFile("HW_Score.txt");
    ofstream outputFile("HW_Result.txt");
    if (!inputFile.is_open()) {
        cerr << "ccannot open HW_Score.txt" << endl;
        return 1;
    }
    
    if (!outputFile.is_open()) {
        cerr << "cannot found HW_Result.txt" << endl;
        return 1;
    }
    outputFile << "name    ave      var " << endl; 
    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) continue; 
        reslt result = cal(line);
        outputFile << result.name << " "
                  << fixed << result.ave << " "
                  << fixed  << result.var << endl;
    }
    inputFile.close();
    outputFile.close();
    
    cout << "ok,new statistic load in HW_Result.txt" << endl;
    return 0;
}