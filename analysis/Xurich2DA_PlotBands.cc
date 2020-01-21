	int nbins_S1		= 500;
	double min_S1		= 0;
	double max_S1		= 1e3;

	int nbins_S2		= 400;
	double min_S2		= 0;
	double max_S2		= 5.0e5;

	int nbins_S2bot		= 400;
	double min_S2bot	= 0;
	double max_S2bot	= 5.0e5;

	double max_logS2S1	= 3.5;

	TH2F *h2_S2vsS1 			= new TH2F("h2_S2vsS1",				DataSetName1, 	nbins_S1, 		min_S1, max_S1, nbins_S2, 		min_S2, max_S2);
	TH2F *h2_S2vsCS1 			= new TH2F("h2_S2vsCS1",			DataSetName1, 	nbins_S1, 		min_S1, max_S1, nbins_S2, 		min_S2, max_S2);
	TH2F *h2_LogS2S1vsS1 		= new TH2F("h2_LogS2S1vsS1",		DataSetName1, 	nbins_S1/2, 	min_S1, max_S1, nbins_S2/2, 	0.0, 	max_logS2S1);
	TH2F *h2_LogS2S1vsCS1 		= new TH2F("h2_LogS2S1vsS1",		DataSetName1, 	nbins_S1/2, 	min_S1, max_S1, nbins_S2/2, 	0.0, 	max_logS2S1);
	TH2F *h2_LogS2S1vsCS1_scat 	= new TH2F("h2_LogS2S1vsCS1_scat",	DataSetName1, 	nbins_S1*10, 	min_S1, max_S1, nbins_S2*10, 	0.0, 	max_logS2S1);
		  h2_LogS2S1vsCS1_scat ->SetMarkerStyle(4);
		  h2_LogS2S1vsCS1_scat ->SetMarkerSize(0.6);
		  h2_LogS2S1vsCS1_scat ->SetMarkerColor(2);

	//////////////////////////////////////////////////////////////////////////////////////
	// SAVE PLOTS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s_%s", DataSet1, CutName);
	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_dataset);

	char outFolder_bands[500];
	sprintf(outFolder_bands, "%s/bands", outFolder_dataset);
	char mkdir_outFolder_bands[500];
	sprintf(mkdir_outFolder_bands, ".mkdir %s", outFolder_bands);
	gROOT->ProcessLine(mkdir_outFolder_bands);

	char char_S2vsS1[500];
	char char_S2vsCS1[500];
	char char_LogS2vsS1[500];
	char char_LogS2vsCS1[500];
	char char_LogS2vsCS1_scat[500];

	sprintf(char_S2vsS1,		"%s/%s_S2vsS1_%s%s",		outFolder_bands, DataSet1, CutName, extensionPlots);
	sprintf(char_S2vsCS1,		"%s/%s_S2vsCS1_%s%s",		outFolder_bands, DataSet1, CutName, extensionPlots);
	sprintf(char_LogS2vsS1,		"%s/%s_LogS2vsS1_%s%s",		outFolder_bands, DataSet1, CutName, extensionPlots);
	sprintf(char_LogS2vsCS1,	"%s/%s_LogS2vsCS1_%s%s",	outFolder_bands, DataSet1, CutName, extensionPlots);
	sprintf(char_LogS2vsCS1,	"%s/%s_LogS2vsCS1_%s%s",	outFolder_bands, DataSet1, CutName, extensionPlots);

	c_S2vsS1			->SaveAs(char_S2vsS1);
	c_S2vsCS1			->SaveAs(char_S2vsCS1);
	c_LogS2vsS1			->SaveAs(char_LogS2vsS1);
	c_LogS2vsCS1		->SaveAs(char_LogS2vsCS1);
	c_LogS2vsCS1_scat	->SaveAs(char_LogS2vsCS1_scat);
