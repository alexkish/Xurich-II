	int nbins_tracemax	= 1600;
	double min_tracemax	= 0;
	double max_tracemax	= 16000;

	TH1F *h1_tracemaxTop 	= new TH1F("h1_tracemaxTop",	DataSetName1, nbins_tracemax, min_tracemax, max_tracemax);
	TH1F *h1_tracemaxBot 	= new TH1F("h1_tracemaxBot",	DataSetName1, nbins_tracemax, min_tracemax, max_tracemax);
		  h1_tracemaxTop	->SetLineColor(2);
		  h1_tracemaxBot	->SetLineColor(3);


	int c1x = 1000;
	int c1y = 500;

	TCanvas *c1_tracemax = new TCanvas("c1_tracemax", "c1_tracemax", 0, 0, c1x, c1y);
			 c1_tracemax->SetFillColor(10);
    		 c1_tracemax->SetLogy();
		T1	->Draw("TraceMaxPMT1>>h1_tracemaxTop",	"",	"");
		T1	->Draw("TraceMaxPMT2>>h1_tracemaxBot",	"",	"same");
		h1_tracemaxTop	-> GetXaxis() -> SetTitle("Trace maximum [ADC channels]");
		h1_tracemaxTop	-> GetYaxis() -> SetTitle("Counts");
		h1_tracemaxTop	-> GetXaxis() -> CenterTitle(true);
		h1_tracemaxTop	-> GetYaxis() -> CenterTitle(true);
		h1_tracemaxTop	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_tracemaxTop	-> GetYaxis() -> SetTitleOffset(1.25);

	double tracemaxTop_max = h1_tracemaxTop->GetMaximum();
	double tracemaxBot_max = h1_tracemaxBot->GetMaximum();

	double cut_tracemaxTop = 13500;
	double cut_tracemaxBot = 12500;

	TLine *l_tracemaxTop = new TLine(cut_tracemaxTop, 0, cut_tracemaxTop, tracemaxTop_max);
	TLine *l_tracemaxBot = new TLine(cut_tracemaxBot, 0, cut_tracemaxBot, tracemaxBot_max);
		   l_tracemaxTop ->SetLineColor(2);
		   l_tracemaxBot ->SetLineColor(3);
		   l_tracemaxTop ->SetLineStyle(7);
		   l_tracemaxBot ->SetLineStyle(7);
		   l_tracemaxTop ->Draw("same");
		   l_tracemaxBot ->Draw("same");
	c1_tracemax->Update();



	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_TraceMax[500];
	sprintf(outFolder_TraceMax, "%s/TraceMax", outFolder_dataset);
	char mkdir_outFolder_TraceMax[500];
	sprintf(mkdir_outFolder_TraceMax, ".mkdir %s", outFolder_TraceMax);
	gROOT->ProcessLine(mkdir_outFolder_TraceMax);


	char char_TraceMax[500];
	char char_TraceMax_C[500];

	sprintf(char_TraceMax,		"%s/%s_TraceMax_%s%s",	outFolder_TraceMax, DataSet1, CutName, extensionPlots);
	sprintf(char_TraceMax_C,	"%s/%s_TraceMax_%s%s",	outFolder_TraceMax, DataSet1, CutName, extensionPlots_C);

	c1_tracemax		->SaveAs(char_TraceMax);
	c1_tracemax		->SaveAs(char_TraceMax_C);
