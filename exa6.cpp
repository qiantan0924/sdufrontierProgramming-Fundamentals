
void exa6() {
    TFile *infile = TFile::Open("trackHits.root");
    if (!infile || infile->IsZombie()) {
        Error("save_by_event", "cantopenfile");
        return;
    }

    TTree *intree = (TTree*)infile->Get("t");
    if (!intree) {
        Error("save_by_event", "notfoundtree");
        infile->ls();
        infile->Close();
        return;
    }
    int evt = -1, pdg = 0;
    double x = 0, y = 0, ex1 = 0, ex2 = 0, ey1 = 0, ey2 = 0;

    if (intree->GetBranch("evt"))  intree->SetBranchAddress("evt", &evt);
    if (intree->GetBranch("eventID")) intree->SetBranchAddress("eventID", &evt);
    
    intree->SetBranchAddress("pdg", &pdg);
    intree->SetBranchAddress("x", &x);
    intree->SetBranchAddress("y", &y);
    intree->SetBranchAddress("ex1", &ex1);
    intree->SetBranchAddress("ex2", &ex2);
    intree->SetBranchAddress("ey1", &ey1);
    intree->SetBranchAddress("ey2", &ey2);

    TFile *outfile = new TFile("events_saved.root", "RECREATE");
    TTree *outtree = new TTree("events", "statics");
    const int MAX_HITS = 500;
    int eventID = -1, nHits = 0;
    double x_arr[MAX_HITS], y_arr[MAX_HITS];
    double ex1_arr[MAX_HITS], ex2_arr[MAX_HITS];
    double ey1_arr[MAX_HITS], ey2_arr[MAX_HITS];
    int pdg_arr[MAX_HITS];

    outtree->Branch("eventID", &eventID, "eventID/I");
    outtree->Branch("nHits", &nHits, "nHits/I");
    outtree->Branch("x", x_arr, "x[nHits]/D");
    outtree->Branch("y", y_arr, "y[nHits]/D");
    outtree->Branch("ex1", ex1_arr, "ex1[nHits]/D");
    outtree->Branch("ex2", ex2_arr, "ex2[nHits]/D");
    outtree->Branch("ey1", ey1_arr, "ey1[nHits]/D");
    outtree->Branch("ey2", ey2_arr, "ey2[nHits]/D");
    outtree->Branch("pdg", pdg_arr, "pdg[nHits]/I");

    int current_event = -999; 
    for (int i = 0; i < intree->GetEntries(); i++) {
        intree->GetEntry(i);

        if (evt != current_event) {
            if (current_event != -999 && nHits > 0) {
                outtree->Fill(); 
            }
            current_event = evt;
            eventID = evt;
            nHits = 0;
        }

        if (nHits < MAX_HITS) {
            x_arr[nHits] = x;
            y_arr[nHits] = y;
            ex1_arr[nHits] = ex1;
            ex2_arr[nHits] = ex2;
            ey1_arr[nHits] = ey1;
            ey2_arr[nHits] = ey2;
            pdg_arr[nHits] = pdg;
            nHits++;
        }
    }

    if (nHits > 0) {
        outtree->Fill();
    }
    outfile->Write();
    outfile->Close();
    infile->Close();

    Info("save_by_event", "save in events_saved.root");
}