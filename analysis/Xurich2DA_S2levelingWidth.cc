	////////////////////////////////////////////////////////////////
	//TCut cut_S2levelingWidth = "";
	// COMPUTE THE CUTS BASED ON THE S2-AREA FITS
	double S2TopEdgeLeft	= S2TOPmean - S2TOPsigma;
	double S2TopEdgeRight	= S2TOPmean + S2TOPsigma;
	double S2BotEdgeLeft	= S2BOTmean - S2BOTsigma;
	double S2BotEdgeRight	= S2BOTmean + S2BOTsigma;
	TCut cut_S2levelingWidth = Form("S2topPE>%g && S2topPE<%g && S2botPE>%g && S2botPE<%g", S2TopEdgeLeft, S2TopEdgeRight, S2BotEdgeLeft, S2BotEdgeRight);

	cout << endl;
	cout <<"> Dataset: "<< DataSet1 << endl;
	cout <<"> S2top cut: "<< S2TopEdgeLeft <<" - "<< S2TopEdgeRight << endl;
	cout <<"> S2bot cut: "<< S2BotEdgeLeft <<" - "<< S2BotEdgeRight << endl;
	cout << endl;

/*	int nbins_S1			= 200;
	double min_S1			= 0;
	double max_S1			= 2e3;

	int nbins_S2			= 120;
	double min_S2			= 0;
	double max_S2			= 1e5;

	int nbins_dt			= 200;
	double min_dt			= 0.;
	double max_dt			= 20.;
*/
	int nbins_S2width		= 101;
	double min_S2width		= 0.;
	double max_S2width		= 1.0;

	int nbins_S2widthLow	= 201;
	double min_S2widthLow	= 0.;
	double max_S2widthLow	= 2.0;

	int nbins_S2height		= 200;
	double min_S2height		= 0.0;
	double max_S2height		= 13500;

	int nbins_S1width		= 200;
	double min_S1width		= 0.0;
	double max_S1width		= 20;

	TH1F *h1_S2WIDTHtop 				= new TH1F("h1_S2WIDTHtop",		DataSetName1, nbins_S2width, 		min_S2width, 	max_S2width);
	TH1F *h1_S2WIDTHbot 				= new TH1F("h1_S2WIDTHbot",		DataSetName1, nbins_S2width, 		min_S2width, 	max_S2width);
	TH1F *h1_S2WIDTHLOWtop 				= new TH1F("h1_S2WIDTHLOWtop",	DataSetName1, nbins_S2widthLow, 	min_S2widthLow, max_S2widthLow);
	TH1F *h1_S2WIDTHLOWbot 				= new TH1F("h1_S2WIDTHLOWbot",	DataSetName1, nbins_S2widthLow, 	min_S2widthLow, max_S2widthLow);

/*	TH2F *h2_S2WIDTHvsDT 				= new TH2F("h2_S2WIDTHvsDT",				"", nbins_dt, 			min_dt, 		max_dt, 		nbins_S2width/2, 	min_S2width, 	max_S2width);
	TH2F *h2_S2WIDTHLOWvsDT 			= new TH2F("h2_S2WIDTHLOWvsDT",				"", nbins_dt, 			min_dt, 		max_dt, 		nbins_S2width, 		min_S2width, 	max_S2width*2);
	TH2F *h2_S2WIDTHvsS2 				= new TH2F("h2_S2WIDTHvsS2",				"", nbins_S2, 			min_S2, 		max_S2, 		nbins_S2width/2, 	min_S2width, 	max_S2width);
	TH2F *h2_S2WIDTHLOWvsS2 			= new TH2F("h2_S2WIDTHLOWvsS2",				"", nbins_S2, 			min_S2, 		max_S2, 		nbins_S2width, 		min_S2width, 	max_S2width*2);
	TH2F *h2_S1WIDTHvsS1 				= new TH2F("h2_S1WIDTHvsS1",				"", nbins_S1, 			min_S1, 		max_S1, 		nbins_S1width/2, 	min_S1width, 	max_S1width);
	TH2F *h2_S1WIDTHLOWvsS1 			= new TH2F("h2_S1WIDTHLOWvsS1",				"", nbins_S1, 			min_S1, 		max_S1, 		nbins_S1width, 		min_S1width, 	max_S1width*2);
	TH2F *h2_S2WIDTHoverHEIGHTvsS2 		= new TH2F("h2_S2WIDTHoverHEIGHTvsS2",		"", nbins_S2*10, 		min_S2, 		max_S2, 		nbins_S2*10, 		1e-5, 			1e-1);
	TH2F *h2_S2WIDTHLOWoverHEIGHTvsS2 	= new TH2F("h2_S2WIDTHLOWoverHEIGHTvsS2",	"", nbins_S2*10, 		min_S2,	 		max_S2, 		nbins_S2*10, 		1e-5, 			1e-1);
	TH2F *h2_S2WIDTHvsHEIGHT 			= new TH2F("h2_S2WIDTHvsHEIGHT",			"", nbins_S2height, 	min_S2height, 	max_S2height, 	nbins_S2width/2, 	min_S2width, 	max_S2width);
	TH2F *h2_S2WIDTHLOWvsHEIGHT 		= new TH2F("h2_S2WIDTHLOWvsHEIGHT",			"", nbins_S2height, 	min_S2height, 	max_S2height, 	nbins_S2width, 		min_S2width, 	max_S2width*2);
	TH2F *h2_S2HEIGHTvsS2 				= new TH2F("h2_S2HEIGHTvsS2",				"", nbins_S2, 			min_S2, 		max_S2, 		nbins_S2height, 	min_S2height, 	max_S2height);
*/



	TCanvas *c_S2WIDTHtop = new TCanvas("c_S2WIDTHtop", "c_S2WIDTHtop", 0, 0, 700, 500);
			 c_S2WIDTHtop->SetFillColor(10);
    		 //c_S2WIDTHtop->SetLogy();
		T1	->Draw("S2width_top>>h1_S2WIDTHtop",	cut_S2levelingWidth,	"");
		//h1_S2WIDTHtop	-> Scale(ScalingFactor);
		//h1_S2WIDTHtop	-> Scale(1e3);
		h1_S2WIDTHtop	-> GetXaxis() -> SetTitle("S2 width (top) at 50% height [#mus]");
		h1_S2WIDTHtop	-> GetYaxis() -> SetTitle("Counts");
		h1_S2WIDTHtop	-> GetXaxis() -> CenterTitle(true);
		h1_S2WIDTHtop	-> GetYaxis() -> CenterTitle(true);
		h1_S2WIDTHtop	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_S2WIDTHtop	-> GetYaxis() -> SetTitleOffset(1.30);
	c_S2WIDTHtop->Update();

	TCanvas *c_S2WIDTHbot = new TCanvas("c_S2WIDTHbot", "c_S2WIDTHbot", 0, 510, 700, 500);
			 c_S2WIDTHbot->SetFillColor(10);
    		 //c_S2WIDTHbot->SetLogy();
		T1	->Draw("S2width_bot>>h1_S2WIDTHbot",	cut_S2levelingWidth,	"");
		//h1_S2WIDTHbot	-> Scale(ScalingFactor);
		//h1_S2WIDTHbot	-> Scale(1e3);
		h1_S2WIDTHbot	-> GetXaxis() -> SetTitle("S2 width (bottom) at 50% height [#mus]");
		h1_S2WIDTHbot	-> GetYaxis() -> SetTitle("Counts");
		h1_S2WIDTHbot	-> GetXaxis() -> CenterTitle(true);
		h1_S2WIDTHbot	-> GetYaxis() -> CenterTitle(true);
		h1_S2WIDTHbot	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_S2WIDTHbot	-> GetYaxis() -> SetTitleOffset(1.30);
	c_S2WIDTHbot->Update();

	TCanvas *c_S2WIDTHLOWtop = new TCanvas("c_S2WIDTHLOWtop", "c_S2WIDTHLOWtop", 710, 0, 700, 500);
			 c_S2WIDTHLOWtop->SetFillColor(10);
    		 //c_S2WIDTHLOWtop->SetLogy();
		T1	->Draw("S2widthLow_top>>h1_S2WIDTHLOWtop",	cut_S2levelingWidth,	"");
		//h1_S2WIDTHLOWtop	-> Scale(ScalingFactor);
		//h1_S2WIDTHLOWtop	-> Scale(1e3);
		h1_S2WIDTHLOWtop	-> GetXaxis() -> SetTitle("S2 width (top) at 10% height [#mus]");
		h1_S2WIDTHLOWtop	-> GetYaxis() -> SetTitle("Counts");
		h1_S2WIDTHLOWtop	-> GetXaxis() -> CenterTitle(true);
		h1_S2WIDTHLOWtop	-> GetYaxis() -> CenterTitle(true);
	c_S2WIDTHLOWtop->Update();

	TCanvas *c_S2WIDTHLOWbot = new TCanvas("c_S2WIDTHLOWbot", "c_S2WIDTHLOWbot", 710, 510, 700, 500);
			 c_S2WIDTHLOWbot->SetFillColor(10);
    		 //c_S2WIDTHLOWbot->SetLogy();
		T1	->Draw("S2widthLow_bot>>h1_S2WIDTHLOWbot",	cut_S2levelingWidth,	"");
		//h1_S2WIDTHLOWbot	-> Scale(ScalingFactor);
		//h1_S2WIDTHLOWbot	-> Scale(1e3);
		h1_S2WIDTHLOWbot	-> GetXaxis() -> SetTitle("S2 width (bottom) at 10% height [#mus]");
		h1_S2WIDTHLOWbot	-> GetYaxis() -> SetTitle("Counts");
		h1_S2WIDTHLOWbot	-> GetXaxis() -> CenterTitle(true);
		h1_S2WIDTHLOWbot	-> GetYaxis() -> CenterTitle(true);
	c_S2WIDTHLOWbot->Update();




	//////////////////////////////////////////////////////////////////////////////////////
	// DEFINE FIT RANGES AND FIT
	const double S2widthTopLeft 	= 0.32;
	const double S2widthTopRight	= 0.38; 
		  double S2widthBotLeft 	= S2widthTopLeft;
		  double S2widthBotRight	= S2widthTopRight;

	const double S2widthLowTopLeft 	= 0.62;
	const double S2widthLowTopRight	= 0.76; 
		  double S2widthLowBotLeft 	= S2widthLowTopLeft;
		  double S2widthLowBotRight	= S2widthLowTopRight;
	

	c_S2WIDTHtop->cd();
		TF1 *fit_S2widthTop = new TF1("fit_S2widthTop", "gaus", S2widthTopLeft, S2widthTopRight);
			 fit_S2widthTop->SetLineColor(2);
			 fit_S2widthTop->SetLineWidth(2);
		h1_S2WIDTHtop->Fit(fit_S2widthTop,"R");
		double S2widthTopMean 			= fit_S2widthTop->GetParameter(1);
		double S2widthTopSigma			= fit_S2widthTop->GetParameter(2);		
		double S2widthTopMeanError 		= fit_S2widthTop->GetParError(1);
		double S2widthTopSigmaError		= fit_S2widthTop->GetParError(2);		
		double S2widthTopMedian 		= h1_S2WIDTHtop->GetMean(1);
		double S2widthTopRms			= h1_S2WIDTHtop->GetRMS(1);		
		double S2widthTopMedianError 	= h1_S2WIDTHtop->GetMeanError(1);
		double S2widthTopRmsError		= h1_S2WIDTHtop->GetRMSError(1);		
		TPaveStats *ptstats_S2widthTop = new TPaveStats(0.5632184,0.6716102,0.8979885,0.8961864,"brNDC");
					ptstats_S2widthTop->SetName("stats");
					ptstats_S2widthTop->SetBorderSize(0);
					ptstats_S2widthTop->SetTextAlign(12);
					ptstats_S2widthTop->SetFillStyle(0);
					ptstats_S2widthTop->SetFillColor(0);
			char text_S2widthTop_1[256];
			char text_S2widthTop_2[256];
			char text_S2widthTop_3[256];
			char text_S2widthTop_4[256];
  			sprintf(text_S2widthTop_1, 	"#mu_{fit} = (%1.3f #pm %1.3f) #mus", 	S2widthTopMean, 	S2widthTopMeanError);
  			sprintf(text_S2widthTop_2, 	"#sigma_{fit} = (%1.3f #pm %1.3f) #mus", 	S2widthTopSigma, 	S2widthTopSigmaError);
  			sprintf(text_S2widthTop_3, 	"#mu_{hist} = (%1.3f #pm %1.3f) #mus", 	S2widthTopMedian, 	S2widthTopMedianError);
  			sprintf(text_S2widthTop_4, 	"rms_{hist} = (%1.3f #pm %1.3f) #mus", 	S2widthTopRms, 		S2widthTopRmsError);
			TText *
					text_S2widthTop = ptstats_S2widthTop->AddText(text_S2widthTop_1);
					text_S2widthTop = ptstats_S2widthTop->AddText(text_S2widthTop_2);
					text_S2widthTop = ptstats_S2widthTop->AddText(text_S2widthTop_3);
					text_S2widthTop = ptstats_S2widthTop->AddText(text_S2widthTop_4);
   			ptstats_S2widthTop->Draw();
	c_S2WIDTHtop->Update();


	c_S2WIDTHbot->cd();
		TF1 *fit_S2widthBot = new TF1("fit_S2widthBot", "gaus", S2widthBotLeft, S2widthBotRight);
			 fit_S2widthBot->SetLineColor(2);
			 fit_S2widthBot->SetLineWidth(2);
		h1_S2WIDTHbot->Fit(fit_S2widthBot,"R");
		double S2widthBotMean 			= fit_S2widthBot->GetParameter(1);
		double S2widthBotSigma			= fit_S2widthBot->GetParameter(2);		
		double S2widthBotMeanError 		= fit_S2widthBot->GetParError(1);
		double S2widthBotSigmaError		= fit_S2widthBot->GetParError(2);		
		double S2widthBotMedian 		= h1_S2WIDTHbot->GetMean(1);
		double S2widthBotRms			= h1_S2WIDTHbot->GetRMS(1);		
		double S2widthBotMedianError 	= h1_S2WIDTHbot->GetMeanError(1);
		double S2widthBotRmsError		= h1_S2WIDTHbot->GetRMSError(1);		
		TPaveStats *ptstats_S2widthBot = new TPaveStats(0.5632184,0.6716102,0.8979885,0.8961864,"brNDC");
					ptstats_S2widthBot->SetName("stats");
					ptstats_S2widthBot->SetBorderSize(0);
					ptstats_S2widthBot->SetTextAlign(12);
					ptstats_S2widthBot->SetFillStyle(0);
					ptstats_S2widthBot->SetFillColor(0);
			char text_S2widthBot_1[256];
			char text_S2widthBot_2[256];
			char text_S2widthBot_3[256];
			char text_S2widthBot_4[256];
  			sprintf(text_S2widthBot_1, 	"#mu_{fit} = (%1.2f #pm %1.2f) #mus", 	S2widthBotMean, 	S2widthBotMeanError);
  			sprintf(text_S2widthBot_2, 	"#sigma_{fit} = (%1.2f #pm %1.2f) #mus", 	S2widthBotSigma, 	S2widthBotSigmaError);
  			sprintf(text_S2widthBot_3, 	"#mus_{hist} = (%1.3f #pm %1.3f) #mus", 	S2widthBotMedian, 	S2widthBotMedianError);
  			sprintf(text_S2widthBot_4, 	"rms_{hist} = (%1.3f #pm %1.3f) #mus", 	S2widthBotRms, 		S2widthBotRmsError);
			TText *
					text_S2widthBot = ptstats_S2widthBot->AddText(text_S2widthBot_1);
					text_S2widthBot = ptstats_S2widthBot->AddText(text_S2widthBot_2);
					text_S2widthBot = ptstats_S2widthBot->AddText(text_S2widthBot_3);
					text_S2widthBot = ptstats_S2widthBot->AddText(text_S2widthBot_4);
   			ptstats_S2widthBot->Draw();
	c_S2WIDTHbot->Update();


	c_S2WIDTHLOWtop->cd();
		TF1 *fit_S2widthLowTop = new TF1("fit_S2widthLowTop","gaus", S2widthLowTopLeft, S2widthLowTopRight);
			 fit_S2widthLowTop->SetLineColor(2);
			 fit_S2widthLowTop->SetLineWidth(2);
		h1_S2WIDTHLOWtop->Fit(fit_S2widthLowTop, "R");
		double S2widthLowTopMean 		= fit_S2widthLowTop->GetParameter(1);
		double S2widthLowTopSigma		= fit_S2widthLowTop->GetParameter(2);		
		double S2widthLowTopMeanError 	= fit_S2widthLowTop->GetParError(1);
		double S2widthLowTopSigmaError	= fit_S2widthLowTop->GetParError(2);		
		double S2widthLowTopMedian 		= h1_S2WIDTHLOWtop->GetMean(1);
		double S2widthLowTopRms			= h1_S2WIDTHLOWtop->GetRMS(1);		
		double S2widthLowTopMedianError = h1_S2WIDTHLOWtop->GetMeanError(1);
		double S2widthLowTopRmsError	= h1_S2WIDTHLOWtop->GetRMSError(1);		
		TPaveStats *ptstats_S2widthLowTop = new TPaveStats(0.5632184,0.6716102,0.8979885,0.8961864,"brNDC");
					ptstats_S2widthLowTop->SetName("stats");
					ptstats_S2widthLowTop->SetBorderSize(0);
					ptstats_S2widthLowTop->SetTextAlign(12);
					ptstats_S2widthLowTop->SetFillStyle(0);
					ptstats_S2widthLowTop->SetFillColor(0);
			char text_S2widthLowTop_1[256];
			char text_S2widthLowTop_2[256];
			char text_S2widthLowTop_3[256];
			char text_S2widthLowTop_4[256];
  			sprintf(text_S2widthLowTop_1, 	"#mu_{fit} = (%1.3f #pm %1.3f) #mus", 		S2widthLowTopMean, 		S2widthLowTopMeanError);
  			sprintf(text_S2widthLowTop_2, 	"#sigma_{fit} = (%1.3f #pm %1.3f) #mus", 	S2widthLowTopSigma, 	S2widthLowTopSigmaError);
  			sprintf(text_S2widthLowTop_3, 	"#mu_{hist} = (%1.3f #pm %1.3f) #mus", 		S2widthLowTopMedian, 	S2widthLowTopMedianError);
  			sprintf(text_S2widthLowTop_4, 	"rms_{hist} = (%1.3f #pm %1.3f) #mus", 		S2widthLowTopRms, 		S2widthLowTopRmsError);
			TText *
					text_S2widthLowTop = ptstats_S2widthLowTop->AddText(text_S2widthLowTop_1);
					text_S2widthLowTop = ptstats_S2widthLowTop->AddText(text_S2widthLowTop_2);
					text_S2widthLowTop = ptstats_S2widthLowTop->AddText(text_S2widthLowTop_3);
					text_S2widthLowTop = ptstats_S2widthLowTop->AddText(text_S2widthLowTop_4);
   			ptstats_S2widthLowTop->Draw();
	c_S2WIDTHLOWtop->Update();

	c_S2WIDTHLOWbot->cd();
		TF1 *fit_S2widthLowBot = new TF1("fit_S2widthLowBot", "gaus", S2widthLowBotLeft, S2widthLowBotRight);
			 fit_S2widthLowBot->SetLineColor(2);
			 fit_S2widthLowBot->SetLineWidth(2);
		h1_S2WIDTHLOWbot->Fit(fit_S2widthLowBot,"R");
		double S2widthLowBotMean 		= fit_S2widthLowBot->GetParameter(1);
		double S2widthLowBotSigma		= fit_S2widthLowBot->GetParameter(2);		
		double S2widthLowBotMeanError 	= fit_S2widthLowBot->GetParError(1);
		double S2widthLowBotSigmaError	= fit_S2widthLowBot->GetParError(2);		
		double S2widthLowBotMedian 		= h1_S2WIDTHLOWbot->GetMean(1);
		double S2widthLowBotRms			= h1_S2WIDTHLOWbot->GetRMS(1);		
		double S2widthLowBotMedianError = h1_S2WIDTHLOWbot->GetMeanError(1);
		double S2widthLowBotRmsError	= h1_S2WIDTHLOWbot->GetRMSError(1);		
		TPaveStats *ptstats_S2widthLowBot = new TPaveStats(0.5632184,0.6716102,0.8979885,0.8961864,"brNDC");
					ptstats_S2widthLowBot->SetName("stats");
					ptstats_S2widthLowBot->SetBorderSize(0);
					ptstats_S2widthLowBot->SetTextAlign(12);
					ptstats_S2widthLowBot->SetFillStyle(0);
					ptstats_S2widthLowBot->SetFillColor(0);
			char text_S2widthLowBot_1[256];
			char text_S2widthLowBot_2[256];
			char text_S2widthLowBot_3[256];
			char text_S2widthLowBot_4[256];
  			sprintf(text_S2widthLowBot_1, "#mu_{fit} = (%1.3f #pm %1.3f) #mus", 	S2widthLowBotMean, 		S2widthLowBotMeanError);
  			sprintf(text_S2widthLowBot_2, "#sigma_{fit} = (%1.3f #pm %1.3f) #mus", 	S2widthLowBotSigma, 	S2widthLowBotSigmaError);
  			sprintf(text_S2widthLowBot_3, "#mu_{hist} = (%1.3f #pm %1.3f) #mus", 	S2widthLowBotMedian, 	S2widthLowBotMedianError);
  			sprintf(text_S2widthLowBot_4, "rms_{hist} = (%1.3f #pm %1.3f) #mus", 	S2widthLowBotRms, 		S2widthLowBotRmsError);
			TText *
					text_S2widthLowBot = ptstats_S2widthLowBot->AddText(text_S2widthLowBot_1);
					text_S2widthLowBot = ptstats_S2widthLowBot->AddText(text_S2widthLowBot_2);
					text_S2widthLowBot = ptstats_S2widthLowBot->AddText(text_S2widthLowBot_3);
					text_S2widthLowBot = ptstats_S2widthLowBot->AddText(text_S2widthLowBot_4);
   			ptstats_S2widthLowBot->Draw();
	c_S2WIDTHLOWbot->Update();




	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_S2levelingWidth[500];
	//sprintf(outFolder_S2levelingWidth, "./plots/chi2/%s_%s/S2levelingWidth", DataSet1, CutName);
	//sprintf(outFolder_S2levelingWidth, "./plots/fra/%s_%s/S2levelingWidth", DataSet1, CutName);
	sprintf(outFolder_S2levelingWidth, "./plots/%s_%s/S2levelingWidth", DataSet1, CutName);

	char mkdir_outFolder_S2levelingWidth[500];
	sprintf(mkdir_outFolder_S2levelingWidth, ".mkdir %s", outFolder_S2levelingWidth);

	gROOT->ProcessLine(mkdir_outFolder_S2levelingWidth);


	char char_S2WIDTHtop[500];
	char char_S2WIDTHLOWtop[500];
	char char_S2WIDTHbot[500];
	char char_S2WIDTHLOWbot[500];

/*	char char_S2WIDTHvsDT[500];
	char char_S2WIDTHLOWvsDT[500];
	char char_S2WIDTHvsS2[500];
	char char_S2WIDTHLOWvsS2[500];
	char char_S2HEIGHTvsS2[500];
	char char_S1WIDTHvsS1[500];
	char char_S1WIDTHLOWvsS1[500];
*/
	char char_S2WIDTHtop_C[500];
	char char_S2WIDTHLOWtop_C[500];
	char char_S2WIDTHbot_C[500];
	char char_S2WIDTHLOWbot_C[500];

/*	char char_S2WIDTHvsDT_C[500];
	char char_S2WIDTHLOWvsDT_C[500];
	char char_S2WIDTHvsS2_C[500];
	char char_S2WIDTHLOWvsS2_C[500];
	char char_S2HEIGHTvsS2_C[500];
	char char_S1WIDTHvsS1_C[500];
	char char_S1WIDTHLOWvsS1_C[500];
*/		

	sprintf(char_S2WIDTHtop,			"%s/%s_S2WIDTHtop_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots);
	sprintf(char_S2WIDTHLOWtop,			"%s/%s_S2WIDTHLOWtop_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots);
	sprintf(char_S2WIDTHbot,			"%s/%s_S2WIDTHbot_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots);
	sprintf(char_S2WIDTHLOWbot,			"%s/%s_S2WIDTHLOWbot_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots);

/*	sprintf(char_S2WIDTHvsDT,			"%s/%s_S2WIDTHvsDT_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots);
	sprintf(char_S2WIDTHLOWvsDT,		"%s/%s_S2WIDTHLOWvsDT_%s%s",	outFolder_dataset, DataSet1, CutName, extensionPlots);
	sprintf(char_S2WIDTHvsS2,			"%s/%s_S2WIDTHvsS2_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots);
	sprintf(char_S2WIDTHLOWvsS2,		"%s/%s_S2WIDTHLOWvsS2_%s%s",	outFolder_dataset, DataSet1, CutName, extensionPlots);
	sprintf(char_S2HEIGHTvsS2,			"%s/%s_S2HEIGHTvsS2_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots);
	sprintf(char_S1WIDTHvsS1,			"%s/%s_S1WIDTHvsS1_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots);
	sprintf(char_S1WIDTHLOWvsS1,		"%s/%s_S1WIDTHLOWvsS1_%s%s",	outFolder_dataset, DataSet1, CutName, extensionPlots);
*/
	sprintf(char_S2WIDTHtop_C,			"%s/%s_S2WIDTHtop_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2WIDTHLOWtop_C,		"%s/%s_S2WIDTHLOWtop_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2WIDTHbot_C,			"%s/%s_S2WIDTHbot_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2WIDTHLOWbot_C,		"%s/%s_S2WIDTHLOWbot_%s%s",		outFolder_S2levelingWidth, DataSet1, CutName, extensionPlots_C);

/*	sprintf(char_S2WIDTHvsDT_C,			"%s/%s_S2WIDTHvsDT_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2WIDTHLOWvsDT_C,		"%s/%s_S2WIDTHLOWvsDT_%s%s",	outFolder_dataset, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2WIDTHvsS2_C,			"%s/%s_S2WIDTHvsS2_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2WIDTHLOWvsS2_C,		"%s/%s_S2WIDTHLOWvsS2_%s%s",	outFolder_dataset, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2HEIGHTvsS2_C,		"%s/%s_S2HEIGHTvsS2_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S1WIDTHvsS1_C,			"%s/%s_S1WIDTHvsS1_%s%s",		outFolder_dataset, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S1WIDTHLOWvsS1_C,		"%s/%s_S1WIDTHLOWvsS1_%s%s",	outFolder_dataset, DataSet1, CutName, extensionPlots_C);
*/
	c_S2WIDTHtop		->SaveAs(char_S2WIDTHtop);
	c_S2WIDTHLOWtop		->SaveAs(char_S2WIDTHLOWtop);
	c_S2WIDTHbot		->SaveAs(char_S2WIDTHbot);
	c_S2WIDTHLOWbot		->SaveAs(char_S2WIDTHLOWbot);

/*	c_S2WIDTHvsDT		->SaveAs(char_S2WIDTHvsDT);
	c_S2WIDTHLOWvsDT	->SaveAs(char_S2WIDTHLOWvsDT);
	c_S2WIDTHvsS2		->SaveAs(char_S2WIDTHvsS2);
	c_S2WIDTHLOWvsS2	->SaveAs(char_S2WIDTHLOWvsS2);
	c_S2HEIGHTvsS2		->SaveAs(char_S2HEIGHTvsS2);
*/
	c_S2WIDTHtop		->SaveAs(char_S2WIDTHtop_C);
	c_S2WIDTHLOWtop		->SaveAs(char_S2WIDTHLOWtop_C);
	c_S2WIDTHbot		->SaveAs(char_S2WIDTHbot_C);
	c_S2WIDTHLOWbot		->SaveAs(char_S2WIDTHLOWbot_C);

/*	c_S2WIDTHvsDT		->SaveAs(char_S2WIDTHvsDT_C);
	c_S2WIDTHLOWvsDT	->SaveAs(char_S2WIDTHLOWvsDT_C);
	c_S2WIDTHvsS2		->SaveAs(char_S2WIDTHvsS2_C);
	c_S2WIDTHLOWvsS2	->SaveAs(char_S2WIDTHLOWvsS2_C);
	c_S2HEIGHTvsS2		->SaveAs(char_S2HEIGHTvsS2_C);
*/