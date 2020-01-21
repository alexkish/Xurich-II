	// 50deg
	int nbins_TOF		= 200;
	double min_TOF		= 0;
	double max_TOF		= 1.6e4;

	int nbins_PSD		= 500;
	double min_PSD		= 0;
	double max_PSD		= 1.6e4;

	int nbins_AMP		= 500;
	double min_AMP		= 0;
	double max_AMP		= 1.6e4;

	int nbins_isign		= 50;
	double min_isign	= 0;
	double max_isign	= 50;
	
	int nbinsC = 100; //for coarse binning in 2D plots

	TH1F *h1_isign 		= new TH1F("h1_isign", 			DataSetName1, nbins_TOF, min_TOF, max_TOF);
		  h1_isign		->SetLineColor(4);
	TH1F *h1_TOF 		= new TH1F("h1_TOF", 			DataSetName1, nbins_TOF, min_TOF, max_TOF);
		  h1_TOF		->SetLineColor(2);
	TH1F *h1_AMP 		= new TH1F("h1_AMP", 			DataSetName1, nbins_AMP, min_AMP, max_AMP);
		  h1_AMP		->SetLineColor(2);
	TH1F *h1_PSD 		= new TH1F("h1_PSD", 			DataSetName1, nbins_PSD, min_PSD, max_PSD);
		  h1_PSD		->SetLineColor(2);
	TH1F *h1_TOF_PSDcut = new TH1F("h1_TOF_PSDcut", 	DataSetName1, nbins_TOF, min_TOF, max_TOF);
		  h1_TOF_PSDcut	->SetLineColor(2);
	TH2F *h2_PSDvsTOF 	= new TH2F("h2_PSDvsTOF",		DataSetName1, nbinsC, min_TOF, max_TOF, nbinsC, min_PSD, max_PSD);
		  h2_PSDvsTOF	->SetMarkerStyle(4);
		  h2_PSDvsTOF	->SetMarkerSize(0.6);
		  h2_PSDvsTOF	->SetMarkerColor(2);
	TH2F *h2_PSDvsAMP 	= new TH2F("h2_PSDvsAMP",		DataSetName1, nbinsC, min_AMP, max_AMP, nbinsC, min_PSD, max_PSD);
		  h2_PSDvsAMP	->SetMarkerStyle(4);
		  h2_PSDvsAMP	->SetMarkerSize(0.6);
		  h2_PSDvsAMP	->SetMarkerColor(2);

	int canX = 700;
	int canY = 500;


	cout <<"MaxAMP0 size:"<< MaxAMP0.size << endl;
	cout <<"MaxTAC0 size:"<< MaxTAC0.size << endl;

//	for (int i=0; i<MaxAMP0)