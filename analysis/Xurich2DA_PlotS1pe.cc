	int nbins_S1raw		= 300;
	double min_S1raw	= 0;
	double max_S1raw	= 1500;

	TH1F *h1_S1 	= new TH1F("h1_S1",		DataSetName1, nbins_S1raw, min_S1raw, max_S1raw);
	TH1F *h1_S1top 	= new TH1F("h1_S1top",	DataSetName1, nbins_S1raw, min_S1raw, max_S1raw);
	TH1F *h1_S1bot 	= new TH1F("h1_S1bot",	DataSetName1, nbins_S1raw, min_S1raw, max_S1raw);
		  h1_S1		->SetLineColor(1);
		  h1_S1top	->SetLineColor(2);
		  h1_S1bot	->SetLineColor(3);


	// FIT RANGES
/*	// 150522_2009
	double fmin_S1top = 70;
	double fmax_S1top = 160;
	double fmin_S1bot = 600;
	double fmax_S1bot = 1000;
	// 150523_1248
	double fmin_S1top = 50;
	double fmax_S1top = 130;
	double fmin_S1bot = 500;
	double fmax_S1bot = 900;
	// 150524_1601
	double fmin_S1top = 50;
	double fmax_S1top = 130;
	double fmin_S1bot = 500;
	double fmax_S1bot = 900;
	// 150525_1311
	double fmin_S1top = 50;
	double fmax_S1top = 130;
	double fmin_S1bot = 500;
	double fmax_S1bot = 900;
	// 150526_0036
	double fmin_S1top = 50;
	double fmax_S1top = 130;
	double fmin_S1bot = 500;
	double fmax_S1bot = 900;
	// 150526_1722
	double fmin_S1top = 50;
	double fmax_S1top = 130;
	double fmin_S1bot = 500;
	double fmax_S1bot = 850;
	// 150526_2253
	double fmin_S1top = 50;
	double fmax_S1top = 130;
	double fmin_S1bot = 500;
	double fmax_S1bot = 850;
*/	// 150529
	double fmin_S1top = 50;
	double fmax_S1top = 130;
	double fmin_S1bot = 500;
	double fmax_S1bot = 850;


	TF1 *f1_S1top = new TF1("f1_S1top", "gaus", fmin_S1top, fmax_S1top);
	TF1 *f1_S1bot = new TF1("f1_S1bot", "gaus", fmin_S1bot, fmax_S1bot);
		 f1_S1top->SetLineColor(1);
		 f1_S1bot->SetLineColor(1);


	TCanvas *c1_S1 = new TCanvas("c1_S1", "c1_S1", 0, 0, 700, 500);
			 c1_S1->SetFillColor(10);
    		 //c_S1_raw->SetLogy();

		T1	->Draw("S1botPE>>h1_S1bot",	"",	"");
		T1	->Draw("S1topPE>>h1_S1top",	"",	"same");

	h1_S1top->Fit(f1_S1top, "R");
	h1_S1bot->Fit(f1_S1bot, "R+");	

	double E_Co57 = 122.0;
	
	double mean_S1top 	= f1_S1top->GetParameter(1);
	double meanEr_S1top = f1_S1top->GetParError(1);
	double sigma_S1top 	= f1_S1top->GetParameter(2);
	double res_S1top 	= sigma_S1top/mean_S1top*100;
	double ly_S1top		= mean_S1top/E_Co57;
	double lyEr_S1top	= meanEr_S1top/E_Co57;

	double mean_S1bot 	= f1_S1bot->GetParameter(1);
	double meanEr_S1bot = f1_S1bot->GetParError(1);
	double sigma_S1bot 	= f1_S1bot->GetParameter(2);
	double res_S1bot 	= sigma_S1bot/mean_S1bot*100;
	double ly_S1bot		= mean_S1bot/E_Co57;
	double lyEr_S1bot	= meanEr_S1bot/E_Co57;


	cout << endl;
	cout << DataSet1 << endl;
	cout <<"S1 top = "<< mean_S1top <<" +- "<< sigma_S1top <<",   res. "<< res_S1top <<" %"<< endl;
	cout <<"S1 bot = "<< mean_S1bot <<" +- "<< sigma_S1bot <<",   res. "<< res_S1bot <<" %"<< endl;
	cout << endl;


	c1_S1->cd();

	h1_S1bot->Draw("same");
	h1_S1top->Draw("same");

	h1_S1bot	-> GetXaxis() -> SetTitle("S1 [PE]");
	h1_S1bot	-> GetYaxis() -> SetTitle("Counts");
	h1_S1bot	-> GetXaxis() -> CenterTitle(true);
	h1_S1bot	-> GetYaxis() -> CenterTitle(true);
	h1_S1bot	-> GetXaxis() -> SetTitleOffset(1.25);
	h1_S1bot	-> GetYaxis() -> SetTitleOffset(1.25);
	h1_S1bot	-> SetMaximum(h1_S1top->GetMaximum());
	
	TPaveStats *ptstats_S1top = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
				ptstats_S1top->SetName("stats");
				ptstats_S1top->SetBorderSize(0);
				ptstats_S1top->SetTextAlign(12);
				ptstats_S1top->SetFillStyle(0);
				ptstats_S1top->SetFillColor(0);
		char text_S1top_1[256];
		char text_S1top_2[256];
		char text_S1top_3[256];
  		sprintf(text_S1top_1, "S1_{top} = (%1.0f #pm %1.0f) pe", 	mean_S1top, sigma_S1top);
  		sprintf(text_S1top_2, "LY = %1.1f pe/keV", 	ly_S1top);
  		sprintf(text_S1top_3, "resolution = %1.1f", res_S1top);
		TText *	text1_S1top = ptstats_S1top->AddText(text_S1top_1);
		TText *	text2_S1top = ptstats_S1top->AddText(text_S1top_2);
		TText *	text3_S1top = ptstats_S1top->AddText(text_S1top_3);
				text1_S1top->SetTextColor(2);
				text2_S1top->SetTextColor(2);
				text3_S1top->SetTextColor(2);
   		ptstats_S1top->Draw();

	TPaveStats *ptstats_S1bot = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
				ptstats_S1bot->SetName("stats");
				ptstats_S1bot->SetBorderSize(0);
				ptstats_S1bot->SetTextAlign(12);
				ptstats_S1bot->SetFillStyle(0);
				ptstats_S1bot->SetFillColor(0);
		char text_S1bot_1[256];
		char text_S1bot_2[256];
		char text_S1bot_3[256];
  		sprintf(text_S1bot_1, "S1_{bottom} = (%1.0f #pm %1.0f) pe", 	mean_S1bot, sigma_S1bot);
  		sprintf(text_S1bot_2, "LY = %1.1f pe/keV", 	ly_S1bot);
  		sprintf(text_S1bot_3, "resolution = %1.1f", res_S1bot);
		TText *	text1_S1bot = ptstats_S1bot->AddText(text_S1bot_1);
		TText *	text2_S1bot = ptstats_S1bot->AddText(text_S1bot_2);
		TText *	text3_S1bot = ptstats_S1bot->AddText(text_S1bot_3);
   		ptstats_S1bot->Draw();

	c1_S1->Update();


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


	char char_S1[500];
	char char_S1_C[500];
	char char_S1top[500];
	char char_S1top_C[500];
	char char_S1bot[500];
	char char_S1bot_C[500];
	sprintf(char_S1,		"%s/%s_peS1_%s_withFits%s",		outFolder_S1, DataSet1, CutName, extensionPlots);
	sprintf(char_S1_C,		"%s/%s_peS1_%s_withFits%s",		outFolder_S1, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S1top,		"%s/%s_peS1top_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots);
	sprintf(char_S1top_C,	"%s/%s_peS1top_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S1bot,		"%s/%s_peS1bot_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots);
	sprintf(char_S1bot_C,	"%s/%s_peS1bot_%s_withFits%s",	outFolder_S1, DataSet1, CutName, extensionPlots_C);
	c1_S1		->SaveAs(char_S1top);
	c1_S1		->SaveAs(char_S1top_C);
	//c1_S1top	->SaveAs(char_S1top);
	//c1_S1top	->SaveAs(char_S1top_C);
	//c1_S1bot	->SaveAs(char_S1bot);
	//c1_S1bot	->SaveAs(char_S1bot_C);

