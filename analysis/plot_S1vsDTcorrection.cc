#include "TTree.h"
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TObject.h"
#include "TMath.h"
#include "TRandom.h"
#include "TChain.h"
#include "TPad.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TH3.h"
#include "TH3F.h"
#include "TProfile.h"
#include "TF1.h"
#include "TF2.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TCut.h"
#include "TPie.h"
#include "TPieSlice.h"
#include "TPaletteAxis.h"
#include "TPaveStats.h"
#include "TList.h"
#include "TMarker.h"
#include "TEllipse.h"
#include "TColor.h"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"

void plot_S1vsDTcorrection()
{	

	// LOAD SETTINGS
	gStyle	->SetOptStat(0);
	//gStyle	->SetOptFit(0);
	//gStyle	->SetOptStat("m");
	gStyle	->SetOptFit(1);

	//gStyle	->SetPalette(1);
	//------ define color gradinet
	const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
	//------
    gStyle->SetNumberContours(30);

	gStyle->SetStatBorderSize(0);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFillColor(10);
	gStyle->SetStatColor(10);
	gStyle->SetStatFont(42);
	
	//gStyle->SetMarkerStyle(7);
	gStyle->SetMarkerColor(1);

	// LOAD HISTOGRAM
	//#include "./plots/150525_1311_cutA0/150525_1311_S1vsDT_cutA0_withFit.C"
	#include "./plots/150525_1311_cutA0/150525_1311_S1vsDT_toFit_cutA0.C"
	
	////////////////////////////////////////////////////////////////////////	
	// open datafile with fit parameters
	Char_t  DataFileFitResults[500];
	sprintf(DataFileFitResults, "./plots/150525_1311_cutA0/S1DTcorrection/S1slices.dat");			

	h2_S1vsDT_toFit->GetYaxis()->SetRangeUser(0, 1500);
	h2_S1vsDT_toFit->GetXaxis()->SetTitleOffset(1.25);
	h2_S1vsDT_toFit->GetYaxis()->SetTitleOffset(1.25);

	TTree *t1	= new TTree("t1","t1");
	//t1->ReadFile(DataFileFitResults, "S1dt:S1mean:S1sigma:S1meanEr:S1sigmaEr");
	t1->ReadFile(DataFileFitResults, "xmean:xinterval:ymean:ymeanEr:ysigma:ysigmaEr");
	
	int k = t1->GetEntries();
	cout << "Length of the DATA Tree   k = "	<< k << endl;
	
	float xmean, xinterval, ymean, ymeanEr, ysigma, ysigmaEr;
	
	t1->SetBranchAddress("xmean",		&xmean);
	t1->SetBranchAddress("xinterval",	&xinterval);
	t1->SetBranchAddress("ymean",		&ymean);
	t1->SetBranchAddress("ymeanEr",		&ymeanEr);
	t1->SetBranchAddress("ysigma",		&ysigma);
	t1->SetBranchAddress("ysigmaEr",	&ysigmaEr);

	const int kk = k;
	double X[kk], Y[kk], Xer[kk], Yer[kk];

	for(int i=0; i<k; i++){
		t1->GetEntry(i);
		X[i] 	= xmean;
		Y[i] 	= ymean;
		Xer[i] 	= xinterval;
		Yer[i] 	= ysigma;
	}	
	
	
	TGraphErrors *grFitResults = new TGraphErrors(k, X, Y, Xer, Yer);
				  grFitResults->SetMarkerColor(1);
				  grFitResults->SetLineColor(1);
	
	c_S1vsDT_toFit->cd();
		grFitResults->Draw("P same");

		
	double fit_DTmin = 2.0;
	double fit_DTmax = 17.5;

		TF1 *fit_S1vsDT = new TF1("fit_S1vsDT","pol3", fit_DTmin, fit_DTmax);
			 fit_S1vsDT->SetLineColor(6);
			 fit_S1vsDT->SetLineWidth(2);
			 fit_S1vsDT->SetLineStyle(2);
		grFitResults->Fit(fit_S1vsDT, "R");
		fit_S1vsDT->Draw("sames");

		TF1 *fitMean_S1vsDT = new TF1("fitMean_S1vsDT","pol0", fit_DTmin, fit_DTmax);
			 fitMean_S1vsDT->SetLineColor(4);
			 fitMean_S1vsDT->SetLineWidth(1);
			 fitMean_S1vsDT->SetLineStyle(7);
		grFitResults->Fit(fitMean_S1vsDT, "R");
		fitMean_S1vsDT->Draw("sames");


	c_S1vsDT_toFit->Update();		

	
	double fitS1_p0 = fit_S1vsDT->GetParameter(0);
	double fitS1_p1 = fit_S1vsDT->GetParameter(1);
	double fitS1_p2 = fit_S1vsDT->GetParameter(2);
	double fitS1_p3 = fit_S1vsDT->GetParameter(3);

	double meanS1 = fitMean_S1vsDT->GetParameter(0);

/*	const int npar = 4;
	double fpar[npar];
	fpar[0] = fitS1_p0;
	fpar[1] = fitS1_p1;
	fpar[2] = fitS1_p2;
	fpar[3] = fitS1_p3;

	TF1 *S1correctionFunction = new TF1("S1correctionFunction", "pol3",2, 17.5);
		 S1correctionFunction->SetParameter(0, fpar[0]);
		 S1correctionFunction->SetParameter(1, fpar[1]);
		 S1correctionFunction->SetParameter(2, fpar[2]);
		 S1correctionFunction->SetParameter(3, fpar[3]);

	TCanvas *c_S1correctionFunction = new TCanvas("c_S1correctionFunction", "c_correctionFunction", 0, 0, 700, 500);
			 c_S1correctionFunction->SetFillColor(10);
    		 c_S1correctionFunction->SetLogz();
    		 S1correctionFunction->Draw();
		S1correctionFunction	-> GetXaxis() -> SetTitle("drift time [#mus]");
		S1correctionFunction	-> GetYaxis() -> SetTitle("S1, normalized to average");
		S1correctionFunction	-> GetXaxis() -> CenterTitle(true);
		S1correctionFunction	-> GetYaxis() -> CenterTitle(true);
	c_S1correctionFunction->Update();
*/

	double XC[kk], YC[kk], XCer[kk], YCer[kk];

	for(int i=0; i<k; i++){
		//t1->GetEntry(i);
		XC[i] 		= X[i];
		YC[i] 		= Y[i]/meanS1;
		XCer[i] 	= Xer[i];
		YCer[i] 	= YC[i]*Yer[i]/Y[i];
	}	

	TGraphErrors *grFitResultsNorm = new TGraphErrors(k, XC, YC, XCer, YCer);
				  grFitResultsNorm->SetMarkerColor(1);
				  grFitResultsNorm->SetLineColor(1);
				  grFitResultsNorm->SetTitle(0);
	
	TCanvas *c_FitResultsNorm = new TCanvas("c_FitResultsNorm", "c_FitResultsNorm", 0, 0, 700, 500);
			 c_FitResultsNorm->SetFillColor(10);
    		 c_FitResultsNorm->SetLogz();
		grFitResultsNorm->Draw("AP same");
		grFitResultsNorm	-> GetXaxis() -> SetTitle("drift time [#mus]");
		grFitResultsNorm	-> GetYaxis() -> SetTitle("correction factor");
		grFitResultsNorm	-> GetXaxis() -> CenterTitle(true);
		grFitResultsNorm	-> GetYaxis() -> CenterTitle(true);

		double minY_grFitResultsNorm = 0.0;
		double maxY_grFitResultsNorm = 1.7;
		grFitResultsNorm	-> GetYaxis() -> SetRangeUser(minY_grFitResultsNorm, maxY_grFitResultsNorm);

		TF1 *fitNorm_S1vsDT = new TF1("fitNorm_S1vsDT","pol3", fit_DTmin, fit_DTmax);
			 fitNorm_S1vsDT->SetLineColor(6);
			 fitNorm_S1vsDT->SetLineWidth(2);
			 fitNorm_S1vsDT->SetLineStyle(2);
			 fitNorm_S1vsDT->SetName(0);
		grFitResultsNorm->Fit(fitNorm_S1vsDT, "R");
		fitNorm_S1vsDT->Draw("sames");

	TLine *fitNorm_left 	= new TLine(fit_DTmin, minY_grFitResultsNorm, fit_DTmin, maxY_grFitResultsNorm);
	TLine *fitNorm_right	= new TLine(fit_DTmax, minY_grFitResultsNorm, fit_DTmax, maxY_grFitResultsNorm);
	TLine *fitNorm_mean 	= new TLine(fit_DTmin, 1.0, fit_DTmax, 1.0);
		   fitNorm_left		->SetLineColor(2);
		   fitNorm_right	->SetLineColor(2);
		   fitNorm_mean		->SetLineColor(2);
		   fitNorm_left		->SetLineStyle(7);
		   fitNorm_right	->SetLineStyle(7);
		   fitNorm_mean		->SetLineStyle(7);
		fitNorm_left	->Draw("same");
		fitNorm_right	->Draw("same");
		fitNorm_mean	->Draw("same");

	c_FitResultsNorm->Update();


}

