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
#include "TF1.h"
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
#include "TMath.h"
#include "TEventList.h"
#include "TTreePlayer.h"
#include "TInterpreter.h"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"

#include <cmath>
#include "math.h"


void plot_S2widthQuantiles()
{	

	gInterpreter->EnableAutoLoading();
	
	//////////////////////////////////////////////////////////////////////////////////////
	// define style
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(0);
	gStyle->SetStatBorderSize(0);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFillColor(10);
	gStyle->SetStatColor(10);
	gStyle->SetStatFont(42);
	//gStyle->SetMarkerStyle(7);
	gStyle->SetMarkerColor(1);
	
	
	//////////////////////////////////////////////////////////////////////////////////////
	// define color gradient
	const Int_t NRGBs = 5;
    const Int_t NCont = 255;
    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
    
	////////////////////////////////////////////////////////////////////////
	// DATA
	//const char *DataFolder 	= "./plots/161012_1910_Files7_cutDelayS1S2TopAndBot_cutDelayMinTopAndBot/S2widthDT_Kr83m";	// idark05x
	const char *DataFolder 	= "./plots/161012_1910_Files13_cutDelayS1S2TopAndBot_cutDelayMinTopAndBot/S2widthDT_Kr83m";	// idark05x
	
	char DF_S20_FWHM_top[500];
	char DF_S20_FWHM_bot[500];
	char DF_S20_FWTM_top[500];
	char DF_S20_FWTM_bot[500];

	char DF_S21_FWHM_top[500];
	char DF_S21_FWHM_bot[500];
	char DF_S21_FWTM_top[500];
	char DF_S21_FWTM_bot[500];

	sprintf(DF_S20_FWHM_top, "%s/sliceDT_S20_FWHM_top.dat", DataFolder);		
	sprintf(DF_S20_FWHM_bot, "%s/sliceDT_S20_FWHM_bot.dat", DataFolder);			
	sprintf(DF_S20_FWTM_top, "%s/sliceDT_S20_FWTM_top.dat", DataFolder);			
	sprintf(DF_S20_FWTM_bot, "%s/sliceDT_S20_FWTM_bot.dat", DataFolder);			

	sprintf(DF_S21_FWHM_top, "%s/sliceDT_S21_FWHM_top.dat", DataFolder);		
	sprintf(DF_S21_FWHM_bot, "%s/sliceDT_S21_FWHM_bot.dat", DataFolder);			
	sprintf(DF_S21_FWTM_top, "%s/sliceDT_S21_FWTM_top.dat", DataFolder);			
	sprintf(DF_S21_FWTM_bot, "%s/sliceDT_S21_FWTM_bot.dat", DataFolder);			

	TTree *t1_S20_FWHM_top	= new TTree("t1_S20_FWHM_top","t1_S20_FWHM_top");
	TTree *t1_S20_FWHM_bot	= new TTree("t1_S20_FWHM_bot","t1_S20_FWHM_bot");
	TTree *t1_S20_FWTM_top	= new TTree("t1_S20_FWTM_top","t1_S20_FWTM_top");
	TTree *t1_S20_FWTM_bot	= new TTree("t1_S20_FWTM_bot","t1_S20_FWTM_bot");

	TTree *t1_S21_FWHM_top	= new TTree("t1_S21_FWHM_top","t1_S21_FWHM_top");
	TTree *t1_S21_FWHM_bot	= new TTree("t1_S21_FWHM_bot","t1_S21_FWHM_bot");
	TTree *t1_S21_FWTM_top	= new TTree("t1_S21_FWTM_top","t1_S21_FWTM_top");
	TTree *t1_S21_FWTM_bot	= new TTree("t1_S21_FWTM_bot","t1_S21_FWTM_bot");

	t1_S20_FWHM_top->ReadFile(DF_S20_FWHM_top, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");
	t1_S20_FWHM_bot->ReadFile(DF_S20_FWHM_bot, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");
	t1_S20_FWTM_top->ReadFile(DF_S20_FWTM_top, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");
	t1_S20_FWTM_bot->ReadFile(DF_S20_FWTM_bot, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");

	t1_S21_FWHM_top->ReadFile(DF_S21_FWHM_top, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");
	t1_S21_FWHM_bot->ReadFile(DF_S21_FWHM_bot, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");
	t1_S21_FWTM_top->ReadFile(DF_S21_FWTM_top, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");
	t1_S21_FWTM_bot->ReadFile(DF_S21_FWTM_bot, "x:xbin:y:y02:y05:y95:y98:yF:yF02:yF05:yF95:yF98");
	
	float 
	x, xbin, y, y02, y05, y95, y98, yF, yF02, yF05, yF95, yF98;
	
	t1_S20_FWHM_top->SetBranchAddress("x",		&x);
	t1_S20_FWHM_top->SetBranchAddress("xbin",	&xbin);
	t1_S20_FWHM_top->SetBranchAddress("y",		&y);
	t1_S20_FWHM_top->SetBranchAddress("y02",	&y02);
	t1_S20_FWHM_top->SetBranchAddress("y05",	&y05);
	t1_S20_FWHM_top->SetBranchAddress("y95",	&y95);
	t1_S20_FWHM_top->SetBranchAddress("y98",	&y98);
	t1_S20_FWHM_top->SetBranchAddress("yF",		&yF);
	t1_S20_FWHM_top->SetBranchAddress("yF02",	&yF02);
	t1_S20_FWHM_top->SetBranchAddress("yF05",	&yF05);
	t1_S20_FWHM_top->SetBranchAddress("yF95",	&yF95);
	t1_S20_FWHM_top->SetBranchAddress("yF98",	&yF98);

 	t1_S20_FWHM_bot->SetBranchAddress("x",		&x);
	t1_S20_FWHM_bot->SetBranchAddress("xbin",	&xbin);
	t1_S20_FWHM_bot->SetBranchAddress("y",		&y);
	t1_S20_FWHM_bot->SetBranchAddress("y02",	&y02);
	t1_S20_FWHM_bot->SetBranchAddress("y05",	&y05);
	t1_S20_FWHM_bot->SetBranchAddress("y95",	&y95);
	t1_S20_FWHM_bot->SetBranchAddress("y98",	&y98);
	t1_S20_FWHM_bot->SetBranchAddress("yF",		&yF);
	t1_S20_FWHM_bot->SetBranchAddress("yF02",	&yF02);
	t1_S20_FWHM_bot->SetBranchAddress("yF05",	&yF05);
	t1_S20_FWHM_bot->SetBranchAddress("yF95",	&yF95);
	t1_S20_FWHM_bot->SetBranchAddress("yF98",	&yF98);

	t1_S20_FWTM_top->SetBranchAddress("x",		&x);
	t1_S20_FWTM_top->SetBranchAddress("xbin",	&xbin);
	t1_S20_FWTM_top->SetBranchAddress("y",		&y);
	t1_S20_FWTM_top->SetBranchAddress("y02",	&y02);
	t1_S20_FWTM_top->SetBranchAddress("y05",	&y05);
	t1_S20_FWTM_top->SetBranchAddress("y95",	&y95);
	t1_S20_FWTM_top->SetBranchAddress("y98",	&y98);
	t1_S20_FWTM_top->SetBranchAddress("yF",		&yF);
	t1_S20_FWTM_top->SetBranchAddress("yF02",	&yF02);
	t1_S20_FWTM_top->SetBranchAddress("yF05",	&yF05);
	t1_S20_FWTM_top->SetBranchAddress("yF95",	&yF95);
	t1_S20_FWTM_top->SetBranchAddress("yF98",	&yF98);

	t1_S20_FWTM_bot->SetBranchAddress("x",		&x);
	t1_S20_FWTM_bot->SetBranchAddress("xbin",	&xbin);
	t1_S20_FWTM_bot->SetBranchAddress("y",		&y);
	t1_S20_FWTM_bot->SetBranchAddress("y02",	&y02);
	t1_S20_FWTM_bot->SetBranchAddress("y05",	&y05);
	t1_S20_FWTM_bot->SetBranchAddress("y95",	&y95);
	t1_S20_FWTM_bot->SetBranchAddress("y98",	&y98);
	t1_S20_FWTM_bot->SetBranchAddress("yF",		&yF);
	t1_S20_FWTM_bot->SetBranchAddress("yF02",	&yF02);
	t1_S20_FWTM_bot->SetBranchAddress("yF05",	&yF05);
	t1_S20_FWTM_bot->SetBranchAddress("yF95",	&yF95);
	t1_S20_FWTM_bot->SetBranchAddress("yF98",	&yF98);


	t1_S21_FWHM_top->SetBranchAddress("x",		&x);
	t1_S21_FWHM_top->SetBranchAddress("xbin",	&xbin);
	t1_S21_FWHM_top->SetBranchAddress("y",		&y);
	t1_S21_FWHM_top->SetBranchAddress("y02",	&y02);
	t1_S21_FWHM_top->SetBranchAddress("y05",	&y05);
	t1_S21_FWHM_top->SetBranchAddress("y95",	&y95);
	t1_S21_FWHM_top->SetBranchAddress("y98",	&y98);
	t1_S21_FWHM_top->SetBranchAddress("yF",		&yF);
	t1_S21_FWHM_top->SetBranchAddress("yF02",	&yF02);
	t1_S21_FWHM_top->SetBranchAddress("yF05",	&yF05);
	t1_S21_FWHM_top->SetBranchAddress("yF95",	&yF95);
	t1_S21_FWHM_top->SetBranchAddress("yF98",	&yF98);

 	t1_S21_FWHM_bot->SetBranchAddress("x",		&x);
	t1_S21_FWHM_bot->SetBranchAddress("xbin",	&xbin);
	t1_S21_FWHM_bot->SetBranchAddress("y",		&y);
	t1_S21_FWHM_bot->SetBranchAddress("y02",	&y02);
	t1_S21_FWHM_bot->SetBranchAddress("y05",	&y05);
	t1_S21_FWHM_bot->SetBranchAddress("y95",	&y95);
	t1_S21_FWHM_bot->SetBranchAddress("y98",	&y98);
	t1_S21_FWHM_bot->SetBranchAddress("yF",		&yF);
	t1_S21_FWHM_bot->SetBranchAddress("yF02",	&yF02);
	t1_S21_FWHM_bot->SetBranchAddress("yF05",	&yF05);
	t1_S21_FWHM_bot->SetBranchAddress("yF95",	&yF95);
	t1_S21_FWHM_bot->SetBranchAddress("yF98",	&yF98);

	t1_S21_FWTM_top->SetBranchAddress("x",		&x);
	t1_S21_FWTM_top->SetBranchAddress("xbin",	&xbin);
	t1_S21_FWTM_top->SetBranchAddress("y",		&y);
	t1_S21_FWTM_top->SetBranchAddress("y02",	&y02);
	t1_S21_FWTM_top->SetBranchAddress("y05",	&y05);
	t1_S21_FWTM_top->SetBranchAddress("y95",	&y95);
	t1_S21_FWTM_top->SetBranchAddress("y98",	&y98);
	t1_S21_FWTM_top->SetBranchAddress("yF",		&yF);
	t1_S21_FWTM_top->SetBranchAddress("yF02",	&yF02);
	t1_S21_FWTM_top->SetBranchAddress("yF05",	&yF05);
	t1_S21_FWTM_top->SetBranchAddress("yF95",	&yF95);
	t1_S21_FWTM_top->SetBranchAddress("yF98",	&yF98);

	t1_S21_FWTM_bot->SetBranchAddress("x",		&x);
	t1_S21_FWTM_bot->SetBranchAddress("xbin",	&xbin);
	t1_S21_FWTM_bot->SetBranchAddress("y",		&y);
	t1_S21_FWTM_bot->SetBranchAddress("y02",	&y02);
	t1_S21_FWTM_bot->SetBranchAddress("y05",	&y05);
	t1_S21_FWTM_bot->SetBranchAddress("y95",	&y95);
	t1_S21_FWTM_bot->SetBranchAddress("y98",	&y98);
	t1_S21_FWTM_bot->SetBranchAddress("yF",		&yF);
	t1_S21_FWTM_bot->SetBranchAddress("yF02",	&yF02);
	t1_S21_FWTM_bot->SetBranchAddress("yF05",	&yF05);
	t1_S21_FWTM_bot->SetBranchAddress("yF95",	&yF95);
	t1_S21_FWTM_bot->SetBranchAddress("yF98",	&yF98);

	const int NP = 30;
	double 
	xp[NP], 
	y_S20_FWHM_top[NP], y_S20_FWHM_bot[NP], y_S20_FWTM_top[NP], y_S20_FWTM_bot[NP], 
	y_S21_FWHM_top[NP], y_S21_FWHM_bot[NP], y_S21_FWTM_top[NP], y_S21_FWTM_bot[NP], 

	yErP_S20_FWHM_top[NP], yErP_S20_FWHM_bot[NP], yErP_S20_FWTM_top[NP], yErP_S20_FWTM_bot[NP], 
	yErM_S21_FWHM_top[NP], yErM_S21_FWHM_bot[NP], yErM_S21_FWTM_top[NP], yErM_S21_FWTM_bot[NP], 

	y02_S20_FWHM_top[NP], y02_S20_FWHM_bot[NP], y02_S20_FWTM_top[NP], y02_S20_FWTM_bot[NP], 
	y02_S21_FWHM_top[NP], y02_S21_FWHM_bot[NP], y02_S21_FWTM_top[NP], y02_S21_FWTM_bot[NP], 

	y05_S20_FWHM_top[NP], y05_S20_FWHM_bot[NP], y05_S20_FWTM_top[NP], y05_S20_FWTM_bot[NP], 
	y05_S21_FWHM_top[NP], y05_S21_FWHM_bot[NP], y05_S21_FWTM_top[NP], y05_S21_FWTM_bot[NP], 

	y95_S20_FWHM_top[NP], y95_S20_FWHM_bot[NP], y95_S20_FWTM_top[NP], y95_S20_FWTM_bot[NP], 
	y95_S21_FWHM_top[NP], y95_S21_FWHM_bot[NP], y95_S21_FWTM_top[NP], y95_S21_FWTM_bot[NP], 

	y98_S20_FWHM_top[NP], y98_S20_FWHM_bot[NP], y98_S20_FWTM_top[NP], y98_S20_FWTM_bot[NP], 
	y98_S21_FWHM_top[NP], y98_S21_FWHM_bot[NP], y98_S21_FWTM_top[NP], y98_S21_FWTM_bot[NP];
	

	for(int i=0; i<NP; i++){
		t1_S20_FWHM_top->GetEntry(i);
		xp[i] 					= x;
		y_S20_FWHM_top[i] 		= y;
		y02_S20_FWHM_top[i] 	= y02;
		y05_S20_FWHM_top[i] 	= y05;
		y95_S20_FWHM_top[i] 	= y95;
		y98_S20_FWHM_top[i] 	= y98;
	}

	for(int i=0; i<NP; i++){
		t1_S20_FWHM_bot->GetEntry(i);
		y_S20_FWHM_bot[i] 	= y;
		y02_S20_FWHM_bot[i] = y02;
		y05_S20_FWHM_bot[i] = y05;
		y95_S20_FWHM_bot[i] = y95;
		y98_S20_FWHM_bot[i] = y98;
	}

	for(int i=0; i<NP; i++){
		t1_S20_FWTM_top->GetEntry(i);
		y_S20_FWTM_top[i] 	= y;
		y02_S20_FWTM_top[i] = y02;
		y05_S20_FWTM_top[i] = y05;
		y95_S20_FWTM_top[i] = y95;
		y98_S20_FWTM_top[i] = y98;
	}

	for(int i=0; i<NP; i++){
		t1_S20_FWTM_bot->GetEntry(i);
		y_S20_FWTM_bot[i] 	= y;
		y02_S20_FWTM_bot[i] = y02;
		y05_S20_FWTM_bot[i] = y05;
		y95_S20_FWTM_bot[i] = y95;
		y98_S20_FWTM_bot[i] = y98;
	}

	for(int i=0; i<NP; i++){
		t1_S21_FWHM_top->GetEntry(i);
		y_S21_FWHM_top[i] 	= y;
		y02_S21_FWHM_top[i] = y02;
		y05_S21_FWHM_top[i] = y05;
		y95_S21_FWHM_top[i] = y95;
		y98_S21_FWHM_top[i] = y98;
	}

	for(int i=0; i<NP; i++){
		t1_S21_FWHM_bot->GetEntry(i);
		y_S21_FWHM_bot[i] 	= y;
		y02_S21_FWHM_bot[i] = y02;
		y05_S21_FWHM_bot[i] = y05;
		y95_S21_FWHM_bot[i] = y95;
		y98_S21_FWHM_bot[i] = y98;
	}

	for(int i=0; i<NP; i++){
		t1_S21_FWTM_top->GetEntry(i);
		y_S21_FWTM_top[i] 	= y;
		y02_S21_FWTM_top[i] = y02;
		y05_S21_FWTM_top[i] = y05;
		y95_S21_FWTM_top[i] = y95;
		y98_S21_FWTM_top[i] = y98;
	}

	for(int i=0; i<NP; i++){
		t1_S21_FWTM_bot->GetEntry(i);
		y_S21_FWTM_bot[i] 	= y;
		y02_S21_FWTM_bot[i] = y02;
		y05_S21_FWTM_bot[i] = y05;
		y95_S21_FWTM_bot[i] = y95;
		y98_S21_FWTM_bot[i] = y98;
	}

	TGraph *gr_S20_FWHM_top = new TGraph(NP, xp, y_S20_FWHM_top);
	TGraph *gr_S20_FWHM_bot = new TGraph(NP, xp, y_S20_FWHM_bot);
	TGraph *gr_S20_FWTM_top = new TGraph(NP, xp, y_S20_FWTM_top);
	TGraph *gr_S20_FWTM_bot = new TGraph(NP, xp, y_S20_FWTM_bot);

	TGraph *gr_S21_FWHM_top = new TGraph(NP, xp, y_S21_FWHM_top);
	TGraph *gr_S21_FWHM_bot = new TGraph(NP, xp, y_S21_FWHM_bot);
	TGraph *gr_S21_FWTM_top = new TGraph(NP, xp, y_S21_FWTM_top);
	TGraph *gr_S21_FWTM_bot = new TGraph(NP, xp, y_S21_FWTM_bot);


	TGraph *gr02_S20_FWHM_top = new TGraph(NP, xp, y02_S20_FWHM_top);
	TGraph *gr02_S20_FWHM_bot = new TGraph(NP, xp, y02_S20_FWHM_bot);
	TGraph *gr02_S20_FWTM_top = new TGraph(NP, xp, y02_S20_FWTM_top);
	TGraph *gr02_S20_FWTM_bot = new TGraph(NP, xp, y02_S20_FWTM_bot);

	TGraph *gr02_S21_FWHM_top = new TGraph(NP, xp, y02_S21_FWHM_top);
	TGraph *gr02_S21_FWHM_bot = new TGraph(NP, xp, y02_S21_FWHM_bot);
	TGraph *gr02_S21_FWTM_top = new TGraph(NP, xp, y02_S21_FWTM_top);
	TGraph *gr02_S21_FWTM_bot = new TGraph(NP, xp, y02_S21_FWTM_bot);


	TGraph *gr98_S20_FWHM_top = new TGraph(NP, xp, y98_S20_FWHM_top);
	TGraph *gr98_S20_FWHM_bot = new TGraph(NP, xp, y98_S20_FWHM_bot);
	TGraph *gr98_S20_FWTM_top = new TGraph(NP, xp, y98_S20_FWTM_top);
	TGraph *gr98_S20_FWTM_bot = new TGraph(NP, xp, y98_S20_FWTM_bot);

	TGraph *gr98_S21_FWHM_top = new TGraph(NP, xp, y98_S21_FWHM_top);
	TGraph *gr98_S21_FWHM_bot = new TGraph(NP, xp, y98_S21_FWHM_bot);
	TGraph *gr98_S21_FWTM_top = new TGraph(NP, xp, y98_S21_FWTM_top);
	TGraph *gr98_S21_FWTM_bot = new TGraph(NP, xp, y98_S21_FWTM_bot);


	gr_S20_FWHM_top	->SetMarkerStyle(20);
	gr_S20_FWHM_top	->SetMarkerColor(4);
	gr_S20_FWHM_top	->SetLineColor(4);

	gr_S20_FWHM_bot	->SetMarkerStyle(21);
	gr_S20_FWHM_bot	->SetMarkerColor(2);
	gr_S20_FWHM_bot	->SetLineColor(2);

	gr_S20_FWTM_top	->SetMarkerStyle(22);
	gr_S20_FWTM_top	->SetMarkerColor(4);
	gr_S20_FWTM_top	->SetLineColor(4);

	gr_S20_FWTM_bot	->SetMarkerStyle(23);
	gr_S20_FWTM_bot	->SetMarkerColor(2);
	gr_S20_FWTM_bot	->SetLineColor(2);


	gr_S21_FWHM_top	->SetMarkerStyle(24);
	gr_S21_FWHM_top	->SetMarkerColor(3);
	gr_S21_FWHM_top	->SetLineColor(3);

	gr_S21_FWHM_bot	->SetMarkerStyle(25);
	gr_S21_FWHM_bot	->SetMarkerColor(6);
	gr_S21_FWHM_bot	->SetLineColor(6);

	gr_S21_FWTM_top	->SetMarkerStyle(26);
	gr_S21_FWTM_top	->SetMarkerColor(3);
	gr_S21_FWTM_top	->SetLineColor(3);

	gr_S21_FWTM_bot	->SetMarkerStyle(32);
	gr_S21_FWTM_bot	->SetMarkerColor(6);
	gr_S21_FWTM_bot	->SetLineColor(6);


	gr05_S20_FWHM_top	->SetMarkerStyle(20);
	gr05_S20_FWHM_top	->SetMarkerColor(4);
	gr05_S20_FWHM_top	->SetLineColor(4);

	gr05_S20_FWHM_bot	->SetMarkerStyle(21);
	gr05_S20_FWHM_bot	->SetMarkerColor(2);
	gr05_S20_FWHM_bot	->SetLineColor(2);

	gr05_S20_FWTM_top	->SetMarkerStyle(22);
	gr05_S20_FWTM_top	->SetMarkerColor(4);
	gr05_S20_FWTM_top	->SetLineColor(4);

	gr05_S20_FWTM_bot	->SetMarkerStyle(23);
	gr05_S20_FWTM_bot	->SetMarkerColor(2);
	gr05_S20_FWTM_bot	->SetLineColor(2);


	gr05_S21_FWHM_top	->SetMarkerStyle(24);
	gr05_S21_FWHM_top	->SetMarkerColor(3);
	gr05_S21_FWHM_top	->SetLineColor(3);

	gr05_S21_FWHM_bot	->SetMarkerStyle(25);
	gr05_S21_FWHM_bot	->SetMarkerColor(6);
	gr05_S21_FWHM_bot	->SetLineColor(6);

	gr05_S21_FWTM_top	->SetMarkerStyle(26);
	gr05_S21_FWTM_top	->SetMarkerColor(3);
	gr05_S21_FWTM_top	->SetLineColor(3);

	gr05_S21_FWTM_bot	->SetMarkerStyle(32);
	gr05_S21_FWTM_bot	->SetMarkerColor(6);
	gr05_S21_FWTM_bot	->SetLineColor(6);


	gr95_S20_FWHM_top	->SetMarkerStyle(20);
	gr95_S20_FWHM_top	->SetMarkerColor(4);
	gr95_S20_FWHM_top	->SetLineColor(4);

	gr95_S20_FWHM_bot	->SetMarkerStyle(21);
	gr95_S20_FWHM_bot	->SetMarkerColor(2);
	gr95_S20_FWHM_bot	->SetLineColor(2);

	gr95_S20_FWTM_top	->SetMarkerStyle(22);
	gr95_S20_FWTM_top	->SetMarkerColor(4);
	gr95_S20_FWTM_top	->SetLineColor(4);

	gr95_S20_FWTM_bot	->SetMarkerStyle(23);
	gr95_S20_FWTM_bot	->SetMarkerColor(2);
	gr95_S20_FWTM_bot	->SetLineColor(2);


	gr95_S21_FWHM_top	->SetMarkerStyle(24);
	gr95_S21_FWHM_top	->SetMarkerColor(3);
	gr95_S21_FWHM_top	->SetLineColor(3);

	gr95_S21_FWHM_bot	->SetMarkerStyle(25);
	gr95_S21_FWHM_bot	->SetMarkerColor(6);
	gr95_S21_FWHM_bot	->SetLineColor(6);

	gr95_S21_FWTM_top	->SetMarkerStyle(26);
	gr95_S21_FWTM_top	->SetMarkerColor(3);
	gr95_S21_FWTM_top	->SetLineColor(3);

	gr95_S21_FWTM_bot	->SetMarkerStyle(32);
	gr95_S21_FWTM_bot	->SetMarkerColor(6);
	gr95_S21_FWTM_bot	->SetLineColor(6);



	gr02_S20_FWHM_top	->SetMarkerStyle(20);
	gr02_S20_FWHM_top	->SetMarkerColor(4);
	gr02_S20_FWHM_top	->SetLineColor(4);

	gr02_S20_FWHM_bot	->SetMarkerStyle(21);
	gr02_S20_FWHM_bot	->SetMarkerColor(2);
	gr02_S20_FWHM_bot	->SetLineColor(2);

	gr02_S20_FWTM_top	->SetMarkerStyle(22);
	gr02_S20_FWTM_top	->SetMarkerColor(4);
	gr02_S20_FWTM_top	->SetLineColor(4);

	gr02_S20_FWTM_bot	->SetMarkerStyle(23);
	gr02_S20_FWTM_bot	->SetMarkerColor(2);
	gr02_S20_FWTM_bot	->SetLineColor(2);


	gr02_S21_FWHM_top	->SetMarkerStyle(24);
	gr02_S21_FWHM_top	->SetMarkerColor(3);
	gr02_S21_FWHM_top	->SetLineColor(3);

	gr02_S21_FWHM_bot	->SetMarkerStyle(25);
	gr02_S21_FWHM_bot	->SetMarkerColor(6);
	gr02_S21_FWHM_bot	->SetLineColor(6);

	gr02_S21_FWTM_top	->SetMarkerStyle(26);
	gr02_S21_FWTM_top	->SetMarkerColor(3);
	gr02_S21_FWTM_top	->SetLineColor(3);

	gr02_S21_FWTM_bot	->SetMarkerStyle(32);
	gr02_S21_FWTM_bot	->SetMarkerColor(6);
	gr02_S21_FWTM_bot	->SetLineColor(6);


	gr98_S20_FWHM_top	->SetMarkerStyle(20);
	gr98_S20_FWHM_top	->SetMarkerColor(4);
	gr98_S20_FWHM_top	->SetLineColor(4);

	gr98_S20_FWHM_bot	->SetMarkerStyle(21);
	gr98_S20_FWHM_bot	->SetMarkerColor(2);
	gr98_S20_FWHM_bot	->SetLineColor(2);

	gr98_S20_FWTM_top	->SetMarkerStyle(22);
	gr98_S20_FWTM_top	->SetMarkerColor(4);
	gr98_S20_FWTM_top	->SetLineColor(4);

	gr98_S20_FWTM_bot	->SetMarkerStyle(23);
	gr98_S20_FWTM_bot	->SetMarkerColor(2);
	gr98_S20_FWTM_bot	->SetLineColor(2);


	gr98_S21_FWHM_top	->SetMarkerStyle(24);
	gr98_S21_FWHM_top	->SetMarkerColor(3);
	gr98_S21_FWHM_top	->SetLineColor(3);

	gr98_S21_FWHM_bot	->SetMarkerStyle(25);
	gr98_S21_FWHM_bot	->SetMarkerColor(6);
	gr98_S21_FWHM_bot	->SetLineColor(6);

	gr98_S21_FWTM_top	->SetMarkerStyle(26);
	gr98_S21_FWTM_top	->SetMarkerColor(3);
	gr98_S21_FWTM_top	->SetLineColor(3);

	gr98_S21_FWTM_bot	->SetMarkerStyle(32);
	gr98_S21_FWTM_bot	->SetMarkerColor(6);
	gr98_S21_FWTM_bot	->SetLineColor(6);
    

	gr_S20_FWHM_top	->SetTitle(0);
	gr_S20_FWHM_bot	->SetTitle(0);
	gr_S20_FWTM_top	->SetTitle(0);
	gr_S20_FWTM_bot	->SetTitle(0);

	gr_S21_FWHM_top	->SetTitle(0);
	gr_S21_FWHM_bot	->SetTitle(0);
	gr_S21_FWTM_top	->SetTitle(0);
	gr_S21_FWTM_bot	->SetTitle(0);

	TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 700, 500);
			 c1->SetFillColor(10);
			 //c1->SetLogy(10);
		gr_S20_FWHM_top		->Draw("APC");
		gr05_S20_FWHM_top	->Draw("PC");
		gr95_S20_FWHM_top	->Draw("PC");
		
		gr_S20_FWHM_bot		->Draw("PC");
		gr05_S20_FWHM_bot	->Draw("PC");
		gr95_S20_FWHM_bot	->Draw("PC");

		gr_S21_FWHM_top		->Draw("PC");
		gr05_S21_FWHM_top	->Draw("PC");
		gr95_S21_FWHM_top	->Draw("PC");
		
		gr_S21_FWHM_bot		->Draw("PC");
		gr05_S21_FWHM_bot	->Draw("PC");
		gr95_S21_FWHM_bot	->Draw("PC");

		gr_S20_FWHM_top->SetMaximum(0.5);
		gr_S20_FWHM_top->SetMinimum(0.0);

		gr_S20_FWHM_top	->GetXaxis()->SetTitle("e^{-} drift time [#mus]");
		gr_S20_FWHM_top	->GetYaxis()->SetTitle("S2 width at 50%");
		gr_S20_FWHM_top	->GetXaxis()->CenterTitle(true);
		gr_S20_FWHM_top	->GetYaxis()->CenterTitle(true);
		gr_S20_FWHM_top	->GetXaxis()->SetTitleOffset(1.25);
		gr_S20_FWHM_top	->GetYaxis()->SetTitleOffset(1.25);

		TLegend *leg1a = new TLegend(0.6325215,0.7438272,0.8968481,0.8981481,NULL,"brNDC");
				 leg1a ->SetBorderSize(0);
				 leg1a ->SetFillColor(10);
				 leg1a ->AddEntry(gr_S20_FWHM_top,		"S2[0] top, 5% - 95%",		"pl");
				 leg1a ->AddEntry(gr_S20_FWHM_bot,		"S2[0] bottom, 5% - 95%",	"pl");
				 leg1a ->AddEntry(gr_S21_FWHM_top,		"S2[1] top, 5% - 95%",		"pl");
				 leg1a ->AddEntry(gr_S21_FWHM_bot,		"S2[1] bottom, 5% - 95%",	"pl");
				 leg1a ->Draw();
	c1->Update();


	TCanvas *c2 = new TCanvas("c2", "c2", 0, 0, 700, 500);
			 c2->SetFillColor(10);
			 //c1->SetLogy(10);
		gr_S20_FWTM_top		->Draw("APC");
		gr05_S20_FWTM_top	->Draw("PC");
		gr95_S20_FWTM_top	->Draw("PC");
		
		gr_S20_FWTM_bot		->Draw("PC");
		gr05_S20_FWTM_bot	->Draw("PC");
		gr95_S20_FWTM_bot	->Draw("PC");

		gr_S21_FWTM_top		->Draw("PC");
		gr05_S21_FWTM_top	->Draw("PC");
		gr95_S21_FWTM_top	->Draw("PC");
		
		gr_S21_FWTM_bot		->Draw("PC");
		gr05_S21_FWTM_bot	->Draw("PC");
		gr95_S21_FWTM_bot	->Draw("PC");

		gr_S20_FWTM_top->SetMaximum(1.0);
		gr_S20_FWTM_top->SetMinimum(0.0);

		gr_S20_FWTM_top	->GetXaxis()->SetTitle("e^{-} drift time [#mus]");
		gr_S20_FWTM_top	->GetYaxis()->SetTitle("S2 width at 10%");
		gr_S20_FWTM_top	->GetXaxis()->CenterTitle(true);
		gr_S20_FWTM_top	->GetYaxis()->CenterTitle(true);
		gr_S20_FWTM_top	->GetXaxis()->SetTitleOffset(1.25);
		gr_S20_FWTM_top	->GetYaxis()->SetTitleOffset(1.25);

		TLegend *leg2a = new TLegend(0.6325215,0.7438272,0.8968481,0.8981481,NULL,"brNDC");
				 leg2a ->SetBorderSize(0);
				 leg2a ->SetFillColor(10);
				 leg2a ->AddEntry(gr_S20_FWTM_top,		"S2[0] top, 5% - 95%",		"pl");
				 leg2a ->AddEntry(gr_S20_FWTM_bot,		"S2[0] bottom, 5% - 95%",	"pl");
				 leg2a ->AddEntry(gr_S21_FWTM_top,		"S2[1] top, 5% - 95%",		"pl");
				 leg2a ->AddEntry(gr_S21_FWTM_bot,		"S2[1] bottom, 5% - 95%",	"pl");
				 leg2a ->Draw();
	c2->Update();




	TCanvas *c3 = new TCanvas("c3", "c3", 0, 0, 700, 500);
			 c3->SetFillColor(10);
			 //c3->SetLogy(10);
		gr_S20_FWTM_top		->Draw("AP");
		gr05_S20_FWTM_top	->Draw("P");
		gr95_S20_FWTM_top	->Draw("P");
		
		gr_S20_FWTM_bot		->Draw("P");
		gr05_S20_FWTM_bot	->Draw("P");
		gr95_S20_FWTM_bot	->Draw("P");

		gr_S21_FWTM_top		->Draw("P");
		gr05_S21_FWTM_top	->Draw("P");
		gr95_S21_FWTM_top	->Draw("P");
		
		gr_S21_FWTM_bot		->Draw("P");
		gr05_S21_FWTM_bot	->Draw("P");
		gr95_S21_FWTM_bot	->Draw("P");

		gr_S20_FWTM_top->SetMaximum(0.9);
		gr_S20_FWTM_top->SetMinimum(0.4);

		gr_S20_FWTM_top	->GetXaxis()->SetTitle("e^{-} drift time [#mus]");
		gr_S20_FWTM_top	->GetYaxis()->SetTitle("S2 width at 10%");
		gr_S20_FWTM_top	->GetXaxis()->CenterTitle(true);
		gr_S20_FWTM_top	->GetYaxis()->CenterTitle(true);
		gr_S20_FWTM_top	->GetXaxis()->SetTitleOffset(1.25);
		gr_S20_FWTM_top	->GetYaxis()->SetTitleOffset(1.25);

		TLegend *leg3a = new TLegend(0.6325215,0.7438272,0.8968481,0.8981481,NULL,"brNDC");
				 leg3a ->SetBorderSize(0);
				 leg3a ->SetFillColor(10);
				 leg3a ->AddEntry(gr_S20_FWTM_top,		"S2[0] top, 5% - 95%",		"pl");
				 leg3a ->AddEntry(gr_S20_FWTM_bot,		"S2[0] bottom, 5% - 95%",	"pl");
				 leg3a ->AddEntry(gr_S21_FWTM_top,		"S2[1] top, 5% - 95%",		"pl");
				 leg3a ->AddEntry(gr_S21_FWTM_bot,		"S2[1] bottom, 5% - 95%",	"pl");
				 leg3a ->Draw();

		TF1 *f1_S20_FWTM_top_gr05 = new TF1("f1_S20_FWTM_top_gr05","pol2",2, 17);
		TF1 *f1_S20_FWTM_top_gr95 = new TF1("f1_S20_FWTM_top_gr95","pol2",2, 17);
			 f1_S20_FWTM_top_gr05 ->SetLineColor(4);
			 f1_S20_FWTM_top_gr95 ->SetLineColor(4);
		gr05_S20_FWTM_top->Fit("f1_S20_FWTM_top_gr05","R");
		gr95_S20_FWTM_top->Fit("f1_S20_FWTM_top_gr95","R");
		f1_S20_FWTM_top_gr05->Draw("same");
		f1_S20_FWTM_top_gr95->Draw("same");		

		TF1 *f1_S21_FWTM_top_gr05 = new TF1("f1_S21_FWTM_top_gr05","pol2",2, 17);
		TF1 *f1_S21_FWTM_top_gr95 = new TF1("f1_S21_FWTM_top_gr95","pol2",2, 17);
			 f1_S21_FWTM_top_gr05 ->SetLineColor(3);
			 f1_S21_FWTM_top_gr95 ->SetLineColor(3);
		gr05_S21_FWTM_top->Fit("f1_S21_FWTM_top_gr05","R");
		gr95_S21_FWTM_top->Fit("f1_S21_FWTM_top_gr95","R");
		f1_S21_FWTM_top_gr05->Draw("same");
		f1_S21_FWTM_top_gr95->Draw("same");		


		TF1 *f1_S20_FWTM_bot_gr05 = new TF1("f1_S20_FWTM_bot_gr05","pol2",2, 17);
		TF1 *f1_S20_FWTM_bot_gr95 = new TF1("f1_S20_FWTM_bot_gr95","pol2",2, 17);
			 f1_S20_FWTM_bot_gr05 ->SetLineColor(2);
			 f1_S20_FWTM_bot_gr95 ->SetLineColor(2);
		gr05_S20_FWTM_bot->Fit("f1_S20_FWTM_bot_gr05","R");
		gr95_S20_FWTM_bot->Fit("f1_S20_FWTM_bot_gr95","R");
		f1_S20_FWTM_bot_gr05->Draw("same");
		f1_S20_FWTM_bot_gr95->Draw("same");		

		TF1 *f1_S21_FWTM_bot_gr05 = new TF1("f1_S21_FWTM_bot_gr05","pol2",2, 17);
		TF1 *f1_S21_FWTM_bot_gr95 = new TF1("f1_S21_FWTM_bot_gr95","pol2",2, 17);
			 f1_S21_FWTM_bot_gr05 ->SetLineColor(6);
			 f1_S21_FWTM_bot_gr95 ->SetLineColor(6);
		gr05_S21_FWTM_bot->Fit("f1_S21_FWTM_bot_gr05","R");
		gr95_S21_FWTM_bot->Fit("f1_S21_FWTM_bot_gr95","R");
		f1_S21_FWTM_bot_gr05->Draw("same");
		f1_S21_FWTM_bot_gr95->Draw("same");		

		
		char fform05_S20_FWTM_top[500];
		char fform05_S20_FWTM_bot[500];
		char fform05_S21_FWTM_top[500];
		char fform05_S21_FWTM_bot[500];

		char fform95_S20_FWTM_top[500];
		char fform95_S20_FWTM_bot[500];
		char fform95_S21_FWTM_top[500];
		char fform95_S21_FWTM_bot[500];

		sprintf(fform05_S20_FWTM_top, "%g + x*%g + x^2*%g", f1_S20_FWTM_top_gr05->GetParameter(0), f1_S20_FWTM_top_gr05->GetParameter(1), f1_S20_FWTM_top_gr05->GetParameter(2));
		sprintf(fform05_S20_FWTM_bot, "%g + x*%g + x^2*%g", f1_S20_FWTM_bot_gr05->GetParameter(0), f1_S20_FWTM_bot_gr05->GetParameter(1), f1_S20_FWTM_bot_gr05->GetParameter(2));
		sprintf(fform05_S21_FWTM_top, "%g + x*%g + x^2*%g", f1_S21_FWTM_top_gr05->GetParameter(0), f1_S21_FWTM_top_gr05->GetParameter(1), f1_S21_FWTM_top_gr05->GetParameter(2));
		sprintf(fform05_S21_FWTM_bot, "%g + x*%g + x^2*%g", f1_S21_FWTM_bot_gr05->GetParameter(0), f1_S21_FWTM_bot_gr05->GetParameter(1), f1_S21_FWTM_bot_gr05->GetParameter(2));

		sprintf(fform95_S20_FWTM_top, "%g + x*%g + x^2*%g", f1_S20_FWTM_top_gr95->GetParameter(0), f1_S20_FWTM_top_gr95->GetParameter(1), f1_S20_FWTM_top_gr95->GetParameter(2));
		sprintf(fform95_S20_FWTM_bot, "%g + x*%g + x^2*%g", f1_S20_FWTM_bot_gr95->GetParameter(0), f1_S20_FWTM_bot_gr95->GetParameter(1), f1_S20_FWTM_bot_gr95->GetParameter(2));
		sprintf(fform95_S21_FWTM_top, "%g + x*%g + x^2*%g", f1_S21_FWTM_top_gr95->GetParameter(0), f1_S21_FWTM_top_gr95->GetParameter(1), f1_S21_FWTM_top_gr95->GetParameter(2));
		sprintf(fform95_S21_FWTM_bot, "%g + x*%g + x^2*%g", f1_S21_FWTM_bot_gr95->GetParameter(0), f1_S21_FWTM_bot_gr95->GetParameter(1), f1_S21_FWTM_bot_gr95->GetParameter(2));

		cout <<">> S20_FWTM_top:   "<< fform05_S20_FWTM_top <<"  to  "<< fform95_S20_FWTM_top << endl;
		cout <<">> S20_FWTM_bot:   "<< fform05_S20_FWTM_bot <<"  to  "<< fform95_S20_FWTM_bot << endl;
		cout <<">> S21_FWTM_top:   "<< fform05_S21_FWTM_top <<"  to  "<< fform95_S21_FWTM_top << endl;
		cout <<">> S21_FWTM_bot:   "<< fform05_S21_FWTM_bot <<"  to  "<< fform95_S21_FWTM_bot << endl;


		char cut05_S20_FWTM_top[500];
		char cut05_S20_FWTM_bot[500];
		char cut05_S21_FWTM_top[500];
		char cut05_S21_FWTM_bot[500];

		char cut95_S20_FWTM_top[500];
		char cut95_S20_FWTM_bot[500];
		char cut95_S21_FWTM_top[500];
		char cut95_S21_FWTM_bot[500];

		sprintf(cut05_S20_FWTM_top, "S2widthLow_top>(%g + %g*dt_top %g*dt_top*dt_top)", f1_S20_FWTM_top_gr05->GetParameter(0), f1_S20_FWTM_top_gr05->GetParameter(1), f1_S20_FWTM_top_gr05->GetParameter(2));
		sprintf(cut05_S20_FWTM_bot, "S2widthLow_bot>(%g + %g*dt_bot %g*dt_top*dt_bot)", f1_S20_FWTM_bot_gr05->GetParameter(0), f1_S20_FWTM_bot_gr05->GetParameter(1), f1_S20_FWTM_bot_gr05->GetParameter(2));
		sprintf(cut05_S21_FWTM_top, "S2widthLow_top>(%g + %g*dt_top %g*dt_top*dt_top)", f1_S21_FWTM_top_gr05->GetParameter(0), f1_S21_FWTM_top_gr05->GetParameter(1), f1_S21_FWTM_top_gr05->GetParameter(2));
		sprintf(cut05_S21_FWTM_bot, "S2widthLow_bot>(%g + %g*dt_bot %g*dt_top*dt_top)", f1_S21_FWTM_bot_gr05->GetParameter(0), f1_S21_FWTM_bot_gr05->GetParameter(1), f1_S21_FWTM_bot_gr05->GetParameter(2));

		sprintf(cut95_S20_FWTM_top, "S2widthLow_top<(%g + %g*dt_top %g*dt_top*dt_top)", f1_S20_FWTM_top_gr95->GetParameter(0), f1_S20_FWTM_top_gr95->GetParameter(1), f1_S20_FWTM_top_gr95->GetParameter(2));
		sprintf(cut95_S20_FWTM_bot, "S2widthLow_bot<(%g + %g*dt_bot %g*dt_top*dt_bot)", f1_S20_FWTM_bot_gr95->GetParameter(0), f1_S20_FWTM_bot_gr95->GetParameter(1), f1_S20_FWTM_bot_gr95->GetParameter(2));
		sprintf(cut95_S21_FWTM_top, "S2widthLow_top<(%g + %g*dt_top %g*dt_top*dt_top)", f1_S21_FWTM_top_gr95->GetParameter(0), f1_S21_FWTM_top_gr95->GetParameter(1), f1_S21_FWTM_top_gr95->GetParameter(2));
		sprintf(cut95_S21_FWTM_bot, "S2widthLow_bot<(%g + %g*dt_bot %g*dt_top*dt_bot)", f1_S21_FWTM_bot_gr95->GetParameter(0), f1_S21_FWTM_bot_gr95->GetParameter(1), f1_S21_FWTM_bot_gr95->GetParameter(2));

		cout <<"TCut cut_S20_FWTM_top = "<< cut05_S20_FWTM_top <<" && "<< cut95_S20_FWTM_top <<";"<< endl;
		cout <<"TCut cut_S20_FWTM_bot = "<< cut05_S20_FWTM_bot <<" && "<< cut95_S20_FWTM_bot <<";"<< endl;
		cout <<"TCut cut_S21_FWTM_top = "<< cut05_S21_FWTM_top <<" && "<< cut95_S21_FWTM_top <<";"<< endl;
		cout <<"TCut cut_S21_FWTM_bot = "<< cut05_S21_FWTM_bot <<" && "<< cut95_S21_FWTM_bot <<";"<< endl;

	c3->Update();
    
}
