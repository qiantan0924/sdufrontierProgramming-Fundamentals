#include<iostream>
using namespace std;
void FillHist(string filename,TH2D*h)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open()){
    cout <<"cannot found file"<<endl;
    return;}
    double energy,theta,phi;
    while(file>>energy){
        file >>theta>>phi;
        h->Fill(energy,theta*180./3.1415926);
        
        if (file.eof())
        break;
    }
    file.close();
}
void exa2(){
    TH2D*hist=new TH2D("hist","energy,theta",100,0,2500,70,0,7);
    hist->SetTitle("energy;#theta[deg];E[mev]");
    
    FillHist("root_data_file.txt",hist);
    TCanvas*c1=new TCanvas("c1","ENERGY",1200,800);
    c1->cd();
    hist->Draw("colz");
    //hist->Draw("box");
    //hist->Draw("contz");
    //hist->Draw("lego1");
    //hist->Draw("surf1");
    //hist->Draw("surf2z");
}
