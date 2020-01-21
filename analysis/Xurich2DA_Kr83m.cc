	TCut cut_PlotAll  = "";

	//////////////////////////////////////////////////////////////////////////////////////
	// PLOT
	int nbins_S1		= 350;
	double min_S1		= 0;
	double max_S1		= 700;

	int nbins_S2		= 350;
	double min_S2		= 0;
	double max_S2		= 8e4;

	int nbins_dt		= 200;
	double min_dt		= 0.;
	double max_dt		= 20.;

	int nbins_S1delay	= 100;
	double min_S1delay	= 0.;
	double max_S1delay	= 5.;

	TH2F *h2_S1vsS1			= new TH2F("h2_S1vsS1",			DataSetName1, 	nbins_S1/5, 	min_S1, max_S1, nbins_S1/5, 		min_S1, 		max_S1/2);
	TH2F *h2_S1vsS1_scat 	= new TH2F("h2_S1vsS1_scat",	DataSetName1, 	nbins_S1*10,	min_S1, max_S1, nbins_S1*10, 		min_S1, 		max_S1/2);

	TH1F *h1_S1delayTop 	= new TH1F("h1_S1delayTop",		DataSetName1, 	nbins_S1delay, 	min_S1delay, 	max_S1delay);
	TH1F *h1_S1delayBot 	= new TH1F("h1_S1delayBot",		DataSetName1, 	nbins_S1delay, 	min_S1delay, 	max_S1delay);

	TH1F *h1_S1 			= new TH1F("h1_S1",				DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
	TH1F *h1_S10 			= new TH1F("h1_S10",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
	TH1F *h1_S11 			= new TH1F("h1_S11",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
		  h1_S1				->SetLineColor(1);
		  h1_S10			->SetLineColor(2);
		  h1_S11			->SetLineColor(3);
	TH1F *h1_cS1 			= new TH1F("h1_cS1",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
	TH1F *h1_cS10 			= new TH1F("h1_cS10",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
	TH1F *h1_cS11 			= new TH1F("h1_cS11",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
		  h1_cS1			->SetLineColor(1);
		  h1_cS10			->SetLineColor(2);
		  h1_cS11			->SetLineColor(3);
	TH1F *h1_S1top 			= new TH1F("h1_S1top",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1/5);
	TH1F *h1_S10top 		= new TH1F("h1_S10top",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1/5);
	TH1F *h1_S11top 		= new TH1F("h1_S11top",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1/5);
		  h1_S1top			->SetLineColor(1);
		  h1_S10top			->SetLineColor(2);
		  h1_S11top			->SetLineColor(3);
	TH1F *h1_S1bot 			= new TH1F("h1_S1bot",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
	TH1F *h1_S10bot 		= new TH1F("h1_S10bot",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
	TH1F *h1_S11bot 		= new TH1F("h1_S11bot",			DataSetName1, 	nbins_S1, 		min_S1, 		max_S1);
		  h1_S1bot			->SetLineColor(1);
		  h1_S10bot			->SetLineColor(2);
		  h1_S11bot			->SetLineColor(3);

	TH1F *h1_S2 			= new TH1F("h1_S2",				DataSetName1, 	nbins_S2, 		min_S2, 		max_S2);
	TH1F *h1_S20 			= new TH1F("h1_S20",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2);
	TH1F *h1_S21 			= new TH1F("h1_S21",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2);
		  h1_S2				->SetLineColor(1);
		  h1_S20			->SetLineColor(2);
		  h1_S21			->SetLineColor(3);
	TH1F *h1_S2top 			= new TH1F("h1_S2top",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2/2);
	TH1F *h1_S20top 		= new TH1F("h1_S20top",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2/2);
	TH1F *h1_S21top 		= new TH1F("h1_S21top",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2/2);
		  h1_S2top			->SetLineColor(1);
		  h1_S20top			->SetLineColor(2);
		  h1_S21top			->SetLineColor(3);
	TH1F *h1_S2bot 			= new TH1F("h1_S2bot",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2/2);
	TH1F *h1_S20bot 		= new TH1F("h1_S20bot",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2/2);
	TH1F *h1_S21bot 		= new TH1F("h1_S21bot",			DataSetName1, 	nbins_S2, 		min_S2, 		max_S2/2);
		  h1_S2bot			->SetLineColor(1);
		  h1_S20bot			->SetLineColor(2);
		  h1_S21bot			->SetLineColor(3);

	TH1F *h1_DTtop 			= new TH1F("h1_DTtop",			DataSetName1, 	nbins_dt, 		min_dt, 		max_dt);
	TH1F *h1_DTbot 			= new TH1F("h1_DTbot",			DataSetName1, 	nbins_dt, 		min_dt, 		max_dt);
		  h1_DTtop			->SetLineColor(2);
		  h1_DTbot			->SetLineColor(3);

	TH2F *h2_S2vsS1 		= new TH2F("h2_S2vsS1",			DataSetName1, 	nbins_S1/5, 	min_S1, 		max_S1, 		nbins_S2/5, 			min_S2, 		max_S2);
	TH2F *h2_S20vsS10 		= new TH2F("h2_S20vsS10",		DataSetName1, 	nbins_S1/5, 	min_S1, 		max_S1, 		nbins_S2/5, 			min_S2, 		max_S2);
	TH2F *h2_S21vsS11 		= new TH2F("h2_S21vsS11",		DataSetName1, 	nbins_S1/5, 	min_S1, 		max_S1/2.5, 	nbins_S2/5, 			min_S2, 		max_S2/2.5);
	TH2F *h2_S2TOPvsS1TOP 	= new TH2F("h2_S2TOPvsS1TOP",	DataSetName1, 	nbins_S1/5, 	min_S1, 		max_S1/5, 		nbins_S2/5, 			min_S2, 		max_S2/2);
	TH2F *h2_S2BOTvsS1BOT 	= new TH2F("h2_S2BOTvsS1BOT",	DataSetName1, 	nbins_S1/5, 	min_S1, 		max_S1, 		nbins_S2/5, 			min_S2, 		max_S2/2);
	TH2F *h2_S2TOPvsS1BOT 	= new TH2F("h2_S2TOPvsS1BOT",	DataSetName1, 	nbins_S1/5, 	min_S1, 		max_S1, 		nbins_S2/5, 			min_S2, 		max_S2/2);
	TH2F *h2_S2BOTvsS1TOP 	= new TH2F("h2_S2BOTvsS1TOP",	DataSetName1, 	nbins_S1/5, 	min_S1, 		max_S1/5, 		nbins_S2/5, 			min_S2, 		max_S2/2);

	TH2F *h2_S21vsS20 		= new TH2F("h2_S21vsS20",		DataSetName1, 	nbins_S2/5, 	min_S2, 		max_S2/5, 		nbins_S2/5, 			min_S2, 		max_S2/2);
	TH2F *h2_S21vsS20_top 	= new TH2F("h2_S21vsS20_top",	DataSetName1, 	nbins_S2/5, 	min_S2, 		max_S2/5, 		nbins_S2/5, 			min_S2, 		max_S2/2);
	TH2F *h2_S21vsS20_bot 	= new TH2F("h2_S21vsS20_bot",	DataSetName1, 	nbins_S2/5, 	min_S2, 		max_S2/5, 		nbins_S2/5, 			min_S2, 		max_S2/2);


	// S1vsS1
	TCanvas *c_S1vsS1 = new TCanvas("c_S1vsS1", "c_S1vsS1", 0, 0, 700, 500);
			 c_S1vsS1->SetFillColor(10);
    		 c_S1vsS1->SetLogz();
		T1	->Draw("S1totalPE1:S1totalPE>>h2_S1vsS1", cut_PlotAll,	"COLZ");
		h2_S1vsS1	-> GetXaxis() -> SetTitle("largest S1[0] [PE]");
		h2_S1vsS1	-> GetYaxis() -> SetTitle("S1[1] [PE]");
		h2_S1vsS1	-> GetXaxis() -> CenterTitle(true);
		h2_S1vsS1	-> GetYaxis() -> CenterTitle(true);
	c_S1vsS1->Update();

	// S1vsS1_scat
	TCanvas *c_S1vsS1_scat = new TCanvas("c_S1vsS1_scat", "c_S1vsS1_scat", 0, 0, 700, 500);
			 c_S1vsS1_scat->SetFillColor(10);
    		 //c_S1vsS1_scat->SetLogz();
		T1	->Draw("S1totalPE1:S1totalPE>>h2_S1vsS1_scat", cut_PlotAll,	"");
		h2_S1vsS1_scat	-> GetXaxis() -> SetTitle("largest S1[0] [PE]");
		h2_S1vsS1_scat	-> GetYaxis() -> SetTitle("S1[1] [PE]");
		h2_S1vsS1_scat	-> GetXaxis() -> CenterTitle(true);
		h2_S1vsS1_scat	-> GetYaxis() -> CenterTitle(true);
	c_S1vsS1_scat->Update();

	// S21vsS20
	TCanvas *c_S21vsS20 = new TCanvas("c_S21vsS20", "c_S21vsS20", 0, 0, 700, 500);
			 c_S21vsS20->SetFillColor(10);
    		 c_S21vsS20->SetLogz();
		T1	->Draw("S2totalPE1:S2totalPE>>h2_S21vsS20", cut_PlotAll,	"COLZ");
		h2_S21vsS20	-> GetXaxis() -> SetTitle("S2[0] [PE]");
		h2_S21vsS20	-> GetYaxis() -> SetTitle("S2[1] [PE]");
		h2_S21vsS20	-> GetXaxis() -> CenterTitle(true);
		h2_S21vsS20	-> GetYaxis() -> CenterTitle(true);
		h2_S21vsS20	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21vsS20	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21vsS20->Update();

	TCanvas *c_S21vsS20_top = new TCanvas("c_S21vsS20_top", "c_S21vsS20_top", 0, 0, 700, 500);
			 c_S21vsS20_top->SetFillColor(10);
    		 c_S21vsS20_top->SetLogz();
		T1	->Draw("S2topPE1:S2topPE>>h2_S21vsS20_top", cut_PlotAll,	"COLZ");
		h2_S21vsS20_top	-> GetXaxis() -> SetTitle("S2[0] top [PE]");
		h2_S21vsS20_top	-> GetYaxis() -> SetTitle("S2[1] top [PE]");
		h2_S21vsS20_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21vsS20_top	-> GetYaxis() -> CenterTitle(true);
		h2_S21vsS20_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21vsS20_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21vsS20_top->Update();

	TCanvas *c_S21vsS20_bot = new TCanvas("c_S21vsS20_bot", "c_S21vsS20_bot", 0, 0, 700, 500);
			 c_S21vsS20_bot->SetFillColor(10);
    		 c_S21vsS20_bot->SetLogz();
		T1	->Draw("S2botPE1:S2botPE>>h2_S21vsS20_bot", cut_PlotAll,	"COLZ");
		h2_S21vsS20_bot	-> GetXaxis() -> SetTitle("S2[0] bottom [PE]");
		h2_S21vsS20_bot	-> GetYaxis() -> SetTitle("S2[1] bottom [PE]");
		h2_S21vsS20_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21vsS20_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S21vsS20_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21vsS20_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21vsS20_bot->Update();

	// S1delay
	TCanvas *c_S1delay = new TCanvas("c_S1delay", "c_S1delay", 0, 0, 700, 500);
			 c_S1delay->SetFillColor(10);
    		 c_S1delay->SetLogy();
		T1	->Draw("(S1time1_top-S1time_top)>>h1_S1delayTop",	cut_PlotAll,	"");
		T1	->Draw("(S1time1_bot-S1time_bot)>>h1_S1delayBot",	cut_PlotAll,	"same");
		//h1_S1delay	-> Scale(ScalingFactor);
		h1_S1delayTop	-> GetXaxis() -> SetTitle("delayed time between S1 pulses [#mus]");
		h1_S1delayTop	-> GetYaxis() -> SetTitle("Counts");
		h1_S1delayTop	-> GetXaxis() -> CenterTitle(true);
		h1_S1delayTop	-> GetYaxis() -> CenterTitle(true);

	double fitS1delay_min = 1.2;
	double fitS1delay_max = 2.4;
	TF1 *fitS1delay = new TF1("fitS1delay", "expo", fitS1delay_min, fitS1delay_max);
		 fitS1delay->SetLineColor(2);
	h1_S1delayBot->Fit(fitS1delay,"R");
	fitS1delay->Draw("same");
	
	double lambda 		= fitS1delay->GetParameter(1);
	double lambdaEr 	= fitS1delay->GetParError(1);
	double HalfLife 	= -TMath::Log(2)/lambda *1e3; //ns 
	double MeanLifetime = TMath::Abs(1/lambda) *1e3;
	double uncertainty_frac = TMath::Abs(lambdaEr/lambda);
	double HalfLifeEr	= HalfLife * uncertainty_frac;
		
	cout <<"lambda   = "<< lambda 		<< endl;
	cout <<"halflife = "<< HalfLife 	<<" +- "<< HalfLifeEr <<" ns"<< endl;
	cout <<"meanlife = "<< MeanLifetime <<" ns"<< endl;

   	TPaveStats *ptstats = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   				ptstats->SetName("stats");
   				ptstats->SetBorderSize(0);
   				ptstats->SetTextAlign(12);
   				ptstats->SetFillStyle(0);
   				ptstats->SetFillColor(0);
   
   	char text1[256];
  	sprintf(text1, "T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife, HalfLifeEr);
   	TText *text = ptstats->AddText(text1);
   	ptstats->Draw();
	c_S1delay->Update();

	// DT
	TCanvas *c_DT = new TCanvas("c_DT", "c_DT", 0, 0, 700, 500);
			 c_DT->SetFillColor(10);
    		 c_DT->SetLogy();
		T1	->Draw("dt_top>>h1_DTtop",	cut_PlotAll,	"");
		T1	->Draw("dt_bot>>h1_DTbot",	cut_PlotAll,	"same");
		h1_DTtop	-> GetXaxis() -> SetTitle("drift time [#mus]");
		h1_DTtop	-> GetYaxis() -> SetTitle("Counts");
		h1_DTtop	-> GetXaxis() -> CenterTitle(true);
		h1_DTtop	-> GetYaxis() -> CenterTitle(true);
		double DTtop_max = h1_DTtop->GetMaximum();
		TLine *l_DTmin = new TLine(4, 0, 4, DTtop_max);
		TLine *l_DTmax = new TLine(16, 0, 16, DTtop_max);
			   l_DTmin->SetLineStyle(7);
			   l_DTmax->SetLineStyle(7);		
			   l_DTmin->Draw("same");
			   l_DTmax->Draw("same");
	c_DT->Update();



	// S1
/*	double fmin_S11 	= 90;
	double fmax_S11 	= 150;
	double fmin_S10 	= 230;
	double fmax_S10 	= 340;

	double fmin_S11top 	= 8;
	double fmax_S11top 	= 22;
	double fmin_S10top 	= 22;
	double fmax_S10top 	= 45;

	double fmin_S11bot 	= 75;
	double fmax_S11bot 	= 150;
	double fmin_S10bot 	= 200;
	double fmax_S10bot 	= 320;
*/
	double E_S11 = 9.4;
	double E_S10 = 32.1;

	double mean_S11, meanEr_S11, sigma_S11, sigmaEr_S11, res_S11, ly_S11, lyEr_S11;
	double mean_S10, meanEr_S10, sigma_S10, sigmaEr_S10, res_S10, ly_S10, lyEr_S10;

	double mean_S11top, meanEr_S11top, sigma_S11top, sigmaEr_S11top, res_S11top, ly_S11top, lyEr_S11top;
	double mean_S10top, meanEr_S10top, sigma_S10top, sigmaEr_S10top, res_S10top, ly_S10top, lyEr_S10top;

	double mean_S11bot, meanEr_S11bot, sigma_S11bot, sigmaEr_S11bot, res_S11bot, ly_S11bot, lyEr_S11bot;
	double mean_S10bot, meanEr_S10bot, sigma_S10bot, sigmaEr_S10bot, res_S10bot, ly_S10bot, lyEr_S10bot;


	TCanvas *c_S1 = new TCanvas("c_S1", "c_S1", 0, 0, 700, 500);
			 c_S1->SetFillColor(10);
    		 //c_S1->SetLogy();
		T1 ->Draw("S1totalPE1>>h1_S11",	cut_PlotAll,	"");
		T1 ->Draw("S1totalPE>>h1_S10",	cut_PlotAll,	"same");
		h1_S11	-> GetXaxis() -> SetTitle("S1 [PE]");
		h1_S11	-> GetYaxis() -> SetTitle("Counts");
		h1_S11	-> GetXaxis() -> CenterTitle(true);
		h1_S11	-> GetYaxis() -> CenterTitle(true);

		double Max_S10 			= h1_S10->GetMaximum();
		double MaxBin_S10 		= h1_S10->GetMaximumBin();
		double MaxBinCont_S10 	= h1_S10->GetBinContent(MaxBin_S10);
		double MaxBinVal_S10 	= h1_S10->GetXaxis()->GetBinCenter(MaxBin_S10); 
		double BinRms_S10		= h1_S10->GetRMS(1);		
		double fmin_S10 		= MaxBinVal_S10 - BinRms_S10;
		double fmax_S10 		= MaxBinVal_S10 + BinRms_S10*0.35;

		double Max_S11 			= h1_S11->GetMaximum();
		double MaxBin_S11 		= h1_S11->GetMaximumBin();
		double MaxBinCont_S11 	= h1_S11->GetBinContent(MaxBin_S11);
		double MaxBinVal_S11 	= h1_S11->GetXaxis()->GetBinCenter(MaxBin_S11); 
		double BinRms_S11		= h1_S11->GetRMS(1);		
		double fmin_S11 		= MaxBinVal_S11 - BinRms_S11;
		double fmax_S11 		= MaxBinVal_S11 + BinRms_S11*0.35;

		TF1 *f1_S10 = new TF1("f1_S10", 		"gaus", fmin_S10, fmax_S10);
		TF1 *f1_S11 = new TF1("f1_S11", 		"gaus", fmin_S11, fmax_S11);
			 f1_S10->SetLineColor(1);
			 f1_S11->SetLineColor(1);

		h1_S10->Fit(f1_S10, "R");	
		h1_S11->Fit(f1_S11, "R+");
	
		mean_S10 	= f1_S10->GetParameter(1);
		sigma_S10 	= f1_S10->GetParameter(2);
		res_S10 	= sigma_S10/mean_S10*100;
		ly_S10		= mean_S10/E_S10;
		lyEr_S10	= meanEr_S10/E_S10;

		mean_S11 	= f1_S11->GetParameter(1);
		sigma_S11 	= f1_S11->GetParameter(2);
		res_S11 	= sigma_S11/mean_S11*100;
		ly_S11		= mean_S11/E_S11;
		lyEr_S11	= meanEr_S11/E_S11;

		h1_S11->Draw("same");
		h1_S10->Draw("same");

		h1_S11	-> GetXaxis() -> SetTitle("S1 [PE]");
		h1_S11	-> GetYaxis() -> SetTitle("Counts");
		h1_S11	-> GetXaxis() -> CenterTitle(true);
		h1_S11	-> GetYaxis() -> CenterTitle(true);
		h1_S11	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_S11	-> GetYaxis() -> SetTitleOffset(1.25);
		//h1_S10	-> SetMaximum(h1_S11->GetMaximum());
	
		TPaveStats *ptstats_S11 = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S11->SetName("stats");
					ptstats_S11->SetBorderSize(0);
					ptstats_S11->SetTextAlign(12);
					ptstats_S11->SetFillStyle(0);
					ptstats_S11->SetFillColor(0);
			char text_S11_1[256];
			char text_S11_2[256];
			char text_S11_3[256];
	  		sprintf(text_S11_1, "S11 = (%1.0f #pm %1.0f) pe", 	mean_S11, sigma_S11);
	  		sprintf(text_S11_2, "LY = (%1.1f #pm %1.1f) pe/keV", 	ly_S11, lyEr_S11);
	  		sprintf(text_S11_3, "resolution = %1.1f", res_S11);
			TText *	text1_S11 = ptstats_S11->AddText(text_S11_1);
			TText *	text2_S11 = ptstats_S11->AddText(text_S11_2);
			TText *	text3_S11 = ptstats_S11->AddText(text_S11_3);
					text1_S11->SetTextColor(2);
					text2_S11->SetTextColor(2);
					text3_S11->SetTextColor(2);
	   		ptstats_S11->Draw();

		TPaveStats *ptstats_S10 = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_S10->SetName("stats");
					ptstats_S10->SetBorderSize(0);
					ptstats_S10->SetTextAlign(12);
					ptstats_S10->SetFillStyle(0);
					ptstats_S10->SetFillColor(0);
			char text_S10_1[256];
			char text_S10_2[256];
			char text_S10_3[256];
  			sprintf(text_S10_1, "S10 = (%1.0f #pm %1.0f) pe", 		mean_S10, sigma_S10);
  			sprintf(text_S10_2, "LY = (%1.1f #pm %1.1f) pe/keV", 	ly_S10, lyEr_S10);
  			sprintf(text_S10_3, "resolution = %1.1f", res_S10);
			TText *	text1_S10 = ptstats_S10->AddText(text_S10_1);
			TText *	text2_S10 = ptstats_S10->AddText(text_S10_2);
			TText *	text3_S10 = ptstats_S10->AddText(text_S10_3);
   			ptstats_S10->Draw();

	c_S1->Update();


	// cS1
/*	double fmin_cS11 	= 90;
	double fmax_cS11 	= 150;
	double fmin_cS10 	= 230;
	double fmax_cS10 	= 340;
*/
	double mean_cS11, meanEr_cS11, sigma_cS11, sigmaEr_cS11, res_cS11, ly_cS11, lyEr_cS11;
	double mean_cS10, meanEr_cS10, sigma_cS10, sigmaEr_cS10, res_cS10, ly_cS10, lyEr_cS10;

	TCanvas *c_cS1 = new TCanvas("c_cS1", "c_cS1", 0, 0, 700, 500);
			 c_cS1->SetFillColor(10);
    		 //c_S1->SetLogy();
		T1 ->Draw("cS1totalPE1>>h1_cS11",	cut_PlotAll,	"");
		T1 ->Draw("cS1totalPE>>h1_cS10",	cut_PlotAll,	"same");
		h1_cS11	-> GetXaxis() -> SetTitle("S1, dt-corrected [PE]");
		h1_cS11	-> GetYaxis() -> SetTitle("Counts");
		h1_cS11	-> GetXaxis() -> CenterTitle(true);
		h1_cS11	-> GetYaxis() -> CenterTitle(true);

		double Max_cS10 		= h1_cS10->GetMaximum();
		double MaxBin_cS10 		= h1_cS10->GetMaximumBin();
		double MaxBinCont_cS10 	= h1_cS10->GetBinContent(MaxBin_cS10);
		double MaxBinVal_cS10 	= h1_cS10->GetXaxis()->GetBinCenter(MaxBin_cS10); 
		double BinRms_cS10		= h1_cS10->GetRMS(1);		
		double fmin_cS10 		= MaxBinVal_cS10 - BinRms_cS10*1.5;
		double fmax_cS10 		= MaxBinVal_cS10 + BinRms_cS10;

		double Max_cS11 		= h1_cS11->GetMaximum();
		double MaxBin_cS11 		= h1_cS11->GetMaximumBin();
		double MaxBinCont_cS11 	= h1_cS11->GetBinContent(MaxBin_cS11);
		double MaxBinVal_cS11 	= h1_cS11->GetXaxis()->GetBinCenter(MaxBin_cS11); 
		double BinRms_cS11		= h1_cS11->GetRMS(1);		
		double fmin_cS11 		= MaxBinVal_cS11 - BinRms_cS11*1.5;
		double fmax_cS11 		= MaxBinVal_cS11 + BinRms_cS11*1.5;

		TF1 *f1_cS10 = new TF1("f1_cS10", 	"gaus", fmin_cS10, fmax_cS10);
		TF1 *f1_cS11 = new TF1("f1_cS11", 	"gaus", fmin_cS11, fmax_cS11);
			 f1_cS10->SetLineColor(1);
			 f1_cS11->SetLineColor(1);

		h1_cS10->Fit(f1_cS10, "R");	
		h1_cS11->Fit(f1_cS11, "R+");
	
		mean_cS10 	= f1_cS10->GetParameter(1);
		sigma_cS10 	= f1_cS10->GetParameter(2);
		res_cS10 	= sigma_cS10/mean_cS10*100;
		ly_cS10		= mean_cS10/E_S10;
		lyEr_cS10	= meanEr_cS10/E_S10;

		mean_cS11 	= f1_cS11->GetParameter(1);
		sigma_cS11 	= f1_cS11->GetParameter(2);
		res_cS11 	= sigma_cS11/mean_cS11*100;
		ly_cS11		= mean_cS11/E_S11;
		lyEr_cS11	= meanEr_cS11/E_S11;

		h1_cS11->Draw("same");
		h1_cS10->Draw("same");

		h1_cS11	-> GetXaxis() -> SetTitle("cS1 [PE]");
		h1_cS11	-> GetYaxis() -> SetTitle("Counts");
		h1_cS11	-> GetXaxis() -> CenterTitle(true);
		h1_cS11	-> GetYaxis() -> CenterTitle(true);
		h1_cS11	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_cS11	-> GetYaxis() -> SetTitleOffset(1.25);
		//h1_cS10	-> SetMaximum(h1_S11->GetMaximum());
	
		TPaveStats *ptstats_cS11 = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_cS11->SetName("stats");
					ptstats_cS11->SetBorderSize(0);
					ptstats_cS11->SetTextAlign(12);
					ptstats_cS11->SetFillStyle(0);
					ptstats_cS11->SetFillColor(0);
			char text_cS11_1[256];
			char text_cS11_2[256];
			char text_cS11_3[256];
	  		sprintf(text_cS11_1, "cS11 = (%1.0f #pm %1.0f) pe", 	mean_cS11, sigma_cS11);
	  		sprintf(text_cS11_2, "LY = (%1.1f #pm %1.1f) pe/keV", 	ly_cS11, lyEr_cS11);
	  		sprintf(text_cS11_3, "resolution = %1.1f", res_cS11);
			TText *	text1_cS11 = ptstats_cS11->AddText(text_cS11_1);
			TText *	text2_cS11 = ptstats_cS11->AddText(text_cS11_2);
			TText *	text3_cS11 = ptstats_cS11->AddText(text_cS11_3);
					text1_cS11->SetTextColor(2);
					text2_cS11->SetTextColor(2);
					text3_cS11->SetTextColor(2);
	   		ptstats_cS11->Draw();

		TPaveStats *ptstats_cS10 = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_cS10->SetName("stats");
					ptstats_cS10->SetBorderSize(0);
					ptstats_cS10->SetTextAlign(12);
					ptstats_cS10->SetFillStyle(0);
					ptstats_cS10->SetFillColor(0);
			char text_cS10_1[256];
			char text_cS10_2[256];
			char text_cS10_3[256];
  			sprintf(text_cS10_1, "cS10 = (%1.0f #pm %1.0f) pe", 	mean_cS10, sigma_cS10);
  			sprintf(text_cS10_2, "LY = (%1.1f #pm %1.1f) pe/keV", 	ly_cS10, lyEr_cS10);
  			sprintf(text_cS10_3, "resolution = %1.1f", res_cS10);
			TText *	text1_cS10 = ptstats_cS10->AddText(text_cS10_1);
			TText *	text2_cS10 = ptstats_cS10->AddText(text_cS10_2);
			TText *	text3_cS10 = ptstats_cS10->AddText(text_cS10_3);
   			ptstats_cS10->Draw();

	c_cS1->Update();


	// S1top
	TCanvas *c_S1top = new TCanvas("c_S1top", "c_S1top", 0, 0, 700, 500);
			 c_S1top->SetFillColor(10);
    		 //c_S1top->SetLogy();
		T1 ->Draw("S1topPE1>>h1_S11top",	cut_PlotAll,	"");
		T1 ->Draw("S1topPE>>h1_S10top",		cut_PlotAll,	"same");
		h1_S11top	-> GetXaxis() -> SetTitle("S1 top [PE]");
		h1_S11top	-> GetYaxis() -> SetTitle("Counts");
		h1_S11top	-> GetXaxis() -> CenterTitle(true);
		h1_S11top	-> GetYaxis() -> CenterTitle(true);

		double Max_S10top 			= h1_S10top->GetMaximum();
		double MaxBin_S10top 		= h1_S10top->GetMaximumBin();
		double MaxBinCont_S10top 	= h1_S10top->GetBinContent(MaxBin_S10);
		double MaxBinVal_S10top 	= h1_S10top->GetXaxis()->GetBinCenter(MaxBin_S10top); 
		double BinRms_S10top		= h1_S10top->GetRMS(1);		
		double fmin_S10top 			= MaxBinVal_S10top - BinRms_S10top;
		double fmax_S10top 			= MaxBinVal_S10top + BinRms_S10top*0.35;

		double Max_S11top 			= h1_S11top->GetMaximum();
		double MaxBin_S11top 		= h1_S11top->GetMaximumBin();
		double MaxBinCont_S11top 	= h1_S11top->GetBinContent(MaxBin_S11top);
		double MaxBinVal_S11top 	= h1_S11top->GetXaxis()->GetBinCenter(MaxBin_S11top); 
		double BinRms_S11top		= h1_S11top->GetRMS(1);		
		double fmin_S11top 			= MaxBinVal_S11top - BinRms_S11top;
		double fmax_S11top 			= MaxBinVal_S11top + BinRms_S11top*0.35;

		TF1 *f1_S10top = new TF1("f1_S10top", 	"gaus", fmin_S10top, fmax_S10top);
		TF1 *f1_S11top = new TF1("f1_S11top", 	"gaus", fmin_S11top, fmax_S11top);
			 f1_S10top->SetLineColor(1);
			 f1_S11top->SetLineColor(1);

		h1_S10top->Fit(f1_S10top, "R");	
		h1_S11top->Fit(f1_S11top, "R+");
	
		mean_S10top 	= f1_S10top->GetParameter(1);
		sigma_S10top 	= f1_S10top->GetParameter(2);
		res_S10top 		= sigma_S10top/mean_S10top*100;
		ly_S10top		= mean_S10top/E_S10;
		lyEr_S10top		= meanEr_S10top/E_S10;

		mean_S11top 	= f1_S11top->GetParameter(1);
		sigma_S11top 	= f1_S11top->GetParameter(2);
		res_S11top 		= sigma_S11top/mean_S11*100;
		ly_S11top		= mean_S11top/E_S11;
		lyEr_S11top		= meanEr_S11top/E_S11;

		h1_S11top->Draw("same");
		h1_S10top->Draw("same");

		h1_S11top	-> GetXaxis() -> SetTitle("S1 top [PE]");
		h1_S11top	-> GetYaxis() -> SetTitle("Counts");
		h1_S11top	-> GetXaxis() -> CenterTitle(true);
		h1_S11top	-> GetYaxis() -> CenterTitle(true);
		h1_S11top	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_S11top	-> GetYaxis() -> SetTitleOffset(1.25);
		//h1_S10	-> SetMaximum(h1_S11->GetMaximum());
	
		TPaveStats *ptstats_S11top = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S11top->SetName("stats");
					ptstats_S11top->SetBorderSize(0);
					ptstats_S11top->SetTextAlign(12);
					ptstats_S11top->SetFillStyle(0);
					ptstats_S11top->SetFillColor(0);
			char text_S11top_1[256];
			char text_S11top_2[256];
			char text_S11top_3[256];
	  		sprintf(text_S11top_1, "S11 = (%1.0f #pm %1.0f) pe", 	mean_S11top, sigma_S11top);
	  		sprintf(text_S11top_2, "LY = (%1.1f #pm %1.1f) pe/keV", 	ly_S11top, lyEr_S11top);
	  		sprintf(text_S11top_3, "resolution = %1.1f", res_S11top);
			TText *	text1_S11top = ptstats_S11top->AddText(text_S11top_1);
			TText *	text2_S11top = ptstats_S11top->AddText(text_S11top_2);
			TText *	text3_S11top = ptstats_S11top->AddText(text_S11top_3);
					text1_S11top->SetTextColor(2);
					text2_S11top->SetTextColor(2);
					text3_S11top->SetTextColor(2);
	   		ptstats_S11top->Draw();

		TPaveStats *ptstats_S10top = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_S10top->SetName("stats");
					ptstats_S10top->SetBorderSize(0);
					ptstats_S10top->SetTextAlign(12);
					ptstats_S10top->SetFillStyle(0);
					ptstats_S10top->SetFillColor(0);
			char text_S10top_1[256];
			char text_S10top_2[256];
			char text_S10top_3[256];
  			sprintf(text_S10top_1, "S10 = (%1.0f #pm %1.0f) pe", 	mean_S10top, sigma_S10top);
  			sprintf(text_S10top_2, "LY = (%1.1f #pm %1.1f) pe/keV", 	ly_S10top, lyEr_S10top);
  			sprintf(text_S10top_3, "resolution = %1.1f", res_S10);
			TText *	text1_S10top = ptstats_S10top->AddText(text_S10top_1);
			TText *	text2_S10top = ptstats_S10top->AddText(text_S10top_2);
			TText *	text3_S10top = ptstats_S10top->AddText(text_S10top_3);
   			ptstats_S10top->Draw();

	c_S1top->Update();


	// S1bot
	TCanvas *c_S1bot = new TCanvas("c_S1bot", "c_S1bot", 0, 0, 700, 500);
			 c_S1bot->SetFillColor(10);
    		 //c_S1bot->SetLogy();
		T1 ->Draw("S1botPE1>>h1_S11bot",	cut_PlotAll,	"");
		T1 ->Draw("S1botPE>>h1_S10bot",		cut_PlotAll,	"same");
		h1_S11bot	-> GetXaxis() -> SetTitle("S1 bottom [PE]");
		h1_S11bot	-> GetYaxis() -> SetTitle("Counts");
		h1_S11bot	-> GetXaxis() -> CenterTitle(true);
		h1_S11bot	-> GetYaxis() -> CenterTitle(true);

		double Max_S10bot 			= h1_S10bot->GetMaximum();
		double MaxBin_S10bot 		= h1_S10bot->GetMaximumBin();
		double MaxBinCont_S10bot 	= h1_S10bot->GetBinContent(MaxBin_S10bot);
		double MaxBinVal_S10bot 	= h1_S10bot->GetXaxis()->GetBinCenter(MaxBin_S10bot); 
		double BinRms_S10bot		= h1_S10bot->GetRMS(1);		
		double fmin_S10bot 			= MaxBinVal_S10bot - BinRms_S10bot;
		double fmax_S10bot 			= MaxBinVal_S10bot + BinRms_S10bot*0.35;

		double Max_S11bot 			= h1_S11->GetMaximum();
		double MaxBin_S11bot 		= h1_S11->GetMaximumBin();
		double MaxBinCont_S11bot 	= h1_S11->GetBinContent(MaxBin_S11);
		double MaxBinVal_S11bot 	= h1_S11->GetXaxis()->GetBinCenter(MaxBin_S11); 
		double BinRms_S11bot		= h1_S11->GetRMS(1);		
		double fmin_S11bot 			= MaxBinVal_S11 - BinRms_S11*1.5;
		double fmax_S11bot 			= MaxBinVal_S11 + BinRms_S11*0.35;

		TF1 *f1_S10bot = new TF1("f1_S10bot", 	"gaus", fmin_S10bot, fmax_S10bot);
		TF1 *f1_S11bot = new TF1("f1_S11bot", 	"gaus", fmin_S11bot, fmax_S11bot);
			 f1_S10bot->SetLineColor(1);
			 f1_S11bot->SetLineColor(1);

		h1_S10bot->Fit(f1_S10bot, "R");	
		h1_S11bot->Fit(f1_S11bot, "R+");
	
		mean_S10bot 	= f1_S10bot->GetParameter(1);
		sigma_S10bot 	= f1_S10bot->GetParameter(2);
		res_S10bot 		= sigma_S10bot/mean_S10bot*100;
		ly_S10bot		= mean_S10bot/E_S10;
		lyEr_S10bot		= meanEr_S10bot/E_S10;

		mean_S11bot 	= f1_S11bot->GetParameter(1);
		sigma_S11bot 	= f1_S11bot->GetParameter(2);
		res_S11bot 		= sigma_S11bot/mean_S11*100;
		ly_S11bot		= mean_S11bot/E_S11;
		lyEr_S11bot		= meanEr_S11bot/E_S11;

		h1_S11bot->Draw("same");
		h1_S10bot->Draw("same");

		h1_S11bot	-> GetXaxis() -> SetTitle("S1 bottom [PE]");
		h1_S11bot	-> GetYaxis() -> SetTitle("Counts");
		h1_S11bot	-> GetXaxis() -> CenterTitle(true);
		h1_S11bot	-> GetYaxis() -> CenterTitle(true);
		h1_S11bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_S11bot	-> GetYaxis() -> SetTitleOffset(1.25);
		//h1_S10	-> SetMaximum(h1_S11->GetMaximum());
	
		TPaveStats *ptstats_S11bot = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S11bot->SetName("stats");
					ptstats_S11bot->SetBorderSize(0);
					ptstats_S11bot->SetTextAlign(12);
					ptstats_S11bot->SetFillStyle(0);
					ptstats_S11bot->SetFillColor(0);
			char text_S11bot_1[256];
			char text_S11bot_2[256];
			char text_S11bot_3[256];
	  		sprintf(text_S11bot_1, "S11 = (%1.0f #pm %1.0f) pe", 	mean_S11bot, sigma_S11bot);
	  		sprintf(text_S11bot_2, "LY = (%1.1f #pm %1.1f) pe/keV", ly_S11bot, lyEr_S11bot);
	  		sprintf(text_S11bot_3, "resolution = %1.1f", res_S11bot);
			TText *	text1_S11bot = ptstats_S11bot->AddText(text_S11bot_1);
			TText *	text2_S11bot = ptstats_S11bot->AddText(text_S11bot_2);
			TText *	text3_S11bot = ptstats_S11bot->AddText(text_S11bot_3);
					text1_S11bot->SetTextColor(2);
					text2_S11bot->SetTextColor(2);
					text3_S11bot->SetTextColor(2);
	   		ptstats_S11bot->Draw();

		TPaveStats *ptstats_S10bot = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_S10bot->SetName("stats");
					ptstats_S10bot->SetBorderSize(0);
					ptstats_S10bot->SetTextAlign(12);
					ptstats_S10bot->SetFillStyle(0);
					ptstats_S10bot->SetFillColor(0);
			char text_S10bot_1[256];
			char text_S10bot_2[256];
			char text_S10bot_3[256];
  			sprintf(text_S10bot_1, "S10 = (%1.0f #pm %1.0f) pe", 	mean_S10bot, sigma_S10bot);
  			sprintf(text_S10bot_2, "LY = (%1.1f #pm %1.1f) pe/keV", ly_S10bot, lyEr_S10bot);
  			sprintf(text_S10bot_3, "resolution = %1.1f", res_S10);
			TText *	text1_S10bot = ptstats_S10bot->AddText(text_S10bot_1);
			TText *	text2_S10bot = ptstats_S10bot->AddText(text_S10bot_2);
			TText *	text3_S10bot = ptstats_S10bot->AddText(text_S10bot_3);
   			ptstats_S10bot->Draw();

	c_S1bot->Update();


	// S2
/*	double fmin_S20 	= 36e3;
	double fmax_S20 	= 60e3;

	double fmin_S20top 	= 15e3;
	double fmax_S20top 	= 25e3;

	double fmin_S20bot 	= 21e3;
	double fmax_S20bot 	= 34e3;
*/
	double E_S2 	= 41.5;
	double E_S20 	= 32.1;
	double E_S21 	= 9.4;

	double mean_S20, meanEr_S20, sigma_S20, sigmaEr_S20, res_S20, ly_S20, lyEr_S20;
	double mean_S20top, meanEr_S20top, sigma_S20top, sigmaEr_S20top, res_S20top, ly_S20top, lyEr_S20top;
	double mean_S20bot, meanEr_S20bot, sigma_S20bot, sigmaEr_S20bot, res_S20bot, ly_S20bot, lyEr_S20bot;

	double mean_S21, meanEr_S21, sigma_S21, sigmaEr_S21, res_S21, ly_S21, lyEr_S21;
	double mean_S21top, meanEr_S21top, sigma_S21top, sigmaEr_S21top, res_S21top, ly_S21top, lyEr_S21top;
	double mean_S21bot, meanEr_S21bot, sigma_S21bot, sigmaEr_S21bot, res_S21bot, ly_S21bot, lyEr_S21bot;


	TCanvas *c_S2 = new TCanvas("c_S2", "c_S2", 0, 0, 700, 500);
			 c_S2->SetFillColor(10);
    		 //c_S2->SetLogy();
		T1	->Draw("S2totalPE1>>h1_S21",	cut_PlotAll,	"");
		T1	->Draw("S2totalPE>>h1_S20",		cut_PlotAll,	"same");
		h1_S21	-> GetXaxis() -> SetTitle("S2 [PE]");
		h1_S21	-> GetYaxis() -> SetTitle("Counts");
		h1_S21	-> GetXaxis() -> CenterTitle(true);
		h1_S21	-> GetYaxis() -> CenterTitle(true);

		double Max_S20 			= h1_S20->GetMaximum();
		double MaxBin_S20 		= h1_S20->GetMaximumBin();
		double MaxBinCont_S20 	= h1_S20->GetBinContent(MaxBin_S20);
		double MaxBinVal_S20 	= h1_S20->GetXaxis()->GetBinCenter(MaxBin_S20); 
		double BinRms_S20		= h1_S20->GetRMS(1);		
		double fmin_S20 		= MaxBinVal_S20 - BinRms_S20;
		double fmax_S20 		= MaxBinVal_S20 + BinRms_S20*0.35;

		double Max_S21 			= h1_S21->GetMaximum();
		double MaxBin_S21 		= h1_S21->GetMaximumBin();
		double MaxBinCont_S21 	= h1_S21->GetBinContent(MaxBin_S21);
		double MaxBinVal_S21 	= h1_S21->GetXaxis()->GetBinCenter(MaxBin_S21); 
		double BinRms_S21		= h1_S21->GetRMS(1);		
		double fmin_S21 		= MaxBinVal_S21 - BinRms_S21;
		double fmax_S21 		= MaxBinVal_S21 + BinRms_S21*0.35;
	
		TF1 *f1_S20 	= new TF1("f1_S20", 	"gaus", fmin_S20, fmax_S20);
		TF1 *f1_S21 	= new TF1("f1_S21", 	"gaus", fmin_S21, fmax_S21);
			 f1_S20		->SetLineColor(1);
			 f1_S21		->SetLineColor(1);

		h1_S21->Fit(f1_S21, "R");
		h1_S20->Fit(f1_S20, "R+");
	
		mean_S20 	= f1_S20->GetParameter(1);
		sigma_S20 	= f1_S20->GetParameter(2);
		res_S20 	= sigma_S20/mean_S20*100;
		ly_S20		= mean_S20/E_S20;
		lyEr_S20	= meanEr_S20/E_S20;

		mean_S21 	= f1_S21->GetParameter(1);
		sigma_S21 	= f1_S21->GetParameter(2);
		res_S21 	= sigma_S21/mean_S21*100;
		ly_S21		= mean_S21/E_S21;
		lyEr_S21	= meanEr_S21/E_S21;

		h1_S21->Draw("same");
		h1_S20->Draw("same");

		TPaveStats *ptstats_S20 = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S20->SetName("stats");
					ptstats_S20->SetBorderSize(0);
					ptstats_S20->SetTextAlign(12);
					ptstats_S20->SetFillStyle(0);
					ptstats_S20->SetFillColor(0);
			char text_S20_1[256];
			char text_S20_2[256];
			char text_S20_3[256];
  			sprintf(text_S20_1, "S20 = (%1.0f #pm %1.0f) pe", 	mean_S20, sigma_S20);
  			sprintf(text_S20_2, "Y = (%1.1f #pm %1.1f) pe/keV", ly_S20, lyEr_S20);
  			sprintf(text_S20_3, "resolution = %1.1f", res_S20);
			TText *	text1_S20 = ptstats_S20->AddText(text_S20_1);
			TText *	text2_S20 = ptstats_S20->AddText(text_S20_2);
			TText *	text3_S20 = ptstats_S20->AddText(text_S20_3);
   			ptstats_S20->Draw();

		TPaveStats *ptstats_S21 = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_S21->SetName("stats");
					ptstats_S21->SetBorderSize(0);
					ptstats_S21->SetTextAlign(12);
					ptstats_S21->SetFillStyle(0);
					ptstats_S21->SetFillColor(0);
			char text_S21_1[256];
			char text_S21_2[256];
			char text_S21_3[256];
  			sprintf(text_S21_1, "S21 = (%1.0f #pm %1.0f) pe", 	mean_S21, sigma_S21);
  			sprintf(text_S21_2, "Y = (%1.1f #pm %1.1f) pe/keV", ly_S21, lyEr_S21);
  			sprintf(text_S21_3, "resolution = %1.1f", res_S21);
			TText *	text1_S21 = ptstats_S21->AddText(text_S21_1);
			TText *	text2_S21 = ptstats_S21->AddText(text_S21_2);
			TText *	text3_S21 = ptstats_S21->AddText(text_S21_3);
   			ptstats_S21->Draw();
	c_S2->Update();


	// S2top
	TCanvas *c_S2top = new TCanvas("c_S2top", "c_S2top", 0, 0, 700, 500);
			 c_S2top->SetFillColor(10);
    		 //c_S2top->SetLogy();
		T1	->Draw("S2topPE1>>h1_S21top",	cut_PlotAll,	"");
		T1	->Draw("S2topPE>>h1_S20top",	cut_PlotAll,	"same");
		h1_S21top	-> GetXaxis() -> SetTitle("S2 top [PE]");
		h1_S21top	-> GetYaxis() -> SetTitle("Counts");
		h1_S21top	-> GetXaxis() -> CenterTitle(true);
		h1_S21top	-> GetYaxis() -> CenterTitle(true);

		double Max_S20top 			= h1_S20top->GetMaximum();
		double MaxBin_S20top 		= h1_S20top->GetMaximumBin();
		double MaxBinCont_S20top 	= h1_S20top->GetBinContent(MaxBin_S20top);
		double MaxBinVal_S20top 	= h1_S20top->GetXaxis()->GetBinCenter(MaxBin_S20top); 
		double BinRms_S20top		= h1_S20top->GetRMS(1);
		double fmin_S20top 			= MaxBinVal_S20top - BinRms_S20top;
		double fmax_S20top 			= MaxBinVal_S20top + BinRms_S20top*0.35;

		double Max_S21top 			= h1_S21top->GetMaximum();
		double MaxBin_S21top 		= h1_S21top->GetMaximumBin();
		double MaxBinCont_S21top 	= h1_S21top->GetBinContent(MaxBin_S21top);
		double MaxBinVal_S21top 	= h1_S21top->GetXaxis()->GetBinCenter(MaxBin_S21top); 
		double BinRms_S21top		= h1_S21top->GetRMS(1);		
		double fmin_S21top 			= MaxBinVal_S21top - BinRms_S21top;
		double fmax_S21top 			= MaxBinVal_S21top + BinRms_S21top;

		TF1 *f1_S20top 	= new TF1("f1_S20top", 	"gaus", fmin_S20top, fmax_S20top);
		TF1 *f1_S21top 	= new TF1("f1_S21top", 	"gaus", fmin_S21top, fmax_S21top);
			 f1_S20top	->SetLineColor(1);
			 f1_S21top	->SetLineColor(1);

		h1_S21top->Fit(f1_S21top, "R");	
		h1_S20top->Fit(f1_S20top, "R+");	
	
		mean_S20top 	= f1_S20top->GetParameter(1);
		sigma_S20top 	= f1_S20top->GetParameter(2);
		res_S20top 		= sigma_S20top/mean_S20top*100;
		ly_S20top		= mean_S20top/E_S20;
		lyEr_S20top		= meanEr_S20top/E_S20;

		mean_S21top 	= f1_S21top->GetParameter(1);
		sigma_S21top 	= f1_S21top->GetParameter(2);
		res_S21top 		= sigma_S20top/mean_S21top*100;
		ly_S21top		= mean_S21top/E_S21;
		lyEr_S21top		= meanEr_S21top/E_S21;

		h1_S21top->Draw("same");
		h1_S20top->Draw("same");

		TPaveStats *ptstats_S20top = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S20top->SetName("stats");
					ptstats_S20top->SetBorderSize(0);
					ptstats_S20top->SetTextAlign(12);
					ptstats_S20top->SetFillStyle(0);
					ptstats_S20top->SetFillColor(0);
			char text_S20top_1[256];
			char text_S20top_2[256];
			char text_S20top_3[256];
  			sprintf(text_S20top_1, "S20 = (%1.0f #pm %1.0f) pe", 	mean_S20top, sigma_S20top);
  			sprintf(text_S20top_2, "Y = (%1.1f #pm %1.1f) pe/keV", ly_S20top, lyEr_S20top);
  			sprintf(text_S20top_3, "resolution = %1.1f", res_S20top);
			TText *	text1_S20top = ptstats_S20top->AddText(text_S20top_1);
			TText *	text2_S20top = ptstats_S20top->AddText(text_S20top_2);
			TText *	text3_S20top = ptstats_S20top->AddText(text_S20top_3);
   			ptstats_S20top->Draw();

		TPaveStats *ptstats_S21top = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_S21top->SetName("stats");
					ptstats_S21top->SetBorderSize(0);
					ptstats_S21top->SetTextAlign(12);
					ptstats_S21top->SetFillStyle(0);
					ptstats_S21top->SetFillColor(0);
			char text_S21top_1[256];
			char text_S21top_2[256];
			char text_S21top_3[256];
  			sprintf(text_S21top_1, "S21 = (%1.0f #pm %1.0f) pe", 	mean_S21top, sigma_S21top);
  			sprintf(text_S21top_2, "Y = (%1.1f #pm %1.1f) pe/keV", ly_S21top, lyEr_S21top);
  			sprintf(text_S21top_3, "resolution = %1.1f", res_S21top);
			TText *	text1_S21top = ptstats_S21top->AddText(text_S21top_1);
			TText *	text2_S21top = ptstats_S21top->AddText(text_S21top_2);
			TText *	text3_S21top = ptstats_S21top->AddText(text_S21top_3);
   			ptstats_S21top->Draw();
	c_S2top->Update();


	// S2bot
	TCanvas *c_S2bot = new TCanvas("c_S2bot", "c_S2bot", 0, 0, 700, 500);
			 c_S2bot->SetFillColor(10);
    		 //c_S2bot->SetLogy();
		T1	->Draw("S2totalPE1>>h1_S21bot",	cut_PlotAll,	"");
		T1	->Draw("S2botPE>>h1_S20bot",	cut_PlotAll,	"same");
		h1_S21bot	-> GetXaxis() -> SetTitle("S2 bottom [PE]");
		h1_S21bot	-> GetYaxis() -> SetTitle("Counts");
		h1_S21bot	-> GetXaxis() -> CenterTitle(true);
		h1_S21bot	-> GetYaxis() -> CenterTitle(true);

		double Max_S20bot 			= h1_S20bot->GetMaximum();
		double MaxBin_S20bot 		= h1_S20bot->GetMaximumBin();
		double MaxBinCont_S20bot 	= h1_S20bot->GetBinContent(MaxBin_S20bot);
		double MaxBinVal_S20bot 	= h1_S20bot->GetXaxis()->GetBinCenter(MaxBin_S20bot); 
		double BinRms_S20bot		= h1_S20bot->GetRMS(1);		
		double fmin_S20bot 			= MaxBinVal_S20bot - BinRms_S20bot;
		double fmax_S20bot 			= MaxBinVal_S20bot + BinRms_S20bot*0.35;

		double Max_S21bot 			= h1_S21bot->GetMaximum();
		double MaxBin_S21bot 		= h1_S21bot->GetMaximumBin();
		double MaxBinCont_S21bot 	= h1_S21bot->GetBinContent(MaxBin_S21bot);
		double MaxBinVal_S21bot 	= h1_S21bot->GetXaxis()->GetBinCenter(MaxBin_S21bot); 
		double BinRms_S21bot		= h1_S21bot->GetRMS(1);		
		double fmin_S21bot 			= MaxBinVal_S21bot - BinRms_S21bot;
		double fmax_S21bot 			= MaxBinVal_S21bot + BinRms_S21bot*0.35;

		TF1 *f1_S20bot 	= new TF1("f1_S20bot", 	"gaus", fmin_S20bot, fmax_S20bot);
		TF1 *f1_S21bot 	= new TF1("f1_S21bot", 	"gaus", fmin_S21bot, fmax_S21bot);
			 f1_S20bot	->SetLineColor(1);
			 f1_S21bot	->SetLineColor(1);

		h1_S21bot->Fit(f1_S21bot, "R");	
		h1_S20bot->Fit(f1_S20bot, "R+");	
	
		mean_S20bot 	= f1_S20bot->GetParameter(1);
		sigma_S20bot 	= f1_S20bot->GetParameter(2);
		res_S20bot 		= sigma_S20bot/mean_S20bot*100;
		ly_S20bot		= mean_S20bot/E_S20;
		lyEr_S20bot		= meanEr_S20bot/E_S20;

		mean_S21bot 	= f1_S21bot->GetParameter(1);
		sigma_S21bot 	= f1_S21bot->GetParameter(2);
		res_S21bot 		= sigma_S21bot/mean_S21bot*100;
		ly_S21bot		= mean_S21bot/E_S21;
		lyEr_S21bot		= meanEr_S21bot/E_S21;

		h1_S21bot->Draw("same");
		h1_S20bot->Draw("same");

		TPaveStats *ptstats_S20bot = new TPaveStats(0.5100575,0.7245763,0.8979885,0.8961864,"brNDC");
					ptstats_S20bot->SetName("stats");
					ptstats_S20bot->SetBorderSize(0);
					ptstats_S20bot->SetTextAlign(12);
					ptstats_S20bot->SetFillStyle(0);
					ptstats_S20bot->SetFillColor(0);
			char text_S20bot_1[256];
			char text_S20bot_2[256];
			char text_S20bot_3[256];
  			sprintf(text_S20bot_1, "S20 = (%1.0f #pm %1.0f) pe", 	mean_S20bot, sigma_S20bot);
  			sprintf(text_S20bot_2, "Y = (%1.1f #pm %1.1f) pe/keV", 	ly_S20bot, lyEr_S20bot);
  			sprintf(text_S20bot_3, "resolution = %1.1f", res_S20bot);
			TText *	text1_S20bot = ptstats_S20bot->AddText(text_S20bot_1);
			TText *	text2_S20bot = ptstats_S20bot->AddText(text_S20bot_2);
			TText *	text3_S20bot = ptstats_S20bot->AddText(text_S20bot_3);
   			ptstats_S20bot->Draw();

		TPaveStats *ptstats_S21bot = new TPaveStats(0.5114943,0.5423729,0.8994253,0.7139831,"brNDC");
					ptstats_S21bot->SetName("stats");
					ptstats_S21bot->SetBorderSize(0);
					ptstats_S21bot->SetTextAlign(12);
					ptstats_S21bot->SetFillStyle(0);
					ptstats_S21bot->SetFillColor(0);
			char text_S21bot_1[256];
			char text_S21bot_2[256];
			char text_S21bot_3[256];
  			sprintf(text_S21bot_1, "S21 = (%1.0f #pm %1.0f) pe", 	mean_S21bot, sigma_S21bot);
  			sprintf(text_S21bot_2, "Y = (%1.1f #pm %1.1f) pe/keV", 	ly_S21bot, lyEr_S21bot);
  			sprintf(text_S21bot_3, "resolution = %1.1f", res_S21bot);
			TText *	text1_S21bot = ptstats_S21bot->AddText(text_S21bot_1);
			TText *	text2_S21bot = ptstats_S21bot->AddText(text_S21bot_2);
			TText *	text3_S21bot = ptstats_S21bot->AddText(text_S21bot_3);
   			ptstats_S21bot->Draw();
	c_S2bot->Update();


	// S2vsS1
	TCanvas *c_S2vsS1 = new TCanvas("c_S2vsS1", "c_S2vsS1", 0, 0, 700, 500);
			 c_S2vsS1->SetFillColor(10);
    		 c_S2vsS1->SetLogz();
		T1	->Draw("S2totalPE:(S1totalPE+S1totalPE1)>>h2_S2vsS1",	cut_PlotAll,	"COLZ");
		h2_S2vsS1	-> GetXaxis() -> SetTitle("S1[0+1] total [PE]");
		h2_S2vsS1	-> GetYaxis() -> SetTitle("S2[0] total [PE]");
		h2_S2vsS1	-> GetZaxis() -> SetTitle("Counts");
		h2_S2vsS1	-> GetXaxis() -> CenterTitle(true);
		h2_S2vsS1	-> GetYaxis() -> CenterTitle(true);
		h2_S2vsS1	-> GetZaxis() -> CenterTitle(true);
		h2_S2vsS1	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2vsS1	-> GetYaxis() -> SetTitleOffset(1.30);
		h2_S2vsS1	-> GetZaxis() -> SetTitleOffset(1.25);
	c_S2vsS1->Update();

	// S20vsS10
	TCanvas *c_S20vsS10 = new TCanvas("c_S20vsS10", "c_S20vsS10", 0, 0, 700, 500);
			 c_S20vsS10->SetFillColor(10);
    		 c_S20vsS10->SetLogz();
		T1	->Draw("S2totalPE:cS1totalPE>>h2_S20vsS10",	cut_PlotAll,	"COLZ");
		h2_S20vsS10	-> GetXaxis() -> SetTitle("S1[0] total, dt-corrected [PE]");
		h2_S20vsS10	-> GetYaxis() -> SetTitle("S2[0] total [PE]");
		h2_S20vsS10	-> GetZaxis() -> SetTitle("Counts");
		h2_S20vsS10	-> GetXaxis() -> CenterTitle(true);
		h2_S20vsS10	-> GetYaxis() -> CenterTitle(true);
		h2_S20vsS10	-> GetZaxis() -> CenterTitle(true);
		h2_S20vsS10	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S20vsS10	-> GetYaxis() -> SetTitleOffset(1.30);
		h2_S20vsS10	-> GetZaxis() -> SetTitleOffset(1.25);
	c_S20vsS10->Update();

	// S21vsS11
	TCanvas *c_S21vsS11 = new TCanvas("c_S21vsS11", "c_S21vsS11", 0, 0, 700, 500);
			 c_S21vsS11->SetFillColor(10);
    		 c_S21vsS11->SetLogz();
		T1	->Draw("S2totalPE1:cS1totalPE1>>h2_S21vsS11",	cut_PlotAll,	"COLZ");
		h2_S21vsS11	-> GetXaxis() -> SetTitle("S1[1] total, dt-corrected [PE]");
		h2_S21vsS11	-> GetYaxis() -> SetTitle("S2[1] total [PE]");
		h2_S21vsS11	-> GetZaxis() -> SetTitle("Counts");
		h2_S21vsS11	-> GetXaxis() -> CenterTitle(true);
		h2_S21vsS11	-> GetYaxis() -> CenterTitle(true);
		h2_S21vsS11	-> GetZaxis() -> CenterTitle(true);
		h2_S21vsS11	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21vsS11	-> GetYaxis() -> SetTitleOffset(1.30);
		h2_S21vsS11	-> GetZaxis() -> SetTitleOffset(1.25);
	c_S21vsS11->Update();

	// S2TOPvsS1TOP
	TCanvas *c_S2TOPvsS1TOP = new TCanvas("c_S2TOPvsS1TOP", "c_S2TOPvsS1TOP", 0, 0, 700, 500);
			 c_S2TOPvsS1TOP->SetFillColor(10);
    		 c_S2TOPvsS1TOP->SetLogz();
		T1	->Draw("S2topPE:(S1topPE+S1topPE1)>>h2_S2TOPvsS1TOP",	cut_PlotAll,	"COLZ");
		h2_S2TOPvsS1TOP	-> GetXaxis() -> SetTitle("S1[0+1] top [PE]");
		h2_S2TOPvsS1TOP	-> GetYaxis() -> SetTitle("S2[0] top [PE]");
		h2_S2TOPvsS1TOP	-> GetZaxis() -> SetTitle("Counts");
		h2_S2TOPvsS1TOP	-> GetXaxis() -> CenterTitle(true);
		h2_S2TOPvsS1TOP	-> GetYaxis() -> CenterTitle(true);
		h2_S2TOPvsS1TOP	-> GetZaxis() -> CenterTitle(true);
		h2_S2TOPvsS1TOP	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2TOPvsS1TOP	-> GetYaxis() -> SetTitleOffset(1.30);
		h2_S2TOPvsS1TOP	-> GetZaxis() -> SetTitleOffset(1.25);
	c_S2TOPvsS1TOP->Update();

	// S2BOTvsS1BOT
	TCanvas *c_S2BOTvsS1BOT = new TCanvas("c_S2BOTvsS1BOT", "c_S2BOTvsS1BOT", 0, 0, 700, 500);
			 c_S2BOTvsS1BOT->SetFillColor(10);
    		 c_S2BOTvsS1BOT->SetLogz();
		T1	->Draw("S2botPE:(S1botPE+S1botPE1)>>h2_S2BOTvsS1BOT",	cut_PlotAll,	"COLZ");
		h2_S2BOTvsS1BOT	-> GetXaxis() -> SetTitle("S1[0+1] bottom [PE]");
		h2_S2BOTvsS1BOT	-> GetYaxis() -> SetTitle("S2[0] bottom [PE]");
		h2_S2BOTvsS1BOT	-> GetZaxis() -> SetTitle("Counts");
		h2_S2BOTvsS1BOT	-> GetXaxis() -> CenterTitle(true);
		h2_S2BOTvsS1BOT	-> GetYaxis() -> CenterTitle(true);
		h2_S2BOTvsS1BOT	-> GetZaxis() -> CenterTitle(true);
		h2_S2BOTvsS1BOT	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2BOTvsS1BOT	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2BOTvsS1BOT	-> GetZaxis() -> SetTitleOffset(1.25);
	c_S2BOTvsS1BOT->Update();
	
	// S2TOPvsS1BOT
	TCanvas *c_S2TOPvsS1BOT = new TCanvas("c_S2TOPvsS1BOT", "c_S2TOPvsS1BOT", 0, 0, 700, 500);
			 c_S2TOPvsS1BOT->SetFillColor(10);
    		 c_S2TOPvsS1BOT->SetLogz();
		T1	->Draw("S2topPE:(S1botPE+S1botPE1)>>h2_S2TOPvsS1BOT",	cut_PlotAll,	"COLZ");
		h2_S2TOPvsS1BOT	-> GetXaxis() -> SetTitle("S1[0+1] bottom [PE]");
		h2_S2TOPvsS1BOT	-> GetYaxis() -> SetTitle("S2[0] top [PE]");
		h2_S2TOPvsS1BOT	-> GetZaxis() -> SetTitle("Counts");
		h2_S2TOPvsS1BOT	-> GetXaxis() -> CenterTitle(true);
		h2_S2TOPvsS1BOT	-> GetYaxis() -> CenterTitle(true);
		h2_S2TOPvsS1BOT	-> GetZaxis() -> CenterTitle(true);
		h2_S2BOTvsS1TOP	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2BOTvsS1TOP	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2BOTvsS1TOP	-> GetZaxis() -> SetTitleOffset(1.25);
	c_S2TOPvsS1BOT->Update();

	// S2BOTvsS1TOP
	TCanvas *c_S2BOTvsS1TOP = new TCanvas("c_S2BOTvsS1TOP", "c_S2BOTvsS1TOP", 0, 0, 700, 500);
			 c_S2BOTvsS1TOP->SetFillColor(10);
    		 c_S2BOTvsS1TOP->SetLogz();
		T1	->Draw("S2botPE:(S1topPE+S1topPE1)>>h2_S2BOTvsS1TOP",	cut_PlotAll,	"COLZ");
		h2_S2BOTvsS1TOP	-> GetXaxis() -> SetTitle("S1[0+1] top [PE]");
		h2_S2BOTvsS1TOP	-> GetYaxis() -> SetTitle("S2[0] bottom [PE]");
		h2_S2BOTvsS1TOP	-> GetZaxis() -> SetTitle("Counts");
		h2_S2BOTvsS1TOP	-> GetXaxis() -> CenterTitle(true);
		h2_S2BOTvsS1TOP	-> GetYaxis() -> CenterTitle(true);
		h2_S2BOTvsS1TOP	-> GetZaxis() -> CenterTitle(true);
		h2_S2BOTvsS1TOP	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2BOTvsS1TOP	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2BOTvsS1TOP	-> GetZaxis() -> SetTitleOffset(1.25);
	c_S2BOTvsS1TOP->Update();


	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_Kr[500];
	sprintf(outFolder_Kr, "%s/Kr", outFolder_dataset);
	char mkdir_outFolder_Kr[500];
	sprintf(mkdir_outFolder_Kr, ".mkdir %s", outFolder_Kr);
	gROOT->ProcessLine(mkdir_outFolder_Kr);

	char char_S1vsS1[500];
	char char_S1vsS1_c[500];
	char char_S1vsS1_scat[500];
	char char_S1vsS1_scat_c[500];
	char char_S21vsS20[500];
	char char_S21vsS20_top[500];
	char char_S21vsS20_bot[500];
	char char_S1delay[500];
	char char_S1delay_c[500];
	char char_DT[500];
	char char_DT_c[500];
	char char_S1[500];
	char char_S1_c[500];
	char char_cS1[500];
	char char_cS1_c[500];
	char char_S1top[500];
	char char_S1top_c[500];
	char char_S1bot[500];
	char char_S1bot_c[500];
	char char_S2[500];
	char char_S2_c[500];
	char char_S2top[500];
	char char_S2top_c[500];
	char char_S2bot[500];
	char char_S2bot_c[500];
	char char_S2vsS1[500];
	char char_S2vsS1_c[500];
	char char_S20vsS10[500];
	char char_S20vsS10_c[500];
	char char_S21vsS11[500];
	char char_S21vsS11_c[500];
	char char_S2TOPvsS1TOP[500];
	char char_S2TOPvsS1TOP_c[500];
	char char_S2BOTvsS1BOT[500];
	char char_S2BOTvsS1BOT_c[500];
	char char_S2TOPvsS1BOT[500];
	char char_S2TOPvsS1BOT_c[500];
	char char_S2BOTvsS1TOP[500];
	char char_S2BOTvsS1TOP_c[500];

	sprintf(char_S1vsS1,			"%s/%s_S1vsS1_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S1vsS1_c,			"%s/%s_S1vsS1_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1vsS1_scat,		"%s/%s_S1vsS1_scat_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S1vsS1_scat_c,		"%s/%s_S1vsS1_scat_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S21vsS20,			"%s/%s_S21vsS20_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S21vsS20_top,		"%s/%s_S21vsS20_top_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S21vsS20_bot,		"%s/%s_S21vsS20_bot_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots);

	sprintf(char_S1delay,			"%s/%s_S1delay_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S1delay_c,			"%s/%s_S1delay_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_DT,				"%s/%s_DT_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_DT_c,				"%s/%s_DT_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1,				"%s/%s_S1_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S1_c,				"%s/%s_S1_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_cS1,				"%s/%s_cS1_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_cS1_c,				"%s/%s_cS1_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1top,				"%s/%s_S1top_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S1top_c,			"%s/%s_S1top_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1bot,				"%s/%s_S1bot_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S1bot_c,			"%s/%s_S1bot_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2,				"%s/%s_S2_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2_c,				"%s/%s_S2_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2top,				"%s/%s_S2top_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2top_c,			"%s/%s_S2top_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2bot,				"%s/%s_S2bot_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2bot_c,			"%s/%s_S2bot_%s%s",			outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2vsS1,			"%s/%s_S2vsS1_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2vsS1_c,			"%s/%s_S2vsS1_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S20vsS10,			"%s/%s_S20vsS10_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S20vsS10_c,		"%s/%s_S20vsS10_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S21vsS11,			"%s/%s_S21vsS11_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S21vsS11_c,		"%s/%s_S21vsS11_%s%s",		outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2TOPvsS1TOP,		"%s/%s_S2TOPvsS1TOP_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2TOPvsS1TOP_c,	"%s/%s_S2TOPvsS1TOP_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2BOTvsS1BOT,		"%s/%s_S2BOTvsS1BOT_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2BOTvsS1BOT_c,	"%s/%s_S2BOTvsS1BOT_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2TOPvsS1BOT,		"%s/%s_S2TOPvsS1BOT_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2TOPvsS1BOT_c,	"%s/%s_S2TOPvsS1BOT_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2BOTvsS1TOP,		"%s/%s_S2BOTvsS1TOP_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots);
	sprintf(char_S2BOTvsS1TOP_c,	"%s/%s_S2BOTvsS1TOP_%s%s",	outFolder_Kr, DataSet1, CutName, extensionPlots_C);


	c_S1vsS1		->SaveAs(char_S1vsS1);
	c_S1vsS1		->SaveAs(char_S1vsS1_c);

	c_S1vsS1_scat	->SaveAs(char_S1vsS1_scat);
	c_S1vsS1_scat	->SaveAs(char_S1vsS1_scat_c);

	c_S21vsS20		->SaveAs(char_S21vsS20);
	c_S21vsS20_top	->SaveAs(char_S21vsS20_top);
	c_S21vsS20_bot	->SaveAs(char_S21vsS20_bot);

	c_S1delay		->SaveAs(char_S1delay);
	c_S1delay		->SaveAs(char_S1delay_c);

	c_DT			->SaveAs(char_DT);
	c_DT			->SaveAs(char_DT_c);

	c_cS1			->SaveAs(char_cS1);
	c_cS1			->SaveAs(char_cS1_c);

	c_S1top			->SaveAs(char_S1top);
	c_S1top			->SaveAs(char_S1top_c);

	c_S1bot			->SaveAs(char_S1bot);
	c_S1bot			->SaveAs(char_S1bot_c);

	c_S2			->SaveAs(char_S2);
	c_S2			->SaveAs(char_S2_c);

	c_S2top			->SaveAs(char_S2top);
	c_S2top			->SaveAs(char_S2top_c);

	c_S2bot			->SaveAs(char_S2bot);
	c_S2bot			->SaveAs(char_S2bot_c);

	c_S2vsS1		->SaveAs(char_S2vsS1);
	c_S2vsS1		->SaveAs(char_S2vsS1_c);

	c_S20vsS10		->SaveAs(char_S20vsS10);
	c_S20vsS10		->SaveAs(char_S20vsS10_c);

	c_S21vsS11		->SaveAs(char_S21vsS11);
	c_S21vsS11		->SaveAs(char_S21vsS11_c);

	c_S2TOPvsS1TOP	->SaveAs(char_S2TOPvsS1TOP);
	c_S2TOPvsS1TOP	->SaveAs(char_S2TOPvsS1TOP_c);

	c_S2BOTvsS1BOT	->SaveAs(char_S2BOTvsS1BOT);
	c_S2BOTvsS1BOT	->SaveAs(char_S2BOTvsS1BOT_c);

	c_S2TOPvsS1BOT	->SaveAs(char_S2TOPvsS1BOT);
	c_S2TOPvsS1BOT	->SaveAs(char_S2TOPvsS1BOT_c);

	c_S2BOTvsS1TOP	->SaveAs(char_S2BOTvsS1TOP);
	c_S2BOTvsS1TOP	->SaveAs(char_S2BOTvsS1TOP_c);

