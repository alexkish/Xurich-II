	TCut cut_S2levelingArea  = "";

	//////////////////////////////////////////////////////////////////////////////////////
	// PLOT
	int nbins_S2		= 120;
	double min_S2		= 0;
	double max_S2		= 90e3;
	double max_S2top	= 60e3;
	double max_S2bot	= 25e3;

/*	int nbins_S1delay	= 500;
	double min_S1delay	= 0.;
	double max_S1delay	= 10.;

	int nbins_S2width	= 200;
	double min_S2width	= 0.0;
	double max_S2width	= 1.0;

	int nbins_S2height	= 200;
	double min_S2height	= 0.0;
	double max_S2height	= 13500;

	int nbins_chi2	= 200;
	double min_chi2	= 0.;
	double max_chi2	= 0.015;
*/
	TH1F *h1_S2 			= new TH1F("h1_S2",				DataSetName1, 	nbins_S2, 	min_S2, 	max_S2);
	TH1F *h1_S2TOP 			= new TH1F("h1_S2TOP",			DataSetName1, 	nbins_S2, 	min_S2, 	max_S2top);
	TH1F *h1_S2BOT 			= new TH1F("h1_S2BOT",			DataSetName1, 	nbins_S2, 	min_S2, 	max_S2bot);
	TH2F *h2_S2vsS2 		= new TH2F("h2_S2vsS2",			DataSetName1, 	nbins_S2/2, min_S2, max_S2, 	nbins_S2/2, min_S2, max_S2/50);
	TH2F *h2_S2TOPvsS2BOT 	= new TH2F("h2_S2TOPvsS2BOT",	DataSetName1, 	nbins_S2, 	min_S2, max_S2bot, 	nbins_S2, 	min_S2, max_S2top);



	TCanvas *c_S2vsS2 = new TCanvas("c_S2vsS2", "c_S2vsS2", 0, 0, 700, 500);
			 c_S2vsS2->SetFillColor(10);
    		 c_S2vsS2->SetLogz();
		T1	->Draw("S2totalPE1:S2totalPE>>h2_S2vsS2", cut_S2levelingArea,	"COLZ");
		h2_S2vsS2	-> GetXaxis() -> SetTitle("largest S2[0] [PE]");
		h2_S2vsS2	-> GetYaxis() -> SetTitle("S2[1] [PE]");
		h2_S2vsS2	-> GetXaxis() -> CenterTitle(true);
		h2_S2vsS2	-> GetYaxis() -> CenterTitle(true);
	c_S2vsS2->Update();

	TCanvas *c_S2TOPvsS2BOT = new TCanvas("c_S2TOPvsS2BOT", "c_S2TOPvsS2BOT", 0, 0, 700, 500);
			 c_S2TOPvsS2BOT->SetFillColor(10);
    		 c_S2TOPvsS2BOT->SetLogz();
		T1	->Draw("S2topPE:S2botPE>>h2_S2TOPvsS2BOT",	cut_S2levelingArea,	"COLZ");
		//h2_S2TOPvsS2BOT	-> Scale(ScalingFactor);
		h2_S2TOPvsS2BOT	-> GetXaxis() -> SetTitle("S2 bottom [PE]");
		h2_S2TOPvsS2BOT	-> GetYaxis() -> SetTitle("S2 top [PE]");
		h2_S2TOPvsS2BOT	-> GetXaxis() -> CenterTitle(true);
		h2_S2TOPvsS2BOT	-> GetYaxis() -> CenterTitle(true);
	c_S2TOPvsS2BOT->Update();



	TCanvas *c_S2 = new TCanvas("c_S2", "c_S2", 0, 0, 700, 500);
			 c_S2->SetFillColor(10);
    		 //c_S2->SetLogy();
		T1	->Draw("S2totalPE>>h1_S2",	cut_S2levelingArea,	"");
		//h1_S2	-> Scale(ScalingFactor);
		//h1_S2	-> Scale(1e3);
		h1_S2	-> GetXaxis() -> SetTitle("S2 total [PE]");
		h1_S2	-> GetYaxis() -> SetTitle("Counts");
		h1_S2	-> GetXaxis() -> CenterTitle(true);
		h1_S2	-> GetYaxis() -> CenterTitle(true);
		h1_S2	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2->Update();

	TCanvas *c_S2TOP = new TCanvas("c_S2TOP", "c_S2TOP", 710, 0, 700, 500);
			 c_S2TOP->SetFillColor(10);
    		 //c_S2TOP->SetLogy();
		T1	->Draw("S2topPE>>h1_S2TOP",	cut_S2levelingArea,	"");
		//h1_S2TOP	-> Scale(ScalingFactor);
		//h1_S2TOP	-> Scale(1e3);
		h1_S2TOP	-> GetXaxis() -> SetTitle("S2 top [PE]");
		h1_S2TOP	-> GetYaxis() -> SetTitle("Counts");
		h1_S2TOP	-> GetXaxis() -> CenterTitle(true);
		h1_S2TOP	-> GetYaxis() -> CenterTitle(true);
		h1_S2TOP	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2TOP->Update();

	TCanvas *c_S2BOT = new TCanvas("c_S2BOT", "c_S2BOT", 1420, 0, 700, 500);
			 c_S2BOT->SetFillColor(10);
    		 //c_S2BOT->SetLogy();
		T1	->Draw("S2botPE>>h1_S2BOT",	cut_S2levelingArea,	"");
		//h1_S2BOT	-> Scale(ScalingFactor);
		//h1_S2BOT	-> Scale(1e3);
		h1_S2BOT	-> GetXaxis() -> SetTitle("S2 bottom [PE]");
		h1_S2BOT	-> GetYaxis() -> SetTitle("Counts");
		h1_S2BOT	-> GetXaxis() -> CenterTitle(true);
		h1_S2BOT	-> GetYaxis() -> CenterTitle(true);
		h1_S2BOT	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2BOT->Update();
	




	// CALCULATIONS, PLOT UPDATES

	// pos 1
	double FitXmin_S2tot	= 30e3;
	double FitXmax_S2tot	= 38e3;

	double FitXmin_S2top	= 19e3;
	double FitXmax_S2top	= 25e3;

	double FitXmin_S2bot	= 9e3;
	double FitXmax_S2bot	= 13e3;

/*	// pos 3
	double FitXmin_S2tot	= 27e3;
	double FitXmax_S2tot	= 38e3;

	double FitXmin_S2top	= 19e3;
	double FitXmax_S2top	= 27e3;

	double FitXmin_S2bot	= 8e3;
	double FitXmax_S2bot	= 11.5e3;
*/
/*	// pos 4
	double FitXmin_S2tot	= 28e3;
	double FitXmax_S2tot	= 40e3;

	double FitXmin_S2top	= 20e3;
	double FitXmax_S2top	= 30e3;

	double FitXmin_S2bot	= 8e3;
	double FitXmax_S2bot	= 13e3;
*/	
	c_S2->cd();
		TF1 *fit_S2 = new TF1("fit_S2","gaus", FitXmin_S2tot, FitXmax_S2tot);
			 fit_S2->SetLineColor(2);
			 fit_S2->SetLineWidth(2);
		h1_S2->Fit(fit_S2,"R");
		double S2mean 		= fit_S2->GetParameter(1);
		double S2sigma		= fit_S2->GetParameter(2);		
		double S2meanError 	= fit_S2->GetParError(1);
		double S2sigmaError	= fit_S2->GetParError(2);		
		TPaveStats *ptstats_S2 = new TPaveStats(0.6221264,0.7478814,0.8979885,0.8961864,"brNDC");
					ptstats_S2->SetName("stats");
					ptstats_S2->SetBorderSize(0);
					ptstats_S2->SetTextAlign(12);
					ptstats_S2->SetFillStyle(0);
					ptstats_S2->SetFillColor(0);
			//char text_S2_1[256];
			//char text_S2_2[256];
			char text_S2_3[256];
			char text_S2_4[256];
  			//sprintf(text_S2_1, "#mu = %1.0f pe", S2mean);
  			//sprintf(text_S2_2, "#sigma = %1.0f pe", S2sigma);
  			sprintf(text_S2_3, "#mu = (%1.0f #pm %1.0f) PE", S2mean, S2meanError);
  			sprintf(text_S2_4, "#sigma = (%1.0f #pm %1.0f) PE", S2sigma, S2sigmaError);
			TText *
					//text_S2 = ptstats_S2->AddText(text_S2_1);
					//text_S2 = ptstats_S2->AddText(text_S2_2);
					text_S2 = ptstats_S2->AddText(text_S2_3);
					text_S2 = ptstats_S2->AddText(text_S2_4);
   			ptstats_S2->Draw();
		double S2max = fit_S2->GetMaximum();
		h1_S2->SetMaximum(S2max*1.5);
		TLine *lnL_S2 = new TLine(S2mean-S2sigma, 0, S2mean-S2sigma, S2max);
			   lnL_S2 ->SetLineStyle(7);
			   lnL_S2 ->Draw();
		TLine *lnR_S2 = new TLine(S2mean+S2sigma, 0, S2mean+S2sigma, S2max);
			   lnR_S2 ->SetLineStyle(7);
			   lnR_S2 ->Draw();
	c_S2->Update();

	c_S2TOP->cd();
		TF1 *fit_S2top = new TF1("fit_S2top","gaus", FitXmin_S2top, FitXmax_S2top);
			 fit_S2top->SetLineColor(2);
			 fit_S2top->SetLineWidth(2);
		h1_S2TOP->Fit(fit_S2top,"R");
		double S2TOPmean 		= fit_S2top->GetParameter(1);
		double S2TOPsigma		= fit_S2top->GetParameter(2);		
		double S2TOPmeanError 	= fit_S2top->GetParError(1);
		double S2TOPsigmaError	= fit_S2top->GetParError(2);		
		TPaveStats *ptstats_S2top = new TPaveStats(0.6221264,0.7478814,0.8979885,0.8961864,"brNDC");
					ptstats_S2top->SetName("stats");
					ptstats_S2top->SetBorderSize(0);
					ptstats_S2top->SetTextAlign(12);
					ptstats_S2top->SetFillStyle(0);
					ptstats_S2top->SetFillColor(0);
			//char text_S2top_1[256];
			//char text_S2top_2[256];
			char text_S2top_3[256];
			char text_S2top_4[256];
  			//sprintf(text_S2top_1, "#mu = %1.0f pe", S2TOPmean);
  			//sprintf(text_S2top_2, "#sigma = %1.0f pe", S2TOPsigma);
  			sprintf(text_S2top_3, "#mu = (%1.0f #pm %1.0f) PE", S2TOPmean, S2TOPmeanError);
  			sprintf(text_S2top_4, "#sigma = (%1.0f #pm %1.0f) PE", S2TOPsigma, S2TOPsigmaError);
			TText *
					//text_S2top = ptstats_S2top->AddText(text_S2top_1);
					//text_S2top = ptstats_S2top->AddText(text_S2top_2);
					text_S2top = ptstats_S2top->AddText(text_S2top_3);
					text_S2top = ptstats_S2top->AddText(text_S2top_4);
   			ptstats_S2top->Draw();
		double S2maxTop = fit_S2top->GetMaximum();
		h1_S2TOP->SetMaximum(S2maxTop*1.5);
		TLine *lnL_S2top = new TLine(S2TOPmean-S2TOPsigma, 0, S2TOPmean-S2TOPsigma, S2maxTop);
			   lnL_S2top ->SetLineStyle(7);
			   lnL_S2top ->Draw();
		TLine *lnR_S2top = new TLine(S2TOPmean+S2TOPsigma, 0, S2TOPmean+S2TOPsigma, S2maxTop);
			   lnR_S2top ->SetLineStyle(7);
			   lnR_S2top ->Draw();
	c_S2TOP->Update();

	c_S2BOT->cd();
		TF1 *fit_S2bot = new TF1("fit_S2bot","gaus", FitXmin_S2bot, FitXmax_S2bot);
			 fit_S2bot->SetLineColor(2);
			 fit_S2bot->SetLineWidth(2);
		h1_S2BOT->Fit(fit_S2bot,"R");
		double S2BOTmean 		= fit_S2bot->GetParameter(1);
		double S2BOTsigma		= fit_S2bot->GetParameter(2);		
		double S2BOTmeanError 	= fit_S2bot->GetParError(1);
		double S2BOTsigmaError	= fit_S2bot->GetParError(2);		
		TPaveStats *ptstats_S2bot = new TPaveStats(0.6221264,0.7478814,0.8979885,0.8961864,"brNDC");
					ptstats_S2bot->SetName("stats");
					ptstats_S2bot->SetBorderSize(0);
					ptstats_S2bot->SetTextAlign(12);
					ptstats_S2bot->SetFillStyle(0);
					ptstats_S2bot->SetFillColor(0);
			//char text_S2bot_1[256];
			//char text_S2bot_2[256];
			char text_S2bot_3[256];
			char text_S2bot_4[256];
  			//sprintf(text_S2bot_1, "#mu = %1.0f pe", S2BOTmean);
  			//sprintf(text_S2bot_2, "#sigma = %1.0f pe", S2BOTsigma);
  			sprintf(text_S2bot_3, "#mu = (%1.0f #pm %1.0f) PE", S2BOTmean, S2BOTmeanError);
  			sprintf(text_S2bot_4, "#sigma = (%1.0f #pm %1.0f) PE", S2BOTsigma, S2BOTsigmaError);
			TText *
					//text_S2bot = ptstats_S2bot->AddText(text_S2bot_1);
					//text_S2bot = ptstats_S2bot->AddText(text_S2bot_2);
					text3_S2bot = ptstats_S2bot->AddText(text_S2bot_3);
					text3_S2bot = ptstats_S2bot->AddText(text_S2bot_4);
   			ptstats_S2bot->Draw();
		double S2maxBot = fit_S2bot->GetMaximum();
		h1_S2BOT->SetMaximum(S2maxBot*1.5);
		TLine *lnL_S2bot = new TLine(S2BOTmean-S2BOTsigma, 0, S2BOTmean-S2BOTsigma, S2maxBot);
			   lnL_S2bot ->SetLineStyle(7);
			   lnL_S2bot ->Draw();
		TLine *lnR_S2bot = new TLine(S2BOTmean+S2BOTsigma, 0, S2BOTmean+S2BOTsigma, S2maxBot);
			   lnR_S2bot ->SetLineStyle(7);
			   lnR_S2bot ->Draw();
	c_S2BOT->Update();

		








	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_S2levelingArea[500];
	//sprintf(outFolder_S2levelingArea, "./plots/chi2/%s_%s/S2levelingArea", DataSet1, CutName);
	//sprintf(outFolder_S2levelingArea, "./plots/fra/%s_%s/S2levelingArea", DataSet1, CutName);
	sprintf(outFolder_S2levelingArea, "./plots/%s_%s/S2levelingArea", DataSet1, CutName);

	char mkdir_outFolder_S2levelingArea[500];
	sprintf(mkdir_outFolder_S2levelingArea, ".mkdir %s", outFolder_S2levelingArea);

	gROOT->ProcessLine(mkdir_outFolder_S2levelingArea);


	char char_S2[500];
	char char_S2TOP[500];
	char char_S2BOT[500];
	char char_S2vsS2[500];
	char char_S2TOPvsS2BOT[500];

	char char_S2_C[500];
	char char_S2TOP_C[500];
	char char_S2BOT_C[500];
	char char_S2vsS2_C[500];
	char char_S2TOPvsS2BOT_C[500];
		

	sprintf(char_S2,					"%s/%s_S2_%s%s",				outFolder_S2levelingArea, DataSet1, CutName, extensionPlots);
	sprintf(char_S2TOP,					"%s/%s_S2TOP_%s%s",				outFolder_S2levelingArea, DataSet1, CutName, extensionPlots);
	sprintf(char_S2BOT,					"%s/%s_S2BOT_%s%s",				outFolder_S2levelingArea, DataSet1, CutName, extensionPlots);
	sprintf(char_S2vsS2,				"%s/%s_S2vsS2_%s%s",			outFolder_S2levelingArea, DataSet1, CutName, extensionPlots);
	sprintf(char_S2TOPvsS2BOT,			"%s/%s_S2TOPvsS2BOT_%s%s",		outFolder_S2levelingArea, DataSet1, CutName, extensionPlots);

	sprintf(char_S2_C,					"%s/%s_S2_%s%s",				outFolder_S2levelingArea, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2TOP_C,				"%s/%s_S2TOP_%s%s",				outFolder_S2levelingArea, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2BOT_C,				"%s/%s_S2BOT_%s%s",				outFolder_S2levelingArea, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2vsS2_C,				"%s/%s_S2vsS2_%s%s",			outFolder_S2levelingArea, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2TOPvsS2BOT_C,		"%s/%s_S2TOPvsS2BOT_%s%s",		outFolder_S2levelingArea, DataSet1, CutName, extensionPlots_C);

	c_S2				->SaveAs(char_S2);
	c_S2TOP				->SaveAs(char_S2TOP);
	c_S2BOT				->SaveAs(char_S2BOT);
	c_S2vsS2			->SaveAs(char_S2vsS2);
	c_S2TOPvsS2BOT		->SaveAs(char_S2TOPvsS2BOT);

	c_S2				->SaveAs(char_S2_C);
	c_S2TOP				->SaveAs(char_S2TOP_C);
	c_S2BOT				->SaveAs(char_S2BOT_C);
	c_S2vsS2			->SaveAs(char_S2vsS2_C);
	c_S2TOPvsS2BOT		->SaveAs(char_S2TOPvsS2BOT_C);
