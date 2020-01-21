	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA

	// run_08
	//const char *DataFolder = "/Users/alexkish/data/xurich/xurich2/run_08";
	//const char *DataFolder = "/Users/alexkish/data/xurich_farm";
	//const char *DataFolder = "/disk/data1/atp/fpiastra/xuerich/data/C2proc";
	//const char *DataFolder = "/Users/alexkish/data/xurich_farm_francesco";
	//const char *DataFolder = "/home/atp/xurich/data";
	//const char *DataFolder = "/disk/data1/atp/xurich/data";
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

	// A=2kV, C=3kV
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

	// A = 2kV, C variable
	//const char *DataSet1	= "141110_0950";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=3.0kV";
	//const char *DataSet1	= "141110_1216";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=2.5kV";
	//const char *DataSet1	= "141110_1432";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=2.0kV";
	//const char *DataSet1	= "141110_1805";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=1.5kV";

	// A variable, C variable
	//const char *DataSet1	= "141114_1133";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=1.75kV, C=1.5kV";
	//const char *DataSet1	= "141114_1409";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=1.5kV, C=1.5kV";
	//const char *DataSet1	= "141114_1719";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=1.25kV";

	// A = 2kV, C variable
	//const char *DataSet1	= "141117_1417";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=3.0kV";
	//const char *DataSet1	= "141117_1750";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=1.5kV";

	// A = 2kV, C variable
	//const char *DataSet1	= "141120_1225";	const char *DataSetComment1 = "Co-57 front; LXe 2.2mm; A=2.0kV, C=3.0kV";
	//const char *DataSet1	= "141117_1750";	const char *DataSetComment1 = "Co-57, pos.1 (front), LXe level 1.88mm; A=2.0kV, C=1.5kV";
	//const char *DataSet1	= "141121_1509";	const char *DataSetComment1 = "Co-57 front; LXe 1.88mm; A=2.0kV, C=3.0kV";


	// increased anode, C=2kV
	//const char *DataSet1	= "141122_1611";	const char *DataSetComment1 = "Co-57 front; LXe 1.88mm; A=2.0kV, C=3.0kV";
	//const char *DataSet1	= "141124_1030";	const char *DataSetComment1 = "Co-57 front; LXe 1.88mm; A=2.0kV, C=3.5kV";
	//const char *DataSet1	= "141124_1219";	const char *DataSetComment1 = "Co-57 front; LXe 1.88mm; A=2.0kV, C=4.0kV";
	//const char *DataSet1	= "141124_1444";	const char *DataSetComment1 = "Co-57 front; LXe 1.88mm; A=2.0kV, C=4.0kV, att.top";
	const char *DataSet1	= "141124_1828";	const char *DataSetComment1 = "Co-57 front; LXe 1.88mm; A=2.0kV, C=4.0kV, att.top";



	// Kr-83m
	//const char *DataSet1	= "141103_1245";	const char *DataSetComment1 = "Kr-83m, LXe level 1.88mm above the bottom LVM";
	//const char *DataSet1	= "141107_1551";	const char *DataSetComment1 = "BG, LXe level 1.88mm above the bottom LVM";
	
	
	Char_t  DataSetName1[500];
	sprintf(DataSetName1, "%s, %s", DataSet1, DataSetComment1);			
	

	//--------------------------------------------------
	Char_t  DataFile1[500];
	//sprintf(DataFile1, "%s/%s/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	//sprintf(DataFile1, "%s/%s/proc/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	//sprintf(DataFile1, "%s/proc/%s/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile1, "%s/%s/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	
	cout << "Opening DataFile: "<< DataFile1 << endl;

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);




	////////////////////////////////////////////
	// EXTENSIONS FOR SAVING THE PLOTS
	const char *extensionPlots = ".png";
	const char *extensionPlots_C = ".C";
	////////////////////////////////////////////
	

