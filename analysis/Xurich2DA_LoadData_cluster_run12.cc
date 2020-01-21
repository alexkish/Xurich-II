	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA
	//const char *DataFolder = "/Users/alexkish/data/xurich/xurich2/run_11";
	//const char *DataFolder = "/Users/alexkish/data/xurich_farm";
	//const char *DataFolder = "/disk/data1/atp/xurich/data";
	const char *DataFolder = "/disk/data11/xurich/data";
	///home/atp/fpiastra/xurich/data/merged

	const char *DataSet1, *DataSet2, *DataSet3, *DataSet4, *DataSet5, *DataSet6, *DataSet7, *DataSet8, *DataSet9, *DataSet10;
	const char *DataSetComment1;


	// Kr-83m
	DataSet1  = "161012_2153";	DataSetComment1  = "A=4.0kV, C=-3.0kV"; // NG ON


	////////////////////////////
	// Neutron generator
	
	// COINCIDENCE DATA
	//DataSet1  = "160928_1302";	DataSetComment1  = "A=4.0kV, C=-3.0kV";
	//DataSet1  = "161012_2153";	DataSetComment1  = "A=4.0kV, C=-3.0kV"; // NG ON, Kr ON
	 




	Char_t  DataSetName1[500];
	sprintf(DataSetName1, "%s, %s", DataSet1, DataSetComment1);			
	

	//--------------------------------------------------
	Char_t  DataFile1[500];
	Char_t  DataFile2[500];
	Char_t  DataFile3[500];
	Char_t  DataFile4[500];
	Char_t  DataFile5[500];
	Char_t  DataFile6[500];
	Char_t  DataFile7[500];
	Char_t  DataFile8[500];
	Char_t  DataFile9[500];
	Char_t  DataFile10[500];
	
	// Load ALL files
	sprintf(DataFile1, "%s/%s/proc/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	// Load ONE file
	//sprintf(DataFile1, "%s/%s/proc/T1_%s_Module_0_100.root", DataFolder, DataSet1, DataSet1);			
	// Load FEW files
/*	sprintf(DataFile1, 	"%s/%s/proc/T1_%s_Module_0_10.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile2, 	"%s/%s/proc/T1_%s_Module_0_11.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile3, 	"%s/%s/proc/T1_%s_Module_0_12.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile4, 	"%s/%s/proc/T1_%s_Module_0_13.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile5, 	"%s/%s/proc/T1_%s_Module_0_14.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile6, 	"%s/%s/proc/T1_%s_Module_0_15.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile7, 	"%s/%s/proc/T1_%s_Module_0_16.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile8, 	"%s/%s/proc/T1_%s_Module_0_17.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile9, 	"%s/%s/proc/T1_%s_Module_0_18.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile10, "%s/%s/proc/T1_%s_Module_0_19.root", DataFolder, DataSet1, DataSet1);			
*/
	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
/*			T1	->Add(DataFile2);
			T1	->Add(DataFile3);
			T1	->Add(DataFile4);
			T1	->Add(DataFile5);
			T1	->Add(DataFile6);
			T1	->Add(DataFile7);
			T1	->Add(DataFile8);
			T1	->Add(DataFile9);
			T1	->Add(DataFile10);
*/
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
/*			T1mpd4	->Add(DataFile2);
			T1mpd4	->Add(DataFile3);
			T1mpd4	->Add(DataFile4);
			T1mpd4	->Add(DataFile5);
			T1mpd4	->Add(DataFile6);
			T1mpd4	->Add(DataFile7);
			T1mpd4	->Add(DataFile8);
			T1mpd4	->Add(DataFile9);
			T1mpd4	->Add(DataFile10);
*/	
	T1->AddFriend(T1mpd4);



	////////////////////////////////////////////
	// EXTENSIONS FOR SAVING THE PLOTS
	const char *extensionPlots = ".png";
	const char *extensionPlots_C = ".C";
	////////////////////////////////////////////
