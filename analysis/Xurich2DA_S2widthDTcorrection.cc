/*	// MAKE OUT FOLDERS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_S1DTcorrection[500];
	sprintf(outFolder_S1DTcorrection, "%s/S2widthDTcorrection", outFolder_dataset);
	char mkdir_outFolder_S1DTcorrection[500];
	sprintf(mkdir_outFolder_S1DTcorrection, ".mkdir %s", outFolder_S1DTcorrection);
	gROOT->ProcessLine(mkdir_outFolder_S1DTcorrection);
*/

	// DEFINE RANGES
	int nbins_FWHM	= 60;
	double min_FWHM	= 0;
	double max_FWHM	= 0.6;

	int nbins_FWTM	= 75;
	double min_FWTM	= 0;
	double max_FWTM	= 1.5;

	int nbins_dt	= 100;
	double min_dt	= 0.;
	double max_dt	= 18.;

	TH2F *h2_S20_FWHMvsDT_top 	= new TH2F("h2_S20_FWHMvsDT_top",	"", nbins_dt, min_dt, max_dt, 	nbins_FWHM, min_FWHM, max_FWHM);
	TH2F *h2_S20_FWTMvsDT_top 	= new TH2F("h2_S20_FWTMvsDT_top",	"", nbins_dt, min_dt, max_dt, 	nbins_FWTM, min_FWTM, max_FWTM);
	TH2F *h2_S21_FWHMvsDT_top 	= new TH2F("h2_S21_FWHMvsDT_top",	"", nbins_dt, min_dt, max_dt, 	nbins_FWHM, min_FWHM, max_FWHM);
	TH2F *h2_S21_FWTMvsDT_top 	= new TH2F("h2_S21_FWTMvsDT_top",	"", nbins_dt, min_dt, max_dt, 	nbins_FWTM, min_FWTM, max_FWTM);

	TH2F *h2_S20_FWHMvsDT_bot 	= new TH2F("h2_S20_FWHMvsDT_bot",	"", nbins_dt, min_dt, max_dt, 	nbins_FWHM, min_FWHM, max_FWHM);
	TH2F *h2_S20_FWTMvsDT_bot 	= new TH2F("h2_S20_FWTMvsDT_bot",	"", nbins_dt, min_dt, max_dt, 	nbins_FWTM, min_FWTM, max_FWTM);
	TH2F *h2_S21_FWHMvsDT_bot 	= new TH2F("h2_S21_FWHMvsDT_bot",	"", nbins_dt, min_dt, max_dt, 	nbins_FWHM, min_FWHM, max_FWHM);
	TH2F *h2_S21_FWTMvsDT_bot 	= new TH2F("h2_S21_FWTMvsDT_bot",	"", nbins_dt, min_dt, max_dt, 	nbins_FWTM, min_FWTM, max_FWTM);


	// S2[0]
	TCanvas *c_S20_FWHMvsDT_top = new TCanvas("c_S20_FWHMvsDT_top", "c_S20_FWHMvsDT_top", 0, 0, 700, 500);
			 c_S20_FWHMvsDT_top->SetFillColor(10);
    		 c_S20_FWHMvsDT_top->SetLogz();
		T1	->Draw("S2width_top:dt_top>>h2_S20_FWHMvsDT_top", "",	"COLZ");
		h2_S20_FWHMvsDT_top	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S20_FWHMvsDT_top	-> GetYaxis() -> SetTitle("S2[0] FWHM, top [#mus]");
		h2_S20_FWHMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S20_FWHMvsDT_top	-> GetYaxis() -> CenterTitle(true);
	c_S20_FWHMvsDT_top->Update();

	TCanvas *c_S20_FWHMvsDT_bot = new TCanvas("c_S20_FWHMvsDT_bot", "c_S20_FWHMvsDT_bot", 0, 0, 700, 500);
			 c_S20_FWHMvsDT_bot->SetFillColor(10);
    		 c_S20_FWHMvsDT_bot->SetLogz();
		T1	->Draw("S2width_bot:dt_bot>>h2_S20_FWHMvsDT_bot", "",	"COLZ");
		h2_S20_FWHMvsDT_bot	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S20_FWHMvsDT_bot	-> GetYaxis() -> SetTitle("S2[0] FWHM, bottom [#mus]");
		h2_S20_FWHMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S20_FWHMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
	c_S20_FWHMvsDT_bot->Update();

	TCanvas *c_S20_FWTMvsDT_top = new TCanvas("c_S20_FWTMvsDT_top", "c_S20_FWTMvsDT_top", 0, 0, 700, 500);
			 c_S20_FWTMvsDT_top->SetFillColor(10);
    		 c_S20_FWTMvsDT_top->SetLogz();
		T1	->Draw("S2widthLow_top:dt_top>>h2_S20_FWTMvsDT_top", "",	"COLZ");
		h2_S20_FWTMvsDT_top	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S20_FWTMvsDT_top	-> GetYaxis() -> SetTitle("S2[0] FWTM, top [#mus]");
		h2_S20_FWTMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S20_FWTMvsDT_top	-> GetYaxis() -> CenterTitle(true);
	c_S20_FWHMvsDT_top->Update();

	TCanvas *c_S20_FWTMvsDT_bot = new TCanvas("c_S20_FWTMvsDT_bot", "c_S20_FWTMvsDT_bot", 0, 0, 700, 500);
			 c_S20_FWTMvsDT_bot->SetFillColor(10);
    		 c_S20_FWTMvsDT_bot->SetLogz();
		T1	->Draw("S2widthLow_bot:dt_bot>>h2_S20_FWTMvsDT_bot", "",	"COLZ");
		h2_S20_FWTMvsDT_bot	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S20_FWTMvsDT_bot	-> GetYaxis() -> SetTitle("S2[0] FWTM, bottom [#mus]");
		h2_S20_FWTMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S20_FWTMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
	c_S20_FWHMvsDT_bot->Update();

	// S2[1]
	TCanvas *c_S21_FWHMvsDT_top = new TCanvas("c_S21_FWHMvsDT_top", "c_S21_FWHMvsDT_top", 0, 0, 700, 500);
			 c_S21_FWHMvsDT_top->SetFillColor(10);
    		 c_S21_FWHMvsDT_top->SetLogz();
		T1	->Draw("S21width_top:dt1_top>>h2_S21_FWHMvsDT_top", "",	"COLZ");
		h2_S21_FWHMvsDT_top	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S21_FWHMvsDT_top	-> GetYaxis() -> SetTitle("S2[1] FWHM, top [#mus]");
		h2_S21_FWHMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21_FWHMvsDT_top	-> GetYaxis() -> CenterTitle(true);
	c_S21_FWHMvsDT_top->Update();

	TCanvas *c_S21_FWHMvsDT_bot = new TCanvas("c_S21_FWHMvsDT_bot", "c_S21_FWHMvsDT_bot", 0, 0, 700, 500);
			 c_S21_FWHMvsDT_bot->SetFillColor(10);
    		 c_S21_FWHMvsDT_bot->SetLogz();
		T1	->Draw("S21width_bot:dt1_bot>>h2_S21_FWHMvsDT_bot", "",	"COLZ");
		h2_S21_FWHMvsDT_bot	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S21_FWHMvsDT_bot	-> GetYaxis() -> SetTitle("S2[1] FWHM, bottom [#mus]");
		h2_S21_FWHMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21_FWHMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
	c_S21_FWHMvsDT_bot->Update();

	TCanvas *c_S21_FWTMvsDT_top = new TCanvas("c_S21_FWTMvsDT_top", "c_S20_FWTMvsDT_top", 0, 0, 700, 500);
			 c_S21_FWTMvsDT_top->SetFillColor(10);
    		 c_S21_FWTMvsDT_top->SetLogz();
		T1	->Draw("S21widthLow_top:dt1_top>>h2_S21_FWTMvsDT_top", "",	"COLZ");
		h2_S21_FWTMvsDT_top	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S21_FWTMvsDT_top	-> GetYaxis() -> SetTitle("S2[1] FWTM, top [#mus]");
		h2_S21_FWTMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21_FWTMvsDT_top	-> GetYaxis() -> CenterTitle(true);
	c_S21_FWHMvsDT_top->Update();

	TCanvas *c_S21_FWTMvsDT_bot = new TCanvas("c_S21_FWTMvsDT_bot", "c_S21_FWTMvsDT_bot", 0, 0, 700, 500);
			 c_S21_FWTMvsDT_bot->SetFillColor(10);
    		 c_S21_FWTMvsDT_bot->SetLogz();
		T1	->Draw("S21widthLow_bot:dt1_bot>>h2_S21_FWTMvsDT_bot", "",	"COLZ");
		h2_S21_FWTMvsDT_bot	-> GetXaxis() -> SetTitle("Drift time [#mus]");
		h2_S21_FWTMvsDT_bot	-> GetYaxis() -> SetTitle("S2[1] FWTM, bottom [#mus]");
		h2_S21_FWTMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21_FWTMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
	c_S21_FWHMvsDT_bot->Update();



	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_S2widthDT[500];
	sprintf(outFolder_S2widthDT, "%s/S2widthDT_Kr83m", outFolder_dataset);
	char mkdir_outFolder_S2widthDT[500];
	sprintf(mkdir_outFolder_S2widthDT, ".mkdir %s", outFolder_S2widthDT);
	gROOT->ProcessLine(mkdir_outFolder_S2widthDT);


	char outFolder_S20_FWHM_top[500];
	sprintf(outFolder_S20_FWHM_top, "%s/S20_FWHM_top", outFolder_S2widthDT);
	char mkdir_outFolder_S20_FWHM_top[500];
	sprintf(mkdir_outFolder_S20_FWHM_top, ".mkdir %s", outFolder_S20_FWHM_top);
	gROOT->ProcessLine(mkdir_outFolder_S20_FWHM_top);

	char outFolder_S20_FWHM_bot[500];
	sprintf(outFolder_S20_FWHM_bot, "%s/S20_FWHM_bot", outFolder_S2widthDT);
	char mkdir_outFolder_S20_FWHM_bot[500];
	sprintf(mkdir_outFolder_S20_FWHM_bot, ".mkdir %s", outFolder_S20_FWHM_bot);
	gROOT->ProcessLine(mkdir_outFolder_S20_FWHM_bot);

	char outFolder_S20_FWTM_top[500];
	sprintf(outFolder_S20_FWTM_top, "%s/S20_FWTM_top", outFolder_S2widthDT);
	char mkdir_outFolder_S20_FWTM_top[500];
	sprintf(mkdir_outFolder_S20_FWTM_top, ".mkdir %s", outFolder_S20_FWTM_top);
	gROOT->ProcessLine(mkdir_outFolder_S20_FWTM_top);

	char outFolder_S20_FWTM_bot[500];
	sprintf(outFolder_S20_FWTM_bot, "%s/S20_FWTM_bot", outFolder_S2widthDT);
	char mkdir_outFolder_S20_FWTM_bot[500];
	sprintf(mkdir_outFolder_S20_FWTM_bot, ".mkdir %s", outFolder_S20_FWTM_bot);
	gROOT->ProcessLine(mkdir_outFolder_S20_FWTM_bot);


	char outFolder_S21_FWHM_top[500];
	sprintf(outFolder_S21_FWHM_top, "%s/S21_FWHM_top", outFolder_S2widthDT);
	char mkdir_outFolder_S21_FWHM_top[500];
	sprintf(mkdir_outFolder_S21_FWHM_top, ".mkdir %s", outFolder_S21_FWHM_top);
	gROOT->ProcessLine(mkdir_outFolder_S21_FWHM_top);

	char outFolder_S21_FWHM_bot[500];
	sprintf(outFolder_S21_FWHM_bot, "%s/S21_FWHM_bot", outFolder_S2widthDT);
	char mkdir_outFolder_S21_FWHM_bot[500];
	sprintf(mkdir_outFolder_S21_FWHM_bot, ".mkdir %s", outFolder_S21_FWHM_bot);
	gROOT->ProcessLine(mkdir_outFolder_S21_FWHM_bot);

	char outFolder_S21_FWTM_top[500];
	sprintf(outFolder_S21_FWTM_top, "%s/S21_FWTM_top", outFolder_S2widthDT);
	char mkdir_outFolder_S21_FWTM_top[500];
	sprintf(mkdir_outFolder_S21_FWTM_top, ".mkdir %s", outFolder_S21_FWTM_top);
	gROOT->ProcessLine(mkdir_outFolder_S21_FWTM_top);

	char outFolder_S21_FWTM_bot[500];
	sprintf(outFolder_S21_FWTM_bot, "%s/S21_FWTM_bot", outFolder_S2widthDT);
	char mkdir_outFolder_S21_FWTM_bot[500];
	sprintf(mkdir_outFolder_S21_FWTM_bot, ".mkdir %s", outFolder_S21_FWTM_bot);
	gROOT->ProcessLine(mkdir_outFolder_S21_FWTM_bot);


	char char_S20_FWHMvsDT_top[500];
	char char_S20_FWHMvsDT_bot[500];

	char char_S20_FWTMvsDT_top[500];
	char char_S20_FWTMvsDT_bot[500];

	char char_S21_FWHMvsDT_top[500];
	char char_S21_FWHMvsDT_bot[500];

	char char_S21_FWTMvsDT_top[500];
	char char_S21_FWTMvsDT_bot[500];

	sprintf(char_S20_FWHMvsDT_top,	"%s/%s_S20_FWHMvsDT_top_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);
	sprintf(char_S20_FWHMvsDT_bot,	"%s/%s_S20_FWHMvsDT_bot_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);

	sprintf(char_S20_FWTMvsDT_top,	"%s/%s_S20_FWTMvsDT_top_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);
	sprintf(char_S20_FWTMvsDT_bot,	"%s/%s_S20_FWTMvsDT_bot_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);


	sprintf(char_S21_FWHMvsDT_top,	"%s/%s_S21_FWHMvsDT_top_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);
	sprintf(char_S21_FWHMvsDT_bot,	"%s/%s_S21_FWHMvsDT_bot_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);

	sprintf(char_S21_FWTMvsDT_top,	"%s/%s_S21_FWTMvsDT_top_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);
	sprintf(char_S21_FWTMvsDT_bot,	"%s/%s_S21_FWTMvsDT_bot_%s%s",	outFolder_S2widthDT, DataSet1, CutName, extensionPlots);


	c_S20_FWHMvsDT_top	->SaveAs(char_S20_FWHMvsDT_top);
	c_S20_FWHMvsDT_bot	->SaveAs(char_S20_FWHMvsDT_bot);

	c_S20_FWTMvsDT_top	->SaveAs(char_S20_FWTMvsDT_top);
	c_S20_FWTMvsDT_bot	->SaveAs(char_S20_FWTMvsDT_bot);

	c_S21_FWHMvsDT_top	->SaveAs(char_S21_FWHMvsDT_top);
	c_S21_FWHMvsDT_bot	->SaveAs(char_S21_FWHMvsDT_bot);

	c_S21_FWTMvsDT_top	->SaveAs(char_S21_FWTMvsDT_top);
	c_S21_FWTMvsDT_bot	->SaveAs(char_S21_FWTMvsDT_bot);



	////////////////////////////////////////////////////////////////////////////////////
	// LOOP
	const int nSlices = 30; // number of slices
	double min_DT = 2;
	double max_DT = 17;
	double min_DTslice, max_DTslice;
	double DTinterval = (max_DT-min_DT)/nSlices;

	double xmean, xinterval;

	double ymean_S20_FWHM_top, ysigma_S20_FWHM_top, ymeanEr_S20_FWHM_top, ysigmaEr_S20_FWHM_top;
	double median_S20_FWHM_top, medianError_S20_FWHM_top;

	double ymean_S20_FWHM_bot, ysigma_S20_FWHM_bot, ymeanEr_S20_FWHM_bot, ysigmaEr_S20_FWHM_bot;
	double median_S20_FWHM_bot, medianError_S20_FWHM_bot;

	double ymean_S20_FWTM_top, ysigma_S20_FWTM_top, ymeanEr_S20_FWTM_top, ysigmaEr_S20_FWTM_top;
	double median_S20_FWTM_top, medianError_S20_FWTM_top;

	double ymean_S20_FWTM_bot, ysigma_S20_FWTM_bot, ymeanEr_S20_FWTM_bot, ysigmaEr_S20_FWTM_bot;
	double median_S20_FWTM_bot, medianError_S20_FWTM_bot;


	double ymean_S21_FWHM_top, ysigma_S21_FWHM_top, ymeanEr_S21_FWHM_top, ysigmaEr_S21_FWHM_top;
	double median_S21_FWHM_top, medianError_S21_FWHM_top;

	double ymean_S21_FWHM_bot, ysigma_S21_FWHM_bot, ymeanEr_S21_FWHM_bot, ysigmaEr_S21_FWHM_bot;
	double median_S21_FWHM_bot, medianError_S21_FWHM_bot;

	double ymean_S21_FWTM_top, ysigma_S21_FWTM_top, ymeanEr_S21_FWTM_top, ysigmaEr_S21_FWTM_top;
	double median_S21_FWTM_top, medianError_S21_FWTM_top;

	double ymean_S21_FWTM_bot, ysigma_S21_FWTM_bot, ymeanEr_S21_FWTM_bot, ysigmaEr_S21_FWTM_bot;
	double median_S21_FWTM_bot, medianError_S21_FWTM_bot;


	double x[nSlices], 	xer[nSlices];

	ofstream OutFile_S20_FWHM_top;
	Char_t  OutFile_S20_FWHM_top_char[500];
	sprintf(OutFile_S20_FWHM_top_char, "%s/sliceDT_S20_FWHM_top.dat", outFolder_S2widthDT);
	OutFile_S20_FWHM_top.open(OutFile_S20_FWHM_top_char);

	ofstream OutFile_S20_FWHM_bot;
	Char_t  OutFile_S20_FWHM_bot_char[500];
	sprintf(OutFile_S20_FWHM_bot_char, "%s/sliceDT_S20_FWHM_bot.dat", outFolder_S2widthDT);
	OutFile_S20_FWHM_bot.open(OutFile_S20_FWHM_bot_char);

	ofstream OutFile_S20_FWTM_top;
	Char_t  OutFile_S20_FWTM_top_char[500];
	sprintf(OutFile_S20_FWTM_top_char, "%s/sliceDT_S20_FWTM_top.dat", outFolder_S2widthDT);
	OutFile_S20_FWTM_top.open(OutFile_S20_FWTM_top_char);

	ofstream OutFile_S20_FWTM_bot;
	Char_t  OutFile_S20_FWTM_bot_char[500];
	sprintf(OutFile_S20_FWTM_bot_char, "%s/sliceDT_S20_FWTM_bot.dat", outFolder_S2widthDT);
	OutFile_S20_FWTM_bot.open(OutFile_S20_FWTM_bot_char);


	ofstream OutFile_S21_FWHM_top;
	Char_t  OutFile_S21_FWHM_top_char[500];
	sprintf(OutFile_S21_FWHM_top_char, "%s/sliceDT_S21_FWHM_top.dat", outFolder_S2widthDT);
	OutFile_S21_FWHM_top.open(OutFile_S21_FWHM_top_char);

	ofstream OutFile_S21_FWHM_bot;
	Char_t  OutFile_S21_FWHM_bot_char[500];
	sprintf(OutFile_S21_FWHM_bot_char, "%s/sliceDT_S21_FWHM_bot.dat", outFolder_S2widthDT);
	OutFile_S21_FWHM_bot.open(OutFile_S21_FWHM_bot_char);

	ofstream OutFile_S21_FWTM_top;
	Char_t  OutFile_S21_FWTM_top_char[500];
	sprintf(OutFile_S21_FWTM_top_char, "%s/sliceDT_S21_FWTM_top.dat", outFolder_S2widthDT);
	OutFile_S21_FWTM_top.open(OutFile_S21_FWTM_top_char);

	ofstream OutFile_S21_FWTM_bot;
	Char_t  OutFile_S21_FWTM_bot_char[500];
	sprintf(OutFile_S21_FWTM_bot_char, "%s/sliceDT_S21_FWTM_bot.dat", outFolder_S2widthDT);
	OutFile_S21_FWTM_bot.open(OutFile_S21_FWTM_bot_char);


	int nbins_FWHM_1D	= 100;
	double min_FWHM_1D	= 0;
	double max_FWHM_1D	= 0.5;

	int nbins_FWTM_1D	= 200;
	double min_FWTM_1D	= 0;
	double max_FWTM_1D	= 1.0;


	double fitMin_FWHM = 0.15;
	double fitMax_FWHM = 0.45;

	double fitMin_FWTM = 0.40;
	double fitMax_FWTM = 0.85;


	double 
	Max_S20_FWHM_top, 				Max_S20_FWHM_bot, 			Max_S20_FWTM_top,			Max_S20_FWTM_bot,
	MaxBin_S20_FWHM_top,			MaxBin_S20_FWHM_bot, 		MaxBin_S20_FWTM_top, 		MaxBin_S20_FWTM_bot,
	MaxBinCont_S20_FWHM_top,		MaxBinCont_S20_FWHM_bot,	MaxBinCont_S20_FWTM_top, 	MaxBinCont_S20_FWTM_bot,
	MaxBinVal_S20_FWHM_top, 		MaxBinVal_S20_FWHM_bot, 	MaxBinVal_S20_FWTM_top, 	MaxBinVal_S20_FWTM_bot,
	BinRms_S20_FWHM_top, 			BinRms_S20_FWHM_bot,		BinRms_S20_FWTM_top, 		BinRms_S20_FWTM_bot;

	double 
	Max_S21_FWHM_top, 				Max_S21_FWHM_bot, 			Max_S21_FWTM_top,			Max_S21_FWTM_bot,
	MaxBin_S21_FWHM_top,			MaxBin_S21_FWHM_bot, 		MaxBin_S21_FWTM_top, 		MaxBin_S21_FWTM_bot,
	MaxBinCont_S21_FWHM_top, 		MaxBinCont_S21_FWHM_bot,	MaxBinCont_S21_FWTM_top, 	MaxBinCont_S21_FWTM_bot,
	MaxBinVal_S21_FWHM_top, 		MaxBinVal_S21_FWHM_bot, 	MaxBinVal_S21_FWTM_top, 	MaxBinVal_S21_FWTM_bot,
	BinRms_S21_FWHM_top, 			BinRms_S21_FWHM_bot,		BinRms_S21_FWTM_top, 		BinRms_S21_FWTM_bot;

	double 
	fit0Min_S20_FWHM_top, 			fit0Min_S20_FWHM_bot, 		fit0Min_S20_FWTM_top, 		fit0Min_S20_FWTM_bot,
	fit0Max_S20_FWHM_top, 			fit0Max_S20_FWHM_bot,		fit0Max_S20_FWTM_top, 		fit0Max_S20_FWTM_bot,
	fit0Min_S21_FWHM_top, 			fit0Min_S21_FWHM_bot, 		fit0Min_S21_FWTM_top, 		fit0Min_S21_FWTM_bot,
	fit0Max_S21_FWHM_top, 			fit0Max_S21_FWHM_bot,		fit0Max_S21_FWTM_top, 		fit0Max_S21_FWTM_bot;

	double 
	fit0Amp_S20_FWHM_top, 			fit0Amp_S20_FWHM_bot, 		fit0Amp_S20_FWTM_top, 		fit0Amp_S20_FWTM_bot,
	fit0Mean_S20_FWHM_top, 			fit0Mean_S20_FWHM_bot,	 	fit0Mean_S20_FWTM_top, 		fit0Mean_S20_FWTM_bot,
	fit0Sigma_S20_FWHM_top, 		fit0Sigma_S20_FWHM_bot, 	fit0Sigma_S20_FWTM_top, 	fit0Sigma_S20_FWTM_bot;

	double 
	fit0Amp_S21_FWHM_top, 			fit0Amp_S21_FWHM_bot, 		fit0Amp_S21_FWTM_top, 		fit0Amp_S21_FWTM_bot,
	fit0Mean_S21_FWHM_top, 			fit0Mean_S21_FWHM_bot,	 	fit0Mean_S21_FWTM_top, 		fit0Mean_S21_FWTM_bot,
	fit0Sigma_S21_FWHM_top, 		fit0Sigma_S21_FWHM_bot, 	fit0Sigma_S21_FWTM_top, 	fit0Sigma_S21_FWTM_bot;

	TLine 
	*lineMean_S20_FWHM_top, 		*lineMean_S20_FWHM_bot, 	*lineMean_S20_FWTM_top, 	*lineMean_S20_FWTM_bot,
	*lineF02_S20_FWHM_top, 			*lineF02_S20_FWHM_bot, 		*lineF02_S20_FWTM_top, 		*lineF02_S20_FWTM_bot,
	*lineF05_S20_FWHM_top, 			*lineF05_S20_FWHM_bot, 		*lineF05_S20_FWTM_top, 		*lineF05_S20_FWTM_bot,
	*lineF95_S20_FWHM_top, 			*lineF95_S20_FWHM_bot, 		*lineF95_S20_FWTM_top, 		*lineF95_S20_FWTM_bot,
	*lineF98_S20_FWHM_top, 			*lineF98_S20_FWHM_bot, 		*lineF98_S20_FWTM_top, 		*lineF98_S20_FWTM_bot;

	TLine 
	*lineMedian_S20_FWHM_top,		*lineMedian_S20_FWHM_bot, 	*lineMedian_S20_FWTM_top, 	*lineMedian_S20_FWTM_bot,
	*line02_S20_FWHM_top, 			*line02_S20_FWHM_bot, 		*line02_S20_FWTM_top, 		*line02_S20_FWTM_bot,
	*line05_S20_FWHM_top, 			*line05_S20_FWHM_bot, 		*line05_S20_FWTM_top, 		*line05_S20_FWTM_bot,
	*line95_S20_FWHM_top, 			*line95_S20_FWHM_bot, 		*line95_S20_FWTM_top, 		*line95_S20_FWTM_bot,
	*line98_S20_FWHM_top, 			*line98_S20_FWHM_bot, 		*line98_S20_FWTM_top, 		*line98_S20_FWTM_bot;

	TLine 
	*lineMean_S21_FWHM_top, 		*lineMean_S21_FWHM_bot, 	*lineMean_S21_FWTM_top, 	*lineMean_S21_FWTM_bot,
	*lineF02_S21_FWHM_top, 			*lineF02_S21_FWHM_bot, 		*lineF02_S21_FWTM_top, 		*lineF02_S21_FWTM_bot,
	*lineF05_S21_FWHM_top, 			*lineF05_S21_FWHM_bot, 		*lineF05_S21_FWTM_top, 		*lineF05_S21_FWTM_bot,
	*lineF95_S21_FWHM_top, 			*lineF95_S21_FWHM_bot, 		*lineF95_S21_FWTM_top, 		*lineF95_S21_FWTM_bot,
	*lineF98_S21_FWHM_top, 			*lineF98_S21_FWHM_bot, 		*lineF98_S21_FWTM_top, 		*lineF98_S21_FWTM_bot;

	TLine 
	*lineMedian_S21_FWHM_top,		*lineMedian_S21_FWHM_bot, 	*lineMedian_S21_FWTM_top, 	*lineMedian_S21_FWTM_bot,
	*line02_S21_FWHM_top, 			*line02_S21_FWHM_bot, 		*line02_S21_FWTM_top, 		*line02_S21_FWTM_bot,
	*line05_S21_FWHM_top, 			*line05_S21_FWHM_bot, 		*line05_S21_FWTM_top, 		*line05_S21_FWTM_bot,
	*line95_S21_FWHM_top, 			*line95_S21_FWHM_bot, 		*line95_S21_FWTM_top, 		*line95_S21_FWTM_bot,
	*line98_S21_FWHM_top, 			*line98_S21_FWHM_bot, 		*line98_S21_FWTM_top, 		*line98_S21_FWTM_bot;

	TH1F 
	*h1_S20_FWHM_top, 				*h1_S20_FWHM_bot,			*h1_S20_FWTM_top, 			*h1_S20_FWTM_bot,
	*h1_S21_FWHM_top, 				*h1_S21_FWHM_bot,			*h1_S21_FWTM_top, 			*h1_S21_FWTM_bot;

	TF1
	*fitF_S20_FWHM_top,				*fitF_S20_FWHM_bot, 		*fitF_S20_FWTM_top, 		*fitF_S20_FWTM_bot,
	*fitF_S21_FWHM_top,				*fitF_S21_FWHM_bot, 		*fitF_S21_FWTM_top, 		*fitF_S21_FWTM_bot,
	*fitF0_S20_FWHM_top,			*fitF0_S20_FWHM_bot, 		*fitF0_S20_FWTM_top, 		*fitF0_S20_FWTM_bot,
	*fitF0_S21_FWHM_top,			*fitF0_S21_FWHM_bot, 		*fitF0_S21_FWTM_top, 		*fitF0_S21_FWTM_bot;

	const int Nqu = 4;
	double probsum[Nqu] = {0.02, 0.05, 0.95, 0.98};
	double 
	qu_S20_FWHM_top[Nqu], 	qu_S20_FWHM_bot[Nqu], 		qu_S20_FWTM_top[Nqu], 		qu_S20_FWTM_bot[Nqu],
	quF_S20_FWHM_top[Nqu], 	quF_S20_FWHM_bot[Nqu], 		quF_S20_FWTM_top[Nqu], 		quF_S20_FWTM_bot[Nqu],
	qu_S21_FWHM_top[Nqu], 	qu_S21_FWHM_bot[Nqu], 		qu_S21_FWTM_top[Nqu], 		qu_S21_FWTM_bot[Nqu],
	quF_S21_FWHM_top[Nqu], 	quF_S21_FWHM_bot[Nqu], 		quF_S21_FWTM_top[Nqu], 		quF_S21_FWTM_bot[Nqu];

	char 
	Sname_S20_FWHM_top[500],		Sname_S20_FWHM_bot[500], 	Sname_S20_FWTM_top[500], 	Sname_S20_FWTM_bot[500],
	Sname_S21_FWHM_top[500],		Sname_S21_FWHM_bot[500], 	Sname_S21_FWTM_top[500], 	Sname_S21_FWTM_bot[500];

	char 
	SnameC_S20_FWHM_top[500],	SnameC_S20_FWHM_bot[500], 	SnameC_S20_FWTM_top[500], 	SnameC_S20_FWTM_bot[500];

	TPaveText 
	*ptstats_S20_FWHM_top, 			*ptstats_S20_FWHM_bot, 		*ptstats_S20_FWTM_top, 		*ptstats_S20_FWTM_bot,
	*ptstats_S21_FWHM_top, 			*ptstats_S21_FWHM_bot, 		*ptstats_S21_FWTM_top, 		*ptstats_S21_FWTM_bot;
				
	TText
	*text1_S20_FWHM_top,			*text1_S20_FWHM_bot,		*text1_S20_FWTM_top,		*text1_S20_FWTM_bot,
	*text2_S20_FWHM_top,			*text2_S20_FWHM_bot,		*text2_S20_FWTM_top,		*text2_S20_FWTM_bot,
	*text1_S21_FWHM_top,			*text1_S21_FWHM_bot,		*text1_S21_FWTM_top,		*text1_S21_FWTM_bot,
	*text2_S21_FWHM_top,			*text2_S21_FWHM_bot,		*text2_S21_FWTM_top,		*text2_S21_FWTM_bot;

	char 
	char_text1_S20_FWHM_top[256],	char_text1_S20_FWHM_bot[256],	char_text1_S20_FWTM_top[256],	char_text1_S20_FWTM_bot[256],
	char_text2_S20_FWHM_top[256],	char_text2_S20_FWHM_bot[256],	char_text2_S20_FWTM_top[256],	char_text2_S20_FWTM_bot[256],
	char_text1_S21_FWHM_top[256],	char_text1_S21_FWHM_bot[256],	char_text1_S21_FWTM_top[256],	char_text1_S21_FWTM_bot[256],
	char_text2_S21_FWHM_top[256],	char_text2_S21_FWHM_bot[256],	char_text2_S21_FWTM_top[256],	char_text2_S21_FWTM_bot[256];
	 
	double 
	y_S20_FWHM_top[nSlices], 		y_S20_FWHM_bot[nSlices], 		y_S20_FWTM_top[nSlices], 		y_S20_FWTM_bot[nSlices], 
	y02_S20_FWHM_top[nSlices], 		y02_S20_FWHM_bot[nSlices], 		y02_S20_FWTM_top[nSlices], 		y02_S20_FWTM_bot[nSlices], 
	y05_S20_FWHM_top[nSlices], 		y05_S20_FWHM_bot[nSlices], 		y05_S20_FWTM_top[nSlices], 		y05_S20_FWTM_bot[nSlices], 
	y95_S20_FWHM_top[nSlices], 		y95_S20_FWHM_bot[nSlices], 		y95_S20_FWTM_top[nSlices], 		y95_S20_FWTM_bot[nSlices], 
	y98_S20_FWHM_top[nSlices], 		y98_S20_FWHM_bot[nSlices], 		y98_S20_FWTM_top[nSlices], 		y98_S20_FWTM_bot[nSlices];

	double 
	yF_S20_FWHM_top[nSlices], 		yF_S20_FWHM_bot[nSlices], 		yF_S20_FWTM_top[nSlices], 		yF_S20_FWTM_bot[nSlices], 
	yF02_S20_FWHM_top[nSlices], 	yF02_S20_FWHM_bot[nSlices], 	yF02_S20_FWTM_top[nSlices], 	yF02_S20_FWTM_bot[nSlices], 
	yF05_S20_FWHM_top[nSlices], 	yF05_S20_FWHM_bot[nSlices], 	yF05_S20_FWTM_top[nSlices], 	yF05_S20_FWTM_bot[nSlices], 
	yF95_S20_FWHM_top[nSlices], 	yF95_S20_FWHM_bot[nSlices], 	yF95_S20_FWTM_top[nSlices], 	yF95_S20_FWTM_bot[nSlices], 
	yF98_S20_FWHM_top[nSlices], 	yF98_S20_FWHM_bot[nSlices], 	yF98_S20_FWTM_top[nSlices], 	yF98_S20_FWTM_bot[nSlices];

	double 
	y_S21_FWHM_top[nSlices], 		y_S21_FWHM_bot[nSlices], 		y_S21_FWTM_top[nSlices], 		y_S21_FWTM_bot[nSlices], 
	y02_S21_FWHM_top[nSlices], 		y02_S21_FWHM_bot[nSlices], 		y02_S21_FWTM_top[nSlices], 		y02_S21_FWTM_bot[nSlices], 
	y05_S21_FWHM_top[nSlices], 		y05_S21_FWHM_bot[nSlices], 		y05_S21_FWTM_top[nSlices], 		y05_S21_FWTM_bot[nSlices], 
	y95_S21_FWHM_top[nSlices], 		y95_S21_FWHM_bot[nSlices], 		y95_S21_FWTM_top[nSlices], 		y95_S21_FWTM_bot[nSlices], 
	y98_S21_FWHM_top[nSlices], 		y98_S21_FWHM_bot[nSlices], 		y98_S21_FWTM_top[nSlices], 		y98_S21_FWTM_bot[nSlices];

	double 
	yF_S21_FWHM_top[nSlices], 		yF_S21_FWHM_bot[nSlices], 		yF_S21_FWTM_top[nSlices], 		yF_S21_FWTM_bot[nSlices], 
	yF02_S21_FWHM_top[nSlices], 	yF02_S21_FWHM_bot[nSlices], 	yF02_S21_FWTM_top[nSlices], 	yF02_S21_FWTM_bot[nSlices], 
	yF05_S21_FWHM_top[nSlices], 	yF05_S21_FWHM_bot[nSlices], 	yF05_S21_FWTM_top[nSlices], 	yF05_S21_FWTM_bot[nSlices], 
	yF95_S21_FWHM_top[nSlices], 	yF95_S21_FWHM_bot[nSlices], 	yF95_S21_FWTM_top[nSlices], 	yF95_S21_FWTM_bot[nSlices], 
	yF98_S21_FWHM_top[nSlices], 	yF98_S21_FWHM_bot[nSlices], 	yF98_S21_FWTM_top[nSlices], 	yF98_S21_FWTM_bot[nSlices];


	////////////////////////////////
	// LOOP ON SLICES
	for (int i=0; i<nSlices; i++){
	//for (int i=0; i<2; i++){

		min_DTslice = min_DT + i*DTinterval;
		max_DTslice = min_DTslice + DTinterval;
		
		Char_t  Hname[500];
		sprintf(Hname, "slice_%d", i+1);
		sprintf(Hname, "slice %d, %g us < dt < %g us ", i+1, min_DTslice, max_DTslice);
		cout << Hname << endl;

		h1_S20_FWHM_top = new TH1F("h1_S20_FWHM_top", Hname, nbins_FWHM_1D, min_FWHM_1D, max_FWHM_1D);
		h1_S20_FWHM_top->SetLineColor(1);
		h1_S20_FWHM_top->SetLineWidth(1);
	
		h1_S20_FWHM_bot = new TH1F("h1_S20_FWHM_bot", Hname, nbins_FWHM_1D, min_FWHM_1D, max_FWHM_1D);
		h1_S20_FWHM_bot->SetLineColor(1);
		h1_S20_FWHM_bot->SetLineWidth(1);

		h1_S20_FWTM_top = new TH1F("h1_S20_FWTM_top", Hname, nbins_FWTM_1D, min_FWTM_1D, max_FWTM_1D);
		h1_S20_FWTM_top->SetLineColor(1);
		h1_S20_FWTM_top->SetLineWidth(1);

		h1_S20_FWTM_bot = new TH1F("h1_S20_FWTM_bot", Hname, nbins_FWTM_1D, min_FWTM_1D, max_FWTM_1D);
		h1_S20_FWTM_bot->SetLineColor(1);
		h1_S20_FWTM_bot->SetLineWidth(1);


		h1_S21_FWHM_top = new TH1F("h1_S21_FWHM_top", Hname, nbins_FWHM_1D, min_FWHM_1D, max_FWHM_1D);
		h1_S21_FWHM_top->SetLineColor(1);
		h1_S21_FWHM_top->SetLineWidth(1);

		h1_S21_FWHM_bot = new TH1F("h1_S21_FWHM_bot", Hname, nbins_FWHM_1D, min_FWHM_1D, max_FWHM_1D);
		h1_S21_FWHM_bot->SetLineColor(1);
		h1_S21_FWHM_bot->SetLineWidth(1);

		h1_S21_FWTM_top = new TH1F("h1_S21_FWTM_top", Hname, nbins_FWTM_1D, min_FWTM_1D, max_FWTM_1D);
		h1_S21_FWTM_top->SetLineColor(1);
		h1_S21_FWTM_top->SetLineWidth(1);

		h1_S21_FWTM_bot = new TH1F("h1_S21_FWTM_bot", Hname, nbins_FWTM_1D, min_FWTM_1D, max_FWTM_1D);
		h1_S21_FWTM_bot->SetLineColor(1);
		h1_S21_FWTM_bot->SetLineWidth(1);


		// S1 slicing cut
		TCut cut_DTslice_top	= Form("dt_top > %g && dt_top < %g", 	min_DTslice, max_DTslice);
		TCut cut_DTslice_bot	= Form("dt_bot > %g && dt_bot < %g", 	min_DTslice, max_DTslice);
		TCut cut_DT1slice_top	= Form("dt1_top > %g && dt1_top < %g", 	min_DTslice, max_DTslice);
		TCut cut_DT1slice_bot	= Form("dt1_bot > %g && dt1_bot < %g", 	min_DTslice, max_DTslice);
		
		// PLOT
		TCanvas *c_S20_FWHM_top = new TCanvas("c_S20_FWHM_top", "c_S20_FWHM_top", 0, 0, 700, 500);
				 c_S20_FWHM_top->SetFillColor(10);
				 c_S20_FWHM_top->SetLogy(10);
			T1->Draw("S2width_top>>h1_S20_FWHM_top", cut_DTslice_top,"");
			h1_S20_FWHM_top	->GetXaxis()->SetTitle("S2[0] FWHM, top [PE]");
			h1_S20_FWHM_top	->GetYaxis()->SetTitle("Counts");
			h1_S20_FWHM_top	->GetXaxis()->CenterTitle(true);
			h1_S20_FWHM_top	->GetYaxis()->CenterTitle(true);
			h1_S20_FWHM_top	->GetXaxis()->SetTitleOffset(1.25);
			h1_S20_FWHM_top	->GetYaxis()->SetTitleOffset(1.25);

			Max_S20_FWHM_top 		= h1_S20_FWHM_top->GetMaximum();
			MaxBin_S20_FWHM_top 	= h1_S20_FWHM_top->GetMaximumBin();
			MaxBinCont_S20_FWHM_top = h1_S20_FWHM_top->GetBinContent(MaxBin_S20_FWHM_top);
			MaxBinVal_S20_FWHM_top 	= h1_S20_FWHM_top->GetXaxis()->GetBinCenter(MaxBin_S20_FWHM_top); 
			BinRms_S20_FWHM_top		= h1_S20_FWHM_top->GetRMS(1);
		
			fit0Min_S20_FWHM_top = MaxBinVal_S20_FWHM_top-BinRms_S20_FWHM_top;
			fit0Max_S20_FWHM_top = MaxBinVal_S20_FWHM_top+BinRms_S20_FWHM_top;

			fitF0_S20_FWHM_top = new TF1("fitF0_S20_FWHM_top","gaus", fit0Min_S20_FWHM_top, fit0Max_S20_FWHM_top);
			fitF0_S20_FWHM_top->SetLineColor(3);
			fitF0_S20_FWHM_top->SetLineWidth(1);
			h1_S20_FWHM_top->Fit(fitF0_S20_FWHM_top,"R");

			fit0Amp_S20_FWHM_top	= fitF0_S20_FWHM_top->GetParameter(0);
			fit0Mean_S20_FWHM_top	= fitF0_S20_FWHM_top->GetParameter(1);
			fit0Sigma_S20_FWHM_top 	= fitF0_S20_FWHM_top->GetParameter(2);		

			fitF_S20_FWHM_top = new TF1("fitF_S20_FWHM_top","gaus", fit0Mean_S20_FWHM_top-5*fit0Sigma_S20_FWHM_top, fit0Mean_S20_FWHM_top+5*fit0Sigma_S20_FWHM_top);
			fitF_S20_FWHM_top->SetLineColor(2);
			fitF_S20_FWHM_top->SetLineWidth(1);

			fitF_S20_FWHM_top->SetParameter(0, fit0Amp_S20_FWHM_top);
			fitF_S20_FWHM_top->SetParameter(1, fit0Mean_S20_FWHM_top);
			fitF_S20_FWHM_top->SetParameter(2, fit0Sigma_S20_FWHM_top);

			fitF_S20_FWHM_top->Draw("SAME");		

			ymean_S20_FWHM_top 			= fitF_S20_FWHM_top->GetParameter(1);
			ymeanEr_S20_FWHM_top 		= fitF_S20_FWHM_top->GetParError(1);
			ysigma_S20_FWHM_top 		= fitF_S20_FWHM_top->GetParameter(2);
			ysigmaEr_S20_FWHM_top 		= fitF_S20_FWHM_top->GetParError(2);
			median_S20_FWHM_top 		= h1_S20_FWHM_top->GetMean();
			medianError_S20_FWHM_top 	= h1_S20_FWHM_top->GetMeanError();

			h1_S20_FWHM_top		->GetQuantiles(Nqu, qu_S20_FWHM_top, probsum);
			fitF_S20_FWHM_top	->GetQuantiles(Nqu, quF_S20_FWHM_top, probsum);

			lineMean_S20_FWHM_top 	= new TLine(ymean_S20_FWHM_top, 0, ymean_S20_FWHM_top, Max_S20_FWHM_top);
			lineMean_S20_FWHM_top	->SetLineColor(2);
			lineMean_S20_FWHM_top	->SetLineWidth(1);
			lineF02_S20_FWHM_top 	= new TLine(quF_S20_FWHM_top[0], 0, quF_S20_FWHM_top[0], Max_S20_FWHM_top);
			lineF02_S20_FWHM_top	->SetLineColor(2);
			lineF02_S20_FWHM_top	->SetLineStyle(9);
			lineF05_S20_FWHM_top 	= new TLine(quF_S20_FWHM_top[1], 0, quF_S20_FWHM_top[1], Max_S20_FWHM_top);
			lineF05_S20_FWHM_top	->SetLineColor(2);
			lineF05_S20_FWHM_top	->SetLineStyle(9);
			lineF95_S20_FWHM_top 	= new TLine(quF_S20_FWHM_top[2], 0, quF_S20_FWHM_top[2], Max_S20_FWHM_top);
			lineF95_S20_FWHM_top	->SetLineColor(2);
			lineF95_S20_FWHM_top	->SetLineStyle(9);
			lineF98_S20_FWHM_top 	= new TLine(quF_S20_FWHM_top[3], 0, quF_S20_FWHM_top[3], Max_S20_FWHM_top);
			lineF98_S20_FWHM_top	->SetLineColor(2);
			lineF98_S20_FWHM_top	->SetLineStyle(9);

			lineMean_S20_FWHM_top	->Draw("same");
			lineF02_S20_FWHM_top	->Draw("same");
			lineF05_S20_FWHM_top	->Draw("same");
			lineF95_S20_FWHM_top	->Draw("same");
			lineF98_S20_FWHM_top	->Draw("same");

			lineMedian_S20_FWHM_top = new TLine(median_S20_FWHM_top, 0, median_S20_FWHM_top, Max_S20_FWHM_top);
			lineMedian_S20_FWHM_top	->SetLineColor(3);
			lineMedian_S20_FWHM_top	->SetLineWidth(1);
			line02_S20_FWHM_top = new TLine(qu_S20_FWHM_top[0], 0, qu_S20_FWHM_top[0], Max_S20_FWHM_top);
			line02_S20_FWHM_top	->SetLineColor(3);
			line02_S20_FWHM_top	->SetLineStyle(9);
			line05_S20_FWHM_top = new TLine(qu_S20_FWHM_top[1], 0, qu_S20_FWHM_top[1], Max_S20_FWHM_top);
			line05_S20_FWHM_top	->SetLineColor(3);
			line05_S20_FWHM_top	->SetLineStyle(9);
			line95_S20_FWHM_top = new TLine(qu_S20_FWHM_top[2], 0, qu_S20_FWHM_top[2], Max_S20_FWHM_top);
			line95_S20_FWHM_top	->SetLineColor(3);
			line95_S20_FWHM_top	->SetLineStyle(9);
			line98_S20_FWHM_top = new TLine(qu_S20_FWHM_top[3], 0, qu_S20_FWHM_top[3], Max_S20_FWHM_top);
			line98_S20_FWHM_top	->SetLineColor(3);
			line98_S20_FWHM_top	->SetLineStyle(9);

			lineMedian_S20_FWHM_top	->Draw("same");
			line02_S20_FWHM_top		->Draw("same");
			line05_S20_FWHM_top		->Draw("same");
			line95_S20_FWHM_top		->Draw("same");
			line98_S20_FWHM_top		->Draw("same");			

		   	ptstats_S20_FWHM_top = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S20_FWHM_top->SetName("stats");
   			ptstats_S20_FWHM_top->SetBorderSize(0);
   			//ptstats_S20_FWHM_top->SetTextAlign(12);
   			ptstats_S20_FWHM_top->SetFillStyle(0);
   			ptstats_S20_FWHM_top->SetFillColor(0);
  			sprintf(char_text1_S20_FWHM_top, "Median: (%2.1f #pm %2.1f) ns", median_S20_FWHM_top*1000, medianError_S20_FWHM_top*1000);
  			sprintf(char_text2_S20_FWHM_top, "Mean:   (%2.1f #pm %2.2f) ns", ymean_S20_FWHM_top*1000, ymeanEr_S20_FWHM_top*1000);
   			text1_S20_FWHM_top = ptstats_S20_FWHM_top->AddText(char_text1_S20_FWHM_top);
   			text2_S20_FWHM_top = ptstats_S20_FWHM_top->AddText(char_text2_S20_FWHM_top);
   			ptstats_S20_FWHM_top->Draw();
		c_S20_FWHM_top->Update();

		TCanvas *c_S20_FWHM_bot = new TCanvas("c_S20_FWHM_bot", "c_S20_FWHM_bot", 0, 0, 700, 500);
				 c_S20_FWHM_bot->SetFillColor(10);
				 c_S20_FWHM_bot->SetLogy(10);
			T1->Draw("S2width_bot>>h1_S20_FWHM_bot", cut_DTslice_bot,"");
			h1_S20_FWHM_bot	->GetXaxis()->SetTitle("S2[0] FWHM, bottom [PE]");
			h1_S20_FWHM_bot	->GetYaxis()->SetTitle("Counts");
			h1_S20_FWHM_bot	->GetXaxis()->CenterTitle(true);
			h1_S20_FWHM_bot	->GetYaxis()->CenterTitle(true);
			h1_S20_FWHM_bot	->GetXaxis()->SetTitleOffset(1.25);
			h1_S20_FWHM_bot	->GetYaxis()->SetTitleOffset(1.25);

			Max_S20_FWHM_bot 		= h1_S20_FWHM_bot->GetMaximum();
			MaxBin_S20_FWHM_bot 	= h1_S20_FWHM_bot->GetMaximumBin();
			MaxBinCont_S20_FWHM_bot = h1_S20_FWHM_bot->GetBinContent(MaxBin_S20_FWHM_bot);
			MaxBinVal_S20_FWHM_bot 	= h1_S20_FWHM_bot->GetXaxis()->GetBinCenter(MaxBin_S20_FWHM_bot); 
			BinRms_S20_FWHM_bot		= h1_S20_FWHM_bot->GetRMS(1);
		
			fit0Min_S20_FWHM_bot = MaxBinVal_S20_FWHM_bot-BinRms_S20_FWHM_bot;
			fit0Max_S20_FWHM_bot = MaxBinVal_S20_FWHM_bot+BinRms_S20_FWHM_bot;

			fitF0_S20_FWHM_bot = new TF1("fitF0_S20_FWHM_bot","gaus", fit0Min_S20_FWHM_bot, fit0Max_S20_FWHM_bot);
			fitF0_S20_FWHM_bot->SetLineColor(3);
			fitF0_S20_FWHM_bot->SetLineWidth(1);
			h1_S20_FWHM_bot->Fit(fitF0_S20_FWHM_bot,"R");

			fit0Amp_S20_FWHM_bot	= fitF0_S20_FWHM_bot->GetParameter(0);
			fit0Mean_S20_FWHM_bot	= fitF0_S20_FWHM_bot->GetParameter(1);
			fit0Sigma_S20_FWHM_bot 	= fitF0_S20_FWHM_bot->GetParameter(2);		

			fitF_S20_FWHM_bot = new TF1("fitF_S20_FWHM_bot","gaus", fit0Mean_S20_FWHM_bot-5*fit0Sigma_S20_FWHM_bot, fit0Mean_S20_FWHM_bot+5*fit0Sigma_S20_FWHM_bot);
			fitF_S20_FWHM_bot->SetLineColor(2);
			fitF_S20_FWHM_bot->SetLineWidth(1);

			fitF_S20_FWHM_bot->SetParameter(0, fit0Amp_S20_FWHM_bot);
			fitF_S20_FWHM_bot->SetParameter(1, fit0Mean_S20_FWHM_bot);
			fitF_S20_FWHM_bot->SetParameter(2, fit0Sigma_S20_FWHM_bot);

			fitF_S20_FWHM_bot->Draw("SAME");		

			ymean_S20_FWHM_bot 			= fitF_S20_FWHM_bot->GetParameter(1);
			ymeanEr_S20_FWHM_bot 		= fitF_S20_FWHM_bot->GetParError(1);
			ysigma_S20_FWHM_bot 		= fitF_S20_FWHM_bot->GetParameter(2);
			ysigmaEr_S20_FWHM_bot 		= fitF_S20_FWHM_bot->GetParError(2);
			median_S20_FWHM_bot 		= h1_S20_FWHM_bot->GetMean();
			medianError_S20_FWHM_bot 	= h1_S20_FWHM_bot->GetMeanError();

			h1_S20_FWHM_bot		->GetQuantiles(Nqu, qu_S20_FWHM_bot, probsum);
			fitF_S20_FWHM_bot	->GetQuantiles(Nqu, quF_S20_FWHM_bot, probsum);

			lineMean_S20_FWHM_bot 	= new TLine(ymean_S20_FWHM_bot, 0, ymean_S20_FWHM_bot, Max_S20_FWHM_bot);
			lineMean_S20_FWHM_bot	->SetLineColor(2);
			lineMean_S20_FWHM_bot	->SetLineWidth(1);
			lineF02_S20_FWHM_bot 	= new TLine(quF_S20_FWHM_bot[0], 0, quF_S20_FWHM_bot[0], Max_S20_FWHM_bot);
			lineF02_S20_FWHM_bot	->SetLineColor(2);
			lineF02_S20_FWHM_bot	->SetLineStyle(9);
			lineF05_S20_FWHM_bot 	= new TLine(quF_S20_FWHM_bot[1], 0, quF_S20_FWHM_bot[1], Max_S20_FWHM_bot);
			lineF05_S20_FWHM_bot	->SetLineColor(2);
			lineF05_S20_FWHM_bot	->SetLineStyle(9);
			lineF95_S20_FWHM_bot 	= new TLine(quF_S20_FWHM_bot[2], 0, quF_S20_FWHM_bot[2], Max_S20_FWHM_bot);
			lineF95_S20_FWHM_bot	->SetLineColor(2);
			lineF95_S20_FWHM_bot	->SetLineStyle(9);
			lineF98_S20_FWHM_bot 	= new TLine(quF_S20_FWHM_bot[3], 0, quF_S20_FWHM_bot[3], Max_S20_FWHM_bot);
			lineF98_S20_FWHM_bot	->SetLineColor(2);
			lineF98_S20_FWHM_bot	->SetLineStyle(9);

			lineMean_S20_FWHM_bot	->Draw("same");
			lineF02_S20_FWHM_bot	->Draw("same");
			lineF05_S20_FWHM_bot	->Draw("same");
			lineF95_S20_FWHM_bot	->Draw("same");
			lineF98_S20_FWHM_bot	->Draw("same");

			lineMedian_S20_FWHM_bot = new TLine(median_S20_FWHM_bot, 0, median_S20_FWHM_bot, Max_S20_FWHM_bot);
			lineMedian_S20_FWHM_bot	->SetLineColor(3);
			lineMedian_S20_FWHM_bot	->SetLineWidth(1);
			line02_S20_FWHM_bot = new TLine(qu_S20_FWHM_bot[0], 0, qu_S20_FWHM_bot[0], Max_S20_FWHM_bot);
			line02_S20_FWHM_bot	->SetLineColor(3);
			line02_S20_FWHM_bot	->SetLineStyle(9);
			line05_S20_FWHM_bot = new TLine(qu_S20_FWHM_bot[1], 0, qu_S20_FWHM_bot[1], Max_S20_FWHM_bot);
			line05_S20_FWHM_bot	->SetLineColor(3);
			line05_S20_FWHM_bot	->SetLineStyle(9);
			line95_S20_FWHM_bot = new TLine(qu_S20_FWHM_bot[2], 0, qu_S20_FWHM_bot[2], Max_S20_FWHM_bot);
			line95_S20_FWHM_bot	->SetLineColor(3);
			line95_S20_FWHM_bot	->SetLineStyle(9);
			line98_S20_FWHM_bot = new TLine(qu_S20_FWHM_bot[3], 0, qu_S20_FWHM_bot[3], Max_S20_FWHM_bot);
			line98_S20_FWHM_bot	->SetLineColor(3);
			line98_S20_FWHM_bot	->SetLineStyle(9);

			lineMedian_S20_FWHM_bot	->Draw("same");
			line02_S20_FWHM_bot		->Draw("same");
			line05_S20_FWHM_bot		->Draw("same");
			line95_S20_FWHM_bot		->Draw("same");
			line98_S20_FWHM_bot		->Draw("same");			

		   	ptstats_S20_FWHM_bot = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S20_FWHM_bot->SetName("stats");
   			ptstats_S20_FWHM_bot->SetBorderSize(0);
   			//ptstats_S20_FWHM_bot->SetTextAlign(12);
   			ptstats_S20_FWHM_bot->SetFillStyle(0);
   			ptstats_S20_FWHM_bot->SetFillColor(0);
  			sprintf(char_text1_S20_FWHM_bot, "Median: (%2.1f #pm %2.1f) ns", median_S20_FWHM_bot*1000, medianError_S20_FWHM_bot*1000);
  			sprintf(char_text2_S20_FWHM_bot, "Mean:   (%2.1f #pm %2.1f) ns", ymean_S20_FWHM_bot*1000, ymeanEr_S20_FWHM_bot*1000);
   			text1_S20_FWHM_bot = ptstats_S20_FWHM_bot->AddText(char_text1_S20_FWHM_bot);
   			text2_S20_FWHM_bot = ptstats_S20_FWHM_bot->AddText(char_text2_S20_FWHM_bot);
   			ptstats_S20_FWHM_bot->Draw();
		c_S20_FWHM_bot->Update();

		TCanvas *c_S20_FWTM_top = new TCanvas("c_S20_FWTM_top", "c_S20_FWTM_top", 0, 0, 700, 500);
				 c_S20_FWTM_top->SetFillColor(10);
				 c_S20_FWTM_top->SetLogy(10);
			T1->Draw("S2widthLow_top>>h1_S20_FWTM_top", cut_DTslice_top,"");
			h1_S20_FWTM_top	->GetXaxis()->SetTitle("S2[0] FWTM, top [PE]");
			h1_S20_FWTM_top	->GetYaxis()->SetTitle("Counts");
			h1_S20_FWTM_top	->GetXaxis()->CenterTitle(true);
			h1_S20_FWTM_top	->GetYaxis()->CenterTitle(true);
			h1_S20_FWTM_top	->GetXaxis()->SetTitleOffset(1.25);
			h1_S20_FWTM_top	->GetYaxis()->SetTitleOffset(1.25);

			Max_S20_FWTM_top 		= h1_S20_FWTM_top->GetMaximum();
			MaxBin_S20_FWTM_top 	= h1_S20_FWTM_top->GetMaximumBin();
			MaxBinCont_S20_FWTM_top = h1_S20_FWTM_top->GetBinContent(MaxBin_S20_FWTM_top);
			MaxBinVal_S20_FWTM_top 	= h1_S20_FWTM_top->GetXaxis()->GetBinCenter(MaxBin_S20_FWTM_top); 
			BinRms_S20_FWTM_top		= h1_S20_FWTM_top->GetRMS(1);
		
			fit0Min_S20_FWTM_top = MaxBinVal_S20_FWTM_top-BinRms_S20_FWTM_top;
			fit0Max_S20_FWTM_top = MaxBinVal_S20_FWTM_top+BinRms_S20_FWTM_top;

			fitF0_S20_FWTM_top = new TF1("fitF0_S20_FWTM_top","gaus", fit0Min_S20_FWTM_top, fit0Max_S20_FWTM_top);
			fitF0_S20_FWTM_top->SetLineColor(3);
			fitF0_S20_FWTM_top->SetLineWidth(1);
			h1_S20_FWTM_top->Fit(fitF0_S20_FWTM_top,"R");

			fit0Amp_S20_FWTM_top	= fitF0_S20_FWTM_top->GetParameter(0);
			fit0Mean_S20_FWTM_top	= fitF0_S20_FWTM_top->GetParameter(1);
			fit0Sigma_S20_FWTM_top 	= fitF0_S20_FWTM_top->GetParameter(2);		

			fitF_S20_FWTM_top = new TF1("fitF_S20_FWTM_top","gaus", fit0Mean_S20_FWTM_top-5*fit0Sigma_S20_FWTM_top, fit0Mean_S20_FWTM_top+5*fit0Sigma_S20_FWTM_top);
			fitF_S20_FWTM_top->SetLineColor(2);
			fitF_S20_FWTM_top->SetLineWidth(1);

			fitF_S20_FWTM_top->SetParameter(0, fit0Amp_S20_FWTM_top);
			fitF_S20_FWTM_top->SetParameter(1, fit0Mean_S20_FWTM_top);
			fitF_S20_FWTM_top->SetParameter(2, fit0Sigma_S20_FWTM_top);

			fitF_S20_FWTM_top->Draw("SAME");		

			ymean_S20_FWTM_top 			= fitF_S20_FWTM_top->GetParameter(1);
			ymeanEr_S20_FWTM_top 		= fitF_S20_FWTM_top->GetParError(1);
			ysigma_S20_FWTM_top 		= fitF_S20_FWTM_top->GetParameter(2);
			ysigmaEr_S20_FWTM_top 		= fitF_S20_FWTM_top->GetParError(2);
			median_S20_FWTM_top 		= h1_S20_FWTM_top->GetMean();
			medianError_S20_FWTM_top 	= h1_S20_FWTM_top->GetMeanError();

			h1_S20_FWTM_top		->GetQuantiles(Nqu, qu_S20_FWTM_top, probsum);
			fitF_S20_FWTM_top	->GetQuantiles(Nqu, quF_S20_FWTM_top, probsum);

			lineMean_S20_FWTM_top 	= new TLine(ymean_S20_FWTM_top, 0, ymean_S20_FWTM_top, Max_S20_FWTM_top);
			lineMean_S20_FWTM_top	->SetLineColor(2);
			lineMean_S20_FWTM_top	->SetLineWidth(1);
			lineF02_S20_FWTM_top 	= new TLine(quF_S20_FWTM_top[0], 0, quF_S20_FWTM_top[0], Max_S20_FWTM_top);
			lineF02_S20_FWTM_top	->SetLineColor(2);
			lineF02_S20_FWTM_top	->SetLineStyle(9);
			lineF05_S20_FWTM_top 	= new TLine(quF_S20_FWTM_top[1], 0, quF_S20_FWTM_top[1], Max_S20_FWTM_top);
			lineF05_S20_FWTM_top	->SetLineColor(2);
			lineF05_S20_FWTM_top	->SetLineStyle(9);
			lineF95_S20_FWTM_top 	= new TLine(quF_S20_FWTM_top[2], 0, quF_S20_FWTM_top[2], Max_S20_FWTM_top);
			lineF95_S20_FWTM_top	->SetLineColor(2);
			lineF95_S20_FWTM_top	->SetLineStyle(9);
			lineF98_S20_FWTM_top 	= new TLine(quF_S20_FWTM_top[3], 0, quF_S20_FWTM_top[3], Max_S20_FWTM_top);
			lineF98_S20_FWTM_top	->SetLineColor(2);
			lineF98_S20_FWTM_top	->SetLineStyle(9);

			lineMean_S20_FWTM_top	->Draw("same");
			lineF02_S20_FWTM_top	->Draw("same");
			lineF05_S20_FWTM_top	->Draw("same");
			lineF95_S20_FWTM_top	->Draw("same");
			lineF98_S20_FWTM_top	->Draw("same");

			lineMedian_S20_FWTM_top = new TLine(median_S20_FWTM_top, 0, median_S20_FWTM_top, Max_S20_FWTM_top);
			lineMedian_S20_FWTM_top	->SetLineColor(3);
			lineMedian_S20_FWTM_top	->SetLineWidth(1);
			line02_S20_FWTM_top = new TLine(qu_S20_FWTM_top[0], 0, qu_S20_FWTM_top[0], Max_S20_FWTM_top);
			line02_S20_FWTM_top	->SetLineColor(3);
			line02_S20_FWTM_top	->SetLineStyle(9);
			line05_S20_FWTM_top = new TLine(qu_S20_FWTM_top[1], 0, qu_S20_FWTM_top[1], Max_S20_FWTM_top);
			line05_S20_FWTM_top	->SetLineColor(3);
			line05_S20_FWTM_top	->SetLineStyle(9);
			line95_S20_FWTM_top = new TLine(qu_S20_FWTM_top[2], 0, qu_S20_FWTM_top[2], Max_S20_FWTM_top);
			line95_S20_FWTM_top	->SetLineColor(3);
			line95_S20_FWTM_top	->SetLineStyle(9);
			line98_S20_FWTM_top = new TLine(qu_S20_FWTM_top[3], 0, qu_S20_FWTM_top[3], Max_S20_FWTM_top);
			line98_S20_FWTM_top	->SetLineColor(3);
			line98_S20_FWTM_top	->SetLineStyle(9);

			lineMedian_S20_FWTM_top	->Draw("same");
			line02_S20_FWTM_top		->Draw("same");
			line05_S20_FWTM_top		->Draw("same");
			line95_S20_FWTM_top		->Draw("same");
			line98_S20_FWTM_top		->Draw("same");			

		   	ptstats_S20_FWTM_top = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S20_FWTM_top->SetName("stats");
   			ptstats_S20_FWTM_top->SetBorderSize(0);
   			//ptstats_S20_FWTM_top->SetTextAlign(12);
   			ptstats_S20_FWTM_top->SetFillStyle(0);
   			ptstats_S20_FWTM_top->SetFillColor(0);
  			sprintf(char_text1_S20_FWTM_top, "Median: (%2.1f #pm %2.1f) ns", median_S20_FWTM_top*1000, medianError_S20_FWTM_top*1000);
  			sprintf(char_text2_S20_FWTM_top, "Mean:   (%2.1f #pm %2.2f) ns", ymean_S20_FWTM_top*1000, ymeanEr_S20_FWTM_top*1000);
   			text1_S20_FWTM_top = ptstats_S20_FWTM_top->AddText(char_text1_S20_FWTM_top);
   			text2_S20_FWTM_top = ptstats_S20_FWTM_top->AddText(char_text2_S20_FWTM_top);
   			ptstats_S20_FWTM_top->Draw();
		c_S20_FWTM_top->Update();

		TCanvas *c_S20_FWTM_bot = new TCanvas("c_S20_FWTM_bot", "c_S20_FWTM_bot", 0, 0, 700, 500);
				 c_S20_FWTM_bot->SetFillColor(10);
				 c_S20_FWTM_bot->SetLogy(10);
			T1->Draw("S2widthLow_bot>>h1_S20_FWTM_bot", cut_DTslice_bot,"");
			h1_S20_FWTM_bot	->GetXaxis()->SetTitle("S2[0] FWTM, bottom [PE]");
			h1_S20_FWTM_bot	->GetYaxis()->SetTitle("Counts");
			h1_S20_FWTM_bot	->GetXaxis()->CenterTitle(true);
			h1_S20_FWTM_bot	->GetYaxis()->CenterTitle(true);
			h1_S20_FWTM_bot	->GetXaxis()->SetTitleOffset(1.25);
			h1_S20_FWTM_bot	->GetYaxis()->SetTitleOffset(1.25);

			Max_S20_FWTM_bot 		= h1_S20_FWTM_bot->GetMaximum();
			MaxBin_S20_FWTM_bot 	= h1_S20_FWTM_bot->GetMaximumBin();
			MaxBinCont_S20_FWTM_bot = h1_S20_FWTM_bot->GetBinContent(MaxBin_S20_FWTM_bot);
			MaxBinVal_S20_FWTM_bot 	= h1_S20_FWTM_bot->GetXaxis()->GetBinCenter(MaxBin_S20_FWTM_bot); 
			BinRms_S20_FWTM_bot		= h1_S20_FWTM_bot->GetRMS(1);
		
			fit0Min_S20_FWTM_bot = MaxBinVal_S20_FWTM_bot-BinRms_S20_FWTM_bot;
			fit0Max_S20_FWTM_bot = MaxBinVal_S20_FWTM_bot+BinRms_S20_FWTM_bot;

			fitF0_S20_FWTM_bot = new TF1("fitF0_S20_FWTM_bot","gaus", fit0Min_S20_FWTM_bot, fit0Max_S20_FWTM_bot);
			fitF0_S20_FWTM_bot->SetLineColor(3);
			fitF0_S20_FWTM_bot->SetLineWidth(1);
			h1_S20_FWTM_bot->Fit(fitF0_S20_FWTM_bot,"R");

			fit0Amp_S20_FWTM_bot	= fitF0_S20_FWTM_bot->GetParameter(0);
			fit0Mean_S20_FWTM_bot	= fitF0_S20_FWTM_bot->GetParameter(1);
			fit0Sigma_S20_FWTM_bot 	= fitF0_S20_FWTM_bot->GetParameter(2);		

			fitF_S20_FWTM_bot = new TF1("fitF_S20_FWTM_bot","gaus", fit0Mean_S20_FWTM_bot-5*fit0Sigma_S20_FWTM_bot, fit0Mean_S20_FWTM_bot+5*fit0Sigma_S20_FWTM_bot);
			fitF_S20_FWTM_bot->SetLineColor(2);
			fitF_S20_FWTM_bot->SetLineWidth(1);

			fitF_S20_FWTM_bot->SetParameter(0, fit0Amp_S20_FWTM_bot);
			fitF_S20_FWTM_bot->SetParameter(1, fit0Mean_S20_FWTM_bot);
			fitF_S20_FWTM_bot->SetParameter(2, fit0Sigma_S20_FWTM_bot);

			fitF_S20_FWTM_bot->Draw("SAME");		

			ymean_S20_FWTM_bot 			= fitF_S20_FWTM_bot->GetParameter(1);
			ymeanEr_S20_FWTM_bot 		= fitF_S20_FWTM_bot->GetParError(1);
			ysigma_S20_FWTM_bot 		= fitF_S20_FWTM_bot->GetParameter(2);
			ysigmaEr_S20_FWTM_bot 		= fitF_S20_FWTM_bot->GetParError(2);
			median_S20_FWTM_bot 		= h1_S20_FWTM_bot->GetMean();
			medianError_S20_FWTM_bot 	= h1_S20_FWTM_bot->GetMeanError();

			h1_S20_FWTM_bot		->GetQuantiles(Nqu, qu_S20_FWTM_bot, probsum);
			fitF_S20_FWTM_bot	->GetQuantiles(Nqu, quF_S20_FWTM_bot, probsum);

			lineMean_S20_FWTM_bot 	= new TLine(ymean_S20_FWTM_bot, 0, ymean_S20_FWTM_bot, Max_S20_FWTM_bot);
			lineMean_S20_FWTM_bot	->SetLineColor(2);
			lineMean_S20_FWTM_bot	->SetLineWidth(1);
			lineF02_S20_FWTM_bot 	= new TLine(quF_S20_FWTM_bot[0], 0, quF_S20_FWTM_bot[0], Max_S20_FWTM_bot);
			lineF02_S20_FWTM_bot	->SetLineColor(2);
			lineF02_S20_FWTM_bot	->SetLineStyle(9);
			lineF05_S20_FWTM_bot 	= new TLine(quF_S20_FWTM_bot[1], 0, quF_S20_FWTM_bot[1], Max_S20_FWTM_bot);
			lineF05_S20_FWTM_bot	->SetLineColor(2);
			lineF05_S20_FWTM_bot	->SetLineStyle(9);
			lineF95_S20_FWTM_bot 	= new TLine(quF_S20_FWTM_bot[2], 0, quF_S20_FWTM_bot[2], Max_S20_FWTM_bot);
			lineF95_S20_FWTM_bot	->SetLineColor(2);
			lineF95_S20_FWTM_bot	->SetLineStyle(9);
			lineF98_S20_FWTM_bot 	= new TLine(quF_S20_FWTM_bot[3], 0, quF_S20_FWTM_bot[3], Max_S20_FWTM_bot);
			lineF98_S20_FWTM_bot	->SetLineColor(2);
			lineF98_S20_FWTM_bot	->SetLineStyle(9);

			lineMean_S20_FWTM_bot	->Draw("same");
			lineF02_S20_FWTM_bot	->Draw("same");
			lineF05_S20_FWTM_bot	->Draw("same");
			lineF95_S20_FWTM_bot	->Draw("same");
			lineF98_S20_FWTM_bot	->Draw("same");

			lineMedian_S20_FWTM_bot = new TLine(median_S20_FWTM_bot, 0, median_S20_FWTM_bot, Max_S20_FWTM_bot);
			lineMedian_S20_FWTM_bot	->SetLineColor(3);
			lineMedian_S20_FWTM_bot	->SetLineWidth(1);
			line02_S20_FWTM_bot = new TLine(qu_S20_FWTM_bot[0], 0, qu_S20_FWTM_bot[0], Max_S20_FWTM_bot);
			line02_S20_FWTM_bot	->SetLineColor(3);
			line02_S20_FWTM_bot	->SetLineStyle(9);
			line05_S20_FWTM_bot = new TLine(qu_S20_FWTM_bot[1], 0, qu_S20_FWTM_bot[1], Max_S20_FWTM_bot);
			line05_S20_FWTM_bot	->SetLineColor(3);
			line05_S20_FWTM_bot	->SetLineStyle(9);
			line95_S20_FWTM_bot = new TLine(qu_S20_FWTM_bot[2], 0, qu_S20_FWTM_bot[2], Max_S20_FWTM_bot);
			line95_S20_FWTM_bot	->SetLineColor(3);
			line95_S20_FWTM_bot	->SetLineStyle(9);
			line98_S20_FWTM_bot = new TLine(qu_S20_FWTM_bot[3], 0, qu_S20_FWTM_bot[3], Max_S20_FWTM_bot);
			line98_S20_FWTM_bot	->SetLineColor(3);
			line98_S20_FWTM_bot	->SetLineStyle(9);

			lineMedian_S20_FWTM_bot	->Draw("same");
			line02_S20_FWTM_bot		->Draw("same");
			line05_S20_FWTM_bot		->Draw("same");
			line95_S20_FWTM_bot		->Draw("same");
			line98_S20_FWTM_bot		->Draw("same");			

		   	ptstats_S20_FWTM_bot = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S20_FWTM_bot->SetName("stats");
   			ptstats_S20_FWTM_bot->SetBorderSize(0);
   			//ptstats_S20_FWTM_bot->SetTextAlign(12);
   			ptstats_S20_FWTM_bot->SetFillStyle(0);
   			ptstats_S20_FWTM_bot->SetFillColor(0);
  			sprintf(char_text1_S20_FWTM_bot, "Median: (%2.1f #pm %2.1f) ns", median_S20_FWTM_bot*1000, medianError_S20_FWTM_bot*1000);
  			sprintf(char_text2_S20_FWTM_bot, "Mean:   (%2.1f #pm %2.2f) ns", ymean_S20_FWTM_bot*1000, ymeanEr_S20_FWTM_bot*1000);
   			text1_S20_FWTM_bot = ptstats_S20_FWTM_bot->AddText(char_text1_S20_FWTM_bot);
   			text2_S20_FWTM_bot = ptstats_S20_FWTM_bot->AddText(char_text2_S20_FWTM_bot);
   			ptstats_S20_FWTM_bot->Draw();
		c_S20_FWTM_bot->Update();


		TCanvas *c_S21_FWHM_top = new TCanvas("c_S21_FWHM_top", "c_S21_FWHM_top", 0, 0, 700, 500);
				 c_S21_FWHM_top->SetFillColor(10);
				 c_S21_FWHM_top->SetLogy(10);
			T1->Draw("S21width_top>>h1_S21_FWHM_top", cut_DT1slice_top,"");
			h1_S21_FWHM_top	->GetXaxis()->SetTitle("S2[1] FWHM, top [PE]");
			h1_S21_FWHM_top	->GetYaxis()->SetTitle("Counts");
			h1_S21_FWHM_top	->GetXaxis()->CenterTitle(true);
			h1_S21_FWHM_top	->GetYaxis()->CenterTitle(true);
			h1_S21_FWHM_top	->GetXaxis()->SetTitleOffset(1.25);
			h1_S21_FWHM_top	->GetYaxis()->SetTitleOffset(1.25);

			Max_S21_FWHM_top 		= h1_S21_FWHM_top->GetMaximum();
			MaxBin_S21_FWHM_top 	= h1_S21_FWHM_top->GetMaximumBin();
			MaxBinCont_S21_FWHM_top = h1_S21_FWHM_top->GetBinContent(MaxBin_S21_FWHM_top);
			MaxBinVal_S21_FWHM_top 	= h1_S21_FWHM_top->GetXaxis()->GetBinCenter(MaxBin_S21_FWHM_top); 
			BinRms_S21_FWHM_top		= h1_S21_FWHM_top->GetRMS(1);
		
			fit0Min_S21_FWHM_top = MaxBinVal_S21_FWHM_top-BinRms_S21_FWHM_top;
			fit0Max_S21_FWHM_top = MaxBinVal_S21_FWHM_top+BinRms_S21_FWHM_top;

			fitF0_S21_FWHM_top = new TF1("fitF0_S21_FWHM_top","gaus", fit0Min_S21_FWHM_top, fit0Max_S21_FWHM_top);
			fitF0_S21_FWHM_top->SetLineColor(3);
			fitF0_S21_FWHM_top->SetLineWidth(1);
			h1_S21_FWHM_top->Fit(fitF0_S21_FWHM_top,"R");

			fit0Amp_S21_FWHM_top	= fitF0_S21_FWHM_top->GetParameter(0);
			fit0Mean_S21_FWHM_top	= fitF0_S21_FWHM_top->GetParameter(1);
			fit0Sigma_S21_FWHM_top 	= fitF0_S21_FWHM_top->GetParameter(2);		

			fitF_S21_FWHM_top = new TF1("fitF_S21_FWHM_top","gaus", fit0Mean_S21_FWHM_top-5*fit0Sigma_S21_FWHM_top, fit0Mean_S21_FWHM_top+5*fit0Sigma_S21_FWHM_top);
			fitF_S21_FWHM_top->SetLineColor(2);
			fitF_S21_FWHM_top->SetLineWidth(1);

			fitF_S21_FWHM_top->SetParameter(0, fit0Amp_S21_FWHM_top);
			fitF_S21_FWHM_top->SetParameter(1, fit0Mean_S21_FWHM_top);
			fitF_S21_FWHM_top->SetParameter(2, fit0Sigma_S21_FWHM_top);

			fitF_S21_FWHM_top->Draw("SAME");		

			ymean_S21_FWHM_top 			= fitF_S21_FWHM_top->GetParameter(1);
			ymeanEr_S21_FWHM_top 		= fitF_S21_FWHM_top->GetParError(1);
			ysigma_S21_FWHM_top 		= fitF_S21_FWHM_top->GetParameter(2);
			ysigmaEr_S21_FWHM_top 		= fitF_S21_FWHM_top->GetParError(2);
			median_S21_FWHM_top 		= h1_S21_FWHM_top->GetMean();
			medianError_S21_FWHM_top 	= h1_S21_FWHM_top->GetMeanError();

			h1_S21_FWHM_top		->GetQuantiles(Nqu, qu_S21_FWHM_top, probsum);
			fitF_S21_FWHM_top	->GetQuantiles(Nqu, quF_S21_FWHM_top, probsum);

			lineMean_S21_FWHM_top 	= new TLine(ymean_S21_FWHM_top, 0, ymean_S21_FWHM_top, Max_S21_FWHM_top);
			lineMean_S21_FWHM_top	->SetLineColor(2);
			lineMean_S21_FWHM_top	->SetLineWidth(1);
			lineF02_S21_FWHM_top 	= new TLine(quF_S21_FWHM_top[0], 0, quF_S21_FWHM_top[0], Max_S21_FWHM_top);
			lineF02_S21_FWHM_top	->SetLineColor(2);
			lineF02_S21_FWHM_top	->SetLineStyle(9);
			lineF05_S21_FWHM_top 	= new TLine(quF_S21_FWHM_top[1], 0, quF_S21_FWHM_top[1], Max_S21_FWHM_top);
			lineF05_S21_FWHM_top	->SetLineColor(2);
			lineF05_S21_FWHM_top	->SetLineStyle(9);
			lineF95_S21_FWHM_top 	= new TLine(quF_S21_FWHM_top[2], 0, quF_S21_FWHM_top[2], Max_S21_FWHM_top);
			lineF95_S21_FWHM_top	->SetLineColor(2);
			lineF95_S21_FWHM_top	->SetLineStyle(9);
			lineF98_S21_FWHM_top 	= new TLine(quF_S21_FWHM_top[3], 0, quF_S21_FWHM_top[3], Max_S21_FWHM_top);
			lineF98_S21_FWHM_top	->SetLineColor(2);
			lineF98_S21_FWHM_top	->SetLineStyle(9);

			lineMean_S21_FWHM_top	->Draw("same");
			lineF02_S21_FWHM_top	->Draw("same");
			lineF05_S21_FWHM_top	->Draw("same");
			lineF95_S21_FWHM_top	->Draw("same");
			lineF98_S21_FWHM_top	->Draw("same");

			lineMedian_S21_FWHM_top = new TLine(median_S21_FWHM_top, 0, median_S21_FWHM_top, Max_S21_FWHM_top);
			lineMedian_S21_FWHM_top	->SetLineColor(3);
			lineMedian_S21_FWHM_top	->SetLineWidth(1);
			line02_S21_FWHM_top = new TLine(qu_S21_FWHM_top[0], 0, qu_S21_FWHM_top[0], Max_S21_FWHM_top);
			line02_S21_FWHM_top	->SetLineColor(3);
			line02_S21_FWHM_top	->SetLineStyle(9);
			line05_S21_FWHM_top = new TLine(qu_S21_FWHM_top[1], 0, qu_S21_FWHM_top[1], Max_S21_FWHM_top);
			line05_S21_FWHM_top	->SetLineColor(3);
			line05_S21_FWHM_top	->SetLineStyle(9);
			line95_S21_FWHM_top = new TLine(qu_S21_FWHM_top[2], 0, qu_S21_FWHM_top[2], Max_S21_FWHM_top);
			line95_S21_FWHM_top	->SetLineColor(3);
			line95_S21_FWHM_top	->SetLineStyle(9);
			line98_S21_FWHM_top = new TLine(qu_S21_FWHM_top[3], 0, qu_S21_FWHM_top[3], Max_S21_FWHM_top);
			line98_S21_FWHM_top	->SetLineColor(3);
			line98_S21_FWHM_top	->SetLineStyle(9);

			lineMedian_S21_FWHM_top	->Draw("same");
			line02_S21_FWHM_top		->Draw("same");
			line05_S21_FWHM_top		->Draw("same");
			line95_S21_FWHM_top		->Draw("same");
			line98_S21_FWHM_top		->Draw("same");			

		   	ptstats_S21_FWHM_top = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S21_FWHM_top->SetName("stats");
   			ptstats_S21_FWHM_top->SetBorderSize(0);
   			//ptstats_S21_FWHM_top->SetTextAlign(12);
   			ptstats_S21_FWHM_top->SetFillStyle(0);
   			ptstats_S21_FWHM_top->SetFillColor(0);
  			sprintf(char_text1_S21_FWHM_top, "Median: (%2.1f #pm %2.1f) ns", median_S21_FWHM_top*1000, medianError_S21_FWHM_top*1000);
  			sprintf(char_text2_S21_FWHM_top, "Mean:   (%2.1f #pm %2.2f) ns", ymean_S21_FWHM_top*1000, ymeanEr_S21_FWHM_top*1000);
   			text1_S21_FWHM_top = ptstats_S21_FWHM_top->AddText(char_text1_S21_FWHM_top);
   			text2_S21_FWHM_top = ptstats_S21_FWHM_top->AddText(char_text2_S21_FWHM_top);
   			ptstats_S21_FWHM_top->Draw();
		c_S21_FWHM_top->Update();

		TCanvas *c_S21_FWHM_bot = new TCanvas("c_S21_FWHM_bot", "c_S21_FWHM_bot", 0, 0, 700, 500);
				 c_S21_FWHM_bot->SetFillColor(10);
				 c_S21_FWHM_bot->SetLogy(10);
			T1->Draw("S21width_bot>>h1_S21_FWHM_bot", cut_DT1slice_bot,"");
			h1_S21_FWHM_bot	->GetXaxis()->SetTitle("S2[1] FWHM, bottom [PE]");
			h1_S21_FWHM_bot	->GetYaxis()->SetTitle("Counts");
			h1_S21_FWHM_bot	->GetXaxis()->CenterTitle(true);
			h1_S21_FWHM_bot	->GetYaxis()->CenterTitle(true);
			h1_S21_FWHM_bot	->GetXaxis()->SetTitleOffset(1.25);
			h1_S21_FWHM_bot	->GetYaxis()->SetTitleOffset(1.25);

			Max_S21_FWHM_bot 		= h1_S21_FWHM_bot->GetMaximum();
			MaxBin_S21_FWHM_bot 	= h1_S21_FWHM_bot->GetMaximumBin();
			MaxBinCont_S21_FWHM_bot = h1_S21_FWHM_bot->GetBinContent(MaxBin_S21_FWHM_bot);
			MaxBinVal_S21_FWHM_bot 	= h1_S21_FWHM_bot->GetXaxis()->GetBinCenter(MaxBin_S21_FWHM_bot); 
			BinRms_S21_FWHM_bot		= h1_S21_FWHM_bot->GetRMS(1);
		
			fit0Min_S21_FWHM_bot = MaxBinVal_S21_FWHM_bot-BinRms_S21_FWHM_bot;
			fit0Max_S21_FWHM_bot = MaxBinVal_S21_FWHM_bot+BinRms_S21_FWHM_bot;

			fitF0_S21_FWHM_bot = new TF1("fitF0_S21_FWHM_bot","gaus", fit0Min_S21_FWHM_bot, fit0Max_S21_FWHM_bot);
			fitF0_S21_FWHM_bot->SetLineColor(3);
			fitF0_S21_FWHM_bot->SetLineWidth(1);
			h1_S21_FWHM_bot->Fit(fitF0_S21_FWHM_bot,"R");

			fit0Amp_S21_FWHM_bot	= fitF0_S21_FWHM_bot->GetParameter(0);
			fit0Mean_S21_FWHM_bot	= fitF0_S21_FWHM_bot->GetParameter(1);
			fit0Sigma_S21_FWHM_bot 	= fitF0_S21_FWHM_bot->GetParameter(2);		

			fitF_S21_FWHM_bot = new TF1("fitF_S21_FWHM_bot","gaus", fit0Mean_S21_FWHM_bot-5*fit0Sigma_S21_FWHM_bot, fit0Mean_S21_FWHM_bot+5*fit0Sigma_S21_FWHM_bot);
			fitF_S21_FWHM_bot->SetLineColor(2);
			fitF_S21_FWHM_bot->SetLineWidth(1);

			fitF_S21_FWHM_bot->SetParameter(0, fit0Amp_S21_FWHM_bot);
			fitF_S21_FWHM_bot->SetParameter(1, fit0Mean_S21_FWHM_bot);
			fitF_S21_FWHM_bot->SetParameter(2, fit0Sigma_S21_FWHM_bot);

			fitF_S21_FWHM_bot->Draw("SAME");		

			ymean_S21_FWHM_bot 			= fitF_S21_FWHM_bot->GetParameter(1);
			ymeanEr_S21_FWHM_bot 		= fitF_S21_FWHM_bot->GetParError(1);
			ysigma_S21_FWHM_bot 		= fitF_S21_FWHM_bot->GetParameter(2);
			ysigmaEr_S21_FWHM_bot 		= fitF_S21_FWHM_bot->GetParError(2);
			median_S21_FWHM_bot 		= h1_S21_FWHM_bot->GetMean();
			medianError_S21_FWHM_bot 	= h1_S21_FWHM_bot->GetMeanError();

			h1_S21_FWHM_bot		->GetQuantiles(Nqu, qu_S21_FWHM_bot, probsum);
			fitF_S21_FWHM_bot	->GetQuantiles(Nqu, quF_S21_FWHM_bot, probsum);

			lineMean_S21_FWHM_bot 	= new TLine(ymean_S21_FWHM_bot, 0, ymean_S21_FWHM_bot, Max_S21_FWHM_bot);
			lineMean_S21_FWHM_bot	->SetLineColor(2);
			lineMean_S21_FWHM_bot	->SetLineWidth(1);
			lineF02_S21_FWHM_bot 	= new TLine(quF_S21_FWHM_bot[0], 0, quF_S21_FWHM_bot[0], Max_S21_FWHM_bot);
			lineF02_S21_FWHM_bot	->SetLineColor(2);
			lineF02_S21_FWHM_bot	->SetLineStyle(9);
			lineF05_S21_FWHM_bot 	= new TLine(quF_S21_FWHM_bot[1], 0, quF_S21_FWHM_bot[1], Max_S21_FWHM_bot);
			lineF05_S21_FWHM_bot	->SetLineColor(2);
			lineF05_S21_FWHM_bot	->SetLineStyle(9);
			lineF95_S21_FWHM_bot 	= new TLine(quF_S21_FWHM_bot[2], 0, quF_S21_FWHM_bot[2], Max_S21_FWHM_bot);
			lineF95_S21_FWHM_bot	->SetLineColor(2);
			lineF95_S21_FWHM_bot	->SetLineStyle(9);
			lineF98_S21_FWHM_bot 	= new TLine(quF_S21_FWHM_bot[3], 0, quF_S21_FWHM_bot[3], Max_S21_FWHM_bot);
			lineF98_S21_FWHM_bot	->SetLineColor(2);
			lineF98_S21_FWHM_bot	->SetLineStyle(9);

			lineMean_S21_FWHM_bot	->Draw("same");
			lineF02_S21_FWHM_bot	->Draw("same");
			lineF05_S21_FWHM_bot	->Draw("same");
			lineF95_S21_FWHM_bot	->Draw("same");
			lineF98_S21_FWHM_bot	->Draw("same");

			lineMedian_S21_FWHM_bot = new TLine(median_S21_FWHM_bot, 0, median_S21_FWHM_bot, Max_S21_FWHM_bot);
			lineMedian_S21_FWHM_bot	->SetLineColor(3);
			lineMedian_S21_FWHM_bot	->SetLineWidth(1);
			line02_S21_FWHM_bot = new TLine(qu_S21_FWHM_bot[0], 0, qu_S21_FWHM_bot[0], Max_S21_FWHM_bot);
			line02_S21_FWHM_bot	->SetLineColor(3);
			line02_S21_FWHM_bot	->SetLineStyle(9);
			line05_S21_FWHM_bot = new TLine(qu_S21_FWHM_bot[1], 0, qu_S21_FWHM_bot[1], Max_S21_FWHM_bot);
			line05_S21_FWHM_bot	->SetLineColor(3);
			line05_S21_FWHM_bot	->SetLineStyle(9);
			line95_S21_FWHM_bot = new TLine(qu_S21_FWHM_bot[2], 0, qu_S21_FWHM_bot[2], Max_S21_FWHM_bot);
			line95_S21_FWHM_bot	->SetLineColor(3);
			line95_S21_FWHM_bot	->SetLineStyle(9);
			line98_S21_FWHM_bot = new TLine(qu_S21_FWHM_bot[3], 0, qu_S21_FWHM_bot[3], Max_S21_FWHM_bot);
			line98_S21_FWHM_bot	->SetLineColor(3);
			line98_S21_FWHM_bot	->SetLineStyle(9);

			lineMedian_S21_FWHM_bot	->Draw("same");
			line02_S21_FWHM_bot		->Draw("same");
			line05_S21_FWHM_bot		->Draw("same");
			line95_S21_FWHM_bot		->Draw("same");
			line98_S21_FWHM_bot		->Draw("same");			

		   	ptstats_S21_FWHM_bot = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S21_FWHM_bot->SetName("stats");
   			ptstats_S21_FWHM_bot->SetBorderSize(0);
   			//ptstats_S21_FWHM_bot->SetTextAlign(12);
   			ptstats_S21_FWHM_bot->SetFillStyle(0);
   			ptstats_S21_FWHM_bot->SetFillColor(0);
  			sprintf(char_text1_S21_FWHM_bot, "Median: (%2.1f #pm %2.1f) ns", median_S21_FWHM_bot*1000, medianError_S21_FWHM_bot*1000);
  			sprintf(char_text2_S21_FWHM_bot, "Mean:   (%2.1f #pm %2.2f) ns", ymean_S21_FWHM_bot*1000, ymeanEr_S21_FWHM_bot*1000);
   			text1_S21_FWHM_bot = ptstats_S21_FWHM_bot->AddText(char_text1_S21_FWHM_bot);
   			text2_S21_FWHM_bot = ptstats_S21_FWHM_bot->AddText(char_text2_S21_FWHM_bot);
   			ptstats_S21_FWHM_bot->Draw();
		c_S21_FWHM_bot->Update();

		TCanvas *c_S21_FWTM_top = new TCanvas("c_S21_FWTM_top", "c_S21_FWTM_top", 0, 0, 700, 500);
				 c_S21_FWTM_top->SetFillColor(10);
				 c_S21_FWTM_top->SetLogy(10);
			T1->Draw("S21widthLow_top>>h1_S21_FWTM_top", cut_DT1slice_top,"");
			h1_S21_FWTM_top	->GetXaxis()->SetTitle("S2[1] FWTM, top [PE]");
			h1_S21_FWTM_top	->GetYaxis()->SetTitle("Counts");
			h1_S21_FWTM_top	->GetXaxis()->CenterTitle(true);
			h1_S21_FWTM_top	->GetYaxis()->CenterTitle(true);
			h1_S21_FWTM_top	->GetXaxis()->SetTitleOffset(1.25);
			h1_S21_FWTM_top	->GetYaxis()->SetTitleOffset(1.25);

			Max_S21_FWTM_top 		= h1_S21_FWTM_top->GetMaximum();
			MaxBin_S21_FWTM_top 	= h1_S21_FWTM_top->GetMaximumBin();
			MaxBinCont_S21_FWTM_top = h1_S21_FWTM_top->GetBinContent(MaxBin_S21_FWTM_top);
			MaxBinVal_S21_FWTM_top 	= h1_S21_FWTM_top->GetXaxis()->GetBinCenter(MaxBin_S21_FWTM_top); 
			BinRms_S21_FWTM_top		= h1_S21_FWTM_top->GetRMS(1);
		
			fit0Min_S21_FWTM_top = MaxBinVal_S21_FWTM_top-BinRms_S21_FWTM_top;
			fit0Max_S21_FWTM_top = MaxBinVal_S21_FWTM_top+BinRms_S21_FWTM_top;

			fitF0_S21_FWTM_top = new TF1("fitF0_S21_FWTM_top","gaus", fit0Min_S21_FWTM_top, fit0Max_S21_FWTM_top);
			fitF0_S21_FWTM_top->SetLineColor(3);
			fitF0_S21_FWTM_top->SetLineWidth(1);
			h1_S21_FWTM_top->Fit(fitF0_S21_FWTM_top,"R");

			fit0Amp_S21_FWTM_top	= fitF0_S21_FWTM_top->GetParameter(0);
			fit0Mean_S21_FWTM_top	= fitF0_S21_FWTM_top->GetParameter(1);
			fit0Sigma_S21_FWTM_top 	= fitF0_S21_FWTM_top->GetParameter(2);		

			fitF_S21_FWTM_top = new TF1("fitF_S21_FWTM_top","gaus", fit0Mean_S21_FWTM_top-5*fit0Sigma_S21_FWTM_top, fit0Mean_S21_FWTM_top+5*fit0Sigma_S21_FWTM_top);
			fitF_S21_FWTM_top->SetLineColor(2);
			fitF_S21_FWTM_top->SetLineWidth(1);

			fitF_S21_FWTM_top->SetParameter(0, fit0Amp_S21_FWTM_top);
			fitF_S21_FWTM_top->SetParameter(1, fit0Mean_S21_FWTM_top);
			fitF_S21_FWTM_top->SetParameter(2, fit0Sigma_S21_FWTM_top);

			fitF_S21_FWTM_top->Draw("SAME");		

			ymean_S21_FWTM_top 			= fitF_S21_FWTM_top->GetParameter(1);
			ymeanEr_S21_FWTM_top 		= fitF_S21_FWTM_top->GetParError(1);
			ysigma_S21_FWTM_top 		= fitF_S21_FWTM_top->GetParameter(2);
			ysigmaEr_S21_FWTM_top 		= fitF_S21_FWTM_top->GetParError(2);
			median_S21_FWTM_top 		= h1_S21_FWTM_top->GetMean();
			medianError_S21_FWTM_top 	= h1_S21_FWTM_top->GetMeanError();

			h1_S21_FWTM_top		->GetQuantiles(Nqu, qu_S21_FWTM_top, probsum);
			fitF_S21_FWTM_top	->GetQuantiles(Nqu, quF_S21_FWTM_top, probsum);

			lineMean_S21_FWTM_top 	= new TLine(ymean_S21_FWTM_top, 0, ymean_S21_FWTM_top, Max_S21_FWTM_top);
			lineMean_S21_FWTM_top	->SetLineColor(2);
			lineMean_S21_FWTM_top	->SetLineWidth(1);
			lineF02_S21_FWTM_top 	= new TLine(quF_S21_FWTM_top[0], 0, quF_S21_FWTM_top[0], Max_S21_FWTM_top);
			lineF02_S21_FWTM_top	->SetLineColor(2);
			lineF02_S21_FWTM_top	->SetLineStyle(9);
			lineF05_S21_FWTM_top 	= new TLine(quF_S21_FWTM_top[1], 0, quF_S21_FWTM_top[1], Max_S21_FWTM_top);
			lineF05_S21_FWTM_top	->SetLineColor(2);
			lineF05_S21_FWTM_top	->SetLineStyle(9);
			lineF95_S21_FWTM_top 	= new TLine(quF_S21_FWTM_top[2], 0, quF_S21_FWTM_top[2], Max_S21_FWTM_top);
			lineF95_S21_FWTM_top	->SetLineColor(2);
			lineF95_S21_FWTM_top	->SetLineStyle(9);
			lineF98_S21_FWTM_top 	= new TLine(quF_S21_FWTM_top[3], 0, quF_S21_FWTM_top[3], Max_S21_FWTM_top);
			lineF98_S21_FWTM_top	->SetLineColor(2);
			lineF98_S21_FWTM_top	->SetLineStyle(9);

			lineMean_S21_FWTM_top	->Draw("same");
			lineF02_S21_FWTM_top	->Draw("same");
			lineF05_S21_FWTM_top	->Draw("same");
			lineF95_S21_FWTM_top	->Draw("same");
			lineF98_S21_FWTM_top	->Draw("same");

			lineMedian_S21_FWTM_top = new TLine(median_S21_FWTM_top, 0, median_S21_FWTM_top, Max_S21_FWTM_top);
			lineMedian_S21_FWTM_top	->SetLineColor(3);
			lineMedian_S21_FWTM_top	->SetLineWidth(1);
			line02_S21_FWTM_top = new TLine(qu_S21_FWTM_top[0], 0, qu_S21_FWTM_top[0], Max_S21_FWTM_top);
			line02_S21_FWTM_top	->SetLineColor(3);
			line02_S21_FWTM_top	->SetLineStyle(9);
			line05_S21_FWTM_top = new TLine(qu_S21_FWTM_top[1], 0, qu_S21_FWTM_top[1], Max_S21_FWTM_top);
			line05_S21_FWTM_top	->SetLineColor(3);
			line05_S21_FWTM_top	->SetLineStyle(9);
			line95_S21_FWTM_top = new TLine(qu_S21_FWTM_top[2], 0, qu_S21_FWTM_top[2], Max_S21_FWTM_top);
			line95_S21_FWTM_top	->SetLineColor(3);
			line95_S21_FWTM_top	->SetLineStyle(9);
			line98_S21_FWTM_top = new TLine(qu_S21_FWTM_top[3], 0, qu_S21_FWTM_top[3], Max_S21_FWTM_top);
			line98_S21_FWTM_top	->SetLineColor(3);
			line98_S21_FWTM_top	->SetLineStyle(9);

			lineMedian_S21_FWTM_top	->Draw("same");
			line02_S21_FWTM_top		->Draw("same");
			line05_S21_FWTM_top		->Draw("same");
			line95_S21_FWTM_top		->Draw("same");
			line98_S21_FWTM_top		->Draw("same");			

		   	ptstats_S21_FWTM_top = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S21_FWTM_top->SetName("stats");
   			ptstats_S21_FWTM_top->SetBorderSize(0);
   			//ptstats_S21_FWTM_top->SetTextAlign(12);
   			ptstats_S21_FWTM_top->SetFillStyle(0);
   			ptstats_S21_FWTM_top->SetFillColor(0);
  			sprintf(char_text1_S21_FWTM_top, "Median: (%2.1f #pm %2.1f) ns", median_S21_FWTM_top*1000, medianError_S21_FWTM_top*1000);
  			sprintf(char_text2_S21_FWTM_top, "Mean:   (%2.1f #pm %2.2f) ns", ymean_S21_FWTM_top*1000, ymeanEr_S21_FWTM_top*1000);
   			text1_S21_FWTM_top = ptstats_S21_FWTM_top->AddText(char_text1_S21_FWTM_top);
   			text2_S21_FWTM_top = ptstats_S21_FWTM_top->AddText(char_text2_S21_FWTM_top);
   			ptstats_S21_FWTM_top->Draw();
		c_S21_FWTM_top->Update();

		TCanvas *c_S21_FWTM_bot = new TCanvas("c_S21_FWTM_bot", "c_S21_FWTM_bot", 0, 0, 700, 500);
				 c_S21_FWTM_bot->SetFillColor(10);
				 c_S21_FWTM_bot->SetLogy(10);
			T1->Draw("S21widthLow_bot>>h1_S21_FWTM_bot", cut_DT1slice_bot,"");
			h1_S21_FWTM_bot	->GetXaxis()->SetTitle("S2[1] FWTM, bottom [PE]");
			h1_S21_FWTM_bot	->GetYaxis()->SetTitle("Counts");
			h1_S21_FWTM_bot	->GetXaxis()->CenterTitle(true);
			h1_S21_FWTM_bot	->GetYaxis()->CenterTitle(true);
			h1_S21_FWTM_bot	->GetXaxis()->SetTitleOffset(1.25);
			h1_S21_FWTM_bot	->GetYaxis()->SetTitleOffset(1.25);

			Max_S21_FWTM_bot 		= h1_S21_FWTM_bot->GetMaximum();
			MaxBin_S21_FWTM_bot 	= h1_S21_FWTM_bot->GetMaximumBin();
			MaxBinCont_S21_FWTM_bot = h1_S21_FWTM_bot->GetBinContent(MaxBin_S21_FWTM_bot);
			MaxBinVal_S21_FWTM_bot 	= h1_S21_FWTM_bot->GetXaxis()->GetBinCenter(MaxBin_S21_FWTM_bot); 
			BinRms_S21_FWTM_bot		= h1_S21_FWTM_bot->GetRMS(1);
		
			fit0Min_S21_FWTM_bot = MaxBinVal_S21_FWTM_bot-BinRms_S21_FWTM_bot;
			fit0Max_S21_FWTM_bot = MaxBinVal_S21_FWTM_bot+BinRms_S21_FWTM_bot;

			fitF0_S21_FWTM_bot = new TF1("fitF0_S21_FWTM_bot","gaus", fit0Min_S21_FWTM_bot, fit0Max_S21_FWTM_bot);
			fitF0_S21_FWTM_bot->SetLineColor(3);
			fitF0_S21_FWTM_bot->SetLineWidth(1);
			h1_S21_FWTM_bot->Fit(fitF0_S21_FWTM_bot,"R");

			fit0Amp_S21_FWTM_bot	= fitF0_S21_FWTM_bot->GetParameter(0);
			fit0Mean_S21_FWTM_bot	= fitF0_S21_FWTM_bot->GetParameter(1);
			fit0Sigma_S21_FWTM_bot 	= fitF0_S21_FWTM_bot->GetParameter(2);		

			fitF_S21_FWTM_bot = new TF1("fitF_S21_FWTM_bot","gaus", fit0Mean_S21_FWTM_bot-5*fit0Sigma_S21_FWTM_bot, fit0Mean_S21_FWTM_bot+5*fit0Sigma_S21_FWTM_bot);
			fitF_S21_FWTM_bot->SetLineColor(2);
			fitF_S21_FWTM_bot->SetLineWidth(1);

			fitF_S21_FWTM_bot->SetParameter(0, fit0Amp_S21_FWTM_bot);
			fitF_S21_FWTM_bot->SetParameter(1, fit0Mean_S21_FWTM_bot);
			fitF_S21_FWTM_bot->SetParameter(2, fit0Sigma_S21_FWTM_bot);

			fitF_S21_FWTM_bot->Draw("SAME");		

			ymean_S21_FWTM_bot 			= fitF_S21_FWTM_bot->GetParameter(1);
			ymeanEr_S21_FWTM_bot 		= fitF_S21_FWTM_bot->GetParError(1);
			ysigma_S21_FWTM_bot 		= fitF_S21_FWTM_bot->GetParameter(2);
			ysigmaEr_S21_FWTM_bot 		= fitF_S21_FWTM_bot->GetParError(2);
			median_S21_FWTM_bot 		= h1_S21_FWTM_bot->GetMean();
			medianError_S21_FWTM_bot 	= h1_S21_FWTM_bot->GetMeanError();

			h1_S21_FWTM_bot		->GetQuantiles(Nqu, qu_S21_FWTM_bot, probsum);
			fitF_S21_FWTM_bot	->GetQuantiles(Nqu, quF_S21_FWTM_bot, probsum);

			lineMean_S21_FWTM_bot 	= new TLine(ymean_S21_FWTM_bot, 0, ymean_S21_FWTM_bot, Max_S21_FWTM_bot);
			lineMean_S21_FWTM_bot	->SetLineColor(2);
			lineMean_S21_FWTM_bot	->SetLineWidth(1);
			lineF02_S21_FWTM_bot 	= new TLine(quF_S21_FWTM_bot[0], 0, quF_S21_FWTM_bot[0], Max_S21_FWTM_bot);
			lineF02_S21_FWTM_bot	->SetLineColor(2);
			lineF02_S21_FWTM_bot	->SetLineStyle(9);
			lineF05_S21_FWTM_bot 	= new TLine(quF_S21_FWTM_bot[1], 0, quF_S21_FWTM_bot[1], Max_S21_FWTM_bot);
			lineF05_S21_FWTM_bot	->SetLineColor(2);
			lineF05_S21_FWTM_bot	->SetLineStyle(9);
			lineF95_S21_FWTM_bot 	= new TLine(quF_S21_FWTM_bot[2], 0, quF_S21_FWTM_bot[2], Max_S21_FWTM_bot);
			lineF95_S21_FWTM_bot	->SetLineColor(2);
			lineF95_S21_FWTM_bot	->SetLineStyle(9);
			lineF98_S21_FWTM_bot 	= new TLine(quF_S21_FWTM_bot[3], 0, quF_S21_FWTM_bot[3], Max_S21_FWTM_bot);
			lineF98_S21_FWTM_bot	->SetLineColor(2);
			lineF98_S21_FWTM_bot	->SetLineStyle(9);

			lineMean_S21_FWTM_bot	->Draw("same");
			lineF02_S21_FWTM_bot	->Draw("same");
			lineF05_S21_FWTM_bot	->Draw("same");
			lineF95_S21_FWTM_bot	->Draw("same");
			lineF98_S21_FWTM_bot	->Draw("same");

			lineMedian_S21_FWTM_bot = new TLine(median_S21_FWTM_bot, 0, median_S21_FWTM_bot, Max_S21_FWTM_bot);
			lineMedian_S21_FWTM_bot	->SetLineColor(3);
			lineMedian_S21_FWTM_bot	->SetLineWidth(1);
			line02_S21_FWTM_bot = new TLine(qu_S21_FWTM_bot[0], 0, qu_S21_FWTM_bot[0], Max_S21_FWTM_bot);
			line02_S21_FWTM_bot	->SetLineColor(3);
			line02_S21_FWTM_bot	->SetLineStyle(9);
			line05_S21_FWTM_bot = new TLine(qu_S21_FWTM_bot[1], 0, qu_S21_FWTM_bot[1], Max_S21_FWTM_bot);
			line05_S21_FWTM_bot	->SetLineColor(3);
			line05_S21_FWTM_bot	->SetLineStyle(9);
			line95_S21_FWTM_bot = new TLine(qu_S21_FWTM_bot[2], 0, qu_S21_FWTM_bot[2], Max_S21_FWTM_bot);
			line95_S21_FWTM_bot	->SetLineColor(3);
			line95_S21_FWTM_bot	->SetLineStyle(9);
			line98_S21_FWTM_bot = new TLine(qu_S21_FWTM_bot[3], 0, qu_S21_FWTM_bot[3], Max_S21_FWTM_bot);
			line98_S21_FWTM_bot	->SetLineColor(3);
			line98_S21_FWTM_bot	->SetLineStyle(9);

			lineMedian_S21_FWTM_bot	->Draw("same");
			line02_S21_FWTM_bot		->Draw("same");
			line05_S21_FWTM_bot		->Draw("same");
			line95_S21_FWTM_bot		->Draw("same");
			line98_S21_FWTM_bot		->Draw("same");			

		   	ptstats_S21_FWTM_bot = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   			ptstats_S21_FWTM_bot->SetName("stats");
   			ptstats_S21_FWTM_bot->SetBorderSize(0);
   			//ptstats_S21_FWTM_bot->SetTextAlign(12);
   			ptstats_S21_FWTM_bot->SetFillStyle(0);
   			ptstats_S21_FWTM_bot->SetFillColor(0);
  			sprintf(char_text1_S21_FWTM_bot, "Median: (%2.1f #pm %2.1f) ns", median_S21_FWTM_bot*1000, medianError_S21_FWTM_bot*1000);
  			sprintf(char_text2_S21_FWTM_bot, "Mean:   (%2.1f #pm %2.2f) ns", ymean_S21_FWTM_bot*1000, ymeanEr_S21_FWTM_bot*1000);
   			text1_S21_FWTM_bot = ptstats_S21_FWTM_bot->AddText(char_text1_S21_FWTM_bot);
   			text2_S21_FWTM_bot = ptstats_S21_FWTM_bot->AddText(char_text2_S21_FWTM_bot);
   			ptstats_S21_FWTM_bot->Draw();
		c_S21_FWTM_bot->Update();
	
		xmean 		= min_DTslice + (max_DTslice - min_DTslice)/2;
		xinterval 	= (max_DTslice - min_DTslice)/2;
		x[i] 		= xmean;
		xer[i] 		= xinterval;
	
		y_S20_FWHM_top[i]		= median_S20_FWHM_top;
		y02_S20_FWHM_top[i]		= qu_S20_FWHM_top[0];
		y05_S20_FWHM_top[i]		= qu_S20_FWHM_top[1];
		y95_S20_FWHM_top[i]		= qu_S20_FWHM_top[2];
		y98_S20_FWHM_top[i]		= qu_S20_FWHM_top[3];
		yF_S20_FWHM_top[i]		= ymean_S20_FWHM_top;
		yF02_S20_FWHM_top[i]	= quF_S20_FWHM_top[0];
		yF05_S20_FWHM_top[i]	= quF_S20_FWHM_top[1];
		yF95_S20_FWHM_top[i]	= quF_S20_FWHM_top[2];
		yF98_S20_FWHM_top[i]	= quF_S20_FWHM_top[3];

		y_S20_FWHM_bot[i]		= median_S20_FWHM_bot;
		y02_S20_FWHM_bot[i]		= qu_S20_FWHM_bot[0];
		y05_S20_FWHM_bot[i]		= qu_S20_FWHM_bot[1];
		y95_S20_FWHM_bot[i]		= qu_S20_FWHM_bot[2];
		y98_S20_FWHM_bot[i]		= qu_S20_FWHM_bot[3];
		yF_S20_FWHM_bot[i]		= ymean_S20_FWHM_bot;
		yF02_S20_FWHM_bot[i]	= quF_S20_FWHM_bot[0];
		yF05_S20_FWHM_bot[i]	= quF_S20_FWHM_bot[1];
		yF95_S20_FWHM_bot[i]	= quF_S20_FWHM_bot[2];
		yF98_S20_FWHM_bot[i]	= quF_S20_FWHM_bot[3];

		y_S20_FWTM_top[i]		= median_S20_FWTM_top;
		y02_S20_FWTM_top[i]		= qu_S20_FWTM_top[0];
		y05_S20_FWTM_top[i]		= qu_S20_FWTM_top[1];
		y95_S20_FWTM_top[i]		= qu_S20_FWTM_top[2];
		y98_S20_FWTM_top[i]		= qu_S20_FWTM_top[3];
		yF_S20_FWTM_top[i]		= ymean_S20_FWTM_top;
		yF02_S20_FWTM_top[i]	= quF_S20_FWTM_top[0];
		yF05_S20_FWTM_top[i]	= quF_S20_FWTM_top[1];
		yF95_S20_FWTM_top[i]	= quF_S20_FWTM_top[2];
		yF98_S20_FWTM_top[i]	= quF_S20_FWTM_top[3];

		y_S20_FWTM_bot[i]		= median_S20_FWTM_bot;
		y02_S20_FWTM_bot[i]		= qu_S20_FWTM_bot[0];
		y05_S20_FWTM_bot[i]		= qu_S20_FWTM_bot[1];
		y95_S20_FWTM_bot[i]		= qu_S20_FWTM_bot[2];
		y98_S20_FWTM_bot[i]		= qu_S20_FWTM_bot[3];
		yF_S20_FWTM_bot[i]		= ymean_S20_FWTM_bot;
		yF02_S20_FWTM_bot[i]	= quF_S20_FWTM_bot[0];
		yF05_S20_FWTM_bot[i]	= quF_S20_FWTM_bot[1];
		yF95_S20_FWTM_bot[i]	= quF_S20_FWTM_bot[2];
		yF98_S20_FWTM_bot[i]	= quF_S20_FWTM_bot[3];

		y_S21_FWHM_top[i]		= median_S21_FWHM_top;
		y02_S21_FWHM_top[i]		= qu_S21_FWHM_top[0];
		y05_S21_FWHM_top[i]		= qu_S21_FWHM_top[1];
		y95_S21_FWHM_top[i]		= qu_S21_FWHM_top[2];
		y98_S21_FWHM_top[i]		= qu_S21_FWHM_top[3];
		yF_S21_FWHM_top[i]		= ymean_S21_FWHM_top;
		yF02_S21_FWHM_top[i]	= quF_S21_FWHM_top[0];
		yF05_S21_FWHM_top[i]	= quF_S21_FWHM_top[1];
		yF95_S21_FWHM_top[i]	= quF_S21_FWHM_top[2];
		yF98_S21_FWHM_top[i]	= quF_S21_FWHM_top[3];

		y_S21_FWHM_bot[i]		= median_S21_FWHM_bot;
		y02_S21_FWHM_bot[i]		= qu_S21_FWHM_bot[0];
		y05_S21_FWHM_bot[i]		= qu_S21_FWHM_bot[1];
		y95_S21_FWHM_bot[i]		= qu_S21_FWHM_bot[2];
		y98_S21_FWHM_bot[i]		= qu_S21_FWHM_bot[3];
		yF_S21_FWHM_bot[i]		= ymean_S21_FWHM_bot;
		yF02_S21_FWHM_bot[i]	= quF_S21_FWHM_bot[0];
		yF05_S21_FWHM_bot[i]	= quF_S21_FWHM_bot[1];
		yF95_S21_FWHM_bot[i]	= quF_S21_FWHM_bot[2];
		yF98_S21_FWHM_bot[i]	= quF_S21_FWHM_bot[3];

		y_S21_FWTM_top[i]		= median_S21_FWTM_top;
		y02_S21_FWTM_top[i]		= qu_S21_FWTM_top[0];
		y05_S21_FWTM_top[i]		= qu_S21_FWTM_top[1];
		y95_S21_FWTM_top[i]		= qu_S21_FWTM_top[2];
		y98_S21_FWTM_top[i]		= qu_S21_FWTM_top[3];
		yF_S21_FWTM_top[i]		= ymean_S21_FWTM_top;
		yF02_S21_FWTM_top[i]	= quF_S21_FWTM_top[0];
		yF05_S21_FWTM_top[i]	= quF_S21_FWTM_top[1];
		yF95_S21_FWTM_top[i]	= quF_S21_FWTM_top[2];
		yF98_S21_FWTM_top[i]	= quF_S21_FWTM_top[3];

		y_S21_FWTM_bot[i]		= median_S21_FWTM_bot;
		y02_S21_FWTM_bot[i]		= qu_S21_FWTM_bot[0];
		y05_S21_FWTM_bot[i]		= qu_S21_FWTM_bot[1];
		y95_S21_FWTM_bot[i]		= qu_S21_FWTM_bot[2];
		y98_S21_FWTM_bot[i]		= qu_S21_FWTM_bot[3];
		yF_S21_FWTM_bot[i]		= ymean_S21_FWTM_bot;
		yF02_S21_FWTM_bot[i]	= quF_S21_FWTM_bot[0];
		yF05_S21_FWTM_bot[i]	= quF_S21_FWTM_bot[1];
		yF95_S21_FWTM_bot[i]	= quF_S21_FWTM_bot[2];
		yF98_S21_FWTM_bot[i]	= quF_S21_FWTM_bot[3];

		OutFile_S20_FWHM_top	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S20_FWHM_top[i] 		<<" "
								<< y02_S20_FWHM_top[i] 		<<" "
								<< y05_S20_FWHM_top[i] 		<<" "
								<< y95_S20_FWHM_top[i] 		<<" "
								<< y98_S20_FWHM_top[i] 		<<" "
								<< yF_S20_FWHM_top[i] 		<<" "
								<< yF02_S20_FWHM_top[i] 	<<" "
								<< yF05_S20_FWHM_top[i] 	<<" "
								<< yF95_S20_FWHM_top[i] 	<<" "
								<< yF98_S20_FWHM_top[i] 	<<" "
								<< endl;

		OutFile_S20_FWHM_bot	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S20_FWHM_bot[i] 		<<" "
								<< y02_S20_FWHM_bot[i] 		<<" "
								<< y05_S20_FWHM_bot[i] 		<<" "
								<< y95_S20_FWHM_bot[i] 		<<" "
								<< y98_S20_FWHM_bot[i] 		<<" "
								<< yF_S20_FWHM_bot[i] 		<<" "
								<< yF02_S20_FWHM_bot[i] 	<<" "
								<< yF05_S20_FWHM_bot[i] 	<<" "
								<< yF95_S20_FWHM_bot[i] 	<<" "
								<< yF98_S20_FWHM_bot[i] 	<<" "
								<< endl;

		OutFile_S20_FWTM_top	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S20_FWTM_top[i] 		<<" "
								<< y02_S20_FWTM_top[i] 		<<" "
								<< y05_S20_FWTM_top[i] 		<<" "
								<< y95_S20_FWTM_top[i] 		<<" "
								<< y98_S20_FWTM_top[i] 		<<" "
								<< yF_S20_FWTM_top[i] 		<<" "
								<< yF02_S20_FWTM_top[i] 	<<" "
								<< yF05_S20_FWTM_top[i] 	<<" "
								<< yF95_S20_FWTM_top[i] 	<<" "
								<< yF98_S20_FWTM_top[i] 	<<" "
								<< endl;

		OutFile_S20_FWTM_bot	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S20_FWTM_bot[i] 		<<" "
								<< y02_S20_FWTM_bot[i] 		<<" "
								<< y05_S20_FWTM_bot[i] 		<<" "
								<< y95_S20_FWTM_bot[i] 		<<" "
								<< y98_S20_FWTM_bot[i] 		<<" "
								<< yF_S20_FWTM_bot[i] 		<<" "
								<< yF02_S20_FWTM_bot[i] 	<<" "
								<< yF05_S20_FWTM_bot[i] 	<<" "
								<< yF95_S20_FWTM_bot[i] 	<<" "
								<< yF98_S20_FWTM_bot[i] 	<<" "
								<< endl;


		OutFile_S21_FWHM_top	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S21_FWHM_top[i] 		<<" "
								<< y02_S21_FWHM_top[i] 		<<" "
								<< y05_S21_FWHM_top[i] 		<<" "
								<< y95_S21_FWHM_top[i] 		<<" "
								<< y98_S21_FWHM_top[i] 		<<" "
								<< yF_S21_FWHM_top[i] 		<<" "
								<< yF02_S21_FWHM_top[i] 	<<" "
								<< yF05_S21_FWHM_top[i] 	<<" "
								<< yF95_S21_FWHM_top[i] 	<<" "
								<< yF98_S21_FWHM_top[i] 	<<" "
								<< endl;

		OutFile_S21_FWHM_bot	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S21_FWHM_bot[i] 		<<" "
								<< y02_S21_FWHM_bot[i] 		<<" "
								<< y05_S21_FWHM_bot[i] 		<<" "
								<< y95_S21_FWHM_bot[i] 		<<" "
								<< y98_S21_FWHM_bot[i] 		<<" "
								<< yF_S21_FWHM_bot[i] 		<<" "
								<< yF02_S21_FWHM_bot[i] 	<<" "
								<< yF05_S21_FWHM_bot[i] 	<<" "
								<< yF95_S21_FWHM_bot[i] 	<<" "
								<< yF98_S21_FWHM_bot[i] 	<<" "
								<< endl;

		OutFile_S21_FWTM_top	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S21_FWTM_top[i] 		<<" "
								<< y02_S21_FWTM_top[i] 		<<" "
								<< y05_S21_FWTM_top[i] 		<<" "
								<< y95_S21_FWTM_top[i] 		<<" "
								<< y98_S21_FWTM_top[i] 		<<" "
								<< yF_S21_FWTM_top[i] 		<<" "
								<< yF02_S21_FWTM_top[i] 	<<" "
								<< yF05_S21_FWTM_top[i] 	<<" "
								<< yF95_S21_FWTM_top[i] 	<<" "
								<< yF98_S21_FWTM_top[i] 	<<" "
								<< endl;

		OutFile_S21_FWTM_bot	<< xmean					<<" "
								<< xinterval				<<" "
								<< y_S21_FWTM_bot[i] 		<<" "
								<< y02_S21_FWTM_bot[i] 		<<" "
								<< y05_S21_FWTM_bot[i] 		<<" "
								<< y95_S21_FWTM_bot[i] 		<<" "
								<< y98_S21_FWTM_bot[i] 		<<" "
								<< yF_S21_FWTM_bot[i] 		<<" "
								<< yF02_S21_FWTM_bot[i] 	<<" "
								<< yF05_S21_FWTM_bot[i] 	<<" "
								<< yF95_S21_FWTM_bot[i] 	<<" "
								<< yF98_S21_FWTM_bot[i] 	<<" "
								<< endl;

		sprintf(Sname_S20_FWHM_top, "%s/S20_FWHM_top_Slice_%d.png", outFolder_S20_FWHM_top, i+1);
		c_S20_FWHM_top->SaveAs(Sname_S20_FWHM_top);
		//sprintf(SnameC_S20_FWHM_top, "%s/S20_FWHM_top_Slice_%d.C", outFolder_S20_FWHM_top, i+1);
		//c_S20_FWHM_top->SaveAs(SnameC_S20_FWHM_top);

		sprintf(Sname_S20_FWHM_bot, "%s/S20_FWHM_bot_Slice_%d.png", outFolder_S20_FWHM_bot, i+1);
		c_S20_FWHM_bot->SaveAs(Sname_S20_FWHM_bot);

		sprintf(Sname_S20_FWTM_top, "%s/S20_FWTM_top_Slice_%d.png", outFolder_S20_FWTM_top, i+1);
		c_S20_FWTM_top->SaveAs(Sname_S20_FWTM_top);

		sprintf(Sname_S20_FWTM_bot, "%s/S20_FWTM_bot_Slice_%d.png", outFolder_S20_FWTM_bot, i+1);
		c_S20_FWTM_bot->SaveAs(Sname_S20_FWTM_bot);


		char Sname_S21_FWHM_top[500];
		sprintf(Sname_S21_FWHM_top, "%s/S21_FWHM_top_Slice_%d.png", outFolder_S21_FWHM_top, i+1);
		c_S21_FWHM_top->SaveAs(Sname_S21_FWHM_top);

		char Sname_S21_FWHM_bot[500];
		sprintf(Sname_S21_FWHM_bot, "%s/S21_FWHM_bot_Slice_%d.png", outFolder_S21_FWHM_bot, i+1);
		c_S21_FWHM_bot->SaveAs(Sname_S21_FWHM_bot);

		char Sname_S21_FWTM_top[500];
		sprintf(Sname_S21_FWTM_top, "%s/S21_FWTM_top_Slice_%d.png", outFolder_S21_FWTM_top, i+1);
		c_S21_FWTM_top->SaveAs(Sname_S21_FWTM_top);

		char Sname_S21_FWTM_bot[500];
		sprintf(Sname_S21_FWTM_bot, "%s/S21_FWTM_bot_Slice_%d.png", outFolder_S21_FWTM_bot, i+1);
		c_S21_FWTM_bot->SaveAs(Sname_S21_FWTM_bot);
	

		h1_S20_FWHM_top		->Reset();
		h1_S20_FWHM_bot		->Reset();
		h1_S20_FWTM_top		->Reset();
		h1_S20_FWTM_bot		->Reset();

		h1_S21_FWHM_top		->Reset();
		h1_S21_FWHM_bot		->Reset();
		h1_S21_FWTM_top		->Reset();
		h1_S21_FWTM_bot		->Reset();

	}

	OutFile_S20_FWHM_top.close();
	OutFile_S20_FWHM_bot.close();
	OutFile_S20_FWTM_top.close();
	OutFile_S20_FWTM_bot.close();

	OutFile_S21_FWHM_top.close();
	OutFile_S21_FWHM_bot.close();
	OutFile_S21_FWTM_top.close();
	OutFile_S21_FWTM_bot.close();
	
	int mStyleGr 	= 8;
	int mStyleGrF 	= 22;
	int mColorGr 	= 1;
	int mColorGrF 	= 6;
	double mSizeGr	= 0.6;
	double mSizeGrF = 0.8;
	

	TGraph *gr_S20_FWHM_top = new TGraph(nSlices, x, y_S20_FWHM_top);
			gr_S20_FWHM_top->SetMarkerStyle(mStyleGr);
			gr_S20_FWHM_top->SetMarkerSize(mSizeGr);
			gr_S20_FWHM_top->SetMarkerColor(mColorGr);
			gr_S20_FWHM_top->SetLineColor(mColorGr);
			gr_S20_FWHM_top->SetLineWidth(1);
	TGraph *gr02_S20_FWHM_top = new TGraph(nSlices, x, y02_S20_FWHM_top);
			gr02_S20_FWHM_top->SetMarkerStyle(mStyleGr);
			gr02_S20_FWHM_top->SetMarkerSize(mSizeGr);
			gr02_S20_FWHM_top->SetMarkerColor(mColorGr);
			gr02_S20_FWHM_top->SetLineColor(mColorGr);
			gr02_S20_FWHM_top->SetLineWidth(1);
	TGraph *gr05_S20_FWHM_top = new TGraph(nSlices, x, y05_S20_FWHM_top);
			gr05_S20_FWHM_top->SetMarkerStyle(mStyleGr);
			gr05_S20_FWHM_top->SetMarkerSize(mSizeGr);
			gr05_S20_FWHM_top->SetMarkerColor(mColorGr);
			gr05_S20_FWHM_top->SetLineColor(mColorGr);
			gr05_S20_FWHM_top->SetLineWidth(1);
	TGraph *gr95_S20_FWHM_top = new TGraph(nSlices, x, y95_S20_FWHM_top);
			gr95_S20_FWHM_top->SetMarkerStyle(mStyleGr);
			gr95_S20_FWHM_top->SetMarkerSize(mSizeGr);
			gr95_S20_FWHM_top->SetMarkerColor(mColorGr);
			gr95_S20_FWHM_top->SetLineColor(mColorGr);
			gr95_S20_FWHM_top->SetLineWidth(1);
	TGraph *gr98_S20_FWHM_top = new TGraph(nSlices, x, y98_S20_FWHM_top);
			gr98_S20_FWHM_top->SetMarkerStyle(mStyleGr);
			gr98_S20_FWHM_top->SetMarkerSize(mSizeGr);
			gr98_S20_FWHM_top->SetMarkerColor(mColorGr);
			gr98_S20_FWHM_top->SetLineColor(mColorGr);
			gr98_S20_FWHM_top->SetLineWidth(1);

	TGraph *grF_S20_FWHM_top = new TGraph(nSlices, x, yF_S20_FWHM_top);
			grF_S20_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF_S20_FWHM_top->SetMarkerSize(mSizeGrF);
			grF_S20_FWHM_top->SetMarkerColor(mColorGrF);
			grF_S20_FWHM_top->SetLineColor(mColorGrF);
			grF_S20_FWHM_top->SetLineWidth(1);
	TGraph *grF02_S20_FWHM_top = new TGraph(nSlices, x, yF02_S20_FWHM_top);
			grF02_S20_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF02_S20_FWHM_top->SetMarkerSize(mSizeGrF);
			grF02_S20_FWHM_top->SetMarkerColor(mColorGrF);
			grF02_S20_FWHM_top->SetLineColor(mColorGrF);
			grF02_S20_FWHM_top->SetLineWidth(1);
	TGraph *grF05_S20_FWHM_top = new TGraph(nSlices, x, yF05_S20_FWHM_top);
			grF05_S20_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF05_S20_FWHM_top->SetMarkerSize(mSizeGrF);
			grF05_S20_FWHM_top->SetMarkerColor(mColorGrF);
			grF05_S20_FWHM_top->SetLineColor(mColorGrF);
			grF05_S20_FWHM_top->SetLineWidth(1);
	TGraph *grF95_S20_FWHM_top = new TGraph(nSlices, x, yF95_S20_FWHM_top);
			grF95_S20_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF95_S20_FWHM_top->SetMarkerSize(mSizeGrF);
			grF95_S20_FWHM_top->SetMarkerColor(mColorGrF);
			grF95_S20_FWHM_top->SetLineColor(mColorGrF);
			grF95_S20_FWHM_top->SetLineWidth(1);
	TGraph *grF98_S20_FWHM_top = new TGraph(nSlices, x, yF98_S20_FWHM_top);
			grF98_S20_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF98_S20_FWHM_top->SetMarkerSize(mSizeGrF);
			grF98_S20_FWHM_top->SetMarkerColor(mColorGrF);
			grF98_S20_FWHM_top->SetLineColor(mColorGrF);
			grF98_S20_FWHM_top->SetLineWidth(1);


	TGraph *gr_S20_FWHM_bot = new TGraph(nSlices, x, y_S20_FWHM_bot);
			gr_S20_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr_S20_FWHM_bot->SetMarkerSize(mSizeGr);
			gr_S20_FWHM_bot->SetMarkerColor(mColorGr);
			gr_S20_FWHM_bot->SetLineColor(mColorGr);
			gr_S20_FWHM_bot->SetLineWidth(1);
	TGraph *gr02_S20_FWHM_bot = new TGraph(nSlices, x, y02_S20_FWHM_bot);
			gr02_S20_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr02_S20_FWHM_bot->SetMarkerSize(mSizeGr);
			gr02_S20_FWHM_bot->SetMarkerColor(mColorGr);
			gr02_S20_FWHM_bot->SetLineColor(mColorGr);
			gr02_S20_FWHM_bot->SetLineWidth(1);
	TGraph *gr05_S20_FWHM_bot = new TGraph(nSlices, x, y05_S20_FWHM_bot);
			gr05_S20_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr05_S20_FWHM_bot->SetMarkerSize(mSizeGr);
			gr05_S20_FWHM_bot->SetMarkerColor(mColorGr);
			gr05_S20_FWHM_bot->SetLineColor(mColorGr);
			gr05_S20_FWHM_bot->SetLineWidth(1);
	TGraph *gr95_S20_FWHM_bot = new TGraph(nSlices, x, y95_S20_FWHM_bot);
			gr95_S20_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr95_S20_FWHM_bot->SetMarkerSize(mSizeGr);
			gr95_S20_FWHM_bot->SetMarkerColor(mColorGr);
			gr95_S20_FWHM_bot->SetLineColor(mColorGr);
			gr95_S20_FWHM_bot->SetLineWidth(1);
	TGraph *gr98_S20_FWHM_bot = new TGraph(nSlices, x, y98_S20_FWHM_bot);
			gr98_S20_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr98_S20_FWHM_bot->SetMarkerSize(mSizeGr);
			gr98_S20_FWHM_bot->SetMarkerColor(mColorGr);
			gr98_S20_FWHM_bot->SetLineColor(mColorGr);
			gr98_S20_FWHM_bot->SetLineWidth(1);

	TGraph *grF_S20_FWHM_bot = new TGraph(nSlices, x, yF_S20_FWHM_bot);
			grF_S20_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF_S20_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF_S20_FWHM_bot->SetMarkerColor(mColorGrF);
			grF_S20_FWHM_bot->SetLineColor(mColorGrF);
			grF_S20_FWHM_bot->SetLineWidth(1);
	TGraph *grF02_S20_FWHM_bot = new TGraph(nSlices, x, yF02_S20_FWHM_bot);
			grF02_S20_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF02_S20_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF02_S20_FWHM_bot->SetMarkerColor(mColorGrF);
			grF02_S20_FWHM_bot->SetLineColor(mColorGrF);
			grF02_S20_FWHM_bot->SetLineWidth(1);
	TGraph *grF05_S20_FWHM_bot = new TGraph(nSlices, x, yF05_S20_FWHM_bot);
			grF05_S20_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF05_S20_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF05_S20_FWHM_bot->SetMarkerColor(mColorGrF);
			grF05_S20_FWHM_bot->SetLineColor(mColorGrF);
			grF05_S20_FWHM_bot->SetLineWidth(1);
	TGraph *grF95_S20_FWHM_bot = new TGraph(nSlices, x, yF95_S20_FWHM_bot);
			grF95_S20_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF95_S20_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF95_S20_FWHM_bot->SetMarkerColor(mColorGrF);
			grF95_S20_FWHM_bot->SetLineColor(mColorGrF);
			grF95_S20_FWHM_bot->SetLineWidth(1);
	TGraph *grF98_S20_FWHM_bot = new TGraph(nSlices, x, yF98_S20_FWHM_bot);
			grF98_S20_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF98_S20_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF98_S20_FWHM_bot->SetMarkerColor(mColorGrF);
			grF98_S20_FWHM_bot->SetLineColor(mColorGrF);
			grF98_S20_FWHM_bot->SetLineWidth(1);


	TGraph *gr_S20_FWTM_top = new TGraph(nSlices, x, y_S20_FWTM_top);
			gr_S20_FWTM_top->SetMarkerStyle(mStyleGr);
			gr_S20_FWTM_top->SetMarkerSize(mSizeGr);
			gr_S20_FWTM_top->SetMarkerColor(mColorGr);
			gr_S20_FWTM_top->SetLineColor(mColorGr);
			gr_S20_FWTM_top->SetLineWidth(1);
	TGraph *gr02_S20_FWTM_top = new TGraph(nSlices, x, y02_S20_FWTM_top);
			gr02_S20_FWTM_top->SetMarkerStyle(mStyleGr);
			gr02_S20_FWTM_top->SetMarkerSize(mSizeGr);
			gr02_S20_FWTM_top->SetMarkerColor(mColorGr);
			gr02_S20_FWTM_top->SetLineColor(mColorGr);
			gr02_S20_FWTM_top->SetLineWidth(1);
	TGraph *gr05_S20_FWTM_top = new TGraph(nSlices, x, y05_S20_FWTM_top);
			gr05_S20_FWTM_top->SetMarkerStyle(mStyleGr);
			gr05_S20_FWTM_top->SetMarkerSize(mSizeGr);
			gr05_S20_FWTM_top->SetMarkerColor(mColorGr);
			gr05_S20_FWTM_top->SetLineColor(mColorGr);
			gr05_S20_FWTM_top->SetLineWidth(1);
	TGraph *gr95_S20_FWTM_top = new TGraph(nSlices, x, y95_S20_FWTM_top);
			gr95_S20_FWTM_top->SetMarkerStyle(mStyleGr);
			gr95_S20_FWTM_top->SetMarkerSize(mSizeGr);
			gr95_S20_FWTM_top->SetMarkerColor(mColorGr);
			gr95_S20_FWTM_top->SetLineColor(mColorGr);
			gr95_S20_FWTM_top->SetLineWidth(1);
	TGraph *gr98_S20_FWTM_top = new TGraph(nSlices, x, y98_S20_FWTM_top);
			gr98_S20_FWTM_top->SetMarkerStyle(mStyleGr);
			gr98_S20_FWTM_top->SetMarkerSize(mSizeGr);
			gr98_S20_FWTM_top->SetMarkerColor(mColorGr);
			gr98_S20_FWTM_top->SetLineColor(mColorGr);
			gr98_S20_FWTM_top->SetLineWidth(1);

	TGraph *grF_S20_FWTM_top = new TGraph(nSlices, x, yF_S20_FWTM_top);
			grF_S20_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF_S20_FWTM_top->SetMarkerSize(mSizeGrF);
			grF_S20_FWTM_top->SetMarkerColor(mColorGrF);
			grF_S20_FWTM_top->SetLineColor(mColorGrF);
			grF_S20_FWTM_top->SetLineWidth(1);
	TGraph *grF02_S20_FWTM_top = new TGraph(nSlices, x, yF02_S20_FWTM_top);
			grF02_S20_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF02_S20_FWTM_top->SetMarkerSize(mSizeGrF);
			grF02_S20_FWTM_top->SetMarkerColor(mColorGrF);
			grF02_S20_FWTM_top->SetLineColor(mColorGrF);
			grF02_S20_FWTM_top->SetLineWidth(1);
	TGraph *grF05_S20_FWTM_top = new TGraph(nSlices, x, yF05_S20_FWTM_top);
			grF05_S20_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF05_S20_FWTM_top->SetMarkerSize(mSizeGrF);
			grF05_S20_FWTM_top->SetMarkerColor(mColorGrF);
			grF05_S20_FWTM_top->SetLineColor(mColorGrF);
			grF05_S20_FWTM_top->SetLineWidth(1);
	TGraph *grF95_S20_FWTM_top = new TGraph(nSlices, x, yF95_S20_FWTM_top);
			grF95_S20_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF95_S20_FWTM_top->SetMarkerSize(mSizeGrF);
			grF95_S20_FWTM_top->SetMarkerColor(mColorGrF);
			grF95_S20_FWTM_top->SetLineColor(mColorGrF);
			grF95_S20_FWTM_top->SetLineWidth(1);
	TGraph *grF98_S20_FWTM_top = new TGraph(nSlices, x, yF98_S20_FWTM_top);
			grF98_S20_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF98_S20_FWTM_top->SetMarkerSize(mSizeGrF);
			grF98_S20_FWTM_top->SetMarkerColor(mColorGrF);
			grF98_S20_FWTM_top->SetLineColor(mColorGrF);
			grF98_S20_FWTM_top->SetLineWidth(1);


	TGraph *gr_S20_FWTM_bot = new TGraph(nSlices, x, y_S20_FWTM_bot);
			gr_S20_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr_S20_FWTM_bot->SetMarkerSize(mSizeGr);
			gr_S20_FWTM_bot->SetMarkerColor(mColorGr);
			gr_S20_FWTM_bot->SetLineColor(mColorGr);
			gr_S20_FWTM_bot->SetLineWidth(1);
	TGraph *gr02_S20_FWTM_bot = new TGraph(nSlices, x, y02_S20_FWTM_bot);
			gr02_S20_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr02_S20_FWTM_bot->SetMarkerSize(mSizeGr);
			gr02_S20_FWTM_bot->SetMarkerColor(mColorGr);
			gr02_S20_FWTM_bot->SetLineColor(mColorGr);
			gr02_S20_FWTM_bot->SetLineWidth(1);
	TGraph *gr05_S20_FWTM_bot = new TGraph(nSlices, x, y05_S20_FWTM_bot);
			gr05_S20_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr05_S20_FWTM_bot->SetMarkerSize(mSizeGr);
			gr05_S20_FWTM_bot->SetMarkerColor(mColorGr);
			gr05_S20_FWTM_bot->SetLineColor(mColorGr);
			gr05_S20_FWTM_bot->SetLineWidth(1);
	TGraph *gr95_S20_FWTM_bot = new TGraph(nSlices, x, y95_S20_FWTM_bot);
			gr95_S20_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr95_S20_FWTM_bot->SetMarkerSize(mSizeGr);
			gr95_S20_FWTM_bot->SetMarkerColor(mColorGr);
			gr95_S20_FWTM_bot->SetLineColor(mColorGr);
			gr95_S20_FWTM_bot->SetLineWidth(1);
	TGraph *gr98_S20_FWTM_bot = new TGraph(nSlices, x, y98_S20_FWTM_bot);
			gr98_S20_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr98_S20_FWTM_bot->SetMarkerSize(mSizeGr);
			gr98_S20_FWTM_bot->SetMarkerColor(mColorGr);
			gr98_S20_FWTM_bot->SetLineColor(mColorGr);
			gr98_S20_FWTM_bot->SetLineWidth(1);

	TGraph *grF_S20_FWTM_bot = new TGraph(nSlices, x, yF_S20_FWTM_bot);
			grF_S20_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF_S20_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF_S20_FWTM_bot->SetMarkerColor(mColorGrF);
			grF_S20_FWTM_bot->SetLineColor(mColorGrF);
			grF_S20_FWTM_bot->SetLineWidth(1);
	TGraph *grF02_S20_FWTM_bot = new TGraph(nSlices, x, yF02_S20_FWTM_bot);
			grF02_S20_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF02_S20_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF02_S20_FWTM_bot->SetMarkerColor(mColorGrF);
			grF02_S20_FWTM_bot->SetLineColor(mColorGrF);
			grF02_S20_FWTM_bot->SetLineWidth(1);
	TGraph *grF05_S20_FWTM_bot = new TGraph(nSlices, x, yF05_S20_FWTM_bot);
			grF05_S20_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF05_S20_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF05_S20_FWTM_bot->SetMarkerColor(mColorGrF);
			grF05_S20_FWTM_bot->SetLineColor(mColorGrF);
			grF05_S20_FWTM_bot->SetLineWidth(1);
	TGraph *grF95_S20_FWTM_bot = new TGraph(nSlices, x, yF95_S20_FWTM_bot);
			grF95_S20_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF95_S20_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF95_S20_FWTM_bot->SetMarkerColor(mColorGrF);
			grF95_S20_FWTM_bot->SetLineColor(mColorGrF);
			grF95_S20_FWTM_bot->SetLineWidth(1);
	TGraph *grF98_S20_FWTM_bot = new TGraph(nSlices, x, yF98_S20_FWTM_bot);
			grF98_S20_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF98_S20_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF98_S20_FWTM_bot->SetMarkerColor(mColorGrF);
			grF98_S20_FWTM_bot->SetLineColor(mColorGrF);
			grF98_S20_FWTM_bot->SetLineWidth(1);




	TGraph *gr_S21_FWHM_top = new TGraph(nSlices, x, y_S21_FWHM_top);
			gr_S21_FWHM_top->SetMarkerStyle(mStyleGr);
			gr_S21_FWHM_top->SetMarkerSize(mSizeGr);
			gr_S21_FWHM_top->SetMarkerColor(mColorGr);
			gr_S21_FWHM_top->SetLineColor(mColorGr);
			gr_S21_FWHM_top->SetLineWidth(1);
	TGraph *gr02_S21_FWHM_top = new TGraph(nSlices, x, y02_S21_FWHM_top);
			gr02_S21_FWHM_top->SetMarkerStyle(mStyleGr);
			gr02_S21_FWHM_top->SetMarkerSize(mSizeGr);
			gr02_S21_FWHM_top->SetMarkerColor(mColorGr);
			gr02_S21_FWHM_top->SetLineColor(mColorGr);
			gr02_S21_FWHM_top->SetLineWidth(1);
	TGraph *gr05_S21_FWHM_top = new TGraph(nSlices, x, y05_S21_FWHM_top);
			gr05_S21_FWHM_top->SetMarkerStyle(mStyleGr);
			gr05_S21_FWHM_top->SetMarkerSize(mSizeGr);
			gr05_S21_FWHM_top->SetMarkerColor(mColorGr);
			gr05_S21_FWHM_top->SetLineColor(mColorGr);
			gr05_S21_FWHM_top->SetLineWidth(1);
	TGraph *gr95_S21_FWHM_top = new TGraph(nSlices, x, y95_S21_FWHM_top);
			gr95_S21_FWHM_top->SetMarkerStyle(mStyleGr);
			gr95_S21_FWHM_top->SetMarkerSize(mSizeGr);
			gr95_S21_FWHM_top->SetMarkerColor(mColorGr);
			gr95_S21_FWHM_top->SetLineColor(mColorGr);
			gr95_S21_FWHM_top->SetLineWidth(1);
	TGraph *gr98_S21_FWHM_top = new TGraph(nSlices, x, y98_S21_FWHM_top);
			gr98_S21_FWHM_top->SetMarkerStyle(mStyleGr);
			gr98_S21_FWHM_top->SetMarkerSize(mSizeGr);
			gr98_S21_FWHM_top->SetMarkerColor(mColorGr);
			gr98_S21_FWHM_top->SetLineColor(mColorGr);
			gr98_S21_FWHM_top->SetLineWidth(1);

	TGraph *grF_S21_FWHM_top = new TGraph(nSlices, x, yF_S21_FWHM_top);
			grF_S21_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF_S21_FWHM_top->SetMarkerSize(mSizeGr);
			grF_S21_FWHM_top->SetMarkerColor(mColorGr);
			grF_S21_FWHM_top->SetLineColor(mColorGr);
			grF_S21_FWHM_top->SetLineWidth(1);
	TGraph *grF02_S21_FWHM_top = new TGraph(nSlices, x, yF02_S21_FWHM_top);
			grF02_S21_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF02_S21_FWHM_top->SetMarkerSize(mSizeGrF);
			grF02_S21_FWHM_top->SetMarkerColor(mColorGrF);
			grF02_S21_FWHM_top->SetLineColor(mColorGrF);
			grF02_S21_FWHM_top->SetLineWidth(1);
	TGraph *grF05_S21_FWHM_top = new TGraph(nSlices, x, yF05_S21_FWHM_top);
			grF05_S21_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF05_S21_FWHM_top->SetMarkerSize(mSizeGrF);
			grF05_S21_FWHM_top->SetMarkerColor(mColorGrF);
			grF05_S21_FWHM_top->SetLineColor(mColorGrF);
			grF05_S21_FWHM_top->SetLineWidth(1);
	TGraph *grF95_S21_FWHM_top = new TGraph(nSlices, x, yF95_S21_FWHM_top);
			grF95_S21_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF95_S21_FWHM_top->SetMarkerSize(mSizeGrF);
			grF95_S21_FWHM_top->SetMarkerColor(mColorGrF);
			grF95_S21_FWHM_top->SetLineColor(mColorGrF);
			grF95_S21_FWHM_top->SetLineWidth(1);
	TGraph *grF98_S21_FWHM_top = new TGraph(nSlices, x, yF98_S21_FWHM_top);
			grF98_S21_FWHM_top->SetMarkerStyle(mStyleGrF);
			grF98_S21_FWHM_top->SetMarkerSize(mSizeGrF);
			grF98_S21_FWHM_top->SetMarkerColor(mColorGrF);
			grF98_S21_FWHM_top->SetLineColor(mColorGrF);
			grF98_S21_FWHM_top->SetLineWidth(1);


	TGraph *gr_S21_FWHM_bot = new TGraph(nSlices, x, y_S21_FWHM_bot);
			gr_S21_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr_S21_FWHM_bot->SetMarkerSize(mSizeGr);
			gr_S21_FWHM_bot->SetMarkerColor(mColorGr);
			gr_S21_FWHM_bot->SetLineColor(mColorGr);
			gr_S21_FWHM_bot->SetLineWidth(1);
	TGraph *gr02_S21_FWHM_bot = new TGraph(nSlices, x, y02_S21_FWHM_bot);
			gr02_S21_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr02_S21_FWHM_bot->SetMarkerSize(mSizeGr);
			gr02_S21_FWHM_bot->SetMarkerColor(mColorGr);
			gr02_S21_FWHM_bot->SetLineColor(mColorGr);
			gr02_S21_FWHM_bot->SetLineWidth(1);
	TGraph *gr05_S21_FWHM_bot = new TGraph(nSlices, x, y05_S21_FWHM_bot);
			gr05_S21_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr05_S21_FWHM_bot->SetMarkerSize(mSizeGr);
			gr05_S21_FWHM_bot->SetMarkerColor(mColorGr);
			gr05_S21_FWHM_bot->SetLineColor(mColorGr);
			gr05_S21_FWHM_bot->SetLineWidth(1);
	TGraph *gr95_S21_FWHM_bot = new TGraph(nSlices, x, y95_S21_FWHM_bot);
			gr95_S21_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr95_S21_FWHM_bot->SetMarkerSize(mSizeGr);
			gr95_S21_FWHM_bot->SetMarkerColor(mColorGr);
			gr95_S21_FWHM_bot->SetLineColor(mColorGr);
			gr95_S21_FWHM_bot->SetLineWidth(1);
	TGraph *gr98_S21_FWHM_bot = new TGraph(nSlices, x, y98_S21_FWHM_bot);
			gr98_S21_FWHM_bot->SetMarkerStyle(mStyleGr);
			gr98_S21_FWHM_bot->SetMarkerSize(mSizeGr);
			gr98_S21_FWHM_bot->SetMarkerColor(mColorGr);
			gr98_S21_FWHM_bot->SetLineColor(mColorGr);
			gr98_S21_FWHM_bot->SetLineWidth(1);

	TGraph *grF_S21_FWHM_bot = new TGraph(nSlices, x, yF_S21_FWHM_bot);
			grF_S21_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF_S21_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF_S21_FWHM_bot->SetMarkerColor(mColorGrF);
			grF_S21_FWHM_bot->SetLineColor(mColorGrF);
			grF_S21_FWHM_bot->SetLineWidth(1);
	TGraph *grF02_S21_FWHM_bot = new TGraph(nSlices, x, yF02_S21_FWHM_bot);
			grF02_S21_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF02_S21_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF02_S21_FWHM_bot->SetMarkerColor(mColorGrF);
			grF02_S21_FWHM_bot->SetLineColor(mColorGrF);
			grF02_S21_FWHM_bot->SetLineWidth(1);
	TGraph *grF05_S21_FWHM_bot = new TGraph(nSlices, x, yF05_S21_FWHM_bot);
			grF05_S21_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF05_S21_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF05_S21_FWHM_bot->SetMarkerColor(mColorGrF);
			grF05_S21_FWHM_bot->SetLineColor(mColorGrF);
			grF05_S21_FWHM_bot->SetLineWidth(1);
	TGraph *grF95_S21_FWHM_bot = new TGraph(nSlices, x, yF95_S21_FWHM_bot);
			grF95_S21_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF95_S21_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF95_S21_FWHM_bot->SetMarkerColor(mColorGrF);
			grF95_S21_FWHM_bot->SetLineColor(mColorGrF);
			grF95_S21_FWHM_bot->SetLineWidth(1);
	TGraph *grF98_S21_FWHM_bot = new TGraph(nSlices, x, yF98_S21_FWHM_bot);
			grF98_S21_FWHM_bot->SetMarkerStyle(mStyleGrF);
			grF98_S21_FWHM_bot->SetMarkerSize(mSizeGrF);
			grF98_S21_FWHM_bot->SetMarkerColor(mColorGrF);
			grF98_S21_FWHM_bot->SetLineColor(mColorGrF);
			grF98_S21_FWHM_bot->SetLineWidth(1);


	TGraph *gr_S21_FWTM_top = new TGraph(nSlices, x, y_S21_FWTM_top);
			gr_S21_FWTM_top->SetMarkerStyle(mStyleGr);
			gr_S21_FWTM_top->SetMarkerSize(mSizeGr);
			gr_S21_FWTM_top->SetMarkerColor(mColorGr);
			gr_S21_FWTM_top->SetLineColor(mColorGr);
			gr_S21_FWTM_top->SetLineWidth(1);
	TGraph *gr02_S21_FWTM_top = new TGraph(nSlices, x, y02_S21_FWTM_top);
			gr02_S21_FWTM_top->SetMarkerStyle(mStyleGr);
			gr02_S21_FWTM_top->SetMarkerSize(mSizeGr);
			gr02_S21_FWTM_top->SetMarkerColor(mColorGr);
			gr02_S21_FWTM_top->SetLineColor(mColorGr);
			gr02_S21_FWTM_top->SetLineWidth(1);
	TGraph *gr05_S21_FWTM_top = new TGraph(nSlices, x, y05_S21_FWTM_top);
			gr05_S21_FWTM_top->SetMarkerStyle(mStyleGr);
			gr05_S21_FWTM_top->SetMarkerSize(mSizeGr);
			gr05_S21_FWTM_top->SetMarkerColor(mColorGr);
			gr05_S21_FWTM_top->SetLineColor(mColorGr);
			gr05_S21_FWTM_top->SetLineWidth(1);
	TGraph *gr95_S21_FWTM_top = new TGraph(nSlices, x, y95_S21_FWTM_top);
			gr95_S21_FWTM_top->SetMarkerStyle(mStyleGr);
			gr95_S21_FWTM_top->SetMarkerSize(mSizeGr);
			gr95_S21_FWTM_top->SetMarkerColor(mColorGr);
			gr95_S21_FWTM_top->SetLineColor(mColorGr);
			gr95_S21_FWTM_top->SetLineWidth(1);
	TGraph *gr98_S21_FWTM_top = new TGraph(nSlices, x, y98_S21_FWTM_top);
			gr98_S21_FWTM_top->SetMarkerStyle(mStyleGr);
			gr98_S21_FWTM_top->SetMarkerSize(mSizeGr);
			gr98_S21_FWTM_top->SetMarkerColor(mColorGr);
			gr98_S21_FWTM_top->SetLineColor(mColorGr);
			gr98_S21_FWTM_top->SetLineWidth(1);

	TGraph *grF_S21_FWTM_top = new TGraph(nSlices, x, yF_S21_FWTM_top);
			grF_S21_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF_S21_FWTM_top->SetMarkerSize(mSizeGrF);
			grF_S21_FWTM_top->SetMarkerColor(mColorGrF);
			grF_S21_FWTM_top->SetLineColor(mColorGrF);
			grF_S21_FWTM_top->SetLineWidth(1);
	TGraph *grF02_S21_FWTM_top = new TGraph(nSlices, x, yF02_S21_FWTM_top);
			grF02_S21_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF02_S21_FWTM_top->SetMarkerSize(mSizeGrF);
			grF02_S21_FWTM_top->SetMarkerColor(mColorGrF);
			grF02_S21_FWTM_top->SetLineColor(mColorGrF);
			grF02_S21_FWTM_top->SetLineWidth(1);
	TGraph *grF05_S21_FWTM_top = new TGraph(nSlices, x, yF05_S21_FWTM_top);
			grF05_S21_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF05_S21_FWTM_top->SetMarkerSize(mSizeGrF);
			grF05_S21_FWTM_top->SetMarkerColor(mColorGrF);
			grF05_S21_FWTM_top->SetLineColor(mColorGrF);
			grF05_S21_FWTM_top->SetLineWidth(1);
	TGraph *grF95_S21_FWTM_top = new TGraph(nSlices, x, yF95_S21_FWTM_top);
			grF95_S21_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF95_S21_FWTM_top->SetMarkerSize(mSizeGrF);
			grF95_S21_FWTM_top->SetMarkerColor(mColorGrF);
			grF95_S21_FWTM_top->SetLineColor(mColorGrF);
			grF95_S21_FWTM_top->SetLineWidth(1);
	TGraph *grF98_S21_FWTM_top = new TGraph(nSlices, x, yF98_S21_FWTM_top);
			grF98_S21_FWTM_top->SetMarkerStyle(mStyleGrF);
			grF98_S21_FWTM_top->SetMarkerSize(mSizeGrF);
			grF98_S21_FWTM_top->SetMarkerColor(mColorGrF);
			grF98_S21_FWTM_top->SetLineColor(mColorGrF);
			grF98_S21_FWTM_top->SetLineWidth(1);


	TGraph *gr_S21_FWTM_bot = new TGraph(nSlices, x, y_S21_FWTM_bot);
			gr_S21_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr_S21_FWTM_bot->SetMarkerSize(mSizeGr);
			gr_S21_FWTM_bot->SetMarkerColor(mColorGr);
			gr_S21_FWTM_bot->SetLineColor(mColorGr);
			gr_S21_FWTM_bot->SetLineWidth(1);
	TGraph *gr02_S21_FWTM_bot = new TGraph(nSlices, x, y02_S21_FWTM_bot);
			gr02_S21_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr02_S21_FWTM_bot->SetMarkerSize(mSizeGr);
			gr02_S21_FWTM_bot->SetMarkerColor(mColorGr);
			gr02_S21_FWTM_bot->SetLineColor(mColorGr);
			gr02_S21_FWTM_bot->SetLineWidth(1);
	TGraph *gr05_S21_FWTM_bot = new TGraph(nSlices, x, y05_S21_FWTM_bot);
			gr05_S21_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr05_S21_FWTM_bot->SetMarkerSize(mSizeGr);
			gr05_S21_FWTM_bot->SetMarkerColor(mColorGr);
			gr05_S21_FWTM_bot->SetLineColor(mColorGr);
			gr05_S21_FWTM_bot->SetLineWidth(1);
	TGraph *gr95_S21_FWTM_bot = new TGraph(nSlices, x, y95_S21_FWTM_bot);
			gr95_S21_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr95_S21_FWTM_bot->SetMarkerSize(mSizeGr);
			gr95_S21_FWTM_bot->SetMarkerColor(mColorGr);
			gr95_S21_FWTM_bot->SetLineColor(mColorGr);
			gr95_S21_FWTM_bot->SetLineWidth(1);
	TGraph *gr98_S21_FWTM_bot = new TGraph(nSlices, x, y98_S21_FWTM_bot);
			gr98_S21_FWTM_bot->SetMarkerStyle(mStyleGr);
			gr98_S21_FWTM_bot->SetMarkerSize(mSizeGr);
			gr98_S21_FWTM_bot->SetMarkerColor(mColorGr);
			gr98_S21_FWTM_bot->SetLineColor(mColorGr);
			gr98_S21_FWTM_bot->SetLineWidth(1);

	TGraph *grF_S21_FWTM_bot = new TGraph(nSlices, x, yF_S21_FWTM_bot);
			grF_S21_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF_S21_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF_S21_FWTM_bot->SetMarkerColor(mColorGrF);
			grF_S21_FWTM_bot->SetLineColor(mColorGrF);
			grF_S21_FWTM_bot->SetLineWidth(1);
	TGraph *grF02_S21_FWTM_bot = new TGraph(nSlices, x, yF02_S21_FWTM_bot);
			grF02_S21_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF02_S21_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF02_S21_FWTM_bot->SetMarkerColor(mColorGrF);
			grF02_S21_FWTM_bot->SetLineColor(mColorGrF);
			grF02_S21_FWTM_bot->SetLineWidth(1);
	TGraph *grF05_S21_FWTM_bot = new TGraph(nSlices, x, yF05_S21_FWTM_bot);
			grF05_S21_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF05_S21_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF05_S21_FWTM_bot->SetMarkerColor(mColorGrF);
			grF05_S21_FWTM_bot->SetLineColor(mColorGrF);
			grF05_S21_FWTM_bot->SetLineWidth(1);
	TGraph *grF95_S21_FWTM_bot = new TGraph(nSlices, x, yF95_S21_FWTM_bot);
			grF95_S21_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF95_S21_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF95_S21_FWTM_bot->SetMarkerColor(mColorGrF);
			grF95_S21_FWTM_bot->SetLineColor(mColorGr);
			grF95_S21_FWTM_bot->SetLineWidth(1);
	TGraph *grF98_S21_FWTM_bot = new TGraph(nSlices, x, yF98_S21_FWTM_bot);
			grF98_S21_FWTM_bot->SetMarkerStyle(mStyleGrF);
			grF98_S21_FWTM_bot->SetMarkerSize(mSizeGrF);
			grF98_S21_FWTM_bot->SetMarkerColor(mColorGrF);
			grF98_S21_FWTM_bot->SetLineColor(mColorGrF);
			grF98_S21_FWTM_bot->SetLineWidth(1);

	c_S20_FWHMvsDT_top->cd();
		gr_S20_FWHM_top		->Draw("P same");
		gr02_S20_FWHM_top	->Draw("P same");
		gr05_S20_FWHM_top	->Draw("P same");
		gr95_S20_FWHM_top	->Draw("P same");
		gr98_S20_FWHM_top	->Draw("P same");
		grF_S20_FWHM_top	->Draw("P same");
		grF02_S20_FWHM_top	->Draw("P same");
		grF05_S20_FWHM_top	->Draw("P same");
		grF95_S20_FWHM_top	->Draw("P same");
		grF98_S20_FWHM_top	->Draw("P same");
	c_S20_FWHMvsDT_top->Update();

	c_S20_FWHMvsDT_bot->cd();
		gr_S20_FWHM_bot		->Draw("P same");
		gr02_S20_FWHM_bot	->Draw("P same");
		gr05_S20_FWHM_bot	->Draw("P same");
		gr95_S20_FWHM_bot	->Draw("P same");
		gr98_S20_FWHM_bot	->Draw("P same");
		grF_S20_FWHM_bot	->Draw("P same");
		grF02_S20_FWHM_bot	->Draw("P same");
		grF05_S20_FWHM_bot	->Draw("P same");
		grF95_S20_FWHM_bot	->Draw("P same");
		grF98_S20_FWHM_bot	->Draw("P same");
	c_S20_FWHMvsDT_bot->Update();

	c_S20_FWTMvsDT_top->cd();
		gr_S20_FWTM_top		->Draw("P same");
		gr02_S20_FWTM_top	->Draw("P same");
		gr05_S20_FWTM_top	->Draw("P same");
		gr95_S20_FWTM_top	->Draw("P same");
		gr98_S20_FWTM_top	->Draw("P same");
		grF_S20_FWTM_top	->Draw("P same");
		grF02_S20_FWTM_top	->Draw("P same");
		grF05_S20_FWTM_top	->Draw("P same");
		grF95_S20_FWTM_top	->Draw("P same");
		grF98_S20_FWTM_top	->Draw("P same");
	c_S20_FWTMvsDT_top->Update();

	c_S20_FWTMvsDT_bot->cd();
		gr_S20_FWTM_bot		->Draw("P same");
		gr02_S20_FWTM_bot	->Draw("P same");
		gr05_S20_FWTM_bot	->Draw("P same");
		gr95_S20_FWTM_bot	->Draw("P same");
		gr98_S20_FWTM_bot	->Draw("P same");
		grF_S20_FWTM_bot	->Draw("P same");
		grF02_S20_FWTM_bot	->Draw("P same");
		grF05_S20_FWTM_bot	->Draw("P same");
		grF95_S20_FWTM_bot	->Draw("P same");
		grF98_S20_FWTM_bot	->Draw("P same");
	c_S20_FWTMvsDT_bot->Update();


	c_S21_FWHMvsDT_top->cd();
		gr_S21_FWHM_top		->Draw("P same");
		gr02_S21_FWHM_top	->Draw("P same");
		gr05_S21_FWHM_top	->Draw("P same");
		gr95_S21_FWHM_top	->Draw("P same");
		gr98_S21_FWHM_top	->Draw("P same");
		grF_S21_FWHM_top	->Draw("P same");
		grF02_S21_FWHM_top	->Draw("P same");
		grF05_S21_FWHM_top	->Draw("P same");
		grF95_S21_FWHM_top	->Draw("P same");
		grF98_S21_FWHM_top	->Draw("P same");
	c_S21_FWHMvsDT_top->Update();

	c_S21_FWHMvsDT_bot->cd();
		gr_S21_FWHM_bot		->Draw("P same");
		gr02_S21_FWHM_bot	->Draw("P same");
		gr05_S21_FWHM_bot	->Draw("P same");
		gr95_S21_FWHM_bot	->Draw("P same");
		gr98_S21_FWHM_bot	->Draw("P same");
		grF_S21_FWHM_bot	->Draw("P same");
		grF02_S21_FWHM_bot	->Draw("P same");
		grF05_S21_FWHM_bot	->Draw("P same");
		grF95_S21_FWHM_bot	->Draw("P same");
		grF98_S21_FWHM_bot	->Draw("P same");
	c_S21_FWHMvsDT_bot->Update();

	c_S21_FWTMvsDT_top->cd();
		gr_S21_FWTM_top		->Draw("P same");
		gr02_S21_FWTM_top	->Draw("P same");
		gr05_S21_FWTM_top	->Draw("P same");
		gr95_S21_FWTM_top	->Draw("P same");
		gr98_S21_FWTM_top	->Draw("P same");
		grF_S21_FWTM_top	->Draw("P same");
		grF02_S21_FWTM_top	->Draw("P same");
		grF05_S21_FWTM_top	->Draw("P same");
		grF95_S21_FWTM_top	->Draw("P same");
		grF98_S21_FWTM_top	->Draw("P same");
	c_S21_FWTMvsDT_top->Update();

	c_S21_FWTMvsDT_bot->cd();
		gr_S21_FWTM_bot		->Draw("P same");
		gr02_S21_FWTM_bot	->Draw("P same");
		gr05_S21_FWTM_bot	->Draw("P same");
		gr95_S21_FWTM_bot	->Draw("P same");
		gr98_S21_FWTM_bot	->Draw("P same");
		grF_S21_FWTM_bot	->Draw("P same");
		grF02_S21_FWTM_bot	->Draw("P same");
		grF05_S21_FWTM_bot	->Draw("P same");
		grF95_S21_FWTM_bot	->Draw("P same");
		grF98_S21_FWTM_bot	->Draw("P same");
	c_S21_FWTMvsDT_bot->Update();


	char  char_S20_FWHMvsDT_top_withFits[500];
	char  char_S20_FWHMvsDT_bot_withFits[500];
	char  char_S20_FWTMvsDT_top_withFits[500];
	char  char_S20_FWTMvsDT_bot_withFits[500];

	char  char_S21_FWHMvsDT_top_withFits[500];
	char  char_S21_FWHMvsDT_bot_withFits[500];
	char  char_S21_FWTMvsDT_top_withFits[500];
	char  char_S21_FWTMvsDT_bot_withFits[500];

	sprintf(char_S20_FWHMvsDT_top_withFits, "%s/%s_S20_FWHM_top_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 
	sprintf(char_S20_FWHMvsDT_bot_withFits, "%s/%s_S20_FWHM_bot_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 

	sprintf(char_S20_FWTMvsDT_top_withFits, "%s/%s_S20_FWTM_top_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 
	sprintf(char_S20_FWTMvsDT_bot_withFits, "%s/%s_S20_FWTM_bot_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 

	sprintf(char_S21_FWHMvsDT_top_withFits, "%s/%s_S21_FWHM_top_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 
	sprintf(char_S21_FWHMvsDT_bot_withFits, "%s/%s_S21_FWHM_bot_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 

	sprintf(char_S21_FWTMvsDT_top_withFits, "%s/%s_S21_FWTM_top_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 
	sprintf(char_S21_FWTMvsDT_bot_withFits, "%s/%s_S21_FWTM_bot_WithFits%s", outFolder_S2widthDT, DataSet1, extensionPlots); 

	c_S20_FWHMvsDT_top->SaveAs(char_S20_FWHMvsDT_top_withFits);
	c_S20_FWHMvsDT_bot->SaveAs(char_S20_FWHMvsDT_bot_withFits);
	c_S20_FWTMvsDT_top->SaveAs(char_S20_FWTMvsDT_top_withFits);
	c_S20_FWTMvsDT_bot->SaveAs(char_S20_FWTMvsDT_bot_withFits);

	c_S21_FWHMvsDT_top->SaveAs(char_S21_FWHMvsDT_top_withFits);
	c_S21_FWHMvsDT_bot->SaveAs(char_S21_FWHMvsDT_bot_withFits);
	c_S21_FWTMvsDT_top->SaveAs(char_S21_FWTMvsDT_top_withFits);
	c_S21_FWTMvsDT_bot->SaveAs(char_S21_FWTMvsDT_bot_withFits);


