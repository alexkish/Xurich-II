	int nbins_S2raw		= 300;
	double min_S2raw	= 0;
	double max_S2raw	= 4e5;

	TH1F *h1_S2 	= new TH1F("h1_S2",		DataSetName1, nbins_S2raw, min_S2raw, max_S2raw);
	TH1F *h1_S2top 	= new TH1F("h1_S2top",	DataSetName1, nbins_S2raw, min_S2raw, max_S2raw);
	TH1F *h1_S2bot 	= new TH1F("h1_S2bot",	DataSetName1, nbins_S2raw, min_S2raw, max_S2raw);
		  h1_S2		->SetLineColor(1);
		  h1_S2top	->SetLineColor(2);
		  h1_S2bot	->SetLineColor(3);


	// FIT RANGES
/*	// 150522_2009
	double fmin_S2top = 22e3;
	double fmax_S2top = 50e3;
	double fmin_S2bot = 40e3;
	double fmax_S2bot = 70e3;
	double fmin_S2heightTop = 900;
	double fmax_S2heightTop = 1700;
	// 150523_1248
	double fmin_S2top = 30e3;
	double fmax_S2top = 60e3;
	double fmin_S2bot = 55e3;
	double fmax_S2bot = 90e3;
	double fmin_S2heightTop = 1300;
	double fmax_S2heightTop = 2400;
	// 150524_1601
	double fmin_S2top = 55e3;
	double fmax_S2top = 80e3;
	double fmin_S2bot = 110e3;
	double fmax_S2bot = 140e3;
	double fmin_S2heightTop = 2100;
	double fmax_S2heightTop = 3600;
	// 150525_1311
	double fmin_S2top = 40e3;
	double fmax_S2top = 75e3;
	double fmin_S2bot = 80e3;
	double fmax_S2bot = 120e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150526_0036
	double fmin_S2top = 25e3;
	double fmax_S2top = 45e3;
	double fmin_S2bot = 35e3;
	double fmax_S2bot = 65e3;
	double fmin_S2heightTop = 850;
	double fmax_S2heightTop = 1400;
	// 150526_1722
	double fmin_S2top = 40e3;
	double fmax_S2top = 65e3;
	double fmin_S2bot = 60e3;
	double fmax_S2bot = 100e3;
	double fmin_S2heightTop = 1600;
	double fmax_S2heightTop = 2600;
	// 150526_2253
	double fmin_S2top = 50e3;
	double fmax_S2top = 80e3;
	double fmin_S2bot = 80e3;
	double fmax_S2bot = 130e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150528
	double fmin_S2top = 50e3;
	double fmax_S2top = 80e3;
	double fmin_S2bot = 80e3;
	double fmax_S2bot = 130e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150529
	double fmin_S2top = 40e3;
	double fmax_S2top = 70e3;
	double fmin_S2bot = 75e3;
	double fmax_S2bot = 115e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150601_2230
	double fmin_S2top = 45e3;
	double fmax_S2top = 75e3;
	double fmin_S2bot = 75e3;
	double fmax_S2bot = 125e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150602_0941
	double fmin_S2top = 48e3;
	double fmax_S2top = 78e3;
	double fmin_S2bot = 85e3;
	double fmax_S2bot = 135e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150602_1350
	double fmin_S2top = 50e3;
	double fmax_S2top = 80e3;
	double fmin_S2bot = 87e3;
	double fmax_S2bot = 137e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150602_1931
	double fmin_S2top = 55e3;
	double fmax_S2top = 85e3;
	double fmin_S2bot = 90e3;
	double fmax_S2bot = 140e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
	// 150603
	double fmin_S2top = 55e3;
	double fmax_S2top = 90e3;
	double fmin_S2bot = 95e3;
	double fmax_S2bot = 145e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
*/	// 150604
/*	double fmin_S2top = 47e3;
	double fmax_S2top = 75e3;
	double fmin_S2bot = 75e3;
	double fmax_S2bot = 120e3;
	double fmin_S2heightTop = 1900;
	double fmax_S2heightTop = 3500;
*/
	double fmin_S2top = 150e3;
	double fmax_S2top = 220e3;
	double fmin_S2bot = 140e3;
	double fmax_S2bot = 200e3;
	double fmin_S2heightTop = 1000;
	double fmax_S2heightTop = 2200;
	TF1 *f1_S2top = new TF1("f1_S2top", "gaus", fmin_S2top, fmax_S2top);
	TF1 *f1_S2bot = new TF1("f1_S2bot", "gaus", fmin_S2bot, fmax_S2bot);
		 f1_S2top->SetLineColor(1);
		 f1_S2bot->SetLineColor(1);


	TCanvas *c1_S2 = new TCanvas("c1_S2", "c1_S2", 0, 0, 700, 500);
			 c1_S2->SetFillColor(10);
    		 //c_S2_raw->SetLogy();

		T1	->Draw("S2botPE>>h1_S2bot",	"",	"");
		T1	->Draw("S2topPE>>h1_S2top",	"",	"same");

	h1_S2top->Fit(f1_S2top, "R");
	h1_S2bot->Fit(f1_S2bot, "R+");	


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


	c1_S2->cd();

	h1_S2bot->Draw("same");
	h1_S2top->Draw("same");

	h1_S2bot	-> GetXaxis() -> SetTitle("S2 [PE]");
	h1_S2bot	-> GetYaxis() -> SetTitle("Counts");
	h1_S2bot	-> GetXaxis() -> CenterTitle(true);
	h1_S2bot	-> GetYaxis() -> CenterTitle(true);
	h1_S2bot	-> GetXaxis() -> SetTitleOffset(1.25);
	h1_S2bot	-> GetYaxis() -> SetTitleOffset(1.25);
	h1_S2bot	-> SetMaximum(h1_S2top->GetMaximum());
	
	TPaveStats *ptstats_S2top = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
				ptstats_S2top->SetName("stats");
				ptstats_S2top->SetBorderSize(0);
				ptstats_S2top->SetTextAlign(12);
				ptstats_S2top->SetFillStyle(0);
				ptstats_S2top->SetFillColor(0);
		char text_S2top_1[256];
		char text_S2top_2[256];
		char text_S2top_3[256];
  		sprintf(text_S2top_1, "mean = %1.0f pe", 	mean_S2top);
  		sprintf(text_S2top_2, "#sigma = %1.0f pe", 	sigma_S2top);
  		sprintf(text_S2top_3, "resolution = %1.1f", res_S2top);
		TText *	text1_S2top = ptstats_S2top->AddText(text_S2top_1);
		TText *	text2_S2top = ptstats_S2top->AddText(text_S2top_2);
		TText *	text3_S2top = ptstats_S2top->AddText(text_S2top_3);
				text1_S2top->SetTextColor(2);
				text2_S2top->SetTextColor(2);
				text3_S2top->SetTextColor(2);
   		ptstats_S2top->Draw();

	TPaveStats *ptstats_S2bot = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
				ptstats_S2bot->SetName("stats");
				ptstats_S2bot->SetBorderSize(0);
				ptstats_S2bot->SetTextAlign(12);
				ptstats_S2bot->SetFillStyle(0);
				ptstats_S2bot->SetFillColor(0);
		char text_S2bot_1[256];
		char text_S2bot_2[256];
		char text_S2bot_3[256];
  		sprintf(text_S2bot_1, "mean = %1.0f pe", 	mean_S2bot);
  		sprintf(text_S2bot_2, "#sigma = %1.0f pe", 	sigma_S2bot);
  		sprintf(text_S2bot_3, "resolution = %1.1f", res_S2bot);
		TText *	text1_S2bot = ptstats_S2bot->AddText(text_S2bot_1);
		TText *	text2_S2bot = ptstats_S2bot->AddText(text_S2bot_2);
		TText *	text3_S2bot = ptstats_S2bot->AddText(text_S2bot_3);
   		ptstats_S2bot->Draw();

	double S2topLeft 	= mean_S2top-sigma_S2top;
	double S2topRight 	= mean_S2top+sigma_S2top;
	double S2topMax		= f1_S2top->GetParameter(0);
	TLine *line_S2topLeft 	= new TLine(S2topLeft, 	0, S2topLeft, 	S2topMax);
	TLine *line_S2topRight 	= new TLine(S2topRight, 0, S2topRight, 	S2topMax);
		   line_S2topLeft	->SetLineColor(2);
		   line_S2topRight	->SetLineColor(2);
		   line_S2topLeft	->SetLineStyle(7);
		   line_S2topRight	->SetLineStyle(7);
		   line_S2topLeft	->Draw("same");
		   line_S2topRight	->Draw("same");

	double S2botLeft 	= mean_S2bot-sigma_S2bot;
	double S2botRight 	= mean_S2bot+sigma_S2bot;
	double S2botMax		= f1_S2bot->GetParameter(0);
	TLine *line_S2botLeft 	= new TLine(S2botLeft, 	0, S2botLeft, 	S2botMax);
	TLine *line_S2botRight 	= new TLine(S2botRight, 0, S2botRight, 	S2botMax);
		   line_S2botLeft	->SetLineColor(3);
		   line_S2botRight	->SetLineColor(3);
		   line_S2botLeft	->SetLineStyle(7);
		   line_S2botRight	->SetLineStyle(7);
		   line_S2botLeft	->Draw("same");
		   line_S2botRight	->Draw("same");

	c1_S2->Update();


	// define 1sigma cut on S2 area
	TCut cut_S2area	= Form("S2topPE > %g && S2topPE < %g", mean_S2top-sigma_S2top, mean_S2top+sigma_S2top);


	// PLOT S2 ASYMMETRY
	int nbins_S2asym	= 250;
	double min_S2asym	= -0.5;
	double max_S2asym	= 1.0;

	TH1F *h1_S2asym 	= new TH1F("h1_S2asym",		DataSetName1, nbins_S2asym, min_S2asym, max_S2asym);

	TCanvas *c1_S2asym = new TCanvas("c1_S2asym", "c1_S2asym", 705, 0, 700, 500);
			 c1_S2asym->SetFillColor(10);
 		T1	->Draw("S2asym>>h1_S2asym",	cut_S2area,	"");
		h1_S2asym	-> GetXaxis() -> SetTitle("S2 asymmetry");
		h1_S2asym	-> GetYaxis() -> SetTitle("Counts");
		h1_S2asym	-> GetXaxis() -> CenterTitle(true);
		h1_S2asym	-> GetYaxis() -> CenterTitle(true);

		double S2asym_median 	= h1_S2asym->GetMean(1);
		double S2asym_rms		= h1_S2asym->GetRMS(1);		
		double S2asym_medianEr 	= h1_S2asym->GetMeanError(1);
		double S2asym_rmsEr		= h1_S2asym->GetRMSError(1);		
		TPaveStats *ptstats_S2asym = new TPaveStats(0.5632184,0.6716102,0.8979885,0.8961864,"brNDC");
					ptstats_S2asym->SetName("stats");
					ptstats_S2asym->SetBorderSize(0);
					ptstats_S2asym->SetTextAlign(12);
					ptstats_S2asym->SetFillStyle(0);
					ptstats_S2asym->SetFillColor(0);
			char text_S2asym_1[256];
			char text_S2asym_2[256];
  			//sprintf(text_S2asym_1, 	"median = (%1.3f #pm %1.3f)", 	S2asym_median, 	S2asym_medianEr);
  			//sprintf(text_S2asym_2, 	"rms = (%1.3f #pm %1.3f)", 		S2asym_rms, 	S2asym_rmsEr);
  			sprintf(text_S2asym_1, 	"median = %1.2f", 	S2asym_median);
  			sprintf(text_S2asym_2, 	"rms = %1.2f", 		S2asym_rms);
			TText *text1_S2asym = ptstats_S2asym->AddText(text_S2asym_1);
			TText *text2_S2asym = ptstats_S2asym->AddText(text_S2asym_2);
   			ptstats_S2asym->Draw();
   			
	c1_S2asym->Update();


	// PLOT S1 ASYMMETRY
	int nbins_S1asym	= 250;
	double min_S1asym	= -1.0;
	double max_S1asym	= 0.0;

	TH1F *h1_S1asym 	= new TH1F("h1_S1asym",	DataSetName1, nbins_S1asym, min_S1asym, max_S1asym);

	TCanvas *c1_S1asym = new TCanvas("c1_S1asym", "c1_S1asym", 705, 0, 700, 500);
			 c1_S1asym->SetFillColor(10);
    		 c1_S1asym->SetLogz();
		T1	->Draw("S1asym>>h1_S1asym",	cut_S2area,	"");
		h1_S1asym	-> GetXaxis() -> SetTitle("S1 asymmetry");
		h1_S1asym	-> GetYaxis() -> SetTitle("Counts");
		h1_S1asym	-> GetXaxis() -> CenterTitle(true);
		h1_S1asym	-> GetYaxis() -> CenterTitle(true);

		double S1asym_median 	= h1_S1asym->GetMean(1);
		double S1asym_rms		= h1_S1asym->GetRMS(1);		
		double S1asym_medianEr 	= h1_S1asym->GetMeanError(1);
		double S1asym_rmsEr		= h1_S1asym->GetRMSError(1);		
		TPaveStats *ptstats_S1asym = new TPaveStats(0.5632184,0.6716102,0.8979885,0.8961864,"brNDC");
					ptstats_S1asym->SetName("stats");
					ptstats_S1asym->SetBorderSize(0);
					ptstats_S1asym->SetTextAlign(12);
					ptstats_S1asym->SetFillStyle(0);
					ptstats_S1asym->SetFillColor(0);
			char text_S1asym_1[256];
			char text_S1asym_2[256];
  			sprintf(text_S1asym_1, 	"median = %1.2f", 	S1asym_median);
  			sprintf(text_S1asym_2, 	"rms = %1.2f", 		S1asym_rms);
			TText *text1_S1asym = ptstats_S1asym->AddText(text_S1asym_1);
			TText *text2_S1asym = ptstats_S1asym->AddText(text_S1asym_2);
   			ptstats_S1asym->Draw();
   			
	c1_S1asym->Update();


	// PLOT S2 WIDTH
	int nbins_S2width	= 201;
	double min_S2width	= 0.;
	double max_S2width	= 2.0;

	TH1F *h1_S2widthTop 	= new TH1F("h1_S2widthTop",		DataSetName1, nbins_S2width, min_S2width, max_S2width);
	TH1F *h1_S2widthLowTop 	= new TH1F("h1_S2widthLowTop",	DataSetName1, nbins_S2width, min_S2width, max_S2width);
		  h1_S2widthTop		->SetLineColor(1);
		  h1_S2widthLowTop	->SetLineColor(2);

	TCanvas *c1_S2width = new TCanvas("c1_S2width", "c1_S2width", 705, 0, 700, 500);
			 c1_S2width->SetFillColor(10);
		T1	->Draw("S2width_top>>h1_S2widthTop",		cut_S2area,	"");
		T1	->Draw("S2widthLow_top>>h1_S2widthLowTop",	cut_S2area,	"same");
		h1_S2widthTop	-> GetXaxis() -> SetTitle("S2 top width [#mus]");
		h1_S2widthTop	-> GetYaxis() -> SetTitle("Counts");
		h1_S2widthTop	-> GetXaxis() -> CenterTitle(true);
		h1_S2widthTop	-> GetYaxis() -> CenterTitle(true);

		double S2widthTop_median 	= h1_S2widthTop->GetMean(1);
		double S2widthTop_rms		= h1_S2widthTop->GetRMS(1);		
		double S2widthTop_medianEr = h1_S2widthTop->GetMeanError(1);
		double S2widthTop_rmsEr	= h1_S2widthTop->GetRMSError(1);		
		TPaveStats *ptstats_S2widthTop = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S2widthTop->SetName("stats");
					ptstats_S2widthTop->SetBorderSize(0);
					ptstats_S2widthTop->SetTextAlign(12);
					ptstats_S2widthTop->SetFillStyle(0);
					ptstats_S2widthTop->SetFillColor(0);
			char text_S2widthTop_1[256];
			char text_S2widthTop_2[256];
  			sprintf(text_S2widthTop_1, 	"median = %1.2f", 	S2widthTop_median);
  			sprintf(text_S2widthTop_2, 	"rms = %1.2f", 		S2widthTop_rms);
			TText *text1_S2widthTop = ptstats_S2widthTop->AddText(text_S2widthTop_1);
			TText *text2_S2widthTop = ptstats_S2widthTop->AddText(text_S2widthTop_2);
   			ptstats_S2widthTop->Draw();

		double S2widthLowTop_median 	= h1_S2widthLowTop->GetMean(1);
		double S2widthLowTop_rms		= h1_S2widthLowTop->GetRMS(1);		
		double S2widthLowTop_medianEr 	= h1_S2widthLowTop->GetMeanError(1);
		double S2widthLowTop_rmsEr		= h1_S2widthLowTop->GetRMSError(1);		
		TPaveStats *ptstats_S2widthLowTop = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_S2widthLowTop->SetName("stats");
					ptstats_S2widthLowTop->SetBorderSize(0);
					ptstats_S2widthLowTop->SetTextAlign(12);
					ptstats_S2widthLowTop->SetFillStyle(0);
					ptstats_S2widthLowTop->SetFillColor(0);
			char text_S2widthLowTop_1[256];
			char text_S2widthLowTop_2[256];
  			sprintf(text_S2widthLowTop_1, 	"median = %1.2f", 	S2widthLowTop_median);
  			sprintf(text_S2widthLowTop_2, 	"rms = %1.2f", 		S2widthLowTop_rms);
			TText *text1_S2widthLowTop = ptstats_S2widthTop->AddText(text_S2widthLowTop_1);
			TText *text2_S2widthLowTop = ptstats_S2widthTop->AddText(text_S2widthLowTop_2);
				   text1_S2widthLowTop->SetTextColor(2);
				   text2_S2widthLowTop->SetTextColor(2);
   			ptstats_S2widthTop->Draw();
   			
	c1_S2width->Update();


	// PLOT S2 HEIGHT
	int nbins_S2height	= 200;
	double min_S2height	= 0.;
	double max_S2height	= 6000.;

	TH1F *h1_S2heightTop 	= new TH1F("h1_S2heightTop",	DataSetName1, nbins_S2height, min_S2height, max_S2height);

	TCanvas *c1_S2height = new TCanvas("c1_S2height", "c1_S2height", 705, 0, 700, 500);
			 c1_S2height->SetFillColor(10);
		T1	->Draw("S2height_top>>h1_S2heightTop",		cut_S2area,	"");
		h1_S2heightTop	-> GetXaxis() -> SetTitle("S2 top height [ADC channels]");
		h1_S2heightTop	-> GetYaxis() -> SetTitle("Counts");
		h1_S2heightTop	-> GetXaxis() -> CenterTitle(true);
		h1_S2heightTop	-> GetYaxis() -> CenterTitle(true);

		TF1 *f1_S2heightTop = new TF1("f1_S2heightTop", "gaus", fmin_S2heightTop, fmax_S2heightTop);

		h1_S2heightTop->Fit(f1_S2heightTop, "R");

		double S2heightTop_median 	= h1_S2heightTop->GetMean(1);
		double S2heightTop_rms		= h1_S2heightTop->GetRMS(1);		
		double S2heightTop_medianEr = h1_S2heightTop->GetMeanError(1);
		double S2heightTop_rmsEr	= h1_S2heightTop->GetRMSError(1);		

		double S2heightTop_mean 	= f1_S2heightTop->GetParameter(1);
		double S2heightTop_sigma	= f1_S2heightTop->GetParameter(2);		
		double S2heightTop_meanEr 	= f1_S2heightTop->GetParError(1);
		double S2heightTop_sigmaEr	= f1_S2heightTop->GetParError(2);		

		TPaveStats *ptstats_S2heightTop = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S2heightTop->SetName("stats");
					ptstats_S2heightTop->SetBorderSize(0);
					ptstats_S2heightTop->SetTextAlign(12);
					ptstats_S2heightTop->SetFillStyle(0);
					ptstats_S2heightTop->SetFillColor(0);
			char text_S2heightTop_1[256];
			char text_S2heightTop_2[256];
			char text_S2heightTop_3[256];
			char text_S2heightTop_4[256];
  			sprintf(text_S2heightTop_1, 	"median = %1.0f", 				S2heightTop_median);
  			sprintf(text_S2heightTop_2, 	"rms = %1.0f", 					S2heightTop_rms);
  			sprintf(text_S2heightTop_3, 	"#mu = (%1.0f #pm %1.0f)", 		S2heightTop_mean, S2heightTop_meanEr);
  			sprintf(text_S2heightTop_4, 	"#sigma = (%1.0f #pm %1.0f)", 	S2heightTop_sigma, S2heightTop_sigmaEr);
			TText *text1_S2heightTop = ptstats_S2heightTop->AddText(text_S2heightTop_1);
			TText *text2_S2heightTop = ptstats_S2heightTop->AddText(text_S2heightTop_2);
			TText *text3_S2heightTop = ptstats_S2heightTop->AddText(text_S2heightTop_3);
			TText *text4_S2heightTop = ptstats_S2heightTop->AddText(text_S2heightTop_4);
   			ptstats_S2heightTop->Draw();
   			
	c1_S2height->Update();


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


	char char_S2[500];
	char char_S2_C[500];

	char char_S2asym[500];
	char char_S2asym_C[500];

	char char_S1asym[500];
	char char_S1asym_C[500];

	char char_S2width[500];
	char char_S2width_C[500];

	char char_S2height[500];
	char char_S2height_C[500];

	sprintf(char_S2,			"%s/%s_peS2_%s_withFits%s",	outFolder_S2, DataSet1, CutName, extensionPlots);
	sprintf(char_S2_C,			"%s/%s_peS2_%s_withFits%s",	outFolder_S2, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2asym,		"%s/%s_S2asym_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots);
	sprintf(char_S2asym_C,		"%s/%s_S2asym_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1asym,		"%s/%s_S1asym_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots);
	sprintf(char_S1asym_C,		"%s/%s_S1asym_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2width,		"%s/%s_S2width_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots);
	sprintf(char_S2width_C,		"%s/%s_S2width_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2height,		"%s/%s_S2height_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots);
	sprintf(char_S2height_C,	"%s/%s_S2height_%s%s",		outFolder_S2, DataSet1, CutName, extensionPlots_C);

	c1_S2		->SaveAs(char_S2);
	c1_S2		->SaveAs(char_S2_C);

	c1_S2asym	->SaveAs(char_S2asym);
	c1_S2asym	->SaveAs(char_S2asym_C);

	c1_S1asym	->SaveAs(char_S1asym);
	c1_S1asym	->SaveAs(char_S1asym_C);

	c1_S2width	->SaveAs(char_S2width);
	c1_S2width	->SaveAs(char_S2width_C);

	c1_S2height	->SaveAs(char_S2height);
	c1_S2height	->SaveAs(char_S2height_C);
