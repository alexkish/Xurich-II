	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA
	//const char *DataFolder = "/Users/alexkish/data/xurich/xurich2/run_11";
	//const char *DataFolder = "/Users/alexkish/data/xurich_farm";
	const char *DataFolder = "/disk/data1/atp/xurich/data";

	const char *DataSet1;
	const char *DataSetComment1;
	//DataSet1 = "151015_1447";	DataSetComment1= "A=4.0kV, C=-3.0kV, Co57 front, No att., Trig. bot discr. 0";
	DataSet1 = "151016_1656";	DataSetComment1= "A=4.0kV, C=-3.0kV, LXe=1.5mm, Kr-83m, Trig. bot discr. 0";

	Char_t  DataSetName1[500];
	sprintf(DataSetName1, "%s, %s", DataSet1, DataSetComment1);			
	

	//--------------------------------------------------
	Char_t  DataFile1[500];
	//sprintf(DataFile1, "%s/proc_chi1/%s.root", DataFolder, DataSet1);			
	//sprintf(DataFile1, "%s/%s/proc_chi1/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile1, "%s/%s/proc/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);

	////////////////////////////////////////////
	// EXTENSIONS FOR SAVING THE PLOTS
	const char *extensionPlots = ".png";
	const char *extensionPlots_C = ".C";
	////////////////////////////////////////////
	
