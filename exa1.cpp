#include <iostream>
#include "TH1D.h"
#include "TCanvas.h"
#include "TSystem.h" 
#include "TLegend.h"
#include <fstream>
using namespace std;
void FillHist(string filename, TH2D* h)
{
    ifstream file;
    file.open(filename);

    if (!file.is_open()){
        cout<<"input file not found"<<endl;
        return;
    }

    double Eprime, theta, phi;
    while(file>>Eprime){
        file>>theta>>phi;

        h->Fill(theta/3.1415926535*180,Eprime);
        if (file.eof()) break;
    }
    file.close();
}
void exa1(){
    TH2D*hist= new TH2D("hist", "E' v.s.scatter angle",100,0,8,100,0,2100);
    hist->SetTitle("E' v.s.scatter angle;#theta[deg];E[mev]");
    FillHist("elastic_ep_rd.txt", hist);
    FillHist("pb_inel_rd.txt", hist);
    TCanvas* c1 = new TCanvas("c1", "same name", 1200, 800);
    c1->SetLogy();
    hist->Draw("COLZ");
}