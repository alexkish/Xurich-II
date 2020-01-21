	int nbins_S1raw		= 300;
	double min_S1raw	= 0;
	double max_S1raw	= 2000;

	TH1F *h1_S1 	= new TH1F("h1_S1",		DataSetName1, nbins_S1raw, min_S1raw, max_S1raw);
	TH1F *h1_cS1 	= new TH1F("h1_cS1",	DataSetName1, nbins_S1raw, min_S1raw, max_S1raw);
	TH1F *h1_S1top 	= new TH1F("h1_S1top",	DataSetName1, nbins_S1raw, min_S1raw, max_S1raw);
	TH1F *h1_S1bot 	= new TH1F("h1_S1bot",	DataSetName1, nbins_S1raw, min_S1raw, max_S1raw);
		  h1_S1		->SetLineColor(1);
		  h1_cS1	->SetLineColor(6);
		  h1_S1top	->SetLineColor(2);
		  h1_S1bot	->SetLineColor(3);


	// FIT RANGES
	double fmin_S1 		= 900;
	double fmax_S1 		= 1250;
	double fmin_cS1 	= 1050;
	double fmax_cS1 	= 1350;

	double fmin_S1top 	= 160;
	double fmax_S1top 	= 340;
	double fmin_S1bot 	= 660;
	double fmax_S1bot 	= 940;

	TF1 *f1_S1 	= new TF1("f1_S1", 	"gaus", fmin_S1, 	fmax_S1);
	TF1 *f1_cS1 = new TF1("f1_cS1", "gaus", fmin_cS1, 	fmax_cS1);
		 f1_S1	->SetLineColor(1);
		 f1_cS1	->SetLineColor(1);

	TF1 *f1_S1top = new TF1("f1_S1top", "gaus", fmin_S1top, fmax_S1top);
	TF1 *f1_S1bot = new TF1("f1_S1bot", "gaus", fmin_S1bot, fmax_S1bot);
		 f1_S1top	->SetLineColor(1);
		 f1_S1bot	->SetLineColor(1);


	TCanvas *c1_S1 = new TCanvas("c1_S1", "c1_S1", 0, 0, 700, 500);
			 c1_S1->SetFillColor(10);
    		 //c_S1_raw->SetLogy();

		T1	->Draw("S1totalPE>>h1_S1",		"",	"");
		T1	->Draw("cS1totalPE>>h1_cS1",	"",	"same");

	h1_S1->Fit(f1_S1, "R");
	h1_cS1->Fit(f1_cS1, "R+");	

	double E_Co57 = 122.0;
	
	double mean_S1 		= f1_S1->GetParameter(1);
	double meanEr_S1 	= f1_S1->GetParError(1);
	double sigma_S1 	= f1_S1->GetParameter(2);
	double res_S1 		= sigma_S1/mean_S1*100;
	double ly_S1		= mean_S1/E_Co57;
	double lyEr_S1		= meanEr_S1/E_Co57;

	double mean_cS1 	= f1_cS1->GetParameter(1);
	double meanEr_cS1 	= f1_cS1->GetParError(1);
	double sigma_cS1 	= f1_cS1->GetParameter(2);
	double res_cS1 		= sigma_cS1/mean_cS1*100;
	double ly_cS1		= mean_cS1/E_Co57;
	double lyEr_cS1		= meanEr_cS1/E_Co57;


	cout << endl;
	cout << DataSet1 << endl;
	cout <<"S1  = "<< mean_S1  <<" +- "<< sigma_S1  <<",   res. "<< res_S1  <<" %"<< endl;
	cout <<"cS1 = "<< mean_cS1 <<" +- "<< sigma_cS1 <<",   res. "<< res_cS1 <<" %"<< endl;
	cout << endl;


	c1_S1->cd();

	h1_cS1	->Draw("same");
	h1_S1	->Draw("same");

	h1_cS1	-> GetXaxis() -> SetTitle("S1 [PE]");
	h1_cS1	-> GetYaxis() -> SetTitle("Counts");
	h1_cS1	-> GetXaxis() -> CenterTitle(true);
	h1_cS1	-> GetYaxis() -> CenterTitle(true);
	h1_cS1	-> GetXaxis() -> SetTitleOffset(1.25);
	h1_cS1	-> GetYaxis() -> SetTitleOffset(1.25);
	h1_cS1	-> SetMaximum(h1_cS1->GetMaximum());
	
	TPaveStats *ptstats_S1 = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
				ptstats_S1->SetName("stats");
				ptstats_S1->SetBorderSize(0);
				ptstats_S1->SetTextAlign(12);
				ptstats_S1->SetFillStyle(0);
				ptstats_S1->SetFillColor(0);
		char text_S1_1[256];
		char text_S1_2[256];
		char text_S1_3[256];
  		sprintf(text_S1_1, "S1   = (%1.0f #pm %1.0f) pe", 	mean_S1, sigma_S1);
  		sprintf(text_S1_2, "LY   = %1.1f pe/keV", 			ly_S1);
  		sprintf(text_S1_3, "res. = %1.1f", 					res_S1);
		TText *	text1_S1 = ptstats_S1->AddText(text_S1_1);
		TText *	text2_S1 = ptstats_S1->AddText(text_S1_2);
		TText *	text3_S1 = ptstats_S1->AddText(text_S1_3);
				text1_S1->SetTextColor(1);
				text2_S1->SetTextColor(1);
				text3_S1->SetTextColor(1);
   		ptstats_S1->Draw();

	TPaveStats *ptstats_cS1 = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
				ptstats_cS1->SetName("stats");
				ptstats_cS1->SetBorderSize(0);
				ptstats_cS1->SetTextAlign(12);
				ptstats_cS1->SetFillStyle(0);
				ptstats_cS1->SetFillColor(0);
		char text_cS1_1[256];
		char text_cS1_2[256];
		char text_cS1_3[256];
  		sprintf(text_cS1_1, "cS1  = (%1.0f #pm %1.0f) pe", 	mean_cS1, sigma_cS1);
  		sprintf(text_cS1_2, "LY   = %1.1f pe/keV", 			ly_cS1);
  		sprintf(text_cS1_3, "res. = %1.1f \%", 				res_cS1);
		TText *	text1_cS1 = ptstats_cS1->AddText(text_cS1_1);
		TText *	text2_cS1 = ptstats_cS1->AddText(text_cS1_2);
		TText *	text3_cS1 = ptstats_cS1->AddText(text_cS1_3);
				text1_cS1->SetTextColor(6);
				text2_cS1->SetTextColor(6);
				text3_cS1->SetTextColor(6);
   		ptstats_cS1->Draw();

	c1_S1->Update();



	TCanvas *c1_S1tb = new TCanvas("c1_S1tb", "c1_S1tb", 0, 0, 700, 500);
			 c1_S1tb->SetFillColor(10);
 
		T1	->Draw("S1topPE>>h1_S1top",	"",	"");
		T1	->Draw("S1botPE>>h1_S1bot",	"",	"same");

	h1_S1top->Fit(f1_S1top, "R");
	h1_S1bot->Fit(f1_S1bot, "R+");	
	
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
	cout <<"S1 top = "<< mean_S1top  <<" +- "<< sigma_S1top  <<",   res. "<< res_S1top  <<" %"<< endl;
	cout <<"S1 bot = "<< mean_S1bot  <<" +- "<< sigma_S1bot  <<",   res. "<< res_S1bot  <<" %"<< endl;
	cout << endl;


	c1_S1tb->cd();

	h1_S1top	->Draw("same");
	h1_S1bot	->Draw("same");

	h1_S1top	-> GetXaxis() -> SetTitle("S1 [PE]");
	h1_S1top	-> GetYaxis() -> SetTitle("Counts");
	h1_S1top	-> GetXaxis() -> CenterTitle(true);
	h1_S1top	-> GetYaxis() -> CenterTitle(true);
	h1_S1top	-> GetXaxis() -> SetTitleOffset(1.25);
	h1_S1top	-> GetYaxis() -> SetTitleOffset(1.25);
	h1_S1top	-> SetMaximum(h1_cS1->GetMaximum());
	
	TPaveStats *ptstats_S1top = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
				ptstats_S1top->SetName("stats");
				ptstats_S1top->SetBorderSize(0);
				ptstats_S1top->SetTextAlign(12);
				ptstats_S1top->SetFillStyle(0);
				ptstats_S1top->SetFillColor(0);
		char text_S1top_1[256];
		char text_S1top_2[256];
		char text_S1top_3[256];
  		sprintf(text_S1top_1, "S1 top = (%1.0f #pm %1.0f) pe", 	mean_S1top, sigma_S1top);
  		sprintf(text_S1top_2, "LY_{top} = %1.1f pe/keV", 		ly_S1top);
  		sprintf(text_S1top_3, "res. = %1.1f", 					res_S1top);
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
  		sprintf(text_S1bot_1, "S1 bot = (%1.0f #pm %1.0f) pe", 	mean_S1bot, sigma_S1bot);
  		sprintf(text_S1bot_2, "LY_{bot} = %1.1f pe/keV", 		ly_S1bot);
  		sprintf(text_S1bot_3, "res. = %1.1f", 					res_S1bot);
		TText *	text1_S1bot = ptstats_S1bot->AddText(text_S1bot_1);
		TText *	text2_S1bot = ptstats_S1bot->AddText(text_S1bot_2);
		TText *	text3_S1bot = ptstats_S1bot->AddText(text_S1bot_3);
				text1_S1bot->SetTextColor(1);
				text2_S1bot->SetTextColor(1);
				text3_S1bot->SetTextColor(1);
   		ptstats_S1bot->Draw();

	c1_S1tb->Update();


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

	char char_S1tb[500];
	char char_S1tb_C[500];
	
	sprintf(char_S1,		"%s/%s_cS1_%s_withFits%s",		outFolder_S1, DataSet1, CutName, extensionPlots);
	sprintf(char_S1_C,		"%s/%s_cS1_%s_withFits%s",		outFolder_S1, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1tb,		"%s/%s_S1tb_%s_withFits%s",		outFolder_S1, DataSet1, CutName, extensionPlots);
	sprintf(char_S1tb_C,	"%s/%s_S1tb_%s_withFits%s",		outFolder_S1, DataSet1, CutName, extensionPlots_C);

	c1_S1		->SaveAs(char_S1);
	c1_S1		->SaveAs(char_S1_C);

	c1_S1tb		->SaveAs(char_S1tb);
	c1_S1tb		->SaveAs(char_S1tb_C);

