	int nbins_S1delay		= 250;
	double min_S1delay		= 0.;
	double max_S1delay		= 5.;

	int nbins_S2delay		= 250;
	double min_S2delay		= 0.;
	double max_S2delay		= 5.;

	int nbins_S1S2delay		= 200;
	double min_S1S2delay	= -0.5;
	double max_S1S2delay	= 0.5;

	TH2F *h2_S2DELAYvsS1DELAY_bot 	= new TH2F("h2_S2DELAYvsS1DELAY_bot", 	"", nbins_S1delay, min_S1delay, max_S1delay, nbins_S2delay, min_S2delay, max_S2delay);
	TH2F *h2_S2DELAYvsS1DELAY_top 	= new TH2F("h2_S2DELAYvsS1DELAY_top", 	"", nbins_S1delay, min_S1delay, max_S1delay, nbins_S2delay, min_S2delay, max_S2delay);
	TH2F *h2_S1DELAYvsS1DELAY 		= new TH2F("h2_S1DELAYvsS1DELAY", 		"", nbins_S1delay, min_S1delay, max_S1delay, nbins_S1delay, min_S1delay, max_S1delay);
	TH2F *h2_S2DELAYvsS2DELAY 		= new TH2F("h2_S2DELAYvsS2DELAY", 		"", nbins_S1delay, min_S2delay, max_S2delay, nbins_S2delay, min_S2delay, max_S2delay);

	TH1F *h1_S1S2DELAY_bot = new TH1F("h1_S1S2DELAY_bot", "", nbins_S1S2delay, min_S1S2delay, max_S1S2delay);
		  h1_S1S2DELAY_bot ->SetLineColor(4);
	TH1F *h1_S1S2DELAY_top = new TH1F("h1_S1S2DELAY_top", "", nbins_S1S2delay, min_S1S2delay, max_S1S2delay);
		  h1_S1S2DELAY_top ->SetLineColor(4);

	int nbins_S1delayPlot 	= 151;
	int min_S1delayPlot 	= 0;
	int max_S1delayPlot 	= 3;	
	TH1F *h1_S1DELAY_1s = new TH1F("h1_S1DELAY_1s", "", nbins_S1delayPlot, min_S1delayPlot, max_S1delayPlot);
	TH1F *h1_S1DELAY_2s = new TH1F("h1_S1DELAY_2s", "", nbins_S1delayPlot, min_S1delayPlot, max_S1delayPlot);
	TH1F *h1_S1DELAY_3s = new TH1F("h1_S1DELAY_3s", "", nbins_S1delayPlot, min_S1delayPlot, max_S1delayPlot);
	TH1F *h1_S1DELAY_5s = new TH1F("h1_S1DELAY_5s", "", nbins_S1delayPlot, min_S1delayPlot, max_S1delayPlot);
		  h1_S1DELAY_5s ->SetLineColor(1);
		  h1_S1DELAY_3s ->SetLineColor(4);
		  h1_S1DELAY_2s ->SetLineColor(2);
		  h1_S1DELAY_1s ->SetLineColor(3);

	int nbins_S2delayPlot 	= 151;
	int min_S2delayPlot 	= 0;
	int max_S2delayPlot 	= 3;	
	TH1F *h1_S2DELAY_1s = new TH1F("h1_S2DELAY_1s", "", nbins_S2delayPlot, min_S2delayPlot, max_S2delayPlot);
	TH1F *h1_S2DELAY_2s = new TH1F("h1_S2DELAY_2s", "", nbins_S2delayPlot, min_S2delayPlot, max_S2delayPlot);
	TH1F *h1_S2DELAY_3s = new TH1F("h1_S2DELAY_3s", "", nbins_S2delayPlot, min_S2delayPlot, max_S2delayPlot);
	TH1F *h1_S2DELAY_5s = new TH1F("h1_S2DELAY_5s", "", nbins_S2delayPlot, min_S2delayPlot, max_S2delayPlot);
		  h1_S2DELAY_5s ->SetLineColor(1);
		  h1_S2DELAY_3s ->SetLineColor(4);
		  h1_S2DELAY_2s ->SetLineColor(2);
		  h1_S2DELAY_1s ->SetLineColor(3);

	int canX = 700;
	int canY = 500;

	TCanvas *c_S2DELAYvsS1DELAY_bot = new TCanvas("c_S2DELAYvsS1DELAY_bot", "c_S2DELAYvsS1DELAY_bot", 0, 0, canX, canY);
			 c_S2DELAYvsS1DELAY_bot->SetFillColor(10);
    		 c_S2DELAYvsS1DELAY_bot->SetLogz();
		T1 ->Draw("S2delay_bot:S1delay_bot>>h2_S2DELAYvsS1DELAY_bot",	cut_all,	"colz");
		h2_S2DELAYvsS1DELAY_bot	-> GetXaxis() -> SetTitle("S1 delay, bottom [#mus]");
		h2_S2DELAYvsS1DELAY_bot	-> GetYaxis() -> SetTitle("S2 delay, bottom [#mus]");
		h2_S2DELAYvsS1DELAY_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S2DELAYvsS1DELAY_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S2DELAYvsS1DELAY_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2DELAYvsS1DELAY_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2DELAYvsS1DELAY_bot->Update();

	TCanvas *c_S2DELAYvsS1DELAY_top = new TCanvas("c_S2DELAYvsS1DELAY_top", "c_S2DELAYvsS1DELAY_top", 0, 0, canX, canY);
			 c_S2DELAYvsS1DELAY_top->SetFillColor(10);
    		 c_S2DELAYvsS1DELAY_top->SetLogz();
		T1 ->Draw("S2delay_top:S1delay_top>>h2_S2DELAYvsS1DELAY_top",	cut_all,	"colz");
		h2_S2DELAYvsS1DELAY_top	-> GetXaxis() -> SetTitle("S1 delay, top [#mus]");
		h2_S2DELAYvsS1DELAY_top	-> GetYaxis() -> SetTitle("S2 delay, top [#mus]");
		h2_S2DELAYvsS1DELAY_top	-> GetXaxis() -> CenterTitle(true);
		h2_S2DELAYvsS1DELAY_top	-> GetYaxis() -> CenterTitle(true);
		h2_S2DELAYvsS1DELAY_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2DELAYvsS1DELAY_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2DELAYvsS1DELAY_top->Update();

	TCanvas *c_S1DELAYvsS1DELAY = new TCanvas("c_S1DELAYvsS1DELAY", "c_S1DELAYvsS1DELAY", 0, 0, canX, canY);
			 c_S1DELAYvsS1DELAY->SetFillColor(10);
    		 c_S1DELAYvsS1DELAY->SetLogz();
		T1 ->Draw("S1delay_top:S1delay_bot>>h2_S1DELAYvsS1DELAY",	cut_all,	"colz");
		h2_S1DELAYvsS1DELAY	-> GetXaxis() -> SetTitle("S1 delay, bottom [#mus]");
		h2_S1DELAYvsS1DELAY	-> GetYaxis() -> SetTitle("S1 delay, top [#mus]");
		h2_S1DELAYvsS1DELAY	-> GetXaxis() -> CenterTitle(true);
		h2_S1DELAYvsS1DELAY	-> GetYaxis() -> CenterTitle(true);
		h2_S1DELAYvsS1DELAY	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S1DELAYvsS1DELAY	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S1DELAYvsS1DELAY->Update();

	TCanvas *c_S2DELAYvsS2DELAY = new TCanvas("c_S2DELAYvsS1DELAY", "c_S2DELAYvsS1DELAY", 0, 0, canX, canY);
			 c_S2DELAYvsS2DELAY->SetFillColor(10);
    		 c_S2DELAYvsS2DELAY->SetLogz();
		T1 ->Draw("S2delay_top:S2delay_bot>>h2_S2DELAYvsS2DELAY",	cut_all,	"colz");
		h2_S2DELAYvsS2DELAY	-> GetXaxis() -> SetTitle("S2 delay, bottom [#mus]");
		h2_S2DELAYvsS2DELAY	-> GetYaxis() -> SetTitle("S2 delay, top [#mus]");
		h2_S2DELAYvsS2DELAY	-> GetXaxis() -> CenterTitle(true);
		h2_S2DELAYvsS2DELAY	-> GetYaxis() -> CenterTitle(true);
		h2_S2DELAYvsS2DELAY	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2DELAYvsS2DELAY	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2DELAYvsS2DELAY->Update();

	TCanvas *c_S1S2DELAY_bot = new TCanvas("c_S1S2DELAY_bot", "c_S1S2DELAY_bot", 0, 0, canX, canY);
			 c_S1S2DELAY_bot->SetFillColor(10);
    		 c_S1S2DELAY_bot->SetLogy();
		T1 ->Draw("(S1delay_bot-S2delay_bot)>>h1_S1S2DELAY_bot",	cut_all,	"");
		h1_S1S2DELAY_bot	-> GetXaxis() -> SetTitle("S1 delay - S2 delay [#mus]");
		h1_S1S2DELAY_bot	-> GetYaxis() -> SetTitle("Counts");
		h1_S1S2DELAY_bot	-> GetXaxis() -> CenterTitle(true);
		h1_S1S2DELAY_bot	-> GetYaxis() -> CenterTitle(true);
	c_S1S2DELAY_bot->Update();

	TCanvas *c_S1S2DELAY_top = new TCanvas("c_S1S2DELAY_top", "c_S1S2DELAY_top", 0, 0, canX, canY);
			 c_S1S2DELAY_top->SetFillColor(10);
    		 c_S1S2DELAY_top->SetLogy();
		T1 ->Draw("(S1delay_top-S2delay_top)>>h1_S1S2DELAY_top",	cut_all,	"");
		h1_S1S2DELAY_top	-> GetXaxis() -> SetTitle("S1 delay - S2 delay [#mus]");
		h1_S1S2DELAY_top	-> GetYaxis() -> SetTitle("Counts");
		h1_S1S2DELAY_top	-> GetXaxis() -> CenterTitle(true);
		h1_S1S2DELAY_top	-> GetYaxis() -> CenterTitle(true);
	c_S1S2DELAY_top->Update();



	// COMPUTE CUT RANGES
	c_S1S2DELAY_top ->cd();
		TF1 *fit_S1S2DELAY_top = new TF1("fit1_S1S2DELAY_top","gaus", -0.025, 0.03);
			 fit_S1S2DELAY_top ->SetLineColor(2);
		h1_S1S2DELAY_top ->Fit(fit_S1S2DELAY_top,"R");
		double fitOffset_S1S2DELAY_top 	= fit_S1S2DELAY_top->GetParameter(0);
		double fitMean_S1S2DELAY_top 	= fit_S1S2DELAY_top->GetParameter(1);
		double fitMeanEr_S1S2DELAY_top 	= fit_S1S2DELAY_top->GetParError(1);
		double fitSigma_S1S2DELAY_top 	= fit_S1S2DELAY_top->GetParameter(2);
		double fitSigmaEr_S1S2DELAY_top = fit_S1S2DELAY_top->GetParError(2);
		double fitMax_S1S2DELAY_top 	= fit_S1S2DELAY_top->GetMaximum();
		double fitMin_S1S2DELAY_top 	= h1_S1S2DELAY_top->GetMinimum();

		double cutValue_1s_neg_top = fitMean_S1S2DELAY_top - fitSigma_S1S2DELAY_top;
		double cutValue_1s_pos_top = fitMean_S1S2DELAY_top + fitSigma_S1S2DELAY_top;

		double cutValue_2s_neg_top = fitMean_S1S2DELAY_top - 2*fitSigma_S1S2DELAY_top;
		double cutValue_2s_pos_top = fitMean_S1S2DELAY_top + 2*fitSigma_S1S2DELAY_top;

		double cutValue_3s_neg_top = fitMean_S1S2DELAY_top - 3*fitSigma_S1S2DELAY_top;
		double cutValue_3s_pos_top = fitMean_S1S2DELAY_top + 3*fitSigma_S1S2DELAY_top;

		double cutValue_5s_neg_top = fitMean_S1S2DELAY_top - 5*fitSigma_S1S2DELAY_top;
		double cutValue_5s_pos_top = fitMean_S1S2DELAY_top + 5*fitSigma_S1S2DELAY_top;
	
		TF1 *fitDraw_S1S2DELAY_top = new TF1("fit1_S1S2DELAY_top","gaus", -0.1, 0.1);
			 fitDraw_S1S2DELAY_top ->SetLineColor(2);
			 fitDraw_S1S2DELAY_top ->SetLineStyle(7);
			 fitDraw_S1S2DELAY_top ->SetParameter(0, fitOffset_S1S2DELAY_top);
			 fitDraw_S1S2DELAY_top ->SetParameter(1, fitMean_S1S2DELAY_top);
			 fitDraw_S1S2DELAY_top ->SetParameter(2, fitSigma_S1S2DELAY_top);
			 fitDraw_S1S2DELAY_top ->Draw("same");

		TLine *line1s_neg_top = new TLine(fitMean_S1S2DELAY_top-fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top-fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line1s_neg_top ->SetLineStyle(7);
			   line1s_neg_top ->SetLineColor(3);
		TLine *line1s_pos_top = new TLine(fitMean_S1S2DELAY_top+fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top+fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line1s_pos_top ->SetLineStyle(7);
			   line1s_pos_top ->SetLineColor(3);

		TLine *line2s_neg_top = new TLine(fitMean_S1S2DELAY_top-2*fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top-2*fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line2s_neg_top ->SetLineStyle(7);
			   line2s_neg_top ->SetLineColor(3);
		TLine *line2s_pos_top = new TLine(fitMean_S1S2DELAY_top+2*fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top+2*fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line2s_pos_top ->SetLineStyle(7);
			   line2s_pos_top ->SetLineColor(3);

		TLine *line3s_neg_top = new TLine(fitMean_S1S2DELAY_top-3*fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top-3*fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line3s_neg_top ->SetLineStyle(7);
			   line3s_neg_top ->SetLineColor(3);
		TLine *line3s_pos_top = new TLine(fitMean_S1S2DELAY_top+3*fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top+3*fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line3s_pos_top ->SetLineStyle(7);
			   line3s_pos_top ->SetLineColor(3);

		TLine *line5s_neg_top = new TLine(fitMean_S1S2DELAY_top-5*fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top-5*fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line5s_neg_top ->SetLineStyle(7);
			   line5s_neg_top ->SetLineColor(3);
		TLine *line5s_pos_top = new TLine(fitMean_S1S2DELAY_top+5*fitSigma_S1S2DELAY_top, fitMin_S1S2DELAY_top, fitMean_S1S2DELAY_top+5*fitSigma_S1S2DELAY_top, fitMax_S1S2DELAY_top);
			   line5s_pos_top ->SetLineStyle(7);
			   line5s_pos_top ->SetLineColor(3);

		line1s_neg_top->Draw("same");
		line1s_pos_top->Draw("same");

		line2s_neg_top->Draw("same");
		line2s_pos_top->Draw("same");

		line3s_neg_top->Draw("same");
		line3s_pos_top->Draw("same");

		line5s_neg_top->Draw("same");
		line5s_pos_top->Draw("same");
	
	   	TPaveStats *ptstats_S1S2delay_top = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   					ptstats_S1S2delay_top->SetName("stats");
   					ptstats_S1S2delay_top->SetBorderSize(0);
   					ptstats_S1S2delay_top->SetTextAlign(12);
   					ptstats_S1S2delay_top->SetFillStyle(0);
   					ptstats_S1S2delay_top->SetFillColor(0);
   		char char_text_S1S2delay_top_1[256];
   		char char_text_S1S2delay_top_2[256];
  		sprintf(char_text_S1S2delay_top_1, "#mu:    (%2.1f #pm %2.1f) ns", fitMean_S1S2DELAY_top*1000, fitMeanEr_S1S2DELAY_top*1000);
  		sprintf(char_text_S1S2delay_top_2, "#sigma: (%2.1f #pm %2.1f) ns", fitSigma_S1S2DELAY_top*1000, fitSigmaEr_S1S2DELAY_top*1000);
   		TText *text_S1S2delay_top_1 = ptstats_S1S2delay_top->AddText(char_text_S1S2delay_top_1);
   		TText *text_S1S2delay_top_2 = ptstats_S1S2delay_top->AddText(char_text_S1S2delay_top_2);
   		ptstats_S1S2delay_top->Draw();

		char char_cutKr83m_top_1s[500];
		char char_cutKr83m_top_2s[500];
		char char_cutKr83m_top_3s[500];
		char char_cutKr83m_top_5s[500];

		sprintf(char_cutKr83m_top_1s, "(S1delay_top-S2delay_top)>%1.3f && (S1delay_top-S2delay_top)<%1.3f", cutValue_1s_neg_top, cutValue_1s_pos_top);
		sprintf(char_cutKr83m_top_2s, "(S1delay_top-S2delay_top)>%1.3f && (S1delay_top-S2delay_top)<%1.3f", cutValue_2s_neg_top, cutValue_2s_pos_top);
		sprintf(char_cutKr83m_top_3s, "(S1delay_top-S2delay_top)>%1.3f && (S1delay_top-S2delay_top)<%1.3f", cutValue_3s_neg_top, cutValue_3s_pos_top);
		sprintf(char_cutKr83m_top_5s, "(S1delay_top-S2delay_top)>%1.3f && (S1delay_top-S2delay_top)<%1.3f", cutValue_5s_neg_top, cutValue_5s_pos_top);

		TCut cutKr83m_top_1s 	= Form("(S1delay_top-S2delay_top)>%g && (S1delay_top-S2delay_top)<%g", cutValue_1s_neg_top, cutValue_1s_pos_top);
		TCut cutKr83m_top_2s 	= Form("(S1delay_top-S2delay_top)>%g && (S1delay_top-S2delay_top)<%g", cutValue_2s_neg_top, cutValue_2s_pos_top);
		TCut cutKr83m_top_3s 	= Form("(S1delay_top-S2delay_top)>%g && (S1delay_top-S2delay_top)<%g", cutValue_3s_neg_top, cutValue_3s_pos_top);
		TCut cutKr83m_top_5s 	= Form("(S1delay_top-S2delay_top)>%g && (S1delay_top-S2delay_top)<%g", cutValue_5s_neg_top, cutValue_5s_pos_top);

		cout << "CUT top 1s: "<< char_cutKr83m_top_1s << endl;
		cout << "CUT top 2s: "<< char_cutKr83m_top_2s << endl;
		cout << "CUT top 3s: "<< char_cutKr83m_top_3s << endl;
		cout << "CUT top 5s: "<< char_cutKr83m_top_5s << endl;	

	c_S1S2DELAY_top ->Update();


	c_S1S2DELAY_bot ->cd();
		TF1 *fit_S1S2DELAY_bot = new TF1("fit1_S1S2DELAY_bot","gaus", -0.025, 0.03);
			 fit_S1S2DELAY_bot ->SetLineColor(2);
		h1_S1S2DELAY_bot ->Fit(fit_S1S2DELAY_bot,"R");
		double fitOffset_S1S2DELAY_bot 	= fit_S1S2DELAY_bot->GetParameter(0);
		double fitMean_S1S2DELAY_bot 	= fit_S1S2DELAY_bot->GetParameter(1);
		double fitMeanEr_S1S2DELAY_bot 	= fit_S1S2DELAY_bot->GetParError(1);
		double fitSigma_S1S2DELAY_bot 	= fit_S1S2DELAY_bot->GetParameter(2);
		double fitSigmaEr_S1S2DELAY_bot = fit_S1S2DELAY_bot->GetParError(2);
		double fitMax_S1S2DELAY_bot 	= fit_S1S2DELAY_bot->GetMaximum();
		double fitMin_S1S2DELAY_bot 	= h1_S1S2DELAY_bot->GetMinimum();

		double cutValue_1s_neg_bot = fitMean_S1S2DELAY_bot-fitSigma_S1S2DELAY_bot;
		double cutValue_1s_pos_bot = fitMean_S1S2DELAY_bot+fitSigma_S1S2DELAY_bot;

		double cutValue_2s_neg_bot = fitMean_S1S2DELAY_bot-2*fitSigma_S1S2DELAY_bot;
		double cutValue_2s_pos_bot = fitMean_S1S2DELAY_bot+2*fitSigma_S1S2DELAY_bot;

		double cutValue_3s_neg_bot = fitMean_S1S2DELAY_bot-3*fitSigma_S1S2DELAY_bot;
		double cutValue_3s_pos_bot = fitMean_S1S2DELAY_bot+3*fitSigma_S1S2DELAY_bot;

		double cutValue_5s_neg_bot = fitMean_S1S2DELAY_bot-5*fitSigma_S1S2DELAY_bot;
		double cutValue_5s_pos_bot = fitMean_S1S2DELAY_bot+5*fitSigma_S1S2DELAY_bot;
	
		TF1 *fitDraw_S1S2DELAY_bot = new TF1("fit1_S1S2DELAY_bot","gaus", -0.1, 0.1);
			 fitDraw_S1S2DELAY_bot ->SetLineColor(2);
			 fitDraw_S1S2DELAY_bot ->SetLineStyle(7);
			 fitDraw_S1S2DELAY_bot ->SetParameter(0, fitOffset_S1S2DELAY_bot);
			 fitDraw_S1S2DELAY_bot ->SetParameter(1, fitMean_S1S2DELAY_bot);
			 fitDraw_S1S2DELAY_bot ->SetParameter(2, fitSigma_S1S2DELAY_bot);
			 fitDraw_S1S2DELAY_bot ->Draw("same");

		TLine *line1s_neg_bot = new TLine(fitMean_S1S2DELAY_bot-fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot-fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line1s_neg_bot ->SetLineStyle(7);
			   line1s_neg_bot ->SetLineColor(3);
		TLine *line1s_pos_bot = new TLine(fitMean_S1S2DELAY_bot+fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot+fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line1s_pos_bot ->SetLineStyle(7);
			   line1s_pos_bot ->SetLineColor(3);

		TLine *line2s_neg_bot = new TLine(fitMean_S1S2DELAY_bot-2*fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot-2*fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line2s_neg_bot ->SetLineStyle(7);
			   line2s_neg_bot ->SetLineColor(3);
		TLine *line2s_pos_bot = new TLine(fitMean_S1S2DELAY_bot+2*fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot+2*fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line2s_pos_bot ->SetLineStyle(7);
			   line2s_pos_bot ->SetLineColor(3);

		TLine *line3s_neg_bot = new TLine(fitMean_S1S2DELAY_bot-3*fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot-3*fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line3s_neg_bot ->SetLineStyle(7);
			   line3s_neg_bot ->SetLineColor(3);
		TLine *line3s_pos_bot = new TLine(fitMean_S1S2DELAY_bot+3*fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot+3*fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line3s_pos_bot ->SetLineStyle(7);
			   line3s_pos_bot ->SetLineColor(3);

		TLine *line5s_neg_bot = new TLine(fitMean_S1S2DELAY_bot-5*fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot-5*fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line5s_neg_bot ->SetLineStyle(7);
			   line5s_neg_bot ->SetLineColor(3);
		TLine *line5s_pos_bot = new TLine(fitMean_S1S2DELAY_bot+5*fitSigma_S1S2DELAY_bot, fitMin_S1S2DELAY_bot, fitMean_S1S2DELAY_bot+5*fitSigma_S1S2DELAY_bot, fitMax_S1S2DELAY_bot);
			   line5s_pos_bot ->SetLineStyle(7);
			   line5s_pos_bot ->SetLineColor(3);

		line1s_neg_bot->Draw("same");
		line1s_pos_bot->Draw("same");

		line2s_neg_bot->Draw("same");
		line2s_pos_bot->Draw("same");

		line3s_neg_bot->Draw("same");
		line3s_pos_bot->Draw("same");

		line5s_neg_bot->Draw("same");
		line5s_pos_bot->Draw("same");
	
	   	TPaveStats *ptstats_S1S2delay_bot = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   					ptstats_S1S2delay_bot->SetName("stats");
   					ptstats_S1S2delay_bot->SetBorderSize(0);
   					ptstats_S1S2delay_bot->SetTextAlign(12);
   					ptstats_S1S2delay_bot->SetFillStyle(0);
   					ptstats_S1S2delay_bot->SetFillColor(0);
   		char char_text_S1S2delay_bot_1[256];
   		char char_text_S1S2delay_bot_2[256];
  		sprintf(char_text_S1S2delay_bot_1, "#mu:    (%2.1f #pm %2.1f) ns", fitMean_S1S2DELAY_bot*1000, fitMeanEr_S1S2DELAY_bot*1000);
  		sprintf(char_text_S1S2delay_bot_2, "#sigma: (%2.1f #pm %2.1f) ns", fitSigma_S1S2DELAY_bot*1000, fitSigmaEr_S1S2DELAY_bot*1000);
   		TText *text_S1S2delay_bot_1 = ptstats_S1S2delay_bot->AddText(char_text_S1S2delay_bot_1);
   		TText *text_S1S2delay_bot_2 = ptstats_S1S2delay_bot->AddText(char_text_S1S2delay_bot_2);
   		ptstats_S1S2delay_bot->Draw();

		char char_cutKr83m_bot_1s[500];
		char char_cutKr83m_bot_2s[500];
		char char_cutKr83m_bot_3s[500];
		char char_cutKr83m_bot_5s[500];

		sprintf(char_cutKr83m_bot_1s, "(S1delay_bot-S2delay_bot)>%1.3f && (S1delay_bot-S2delay_bot)<%1.3f", cutValue_1s_neg_bot, cutValue_1s_pos_bot);
		sprintf(char_cutKr83m_bot_2s, "(S1delay_bot-S2delay_bot)>%1.3f && (S1delay_bot-S2delay_bot)<%1.3f", cutValue_2s_neg_bot, cutValue_2s_pos_bot);
		sprintf(char_cutKr83m_bot_3s, "(S1delay_bot-S2delay_bot)>%1.3f && (S1delay_bot-S2delay_bot)<%1.3f", cutValue_3s_neg_bot, cutValue_3s_pos_bot);
		sprintf(char_cutKr83m_bot_5s, "(S1delay_bot-S2delay_bot)>%1.3f && (S1delay_bot-S2delay_bot)<%1.3f", cutValue_5s_neg_bot, cutValue_5s_pos_bot);

		TCut cutKr83m_bot_1s 	= Form("(S1delay_bot-S2delay_bot)>%g && (S1delay_bot-S2delay_bot)<%g", cutValue_1s_neg_bot, cutValue_1s_pos_bot);
		TCut cutKr83m_bot_2s 	= Form("(S1delay_bot-S2delay_bot)>%g && (S1delay_bot-S2delay_bot)<%g", cutValue_2s_neg_bot, cutValue_2s_pos_bot);
		TCut cutKr83m_bot_3s 	= Form("(S1delay_bot-S2delay_bot)>%g && (S1delay_bot-S2delay_bot)<%g", cutValue_3s_neg_bot, cutValue_3s_pos_bot);
		TCut cutKr83m_bot_5s 	= Form("(S1delay_bot-S2delay_bot)>%g && (S1delay_bot-S2delay_bot)<%g", cutValue_5s_neg_bot, cutValue_5s_pos_bot);

		cout << "CUT bot 1s: "<< char_cutKr83m_bot_1s << endl;
		cout << "CUT bot 2s: "<< char_cutKr83m_bot_2s << endl;
		cout << "CUT bot 3s: "<< char_cutKr83m_bot_3s << endl;
		cout << "CUT bot 5s: "<< char_cutKr83m_bot_5s << endl;	

	c_S1S2DELAY_bot ->Update();
		


	// S1 delay
	TCanvas *c_S1DELAY_bot = new TCanvas("c_S1DELAY_bot", "c_S1DELAY_bot", 0, 0, canX, canY);
			 c_S1DELAY_bot->SetFillColor(10);
    		 c_S1DELAY_bot->SetLogy();
		T1 ->Draw("S1delay_bot>>h1_S1DELAY_5s",	cutKr83m_bot_5s,	"");
		T1 ->Draw("S1delay_bot>>h1_S1DELAY_3s",	cutKr83m_bot_3s,	"same");
		T1 ->Draw("S1delay_bot>>h1_S1DELAY_2s",	cutKr83m_bot_2s,	"same");
		T1 ->Draw("S1delay_bot>>h1_S1DELAY_1s",	cutKr83m_bot_1s,	"same");
		h1_S1DELAY_5s	-> GetXaxis() -> SetTitle("S1 delay [#mus]");
		h1_S1DELAY_5s	-> GetYaxis() -> SetTitle("Counts");
		h1_S1DELAY_5s	-> GetXaxis() -> CenterTitle(true);
		h1_S1DELAY_5s	-> GetYaxis() -> CenterTitle(true);
	
		double minFitRange_S1delay = 1.1;
		double maxFitRange_S1delay = 2.0;
		TF1 *fit_S1delay_1s = new TF1("fit_S1delay_1s", "expo", minFitRange_S1delay, maxFitRange_S1delay);
		TF1 *fit_S1delay_2s = new TF1("fit_S1delay_2s", "expo", minFitRange_S1delay, maxFitRange_S1delay);
		TF1 *fit_S1delay_3s = new TF1("fit_S1delay_3s", "expo", minFitRange_S1delay, maxFitRange_S1delay);
		TF1 *fit_S1delay_5s = new TF1("fit_S1delay_5s", "expo", minFitRange_S1delay, maxFitRange_S1delay);
			 fit_S1delay_5s ->SetLineColor(1);
			 fit_S1delay_2s ->SetLineColor(4);
			 fit_S1delay_3s ->SetLineColor(2);
			 fit_S1delay_1s ->SetLineColor(3);
		h1_S1DELAY_5s->Fit(fit_S1delay_5s,"R");
		h1_S1DELAY_3s->Fit(fit_S1delay_3s,"R");
		h1_S1DELAY_2s->Fit(fit_S1delay_2s,"R");
		h1_S1DELAY_1s->Fit(fit_S1delay_1s,"R");

		double lambda_S1_1s 		= fit_S1delay_1s->GetParameter(1);
		double lambdaEr_S1_1s 		= fit_S1delay_1s->GetParError(1);
		double HalfLife_S1_1s 		= -TMath::Log(2)/lambda_S1_1s *1e3; //ns 
		double MeanLifetime_S1_1s 	= TMath::Abs(1/lambda_S1_1s) *1e3;
		double fracEr_S1_1s 		= TMath::Abs(lambdaEr_S1_1s/lambda_S1_1s);
		double HalfLifeEr_S1_1s		= HalfLife_S1_1s * fracEr_S1_1s;

		double lambda_S1_2s 		= fit_S1delay_2s->GetParameter(1);
		double lambdaEr_S1_2s 		= fit_S1delay_2s->GetParError(1);
		double HalfLife_S1_2s 		= -TMath::Log(2)/lambda_S1_2s *1e3; //ns 
		double MeanLifetime_S1_2s 	= TMath::Abs(1/lambda_S1_2s) *1e3;
		double fracEr_S1_2s 		= TMath::Abs(lambdaEr_S1_2s/lambda_S1_2s);
		double HalfLifeEr_S1_2s		= HalfLife_S1_2s * fracEr_S1_2s;

		double lambda_S1_3s 		= fit_S1delay_3s->GetParameter(1);
		double lambdaEr_S1_3s 		= fit_S1delay_3s->GetParError(1);
		double HalfLife_S1_3s 		= -TMath::Log(2)/lambda_S1_3s *1e3; //ns 
		double MeanLifetime_S1_3s 	= TMath::Abs(1/lambda_S1_3s) *1e3;
		double fracEr_S1_3s 		= TMath::Abs(lambdaEr_S1_3s/lambda_S1_3s);
		double HalfLifeEr_S1_3s		= HalfLife_S1_3s * fracEr_S1_3s;

		double lambda_S1_5s 		= fit_S1delay_5s->GetParameter(1);
		double lambdaEr_S1_5s 		= fit_S1delay_5s->GetParError(1);
		double HalfLife_S1_5s 		= -TMath::Log(2)/lambda_S1_5s *1e3; //ns 
		double MeanLifetime_S1_5s 	= TMath::Abs(1/lambda_S1_5s) *1e3;
		double fracEr_S1_5s 		= TMath::Abs(lambdaEr_S1_5s/lambda_S1_5s);
		double HalfLifeEr_S1_5s		= HalfLife_S1_5s * fracEr_S1_5s;
	
		cout <<"CUT 1 sigma: "<< endl;	
		cout <<"lambda_S1   = "<< lambda_S1_1s 			<< endl;
		cout <<"halflife_S1 = "<< HalfLife_S1_1s 		<<" +- "<< HalfLifeEr_S1_1s <<" ns"<< endl;
		cout <<"meanlife_S1 = "<< MeanLifetime_S1_1s 	<<" ns"<< endl;

		cout <<"CUT 2 sigma: "<< endl;	
		cout <<"lambda_S1   = "<< lambda_S1_2s 			<< endl;
		cout <<"halflife_S1 = "<< HalfLife_S1_2s 		<<" +- "<< HalfLifeEr_S1_2s <<" ns"<< endl;
		cout <<"meanlife_S1 = "<< MeanLifetime_S1_2s 	<<" ns"<< endl;

		cout <<"CUT 3 sigma: "<< endl;	
		cout <<"lambda_S1   = "<< lambda_S1_3s 			<< endl;
		cout <<"halflife_S1 = "<< HalfLife_S1_3s 		<<" +- "<< HalfLifeEr_S1_3s <<" ns"<< endl;
		cout <<"meanlife_S1 = "<< MeanLifetime_S1_3s 	<<" ns"<< endl;

		cout <<"CUT 5 sigma: "<< endl;	
		cout <<"lambda_S1   = "<< lambda_S1_5s 			<< endl;
		cout <<"halflife_S1 = "<< HalfLife_S1_5s 		<<" +- "<< HalfLifeEr_S1_5s <<" ns"<< endl;
		cout <<"meanlife_S1 = "<< MeanLifetime_S1_5s 	<<" ns"<< endl;

   		TPaveStats *ptstats_S1delay = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   					ptstats_S1delay->SetName("stats");
   					ptstats_S1delay->SetBorderSize(0);
   					ptstats_S1delay->SetTextAlign(12);
   					ptstats_S1delay->SetFillStyle(0);
   					ptstats_S1delay->SetFillColor(0);
   		char char_text_S1delay_1[256];
   		char char_text_S1delay_2[256];
   		char char_text_S1delay_3[256];
   		char char_text_S1delay_4[256];
  		sprintf(char_text_S1delay_1, "#pm1#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S1_1s, HalfLifeEr_S1_1s);
  		sprintf(char_text_S1delay_2, "#pm2#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S1_2s, HalfLifeEr_S1_2s);
  		sprintf(char_text_S1delay_3, "#pm3#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S1_3s, HalfLifeEr_S1_3s);
  		sprintf(char_text_S1delay_4, "#pm5#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S1_5s, HalfLifeEr_S1_5s);
   		TText *text_S1delay_1 = ptstats_S1delay->AddText(char_text_S1delay_1);
   		TText *text_S1delay_2 = ptstats_S1delay->AddText(char_text_S1delay_2);
   		TText *text_S1delay_3 = ptstats_S1delay->AddText(char_text_S1delay_3);
   		TText *text_S1delay_4 = ptstats_S1delay->AddText(char_text_S1delay_4);
   			   text_S1delay_1->SetTextColor(3);
   			   text_S1delay_2->SetTextColor(2);
   			   text_S1delay_3->SetTextColor(4);
   			   text_S1delay_4->SetTextColor(1);
   		ptstats_S1delay->Draw();
	c_S1DELAY_bot->Update();

	// S2 delay
	TCanvas *c_S2DELAY_bot = new TCanvas("c_S2DELAY_bot", "c_S2DELAY_bot", 0, 0, canX, canY);
			 c_S2DELAY_bot->SetFillColor(10);
    		 c_S2DELAY_bot->SetLogy();
		T1 ->Draw("S2delay_bot>>h1_S2DELAY_5s",	cutKr83m_bot_5s,	"");
		T1 ->Draw("S2delay_bot>>h1_S2DELAY_3s",	cutKr83m_bot_3s,	"same");
		T1 ->Draw("S2delay_bot>>h1_S2DELAY_2s",	cutKr83m_bot_2s,	"same");
		T1 ->Draw("S2delay_bot>>h1_S2DELAY_1s",	cutKr83m_bot_1s,	"same");
		h1_S2DELAY_5s	-> GetXaxis() -> SetTitle("S2 delay [#mus]");
		h1_S2DELAY_5s	-> GetYaxis() -> SetTitle("Counts");
		h1_S2DELAY_5s	-> GetXaxis() -> CenterTitle(true);
		h1_S2DELAY_5s	-> GetYaxis() -> CenterTitle(true);

		double minFitRange_S2delay = 1.1;
		double maxFitRange_S2delay = 2.0;
		TF1 *fit_S2delay_1s = new TF1("fit_S2delay_1s", "expo", minFitRange_S2delay, maxFitRange_S2delay);
		TF1 *fit_S2delay_2s = new TF1("fit_S2delay_2s", "expo", minFitRange_S2delay, maxFitRange_S2delay);
		TF1 *fit_S2delay_3s = new TF1("fit_S2delay_3s", "expo", minFitRange_S2delay, maxFitRange_S2delay);
		TF1 *fit_S2delay_5s = new TF1("fit_S2delay_5s", "expo", minFitRange_S2delay, maxFitRange_S2delay);
			 fit_S2delay_5s ->SetLineColor(1);
			 fit_S2delay_2s ->SetLineColor(4);
			 fit_S2delay_3s ->SetLineColor(2);
			 fit_S2delay_1s ->SetLineColor(3);
		h1_S2DELAY_5s->Fit(fit_S2delay_5s,"R");
		h1_S2DELAY_3s->Fit(fit_S2delay_3s,"R");
		h1_S2DELAY_2s->Fit(fit_S2delay_2s,"R");
		h1_S2DELAY_1s->Fit(fit_S2delay_1s,"R");

		double lambda_S2_1s 		= fit_S2delay_1s->GetParameter(1);
		double lambdaEr_S2_1s 		= fit_S2delay_1s->GetParError(1);
		double HalfLife_S2_1s 		= -TMath::Log(2)/lambda_S2_1s *1e3; //ns 
		double MeanLifetime_S2_1s 	= TMath::Abs(1/lambda_S2_1s) *1e3;
		double fracEr_S2_1s 		= TMath::Abs(lambdaEr_S2_1s/lambda_S2_1s);
		double HalfLifeEr_S2_1s		= HalfLife_S2_1s * fracEr_S2_1s;

		double lambda_S2_2s 		= fit_S2delay_2s->GetParameter(1);
		double lambdaEr_S2_2s 		= fit_S2delay_2s->GetParError(1);
		double HalfLife_S2_2s 		= -TMath::Log(2)/lambda_S2_2s *1e3; //ns 
		double MeanLifetime_S2_2s 	= TMath::Abs(1/lambda_S2_2s) *1e3;
		double fracEr_S2_2s 		= TMath::Abs(lambdaEr_S2_2s/lambda_S2_2s);
		double HalfLifeEr_S2_2s		= HalfLife_S2_2s * fracEr_S2_2s;

		double lambda_S2_3s 		= fit_S2delay_3s->GetParameter(1);
		double lambdaEr_S2_3s 		= fit_S2delay_3s->GetParError(1);
		double HalfLife_S2_3s 		= -TMath::Log(2)/lambda_S2_3s *1e3; //ns 
		double MeanLifetime_S2_3s 	= TMath::Abs(1/lambda_S2_3s) *1e3;
		double fracEr_S2_3s 		= TMath::Abs(lambdaEr_S2_3s/lambda_S2_3s);
		double HalfLifeEr_S2_3s		= HalfLife_S2_3s * fracEr_S2_3s;

		double lambda_S2_5s 		= fit_S2delay_5s->GetParameter(1);
		double lambdaEr_S2_5s 		= fit_S2delay_5s->GetParError(1);
		double HalfLife_S2_5s 		= -TMath::Log(2)/lambda_S2_5s *1e3; //ns 
		double MeanLifetime_S2_5s 	= TMath::Abs(1/lambda_S2_5s) *1e3;
		double fracEr_S2_5s 		= TMath::Abs(lambdaEr_S2_5s/lambda_S2_5s);
		double HalfLifeEr_S2_5s		= HalfLife_S2_5s * fracEr_S2_5s;
	
		cout <<"CUT 1 sigma: "<< endl;	
		cout <<"lambda_S2   = "<< lambda_S2_1s 			<< endl;
		cout <<"halflife_S2 = "<< HalfLife_S2_1s 		<<" +- "<< HalfLifeEr_S2_1s <<" ns"<< endl;
		cout <<"meanlife_S2 = "<< MeanLifetime_S2_1s 	<<" ns"<< endl;

		cout <<"CUT 2 sigma: "<< endl;	
		cout <<"lambda_S2   = "<< lambda_S2_2s 			<< endl;
		cout <<"halflife_S2 = "<< HalfLife_S2_2s 		<<" +- "<< HalfLifeEr_S2_2s <<" ns"<< endl;
		cout <<"meanlife_S2 = "<< MeanLifetime_S2_2s 	<<" ns"<< endl;

		cout <<"CUT 3 sigma: "<< endl;	
		cout <<"lambda_S2   = "<< lambda_S2_3s 			<< endl;
		cout <<"halflife_S2 = "<< HalfLife_S2_3s 		<<" +- "<< HalfLifeEr_S2_3s <<" ns"<< endl;
		cout <<"meanlife_S2 = "<< MeanLifetime_S2_3s 	<<" ns"<< endl;

		cout <<"CUT 5 sigma: "<< endl;	
		cout <<"lambda_S2   = "<< lambda_S2_5s 			<< endl;
		cout <<"halflife_S2 = "<< HalfLife_S2_5s 		<<" +- "<< HalfLifeEr_S2_5s <<" ns"<< endl;
		cout <<"meanlife_S2 = "<< MeanLifetime_S2_5s 	<<" ns"<< endl;

   		TPaveStats *ptstats_S2delay = new TPaveStats(0.5114379,0.6432039,0.8986928,0.8956311,"brNDC");
   					ptstats_S2delay->SetName("stats");
   					ptstats_S2delay->SetBorderSize(0);
   					ptstats_S2delay->SetTextAlign(12);
   					ptstats_S2delay->SetFillStyle(0);
   					ptstats_S2delay->SetFillColor(0);
   		char char_text_S2delay_1[256];
   		char char_text_S2delay_2[256];
   		char char_text_S2delay_3[256];
   		char char_text_S2delay_4[256];
  		sprintf(char_text_S2delay_1, "#pm1#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S2_1s, HalfLifeEr_S2_1s);
  		sprintf(char_text_S2delay_2, "#pm2#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S2_2s, HalfLifeEr_S2_2s);
  		sprintf(char_text_S2delay_3, "#pm3#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S2_3s, HalfLifeEr_S2_3s);
  		sprintf(char_text_S2delay_4, "#pm5#sigma: T_{1/2} (%3.1f #pm %1.1f) ns", HalfLife_S2_5s, HalfLifeEr_S2_5s);
   		TText *text_S2delay_1 = ptstats_S2delay->AddText(char_text_S2delay_1);
   		TText *text_S2delay_2 = ptstats_S2delay->AddText(char_text_S2delay_2);
   		TText *text_S2delay_3 = ptstats_S2delay->AddText(char_text_S2delay_3);
   		TText *text_S2delay_4 = ptstats_S2delay->AddText(char_text_S2delay_4);
   			   text_S2delay_1->SetTextColor(3);
   			   text_S2delay_2->SetTextColor(2);
   			   text_S2delay_3->SetTextColor(4);
   			   text_S2delay_4->SetTextColor(1);
   		ptstats_S2delay->Draw();
	c_S2DELAY_bot->Update();




	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_Kr83m[500];
	sprintf(outFolder_Kr83m, "%s/Kr83m", outFolder_dataset);
	char mkdir_outFolder_Kr83m[500];
	sprintf(mkdir_outFolder_Kr83m, ".mkdir %s", outFolder_Kr83m);
	gROOT->ProcessLine(mkdir_outFolder_Kr83m);

	char char_S2DELAYvsS1DELAY_bot[500];
	char char_S2DELAYvsS1DELAY_top[500];
	char char_S1DELAYvsS1DELAY[500];
	char char_S2DELAYvsS2DELAY[500];
	char char_S1S2DELAY_bot[500];
	char char_S1S2DELAY_top[500];
	char char_S1DELAY_bot[500];
	char char_S2DELAY_bot[500];

	char charC_S2DELAYvsS1DELAY_bot[500];
	char charC_S2DELAYvsS1DELAY_top[500];
	char charC_S1DELAYvsS1DELAY[500];
	char charC_S2DELAYvsS2DELAY[500];
	char charC_S1S2DELAY_bot[500];
	char charC_S1S2DELAY_top[500];
	char charC_S1DELAY_bot[500];
	char charC_S2DELAY_bot[500];

	sprintf(char_S2DELAYvsS1DELAY_bot,	"%s/%s_S2DELAYvsS1DELAY_bot_%s%s",	outFolder_Kr83m, DataSet1, CutName, extensionPlots);
	sprintf(char_S2DELAYvsS1DELAY_top,	"%s/%s_S2DELAYvsS1DELAY_top_%s%s",	outFolder_Kr83m, DataSet1, CutName, extensionPlots);
	sprintf(char_S1DELAYvsS1DELAY,		"%s/%s_S1DELAYvsS1DELAY_%s%s",		outFolder_Kr83m, DataSet1, CutName, extensionPlots);
	sprintf(char_S2DELAYvsS2DELAY,		"%s/%s_S2DELAYvsS2DELAY_%s%s",		outFolder_Kr83m, DataSet1, CutName, extensionPlots);
	sprintf(char_S1S2DELAY_bot,			"%s/%s_S1S2DELAY_bot_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots);
	sprintf(char_S1S2DELAY_top,			"%s/%s_S1S2DELAY_top_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots);
	sprintf(char_S1DELAY_bot,			"%s/%s_S1DELAY_bot_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots);
	sprintf(char_S2DELAY_bot,			"%s/%s_S2DELAY_bot_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots);

	sprintf(charC_S2DELAYvsS1DELAY_bot,	"%s/%s_S2DELAYvsS1DELAY_bot_%s%s",	outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);
	sprintf(charC_S2DELAYvsS1DELAY_top,	"%s/%s_S2DELAYvsS1DELAY_top_%s%s",	outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);
	sprintf(charC_S1DELAYvsS1DELAY,		"%s/%s_S1DELAYvsS1DELAY_%s%s",		outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);
	sprintf(charC_S2DELAYvsS2DELAY,		"%s/%s_S2DELAYvsS2DELAY_%s%s",		outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);
	sprintf(charC_S1S2DELAY_bot,		"%s/%s_S1S2DELAY_bot_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);
	sprintf(charC_S1S2DELAY_top,		"%s/%s_S1S2DELAY_top_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);
	sprintf(charC_S1DELAY_bot,			"%s/%s_S1DELAY_bot_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);
	sprintf(charC_S2DELAY_bot,			"%s/%s_S2DELAY_bot_%s%s",			outFolder_Kr83m, DataSet1, CutName, extensionPlots_C);

	c_S2DELAYvsS1DELAY_bot	->SaveAs(char_S2DELAYvsS1DELAY_bot);
	c_S2DELAYvsS1DELAY_top	->SaveAs(char_S2DELAYvsS1DELAY_top);
	c_S1DELAYvsS1DELAY		->SaveAs(char_S1DELAYvsS1DELAY);
	c_S2DELAYvsS2DELAY		->SaveAs(char_S2DELAYvsS2DELAY);
	c_S1S2DELAY_bot			->SaveAs(char_S1S2DELAY_bot);
	c_S1S2DELAY_top			->SaveAs(char_S1S2DELAY_top);
	c_S1DELAY_bot			->SaveAs(char_S1DELAY_bot);
	c_S2DELAY_bot			->SaveAs(char_S2DELAY_bot);

	c_S2DELAYvsS1DELAY_bot	->SaveAs(charC_S2DELAYvsS1DELAY_bot);
	c_S2DELAYvsS1DELAY_top	->SaveAs(charC_S2DELAYvsS1DELAY_top);
	c_S1DELAYvsS1DELAY		->SaveAs(charC_S1DELAYvsS1DELAY);
	c_S2DELAYvsS2DELAY		->SaveAs(charC_S2DELAYvsS2DELAY);
	c_S1S2DELAY_bot			->SaveAs(charC_S1S2DELAY_bot);
	c_S1S2DELAY_top			->SaveAs(charC_S1S2DELAY_top);
	c_S1DELAY_bot			->SaveAs(charC_S1DELAY_bot);
	c_S2DELAY_bot			->SaveAs(charC_S2DELAY_bot);

