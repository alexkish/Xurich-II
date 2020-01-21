
	const char *EventListFolder = "./EventList";
	ofstream EventListAscii;
	
	Char_t  char_EventListAscii[500];
	sprintf(char_EventListAscii,	"%s/%s_%s.list", EventListFolder, DataSet1, CutName);

	Char_t  char_EventListRoot[500];
	sprintf(char_EventListRoot,	"%s/%s_%s.root", EventListFolder, DataSet1, CutName);

	EventListAscii.open(char_EventListAscii);

	//T1->SetMakeClass(1);

	int max_peaks_num = 4; //Depends on the processing (to be set by hands)

	T1->Draw(">>EventList", cut_all);
	TEventList *EventList = (TEventList*)gDirectory->Get("EventList");


	// SAVE IN A ROOT FILE
	TFile *EventListRoot = new TFile(char_EventListRoot,"recreate");
	EventList		->Write();
	EventListRoot	->Close();
		
/*	// SAVE AS ASCII FILE
	string *filename =0;
	int tracenum;

	T1->SetBranchAddress("Filename",&filename);
	T1->SetBranchAddress("Event",&tracenum);

	int nEvents = EventList -> GetN();

	for(int iEv=0; iEv<nEvents; iEv++){
	T1->GetEntry(EventList->GetEntry(iEv));
	//EventListAscii << EventList->GetEntry(iEv) << endl;
	EventListAscii << (filename) <<"\t" << tracenum << endl;
	}
	EventListAscii.close();
*/

/*	// write scan list
	((TTreePlayer*)(T1->GetPlayer()))->SetScanRedirect(true);
	T1->SetScanField(0);
	Char_t  ScanList[500];
	sprintf(ScanList,	"%s/%s_%s.scan", outFolder_EventList, DataSet1, CutName);

	((TTreePlayer*)(T1->GetPlayer()))->SetScanFileName(ScanList);
	//T1->Scan("S1peaks_top:S1maxposRawPMT1[0]:S1peaks_bot:S1maxposRawPMT2[0]:S2peaks_top:S2maxposRawPMT1[0]:S2peaks_bot:S2maxposRawPMT2[0]:S2maxRawPMT2[0]:S2maxRawPMT2[1]", cut_all, "colsize=18");
	T1->Scan("S1peaks_top:S1maxposRawPMT1[0]:S1peaks_bot:S1maxposRawPMT2[0]:S2peaks_top:S2maxposRawPMT1[0]:S2peaks_bot:S2maxposRawPMT2[0]", cut_all, "colsize=18");
*/



	////////////////////////////////////////////
	// CREATE THE MAIN FOLDER TO SAVE THE PLOTS	
	char outFolder_dataset[500];
	//sprintf(outFolder_dataset, "./plots/farm/%s_%s", DataSet1, CutName);
	//sprintf(outFolder_dataset, "./plots/chi2/%s_%s", DataSet1, CutName);
	//sprintf(outFolder_dataset, "./plots/fra/%s_%s", DataSet1, CutName);
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);

	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);

	gROOT->ProcessLine(mkdir_outFolder_dataset);


/*


T1->SetBranchAddress("Filename",&filename);
T1->SetBranchAddress("Event",&tracenum);

//Make here your main cut
TCut mainCut ("S1_bot > 350 && S1_bot < 400 && Chi2_bot > 0.034 && Chi2_bot < 0.037");

T1->Draw(">>EvList",mainCut);
TEventList *EvList = (TEventList*)gDirectory->Get("EvList");
int nEvents = EvList -> GetN();
ofstream listfile( outfilename.c_str() );
for(int iEv=0; iEv<nEvents; iEv++){
	int chainEntry = EvList->GetEntry(iEv);
	T1->GetEntry(chainEntry);
	listfile << (*filename) << "\t" << tracenum << endl;
*/