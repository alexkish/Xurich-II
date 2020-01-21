	int nbins_DT		= 600;
	double min_DT		= -30;
	double max_DT		= 30;

	int nbins_DTdif		= 1000;
	double min_DTdif	= -30;
	double max_DTdif	= 30;

	int nbins_S1coin	= 1000;
	double min_S1coin	= -30;
	double max_S1coin	= 30;

	int nbins_S2coin	= 1000;
	double min_S2coin	= -30;
	double max_S2coin	= 30;

	TH1F *h1_DTdif 		= new TH1F("h1_DTdif",		DataSetName1, nbins_DTdif, min_DTdif, max_DTdif);
	TH1F *h1zoom_DTdif 	= new TH1F("h1zoom_DTdif",	DataSetName1, nbins_DTdif/5, min_DTdif/60, max_DTdif/60);

	TH1F *h1_S1coin 	= new TH1F("h1_S1coin",		DataSetName1, nbins_S1coin, min_S1coin, max_S1coin);
	TH1F *h1_S2coin 	= new TH1F("h1_S2coin",		DataSetName1, nbins_S2coin, min_S2coin, max_S2coin);

	TH1F *h1zoom_S1coin = new TH1F("h1zoom_S1coin",	DataSetName1, nbins_S1coin/10, min_S1coin/60, max_S1coin/60);
	TH1F *h1zoom_S2coin = new TH1F("h1zoom_S2coin",	DataSetName1, nbins_S2coin/10, min_S2coin/60, max_S2coin/60);


	int nbins_S1ratio	= 200;
	double min_S1ratio	= 0.;
	double max_S1ratio	= 10.;

	int nbins_S2ratio	= 200;
	double min_S2ratio	= 0.;
	double max_S2ratio	= 10.;

	TH2F *h2_S1RATIOvsS1COIN 		= new TH2F("h2_S1RATIOvsS1COIN",		DataSetName1, 200, min_S1coin, max_S1coin, 200, min_S1ratio, max_S1ratio);
	TH2F *h2_S2RATIOvsS2COIN 		= new TH2F("h2_S2RATIOvsS2COIN",		DataSetName1, 200, min_S1coin, max_S1coin, 200, min_S1ratio, max_S1ratio);

	TH2F *h2zoom_S1RATIOvsS1COIN 	= new TH2F("h2zoom_S1RATIOvsS1COIN",	DataSetName1, 200, min_S1coin/60, max_S1coin/60, 200, min_S1ratio/5, max_S1ratio/5);
	TH2F *h2zoom_S2RATIOvsS2COIN 	= new TH2F("h2zoom_S2RATIOvsS2COIN",	DataSetName1, 200, min_S1coin/60, max_S1coin/60, 200, min_S1ratio/5, max_S1ratio/5);

	TH2F *h2_S2COINvsS1COIN 		= new TH2F("h2_S2COINvsS1COIN",			DataSetName1, 200, min_S1coin, max_S1coin, 200, min_S2coin, max_S2coin);
	TH2F *h2zoom_S2COINvsS1COIN 	= new TH2F("h2zoom_S2COINvsS1COIN",		DataSetName1, 200, min_S1coin/60, max_S1coin/60, 200, min_S2coin/60, max_S2coin/60);

	TH2F *h2_S1COINvsDTbot 			= new TH2F("h2_S1COINvsDTbot",			DataSetName1, 200, min_DT, max_DT, 200, min_S1coin/60, max_S1coin/60);
	TH2F *h2_S2COINvsDTbot 			= new TH2F("h2_S2COINvsDTbot",			DataSetName1, 200, min_DT, max_DT, 200, min_S2coin/120, max_S2coin/120);
	TH2F *h2zoom_S1COINvsDTbot 		= new TH2F("h2zoom_S1COINvsDTbot",		DataSetName1, 200, min_DT/30, max_DT/30, 200, min_S1coin/60, max_S1coin/60);
	TH2F *h2zoom_S2COINvsDTbot 		= new TH2F("h2zoom_S2COINvsDTbot",		DataSetName1, 200, min_DT/30, max_DT/30, 200, min_S2coin/60, max_S2coin/60);


	int nbins_S2height	= 200;
	double min_S2height	= 0;
	double max_S2height	= 16000; // mV

	TH2F *h2_S2COINvsS2heightTop 	= new TH2F("h2_S2COINvsS2heightTop",	DataSetName1, nbins_S2height, min_S2height, max_S2height, nbins_S2coin, min_S2coin/60, max_S2coin/60);
	TH2F *h2_S2COINvsS2heightBot 	= new TH2F("h2_S2COINvsS2heightBot",	DataSetName1, nbins_S2height, min_S2height, max_S2height, nbins_S2coin, min_S2coin/60, max_S2coin/60);

	int nbins_S2asym	= 200;
	double min_S2asym	= -1.0;
	double max_S2asym	= 1.0; // mV

	TH2F *h2_S2COINvsS2ASYM 	= new TH2F("h2_S2COINvsS2ASYM",				DataSetName1, 200, min_S2asym/2, max_S2asym/2, 200, min_S2coin/60, max_S2coin/60);

	TH2F *h2_S2ASYMvsS2RATIO 	= new TH2F("h2_S2ASYMvsS2RATIO",			DataSetName1, 200, min_S2ratio, max_S2ratio, 200, min_S2coin/60, max_S2coin/60);

	int nbins_S2width	= 200;
	double min_S2width	= 0.0;
	double max_S2width	= 2.0;

	TH2F *h2_S2COINvsS2widthLowBot 	= new TH2F("h2_S2COINvsS2widthLowBot",	DataSetName1, 200, min_S2width, max_S2width, 200, min_S2coin/120, max_S2coin/120);
	TH2F *h2_S2COINvsS2M2bot 		= new TH2F("h2_S2COINvsS2M2bot",		DataSetName1, 200, min_S2width, max_S2width, 200, min_S2coin/120, max_S2coin/120);


	//////////////////////////////////////////////////////////////////////////////////////
	// PLOT
	int c1x = 1000;
	int c1y = 500;

	TCanvas *c1_DTdif = new TCanvas("c1_DTdif", "c1_DTdif", 0, 0, c1x, c1y);
			 c1_DTdif->SetFillColor(10);
    		 c1_DTdif->SetLogy();
		T1	->Draw("(dt_top-dt_bot)>>h1_DTdif",	"",	"");
		h1_DTdif	-> GetXaxis() -> SetTitle("#Delta(Drift Time), top-bottom [#mus]");
		h1_DTdif	-> GetYaxis() -> SetTitle("Counts");
		h1_DTdif	-> GetXaxis() -> CenterTitle(true);
		h1_DTdif	-> GetYaxis() -> CenterTitle(true);
		h1_DTdif	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_DTdif	-> GetYaxis() -> SetTitleOffset(1.25);
	c1_DTdif->Update();

	TCanvas *c1zoom_DTdif = new TCanvas("c1zoom_DTdif", "c1zoom_DTdif", 0, 0, c1x, c1y);
			 c1zoom_DTdif->SetFillColor(10);
    		 c1zoom_DTdif->SetLogy();
		T1	->Draw("(dt_top-dt_bot)>>h1zoom_DTdif",	"",	"");
		h1zoom_DTdif	-> GetXaxis() -> SetTitle("#Delta(Drift Time), top-bottom [#mus]");
		h1zoom_DTdif	-> GetYaxis() -> SetTitle("Counts");
		h1zoom_DTdif	-> GetXaxis() -> CenterTitle(true);
		h1zoom_DTdif	-> GetYaxis() -> CenterTitle(true);
		h1zoom_DTdif	-> GetXaxis() -> SetTitleOffset(1.25);
		h1zoom_DTdif	-> GetYaxis() -> SetTitleOffset(1.25);
	c1zoom_DTdif->Update();

	TCanvas *c1_S1coin = new TCanvas("c1_S1coin", "c1_S1coin", 0, 0, c1x, c1y);
			 c1_S1coin->SetFillColor(10);
    		 c1_S1coin->SetLogy();
		T1	->Draw("(S1time_top-S1time_bot)>>h1_S1coin",	"",	"");
		h1_S1coin	-> GetXaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h1_S1coin	-> GetYaxis() -> SetTitle("Counts");
		h1_S1coin	-> GetXaxis() -> CenterTitle(true);
		h1_S1coin	-> GetYaxis() -> CenterTitle(true);
		h1_S1coin	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_S1coin	-> GetYaxis() -> SetTitleOffset(1.25);
	c1_S1coin->Update();

	TCanvas *c1_S2coin = new TCanvas("c1_S2coin", "c1_S2coin", 0, 0, c1x, c1y);
			 c1_S2coin->SetFillColor(10);
    		 c1_S2coin->SetLogy();
		T1	->Draw("(S2time_top-S2time_bot)>>h1_S2coin",	"",	"");
		h1_S2coin	-> GetXaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h1_S2coin	-> GetYaxis() -> SetTitle("Counts");
		h1_S2coin	-> GetXaxis() -> CenterTitle(true);
		h1_S2coin	-> GetYaxis() -> CenterTitle(true);
		h1_S2coin	-> GetXaxis() -> SetTitleOffset(1.25);
		h1_S2coin	-> GetYaxis() -> SetTitleOffset(1.25);
	c1_S2coin->Update();


	TCanvas *c1zoom_S1coin = new TCanvas("c1zoom_S1coin", "c1zoom_S1coin", 0, 0, c1x, c1y);
			 c1zoom_S1coin->SetFillColor(10);
    		 c1zoom_S1coin->SetLogy();
		T1	->Draw("(S1time_top-S1time_bot)>>h1zoom_S1coin",	"",	"");
		h1zoom_S1coin	-> GetXaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h1zoom_S1coin	-> GetYaxis() -> SetTitle("Counts");
		h1zoom_S1coin	-> GetXaxis() -> CenterTitle(true);
		h1zoom_S1coin	-> GetYaxis() -> CenterTitle(true);
		h1zoom_S1coin	-> GetXaxis() -> SetTitleOffset(1.25);
		h1zoom_S1coin	-> GetYaxis() -> SetTitleOffset(1.25);
	c1zoom_S1coin->Update();

	TCanvas *c1zoom_S2coin = new TCanvas("c1zoom_S2coin", "c1zoom_S2coin", 0, 0, c1x, c1y);
			 c1zoom_S2coin->SetFillColor(10);
    		 c1zoom_S2coin->SetLogy();
		T1	->Draw("(S2time_top-S2time_bot)>>h1zoom_S2coin",	"",	"");
		h1zoom_S2coin	-> GetXaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h1zoom_S2coin	-> GetYaxis() -> SetTitle("Counts");
		h1zoom_S2coin	-> GetXaxis() -> CenterTitle(true);
		h1zoom_S2coin	-> GetYaxis() -> CenterTitle(true);
		h1zoom_S2coin	-> GetXaxis() -> SetTitleOffset(1.25);
		h1zoom_S2coin	-> GetYaxis() -> SetTitleOffset(1.25);
	c1zoom_S2coin->Update();



	TCanvas *c1_S1RATIOvsS1COIN = new TCanvas("c1_S1RATIOvsS1COIN", "c1_S1RATIOvsS1COIN", 0, 0, c1x, c1y);
			 c1_S1RATIOvsS1COIN->SetFillColor(10);
    		 c1_S1RATIOvsS1COIN->SetLogz();
		T1	->Draw("(S1topPE/S1botPE):(S1time_top-S1time_bot)>>h2_S1RATIOvsS1COIN",	"",	"COLZ");
		h2_S1RATIOvsS1COIN	-> GetXaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h2_S1RATIOvsS1COIN	-> GetYaxis() -> SetTitle("Ratio of S1 top/bottom");
		h2_S1RATIOvsS1COIN	-> GetZaxis() -> SetTitle("Counts");
		h2_S1RATIOvsS1COIN	-> GetXaxis() -> CenterTitle(true);
		h2_S1RATIOvsS1COIN	-> GetYaxis() -> CenterTitle(true);
		h2_S1RATIOvsS1COIN	-> GetZaxis() -> CenterTitle(true);
		h2_S1RATIOvsS1COIN	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S1RATIOvsS1COIN	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S1RATIOvsS1COIN	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S1RATIOvsS1COIN->Update();

	TCanvas *c1_S2RATIOvsS2COIN = new TCanvas("c1_S2RATIOvsS2COIN", "c1_S2RATIOvsS2COIN", 0, 0, c1x, c1y);
			 c1_S2RATIOvsS2COIN->SetFillColor(10);
    		 c1_S2RATIOvsS2COIN->SetLogz();
		T1	->Draw("(S2topPE/S2botPE):(S2time_top-S2time_bot)>>h2_S2RATIOvsS2COIN",	"",	"COLZ");
		h2_S2RATIOvsS2COIN	-> GetXaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2RATIOvsS2COIN	-> GetYaxis() -> SetTitle("Ratio of S2 top/bottom");
		h2_S2RATIOvsS2COIN	-> GetZaxis() -> SetTitle("Counts");
		h2_S2RATIOvsS2COIN	-> GetXaxis() -> CenterTitle(true);
		h2_S2RATIOvsS2COIN	-> GetYaxis() -> CenterTitle(true);
		h2_S2RATIOvsS2COIN	-> GetZaxis() -> CenterTitle(true);
		h2_S2RATIOvsS2COIN	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2RATIOvsS2COIN	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2RATIOvsS2COIN	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2RATIOvsS2COIN->Update();


	TCanvas *c1zoom_S1RATIOvsS1COIN = new TCanvas("c1zoom_S1RATIOvsS1COIN", "c1zoom_S1RATIOvsS1COIN", 0, 0, c1x, c1y);
			 c1zoom_S1RATIOvsS1COIN->SetFillColor(10);
    		 c1zoom_S1RATIOvsS1COIN->SetLogz();
		T1	->Draw("(S1topPE/S1botPE):(S1time_top-S1time_bot)>>h2zoom_S1RATIOvsS1COIN",	"",	"COLZ");
		h2zoom_S1RATIOvsS1COIN	-> GetXaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h2zoom_S1RATIOvsS1COIN	-> GetYaxis() -> SetTitle("Ratio of S1 top/bottom");
		h2zoom_S1RATIOvsS1COIN	-> GetZaxis() -> SetTitle("Counts");
		h2zoom_S1RATIOvsS1COIN	-> GetXaxis() -> CenterTitle(true);
		h2zoom_S1RATIOvsS1COIN	-> GetYaxis() -> CenterTitle(true);
		h2zoom_S1RATIOvsS1COIN	-> GetZaxis() -> CenterTitle(true);
		h2zoom_S1RATIOvsS1COIN	-> GetXaxis() -> SetTitleOffset(1.25);
		h2zoom_S1RATIOvsS1COIN	-> GetYaxis() -> SetTitleOffset(1.25);
		h2zoom_S1RATIOvsS1COIN	-> GetZaxis() -> SetTitleOffset(1.25);
	c1zoom_S1RATIOvsS1COIN->Update();

	TCanvas *c1zoom_S2RATIOvsS2COIN = new TCanvas("c1zoom_S2RATIOvsS2COIN", "c1zoom_S2RATIOvsS2COIN", 0, 0, c1x, c1y);
			 c1zoom_S2RATIOvsS2COIN->SetFillColor(10);
    		 c1zoom_S2RATIOvsS2COIN->SetLogz();
		T1	->Draw("(S2topPE/S2botPE):(S2time_top-S2time_bot)>>h2zoom_S2RATIOvsS2COIN",	"",	"COLZ");
		h2zoom_S2RATIOvsS2COIN	-> GetXaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2zoom_S2RATIOvsS2COIN	-> GetYaxis() -> SetTitle("Ratio of S2 top/bottom");
		h2zoom_S2RATIOvsS2COIN	-> GetZaxis() -> SetTitle("Counts");
		h2zoom_S2RATIOvsS2COIN	-> GetXaxis() -> CenterTitle(true);
		h2zoom_S2RATIOvsS2COIN	-> GetYaxis() -> CenterTitle(true);
		h2zoom_S2RATIOvsS2COIN	-> GetZaxis() -> CenterTitle(true);
		h2zoom_S2RATIOvsS2COIN	-> GetXaxis() -> SetTitleOffset(1.25);
		h2zoom_S2RATIOvsS2COIN	-> GetYaxis() -> SetTitleOffset(1.25);
		h2zoom_S2RATIOvsS2COIN	-> GetZaxis() -> SetTitleOffset(1.25);
	c1zoom_S2RATIOvsS2COIN->Update();

	TCanvas *c1_S2COINvsS1COIN = new TCanvas("c1_S2COINvsS1COIN", "c1_S2COINvsS2COIN", 0, 0, c1x, c1y);
			 c1_S2COINvsS1COIN->SetFillColor(10);
    		 c1_S2COINvsS1COIN->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):(S1time_top-S1time_bot)>>h2_S2COINvsS1COIN",	"",	"COLZ");
		h2_S2COINvsS1COIN	-> GetXaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h2_S2COINvsS1COIN	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2COINvsS1COIN	-> GetZaxis() -> SetTitle("Counts");
		h2_S2COINvsS1COIN	-> GetXaxis() -> CenterTitle(true);
		h2_S2COINvsS1COIN	-> GetYaxis() -> CenterTitle(true);
		h2_S2COINvsS1COIN	-> GetZaxis() -> CenterTitle(true);
		h2_S2COINvsS1COIN	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS1COIN	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS1COIN	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2COINvsS1COIN->Update();

	TCanvas *c1zoom_S2COINvsS1COIN = new TCanvas("c1zoom_S2COINvsS1COIN", "c1zoom_S2COINvsS2COIN", 0, 0, c1x, c1y);
			 c1zoom_S2COINvsS1COIN->SetFillColor(10);
    		 c1zoom_S2COINvsS1COIN->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):(S1time_top-S1time_bot)>>h2zoom_S2COINvsS1COIN",	"",	"COLZ");
		h2zoom_S2COINvsS1COIN	-> GetXaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h2zoom_S2COINvsS1COIN	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2zoom_S2COINvsS1COIN	-> GetZaxis() -> SetTitle("Counts");
		h2zoom_S2COINvsS1COIN	-> GetXaxis() -> CenterTitle(true);
		h2zoom_S2COINvsS1COIN	-> GetYaxis() -> CenterTitle(true);
		h2zoom_S2COINvsS1COIN	-> GetZaxis() -> CenterTitle(true);
		h2zoom_S2COINvsS1COIN	-> GetXaxis() -> SetTitleOffset(1.25);
		h2zoom_S2COINvsS1COIN	-> GetYaxis() -> SetTitleOffset(1.25);
		h2zoom_S2COINvsS1COIN	-> GetZaxis() -> SetTitleOffset(1.25);
	c1zoom_S2COINvsS1COIN->Update();

	TCanvas *c1_S1COINvsDTbot = new TCanvas("c1_S1COINvsDTbot", "c1_S1COINvsDTbot", 0, 0, c1x, c1y);
			 c1_S1COINvsDTbot->SetFillColor(10);
    		 c1_S1COINvsDTbot->SetLogz();
		T1	->Draw("(S1time_top-S1time_bot):dt_bot>>h2_S1COINvsDTbot",	"",	"COLZ");
		h2_S1COINvsDTbot	-> GetXaxis() -> SetTitle("e^{-} drift time, bottom [#mus]");
		h2_S1COINvsDTbot	-> GetYaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h2_S1COINvsDTbot	-> GetZaxis() -> SetTitle("Counts");
		h2_S1COINvsDTbot	-> GetXaxis() -> CenterTitle(true);
		h2_S1COINvsDTbot	-> GetYaxis() -> CenterTitle(true);
		h2_S1COINvsDTbot	-> GetZaxis() -> CenterTitle(true);
		h2_S1COINvsDTbot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S1COINvsDTbot	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S1COINvsDTbot	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S1COINvsDTbot->Update();

	TCanvas *c1zoom_S1COINvsDTbot = new TCanvas("c1zoom_S1COINvsDTbot", "c1zoom_S1COINvsDTbot", 0, 0, c1x, c1y);
			 c1zoom_S1COINvsDTbot->SetFillColor(10);
    		 c1zoom_S1COINvsDTbot->SetLogz();
		T1	->Draw("(S1time_top-S1time_bot):dt_bot>>h2zoom_S1COINvsDTbot",	"",	"COLZ");
		h2zoom_S1COINvsDTbot	-> GetXaxis() -> SetTitle("e^{-} drift time, bottom [#mus]");
		h2zoom_S1COINvsDTbot	-> GetYaxis() -> SetTitle("#DeltaT S1 (top-bottom) [#mus]");
		h2zoom_S1COINvsDTbot	-> GetZaxis() -> SetTitle("Counts");
		h2zoom_S1COINvsDTbot	-> GetXaxis() -> CenterTitle(true);
		h2zoom_S1COINvsDTbot	-> GetYaxis() -> CenterTitle(true);
		h2zoom_S1COINvsDTbot	-> GetZaxis() -> CenterTitle(true);
		h2zoom_S1COINvsDTbot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2zoom_S1COINvsDTbot	-> GetYaxis() -> SetTitleOffset(1.25);
		h2zoom_S1COINvsDTbot	-> GetZaxis() -> SetTitleOffset(1.25);
	c1zoom_S1COINvsDTbot->Update();

	TCanvas *c1_S2COINvsDTbot = new TCanvas("c1_S2COINvsDTbot", "c1_S2COINvsDTbot", 0, 0, c1x, c1y);
			 c1_S2COINvsDTbot->SetFillColor(10);
    		 c1_S2COINvsDTbot->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):dt_bot>>h2_S2COINvsDTbot",	"",	"COLZ");
		h2_S2COINvsDTbot	-> GetXaxis() -> SetTitle("e^{-} drift time, bottom [#mus]");
		h2_S2COINvsDTbot	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2COINvsDTbot	-> GetZaxis() -> SetTitle("Counts");
		h2_S2COINvsDTbot	-> GetXaxis() -> CenterTitle(true);
		h2_S2COINvsDTbot	-> GetYaxis() -> CenterTitle(true);
		h2_S2COINvsDTbot	-> GetZaxis() -> CenterTitle(true);
		h2_S2COINvsDTbot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsDTbot	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsDTbot	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2COINvsDTbot->Update();

	TCanvas *c1zoom_S2COINvsDTbot = new TCanvas("c1zoom_S2COINvsDTbot", "c1zoom_S2COINvsDTbot", 0, 0, c1x, c1y);
			 c1zoom_S2COINvsDTbot->SetFillColor(10);
    		 c1zoom_S2COINvsDTbot->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):dt_bot>>h2zoom_S2COINvsDTbot",	"",	"COLZ");
		h2zoom_S2COINvsDTbot	-> GetXaxis() -> SetTitle("e^{-} drift time, bottom [#mus]");
		h2zoom_S2COINvsDTbot	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2zoom_S2COINvsDTbot	-> GetZaxis() -> SetTitle("Counts");
		h2zoom_S2COINvsDTbot	-> GetXaxis() -> CenterTitle(true);
		h2zoom_S2COINvsDTbot	-> GetYaxis() -> CenterTitle(true);
		h2zoom_S2COINvsDTbot	-> GetZaxis() -> CenterTitle(true);
		h2zoom_S2COINvsDTbot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2zoom_S2COINvsDTbot	-> GetYaxis() -> SetTitleOffset(1.25);
		h2zoom_S2COINvsDTbot	-> GetZaxis() -> SetTitleOffset(1.25);
	c1zoom_S2COINvsDTbot->Update();

	TCanvas *c1_S2COINvsS2heightTop = new TCanvas("c1_S2COINvsS2heightTop", "c1_S2COINvsS2heightTop", 0, 0, c1x, c1y);
			 c1_S2COINvsS2heightTop->SetFillColor(10);
    		 c1_S2COINvsS2heightTop->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):S2height_top>>h2_S2COINvsS2heightTop",	"",	"COLZ");
		h2_S2COINvsS2heightTop	-> GetXaxis() -> SetTitle("S2top height [#mus]");
		h2_S2COINvsS2heightTop	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2COINvsS2heightTop	-> GetZaxis() -> SetTitle("Counts");
		h2_S2COINvsS2heightTop	-> GetXaxis() -> CenterTitle(true);
		h2_S2COINvsS2heightTop	-> GetYaxis() -> CenterTitle(true);
		h2_S2COINvsS2heightTop	-> GetZaxis() -> CenterTitle(true);
		h2_S2COINvsS2heightTop	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2heightTop	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2heightTop	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2COINvsS2heightTop->Update();

	TCanvas *c1_S2COINvsS2heightBot = new TCanvas("c1_S2COINvsS2heightBot", "c1_S2COINvsS2heightBot", 0, 0, c1x, c1y);
			 c1_S2COINvsS2heightBot->SetFillColor(10);
    		 c1_S2COINvsS2heightBot->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):S2height_bot>>h2_S2COINvsS2heightBot",	"",	"COLZ");
		h2_S2COINvsS2heightBot	-> GetXaxis() -> SetTitle("S2bottom height [#mus]");
		h2_S2COINvsS2heightBot	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2COINvsS2heightBot	-> GetZaxis() -> SetTitle("Counts");
		h2_S2COINvsS2heightBot	-> GetXaxis() -> CenterTitle(true);
		h2_S2COINvsS2heightBot	-> GetYaxis() -> CenterTitle(true);
		h2_S2COINvsS2heightBot	-> GetZaxis() -> CenterTitle(true);
		h2_S2COINvsS2heightBot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2heightBot	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2heightBot	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2COINvsS2heightBot->Update();

	TCanvas *c1_S2COINvsS2ASYM = new TCanvas("c1_S2COINvsS2ASYM", "c1_S2COINvsS2ASYM", 0, 0, c1x, c1y);
			 c1_S2COINvsS2ASYM->SetFillColor(10);
    		 c1_S2COINvsS2ASYM->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):S2asym>>h2_S2COINvsS2ASYM",	"",	"COLZ");
		h2_S2COINvsS2ASYM	-> GetXaxis() -> SetTitle("S2 asymmetry");
		h2_S2COINvsS2ASYM	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2COINvsS2ASYM	-> GetZaxis() -> SetTitle("Counts");
		h2_S2COINvsS2ASYM	-> GetXaxis() -> CenterTitle(true);
		h2_S2COINvsS2ASYM	-> GetYaxis() -> CenterTitle(true);
		h2_S2COINvsS2ASYM	-> GetZaxis() -> CenterTitle(true);
		h2_S2COINvsS2ASYM	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2ASYM	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2ASYM	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2COINvsS2ASYM->Update();

	TCanvas *c1_S2ASYMvsS2RATIO = new TCanvas("c1_S2ASYMvsS2RATIO", "c1_S2ASYMvsS2RATIO", 0, 0, c1x, c1y);
			 c1_S2ASYMvsS2RATIO->SetFillColor(10);
    		 c1_S2ASYMvsS2RATIO->SetLogz();
		T1	->Draw("S2asym:(S2topPE/S2botPE)>>h2_S2ASYMvsS2RATIO",	"",	"COLZ");
		h2_S2ASYMvsS2RATIO	-> GetXaxis() -> SetTitle("S2 top/bottom ratio");
		h2_S2ASYMvsS2RATIO	-> GetYaxis() -> SetTitle("S2 asymmetry");
		h2_S2ASYMvsS2RATIO	-> GetZaxis() -> SetTitle("Counts");
		h2_S2ASYMvsS2RATIO	-> GetXaxis() -> CenterTitle(true);
		h2_S2ASYMvsS2RATIO	-> GetYaxis() -> CenterTitle(true);
		h2_S2ASYMvsS2RATIO	-> GetZaxis() -> CenterTitle(true);
		h2_S2ASYMvsS2RATIO	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2ASYMvsS2RATIO	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2ASYMvsS2RATIO	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2ASYMvsS2RATIO->Update();

	TCanvas *c1_S2COINvsS2widthLowBot = new TCanvas("c1_S2COINvsS2widthLowBot", "c1_S2COINvsS2widthLowBot", 0, 0, c1x, c1y);
			 c1_S2COINvsS2widthLowBot->SetFillColor(10);
    		 c1_S2COINvsS2widthLowBot->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):S2widthLow_bot>>h2_S2COINvsS2widthLowBot",	"",	"COLZ");
		h2_S2COINvsS2widthLowBot	-> GetXaxis() -> SetTitle("S2 bottom low width [#mus]");
		h2_S2COINvsS2widthLowBot	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2COINvsS2widthLowBot	-> GetZaxis() -> SetTitle("Counts");
		h2_S2COINvsS2widthLowBot	-> GetXaxis() -> CenterTitle(true);
		h2_S2COINvsS2widthLowBot	-> GetYaxis() -> CenterTitle(true);
		h2_S2COINvsS2widthLowBot	-> GetZaxis() -> CenterTitle(true);
		h2_S2COINvsS2widthLowBot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2widthLowBot	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2widthLowBot	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2COINvsS2widthLowBot->Update();

	TCanvas *c1_S2COINvsS2M2bot = new TCanvas("c1_S2COINvsS2M2bot", "c1_S2COINvsS2M2bot", 0, 0, c1x, c1y);
			 c1_S2COINvsS2M2bot->SetFillColor(10);
    		 c1_S2COINvsS2M2bot->SetLogz();
		T1	->Draw("(S2time_top-S2time_bot):S2M2bot>>h2_S2COINvsS2M2bot",	"",	"COLZ");
		h2_S2COINvsS2M2bot	-> GetXaxis() -> SetTitle("S2 bottom M2 [#mus]");
		h2_S2COINvsS2M2bot	-> GetYaxis() -> SetTitle("#DeltaT S2 (top-bottom) [#mus]");
		h2_S2COINvsS2M2bot	-> GetZaxis() -> SetTitle("Counts");
		h2_S2COINvsS2M2bot	-> GetXaxis() -> CenterTitle(true);
		h2_S2COINvsS2M2bot	-> GetYaxis() -> CenterTitle(true);
		h2_S2COINvsS2M2bot	-> GetZaxis() -> CenterTitle(true);
		h2_S2COINvsS2M2bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2M2bot	-> GetYaxis() -> SetTitleOffset(1.25);
		h2_S2COINvsS2M2bot	-> GetZaxis() -> SetTitleOffset(1.25);
	c1_S2COINvsS2M2bot->Update();


	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_coincidence[500];
	sprintf(outFolder_coincidence, "%s/coincidence", outFolder_dataset);
	char mkdir_outFolder_coincidence[500];
	sprintf(mkdir_outFolder_coincidence, ".mkdir %s", outFolder_coincidence);
	gROOT->ProcessLine(mkdir_outFolder_coincidence);


	char char_DTdif[500];
	char char_DTdif_C[500];

	char char_DTdifZoom[500];
	char char_DTdifZoom_C[500];

	char char_S1coin[500];
	char char_S1coin_C[500];

	char char_S2coin[500];
	char char_S2coin_C[500];

	char char_S1coinZoom[500];
	char char_S1coinZoom_C[500];

	char char_S2coinZoom[500];
	char char_S2coinZoom_C[500];

	char char_S1RATIOvsS1COIN[500];
	char char_S1RATIOvsS1COIN_C[500];

	char char_S2RATIOvsS2COIN[500];
	char char_S2RATIOvsS2COIN_C[500];

	char char_S1RATIOvsS1COINzoom[500];
	char char_S1RATIOvsS1COINzoom_C[500];

	char char_S2RATIOvsS2COINzoom[500];
	char char_S2RATIOvsS2COINzoom_C[500];

	char char_S2COINvsS1COIN[500];
	char char_S2COINvsS1COIN_C[500];

	char char_S2COINvsS1COINzoom[500];
	char char_S2COINvsS1COINzoom_C[500];

	char char_S2COINvsS2heightTop[500];
	char char_S2COINvsS2heightTop_C[500];

	char charZoom_S2COINvsS2heightTop[500];
	char charZoom_S2COINvsS2heightTop_C[500];

	char char_S2COINvsS2heightBot[500];
	char char_S2COINvsS2heightBot_C[500];

	char charZoom_S2COINvsS2heightBot[500];
	char charZoom_S2COINvsS2heightBot_C[500];

	char char_S1COINvsDTtop[500];
	char char_S1COINvsDTtop_C[500];

	char charZoom_S1COINvsDTtop[500];
	char charZoom_S1COINvsDTtop_C[500];

	char char_S1COINvsDTbot[500];
	char char_S1COINvsDTbot_C[500];

	char charZoom_S1COINvsDTbot[500];
	char charZoom_S1COINvsDTbot_C[500];

	char char_S2COINvsDTbot[500];
	char char_S2COINvsDTbot_C[500];
	char charZoom_S2COINvsDTbot[500];
	char charZoom_S2COINvsDTbot_C[500];

	char char_S2COINvsS2ASYM[500];

	char char_S2ASYMvsS2RATIO[500];

	char char_S2COINvsS2widthLowBot[500];
	char char_S2COINvsS2widthLowBot_C[500];
	char char_S2COINvsS2M2bot[500];
	char char_S2COINvsS2M2bot_C[500];

	sprintf(char_DTdif,					"%s/%s_DTdif_%s%s",					outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_DTdif_C,				"%s/%s_DTdif_%s%s",					outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_DTdifZoom,				"%s/%s_DTdifZoom_%s%s",				outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_DTdifZoom_C,			"%s/%s_DTdifZoom_%s%s",				outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1coin,				"%s/%s_S1coin_%s%s",				outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S1coin_C,				"%s/%s_S1coin_%s%s",				outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2coin,				"%s/%s_S2coin_%s%s",				outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2coin_C,				"%s/%s_S2coin_%s%s",				outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1coinZoom,			"%s/%s_S1coinZoom_%s%s",			outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S1coinZoom_C,			"%s/%s_S1coinZoom_%s%s",			outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2coinZoom,			"%s/%s_S2coinZoom_%s%s",			outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2coinZoom_C,			"%s/%s_S2coinZoom_%s%s",			outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1RATIOvsS1COIN,		"%s/%s_S1RATIOvsS1COIN_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S1RATIOvsS1COIN_C,		"%s/%s_S1RATIOvsS1COIN_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2RATIOvsS2COIN,		"%s/%s_S2RATIOvsS2COIN_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2RATIOvsS2COIN_C,		"%s/%s_S2RATIOvsS2COIN_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1RATIOvsS1COINzoom,	"%s/%s_S1RATIOvsS1COINzoom_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S1RATIOvsS1COINzoom_C,	"%s/%s_S1RATIOvsS1COINzoom_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2RATIOvsS2COINzoom,	"%s/%s_S2RATIOvsS2COINzoom_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2RATIOvsS2COINzoom_C,	"%s/%s_S2RATIOvsS2COINzoom_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2COINvsS1COIN,		"%s/%s_S2COINvsS1COIN_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2COINvsS1COIN_C,		"%s/%s_S2COINvsS1COIN_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2COINvsS1COINzoom,	"%s/%s_S2COINvsS1COINzoom_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2COINvsS1COINzoom_C,	"%s/%s_S2COINvsS1COINzoom_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2COINvsS2heightTop,	"%s/%s_S2COINvsS2heightTop_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2COINvsS2heightTop_C,	"%s/%s_S2COINvsS2heightTop_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S2COINvsS2heightBot,	"%s/%s_S2COINvsS2heightBot_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2COINvsS2heightBot_C,	"%s/%s_S2COINvsS2heightBot_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	sprintf(char_S1COINvsDTbot,			"%s/%s_S1COINvsDTbot_%s%s",			outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2COINvsDTbot,			"%s/%s_S2COINvsDTbot_%s%s",			outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(charZoom_S1COINvsDTbot,		"%s/%s_S1COINvsDTbotZOOM_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(charZoom_S2COINvsDTbot,		"%s/%s_S2COINvsDTbotZOOM_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);

	sprintf(char_S2COINvsS2ASYM,		"%s/%s_S2COINvsS2ASYM_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);

	sprintf(char_S2ASYMvsS2RATIO,		"%s/%s_S2ASYMvsS2RATIO_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);

	sprintf(char_S2COINvsS2widthLowBot,		"%s/%s_S2COINvsS2widthLowBot_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2COINvsS2widthLowBot_C,	"%s/%s_S2COINvsS2widthLowBot_%s%s",	outFolder_coincidence, DataSet1, CutName, extensionPlots_C);
	sprintf(char_S2COINvsS2M2bot,			"%s/%s_S2COINvsS2M2bot_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots);
	sprintf(char_S2COINvsS2M2bot_C,			"%s/%s_S2COINvsS2M2bot_%s%s",		outFolder_coincidence, DataSet1, CutName, extensionPlots_C);

	c1_DTdif				->SaveAs(char_DTdif);
	c1_DTdif				->SaveAs(char_DTdif_C);

	c1zoom_DTdif			->SaveAs(char_DTdifZoom);
	c1zoom_DTdif			->SaveAs(char_DTdifZoom_C);

	c1_S1coin				->SaveAs(char_S1coin);
	c1_S1coin				->SaveAs(char_S1coin_C);

	c1_S2coin				->SaveAs(char_S2coin);
	c1_S2coin				->SaveAs(char_S2coin_C);

	c1zoom_S1coin			->SaveAs(char_S1coinZoom);
	c1zoom_S1coin			->SaveAs(char_S1coinZoom_C);

	c1zoom_S2coin			->SaveAs(char_S2coinZoom);
	c1zoom_S2coin			->SaveAs(char_S2coinZoom_C);

	c1_S1RATIOvsS1COIN		->SaveAs(char_S1RATIOvsS1COIN);
	c1_S1RATIOvsS1COIN		->SaveAs(char_S1RATIOvsS1COIN_C);

	c1_S2RATIOvsS2COIN		->SaveAs(char_S2RATIOvsS2COIN);
	c1_S2RATIOvsS2COIN		->SaveAs(char_S2RATIOvsS2COIN_C);

	c1zoom_S1RATIOvsS1COIN	->SaveAs(char_S1RATIOvsS1COINzoom);
	c1zoom_S1RATIOvsS1COIN	->SaveAs(char_S1RATIOvsS1COINzoom_C);

	c1zoom_S2RATIOvsS2COIN	->SaveAs(char_S2RATIOvsS2COINzoom);
	c1zoom_S2RATIOvsS2COIN	->SaveAs(char_S2RATIOvsS2COINzoom_C);

	c1_S2COINvsS1COIN		->SaveAs(char_S2COINvsS1COIN);
	c1_S2COINvsS1COIN		->SaveAs(char_S2COINvsS1COIN_C);

	c1zoom_S2COINvsS1COIN	->SaveAs(char_S2COINvsS1COINzoom);
	c1zoom_S2COINvsS1COIN	->SaveAs(char_S2COINvsS1COINzoom_C);

	c1_S2COINvsS2heightTop	->SaveAs(char_S2COINvsS2heightTop);
	c1_S2COINvsS2heightTop	->SaveAs(char_S2COINvsS2heightTop_C);

	c1_S2COINvsS2heightBot	->SaveAs(char_S2COINvsS2heightBot);
	c1_S2COINvsS2heightBot	->SaveAs(char_S2COINvsS2heightBot_C);

	c1_S1COINvsDTbot		->SaveAs(char_S1COINvsDTbot);
	c1_S2COINvsDTbot		->SaveAs(char_S2COINvsDTbot);
	c1zoom_S1COINvsDTbot	->SaveAs(charZoom_S1COINvsDTbot);
	c1zoom_S2COINvsDTbot	->SaveAs(charZoom_S2COINvsDTbot);

	c1_S2COINvsS2ASYM		->SaveAs(char_S2COINvsS2ASYM);

	c1_S2ASYMvsS2RATIO		->SaveAs(char_S2ASYMvsS2RATIO);

	c1_S2COINvsS2widthLowBot->SaveAs(char_S2COINvsS2widthLowBot);

	c1_S2COINvsS2M2bot		->SaveAs(char_S2COINvsS2M2bot);
