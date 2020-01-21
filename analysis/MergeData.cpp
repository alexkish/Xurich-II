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
#include "TH2D.h"
#include "THStack.h"
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
#include "TList.h"
#include "TColor.h"
#include "TParameter.h"
#include "TEventList.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "/home/atp/fpiastra/xurich/analysis/code/T1alias.cc"
#include "/home/atp/fpiastra/xurich/analysis/code/SignCorr.cc" //There are the functions for S1s and S2s correction
#include "/home/atp/fpiastra/xurich/analysis/code/LoadData.cc"

string rawdatadir = "/home/atp/fpiastra/xurich/maindata/";
string maindatadir = "/home/atp/fpiastra/xurich/data/proc/";
string outdir = "/home/atp/fpiastra/xurich/data/merged/";


//Declarations of the scripts
void MergeData();
void MergeData(string dataset);
void MergeDataFromList(string datasetsfile);
void MergeDataFromList_std(string datasetsfile);//From xurich standard directories
void WriteParameters(string dataset, double Elif, double GateTime, double CathodeTime, double DriftVel, double ElField);
void WriteParamsFromList(string datasetsfile);


void MergeData(){
	
	//gROOT->ProcessLine("#include <vector>");
	//gROOT->ProcessLine("#include <string>");
	
	
	//string maindatadir = "/home/atp/fpiastra/xurich/maindata/";
	//string outdir = "/disk/data1/atp/fpiastra/xurich/data/merged/";

//#include "/home/atp/fpiastra/xurich/analysis/code/SelData.icc"
#include "/home/atp/fpiastra/xurich/analysis/code/Dataset_R12.icc"
	
	
	
#include "/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh"
gROOT->ProcessLine("#include \"/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh\"");
	
	
	map<string, vector<string> >::iterator It;
	for(It=datacollection.begin(); It!=datacollection.end(); ++It){
		string dsname = It->first;
		vector<string> datasets = It->second;
		
		cout << "\n\nDatasets collection <" << dsname << ">:" << endl;
		
		TChain *T1 = new TChain("T1");
		
		int nDSets = datasets.size();
		
		for(int i=0; i<nDSets; i++){
			string datasetchain = maindatadir+datasets[i]+string("/proc/T1*.root");
			cout << "Loading dataset: <" << datasetchain << ">" << endl;
			T1->Add( datasetchain.c_str() );
		}
	
		SetAliases((TTree*)T1);
		
		T1->Merge( (outdir+dsname+string(".root")).c_str() );
		
	}
	
	cout << endl << endl;
	
	return;
}

void MergeData(string dataset){
	
#include "/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh"
	gROOT->ProcessLine("#include \"/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh\"");
	
	
	TChain *T1 = new TChain("T1");
	//string datasetchain = maindatadir+datasets[iDs]+string("/proc/T1*.root");
	string datasetchain = maindatadir+dataset+string("/T1*.root");
	cout << "\nLoading dataset: <" << datasetchain << ">\n" << endl;
	T1->Add( datasetchain.c_str() );
	SetAliases((TTree*)T1);
	T1->Merge( (outdir+dataset+string(".root")).c_str() );
	T1->Delete();
	
	return;
	
}

void MergeDataFromList_std(string datasetsfile){
	
	//gROOT->ProcessLine("#include <vector>");
	//gROOT->ProcessLine("#include <string>");
	
	ifstream infile( datasetsfile.c_str() );
	if(!infile){
		cerr << "\n\nError: Cannot find/open file <" << datasetsfile << ">. QUIT!" << endl;
		return;
	}
	
#include "/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh"
gROOT->ProcessLine("#include \"/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh\"");
	
	vector<string> datasets;
	
	
	string ds_str;
	while( getline(infile,ds_str) ){
		stringstream line; line.clear(); line.str("");
		line << ds_str;
		line >> ds_str;
		datasets.push_back(ds_str);
	}
	
	int nDSets = datasets.size();
	
	cout << endl;
	cout << "Datasets to merge:" << endl;
	for(int iDs=0; iDs<nDSets; iDs++){
		cout << " " <<datasets.at(iDs) << endl;
	}
	cout << endl;
	
	
	
	for(int iDs=0; iDs<nDSets; iDs++){
		TChain *T1 = new TChain("T1");
		string datasetchain = maindatadir+datasets[iDs]+string("/proc/T1*.root");
		cout << "\nLoading dataset: <" << datasetchain << ">\n" << endl;
		T1->Add( datasetchain.c_str() );
		SetAliases((TTree*)T1);
		string datasetname = datasets.at(iDs);
		T1->Merge( (outdir+datasetname+string(".root")).c_str() );
		T1->Delete();
	}
	
	return;
}

void MergeDataFromList(string datasetsfile){
	
	//gROOT->ProcessLine("#include <vector>");
	//gROOT->ProcessLine("#include <string>");
	
	ifstream infile( datasetsfile.c_str() );
	if(!infile){
		cerr << "\n\nError: Cannot find/open file <" << datasetsfile << ">. QUIT!" << endl;
		return;
	}
	
#include "/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh"
gROOT->ProcessLine("#include \"/home/atp/fpiastra/xurich/analysis/code/T1cuts.ihh\"");
	
	vector<string> datasets;
	
	
	string ds_str;
	while( getline(infile,ds_str) ){
		stringstream line; line.clear(); line.str("");
		line << ds_str;
		line >> ds_str;
		datasets.push_back(ds_str);
	}
	
	int nDSets = datasets.size();
	
	cout << endl;
	cout << "Datasets to merge:" << endl;
	for(int iDs=0; iDs<nDSets; iDs++){
		cout << " " <<datasets.at(iDs) << endl;
	}
	cout << endl;
	
	//string maindatadir = "/home/atp/fpiastra/xurich/maindata/";
	//string maindatadir = "/home/atp/fpiastra/xurich/data/";
	//string outdir = "/disk/data1/atp/fpiastra/xurich/data/merged/";

	//#include "/home/atp/fpiastra/xurich/analysis/code/SelData.icc"
	
	
	for(int iDs=0; iDs<nDSets; iDs++){
		TChain *T1 = new TChain("T1");
		//string datasetchain = maindatadir+datasets[iDs]+string("/proc/T1*.root");
		string datasetchain = maindatadir+datasets[iDs]+string("/T1*.root");
		cout << "\nLoading dataset: <" << datasetchain << ">\n" << endl;
		T1->Add( datasetchain.c_str() );
		SetAliases((TTree*)T1);
		string datasetname = datasets.at(iDs);
		T1->Merge( (outdir+datasetname+string(".root")).c_str() );
		T1->Delete();
	}
	
	return;
}


void WriteParamsFromList(string datasetsfile){
	
	ifstream listfile(datasetsfile.c_str());
	string line;
	stringstream ss_tmp;
	while(getline(listfile,line)){
		ss_tmp.clear();
		ss_tmp.str("");
		ss_tmp << line;
		
		string dataset;
		ss_tmp>>dataset;
		
		double Elif;
		ss_tmp >> line;
		Elif = atof(line.c_str());
		
		double GateTime;
		ss_tmp >> line;
		GateTime = atof(line.c_str());
		
		double CathodeTime;
		ss_tmp >> line;
		CathodeTime = atof(line.c_str());
		
		double DriftVel;
		ss_tmp >> line;
		DriftVel = atof(line.c_str());
		
		double ElField;
		ss_tmp >> line;
		ElField = atof(line.c_str());
		
		WriteParameters(dataset, Elif, GateTime, CathodeTime, DriftVel, ElField);
	}
	return;
}

void WriteParameters(string dataset, double elif, double GateTime, double CathodeTime, double DriftVel, double ElField){
	
	stringstream ss_tmp;
	
	ss_tmp.str(""); ss_tmp << rawdatadir << dataset << "/";
	string datadir = ss_tmp.str();
	
	ss_tmp.str(""); ss_tmp << maindatadir << dataset << "/";
	string procdir = ss_tmp.str();
	
	string mergeddir = outdir;
	
	
	//First check that ALL the files needed are in proper places
	ss_tmp.str(""); ss_tmp << mergeddir << dataset << ".root";
	string mergedfilename =ss_tmp.str();
	
	TFile *mergedfile = TFile::Open(mergedfilename.c_str(),"read");
	if(!mergedfile){
		cerr << "\nCannot find/open file <" << mergedfilename << ">. Abort execution." << endl;
		delete mergedfile;
		return;
	}
	delete mergedfile;
	mergedfile = TFile::Open(mergedfilename.c_str(),"update");
	
	
	ss_tmp.str(""); ss_tmp << rawdatadir << dataset << "/" << dataset << ".xml";
	string hardwarexml_name = ss_tmp.str();
	
	ifstream hrdxml(hardwarexml_name.c_str());
	if(!hrdxml){
		cerr << "\nCannot find/open file <" << hardwarexml_name << ">. Abort execution." << endl;
		delete mergedfile;
		return;
	}
	
	
	ss_tmp.str(""); ss_tmp << rawdatadir << dataset << "/" << dataset << ".xml";
	string procxml_name = ss_tmp.str();
	
	ifstream procxml(procxml_name.c_str());
	if(!procxml){
		cerr << "\nCannot find/open file <" << procxml_name << ">. Abort execution." << endl;
		delete mergedfile;
		return;
	}
	
	
	TParameter<double> *tpElif = new TParameter<double>("Elif",elif);
	TParameter<double> *tpGateTime = new TParameter<double>("GateTime",GateTime);
	TParameter<double> *tpCathodeTime = new TParameter<double>("CathodeTime",CathodeTime);
	TParameter<double> *tpDriftVel = new TParameter<double>("DriftVel",DriftVel);
	TParameter<double> *tpElField = new TParameter<double>("ElField",ElField);
	
	
	string *str = new string;
	
	string line;
	stringstream tmpText; tmpText.str("");
	while(getline(hrdxml,line)){
		
		if(line==string("")){
			tmpText << endl;
		}
		
		tmpText << line << endl;
	}
	
	(*str) = tmpText.str();
	mergedfile->WriteObject(str,"DAQxml");
	
	
	tmpText.str("");
	while(getline(procxml,line)){
		
		if(line==string("")){
			tmpText << endl;
		}
		
		tmpText << line << endl;
	}
	
	(*str) = tmpText.str();
	mergedfile->WriteObject(str,"T1xml");
	
	mergedfile->WriteTObject(tpElif, 0, "overwrite");
	mergedfile->WriteTObject(tpGateTime, 0, "overwrite");
	mergedfile->WriteTObject(tpCathodeTime, 0, "overwrite");
	mergedfile->WriteTObject(tpDriftVel, 0, "overwrite");
	mergedfile->WriteTObject(tpElField, 0, "overwrite");
	
	delete mergedfile;
	delete tpElif;
	delete tpGateTime;
	delete tpCathodeTime;
	delete tpDriftVel;
	delete tpElField;
	delete str;
	
	return;
}

// .L MergeData.cpp++
