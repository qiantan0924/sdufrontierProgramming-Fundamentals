void exa5() {
    TFile *file = TFile::Open("trackHits.root");
    TTree *tree = (TTree*)file->Get("t");
    tree->Print();
    tree->Draw("evt");  
    map<int, int> pdg_to_track = {
        {11, 0},   
        {-11, 1},  
        {13, 2},  
        {-13, 3}   
    };
    vector<vector<double>> track_x(4), track_y(4);
    int evt, pdg;
    double x, y;
    tree->SetBranchAddress("evt", &evt);
    tree->SetBranchAddress("pdg", &pdg);
    tree->SetBranchAddress("x", &x);
    tree->SetBranchAddress("y", &y);

    for (int i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);
        if (evt != 0) continue;  

        auto it = pdg_to_track.find(pdg);
        if (it != pdg_to_track.end()) {
            int track_id = it->second;
            track_x[track_id].push_back(x);
            track_y[track_id].push_back(y);
        }
    }

}