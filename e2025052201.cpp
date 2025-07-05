#include <iostream>
#include <fstream>
using namespace std;
void e2025052201(){
    ifstream Infile;
    Infile.open("elastic_ep_rd.txt")
    if(! Infile.open()){
        cout<<"file not found"<<endl;
        return;
    }
    double Eprime1, theta1, phi1;
    Tfile*outfile=new Tfile("output_example1.root","RECREATE");
    TTree*tree=new TTree("T""T");//lable topic
    tree->branch("E",&Eprime2,"E/D");
    tree->branch("theta",&theta2,"theta/D");
    tree->branch("phi",&phi2,"phi/D");
} 
