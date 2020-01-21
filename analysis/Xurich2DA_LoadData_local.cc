	//////////////////////////////////////////////////////////////////////////////////////
	// LOAD DATA

	// run_01
	//const char *DataFolder = "/Users/alexkish/data/xurich/xurich2/run_01";
	//const char *DataFolder = "/Users/alexkish/Dropbox/data/xurich2/run_01";
	// Co57 (only one PMT)
	//const char *DataSet1	= "131202_1537";

	// run_06
	//const char *DataFolder = "/Volumes/DATA/data/xurich/xurich2/run_06"; // DATA HD
	//const char *DataFolder = "/home/atp/xurich/data"; // FARM
	//const char *DataFolder = "/disk/data1/atp/xurich/data"; // FARM
	//const char *DataFolder = "/home/atp/fpiastra/xurich/data/C2proc";  // FARM, chi2 peak finder for S1

	// run_08
	//const char *DataFolder = "/Users/alexkish/data/xurich/xurich2/run_08";
	const char *DataFolder = "/Users/alexkish/data/xurich_farm";
	
	//const char *DataSet1	= "140428_1236";	// anode 4kV, cathode 2kV, Co57 bottom, trigger on large S2s PMTtop (discr. 60)
	//const char *DataSet1	= "140428_1503";	// anode 4kV, cathode 0kV, Co57 side, trigger on large S2s PMTtop (discr. 60)
	//const char *DataSet1	= "140428_1706";	// zero field, Co57 side, trigger on small S1s PMTtop (discr. 3)
	//const char *DataSet1	= "140428_1844";	// anode 4kV, cathode 2kV, Co57 side, trigger on small S1s PMTbot (discr. 3)
	//const char *DataSet1	= "140428_1914";	// zero field, Cs137 side, trigger on small S1s PMTbot (discr. 3)
	//const char *DataSet1	= "140429_1118";	// zero field, Cs137 side, trigger on small S1s PMTtop (discr. 3)
	//const char *DataSet1	= "140429_1225";	// zero field, Cs137 side, trigger on small S1s PMTbot (discr. 12)
	//const char *DataSet1	= "140429_1414";	// zero field, Co57 side, trigger on small S1s PMTtop (discr. 3)
	//const char *DataSet1	= "140429_1414_chi2";	// zero field, Co57 side, trigger on small S1s PMTbot (discr. 3)
	//const char *DataSet1	= "140429_1435";	// zero field, Co57 side, trigger on small S1s PMTtop (discr. 3)
	//const char *DataSet1	= "140430_0859";	// zero field, Co57 side, trigger on small S1s PMTbot (discr. 3)
	//const char *DataSet1	= "140430_1027";	// 
	//const char *DataSet1	= "140430_1158";	// 
	//const char *DataSet1	= "140430_1338";	// 
	//const char *DataSet1	= "140430_1430";	// 
	//const char *DataSet1	= "140430_1552";	// 
	//const char *DataSet1	= "140430_1733";	// 
	//const char *DataSet1	= "140430_1922";	// 
	//const char *DataSet1	= "140502_1526";	// 
	//const char *DataSet1	= "140502_1618";	// 
	//const char *DataSet1	= "140507_1228";	// 
	//const char *DataSet1	= "140507_1355";	// 
	//const char *DataSet1	= "140507_1505";	// 
	//const char *DataSet1	= "140508_1959";	// 

	// leveling data
	//const char *DataSet1	= "140509_1036";	// left
	//const char *DataSet1	= "140509_1148";	// front
	//const char *DataSet1	= "140509_1256";	// back
	//const char *DataSet1	= "140509_1407";	// right
	//--------------------------------------------------

	// FT down by 8 ticks (pos.18)
	//const char *DataSet1	= "140509_1746";	// 
	//const char *DataSet1	= "140509_1830";	// 
	//const char *DataSet1	= "140509_2252";	// 
	//const char *DataSet1	= "140511_1337";	// 

	// FT up by 8 ticks (pos.10)
	//const char *DataSet1	= "140512_1650";	// 
	//const char *DataSet1	= "140512_1906";	// 
	//const char *DataSet1	= "140512_2116";	// 
	//const char *DataSet1	= "140512_2339";	// 

	// FT pos.10, leveling data 1
	//const char *DataSet1	= "140513_0801";	// front screw
	//const char *DataSet1	= "140513_1005";	// left screw
	//const char *DataSet1	= "140513_1153";	// right screw
	//const char *DataSet1	= "140513_1530";	// front (corrupted)

	// FT pos.10, leveling data 2
	// front of the frame lowered by ~2mm
	//const char *DataSet1	= "140514_1242";	// front screw
	//const char *DataSet1	= "140514_1343";	// left screw
	//const char *DataSet1	= "140514_1616";	// right screw

/*	// Kr-83m calibration
	//const char *DataSet1	= "140521_0957";	// Co-57 front
	const char *DataSet1	= "140521_1117";	// Kr-83m, 1
	const char *DataSet2	= "140521_1312";	// Kr-83m, 2
	const char *DataSet3	= "140521_1519";	// Kr-83m, 3
	const char *DataSet4	= "140521_1714";	// Kr-83m, 4
	const char *DataSet5	= "140521_1952";	// Kr-83m, 5
	const char *DataSet6	= "140521_2145";	// Kr-83m, 6
	const char *DataSet7	= "140521_2340";	// Kr-83m, 7
	const char *DataSet8	= "140522_0133";	// Kr-83m, 8
	const char *DataSet9	= "140522_0321";	// Kr-83m, 9
	const char *DataSet10	= "140522_0510";	// Kr-83m, 10
	const char *DataSet11	= "140522_0703";	// Kr-83m, 11
	const char *DataSet12	= "140522_0855";	// Kr-83m, 12
	const char *DataSet13	= "140522_1045";	// Kr-83m, 13
	const char *DataSet14	= "140522_1243";	// Kr-83m, 14
*/
/*	// Co-57 front
	const char *DataSet1	= "140522_1916";	// 1
	const char *DataSet2	= "140522_2002";	// 2
	const char *DataSet3	= "140522_2048";	// 3
	const char *DataSet4	= "140522_2137";	// 4
	const char *DataSet5	= "140522_2223";	// 5
	const char *DataSet6	= "140522_2311";	// 6
	const char *DataSet7	= "140522_2358";	// 7
	const char *DataSet8	= "140523_0045";	// 8
	const char *DataSet9	= "140523_0133";	// 9
*/
/*	// Co-57 left screw
	const char *DataSet1	= "140523_0934";	// 1
	const char *DataSet2	= "140523_1025";	// 2
	const char *DataSet3	= "140523_1116";	// 3
	const char *DataSet4	= "140523_1206";	// 4
	const char *DataSet5	= "140523_1257";	// 5
	const char *DataSet6	= "140523_1347";	// 6
	const char *DataSet7	= "140523_1439";	// 7
	const char *DataSet8	= "140523_1530";	// 8
	const char *DataSet9	= "140523_1622";	// 9
	const char *DataSet10	= "140523_1713";	// 10
*/
/*	// Co-57 right screw
	const char *DataSet1	= "140523_1854";	// 1
	const char *DataSet2	= "140523_1954";	// 2
	const char *DataSet3	= "140523_2053";	// 3
	const char *DataSet4	= "140523_2151";	// 4
	const char *DataSet5	= "140523_2250";	// 5
	const char *DataSet6	= "140523_2348";	// 6
	const char *DataSet7	= "140524_0045";	// 7
	const char *DataSet8	= "140524_0144";	// 8
	const char *DataSet9	= "140524_0242";	// 9
	const char *DataSet10	= "140524_0340";	// 10
*/
/*	// Kr-83m, all Rb-83 in posession
	const char *DataSet1	= "140528_1347";	// 
	const char *DataSet2	= "140528_1556";	// 
	const char *DataSet3	= "140528_1804";	// 
	const char *DataSet4	= "140528_2010";	// 
	const char *DataSet5	= "140528_2217";	// 
	const char *DataSet6	= "140529_0021";	// 
	const char *DataSet7	= "140529_0224";	// 
	const char *DataSet8	= "140529_0425";	// 
	const char *DataSet9	= "140529_0629";	// 
	const char *DataSet10	= "140529_0837";	// 
	const char *DataSet11	= "140529_1044";	// 
	const char *DataSet12	= "140529_1252";	// 
	const char *DataSet13	= "140529_1455";	// 
	const char *DataSet14	= "140529_1656";	// 
	const char *DataSet15	= "140529_1859";	// 
	const char *DataSet16	= "140529_2110";	// 
	const char *DataSet17	= "140529_2314";	// 
	const char *DataSet18	= "140530_0117";	// 
	const char *DataSet19	= "140530_0323";	// 
	const char *DataSet20	= "140530_0533";	// 
	const char *DataSet21	= "140530_0942";	// 
	const char *DataSet22	= "140530_1154";	// 
	const char *DataSet23	= "140530_1405";	// 
	const char *DataSet24	= "140530_1625";	// 
	const char *DataSet25	= "140530_1405";	// 
	const char *DataSet26	= "140530_1625";	// 
	const char *DataSet27	= "140530_1900";	// 
*/
/*	// Kr-83m, all Rb-83 in posession, Xe in direct contact with the source
	const char *DataSet1	= "140604_1104";	// 
	const char *DataSet2	= "140604_1308";	// 
	const char *DataSet3	= "140604_1510";	// 
	const char *DataSet4	= "140604_1715";	// 
	const char *DataSet5	= "140604_1915";	// 
	const char *DataSet6	= "140604_2118";	// 
	const char *DataSet7	= "140604_2325";	// 
	const char *DataSet8	= "140605_0131";	// 
	const char *DataSet9	= "140605_0335";	// 
	const char *DataSet10	= "140605_0540";	// 
	const char *DataSet11	= "140605_0747";	// 
	const char *DataSet12	= "140605_0952";	// 
	const char *DataSet13	= "140605_1155";	// 
	const char *DataSet14	= "140605_1404";	// 
	const char *DataSet15	= "140605_1608";	// 
	const char *DataSet16	= "140605_1808";	// 
*/

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
	const char *DataSet1	= "141028_1418";	const char *DataSetComment1 = "pos.1 (front), LXe level 2.5mm above the bottom LVM, C-57-236";

	
	Char_t  DataSetName1[500];
	sprintf(DataSetName1, "%s, %s", DataSet1, DataSetComment1);			
	

	//--------------------------------------------------
	Char_t  DataFile1[500];
	sprintf(DataFile1, "%s/%s.root", DataFolder, DataSet1);			
/*	Char_t  DataFile2[500];
	sprintf(DataFile2, "%s/%s.root", DataFolder, DataSet2);			
	Char_t  DataFile3[500];
	sprintf(DataFile3, "%s/%s.root", DataFolder, DataSet3);			
	Char_t  DataFile4[500];
	sprintf(DataFile4, "%s/%s.root", DataFolder, DataSet4);			
	Char_t  DataFile5[500];
	sprintf(DataFile5, "%s/%s.root", DataFolder, DataSet5);			
	Char_t  DataFile6[500];
	sprintf(DataFile6, "%s/%s.root", DataFolder, DataSet6);			
	Char_t  DataFile7[500];
	sprintf(DataFile7, "%s/%s.root", DataFolder, DataSet7);			
	Char_t  DataFile8[500];
	sprintf(DataFile8, "%s/%s.root", DataFolder, DataSet8);			
	Char_t  DataFile9[500];
	sprintf(DataFile9, "%s/%s.root", DataFolder, DataSet9);			
	Char_t  DataFile10[500];
	sprintf(DataFile10, "%s/%s.root", DataFolder, DataSet10);			
	Char_t  DataFile11[500];
	sprintf(DataFile11, "%s/%s.root", DataFolder, DataSet11);			
	Char_t  DataFile12[500];
	sprintf(DataFile12, "%s/%s.root", DataFolder, DataSet12);			
	Char_t  DataFile13[500];
	sprintf(DataFile13, "%s/%s.root", DataFolder, DataSet13);			
	Char_t  DataFile14[500];
	sprintf(DataFile14, "%s/%s.root", DataFolder, DataSet14);			
	Char_t  DataFile15[500];
	sprintf(DataFile15, "%s/%s.root", DataFolder, DataSet15);			
	Char_t  DataFile16[500];
	sprintf(DataFile16, "%s/%s.root", DataFolder, DataSet16);			
	Char_t  DataFile17[500];
	sprintf(DataFile17, "%s/%s.root", DataFolder, DataSet17);			
	Char_t  DataFile18[500];
	sprintf(DataFile18, "%s/%s.root", DataFolder, DataSet18);			
	Char_t  DataFile19[500];
	sprintf(DataFile19, "%s/%s.root", DataFolder, DataSet19);			
	Char_t  DataFile20[500];
	sprintf(DataFile20, "%s/%s.root", DataFolder, DataSet20);			
	Char_t  DataFile21[500];
	sprintf(DataFile21, "%s/%s.root", DataFolder, DataSet21);			
	Char_t  DataFile22[500];
	sprintf(DataFile22, "%s/%s.root", DataFolder, DataSet22);			
	Char_t  DataFile23[500];
	sprintf(DataFile23, "%s/%s.root", DataFolder, DataSet23);			
	Char_t  DataFile24[500];
	sprintf(DataFile24, "%s/%s.root", DataFolder, DataSet24);			
	Char_t  DataFile25[500];
	sprintf(DataFile25, "%s/%s.root", DataFolder, DataSet25);			
	Char_t  DataFile26[500];
	sprintf(DataFile26, "%s/%s.root", DataFolder, DataSet26);			
	Char_t  DataFile27[500];
	sprintf(DataFile27, "%s/%s.root", DataFolder, DataSet27);			
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
			T1	->Add(DataFile11);
			T1	->Add(DataFile12);
			T1	->Add(DataFile13);
			T1	->Add(DataFile14);
			T1	->Add(DataFile15);
			T1	->Add(DataFile16);
			T1	->Add(DataFile17);
			T1	->Add(DataFile18);
			T1	->Add(DataFile19);
			T1	->Add(DataFile20);
			T1	->Add(DataFile21);
			T1	->Add(DataFile22);
			T1	->Add(DataFile23);
			T1	->Add(DataFile24);
			T1	->Add(DataFile25);
			T1	->Add(DataFile26);
			T1	->Add(DataFile27);
*/	




	////////////////////////////////////////////
	// EXTENSIONS FOR SAVING THE PLOTS
	const char *extensionPlots = ".png";
	const char *extensionPlots_C = ".C";
	////////////////////////////////////////////
	

