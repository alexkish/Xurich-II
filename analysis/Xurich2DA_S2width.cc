	int nbins_S2width	= 200;
	double min_S2width	= 0.0;
	double max_S2width	= 2.0;

	int nbins_dt		= 200;
	double min_dt		= 0.;
	double max_dt		= 20.0;

	TH2F *h2_S2widthFWHMvsDT_top 	= new TH2F("h2_S2widthFWHMvsDT_top",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S2widthFWHMvsDT_bot 	= new TH2F("h2_S2widthFWHMvsDT_bot",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S2widthFWTMvsDT_top 	= new TH2F("h2_S2widthFWTMvsDT_top",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S2widthFWTMvsDT_bot 	= new TH2F("h2_S2widthFWTMvsDT_bot",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S2widthM2vsDT_top   	= new TH2F("h2_S2widthM2vsDT_top",		DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S2widthM2vsDT_bot   	= new TH2F("h2_S2widthM2vsDT_bot",		DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);


	TH2F *h2_S21widthFWHMvsDT_top 	= new TH2F("h2_S21widthFWHMvsDT_top",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S21widthFWHMvsDT_bot 	= new TH2F("h2_S21widthFWHMvsDT_bot",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S21widthFWTMvsDT_top 	= new TH2F("h2_S21widthFWTMvsDT_top",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S21widthFWTMvsDT_bot 	= new TH2F("h2_S21widthFWTMvsDT_bot",	DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S21widthM2vsDT_top   	= new TH2F("h2_S21widthM2vsDT_top",		DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width*3);
	TH2F *h2_S21widthM2vsDT_bot   	= new TH2F("h2_S21widthM2vsDT_bot",		DataSetName1, nbins_dt, min_dt, max_dt, nbins_S2width, min_S2width, max_S2width*3);


	TH2F *h2_S20_FWHMvsFWTM_top 	= new TH2F("h2_S20_FWHMvsFWTM_top",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S20_FWHMvsFWTM_bot 	= new TH2F("h2_S20_FWHMvsFWTM_bot",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S20_M2vsFWTM_top 		= new TH2F("h2_S20_M2vsFWTM_top",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S20_M2vsFWTM_bot 		= new TH2F("h2_S20_M2vsFWTM_bot",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S20_M2vsFWHM_top 		= new TH2F("h2_S20_M2vsFWHM_top",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S20_M2vsFWHM_bot 		= new TH2F("h2_S20_M2vsFWHM_bot",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);


	TH2F *h2_S21_FWHMvsFWTM_top 	= new TH2F("h2_S21_FWHMvsFWTM_top",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S21_FWHMvsFWTM_bot 	= new TH2F("h2_S21_FWHMvsFWTM_bot",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S21_M2vsFWTM_top 		= new TH2F("h2_S21_M2vsFWTM_top",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S21_M2vsFWTM_bot 		= new TH2F("h2_S21_M2vsFWTM_bot",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);

	TH2F *h2_S21_M2vsFWHM_top 		= new TH2F("h2_S21_M2vsFWHM_top",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);
	TH2F *h2_S21_M2vsFWHM_bot 		= new TH2F("h2_S21_M2vsFWHM_bot",		DataSetName1, nbins_S2width, min_S2width, max_S2width, nbins_S2width, min_S2width, max_S2width);


	int canX = 700;
	int canY = 500;

	TCanvas *c_S2widthFWHMvsDT_top = new TCanvas("c_S2widthFWHMvsDT_top", "c_S2widthFWHMvsDT_top", 0, 0, canX, canY);
			 c_S2widthFWHMvsDT_top->SetFillColor(10);
    		 c_S2widthFWHMvsDT_top->SetLogz();
		T1 ->Draw("S2width_top:dt_top>>h2_S2widthFWHMvsDT_top",	cut_all,	"colz");
		h2_S2widthFWHMvsDT_top	-> GetXaxis() -> SetTitle("drift time, top [#mus]");
		h2_S2widthFWHMvsDT_top	-> GetYaxis() -> SetTitle("S2[0] FWHM, top [#mus]");
		h2_S2widthFWHMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S2widthFWHMvsDT_top	-> GetYaxis() -> CenterTitle(true);
		h2_S2widthFWHMvsDT_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2widthFWHMvsDT_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2widthFWHMvsDT_top->Update();

	TCanvas *c_S2widthFWHMvsDT_bot = new TCanvas("c_S2widthFWHMvsDT_bot", "c_S2widthFWHMvsDT_bot", 0, 0, canX, canY);
			 c_S2widthFWHMvsDT_bot->SetFillColor(10);
    		 c_S2widthFWHMvsDT_bot->SetLogz();
		T1 ->Draw("S2width_bot:dt_bot>>h2_S2widthFWHMvsDT_bot",	cut_all,	"colz");
		h2_S2widthFWHMvsDT_bot	-> GetXaxis() -> SetTitle("drift time, bottom [#mus]");
		h2_S2widthFWHMvsDT_bot	-> GetYaxis() -> SetTitle("S2[0] FWHM, bottom [#mus]");
		h2_S2widthFWHMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S2widthFWHMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S2widthFWHMvsDT_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2widthFWHMvsDT_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2widthFWHMvsDT_top->Update();

	TCanvas *c_S2widthFWTMvsDT_top = new TCanvas("c_S2widthFWTMvsDT_top", "c_S2widthFWTMvsDT_top", 0, 0, canX, canY);
			 c_S2widthFWTMvsDT_top->SetFillColor(10);
    		 c_S2widthFWTMvsDT_top->SetLogz();
		T1 ->Draw("S2widthLow_top:dt_top>>h2_S2widthFWTMvsDT_top",	cut_all,	"colz");
		h2_S2widthFWTMvsDT_top	-> GetXaxis() -> SetTitle("drift time, top [#mus]");
		h2_S2widthFWTMvsDT_top	-> GetYaxis() -> SetTitle("S2[0] FWTM, top [#mus]");
		h2_S2widthFWTMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S2widthFWTMvsDT_top	-> GetYaxis() -> CenterTitle(true);
		h2_S2widthFWTMvsDT_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2widthFWTMvsDT_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2widthFWTMvsDT_top->Update();

	TCanvas *c_S2widthFWTMvsDT_bot = new TCanvas("c_S2widthFWTMvsDT_bot", "c_S2widthFWTMvsDT_bot", 0, 0, canX, canY);
			 c_S2widthFWTMvsDT_bot->SetFillColor(10);
    		 c_S2widthFWTMvsDT_bot->SetLogz();
		T1 ->Draw("S2widthLow_bot:dt_bot>>h2_S2widthFWTMvsDT_bot",	cut_all,	"colz");
		h2_S2widthFWTMvsDT_bot	-> GetXaxis() -> SetTitle("drift time, bottom [#mus]");
		h2_S2widthFWTMvsDT_bot	-> GetYaxis() -> SetTitle("S2[0] FWTM, bottom [#mus]");
		h2_S2widthFWTMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S2widthFWTMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S2widthFWTMvsDT_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2widthFWTMvsDT_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2widthFWTMvsDT_bot->Update();

	TCanvas *c_S2widthM2vsDT_top = new TCanvas("c_S2widthM2vsDT_top", "c_S2widthM2vsDT_top", 0, 0, canX, canY);
			 c_S2widthM2vsDT_top->SetFillColor(10);
    		 c_S2widthM2vsDT_top->SetLogz();
		T1 ->Draw("S2M2top:dt_top>>h2_S2widthM2vsDT_top",	cut_all,	"colz");
		h2_S2widthM2vsDT_top	-> GetXaxis() -> SetTitle("drift time, top [#mus]");
		h2_S2widthM2vsDT_top	-> GetYaxis() -> SetTitle("S2[0] M2, top [#mus]");
		h2_S2widthM2vsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S2widthM2vsDT_top	-> GetYaxis() -> CenterTitle(true);
		h2_S2widthM2vsDT_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2widthM2vsDT_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2widthM2vsDT_top->Update();

	TCanvas *c_S2widthM2vsDT_bot = new TCanvas("c_S2widthM2vsDT_bot", "c_S2widthM2vsDT_top", 0, 0, canX, canY);
			 c_S2widthM2vsDT_bot->SetFillColor(10);
    		 c_S2widthM2vsDT_bot->SetLogz();
		T1 ->Draw("S2M2bot:dt_bot>>h2_S2widthM2vsDT_bot",	cut_all,	"colz");
		h2_S2widthM2vsDT_bot	-> GetXaxis() -> SetTitle("drift time, bottom [#mus]");
		h2_S2widthM2vsDT_bot	-> GetYaxis() -> SetTitle("S2[0] M2, bottom [#mus]");
		h2_S2widthM2vsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S2widthM2vsDT_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S2widthM2vsDT_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S2widthM2vsDT_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S2widthM2vsDT_bot->Update();


	// 2nd S2
	TCanvas *c_S21widthFWHMvsDT_top = new TCanvas("c_S21widthFWHMvsDT_top", "c_S21widthFWHMvsDT_top", 0, 0, canX, canY);
			 c_S21widthFWHMvsDT_top->SetFillColor(10);
    		 c_S21widthFWHMvsDT_top->SetLogz();
		T1 ->Draw("S21width_top:dt1_top>>h2_S21widthFWHMvsDT_top",	cut_all,	"colz");
		h2_S21widthFWHMvsDT_top	-> GetXaxis() -> SetTitle("drift time, top [#mus]");
		h2_S21widthFWHMvsDT_top	-> GetYaxis() -> SetTitle("S2[1] FWHM, top [#mus]");
		h2_S21widthFWHMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21widthFWHMvsDT_top	-> GetYaxis() -> CenterTitle(true);
		h2_S21widthFWHMvsDT_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21widthFWHMvsDT_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21widthFWHMvsDT_top->Update();

	TCanvas *c_S21widthFWHMvsDT_bot = new TCanvas("c_S21widthFWHMvsDT_bot", "c_S21widthFWHMvsDT_bot", 0, 0, canX, canY);
			 c_S21widthFWHMvsDT_bot->SetFillColor(10);
    		 c_S21widthFWHMvsDT_bot->SetLogz();
		T1 ->Draw("S21width_bot:dt1_bot>>h2_S21widthFWHMvsDT_bot",	cut_all,	"colz");
		h2_S21widthFWHMvsDT_bot	-> GetXaxis() -> SetTitle("drift time, bottom [#mus]");
		h2_S21widthFWHMvsDT_bot	-> GetYaxis() -> SetTitle("S2[1] FWHM, bottom [#mus]");
		h2_S21widthFWHMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21widthFWHMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S21widthFWHMvsDT_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21widthFWHMvsDT_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21widthFWHMvsDT_top->Update();

	TCanvas *c_S21widthFWTMvsDT_top = new TCanvas("c_S21widthFWTMvsDT_top", "c_S21widthFWTMvsDT_top", 0, 0, canX, canY);
			 c_S21widthFWTMvsDT_top->SetFillColor(10);
    		 c_S21widthFWTMvsDT_top->SetLogz();
		T1 ->Draw("S21widthLow_top:dt1_top>>h2_S21widthFWTMvsDT_top",	cut_all,	"colz");
		h2_S21widthFWTMvsDT_top	-> GetXaxis() -> SetTitle("drift time, top [#mus]");
		h2_S21widthFWTMvsDT_top	-> GetYaxis() -> SetTitle("S2[1] FWTM, top [#mus]");
		h2_S21widthFWTMvsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21widthFWTMvsDT_top	-> GetYaxis() -> CenterTitle(true);
		h2_S21widthFWTMvsDT_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21widthFWTMvsDT_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21widthFWTMvsDT_top->Update();

	TCanvas *c_S21widthFWTMvsDT_bot = new TCanvas("c_S21widthFWTMvsDT_bot", "c_S21widthFWTMvsDT_bot", 0, 0, canX, canY);
			 c_S21widthFWTMvsDT_bot->SetFillColor(10);
    		 c_S21widthFWTMvsDT_bot->SetLogz();
		T1 ->Draw("S21widthLow_bot:dt1_bot>>h2_S21widthFWTMvsDT_bot",	cut_all,	"colz");
		h2_S21widthFWTMvsDT_bot	-> GetXaxis() -> SetTitle("drift time, bottom [#mus]");
		h2_S21widthFWTMvsDT_bot	-> GetYaxis() -> SetTitle("S2[1] FWTM, bottom [#mus]");
		h2_S21widthFWTMvsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21widthFWTMvsDT_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S21widthFWTMvsDT_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21widthFWTMvsDT_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21widthFWTMvsDT_bot->Update();

	TCanvas *c_S21widthM2vsDT_top = new TCanvas("c_S21widthM2vsDT_top", "c_S21widthM2vsDT_top", 0, 0, canX, canY);
			 c_S21widthM2vsDT_top->SetFillColor(10);
    		 c_S21widthM2vsDT_top->SetLogz();
		T1 ->Draw("S21M2top:dt1_top>>h2_S21widthM2vsDT_top",	cut_all,	"colz");
		h2_S21widthM2vsDT_top	-> GetXaxis() -> SetTitle("drift time, top [#mus]");
		h2_S21widthM2vsDT_top	-> GetYaxis() -> SetTitle("S2[1] M2, top [#mus]");
		h2_S21widthM2vsDT_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21widthM2vsDT_top	-> GetYaxis() -> CenterTitle(true);
		h2_S21widthM2vsDT_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21widthM2vsDT_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21widthM2vsDT_top->Update();

	TCanvas *c_S21widthM2vsDT_bot = new TCanvas("c_S21widthM2vsDT_bot", "c_S21widthM2vsDT_top", 0, 0, canX, canY);
			 c_S21widthM2vsDT_bot->SetFillColor(10);
    		 c_S21widthM2vsDT_bot->SetLogz();
		T1 ->Draw("S21M2bot:dt1_bot>>h2_S21widthM2vsDT_bot",	cut_all,	"colz");
		h2_S21widthM2vsDT_bot	-> GetXaxis() -> SetTitle("drift time, bottom [#mus]");
		h2_S21widthM2vsDT_bot	-> GetYaxis() -> SetTitle("S2[1] M2, bottom [#mus]");
		h2_S21widthM2vsDT_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21widthM2vsDT_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S21widthM2vsDT_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21widthM2vsDT_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21widthM2vsDT_bot->Update();

	////////////////////////////////
	// WIDTH vs WIDTH parameters

	// S2[0]
	TCanvas *c_S20_FWHMvsFWTM_top = new TCanvas("c_S20_FWHMvsFWTM_top", "c_S20_FWHMvsFWTM_top", 0, 0, canX, canY);
			 c_S20_FWHMvsFWTM_top->SetFillColor(10);
    		 c_S20_FWHMvsFWTM_top->SetLogz();
		T1 ->Draw("S2width_top:S2widthLow_top>>h2_S20_FWHMvsFWTM_top",	cut_all,	"colz");
		h2_S20_FWHMvsFWTM_top	-> GetXaxis() -> SetTitle("S2[0] top, FWTM [#mus]");
		h2_S20_FWHMvsFWTM_top	-> GetYaxis() -> SetTitle("S2[0] top, FWHM [#mus]");
		h2_S20_FWHMvsFWTM_top	-> GetXaxis() -> CenterTitle(true);
		h2_S20_FWHMvsFWTM_top	-> GetYaxis() -> CenterTitle(true);
		h2_S20_FWHMvsFWTM_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S20_FWHMvsFWTM_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S20_FWHMvsFWTM_top->Update();

	TCanvas *c_S20_FWHMvsFWTM_bot = new TCanvas("c_S20_FWHMvsFWTM_bot", "c_S20_FWHMvsFWTM_bot", 0, 0, canX, canY);
			 c_S20_FWHMvsFWTM_bot->SetFillColor(10);
    		 c_S20_FWHMvsFWTM_bot->SetLogz();
		T1 ->Draw("S2width_bot:S2widthLow_bot>>h2_S20_FWHMvsFWTM_bot",	cut_all,	"colz");
		h2_S20_FWHMvsFWTM_bot	-> GetXaxis() -> SetTitle("S2[0] bottom, FWTM [#mus]");
		h2_S20_FWHMvsFWTM_bot	-> GetYaxis() -> SetTitle("S2[0] bottom, FWHM [#mus]");
		h2_S20_FWHMvsFWTM_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S20_FWHMvsFWTM_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S20_FWHMvsFWTM_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S20_FWHMvsFWTM_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S20_FWHMvsFWTM_bot->Update();


	TCanvas *c_S20_M2vsFWHM_top = new TCanvas("c_S20_M2vsFWHM_top", "c_S20_M2vsFWHM_top", 0, 0, canX, canY);
			 c_S20_M2vsFWHM_top->SetFillColor(10);
    		 c_S20_M2vsFWHM_top->SetLogz();
		T1 ->Draw("S2M2top:S2width_top>>h2_S20_M2vsFWHM_top",	cut_all,	"colz");
		h2_S20_M2vsFWHM_top	-> GetXaxis() -> SetTitle("S2[0] top, FWHM [#mus]");
		h2_S20_M2vsFWHM_top	-> GetYaxis() -> SetTitle("S2[0] top, M2 [#mus]");
		h2_S20_M2vsFWHM_top	-> GetXaxis() -> CenterTitle(true);
		h2_S20_M2vsFWHM_top	-> GetYaxis() -> CenterTitle(true);
		h2_S20_M2vsFWHM_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S20_M2vsFWHM_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S20_M2vsFWHM_top->Update();

	TCanvas *c_S20_M2vsFWHM_bot = new TCanvas("c_S20_M2vsFWHM_bot", "c_S20_M2vsFWHM_bot", 0, 0, canX, canY);
			 c_S20_M2vsFWHM_bot->SetFillColor(10);
    		 c_S20_M2vsFWHM_bot->SetLogz();
		T1 ->Draw("S2M2bot:S2width_bot>>h2_S20_M2vsFWHM_bot",	cut_all,	"colz");
		h2_S20_M2vsFWHM_bot	-> GetXaxis() -> SetTitle("S2[0] bottom, FWHM [#mus]");
		h2_S20_M2vsFWHM_bot	-> GetYaxis() -> SetTitle("S2[0] bottom, M2 [#mus]");
		h2_S20_M2vsFWHM_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S20_M2vsFWHM_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S20_M2vsFWHM_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S20_M2vsFWHM_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S20_M2vsFWHM_bot->Update();


	TCanvas *c_S20_M2vsFWTM_top = new TCanvas("c_S20_M2vsFWTM_top", "c_S20_M2vsFWTM_top", 0, 0, canX, canY);
			 c_S20_M2vsFWTM_top->SetFillColor(10);
    		 c_S20_M2vsFWTM_top->SetLogz();
		T1 ->Draw("S2M2top:S2widthLow_top>>h2_S20_M2vsFWTM_top",	cut_all,	"colz");
		h2_S20_M2vsFWTM_top	-> GetXaxis() -> SetTitle("S2[0] top, FWTM [#mus]");
		h2_S20_M2vsFWTM_top	-> GetYaxis() -> SetTitle("S2[0] top, M2 [#mus]");
		h2_S20_M2vsFWTM_top	-> GetXaxis() -> CenterTitle(true);
		h2_S20_M2vsFWTM_top	-> GetYaxis() -> CenterTitle(true);
		h2_S20_M2vsFWTM_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S20_M2vsFWTM_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S20_M2vsFWTM_top->Update();

	TCanvas *c_S20_M2vsFWTM_bot = new TCanvas("c_S20_M2vsFWTM_bot", "c_S20_M2vsFWTM_bot", 0, 0, canX, canY);
			 c_S20_M2vsFWTM_bot->SetFillColor(10);
    		 c_S20_M2vsFWTM_bot->SetLogz();
		T1 ->Draw("S2M2bot:S2widthLow_bot>>h2_S20_M2vsFWTM_bot",	cut_all,	"colz");
		h2_S20_M2vsFWTM_bot	-> GetXaxis() -> SetTitle("S2[0] bottom, FWTM [#mus]");
		h2_S20_M2vsFWTM_bot	-> GetYaxis() -> SetTitle("S2[0] bottom, M2 [#mus]");
		h2_S20_M2vsFWTM_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S20_M2vsFWTM_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S20_M2vsFWTM_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S20_M2vsFWTM_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S20_M2vsFWTM_bot->Update();


	// S2[1]
	TCanvas *c_S21_FWHMvsFWTM_top = new TCanvas("c_S21_FWHMvsFWTM_top", "c_S21_FWHMvsFWTM_top", 0, 0, canX, canY);
			 c_S21_FWHMvsFWTM_top->SetFillColor(10);
    		 c_S21_FWHMvsFWTM_top->SetLogz();
		T1 ->Draw("S21width_top:S21widthLow_top>>h2_S21_FWHMvsFWTM_top",	cut_all,	"colz");
		h2_S21_FWHMvsFWTM_top	-> GetXaxis() -> SetTitle("S2[1] top, FWTM [#mus]");
		h2_S21_FWHMvsFWTM_top	-> GetYaxis() -> SetTitle("S2[1] top, FWHM [#mus]");
		h2_S21_FWHMvsFWTM_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21_FWHMvsFWTM_top	-> GetYaxis() -> CenterTitle(true);
		h2_S21_FWHMvsFWTM_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21_FWHMvsFWTM_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21_FWHMvsFWTM_top->Update();

	TCanvas *c_S21_FWHMvsFWTM_bot = new TCanvas("c_S21_FWHMvsFWTM_bot", "c_S21_FWHMvsFWTM_bot", 0, 0, canX, canY);
			 c_S21_FWHMvsFWTM_bot->SetFillColor(10);
    		 c_S21_FWHMvsFWTM_bot->SetLogz();
		T1 ->Draw("S21width_bot:S21widthLow_bot>>h2_S21_FWHMvsFWTM_bot",	cut_all,	"colz");
		h2_S21_FWHMvsFWTM_bot	-> GetXaxis() -> SetTitle("S2[1] bottom, FWTM [#mus]");
		h2_S21_FWHMvsFWTM_bot	-> GetYaxis() -> SetTitle("S2[1] bottom, FWHM [#mus]");
		h2_S21_FWHMvsFWTM_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21_FWHMvsFWTM_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S21_FWHMvsFWTM_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21_FWHMvsFWTM_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21_FWHMvsFWTM_bot->Update();


	TCanvas *c_S21_M2vsFWHM_top = new TCanvas("c_S21_M2vsFWHM_top", "c_S21_M2vsFWHM_top", 0, 0, canX, canY);
			 c_S21_M2vsFWHM_top->SetFillColor(10);
    		 c_S21_M2vsFWHM_top->SetLogz();
		T1 ->Draw("S21M2top:S21width_top>>h2_S21_M2vsFWHM_top",	cut_all,	"colz");
		h2_S21_M2vsFWHM_top	-> GetXaxis() -> SetTitle("S2[1] top, FWHM [#mus]");
		h2_S21_M2vsFWHM_top	-> GetYaxis() -> SetTitle("S2[1] top, M2 [#mus]");
		h2_S21_M2vsFWHM_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21_M2vsFWHM_top	-> GetYaxis() -> CenterTitle(true);
		h2_S21_M2vsFWHM_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21_M2vsFWHM_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21_M2vsFWHM_top->Update();

	TCanvas *c_S21_M2vsFWHM_bot = new TCanvas("c_S21_M2vsFWHM_bot", "c_S21_M2vsFWHM_bot", 0, 0, canX, canY);
			 c_S21_M2vsFWHM_bot->SetFillColor(10);
    		 c_S21_M2vsFWHM_bot->SetLogz();
		T1 ->Draw("S21M2bot:S21width_bot>>h2_S21_M2vsFWHM_bot",	cut_all,	"colz");
		h2_S21_M2vsFWHM_bot	-> GetXaxis() -> SetTitle("S2[1] bottom, FWHM [#mus]");
		h2_S21_M2vsFWHM_bot	-> GetYaxis() -> SetTitle("S2[1] bottom, M2 [#mus]");
		h2_S21_M2vsFWHM_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21_M2vsFWHM_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S21_M2vsFWHM_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21_M2vsFWHM_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21_M2vsFWHM_bot->Update();


	TCanvas *c_S21_M2vsFWTM_top = new TCanvas("c_S21_M2vsFWTM_top", "c_S21_M2vsFWTM_top", 0, 0, canX, canY);
			 c_S21_M2vsFWTM_top->SetFillColor(10);
    		 c_S21_M2vsFWTM_top->SetLogz();
		T1 ->Draw("S21M2top:S21widthLow_top>>h2_S21_M2vsFWTM_top",	cut_all,	"colz");
		h2_S21_M2vsFWTM_top	-> GetXaxis() -> SetTitle("S2[1] top, FWTM [#mus]");
		h2_S21_M2vsFWTM_top	-> GetYaxis() -> SetTitle("S2[1] top, M2 [#mus]");
		h2_S21_M2vsFWTM_top	-> GetXaxis() -> CenterTitle(true);
		h2_S21_M2vsFWTM_top	-> GetYaxis() -> CenterTitle(true);
		h2_S21_M2vsFWTM_top	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21_M2vsFWTM_top	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21_M2vsFWTM_top->Update();

	TCanvas *c_S21_M2vsFWTM_bot = new TCanvas("c_S21_M2vsFWTM_bot", "c_S21_M2vsFWTM_bot", 0, 0, canX, canY);
			 c_S21_M2vsFWTM_bot->SetFillColor(10);
    		 c_S21_M2vsFWTM_bot->SetLogz();
		T1 ->Draw("S21M2bot:S21widthLow_bot>>h2_S21_M2vsFWTM_bot",	cut_all,	"colz");
		h2_S21_M2vsFWTM_bot	-> GetXaxis() -> SetTitle("S2[1] bottom, FWTM [#mus]");
		h2_S21_M2vsFWTM_bot	-> GetYaxis() -> SetTitle("S2[1] bottom, M2 [#mus]");
		h2_S21_M2vsFWTM_bot	-> GetXaxis() -> CenterTitle(true);
		h2_S21_M2vsFWTM_bot	-> GetYaxis() -> CenterTitle(true);
		h2_S21_M2vsFWTM_bot	-> GetXaxis() -> SetTitleOffset(1.25);
		h2_S21_M2vsFWTM_bot	-> GetYaxis() -> SetTitleOffset(1.25);
	c_S21_M2vsFWTM_bot->Update();


	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_S2width[500];
	sprintf(outFolder_S2width, "%s/S2width_Kr83m", outFolder_dataset);
	char mkdir_outFolder_S2width[500];
	sprintf(mkdir_outFolder_S2width, ".mkdir %s", outFolder_S2width);
	gROOT->ProcessLine(mkdir_outFolder_S2width);

	char char_S2widthFWHMvsDT_top[500];
	char char_S2widthFWHMvsDT_bot[500];

	char char_S2widthFWTMvsDT_top[500];
	char char_S2widthFWTMvsDT_bot[500];

	char char_S2widthM2vsDT_top[500];
	char char_S2widthM2vsDT_bot[500];


	char char_S21widthFWHMvsDT_top[500];
	char char_S21widthFWHMvsDT_bot[500];

	char char_S21widthFWTMvsDT_top[500];
	char char_S21widthFWTMvsDT_bot[500];

	char char_S21widthM2vsDT_top[500];
	char char_S21widthM2vsDT_bot[500];


	char char_S20_FWHMvsFWTM_top[500];
	char char_S20_FWHMvsFWTM_bot[500];

	char char_S20_M2vsFWHM_top[500];
	char char_S20_M2vsFWHM_bot[500];

	char char_S20_M2vsFWTM_top[500];
	char char_S20_M2vsFWTM_bot[500];


	char char_S21_FWHMvsFWTM_top[500];
	char char_S21_FWHMvsFWTM_bot[500];

	char char_S21_M2vsFWHM_top[500];
	char char_S21_M2vsFWHM_bot[500];

	char char_S21_M2vsFWTM_top[500];
	char char_S21_M2vsFWTM_bot[500];


	sprintf(char_S2widthFWHMvsDT_top,	"%s/%s_S2widthFWHMvsDT_top_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S2widthFWHMvsDT_bot,	"%s/%s_S2widthFWHMvsDT_bot_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S2widthFWTMvsDT_top,	"%s/%s_S2widthFWTMvsDT_top_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S2widthFWTMvsDT_bot,	"%s/%s_S2widthFWTMvsDT_bot_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S2widthM2vsDT_top,		"%s/%s_S2widthM2vsDT_top_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S2widthM2vsDT_bot,		"%s/%s_S2widthM2vsDT_bot_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);


	sprintf(char_S21widthFWHMvsDT_top,	"%s/%s_S21widthFWHMvsDT_top_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S21widthFWHMvsDT_bot,	"%s/%s_S21widthFWHMvsDT_bot_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S21widthFWTMvsDT_top,	"%s/%s_S21widthFWTMvsDT_top_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S21widthFWTMvsDT_bot,	"%s/%s_S21widthFWTMvsDT_bot_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S21widthM2vsDT_top,	"%s/%s_S21widthM2vsDT_top_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S21widthM2vsDT_bot,	"%s/%s_S21widthM2vsDT_bot_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);


	sprintf(char_S20_FWHMvsFWTM_top,	"%s/%s_S20_FWHMvsFWTM_top_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S20_FWHMvsFWTM_bot,	"%s/%s_S20_FWHMvsFWTM_bot_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S20_M2vsFWHM_top,		"%s/%s_S20_M2vsFWHM_top_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S20_M2vsFWHM_bot,		"%s/%s_S20_M2vsFWHM_bot_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S20_M2vsFWTM_top,		"%s/%s_S20_M2vsFWTM_top_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S20_M2vsFWTM_bot,		"%s/%s_S20_M2vsFWTM_bot_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);


	sprintf(char_S21_FWHMvsFWTM_top,	"%s/%s_S21_FWHMvsFWTM_top_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S21_FWHMvsFWTM_bot,	"%s/%s_S21_FWHMvsFWTM_bot_%s%s",	outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S21_M2vsFWHM_top,		"%s/%s_S21_M2vsFWHM_top_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S21_M2vsFWHM_bot,		"%s/%s_S21_M2vsFWHM_bot_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);

	sprintf(char_S21_M2vsFWTM_top,		"%s/%s_S21_M2vsFWTM_top_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);
	sprintf(char_S21_M2vsFWTM_bot,		"%s/%s_S21_M2vsFWTM_bot_%s%s",		outFolder_S2width, DataSet1, CutName, extensionPlots);


	c_S2widthFWHMvsDT_top	->SaveAs(char_S2widthFWHMvsDT_top);
	c_S2widthFWHMvsDT_bot	->SaveAs(char_S2widthFWHMvsDT_bot);

	c_S2widthFWTMvsDT_top	->SaveAs(char_S2widthFWTMvsDT_top);
	c_S2widthFWTMvsDT_bot	->SaveAs(char_S2widthFWTMvsDT_bot);

	c_S2widthM2vsDT_top		->SaveAs(char_S2widthM2vsDT_top);
	c_S2widthM2vsDT_bot		->SaveAs(char_S2widthM2vsDT_bot);


	c_S21widthFWHMvsDT_top	->SaveAs(char_S21widthFWHMvsDT_top);
	c_S21widthFWHMvsDT_bot	->SaveAs(char_S21widthFWHMvsDT_bot);

	c_S21widthFWTMvsDT_top	->SaveAs(char_S21widthFWTMvsDT_top);
	c_S21widthFWTMvsDT_bot	->SaveAs(char_S21widthFWTMvsDT_bot);

	c_S21widthM2vsDT_top	->SaveAs(char_S21widthM2vsDT_top);
	c_S21widthM2vsDT_bot	->SaveAs(char_S21widthM2vsDT_bot);


	c_S20_FWHMvsFWTM_top	->SaveAs(char_S20_FWHMvsFWTM_top);
	c_S20_FWHMvsFWTM_bot	->SaveAs(char_S20_FWHMvsFWTM_bot);

	c_S20_M2vsFWHM_top		->SaveAs(char_S20_M2vsFWHM_top);
	c_S20_M2vsFWHM_bot		->SaveAs(char_S20_M2vsFWHM_bot);

	c_S20_M2vsFWTM_top		->SaveAs(char_S20_M2vsFWTM_top);
	c_S20_M2vsFWTM_bot		->SaveAs(char_S20_M2vsFWTM_bot);


	c_S21_FWHMvsFWTM_top	->SaveAs(char_S21_FWHMvsFWTM_top);
	c_S21_FWHMvsFWTM_bot	->SaveAs(char_S21_FWHMvsFWTM_bot);

	c_S21_M2vsFWHM_top		->SaveAs(char_S21_M2vsFWHM_top);
	c_S21_M2vsFWHM_bot		->SaveAs(char_S21_M2vsFWHM_bot);

	c_S21_M2vsFWTM_top		->SaveAs(char_S21_M2vsFWTM_top);
	c_S21_M2vsFWTM_bot		->SaveAs(char_S21_M2vsFWTM_bot);




