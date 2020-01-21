	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA

	//const char *DataFolder = "/Users/alexkish/data/xurich_farm";
	const char *DataFolder = "/Users/alexkish/data/xurich_farm/processed_files/2015_calibration/Cs137";


	// Co-57
	//const char *DataSet1	= "150520_1334";	const char *DataSetComment1 = "A=0kV, C=0kV";// att. top+bot, trig. top-10";
	//const char *DataSet1	= "150521_1224";	const char *DataSetComment1 = "A=4.0kV, C=-3.0kV";// att. top+bot, trig. top-10";
	//const char *DataSet1	= "150521_1440";	const char *DataSetComment1 = "A=3.0kV, C=-3.0kV";// att. top+bot, trig. top-10";
	//const char *DataSet1	= "150521_1653";	const char *DataSetComment1 = "A=2.0kV, C=-3.0kV";// att. top+bot, trig. top-10";
	//const char *DataSet1	= "150521_1905";	const char *DataSetComment1 = "A=3.0kV, C=-1.5kV";// att. top+bot, trig. top-10";
	//const char *DataSet1	= "150522_1052";	const char *DataSetComment1 = "A=3.0kV, C=-1.5kV";// att. top+bot, trig. top-10", liquid level lowered by 10deg
	//const char *DataSet1	= "150522_1347";	const char *DataSetComment1 = "A=3.0kV, C=-1.5kV, PMT925V, LL10deg";// att. top+bot, trig. top-10", liquid level lowered by 10deg
	//const char *DataSet1	= "150522_1604";	const char *DataSetComment1 = "BG, A=3.0kV, C=-1.5kV, PMT925V, LL10deg";// att. top+bot, trig. top-10", liquid level lowered by 10deg
	//const char *DataSet1	= "150522_1737";	const char *DataSetComment1 = "A=3.0kV, C=-1.5kV, PMT900V, LL10deg";// att. top+bot, trig. top-10", liquid level lowered by 10deg, both Co57 sources together
	//const char *DataSet1	= "150522_1840";	const char *DataSetComment1 = "A=3.0kV, C=-1.5kV, PMT900Vsw";// att. top+bot, trig. top-10", liquid level lowered by 10deg, both Co57 sources together, ADC channels swapped
	//const char *DataSet1	= "150522_1930";	const char *DataSetComment1 = "Co back, 3.0kV/-1.5kV, PMT900V";// att. top+bot, trig. top-10", liquid level lowered by 10deg, both Co57 sources together

	//const char *DataSet1	= "150522_2009";	const char *DataSetComment1 = "Co front, 3.0kV/-1.5kV, PMT900V, MFT0";
	//const char *DataSet1	= "150523_1248";	const char *DataSetComment1 = "Co front, 3.0kV/-3.0kV, PMT900V, MFT0";
	//const char *DataSet1	= "150526_1722";	const char *DataSetComment1 = "Co back, 3.0kV/-3.0kV, PMT900V, MFT0";
	//const char *DataSet1	= "150524_1601";	const char *DataSetComment1 = "Co front, 4.0kV/-3.0kV, PMT900V, MFT0";
	//const char *DataSet1	= "150525_1311";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MFT0";
	//const char *DataSet1	= "150526_2253";	const char *DataSetComment1 = "Co back, 3.5kV/-3.0kV, PMT900V";// att. top+bot, trig. top-10", liquid level lowered by 10deg, both Co57 sources together
	//const char *DataSet1	= "150526_0036";	const char *DataSetComment1 = "Co front, 2.5kV/-3.0kV, PMT900V, MFT0";
	

	//const char *DataSet1	= "150528_1104";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MFT0";// att. top+bot, trig. top-10", liquid level lowered by 10deg, both Co57 sources together
	//const char *DataSet1	= "150528_1444";	const char *DataSetComment1 = "Co back, 3.5kV/-3.0kV, PMT900V, MFT0";// att. top+bot, trig. top-10", liquid level lowered by 10deg, both Co57 sources together

	//const char *DataSet1	= "150529_1125";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+15";// att. top+bot, trig. top-10", liquid level lowered by 10deg, both Co57 sources together
	//const char *DataSet1	= "150529_1410";	const char *DataSetComment1 = "Co back, 3.5kV/-3.0kV, PMT900V, MFT+15";
	//const char *DataSet1	= "150601_2230";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+5";
	//const char *DataSet1	= "150602_0941";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+2.5";
	//const char *DataSet1	= "150602_1350";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF0";
	//const char *DataSet1	= "150602_1624";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF-2.5";
	//const char *DataSet1	= "150602_1931";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF-5";
	//const char *DataSet1	= "150603_1014";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF-10";
	//const char *DataSet1	= "150603_1216";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF-15";
	//const char *DataSet1	= "150603_1413";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF-20";
	//const char *DataSet1	= "150603_1728";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF-25";
	//const char *DataSet1	= "150603_1930";	const char *DataSetComment1 = "Co back, 3.5kV/-3.0kV, PMT900V, MTF-25";

	//const char *DataSet1	= "150604_1344";	const char *DataSetComment1 = "Co back, 3.5kV/-3.0kV, PMT900V, MTF+15";
	//const char *DataSet1	= "150604_1534";	const char *DataSetComment1 = "Co left, 3.5kV/-3.0kV, PMT900V, MTF+15";
	//const char *DataSet1	= "150604_1720";	const char *DataSetComment1 = "Co right, 3.5kV/-3.0kV, PMT900V, MTF+15";
	//const char *DataSet1	= "150604_1836";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+15";

	// Kr-83m
	//const char *DataSet1	= "150527_1416";	const char *DataSetComment1 = "Kr-83m, 3.0kV/-3.0kV, PMT900V, MFT0";
	//const char *DataSet1	= "150528_1905";	const char *DataSetComment1 = "Kr-83m, 4.0kV/-3.0kV, PMT900V, MFT+15";

	// Cs-137
	//const char *DataSet1	= "150605_1230";	const char *DataSetComment1 = "Cs back, 4.0kV/-3.0kV, PMT900V, MTF+15";
	const char *DataSet1	= "150605_1626";	const char *DataSetComment1 = "Cs-137, 4.0kV/-3.0kV, PMT900V, MTF+15";


	// BAD DATA (no S2s)	
	//const char *DataSet1	= "150601_1232";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+20";
	//const char *DataSet1	= "150601_1433";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+17.5";
	//const char *DataSet1	= "150601_1641";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+15";
	//const char *DataSet1	= "150601_1856";	const char *DataSetComment1 = "Co front, 3.5kV/-3.0kV, PMT900V, MTF+10";
	//const char *DataSet1	= "150529_1723";	const char *DataSetComment1 = "Kr-83m, 4.0kV/-3.0kV, PMT900V, MFT+30";


	
	
	Char_t  DataSetName1[500];
	sprintf(DataSetName1, "%s, %s", DataSet1, DataSetComment1);			
	
	//--------------------------------------------------
	Char_t  DataFile1[500];
	//sprintf(DataFile1, "%s/%s/proc/T1_%s_*.root", DataFolder, DataSet1, DataSet1);
	//sprintf(DataFile1, "%s/%s/proc/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	//sprintf(DataFile1, "%s/%s/proc_OldCode/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	//sprintf(DataFile1, "%s/%s/proc_chi0023/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	//sprintf(DataFile1, "%s/%s/proc_chi005/T1_%s_*.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile1, "%s/%s_Chi2025_reduced.root", DataFolder, DataSet1);
	
	cout << "Opening DataFile: "<< DataFile1 << endl;

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);

	////////////////////////////////////////////
	// EXTENSIONS FOR SAVING THE PLOTS
	const char *extensionPlots = ".png";
	const char *extensionPlots_C = ".C";
	////////////////////////////////////////////
	

