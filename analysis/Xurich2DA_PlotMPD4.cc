/*	int nbins_TOF	= 200;
	double min_TOF	= 0;
	double max_TOF	= 1.6e4;

	int nbins_PSD	= 500;
	double min_PSD	= 0;
	double max_PSD	= 1.6e4;

	int nbins_AMP	= 500;
	double min_AMP	= 0;
	double max_AMP	= 1.6e4;
*/

	// 50deg
	int nbins_TOF		= 200;
	double min_TOF		= 8500;
	double max_TOF		= 10500;

	int nbins_PSD		= 500;
	double min_PSD		= 0;
	double max_PSD		= 3.2e3;

	int nbins_AMP		= 500;
	double min_AMP		= 0;
	double max_AMP		= 3.2e3;

	int nbins_isign		= 50;
	double min_isign	= 0;
	double max_isign	= 50;
	
	int nbinsC = 100; //for coarse binning in 2D plots

	TH2F *h2_isign 		= new TH2F("h2_isign", 			DataSetName1, nbins_isign, min_isign, max_isign,  nbins_isign, min_isign, max_isign);
		  h2_isign		->SetLineColor(2);
		  h2_isign		->SetMarkerColor(2);
	TH1F *h1_isignTAC 	= new TH1F("h1_isignTAC", 		DataSetName1, nbins_TOF, min_TOF, max_TOF);
		  h1_isignTAC	->SetLineColor(4);
	TH1F *h1_TOF 		= new TH1F("h1_TOF", 			DataSetName1, nbins_TOF, min_TOF, max_TOF);
		  h1_TOF		->SetLineColor(2);
	TH1F *h1_AMP 		= new TH1F("h1_AMP", 			DataSetName1, nbins_AMP, min_AMP, max_AMP);
		  h1_AMP		->SetLineColor(2);
	TH1F *h1_PSD 		= new TH1F("h1_PSD", 			DataSetName1, nbins_PSD, min_PSD, max_PSD);
		  h1_PSD		->SetLineColor(2);
	TH1F *h1_TOF_PSDcut = new TH1F("h1_TOF_PSDcut", 	DataSetName1, nbins_TOF, min_TOF, max_TOF);
		  h1_TOF_PSDcut	->SetLineColor(2);
	TH2F *h2_PSDvsTOF 	= new TH2F("h2_PSDvsTOF",		DataSetName1, nbinsC, min_TOF, max_TOF, nbinsC, min_PSD, max_PSD);
		  h2_PSDvsTOF	->SetMarkerStyle(4);
		  h2_PSDvsTOF	->SetMarkerSize(0.6);
		  h2_PSDvsTOF	->SetMarkerColor(2);
	TH2F *h2_PSDvsAMP 	= new TH2F("h2_PSDvsAMP",		DataSetName1, nbinsC, min_AMP, max_AMP, nbinsC, min_PSD, max_PSD);
		  h2_PSDvsAMP	->SetMarkerStyle(4);
		  h2_PSDvsAMP	->SetMarkerSize(0.6);
		  h2_PSDvsAMP	->SetMarkerColor(2);

	int canX = 700;
	int canY = 500;


/*	TCanvas *c_isign = new TCanvas("c_isign", "c_isign", 0, 0, canX, canY);
			 c_isign->SetFillColor(10);
    		 c_isign->SetLogy();
		T1 ->Draw("NsignTAC0:NsignAMP0>>h2_isign",		cut_all,	"");
		//T1 ->Draw("TOF>>h1_TOF_PSDcut",	cut_all && "AMP<8000 && PSD>8000",	"same");
		h2_isign	-> GetXaxis() -> SetTitle("N signals in AMP0");
		h2_isign	-> GetYaxis() -> SetTitle("N signals in TAC0");
		h2_isign	-> GetYaxis() -> SetTitle("Counts");
		h2_isign	-> GetXaxis() -> CenterTitle(true);
		h2_isign	-> GetYaxis() -> CenterTitle(true);
	c_isign->Update();
*/
	TCanvas *c_TOF = new TCanvas("c_TOF", "c_TOF", 0, 0, canX, canY);
			 c_TOF->SetFillColor(10);
    		 c_TOF->SetLogy();
		T1 ->Draw("TOF>>h1_TOF",		cut_all,	"");
		//T1 ->Draw("TOF>>h1_TOF_PSDcut",	cut_all && "AMP<8000 && PSD>8000",	"same");
		h1_TOF	-> GetXaxis() -> SetTitle("TOF [ADC ch.]");
		h1_TOF	-> GetYaxis() -> SetTitle("Counts");
		h1_TOF	-> GetXaxis() -> CenterTitle(true);
		h1_TOF	-> GetYaxis() -> CenterTitle(true);
	c_TOF->Update();
	//cout <<"N coin:          "<< h1_TOF->GetEntries() << endl;
	//cout <<"N coin with PSD: "<< h1_TOF_PSDcut->GetEntries() << endl;

	TCanvas *c_AMP = new TCanvas("c_AMP", "c_AMP", 0, 0, canX, canY);
			 c_AMP->SetFillColor(10);
    		 c_AMP->SetLogy();
		T1 ->Draw("AMP>>h1_AMP",		cut_all,	"");
		h1_AMP	-> GetXaxis() -> SetTitle("AMP [ADC ch.]");
		h1_AMP	-> GetYaxis() -> SetTitle("Counts");
		h1_AMP	-> GetXaxis() -> CenterTitle(true);
		h1_AMP	-> GetYaxis() -> CenterTitle(true);
	c_AMP->Update();

	TCanvas *c_PSD = new TCanvas("c_PSD", "c_PSD", 0, 0, canX, canY);
			 c_PSD->SetFillColor(10);
    		 c_PSD->SetLogy();
		T1 ->Draw("PSD>>h1_PSD",		cut_all,	"");
		h1_PSD	-> GetXaxis() -> SetTitle("PSD [ADC ch.]");
		h1_PSD	-> GetYaxis() -> SetTitle("Counts");
		h1_PSD	-> GetXaxis() -> CenterTitle(true);
		h1_PSD	-> GetYaxis() -> CenterTitle(true);
	c_PSD->Update();


	TCanvas *c_PSDvsTOF = new TCanvas("c_PSDvsTOF", "c_PSDvsTOF", 0, 0, canX, canY);
			 c_PSDvsTOF->SetFillColor(10);
    		 c_PSDvsTOF->SetLogz();
		T1 ->Draw("PSD:TOF>>h2_PSDvsTOF",	cut_all,	"");
		h2_PSDvsTOF	-> GetXaxis() -> SetTitle("TOF [ADC ch.]");
		h2_PSDvsTOF	-> GetYaxis() -> SetTitle("PSD");
		h2_PSDvsTOF	-> GetXaxis() -> CenterTitle(true);
		h2_PSDvsTOF	-> GetYaxis() -> CenterTitle(true);
		h2_PSDvsTOF	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_PSDvsTOF	-> GetYaxis() -> SetTitleOffset(1.25);
	c_PSDvsTOF->Update();

	TCanvas *c_PSDvsAMP = new TCanvas("c_PSDvsAMP", "c_PSDvsAMP", 0, 0, canX, canY);
			 c_PSDvsAMP->SetFillColor(10);
    		 c_PSDvsAMP->SetLogz();
		T1 ->Draw("PSD:AMP>>h2_PSDvsAMP",	cut_all,	"");
		h2_PSDvsAMP	-> GetXaxis() -> SetTitle("AMP [ADC ch.]");
		h2_PSDvsAMP	-> GetYaxis() -> SetTitle("PSD [ADC ch.]");
		h2_PSDvsAMP	-> GetXaxis() -> CenterTitle(true);
		h2_PSDvsAMP	-> GetYaxis() -> CenterTitle(true);
		h2_PSDvsAMP	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_PSDvsAMP	-> GetYaxis() -> SetTitleOffset(1.25);
	c_PSDvsAMP->Update();



	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_MPD4[500];
	sprintf(outFolder_MPD4, "%s/MPD4", outFolder_dataset);
	char mkdir_outFolder_MPD4[500];
	sprintf(mkdir_outFolder_MPD4, ".mkdir %s", outFolder_MPD4);
	gROOT->ProcessLine(mkdir_outFolder_MPD4);

	char char_isign[500];
	char char_TOF[500];
	char char_AMP[500];
	char char_PSD[500];
	char char_PSDvsTOF[500];
	char char_PSDvsAMP[500];

	char char_TOF_C[500];
	char char_AMP_C[500];
	char char_PSD_C[500];
	char char_PSDvsTOF_C[500];
	char char_PSDvsAMP_C[500];

	sprintf(char_isign,			"%s/%s_isign_%s%s",		outFolder_MPD4, DataSet1, CutName, extensionPlots);
	sprintf(char_TOF,			"%s/%s_TOF_%s%s",		outFolder_MPD4, DataSet1, CutName, extensionPlots);
	sprintf(char_AMP,			"%s/%s_AMP_%s%s",		outFolder_MPD4, DataSet1, CutName, extensionPlots);
	sprintf(char_PSD,			"%s/%s_PSD_%s%s",		outFolder_MPD4, DataSet1, CutName, extensionPlots);
	sprintf(char_PSDvsTOF,		"%s/%s_PSDvsTOF_%s%s",	outFolder_MPD4, DataSet1, CutName, extensionPlots);
	sprintf(char_PSDvsAMP,		"%s/%s_PSDvsAMP_%s%s",	outFolder_MPD4, DataSet1, CutName, extensionPlots);

	sprintf(char_TOF_C,			"%s/%s_TOF_%s%s",		outFolder_MPD4, DataSet1, CutName, extensionPlots_C);
	sprintf(char_AMP_C,			"%s/%s_AMP_%s%s",		outFolder_MPD4, DataSet1, CutName, extensionPlots_C);
	sprintf(char_PSD_C,			"%s/%s_PSD_%s%s",		outFolder_MPD4, DataSet1, CutName, extensionPlots_C);
	sprintf(char_PSDvsTOF_C,	"%s/%s_PSDvsTOF_%s%s",	outFolder_MPD4, DataSet1, CutName, extensionPlots_C);
	sprintf(char_PSDvsAMP_C,	"%s/%s_PSDvsAMP_%s%s",	outFolder_MPD4, DataSet1, CutName, extensionPlots_C);

	//c_isign		->SaveAs(char_isign);
	c_TOF		->SaveAs(char_TOF);
	c_AMP		->SaveAs(char_AMP);
	c_PSD		->SaveAs(char_PSD);
	c_PSDvsTOF	->SaveAs(char_PSDvsTOF);
	c_PSDvsAMP	->SaveAs(char_PSDvsAMP);

	c_TOF		->SaveAs(char_TOF_C);
	c_AMP		->SaveAs(char_AMP_C);
	c_PSD		->SaveAs(char_PSD_C);
	c_PSDvsTOF	->SaveAs(char_PSDvsTOF_C);
	c_PSDvsAMP	->SaveAs(char_PSDvsAMP_C);
