#include <iostream>
#include "TH1D.h"
#include "TCanvas.h"
#include "TSystem.h" 
#include "TLegend.h"
#include <fstream>
using namespace std;

void FillHist(string filename, TH1D* h)
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
        h->Fill(Eprime);
        if (file.eof()) break;
    }
    file.close();
}

void Draw1DHist()
{
   
    TH1D* hist = new TH1D("hist", "E' distribution", 100, 0, 2100);
    hist->SetTitle("E' distribution; E' [MeV] ; count");
    hist->SetLineColor(2);
    hist->SetLineWidth(1);

    TH1D* hist1 = new TH1D("hist1", "E' distribution", 100, 0, 2100);
    hist1->SetTitle("E' distribution; E' [MeV] ; count");
    hist1->SetLineColor(4);
    hist1->SetLineWidth(1);
    FillHist("elastic_ep_rd.txt", hist);
    FillHist("pb_inel_rd.txt", hist1);

    TCanvas* c1 = new TCanvas("c1", "same name", 1200, 800);
    c1->SetLogy();
    hist->Draw("E");
    hist1->Draw("same");  
    cout << gSystem << endl;
    cout << "Current dir: " << gSystem->pwd() << endl; 
    hist->SetBinContent(12, 3456);  
//double val = hist->GetBinContent(12);  
//hist->SetLineColor(kRed);
//hist->SetLineWidth(5);
//double total = hist->Integral(200,300);
//hist->Rebin(2);  
//hist->Sumw2();  
//hist->Draw("E");  
}