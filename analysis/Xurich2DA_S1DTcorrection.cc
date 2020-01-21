	// MAKE OUT FOLDERS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_S1DTcorrection[500];
	sprintf(outFolder_S1DTcorrection, "%s/S1DTcorrection", outFolder_dataset);
	char mkdir_outFolder_S1DTcorrection[500];
	sprintf(mkdir_outFolder_S1DTcorrection, ".mkdir %s", outFolder_S1DTcorrection);
	gROOT->ProcessLine(mkdir_outFolder_S1DTcorrection);


	// DEFINE RANGES
	int nbins_S1		= 200;
	double min_S1		= 0;
	double max_S1		= 1600;

	int nbins_S1top		= 200;
	double min_S1top	= 0;
	double max_S1top	= 1600;

	int nbins_S1bot	= 200;
	double min_S1bot	= 0;
	double max_S1bot	= 1600;

	int nbins_dt	= 200;
	double min_dt	= 0.;
	double max_dt	= 18.;

	TH2F *h2_S1vsDT 	= new TH2F("h2_S1vsDT",		"", nbins_dt, min_dt, max_dt, 	nbins_S1, min_S1, max_S1);
	TH2F *h2_S1TOPvsDT 	= new TH2F("h2_S1TOPvsDT",	"", nbins_dt, min_dt, max_dt, 	nbins_S1, min_S1, max_S1);
	TH2F *h2_S2BOTvsDT 	= new TH2F("h2_S1BOTvsDT",	"", nbins_dt, min_dt, max_dt, 	nbins_S1, min_S1, max_S1);

	TCanvas *c_S1vsDT = new TCanvas("c_S1vsDT", "c_S1vsDT", 0, 0, 700, 500);
			 c_S1vsDT->SetFillColor(10);
    		 c_S1vsDT->SetLogz();
		T1	->Draw("S1totalPE:dt_top>>h2_S1vsDT", "",	"COLZ");
		h2_S1vsDT	-> GetXaxis() -> SetTitle("drift time [#mus]");
		h2_S1vsDT	-> GetYaxis() -> SetTitle("largest S1 [PE]");
		h2_S1vsDT	-> GetXaxis() -> CenterTitle(true);
		h2_S1vsDT	-> GetYaxis() -> CenterTitle(true);
	c_S1vsDT->Update();

	TCanvas *c_S1TOPvsDT = new TCanvas("c_S1TOPvsDT", "c_S1TOPvsDT", 705, 0, 700, 500);
			 c_S1TOPvsDT->SetFillColor(10);
    		 c_S1TOPvsDT->SetLogz();
		T1	->Draw("S1topPE:dt_top>>h2_S1TOPvsDT", "",	"COLZ");
		h2_S1TOPvsDT	-> GetXaxis() -> SetTitle("drift time [#mus]");
		h2_S1TOPvsDT	-> GetYaxis() -> SetTitle("largest S1 top [PE]");
		h2_S1TOPvsDT	-> GetXaxis() -> CenterTitle(true);
		h2_S1TOPvsDT	-> GetYaxis() -> CenterTitle(true);
	c_S1TOPvsDT->Update();

	TCanvas *c_S1BOTvsDT = new TCanvas("c_S1BOTvsDT", "c_S1BOTvsDT", 1410, 0, 700, 500);
			 c_S1BOTvsDT->SetFillColor(10);
    		 c_S1BOTvsDT->SetLogz();
		T1	->Draw("S1botPE:dt_top>>h2_S1BOTvsDT", "",	"COLZ");
		h2_S1BOTvsDT	-> GetXaxis() -> SetTitle("drift time [#mus]");
		h2_S1BOTvsDT	-> GetYaxis() -> SetTitle("largest S1 bottom [PE]");
		h2_S1BOTvsDT	-> GetXaxis() -> CenterTitle(true);
		h2_S1BOTvsDT	-> GetYaxis() -> CenterTitle(true);
	c_S1BOTvsDT->Update();


	const int nSlices = 36; // number of slices

	double xmean, xinterval;
	double ymean, ysigma, ymeanEr, ysigmaEr;
	double median, medianError;
	double ymean_top, ysigma_top, ymeanEr_top, ysigmaEr_top;
	double median_top, medianError_top;
	double ymean_bot, ysigma_bot, ymeanEr_bot, ysigmaEr_bot;
	double median_bot, medianError_bot;

	double x[nSlices], 	xer[nSlices];
	double y[nSlices], 	yer[nSlices];
	double yM[nSlices], yMer[nSlices];

	double y1p[nSlices];
	double y1m[nSlices];

	double min_DT = 0;
	double max_DT = 18;
	double min_DTslice, max_DTslice;
	double DTinterval = (max_DT-min_DT)/nSlices;

	double fitS1_min;
	double fitS1_max;

	double fitS1top_min;
	double fitS1top_max;

	double fitS1bot_min;
	double fitS1bot_max;

	ofstream OutFile;
	Char_t  OutFile_char[500];
	sprintf(OutFile_char, "%s/S1slices.dat", outFolder_S1DTcorrection);
	OutFile.open(OutFile_char);

	ofstream OutFileTop;
	Char_t  OutFileTop_char[500];
	sprintf(OutFileTop_char, "%s/S1TOPslices.dat", outFolder_S1DTcorrection);
	OutFileTop.open(OutFileTop_char);

	ofstream OutFileBot;
	Char_t  OutFileBot_char[500];
	sprintf(OutFileBot_char, "%s/S1BOTslices.dat", outFolder_S1DTcorrection);
	OutFileBot.open(OutFileBot_char);

	for (int i=0; i<nSlices; i++){

		min_DTslice = min_DT + i*DTinterval;
		max_DTslice = min_DTslice + DTinterval;
		
		Char_t  Hname[500];
		sprintf(Hname, "slice_%d", i+1);
		sprintf(Hname, "slice %d, %g us < dt < %g us ", i+1, min_DTslice, max_DTslice);
		//cout << Hname <<" S1: "<< min_S1slice <<" - "<< max_S1slice <<" phe"<< endl;
		cout << Hname << endl;

		TH1F *h1_S1slice = new TH1F("h1_S1slice", Hname, nbins_S1, min_S1, max_S1);
			  h1_S1slice->SetLineColor(1);
			  h1_S1slice->SetLineWidth(2);

		TH1F *h1_S1TOPslice = new TH1F("h1_S1TOPslice", Hname, nbins_S1, min_S1, max_S1);
			  h1_S1TOPslice->SetLineColor(1);
			  h1_S1TOPslice->SetLineWidth(2);

		TH1F *h1_S1BOTslice = new TH1F("h1_S1BOTslice", Hname, nbins_S1, min_S1, max_S1);
			  h1_S1BOTslice->SetLineColor(1);
			  h1_S1BOTslice->SetLineWidth(2);
		
		// define fit range for each slice
		#include "S1DTcorrection_DefineFitRanges_40bins.cc"

		// Gaussian Fit
		TF1 *S1sliceFit = new TF1("S1sliceFit","gaus", fitS1_min, fitS1_max);
			 S1sliceFit->SetLineColor(2);
			 S1sliceFit->SetLineWidth(2);

		TF1 *S1TOPsliceFit = new TF1("S1TOPsliceFit","gaus", fitS1_min, fitS1_max);
			 S1TOPsliceFit->SetLineColor(2);
			 S1TOPsliceFit->SetLineWidth(2);

		TF1 *S1BOTsliceFit = new TF1("S1BOTsliceFit","gaus", fitS1_min, fitS1_max);
			 S1BOTsliceFit->SetLineColor(2);
			 S1BOTsliceFit->SetLineWidth(2);
		
		// S1 slicing cut
		TCut cut_DTslice	= Form("dt_top > %g && dt_top < %g", min_DTslice, max_DTslice);
		
		// PLOT
		TCanvas *c_S1slice = new TCanvas("c_S1slice", "c_S1slice", 0, 0, 700, 500);
				 c_S1slice->SetFillColor(10);
				 //c_S1slice->SetGrid();
			// fill histogram
			T1->Draw("S1totalPE>>h1_S1slice", cut_all && cut_DTslice,"");
			h1_S1slice	->GetXaxis()->SetTitle("S1 total [PE]");
			h1_S1slice	->GetYaxis()->SetTitle("Counts");
			h1_S1slice	->GetXaxis()->CenterTitle(true);
			h1_S1slice	->GetYaxis()->CenterTitle(true);
			// fit histogram
			h1_S1slice->Fit(S1sliceFit,"R");
			S1sliceFit->Draw("SAME");		
		c_S1slice->Update();

		TCanvas *c_S1TOPslice = new TCanvas("c_S1TOPslice", "c_S1TOPslice", 0, 0, 700, 500);
				 c_S1TOPslice->SetFillColor(10);
				 //c_S1TOPslice->SetGrid();
			// fill histogram
			T1->Draw("S1topPE>>h1_S1TOPslice", cut_DTslice,"");
			h1_S1TOPslice	->GetXaxis()->SetTitle("S1 top [PE]");
			h1_S1TOPslice	->GetYaxis()->SetTitle("Counts");
			h1_S1TOPslice	->GetXaxis()->CenterTitle(true);
			h1_S1TOPslice	->GetYaxis()->CenterTitle(true);
			// fit histogram
			h1_S1TOPslice->Fit(S1TOPsliceFit,"R");
			S1TOPsliceFit->Draw("SAME");		
		c_S1slice->Update();

		TCanvas *c_S1BOTslice = new TCanvas("c_S1BOTslice", "c_S1BOTslice", 0, 0, 700, 500);
				 c_S1BOTslice->SetFillColor(10);
				 //c_S1BOTslice->SetGrid();
			// fill histogram
			T1->Draw("S1botPE>>h1_S1slice", cut_all && cut_DTslice,"");
			h1_S1BOTslice	->GetXaxis()->SetTitle("S1 bottom [PE]");
			h1_S1BOTslice	->GetYaxis()->SetTitle("Counts");
			h1_S1BOTslice	->GetXaxis()->CenterTitle(true);
			h1_S1BOTslice	->GetYaxis()->CenterTitle(true);
			// fit histogram
			h1_S1BOTslice->Fit(S1BOTsliceFit,"R");
			S1BOTsliceFit->Draw("SAME");		
		c_S1BOTslice->Update();

	
		xmean 		= min_DTslice + (max_DTslice - min_DTslice)/2;
		xinterval 	= (max_DTslice - min_DTslice)/2;
		x[i] 		= xmean;
		xer[i] 		= xinterval;
	
		ymean 				= S1sliceFit->GetParameter(1);
		ymeanEr 			= S1sliceFit->GetParError(1);
		ysigma 				= S1sliceFit->GetParameter(2);
		ysigmaEr 			= S1sliceFit->GetParError(2);
		median 				= h1_S1slice->GetMean();
		medianError 		= h1_S1slice->GetMean();

		ymean_top 			= S1TOPsliceFit->GetParameter(1);
		ymeanEr_top 		= S1TOPsliceFit->GetParError(1);
		ysigma_top 			= S1TOPsliceFit->GetParameter(2);
		ysigmaEr_top 		= S1TOPsliceFit->GetParError(2);
		median_top 			= h1_S1TOPslice->GetMean();
		medianError_top 	= h1_S1TOPslice->GetMean();

		ymean_bot 			= S1BOTsliceFit->GetParameter(1);
		ymeanEr_bot 		= S1BOTsliceFit->GetParError(1);
		ysigma_bot 			= S1BOTsliceFit->GetParameter(2);
		ysigmaEr_bot 		= S1BOTsliceFit->GetParError(2);
		median_bot 			= h1BOT_S1slice->GetMean();
		medianError_bot 	= h1BOT_S1slice->GetMean();

		cout <<"median = "<< median <<" +- "<< medianError << endl;
		
		y[i]	= ymean;
		y1p[i]	= (ymean+1*ysigma);
		y1m[i]	= (ymean-1*ysigma);
		y2p[i]	= (ymean+2*ysigma);
		y2m[i]	= (ymean-2*ysigma);
		y3p[i]	= (ymean+3*ysigma);
		y3m[i]	= (ymean-3*ysigma);

		yM[i]	= median;
		yMer[i]	= medianError;
		yer[i] = ysigma;
	

		OutFile		<< xmean			<<" "
					<< xinterval		<<" "
					<< ymean 			<<" "
					<< ymeanEr 			<<" "
					<< ysigma			<<" "
					<< ysigmaEr			<<" "<< endl;

		OutFileTop	<< xmean			<<" "
					<< xinterval		<<" "
					<< ymean_top 		<<" "
					<< ymeanEr_top 		<<" "
					<< ysigma_top		<<" "
					<< ysigmaEr_top		<<" "<< endl;

		OutFileBot	<< xmean			<<" "
					<< xinterval		<<" "
					<< ymean_bot 		<<" "
					<< ymeanEr_bot 		<<" "
					<< ysigma_bot		<<" "
					<< ysigmaEr_bot		<<" "<< endl;
				
		Char_t  Sname[500];
		sprintf(Sname, "%s/S1slice_%d.png", outFolder_S1DTcorrection, i+1);
		c_S1slice->Print(Sname);

		Char_t  SnameTOP[500];
		sprintf(SnameTOP, "%s/S1TOPslice_%d.png", outFolder_S1DTcorrection, i+1);
		c_S1TOPslice->Print(SnameTOP);

		Char_t  SnameBOT[500];
		sprintf(SnameBOT, "%s/S1BOTslice_%d.png", outFolder_S1DTcorrection, i+1);
		c_S1BOTslice->Print(SnameBOT);

	}

	
	OutFile.close();
	OutFileTop.close();
	OutFileBot.close();
	

	TGraph *grMean = new TGraph(nSlices, x, y);
			grMean->SetMarkerStyle(8);
			grMean->SetMarkerSize(0.6);
			grMean->SetMarkerColor(1);
			grMean->SetLineColor(1);
			grMean->SetLineWidth(2);
	TGraphErrors *grMedian = new TGraphErrors(nSlices, x, yM, xer, yMer);
				  grMedian->SetMarkerStyle(8);
				  grMedian->SetMarkerSize(0.6);
				  grMedian->SetMarkerColor(1);
				  grMedian->SetLineColor(1);
				  grMedian->SetLineWidth(1);


	TGraph *gr1p = new TGraph(nSlices, x, y1p);
			gr1p->SetMarkerStyle(8);
			gr1p->SetMarkerSize(0.6);
			gr1p->SetMarkerColor(1);
			gr1p->SetLineColor(1);
			gr1p->SetLineWidth(2);
	TGraph *gr1m = new TGraph(nSlices, x, y1m);
			gr1m->SetMarkerStyle(8);
			gr1m->SetMarkerSize(0.6);
			gr1m->SetMarkerColor(1);
			gr1m->SetLineColor(1);
			gr1m->SetLineWidth(2);

	c_S1vsDT->cd();
		grMean		->Draw("PСC same");
		gr1p		->Draw("PСC same");
		gr1m		->Draw("PСC same");

	Char_t  char_S1vsDT_withFits[500];
	sprintf(char_S1vsDT_withFits, "%s/%s_S1vsDT-withFits%s", outFolder_dataset, DataSet1, extensionPlots); 
	c_S1vsDT->SaveAs(char_S1vsDT_withFits);


