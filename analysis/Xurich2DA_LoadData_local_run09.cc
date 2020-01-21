	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA
	const char *DataFolder = "/Users/alexkish/data/xurich/xurich2/run_09";

	const char *DataSet1;
	const char *DataSetComment1; 
	//DataSet1 = "150515_1710";	DataSetComment1= "A=3.5kV, C=-1.5kV, Co57 front";
	//DataSet1 = "150518_1524";	DataSetComment1= "A=4.0kV, C=-1.5kV, Co57 front";
	//DataSet1 = "150519_1313";	DataSetComment1= "A=4.0kV, C=-1.5kV, Co57 front, Att.(top+bot)";
	//DataSet1 = "150519_1544_1";	DataSetComment1= "A=4.0kV, C=-1.5kV, Co57 front, Att.(top+bot)";
	//DataSet1 = "150519_1544_2";	DataSetComment1= "A=4.0kV, C=-1.5kV, Co57 front, Att.(top+bot)";
	//DataSet1 = "150519_1544_3";	DataSetComment1= "A=4.0kV, C=-1.5kV, Co57 front, Att.(top+bot)";
	//DataSet1 = "150519_1544_4";	DataSetComment1= "A=4.0kV, C=-1.5kV, Co57 front, Att.(top+bot)";
	//DataSet1 = "150519_1544_notChi2";	DataSetComment1= "A=4.0kV, C=-1.5kV, Co57 front, Att.(top+bot)";
	DataSet1 = "150521_1224";	DataSetComment1= "A=4.0kV, C=-3.0kV, Co57 left, Att.(top+bot), Trig. top discr. 10";

	Char_t  DataSetName1[500];
	sprintf(DataSetName1, "%s, %s", DataSet1, DataSetComment1);			
	

	//--------------------------------------------------
	Char_t  DataFile1[500];
	sprintf(DataFile1, "%s/%s.root", DataFolder, DataSet1);			

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);

	////////////////////////////////////////////
	// EXTENSIONS FOR SAVING THE PLOTS
	const char *extensionPlots = ".png";
	const char *extensionPlots_C = ".C";
	////////////////////////////////////////////
	
