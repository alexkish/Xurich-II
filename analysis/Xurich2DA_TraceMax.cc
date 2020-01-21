	int nbins_TraceMax		= 1000;
	double min_TraceMax		= 0;
	double max_TraceMax		= 16e3;

	TH1F *h1_TraceMaxPMT1 = new TH1F("h1_TraceMaxPMT1", DataSetName1, nbins_TraceMax, min_TraceMax, max_TraceMax);
		  h1_TraceMaxPMT1 ->SetLineColor(4);
	TH1F *h1_TraceMaxPMT2 = new TH1F("h1_TraceMaxPMT2", DataSetName1, nbins_TraceMax, min_TraceMax, max_TraceMax);
		  h1_TraceMaxPMT2 ->SetLineColor(2);


	TCanvas *c_TraceMax = new TCanvas("c_TraceMax", "c_TraceMax", 0, 0, 700, 500);
			 c_TraceMax->SetFillColor(10);
    		 //c_S1->SetLogy();
		T1 ->Draw("TraceMaxPMT1>>h1_TraceMaxPMT1",	cut_all,	"");
		T1 ->Draw("TraceMaxPMT2>>h1_TraceMaxPMT2",	cut_all,	"same");
		//h1_S1 	->Scale(ScalingFactor);
		//h1_S1 	->Scale(1e3);
		h1_TraceMaxPMT1	-> GetXaxis() -> SetTitle("Maximum amplitude in the trace [ADC channels]");
		h1_TraceMaxPMT1	-> GetYaxis() -> SetTitle("Counts");
		h1_TraceMaxPMT1	-> GetXaxis() -> CenterTitle(true);
		h1_TraceMaxPMT1	-> GetYaxis() -> CenterTitle(true);
	c_TraceMax->Update();
