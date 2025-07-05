

void bighomework() {
    
    TFile* file = TFile::Open("1GeV_BeamOnTarget_1e10_reduced.root");
    if (!file || file->IsZombie()) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }
    TTree* tree = nullptr;
    file->GetObject("T", tree);
    if (!tree) {
        cout << "Error: Cannot find TTree!" << endl;
        file->Close();
        return;
    }

    unsigned short NPar;
    const int MAX_PAR = 3688;  
    short PID[MAX_PAR];
    float x[MAX_PAR], y[MAX_PAR], p[MAX_PAR];
    const double targetdensity = 0.0708;    
    const double targetlength = 1.0;       
    const double proton_mass = 938.0;       
    const double avogadro = 6.022e23;      
    const double npr = (targetdensity * avogadro) / 1.008;  
    const double nele = npr;     
    const double itgep = 1e9 * npr * targetlength;  
    const double itgee = 1e9 * nele * targetlength;

  
    
    tree->SetBranchAddress("NPar", &NPar);
    tree->SetBranchAddress("PID", PID);
    tree->SetBranchAddress("x", x);
    tree->SetBranchAddress("y", y);
    tree->SetBranchAddress("p", p);
    TH2D* h2 = new TH2D("h2", 
                    "Electron scattering from target;Scattering angle [deg];Momentum [MeV]",
                    180, 0, 7,   
                    100, 0,1002); 
    h2->SetTitle("Electron scattering;Scattering angle [deg];Momentum [MeV];Counts");
   TH1D* h1ee = new TH1D("h1ee", "Scattering angle [deg];Counts", 500, 0.6, 5.6);
   TH1D* h1ep = new TH1D("h1ep", "Scattering angle [deg];Counts", 500, 0.6, 5.6);
    const double detector_z = 500.0;  

    int ety = tree->GetEntries();
    for (int i = 0; i < ety; ++i) {
        tree->GetEntry(i);
        
        for (unsigned short j = 0; j < NPar; ++j) {
            if (PID[j] != 11) continue; 
            
            double r_hit = sqrt(x[j]*x[j] + y[j]*y[j]);
            if (r_hit < 5. || r_hit > 60.) continue;  
            
            double theta = atan(r_hit / detector_z) * TMath::RadToDeg();
            h2->Fill(theta, p[j]);
            double expecteeenergy = 1000.0; 
            Double_t expectepenergy = 1000.0 / (1.0 + (1000.0/938.0)*(1.0 - TMath::Cos(theta)));

            
            if (TMath::Abs(p[j] - expecteeenergy) < 5.0) {
                h1ee->Fill(theta);
            } else if (TMath::Abs(p[j] - expectepenergy) < 5.0) {
                h1ep->Fill(theta);
        }}
    }
    const double binwiddeg = h1ep->GetBinWidth(1);
      
     const double binwids = 2*TMath::Pi() * (TMath::Cos(0.6*TMath::DegToRad()) - 
                                      TMath::Cos(5.6*TMath::DegToRad()));
    h1ee->Scale(1.0 / (itgee * binwids));
    h1ep->Scale(1.0 / (itgep * binwids));
    
    h1ee->GetYaxis()->SetTitle("d#sigma/d#Omega [cm^{2}/sr]");
    h1ep->GetYaxis()->SetTitle("d#sigma/d#Omega [cm^{2}/sr]");

    TCanvas* c1 = new TCanvas("c1", "Analysis Results", 1200, 800);
    c1->Divide(2, 2);

    c1->cd(1);
    h2->Draw("LEGO");

    c1->cd(2);
    h1ep->Draw("HIST");
    h1ep->SetFillColor(kRed);

    c1->cd(3);
    h1ee->Draw("HIST");
    h1ee->SetFillColor(kBlue);
   
}