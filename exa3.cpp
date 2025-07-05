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
void exa3(){
    TH2D*hist=new TH2D("hist","energy,theta",100,0,2500,70,0,7);
    hist->SetTitle("energy;#theta[deg];E[mev]");
    
    FillHist("root_data_file.txt",hist);
    TH1D*projh2X=hist->ProjectionX();
    TH1D*projh2Y=hist->ProjectionY();
    projh2X->SetTitle("projection,x value,count");
    projh2X->SetLineColor(2);
    projh2X->SetLineWidth(2);
    projh2Y->SetTitle("projection,y value,count");
    projh2Y->SetLineColor(3);
    projh2Y->SetLineWidth(2);
    TCanvas*ca=new TCanvas("ca","ENERGY",1200,800);
    ca->cd();
    hist->Draw("colz");
    TCanvas*cb=new TCanvas("cb","x",1200,800);
    cb->cd();
    projh2X->Draw("HIST");
    TCanvas*cc=new TCanvas("cc","y",1200,800);
    cc->cd();
    projh2Y->Draw("HIST");
    
    //hist->Draw("box");
    //hist->Draw("contz");
    //hist->Draw("lego1");
    //hist->Draw("surf1");
    //hist->Draw("surf2z");
}
