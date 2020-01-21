	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA

	// run_08
	//const char *DataFolder = "/Users/alexkish/data/xurich/xurich2/run_08";
	const char *DataFolder = "/Users/alexkish/data/xurich_farm";

	// run_08
	// A = 3kV
	//const char *DataSet1	= "140909_1029";	// 1 (front)
	//const char *DataSet1	= "140909_1801";	// 2 (back)
	//const char *DataSet1	= "140910_1049";	// 3 (right)
	//const char *DataSet1	= "140908_1407";	// 4 (left)
	//const char *DataSet1	= "T1_140909_1029_00001";
	//const char *DataSet1	= "T1_140922_1750_chi015";

	//const char *DataSet1	= "140929_1226";	// A=3.0kV
	//const char *DataSet1	= "140924_1919";	// A=2.5kV
	//const char *DataSet1	= "140925_0933";	// A=2.0kV
	//const char *DataSet1	= "140925_1758";	// A=1.5kV

	// A = 2kV
	//const char *DataSet1	= "140925_0933";	// 1 (front)
	//const char *DataSet1	= "140925_0933_v1";
	//const char *DataSet1	= "140925_0933_v2"; 	const char *DataSetComment1 = "pos.1 (front)";
	//const char *DataSet1	= "140925_0933_fra"; 	const char *DataSetComment1 = "pos.1 (front)";
	//const char *DataSet1	= "140930_1030";	// 2 (right)
	//const char *DataSet1	= "140930_1402";	// 3 (back)
	//const char *DataSet1	= "140930_1739";	// 4 (left)
	
	//const char *DataSet1	= "141014_1120";	const char *DataSetComment1 = "pos.1 (front), before turning the screw";
	//const char *DataSet1	= "141015_1448";	const char *DataSetComment1 = "pos.1 (front), after turning the screw (1 turn)";
	//const char *DataSet1	= "141021_1511";	const char *DataSetComment1 = "pos.1 (front), 3 full turns of the front screw";

	//const char *DataSet1	= "141014_1555";	const char *DataSetComment1 = "pos.3 (back), before turning the screw";
	//const char *DataSet1	= "141015_1035";	const char *DataSetComment1 = "pos.3 (back), after turning the screw (1 turn)";
	//const char *DataSet1	= "141021_1758";	const char *DataSetComment1 = "pos.3 (back), 3 full turns of the front screw";
	
	//const char *DataSet1	= "141022_1026";	const char *DataSetComment1 = "pos.3 (back), initial screw position";

	//const char *DataSet1	= "141022_1526";	const char *DataSetComment1 = "pos.1 (front)";
	//const char *DataSet1	= "141023_0938";	const char *DataSetComment1 = "pos.1 (front), LXe level 1.56mm above the bottom LVM";
	//const char *DataSet1	= "141023_1659";	const char *DataSetComment1 = "pos.1 (front), LXe level 0.94mm above the bottom LVM";
	//const char *DataSet1	= "141024_1154";	const char *DataSetComment1 = "pos.1 (front), LXe level 0.94mm above the bottom LVM, C-57-236";
	//const char *DataSet1	= "141027_1444";	const char *DataSetComment1 = "pos.1 (front), LXe level 1.88mm above the bottom LVM, C-57-236";
	//const char *DataSet1	= "141028_1418";	const char *DataSetComment1 = "pos.1 (front), LXe level 2.5mm above the bottom LVM, C-57-236";
	const char *DataSet1	= "141030_1805";	const char *DataSetComment1 = "pos.1 (front), LXe level 1.75mm above the bottom LVM, C-57-236";

	
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
	

