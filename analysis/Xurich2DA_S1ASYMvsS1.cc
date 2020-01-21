	// MAKE OUT FOLDERS
	char outFolder_dataset[500];
	sprintf(outFolder_dataset, "./plots/%s", DataSet1);
	
	char outFolder_S1ASYMvsS1[500];
	sprintf(outFolder_S1ASYMvsS1, "%s/S1ASYMvsS1", outFolder_dataset);

	char mkdir_outFolder_dataset[500];
	sprintf(mkdir_outFolder_dataset, ".mkdir %s", outFolder_dataset);

	char mkdir_outFolder_S1ASYMvsS1[500];
	sprintf(mkdir_outFolder_S1ASYMvsS1, ".mkdir %s", outFolder_S1ASYMvsS1);

	gROOT->ProcessLine(mkdir_outFolder_dataset);
	gROOT->ProcessLine(mkdir_outFolder_S1ASYMvsS1);

	char extensionPlots[500];
	sprintf(extensionPlots, ".png");


	// DEFINE RANGES
	int nbins_S1	= 100;
	double min_S1	= 0;
	double max_S1	= 1.0e3;

	int nbins_dt	= 200;
	double min_dt	= 0.;
	double max_dt	= 20.;

	TH2F *h2_S1vsDT = new TH2F("h2_S1vsDT",	"", nbins_dt, min_dt, max_dt, nbins_S1, min_S1, max_S1);

	TCanvas *c_S1vsDT = new TCanvas("c_S1vsDT", "c_S1vsDT", 0, 0, 700, 500);
			 c_S1vsDT->SetFillColor(10);
    		 c_S1vsDT->SetLogz();
		T1	->Draw("S1totalPE:dt_top>>h2_S1vsDT",	cut_all && cut_S2saturationTop && cut_S2saturationBot,	"COLZ");
		h2_S1vsDT	-> Scale(ScalingFactor);
		h2_S1vsDT	-> GetXaxis() -> SetTitle("drift time [#mus]");
		h2_S1vsDT	-> GetYaxis() -> SetTitle("largest S1[PE]");
		h2_S1vsDT	-> GetXaxis() -> CenterTitle(true);
		h2_S1vsDT	-> GetYaxis() -> CenterTitle(true);
	c_S1vsDT->Update();


	const int nSlices = 38; // number of slices

	double xmean, xinterval;
	double ymean, ysigma;
	double median, medianError;

/*	double x[nSlices], 	xer[nSlices];
	double y[nSlices], 	yer[nSlices];
	double yM[nSlices], yMer[nSlices];

	double y1p[nSlices];
	double y1m[nSlices];

	double y2p[nSlices];
	double y2m[nSlices];

	double y3p[nSlices];
	double y3m[nSlices];
*/
	double min_DT = 0;
	double max_DT = 19;
	double min_DTslice, max_DTslice;
	double DTinterval = (max_DT-min_DT)/nSlices;

/*	double fitS1_min;
	double fitS1_max;

	ofstream OutFile;
	Char_t  OutFile_char[500];
	sprintf(OutFile_char, "%s/S1slices.dat", outFolder_S1DTcorrection);
	OutFile.open(OutFile_char);
*/
	for (int i=0; i<nSlices; i++){

		min_DTslice = min_DT + i*DTinterval;
		max_DTslice = min_DTslice + DTinterval;
		
		//#include "SliceS1_DefineSliceWidth_AmBe.cc"
		//#include "SliceS1_DefineSliceWidth30bins_AmBe.cc"

		Char_t  Hname[500];
		sprintf(Hname, "slice_%d", i+1);
		sprintf(Hname, "slice %d, %g us < dt < %g us ", i+1, min_DTslice, max_DTslice);
		//cout << Hname <<" S1: "<< min_S1slice <<" - "<< max_S1slice <<" phe"<< endl;
		cout << Hname << endl;

		TH2F *h2_S1ASYMvsS1 = new TH2F("h2_S1ASYMvsS1", Hname, nbins_S1, min_S1, max_S1, nbins_S1, -1, +1);
			  h2_S1ASYMvsS1->SetLineColor(1);
			  h2_S1ASYMvsS1->SetLineWidth(2);
		
		// define fit range for each slice
		//#include "S1DTcorrection_DefineFitRanges_19bins.cc"
		//#include "S1DTcorrection_DefineFitRanges_38bins.cc"

/*		// Gaussian Fit
		TF1 *S1sliceFit = new TF1("S1sliceFit","gaus", fitS1_min, fitS1_max);
			 S1sliceFit->SetLineColor(2);
			 S1sliceFit->SetLineWidth(2);
*/		
		// S1 slicing cut
		TCut cut_DTslice	= Form("dt_top > %g && dt_top < %g", min_DTslice, max_DTslice);
		
		// PLOT
		TCanvas *c_S1ASYMvsS1 = new TCanvas("c_S1ASYMvsS1", "c_S1ASYMvsS1", 0, 0, 700, 500);
				 c_S1ASYMvsS1->SetFillColor(10);
				 c_S1ASYMvsS1->SetLogz();
			// fill histogram
			T1->Draw("S1asym:S1totalPE>>h2_S1ASYMvsS1", cut_all && cut_DTslice,"COLZ");
			h2_S1ASYMvsS1	->GetXaxis()->SetTitle("S1 total [PE]");
			h2_S1ASYMvsS1	->GetYaxis()->SetTitle("S1 asymmetry");
			h2_S1ASYMvsS1	->GetZaxis()->SetTitle("Counts");
			h2_S1ASYMvsS1	->GetXaxis()->CenterTitle(true);
			h2_S1ASYMvsS1	->GetYaxis()->CenterTitle(true);
			h2_S1ASYMvsS1	->GetZaxis()->CenterTitle(true);
/*			// fit histogram
			h1_S1slice->Fit(S1sliceFit,"R");
			S1sliceFit->Draw("SAME");		
*/
		c_S1ASYMvsS1->Update();

	
/*		xmean 		= min_DTslice + (max_DTslice - min_DTslice)/2;
		xinterval 	= (max_DTslice - min_DTslice)/2;
		x[i] 		= xmean;
		xer[i] 		= xinterval;
	
		ymean 			= S1sliceFit->GetParameter(1);
		ysigma 			= S1sliceFit->GetParameter(2);
		median 			= h1_S1slice->GetMean();
		medianError 	= h1_S1slice->GetMean();

		cout <<"median = "<< median <<" +- "<< medianError << endl;
		
		y[i]	= ymean;
		y1p[i]	= (ymean+1*ysigma);
		y1m[i]	= (ymean-1*ysigma);
		y2p[i]	= (ymean+2*ysigma);
		y2m[i]	= (ymean-2*ysigma);
		y3p[i]	= (ymean+3*ysigma);
		y3m[i]	= (ymean-3*ysigma);

		yM[i]	= median;
		yMer[i]	= medianError;

		yer[i] = ysigma;
	

		OutFile	<< xmean		<<" "
				<< xinterval	<<" "
				<< ymean 		<<" "
				<< ysigma		<<" "<< endl;
*/				
		Char_t  Sname[500];
		sprintf(Sname, "%s/S1ASYMvsS1_%d.png", outFolder_S1ASYMvsS1, i+1);
		c_S1ASYMvsS1->Print(Sname);

	}

	
/*	OutFile.close();
	

	TGraph *grMean = new TGraph(nSlices, x, y);
			grMean->SetMarkerStyle(8);
			grMean->SetMarkerSize(0.6);
			grMean->SetMarkerColor(1);
			grMean->SetLineColor(1);
			grMean->SetLineWidth(2);
	TGraphErrors *grMedian = new TGraphErrors(nSlices, x, yM, xer, yMer);
				  grMedian->SetMarkerStyle(8);
				  grMedian->SetMarkerSize(0.6);
				  grMedian->SetMarkerColor(1);
				  grMedian->SetLineColor(1);
				  grMedian->SetLineWidth(1);


	TGraph *gr1p = new TGraph(nSlices, x, y1p);
			gr1p->SetMarkerStyle(8);
			gr1p->SetMarkerSize(0.6);
			gr1p->SetMarkerColor(1);
			gr1p->SetLineColor(1);
			gr1p->SetLineWidth(2);
	TGraph *gr1m = new TGraph(nSlices, x, y1m);
			gr1m->SetMarkerStyle(8);
			gr1m->SetMarkerSize(0.6);
			gr1m->SetMarkerColor(1);
			gr1m->SetLineColor(1);
			gr1m->SetLineWidth(2);

	TGraph *gr2p = new TGraph(nSlices, x, y2p);
			gr2p->SetMarkerStyle(8);
			gr2p->SetMarkerSize(0.6);
			gr2p->SetMarkerColor(1);
			gr2p->SetLineColor(1);
			gr2p->SetLineWidth(2);
	TGraph *gr2m = new TGraph(nSlices, x, y2m);
			gr2m->SetMarkerStyle(8);
			gr2m->SetMarkerSize(0.6);
			gr2m->SetMarkerColor(1);
			gr2m->SetLineColor(1);
			gr2m->SetLineWidth(2);
	TGraph *gr3p = new TGraph(nSlices, x, y3p);
			gr3p->SetMarkerStyle(8);
			gr3p->SetMarkerSize(0.6);
			gr3p->SetMarkerColor(1);
			gr3p->SetLineColor(1);
			gr3p->SetLineWidth(2);
	TGraph *gr3m = new TGraph(nSlices, x, y3m);
			gr3m->SetMarkerStyle(8);
			gr3m->SetMarkerSize(0.6);
			gr3m->SetMarkerColor(1);
			gr3m->SetLineColor(1);
			gr3m->SetLineWidth(2);
*/
/*	TGraphErrors *grMeanEr = new TGraphErrors(n, x, y, xer, yer);
			grMeanEr->SetMarkerColor(1);
			grMeanEr->SetLineColor(1);
			grMeanEr->SetMarkerStyle(1);
			grMeanEr->SetLineWidth(2);
*/


/*	c_S1vsDT->cd();
		grMean		->Draw("PСC same");
		gr1p		->Draw("PСC same");
		gr1m		->Draw("PСC same");
		gr2p		->Draw("PСC same");
		gr2m		->Draw("PСC same");
		gr3p		->Draw("PСC same");
		gr3m		->Draw("PСC same");
		//grMedian	->Draw("PС");

		Char_t  char_S1vsDT_withFits[500];
		sprintf(char_S1vsDT_withFits, "%s/%s_S1vsDT-withFits%s", outFolder_dataset, DataSet1, extensionPlots); 
	c_S1vsDT->SaveAs(char_S1vsDT_withFits);
*/

	
/*	TCanvas *c_graphs = new TCanvas("c_gr", "c_gr", 0, 0, 700, 500);
			 c_graphs->SetFillColor(10);
   			 c_graphs->SetBorderSize(2);
			 c_graphs->SetGridx();
   			 c_graphs->SetGridy();
			 c_graphs->SetFrameFillColor(0);
		grMean	->Draw("AP");
		gr1p	->Draw("P SAMES");
		gr1m	->Draw("P SAMES");

		gr2p	->Draw("P SAMES");
		gr2m	->Draw("P SAMES");
		
		gr3p	->Draw("P SAMES");
		gr3m	->Draw("P SAMES");

		grMean->SetTitle(0);
		grMean->GetXaxis()->SetTitle("Drift time [#mus]");
		grMean->GetXaxis()->CenterTitle(true);
		grMean->GetYaxis()->SetTitle("S2sLowWidth[0] [samples]");
		grMean->GetYaxis()->CenterTitle(true);
	
		TF1 *grMean_fit = new TF1("grMean_fit","pol5",0,180);
			 grMean_fit->SetLineColor(2);
			 grMean_fit->SetLineWidth(2);
			 grMean_fit->SetLineStyle(1);
		grMean->Fit(grMean_fit);
		grMean_fit->Draw("SAMES");
		TF1 *gr1p_fit = new TF1("gr1p_fit","pol5",0,180);
			 gr1p_fit->SetLineColor(2);
			 gr1p_fit->SetLineWidth(2);
			 gr1p_fit->SetLineStyle(2);
		gr1p->Fit(gr1p_fit);
		gr1p_fit->Draw("SAMES");
		TF1 *gr1m_fit = new TF1("gr1m_fit","pol5",0,180);
			 gr1m_fit->SetLineColor(2);
			 gr1m_fit->SetLineWidth(2);
			 gr1m_fit->SetLineStyle(2);
		gr1m->Fit(gr1m_fit);
		gr1m_fit->Draw("SAMES");
		// 2 sigma
		TF1 *gr2p_fit = new TF1("gr2p_fit","pol5",0,180);
			 gr2p_fit->SetLineColor(2);
			 gr2p_fit->SetLineWidth(2);
			 gr2p_fit->SetLineStyle(2);
		gr2p->Fit(gr2p_fit);
		gr2p_fit->Draw("SAMES");
		TF1 *gr2m_fit = new TF1("gr2m_fit","pol5",0,180);
			 gr2m_fit->SetLineColor(2);
			 gr2m_fit->SetLineWidth(2);
			 gr2m_fit->SetLineStyle(2);
		gr2m->Fit(gr2m_fit);
		gr2m_fit->Draw("SAMES");
		// 3 sigma
		TF1 *gr3p_fit = new TF1("gr3p_fit","pol5",0,180);
			 gr3p_fit->SetLineColor(2);
			 gr3p_fit->SetLineWidth(2);
			 gr3p_fit->SetLineStyle(2);
		gr3p->Fit(gr3p_fit);
		gr3p_fit->Draw("SAMES");
		TF1 *gr3m_fit = new TF1("gr3m_fit","pol5",0,180);
			 gr3m_fit->SetLineColor(2);
			 gr3m_fit->SetLineWidth(2);
			 gr3m_fit->SetLineStyle(2);
		gr3m->Fit(gr3m_fit);
		gr3m_fit->Draw("SAMES");

	c_graphs->Update();
	char c_graphs_nameC[500];
	sprintf(c_graphs_nameC, "%s/%s/graphs.C", outFolder, OutFolderName);
	char c_graphs_nameP[500];
	sprintf(c_graphs_nameP, "%s/%s/graphs.png", outFolder, OutFolderName);
	c_graphs->SaveAs(c_graphs_nameC);
	c_graphs->SaveAs(c_graphs_nameP);

	double grMean_p0 = grMean_fit->GetParameter(0);
	double grMean_p1 = grMean_fit->GetParameter(1);
	double grMean_p2 = grMean_fit->GetParameter(2);
	double grMean_p3 = grMean_fit->GetParameter(3);
	double grMean_p4 = grMean_fit->GetParameter(4);
	double grMean_p5 = grMean_fit->GetParameter(5);

	double gr1p_p0 = gr1p_fit->GetParameter(0);
	double gr1p_p1 = gr1p_fit->GetParameter(1);
	double gr1p_p2 = gr1p_fit->GetParameter(2);
	double gr1p_p3 = gr1p_fit->GetParameter(3);
	double gr1p_p4 = gr1p_fit->GetParameter(4);
	double gr1p_p5 = gr1p_fit->GetParameter(5);

	double gr1m_p0 = gr1m_fit->GetParameter(0);
	double gr1m_p1 = gr1m_fit->GetParameter(1);
	double gr1m_p2 = gr1m_fit->GetParameter(2);
	double gr1m_p3 = gr1m_fit->GetParameter(3);
	double gr1m_p4 = gr1m_fit->GetParameter(4);
	double gr1m_p5 = gr1m_fit->GetParameter(5);
	// 2 sigma
	double gr2p_p0 = gr2p_fit->GetParameter(0);
	double gr2p_p1 = gr2p_fit->GetParameter(1);
	double gr2p_p2 = gr2p_fit->GetParameter(2);
	double gr2p_p3 = gr2p_fit->GetParameter(3);
	double gr2p_p4 = gr2p_fit->GetParameter(4);
	double gr2p_p5 = gr2p_fit->GetParameter(5);

	double gr2m_p0 = gr2m_fit->GetParameter(0);
	double gr2m_p1 = gr2m_fit->GetParameter(1);
	double gr2m_p2 = gr2m_fit->GetParameter(2);
	double gr2m_p3 = gr2m_fit->GetParameter(3);
	double gr2m_p4 = gr2m_fit->GetParameter(4);
	double gr2m_p5 = gr2m_fit->GetParameter(5);
	// 3 sigma
	double gr3p_p0 = gr3p_fit->GetParameter(0);
	double gr3p_p1 = gr3p_fit->GetParameter(1);
	double gr3p_p2 = gr3p_fit->GetParameter(2);
	double gr3p_p3 = gr3p_fit->GetParameter(3);
	double gr3p_p4 = gr3p_fit->GetParameter(4);
	double gr3p_p5 = gr3p_fit->GetParameter(5);

	double gr3m_p0 = gr3m_fit->GetParameter(0);
	double gr3m_p1 = gr3m_fit->GetParameter(1);
	double gr3m_p2 = gr3m_fit->GetParameter(2);
	double gr3m_p3 = gr3m_fit->GetParameter(3);
	double gr3m_p4 = gr3m_fit->GetParameter(4);
	double gr3m_p5 = gr3m_fit->GetParameter(5);

	
	
	ofstream OutFile1;
	
	Char_t  OutFile1_char[500];
	sprintf(OutFile1_char, "%s/%s/S2slices_fits.dat", outFolder, OutFolderName);
	OutFile1.open(OutFile1_char);

	OutFile1<< "grMean ="		<<" "
			<< grMean_p0	<<" "
			<< grMean_p1	<<" "
			<< grMean_p2	<<" "
			<< grMean_p3	<<" "
			<< grMean_p4	<<" "
			<< grMean_p5	<<endl
			<< "gr1p ="		<<" "
			<< gr1p_p0		<<" "
			<< gr1p_p1		<<" "
			<< gr1p_p2		<<" "
			<< gr1p_p3		<<" "
			<< gr1p_p4		<<" "
			<< gr1p_p5		<<endl
			<< "gr1m ="		<<" "
			<< gr1m_p0		<<" "
			<< gr1m_p1		<<" "
			<< gr1m_p2		<<" "
			<< gr1m_p3		<<" "
			<< gr1m_p4		<<" "
			<< gr1m_p5		<<endl
			<< "gr2p ="		<<" "
			<< gr2p_p0		<<" "
			<< gr2p_p1		<<" "
			<< gr2p_p2		<<" "
			<< gr2p_p3		<<" "
			<< gr2p_p4		<<" "
			<< gr2p_p5		<<endl
			<< "gr2m ="		<<" "
			<< gr2m_p0		<<" "
			<< gr2m_p1		<<" "
			<< gr2m_p2		<<" "
			<< gr2m_p3		<<" "
			<< gr2m_p4		<<" "
			<< gr2m_p5		<<endl
			<< "gr3p ="		<<" "
			<< gr3p_p0		<<" "
			<< gr3p_p1		<<" "
			<< gr3p_p2		<<" "
			<< gr3p_p3		<<" "
			<< gr3p_p4		<<" "
			<< gr3p_p5		<<endl
			<< "gr3m ="		<<" "
			<< gr3m_p0		<<" "
			<< gr3m_p1		<<" "
			<< gr3m_p2		<<" "
			<< gr3m_p3		<<" "
			<< gr3m_p4		<<" "
			<< gr3m_p5		<<endl;
			
	OutFile1.close();

*/
