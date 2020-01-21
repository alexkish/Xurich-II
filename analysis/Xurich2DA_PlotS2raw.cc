	int nbins_S2raw		= 400;
	double min_S2raw	= 0;
	double max_S2raw	= 5e5;

	TH1F *h1_S2 	= new TH1F("h1_S2",		DataSetName1, nbins_S2raw, min_S2raw, max_S2raw);
	TH1F *h1_S2top 	= new TH1F("h1_S2top",	DataSetName1, nbins_S2raw, min_S2raw, max_S2raw);
	TH1F *h1_S2bot 	= new TH1F("h1_S2bot",	DataSetName1, nbins_S2raw, min_S2raw, max_S2raw);
		  h1_S2		->SetLineColor(1);
		  h1_S2top	->SetLineColor(2);
		  h1_S2bot	->SetLineColor(3);


	// FIT RANGES
/*	// 150522_2009
	double fmin_S2top = 35e3;
	double fmax_S2top = 75e3;
	double fmin_S2bot = 65e3;
	double fmax_S2bot = 110e3;
*/	// 150523_1248
	double fmin_S2top = 50e3;
	double fmax_S2top = 95e3;
	double fmin_S2bot = 85e3;
	double fmax_S2bot = 140e3;
/*	// 150524_1601
	double fmin_S2top = 75e3;
	double fmax_S2top = 135e3;
	double fmin_S2bot = 170e3;
	double fmax_S2bot = 240e3;
	// 150525_1311
	double fmin_S2top = 70e3;
	double fmax_S2top = 120e3;
	double fmin_S2bot = 120e3;
	double fmax_S2bot = 220e3;
	// 150526_0036
	double fmin_S2top = 35e3;
	double fmax_S2top = 75e3;
	double fmin_S2bot = 50e3;
	double fmax_S2bot = 100e3;
	// 150526_1722
	double fmin_S2top = 60e3;
	double fmax_S2top = 110e3;
	double fmin_S2bot = 85e3;
	double fmax_S2bot = 165e3;
	// 150526_2253
	double fmin_S2top = 80e3;
	double fmax_S2top = 135e3;
	double fmin_S2bot = 130e3;
	double fmax_S2bot = 220e3;
*/

	TF1 *f1_S2top = new TF1("f1_S2top", "gaus", fmin_S2top, fmax_S2top);
	TF1 *f1_S2bot = new TF1("f1_S2bot", "gaus", fmin_S2bot, fmax_S2bot);
		 f1_S2top->SetLineColor(1);
		 f1_S2bot->SetLineColor(1);



	TCanvas *c1_S2top = new TCanvas("c1_S2top", "c1_S2top", 0, 0, 700, 500);
			 c1_S2top->SetFillColor(10);
    		 //c_S2_raw->SetLogy();
		T1	->Draw("S2top>>h1_S2top",	"",	"");
		//T1	->Draw("S2bot>>h1_S2bot_raw",	"",	"same");
		h1_S2top	-> GetXaxis() -> SetTitle("S2 top [int. ADC counts]");
		h1_S2top	-> GetYaxis() -> SetTitle("Counts");
		h1_S2top	-> GetXaxis() -> CenterTitle(true);
		h1_S2top	-> GetYaxis() -> CenterTitle(true);

	h1_S2top->Fit(f1_S2top, "R");
	c1_S2top->Update();


	TCanvas *c1_S2bot = new TCanvas("c1_S2bot", "c1_S2bot", 705, 0, 700, 500);
			 c1_S2bot->SetFillColor(10);
    		 //c_S2_raw->SetLogy();
		//T1	->Draw("S2top>>h1_S2top_raw",	"",	"");
		T1	->Draw("S2bot>>h1_S2bot",	"",	"same");
		h1_S2bot	-> GetXaxis() -> SetTitle("S2 bottom [int. ADC counts]");
		h1_S2bot	-> GetYaxis() -> SetTitle("Counts");
		h1_S2bot	-> GetXaxis() -> CenterTitle(true);
		h1_S2bot	-> GetYaxis() -> CenterTitle(true);

	h1_S2bot->Fit(f1_S2bot, "R");	
	c1_S2bot->Update();


	double mean_S2top 	= f1_S2top->GetParameter(1);
	double sigma_S2top 	= f1_S2top->GetParameter(2);
	double res_S2top 	= sigma_S2top/mean_S2top*100;

	double mean_S2bot 	= f1_S2bot->GetParameter(1);
	double sigma_S2bot 	= f1_S2bot->GetParameter(2);
	double res_S2bot 	= sigma_S2bot/mean_S2bot*100;


	cout << endl;
	cout << DataSet1 << endl;
	cout <<"S2 top = "<< mean_S2top <<" +- "<< sigma_S2top <<",   res. "<< res_S2top <<" %"<< endl;
	cout <<"S2 bot = "<< mean_S2bot <<" +- "<< sigma_S2bot <<",   res. "<< res_S2bot <<" %"<< endl;
	cout << endl;


	c1_S2top->cd();
	TPaveStats *ptstats_S2top = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
				ptstats_S2top->SetName("stats");
				ptstats_S2top->SetBorderSize(0);
				ptstats_S2top->SetTextAlign(12);
				ptstats_S2top->SetFillStyle(0);
				ptstats_S2top->SetFillColor(0);
		char text_S2top_1[256];
		char text_S2top_2[256];
		char text_S2top_3[256];
  		sprintf(text_S2top_1, "mean = %1.0f", 		mean_S2top);
  		sprintf(text_S2top_2, "#sigma = %1.0f", 	sigma_S2top);
  		sprintf(text_S2top_3, "resolution = %1.1f", res_S2top);
		TText *
				text_S2top = ptstats_S2top->AddText(text_S2top_1);
				text_S2top = ptstats_S2top->AddText(text_S2top_2);
				text_S2top = ptstats_S2top->AddText(text_S2top_3);
   		ptstats_S2top->Draw();
	c1_S2top->Update();

	c1_S2bot->cd();
	TPaveStats *ptstats_S2bot = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
				ptstats_S2bot->SetName("stats");
				ptstats_S2bot->SetBorderSize(0);
				ptstats_S2bot->SetTextAlign(12);
				ptstats_S2bot->SetFillStyle(0);
				ptstats_S2bot->SetFillColor(0);
		char text_S2bot_1[256];
		char text_S2bot_2[256];
		char text_S2bot_3[256];
  		sprintf(text_S2bot_1, "mean = %1.0f", 		mean_S2bot);
  		sprintf(text_S2bot_2, "#sigma = %1.0f", 	sigma_S2bot);
  		sprintf(text_S2bot_3, "resolution = %1.1f", res_S2bot);
		TText *
				text_S2bot = ptstats_S2bot->AddText(text_S2bot_1);
				text_S2bot = ptstats_S2bot->AddText(text_S2bot_2);
				text_S2bot = ptstats_S2bot->AddText(text_S2bot_3);
   		ptstats_S2bot->Draw();
	c1_S2bot->Update();


	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	//char outFolder_S1[500];
	//sprintf(outFolder_S1, "%s/S1", outFolder_dataset);
	//char mkdir_outFolder_S1[500];
	//sprintf(mkdir_outFolder_S1, ".mkdir %s", outFolder_S1);
	//gROOT->ProcessLine(mkdir_outFolder_S1);

	char outFolder_S2[500];
	sprintf(outFolder_S2, "%s/S2", outFolder_dataset);
	char mkdir_outFolder_S2[500];
	sprintf(mkdir_outFolder_S2, ".mkdir %s", outFolder_S2);
	gROOT->ProcessLine(mkdir_outFolder_S2);


	char char_S2top[500];
	char char_S2top_C[500];
	char char_S2bot[500];
	char char_S2bot_C[500];
	sprintf(char_S2top,		"%s/%s_rawS2top_%s_withFits%s",	outFolder_S2, DataSet1, CutName, extensionPlots);
	sprintf(char_S2top_C,	"%s/%s_rawS2top_%s_withFits%s",	outFolder_S2, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2bot,		"%s/%s_rawS2bot_%s_withFits%s",	outFolder_S2, DataSet1, CutName, extensionPlots);
	sprintf(char_S2bot_C,	"%s/%s_rawS2bot_%s_withFits%s",	outFolder_S2, DataSet1, CutName, extensionPlots_C);
	c1_S2top	->SaveAs(char_S2top);
	c1_S2top	->SaveAs(char_S2top_C);
	c1_S2bot	->SaveAs(char_S2bot);
	c1_S2bot	->SaveAs(char_S2bot_C);

