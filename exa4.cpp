void FillHist(string filename, TH2D* h) {
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    
    double energy, theta, phi;
    while(file >> energy) {
        file >> theta >> phi;
        h->Fill(energy, theta*180./3.1415926);
        if (file.eof()) break;
    }
    file.close();
}
void exa4() {
    TH2D* hist = new TH2D("hist", "E' vs #theta;E' [MeV];#theta [deg]", 100, 0, 2500, 70, 0, 7);    

    FillHist("root_data_file.txt", hist);

    const double theta_ranges[3][2] = {
        {0.8*180/3.1415926, 1.0*180/3.1415926},  
        {1.0*180/3.1415926, 2.0*180/3.1415926},  
        {2.0*180/3.1415926, 3.5*180/3.1415926}  
    };

    TH1D* slices[3];
    const Color_t colors[3] = {kRed, kBlue, kGreen+2}; 
    const char* names[3] = {
        "0.8 < #theta < 1.0 rad", 
        "1.0 < #theta< 2.0 rad", 
        "2.0 < #theta < 3.5 rad"
    };

    for (int i = 0; i < 3; i++) { 
        int first_bin = hist->GetYaxis()->FindBin(theta_ranges[i][0]);
        int last_bin = hist->GetYaxis()->FindBin(theta_ranges[i][1]);
        slices[i] = hist->ProjectionX(
            Form("slice%d", i), 
            first_bin,          
            last_bin            
        );
        slices[i]->SetTitle("E' distribution for different #theta ranges");
        slices[i]->SetLineColor(colors[i]);
        slices[i]->SetLineWidth(2);
        slices[i]->SetStats(0);  
    }

    TCanvas* c_1 = new TCanvas("c_main", "E' Slices by θ", 1200, 800);
    c_1->SetGrid();
    slices[0]->Draw("HIST");
    slices[0]->GetYaxis()->SetRangeUser(0, 1.2*slices[0]->GetMaximum());
    slices[0]->SetXTitle("E' [MeV]");
    slices[0]->SetYTitle("Counts");
    slices[1]->Draw("HIST SAME");
    slices[2]->Draw("HIST SAME");

    TLegend* leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    for (int i = 0; i < 3; i++) {
        leg->AddEntry(slices[i], names[i], "l");
    }
    leg->SetBorderSize(0);
    leg->Draw();

    TCanvas* c_2d = new TCanvas("c_2d", "2D Distribution", 1200, 800);
    hist->Draw("COLZ");

    TCanvas* c_projx = new TCanvas("c_projx", "Full ProjectionX", 1200, 800);
    TH1D* projX = hist->ProjectionX();
    projX->SetTitle("Full E' projection;E' [MeV];Counts");
    projX->SetLineColor(kBlack);
    projX->Draw("HIST");
}