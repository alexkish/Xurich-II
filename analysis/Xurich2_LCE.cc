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
#include "TH2F.h"
#include "TH3.h"
#include "TH3F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TLegend.h"
#include "TCut.h"
#include "TPie.h"
#include "TPieSlice.h"
#include "TPaletteAxis.h"
#include "TPaveStats.h"
#include "TList.h"
#include "TMarker.h"
#include "TColor.h"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"


void Xurich2_LCE()
{	
	gStyle	->SetOptStat(0);
	gStyle	->SetOptFit(0);

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
	
	gStyle->SetStatBorderSize(0);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFillColor(10);
	gStyle->SetStatColor(10);
	gStyle->SetStatFont(42);
	gStyle->SetMarkerStyle(7);
	gStyle->SetMarkerColor(1);
	
	////////////////////////////////////////////////////////////////////////////////
	// DATA
	const char *DataFolder 	= "/Users/alexkish/data/xurich/xurich2/mc/LCE";	// idark05x
	
	//const char *DataSet		= "PhotonTEST_ph1e3-ev1e4.root_Tpc";
	const char *DataSet		= "PhotonTEST1_ph1e3-ev1e4.root_Tpc";
	
	Char_t  DataFile[500];
	sprintf(DataFile, "%s/%s.root", DataFolder, DataSet);			

	TChain *t1	= new TChain("Tree");
			t1	->Add(DataFile);

	int k = t1->GetEntries();
	cout << "Length of the DATA Tree   k = "	<< k << endl;


	////////////////////////////////////////////////////////////////////////////////
	// ALIAS
	const double offsetX 			= 0; 
	const double offsetY 			= -2560;
	const double offsetZ 			= 1095;
	const double Nphotons 			= 1000;
	const double eDriftVelocity 	= -1.8;

	Char_t  Rmm_char[500];
	Char_t  Amm_char[500];
	Char_t  Xmm_char[500];
	Char_t  Ymm_char[500];
	Char_t  Zmm_char[500];
	Char_t  dt_char[500];
	sprintf(Rmm_char, 	"sqrt(pow((primaryX-%g),2)+pow((primaryY-%g),2))", offsetX, offsetY);
	sprintf(Amm_char, 	"(pow((primaryX-%g),2)+pow((primaryY-%g),2))*TMath:Pi/100", offsetX, offsetY);
	sprintf(Xmm_char, 	"primaryX-%g", offsetX);
	sprintf(Ymm_char, 	"primaryY-%g", offsetY);
	sprintf(Zmm_char, 	"primaryZ-%g", offsetZ);
	sprintf(dt_char, 	"(primaryZ-%g)/eDriftVelocity", offsetZ);

	Char_t  LCE_char[500];
	Char_t  LCEtop_char[500];
	Char_t  LCEbot_char[500];
	sprintf(LCE_char, 		"(numTopPmtHits+numBottomPmtHits)/%g*100", Nphotons);
	sprintf(LCEtop_char, 	"numTopPmtHits/%g*100", Nphotons);
	sprintf(LCEbot_char, 	"numBottomPmtHits/%g*100", Nphotons);

	t1	->SetAlias("Rmm", 		Rmm_char);
	t1	->SetAlias("Amm", 		Amm_char);
	t1	->SetAlias("Xmm", 		Xmm_char);
	t1	->SetAlias("Ymm", 		Ymm_char);
	t1	->SetAlias("Zmm", 		Zmm_char);
	t1	->SetAlias("dt", 		dt_char);
	t1	->SetAlias("LCE", 		LCE_char);
	t1	->SetAlias("LCEtop", 	LCEtop_char);
	t1	->SetAlias("LCEbot", 	LCEbot_char);
	t1	->SetAlias("S1asym",	"(numTopPmtHits-numBottomPmtHits)/(numTopPmtHits+numBottomPmtHits)");




	////////////////////////////////////////////////////////////////////////////////
	// HISTOGRAMS
	double nbins_X	= 35;;
	double X_min	= -35;
	double X_max	= 35;

	double nbins_Y	= 35;;
	double Y_min	= -35;
	double Y_max	= 35;
	
	double nbins_R	= 25;
	double R_min	= 0;
	double R_max	= 50;

	double nbins_A	= 50;
	double A_min	= 0;
	double A_max	= 8e3;
	
	double nbins_Z	= 35;
	double Z_min	= -35;
	double Z_max	= 16;
	
	double nbins_ratio	= 20;
	double ratio_min	= 0;
	double ratio_max	= 100;
		
	TH2F *hXZhits 		= new TH2F("hXZhits", 		"", nbins_X, X_min, X_max, nbins_Z, Z_min, Z_max);
	TH2F *hRZhits 		= new TH2F("hRZhits", 		"", nbins_R, R_min, R_max, nbins_Z, Z_min, Z_max);
	TH2F *hRZhitsTop 	= new TH2F("hRZhitsTop", 	"", nbins_R, R_min, R_max, nbins_Z, Z_min, Z_max);
	TH2F *hRZhitsBot 	= new TH2F("hRZhitsBot", 	"", nbins_R, R_min, R_max, nbins_Z, Z_min, Z_max);
	TH2F *hAZhits 		= new TH2F("hAZhits", 		"", nbins_A, A_min, A_max, nbins_Z, Z_min, Z_max);
	TH2F *hXYhits 		= new TH2F("hXYhits", 		"", nbins_X, X_min, X_max, nbins_Y, Y_min, Y_max);

	//TH2F *hXZasym 	= new TH2F("hXZasymTarget", 	"", 50, -TargetVolume_radius, TargetVolume_radius, nbins_Z, Z_min, Z_max);

	TH2F *hS1asymLCE 	= new TH2F("hS1asymLCE", 	"", 100, -1, 1, 100, 0, 100);

/*	TH1F *h_hits_target 	= new TH1F("h_hits_target",		"", 200, 0, 65);
		  h_hits_target->SetLineColor(4);

	TH2F *h_Zhits_target 	= new TH2F("h_Zhits_target",	"", 200, 0, 65, nbins_Z, Z_min, Z_max);

	TH2F *hRZLY 			= new TH2F("hRZLY", 			"", nbins_R, R_min, R_max, nbins_Z, Z_min, Z_max);
	TH2F *hRZLY_topVeto 	= new TH2F("hRZLY_topVeto", 	"", 16, 0, 16, 7, 9, 16);

	TH2F *hTZLCE 			= new TH2F("hTZLCE", 			"", 100, -1.6, 1.6, nbins_Z, -40, 14);
	TH2F *hTZLY 			= new TH2F("hTZLY", 			"", 100, -1.6, 1.6, nbins_Z, -40, 14);

	TH2F *hZLY 				= new TH2F("hZLY", 				"", 50, Z_min, Z_max, 50, 0, 5);
	TH2F *hZLY1 			= new TH2F("hZLY1", 			"", 50, Z_min, Z_max, 50, 0, 5);
		  hZLY1->SetMarkerColor(2);
	TH1F *h1_LY 			= new TH1F("h1_LY", 			"", 1000, 0, 5);
		  h1_LY->SetLineColor(4);
		  h1_LY->SetLineWidth(2);
	TH1F *h1_LY1 			= new TH1F("h1_LY1", 			"", 1000, 0, 5);
		  h1_LY1->SetLineColor(2);
		  h1_LY1->SetLineWidth(2);
*/



	//////////////////////////////////////////////////////////////////////////////////////
	// PLOT
	// LCE	
	TCanvas *cRZhits = new TCanvas("cRZhits", "cRZhits", 0, 0, 700, 700);
			 cRZhits->SetFillColor(10);
   			 cRZhits->SetBorderSize(2);
   			 cRZhits->SetGridx();
   			 cRZhits->SetGridy();
   			 cRZhits->SetRightMargin(0.1609195);
   			 cRZhits->SetFrameFillColor(0);
		t1	->Draw("Zmm:Rmm:LCE>>hRZhits", "", "COLZ");
		hRZhits->SetTitle(0);
		hRZhits->GetXaxis()->SetTitle("R [mm]");
		hRZhits->GetXaxis()->CenterTitle(true);
		hRZhits->GetYaxis()->SetTitle("Z [mm]");
		hRZhits->GetYaxis()->CenterTitle(true);
		hRZhits->GetZaxis()->SetTitle("LCE [%]");
		hRZhits->GetZaxis()->CenterTitle(true);
		hRZhits->GetZaxis()->SetTitleOffset(1.35);		
	cRZhits->Update();

	TCanvas *cRZhitsTop = new TCanvas("cRZhitsTop", "cRZhitsTop", 705, 0, 700, 700);
			 cRZhitsTop->SetFillColor(10);
   			 cRZhitsTop->SetBorderSize(2);
   			 cRZhitsTop->SetGridx();
   			 cRZhitsTop->SetGridy();
   			 cRZhitsTop->SetRightMargin(0.1609195);
   			 cRZhitsTop->SetFrameFillColor(0);
		t1	->Draw("Zmm:Rmm:LCEtop>>hRZhitsTop", "", "COLZ");
		hRZhitsTop->SetTitle(0);
		hRZhitsTop->GetXaxis()->SetTitle("R [mm]");
		hRZhitsTop->GetXaxis()->CenterTitle(true);
		hRZhitsTop->GetYaxis()->SetTitle("Z [mm]");
		hRZhitsTop->GetYaxis()->CenterTitle(true);
		hRZhitsTop->GetZaxis()->SetTitle("top LCE [%]");
		hRZhitsTop->GetZaxis()->CenterTitle(true);
		hRZhitsTop->GetZaxis()->SetTitleOffset(1.35);		
	cRZhitsTop->Update();

	TCanvas *cRZhitsBot = new TCanvas("cRZhitsBot", "cRZhitsBot", 1410, 0, 700, 700);
			 cRZhitsBot->SetFillColor(10);
   			 cRZhitsBot->SetBorderSize(2);
   			 cRZhitsBot->SetGridx();
   			 cRZhitsBot->SetGridy();
   			 cRZhitsBot->SetRightMargin(0.1609195);
   			 cRZhitsBot->SetFrameFillColor(0);
		t1	->Draw("Zmm:Rmm:LCEbot>>hRZhitsBot", "", "COLZ");
		hRZhitsBot->SetTitle(0);
		hRZhitsBot->GetXaxis()->SetTitle("R [mm]");
		hRZhitsBot->GetXaxis()->CenterTitle(true);
		hRZhitsBot->GetYaxis()->SetTitle("Z [mm]");
		hRZhitsBot->GetYaxis()->CenterTitle(true);
		hRZhitsBot->GetZaxis()->SetTitle("bottom LCE [%]");
		hRZhitsBot->GetZaxis()->CenterTitle(true);
		hRZhitsBot->GetZaxis()->SetTitleOffset(1.35);		
	cRZhitsBot->Update();


	// S1 asymmetry 
	TCanvas *cS1asymLCE = new TCanvas("cS1asymLCE", "cS1asymLCE", 0, 705, 700, 700);
			 cS1asymLCE->SetFillColor(10);
   			 cS1asymLCE->SetBorderSize(2);
   			 cS1asymLCE->SetGridx();
   			 cS1asymLCE->SetGridy();
   			 cS1asymLCE->SetRightMargin(0.1609195);
   			 cS1asymLCE->SetFrameFillColor(0);
		t1	->Draw("Zmm:S1asym:LCE>>hS1asymLCE", "", "COLZ");
			hS1asymLCE->SetTitle(0);
			hS1asymLCE->GetXaxis()->SetTitle("S1 asymmetry");
			hS1asymLCE->GetXaxis()->CenterTitle(true);
			hS1asymLCE->GetYaxis()->SetTitle("Z [mm]");
			hS1asymLCE->GetYaxis()->CenterTitle(true);
			hS1asymLCE->GetZaxis()->SetTitle("LCE [%]");
			hS1asymLCE->GetZaxis()->CenterTitle(true);
			hS1asymLCE->GetZaxis()->SetTitleOffset(1.40);
/*		TLine *l1_cathode = new TLine(-15.4, -30.3, 15.4, -30.3);
			   l1_cathode->SetLineColor(1);
			   l1_cathode->SetLineWidth(2);
			   l1_cathode->SetLineStyle(2);
			   l1_cathode->Draw("SAME");
		TLine *l1_window = new TLine(-15.4, -31.1, 15.4, -31.1);
			   l1_window->SetLineColor(1);
			   l1_window->SetLineWidth(2);
			   l1_window->SetLineStyle(2);
			   l1_window->Draw("SAME");			   		   
*/	cS1asymLCE->Update();


}



