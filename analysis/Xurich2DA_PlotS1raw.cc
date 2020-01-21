	int nbins_S1top		= 350;
	double min_S1top	= 0;
	double max_S1top	= 700;

	int nbins_S1bot		= 400;
	double min_S1bot	= 0;
	double max_S1bot	= 3500;

	TH1F *h1_S1top 	= new TH1F("h1_S1top",	DataSetName1, nbins_S1top, min_S1top, max_S1top);
	TH1F *h1_S1bot 	= new TH1F("h1_S1bot",	DataSetName1, nbins_S1bot, min_S1bot, max_S1bot);
		  h1_S1top	->SetLineColor(2);
		  h1_S1bot	->SetLineColor(3);


	// FIT RANGES
/*	// 150522_2009
	double fmin_S1top = 130;
	double fmax_S1top = 240;
	double fmin_S1bot = 1000;
	double fmax_S1bot = 1600;
*/	// 150523_1248 and the rest
	double fmin_S1top = 100;
	double fmax_S1top = 210;
	double fmin_S1bot = 800;
	double fmax_S1bot = 1450;
/*	// 150522_1840
	double fmin_S1top = 100;
	double fmax_S1top = 210;
	double fmin_S1bot = 800;
	double fmax_S1bot = 1450;
*/
	TF1 *f1_S1top = new TF1("f1_S1top", "gaus", fmin_S1top, fmax_S1top);
	TF1 *f1_S1bot = new TF1("f1_S1bot", "gaus", fmin_S1bot, fmax_S1bot);
		 f1_S1top->SetLineColor(1);
		 f1_S1bot->SetLineColor(1);



	TCanvas *c1_S1top = new TCanvas("c1_S1top", "c1_S1top", 0, 0, 700, 500);
			 c1_S1top->SetFillColor(10);
		T1	->Draw("S1top>>h1_S1top",	"",	"");
		h1_S1top	-> GetXaxis() -> SetTitle("S1 top [int. ADC counts]");
		h1_S1top	-> GetYaxis() -> SetTitle("Counts");
		h1_S1top	-> GetXaxis() -> CenterTitle(true);
		h1_S1top	-> GetYaxis() -> CenterTitle(true);

	h1_S1top->Fit(f1_S1top, "R");
	c1_S1top->Update();


	TCanvas *c1_S1bot = new TCanvas("c1_S1bot", "c1_S1bot", 705, 0, 700, 500);
			 c1_S1bot->SetFillColor(10);
		T1	->Draw("S1bot>>h1_S1bot",	"",	"same");
		h1_S1bot	-> GetXaxis() -> SetTitle("S1 bottom [int. ADC counts]");
		h1_S1bot	-> GetYaxis() -> SetTitle("Counts");
		h1_S1bot	-> GetXaxis() -> CenterTitle(true);
		h1_S1bot	-> GetYaxis() -> CenterTitle(true);

	h1_S1bot->Fit(f1_S1bot, "R");	
	c1_S1bot->Update();


	double mean_S1top 	= f1_S1top->GetParameter(1);
	double sigma_S1top 	= f1_S1top->GetParameter(2);
	double res_S1top 	= sigma_S1top/mean_S1top*100;

	double mean_S1bot 	= f1_S1bot->GetParameter(1);
	double sigma_S1bot 	= f1_S1bot->GetParameter(2);
	double res_S1bot 	= sigma_S1bot/mean_S1bot*100;


	cout << endl;
	cout << DataSet1 << endl;
	cout <<"S1 top = "<< mean_S1top <<" +- "<< sigma_S1top <<",   res. "<< res_S1top <<" %"<< endl;
	cout <<"S1 bot = "<< mean_S1bot <<" +- "<< sigma_S1bot <<",   res. "<< res_S1bot <<" %"<< endl;
	cout << endl;


	c1_S1top->cd();
	TPaveStats *ptstats_S1top = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
				ptstats_S1top->SetName("stats");
				ptstats_S1top->SetBorderSize(0);
				ptstats_S1top->SetTextAlign(12);
				ptstats_S1top->SetFillStyle(0);
				ptstats_S1top->SetFillColor(0);
		char text_S1top_1[256];
		char text_S1top_2[256];
		char text_S1top_3[256];
  		sprintf(text_S1top_1, "mean = %1.0f", 		mean_S1top);
  		sprintf(text_S1top_2, "#sigma = %1.0f", 	sigma_S1top);
  		sprintf(text_S1top_3, "resolution = %1.1f", res_S1top);
		TText *
				text_S1top = ptstats_S1top->AddText(text_S1top_1);
				text_S1top = ptstats_S1top->AddText(text_S1top_2);
				text_S1top = ptstats_S1top->AddText(text_S1top_3);
   		ptstats_S1top->Draw();
	c1_S1top->Update();

	c1_S1bot->cd();
	TPaveStats *ptstats_S1bot = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
				ptstats_S1bot->SetName("stats");
				ptstats_S1bot->SetBorderSize(0);
				ptstats_S1bot->SetTextAlign(12);
				ptstats_S1bot->SetFillStyle(0);
				ptstats_S1bot->SetFillColor(0);
		char text_S1bot_1[256];
		char text_S1bot_2[256];
		char text_S1bot_3[256];
  		sprintf(text_S1bot_1, "mean = %1.0f", 		mean_S1bot);
  		sprintf(text_S1bot_2, "#sigma = %1.0f", 	sigma_S1bot);
  		sprintf(text_S1bot_3, "resolution = %1.1f", res_S1bot);
		TText *
				text_S1bot = ptstats_S1bot->AddText(text_S1bot_1);
				text_S1bot = ptstats_S1bot->AddText(text_S1bot_2);
				text_S1bot = ptstats_S1bot->AddText(text_S1bot_3);
   		ptstats_S1bot->Draw();
	c1_S1bot->Update();


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

	char outFolder_S1[500];
	sprintf(outFolder_S1, "%s/S1", outFolder_dataset);
	char mkdir_outFolder_S1[500];
	sprintf(mkdir_outFolder_S1, ".mkdir %s", outFolder_S1);
	gROOT->ProcessLine(mkdir_outFolder_S1);


	char char_S1top[500];
	char char_S1top_C[500];
	char char_S1bot[500];
	char char_S1bot_C[500];
	sprintf(char_S1top,		"%s/%s_rawS1top_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots);
	sprintf(char_S1top_C,	"%s/%s_rawS1top_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S1bot,		"%s/%s_rawS1bot_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots);
	sprintf(char_S1bot_C,	"%s/%s_rawS1bot_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots_C);
	c1_S1top	->SaveAs(char_S1top);
	c1_S1top	->SaveAs(char_S1top_C);
	c1_S1bot	->SaveAs(char_S1bot);
	c1_S1bot	->SaveAs(char_S1bot_C);

