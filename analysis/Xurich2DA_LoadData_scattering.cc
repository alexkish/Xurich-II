	TProof *proof = TProof::Open("workers=4");

	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA
	////////////////////////////////////
	
	const char 	*DataFolder = "/disk/data11/xurich/data";

	const char 	*DataSet1, 	*DataSet2, 	*DataSet3, 	*DataSet4, 	*DataSet5,
				*DataSet6, 	*DataSet7, 	*DataSet8, 	*DataSet9, 	*DataSet10, 
				*DataSet11, *DataSet12, *DataSet13, *DataSet14, *DataSet15;
	const char 	*DataSetComment1;

	char  		DataFile1[500],  DataFile2[500],  DataFile3[500],  DataFile4[500],  DataFile5[500], 
				DataFile6[500],  DataFile7[500],  DataFile8[500],  DataFile9[500],  DataFile10[500], 
				DataFile11[500], DataFile12[500], DataFile13[500], DataFile14[500], DataFile15[500];

	//////////////////////////////////////////////////////////////////////////////////////
	// COINCIDENCE DATA
	////////////////////////////////////	
/*	//----------------------------------
	// calibration
	//DataSet1  = "160921_1658"; // Na-22
	//DataSet1  = "161028_1738"; // Na-22

	//DataSet1  = "160922_1242"; // AmBe
	//DataSet1  = "161028_1226"; // AmBe
	//DataSet2  = "161031_1800"; // AmBe
	//DataSet3  = "161101_1705"; // AmBe

	//DataSet1  = "161108_1315"; // Cs-137
	//DataSet1  = "161108_1442"; // Cs-137

	sprintf(DataFile1, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, DataSet1, DataSet1);

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
	T1->AddFriend(T1mpd4);
*/	//----------------------------------
/*	// NG+Cs
	//DataSet1  = "161102_1624"; // NG+Cs
	//DataSet1  = "161103_1823"; // NG+Cs
	DataSet1  = "161104_1118"; // NG+Cs

	sprintf(DataFile1, "%s/%s/proc/merged/T1_%s-merged.root", DataFolder, DataSet1, DataSet1); // reduced files
	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
	T1->AddFriend(T1mpd4);
*/	//----------------------------------
	// 35.0 deg
	DataSetComment1 = "35.5deg (6.7keV)";

	DataSet1 	= "161203_1333";
	DataSet2 	= "161204_2336";
	DataSet3 	= "161206_1032";
	DataSet4 	= "161206_1756";
	DataSet5 	= "161208_1733";
	DataSet6 	= "161209_1807";
	DataSet7 	= "161211_1434";
	DataSet8 	= "161212_1114";

	const char *file_ext = "ReducedTree-merged.root";

	sprintf(DataFile1, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet1, DataSet1, file_ext);			
	sprintf(DataFile2, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet2, DataSet2, file_ext);			
	sprintf(DataFile3, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet3, DataSet3, file_ext);			
	sprintf(DataFile4, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet4, DataSet4, file_ext);			
	sprintf(DataFile5, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet5, DataSet5, file_ext);			
	sprintf(DataFile6, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet6, DataSet6, file_ext);			
	sprintf(DataFile7, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet7, DataSet7, file_ext);			
	sprintf(DataFile8, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet8, DataSet8, file_ext);			

	//sprintf(DataFile1, "%s/%s/proc/merged/T1_%s_ReducedTree_TestHeight-merged.root", DataFolder, DataSet1, DataSet1);			

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
			T1	->Add(DataFile2);
			T1	->Add(DataFile3);
			T1	->Add(DataFile4);
			T1	->Add(DataFile5);
			T1	->Add(DataFile6);
			T1	->Add(DataFile7);
			T1	->Add(DataFile8);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
			T1mpd4	->Add(DataFile2);
			T1mpd4	->Add(DataFile3);
			T1mpd4	->Add(DataFile4);
			T1mpd4	->Add(DataFile5);
			T1mpd4	->Add(DataFile6);
			T1mpd4	->Add(DataFile7);
			T1mpd4	->Add(DataFile8);
	T1->AddFriend(T1mpd4);			
	//----------------------------------
/*	// 27.5 deg
	DataSetComment1 = "27.5deg (4.2keV)";

	DataSet1 	= "161104_1627";
	DataSet2 	= "161107_1319";
	DataSet3 	= "161109_1450";	// Total Measuring time: 73161 s  = 20.3225 h, Events Measured = 3906549, 	Lifetime: 64218.9
	DataSet4 	= "161110_1110";	// Total Measuring time: 11815 s  = 3.28194 h, Events Measured = 625394, 	Lifetime: 10383.5
	DataSet5 	= "161110_1547";	// Total Measuring time: 85588 s  = 23.7744 h, Events Measured = 4543272, 	Lifetime: 75188.5
	DataSet6 	= "161114_1220";	// Total Measuring time: 98008 s  = 27.2244 h, Events Measured = 4975459, 	Lifetime: 86619.2

	const char *file_ext = "ReducedTree-merged.root";

	sprintf(DataFile1, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet1, DataSet1, file_ext);			
	sprintf(DataFile2, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet2, DataSet2, file_ext);			
	sprintf(DataFile3, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet3, DataSet3, file_ext);			
	sprintf(DataFile4, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet4, DataSet4, file_ext);			
	sprintf(DataFile5, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet5, DataSet5, file_ext);			
	sprintf(DataFile6, "%s/%s/proc/merged/T1_%s_%s", DataFolder, DataSet6, DataSet6, file_ext);			

	//sprintf(DataFile1, "%s/%s/proc/merged/T1_%s_ReducedTree_TestHeight-merged.root", DataFolder, DataSet1, DataSet1);			

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
			T1	->Add(DataFile2);
			T1	->Add(DataFile3);
			T1	->Add(DataFile4);
			T1	->Add(DataFile5);
			T1	->Add(DataFile6);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
			T1mpd4	->Add(DataFile2);
			T1mpd4	->Add(DataFile3);
			T1mpd4	->Add(DataFile4);
			T1mpd4	->Add(DataFile5);
			T1mpd4	->Add(DataFile6);
	T1->AddFriend(T1mpd4);			
*/	//----------------------------------
/*	// 26.5 deg
	DataSetComment1 = "26.5deg (3.9keV)";
	
	DataSet1 	= "160729_1828";
	DataSet2 	= "160829_1519";
	DataSet3 	= "160831_1545";
	DataSet4 	= "160906_1303";
	DataSet5 	= "160914_1409";
	DataSet6 	= "160919_1438";

	sprintf(DataFile1, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, DataSet1, DataSet1);			
	sprintf(DataFile2, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, DataSet2, DataSet2);			
	sprintf(DataFile3, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, DataSet3, DataSet3);			
	sprintf(DataFile4, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, DataSet4, DataSet4);			
	sprintf(DataFile5, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, DataSet5, DataSet5);			
	sprintf(DataFile6, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, DataSet6, DataSet6);			

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
			T1	->Add(DataFile2);
			T1	->Add(DataFile3);
			T1	->Add(DataFile4);
			T1	->Add(DataFile5);
			T1	->Add(DataFile6);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
			T1mpd4	->Add(DataFile2);
			T1mpd4	->Add(DataFile3);
			T1mpd4	->Add(DataFile4);
			T1mpd4	->Add(DataFile5);
			T1mpd4	->Add(DataFile6);
	T1->AddFriend(T1mpd4);
*/	//----------------------------------
/*	// 59.5 deg
	DataSetComment1 = "59.5deg (18.3keV)";

	//DataSet1  	= "160927_1610";	//
	//DataSet2  	= "160928_1302";	//
	//DataSet3  	= "160930_1523";	// Total Measuring time: 104284 s  = 28.9678 h, Events Measured = 4331704, 	Lifetime: 94368.7
	//DataSet4  	= "161003_1646";	// Total Measuring time: 2441 s  = 0.678056 h, 	Events Measured = 135308,	Lifetime: 2131.28
	//DataSet5  	= "161004_1350";	// Total Measuring time: 71553 s  = 19.8758 h, 	Events Measured = 3231016, 	Lifetime: 64157.2
	//DataSet6  	= "161005_0958";	// Total Measuring time: 4675 s  = 1.29861 h, 	Events Measured = 268916, 	Lifetime: 4059.45
	//DataSet7  	= "161005_1222";	// Total Measuring time: 34321 s  = 9.53361 h, 	Events Measured = 1670065,	Lifetime: 30498.2
	//DataSet8  	= "161005_2218";	// Total Measuring time: 143130 s  = 39.7583 h, Events Measured = 6394574, 	Lifetime: 128493
	//DataSet9  	= "161007_1745";	// Total Measuring time: 108648 s  = 30.18 h, 	Events Measured = 5282926, 	Lifetime: 96555.4
	//DataSet10  	= "161009_0029";	// Total Measuring time: 38001 s  = 10.5558 h, 	Events Measured = 2502503, 	Lifetime: 32272.8
	DataSet1  	= "161009_1204";	// Total Measuring time: 173265 s  = 48.1292 h, Events Measured = 10693024, Lifetime: 148789

	//sprintf(DataFile1, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet1, 	DataSet1);
	//sprintf(DataFile2, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet2, 	DataSet2);
	//sprintf(DataFile3, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet3, 	DataSet3);
	//sprintf(DataFile4, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet4, 	DataSet4);
	//sprintf(DataFile5, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet5, 	DataSet5);
	//sprintf(DataFile6, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet6, 	DataSet6);
	//sprintf(DataFile7, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet7, 	DataSet7);
	//sprintf(DataFile8, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet8, 	DataSet8);
	//sprintf(DataFile9, 	"%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet9, 	DataSet9);
	//sprintf(DataFile10, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet10, 	DataSet10);
	//sprintf(DataFile11, "%s/%s/proc/merged/T1_%s_ReducedTree-merged.root", DataFolder, 	DataSet11, 	DataSet11);

	sprintf(DataFile1, 	"%s/%s/proc/merged/T1_%s_ReducedTree_v1-merged.root", DataFolder, 	DataSet1, 	DataSet1);

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
			//T1	->Add(DataFile2);
			//T1	->Add(DataFile3);
			//T1	->Add(DataFile4);
			//T1	->Add(DataFile5);
			//T1	->Add(DataFile6);
			//T1	->Add(DataFile7);
			//T1	->Add(DataFile8);
			//T1	->Add(DataFile9);
			//T1	->Add(DataFile10);
			//T1	->Add(DataFile11);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
			//T1mpd4	->Add(DataFile2);
			//T1mpd4	->Add(DataFile3);
			//T1mpd4	->Add(DataFile4);
			//T1mpd4	->Add(DataFile5);
			//T1mpd4	->Add(DataFile6);
			//T1mpd4	->Add(DataFile7);
			//T1mpd4	->Add(DataFile8);
			//T1mpd4	->Add(DataFile9);
			//T1mpd4	->Add(DataFile10);
			//T1mpd4	->Add(DataFile11);
	T1->AddFriend(T1mpd4);
*/	//----------------------------------
/*	// 50 deg
	DataSetComment1 = "50.0deg (13.3keV)";

	DataSet1 	= "161012_1910";
	DataSet2 	= "161012_2153";
	DataSet3 	= "161014_1425";
	DataSet4 	= "161014_1755";
	DataSet5 	= "161017_1052";
	DataSet6 	= "161018_1735";
	DataSet7 	= "161020_1132";
	DataSet8 	= "161021_1508";
	DataSet9 	= "161023_0547";
	DataSet10 	= "161023_1819";
	DataSet11 	= "161024_1414";
	DataSet12 	= "161024_2108";
	DataSet13 	= "161025_1326";
	DataSet14 	= "161026_1145";

	const char *file_ext = "ReducedTree-merged.root";

	sprintf(DataFile1, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet1, 	DataSet1,	file_ext);
	sprintf(DataFile2, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet2, 	DataSet2,	file_ext);
	sprintf(DataFile3, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet3, 	DataSet3,	file_ext);
	sprintf(DataFile4, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet4, 	DataSet4,	file_ext);
	sprintf(DataFile5, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet5, 	DataSet5,	file_ext);
	sprintf(DataFile6, 	"%s/%s/proc/merged/T1_%s_%s%", DataFolder, 	DataSet6, 	DataSet6,	file_ext);
	sprintf(DataFile7, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet7, 	DataSet7,	file_ext);
	sprintf(DataFile8, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet8, 	DataSet8,	file_ext);
	sprintf(DataFile9, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet9, 	DataSet9,	file_ext);
	sprintf(DataFile10, "%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet10, 	DataSet10,	file_ext);
	sprintf(DataFile11, "%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet11, 	DataSet11,	file_ext);
	sprintf(DataFile12, "%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet12, 	DataSet12,	file_ext);
	sprintf(DataFile13, "%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet13, 	DataSet13,	file_ext);
	sprintf(DataFile14, "%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet14, 	DataSet14,	file_ext);

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
			T1	->Add(DataFile2);
			T1	->Add(DataFile3);
			T1	->Add(DataFile4);
			T1	->Add(DataFile5);
			T1	->Add(DataFile6);
			T1	->Add(DataFile7);
			T1	->Add(DataFile8);
			T1	->Add(DataFile10);
			T1	->Add(DataFile11);
			T1	->Add(DataFile12);
			T1	->Add(DataFile13);
			T1	->Add(DataFile14);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
			T1mpd4	->Add(DataFile2);
			T1mpd4	->Add(DataFile3);
			T1mpd4	->Add(DataFile4);
			T1mpd4	->Add(DataFile5);
			T1mpd4	->Add(DataFile6);
			T1mpd4	->Add(DataFile7);
			T1mpd4	->Add(DataFile8);
			T1mpd4	->Add(DataFile9);
			T1mpd4	->Add(DataFile10);
			T1mpd4	->Add(DataFile11);
			T1mpd4	->Add(DataFile12);
			T1mpd4	->Add(DataFile13);
			T1mpd4	->Add(DataFile14);
	T1->AddFriend(T1mpd4);
*/	//----------------------------------	
/*	// Kr-83m
	DataSetComment1 = "Kr-83m";

	DataSet1 	= "161012_1910";
	DataSet2 	= "161012_2153";
	DataSet3 	= "161014_1425";
	DataSet4 	= "161014_1755";
	DataSet5 	= "161017_1052";
	DataSet6 	= "161018_1735";
	DataSet7 	= "161020_1132";
	//DataSet8 	= "161021_1508";
	DataSet9 	= "161023_0547";
	DataSet10 	= "161023_1819";
	DataSet11 	= "161024_1414";
	DataSet12 	= "161024_2108";
	DataSet13 	= "161025_1326";
	DataSet14 	= "161026_1145";

	const char *file_ext = "ReducedKr83m-merged.root";

	sprintf(DataFile1, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet1, 	DataSet1, 	file_ext);
	sprintf(DataFile2, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet2, 	DataSet2, 	file_ext);
	sprintf(DataFile3, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet3, 	DataSet3, 	file_ext);
	sprintf(DataFile4, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet4, 	DataSet4, 	file_ext);
	sprintf(DataFile5, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet5, 	DataSet5, 	file_ext);
	sprintf(DataFile6, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet6, 	DataSet6, 	file_ext);
	sprintf(DataFile7, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet7, 	DataSet7, 	file_ext);
	//sprintf(DataFile8, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet8, 	DataSet8, 	file_ext);
	sprintf(DataFile9, 		"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet9, 	DataSet9, 	file_ext);
	sprintf(DataFile10, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet10, 	DataSet10, 	file_ext);
	sprintf(DataFile11, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet11, 	DataSet11, 	file_ext);
	sprintf(DataFile12, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet12, 	DataSet12, 	file_ext);
	sprintf(DataFile13, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet13, 	DataSet13, 	file_ext);
	sprintf(DataFile14, 	"%s/%s/proc/merged/T1_%s_%s", DataFolder, 	DataSet14, 	DataSet14, 	file_ext);

	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
			T1	->Add(DataFile2);
			T1	->Add(DataFile3);
			T1	->Add(DataFile4);
			T1	->Add(DataFile5);
			T1	->Add(DataFile6);
			T1	->Add(DataFile7);
			//T1	->Add(DataFile8);
			T1	->Add(DataFile10);
			T1	->Add(DataFile11);
			T1	->Add(DataFile12);
			T1	->Add(DataFile13);
			T1	->Add(DataFile14);
	TChain *T1mpd4	= new TChain("T1mpd4");
			T1mpd4	->Add(DataFile1);
			T1mpd4	->Add(DataFile2);
			T1mpd4	->Add(DataFile3);
			T1mpd4	->Add(DataFile4);
			T1mpd4	->Add(DataFile5);
			T1mpd4	->Add(DataFile6);
			T1mpd4	->Add(DataFile7);
			//T1mpd4	->Add(DataFile8);
			T1mpd4	->Add(DataFile9);
			T1mpd4	->Add(DataFile10);
			T1mpd4	->Add(DataFile11);
			T1mpd4	->Add(DataFile12);
			T1mpd4	->Add(DataFile13);
			T1mpd4	->Add(DataFile14);
	T1->AddFriend(T1mpd4);
*/	//----------------------------------
/*	// Kr-83m
	DataSetComment1 = "Kr-83m, with x10 att.";
	DataSet1 	= "161201_1153";

	const char *file_ext = "merged.root";
	sprintf(DataFile1, 		"%s/%s/proc/merged/T1_%s-%s", DataFolder, 	DataSet1, 	DataSet1, 	file_ext);
	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
*/	//----------------------------------
/*	// Kr-83m
	DataSetComment1 = "Kr-83m, no att.";

	DataSet1 	= "161202_1018";

	const char *file_ext = "merged.root";
	sprintf(DataFile1, 		"%s/%s/proc/merged/T1_%s-%s", DataFolder, 	DataSet1, 	DataSet1, 	file_ext);
	TChain *T1	= new TChain("T1");
			T1	->Add(DataFile1);
*/	//----------------------------------	

	////////////////////////////////////////////////////////////////////////////////////
	cout <<">>> Processing file "<< DataSet1 << endl;
	////////////////////////////////////////////////////////////////////////////////////

	Char_t  DataSetName1[500];
	sprintf(DataSetName1, "%s, %s", DataSet1, DataSetComment1);			

	////////////////////////////////////////////
	// EXTENSIONS FOR SAVING THE PLOTS
	const char *extensionPlots = ".png";
	const char *extensionPlots_C = ".C";
	////////////////////////////////////////////
