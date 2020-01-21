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
#include "TProof.h"
//#include "ProofFirst.h"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"

// define vectors
#include <vector>
//#ifdef __CINT__
#pragma link C++ class vector<vector<int> >;
#pragma link C++ class vector<vector<double> >;
//#endif


void Xurich2DataAnalysisROOT_v4()
{	

	gInterpreter->EnableAutoLoading();
	
	gROOT->ProcessLine("#include <vector>");

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
	
	// run_09
	//#include "Xurich2DA_LoadData_local_run09.cc"
	//#include "Xurich2DA_LoadData_cluster_run09.cc"
	//#include "Xurich2DA_LoadData_cluster_Merged.cc"
	//#include "Xurich2DA_LoadData_cluster_NotMerged.cc"
	
	// run_11
	//#include "Xurich2DA_LoadData_local_run11.cc"
	//#include "Xurich2DA_LoadData_cluster_run11.cc"

	// run_12
	//#include "Xurich2DA_LoadData_cluster_run12.cc"
	#include "Xurich2DA_LoadData_scattering.cc"


	//#include "Xurich2DA_BranchesOFF.cc"
	#include "Xurich2DA_SetAlias.cc"
	#include "Xurich2DA_SetCuts.cc"
	
	
	int nEventsTotal		= T1 ->GetEntries();	
	cout <<"Total number of events in the TTree = "<< nEventsTotal 	<< endl;
	int nEventsSurvived		= T1 ->GetEntries(cut_all);		
	double FractionSurvivedEvents = (double)nEventsSurvived/(double)nEventsTotal*100;
	cout <<"Number of events survived all cuts   = "<< nEventsSurvived <<"  ("<< FractionSurvivedEvents <<"%)"<< endl;

	double ScalingFactor 	= 1/nEventsTotal;
	
	//T1->SetProof();
	
	
	//#include "Xurich2DA_TraceSelector.cc";
	#include "Xurich2DA_LoadEventList.cc";

	#include "Xurich2DA_PlotAll.cc";
	//#include "Xurich2DA_Kr83m.cc";
	
	//#include "Xurich2DA_PlotS1raw.cc";
	//#include "Xurich2DA_PlotS1pe.cc";
	//#include "Xurich2DA_PlotS1peCor.cc";

	//#include "Xurich2DA_PlotS2raw.cc";
	//#include "Xurich2DA_PlotS2pe.cc";

	//#include "Xurich2DA_PlotTraceMax.cc";
	//#include "Xurich2DA_coincidence.cc";

	//#include "Xurich2DA_S1DTcorrection.cc";
	//#include "Xurich2DA_S1ASYMvsS1.cc";
	
	//#include "Xurich2DA_S2levelingArea.cc";
	//#include "Xurich2DA_S2levelingWidth.cc";

	//#include "Xurich2DA_TraceMax.cc";

	//#include "Xurich2DA_PlotMPD4.cc";
	//#include "Xurich2DA_PlotMPD4_loop.cc";

	//#include "Xurich2DA_PlotS1S2delay.cc";
	//#include "Xurich2DA_S2width.cc";
	//#include "Xurich2DA_S2widthDTcorrection.cc";



	//T1->SetProof(0);
}
