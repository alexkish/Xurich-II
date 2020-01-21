	//////////////////////////////////////////////////////////////////////////////////////
	// SET ALIAS

	// correct configuration
	T1->SetAlias("baseline_top",	"baselnPMT1");
	T1->SetAlias("baseline_bot",	"baselnPMT2");
	T1->SetAlias("S1peaks_top",		"nS1rawPMT1");
	T1->SetAlias("S1peaks_bot",		"nS1rawPMT2");
	T1->SetAlias("S1height_top",	"S1maxRawPMT1[0]");			// [mV]
	T1->SetAlias("S1height_bot",	"S1maxRawPMT2[0]");			// [mV]
	T1->SetAlias("S1width_top",		"S1fwhmPMT1[0]");		// [us]
	T1->SetAlias("S1width_bot",		"S1fwhmPMT2[0]");		// [us]
	T1->SetAlias("S1widthLow_top",	"S1fwtmPMT1[0]");		// [us]
	T1->SetAlias("S1widthLow_bot",	"S1fwtmPMT2[0]");		// [us]
	T1->SetAlias("S1top",			"S1sRawPMT1[0]");
	T1->SetAlias("S1bot",			"S1sRawPMT2[0]");
	//T1->SetAlias("S1chi2top",		"S1sRawChi2PMT1[0]");
	//T1->SetAlias("S1chi2bot",		"S1sRawChi2PMT2[0]");
	T1->SetAlias("S1total",			"S1top+S1bot");
	T1->SetAlias("S1topPE",			"S1sPePMT1[0]");
	T1->SetAlias("S1botPE",			"S1sPePMT2[0]");
	T1->SetAlias("S1totalPE",		"S1topPE+S1botPE");	
	T1->SetAlias("S1topPE1",		"S1sPePMT1[1]");
	T1->SetAlias("S1botPE1",		"S1sPePMT2[1]");
	T1->SetAlias("S1totalPE1",		"S1topPE1+S1botPE1");	
	T1->SetAlias("S2peaks_top",		"nS2rawPMT1");
	T1->SetAlias("S2peaks_bot",		"nS2rawPMT2");
	T1->SetAlias("S2height_top",	"S2maxRawPMT1[0]");			// [ADC ch]
	T1->SetAlias("S2height_bot",	"S2maxRawPMT2[0]");			// [ADC ch]

	// TIMING using position of the maxima
/*	T1->SetAlias("S1time_top",		"S1maxposRawPMT1[0]/100.");	// [us]
	T1->SetAlias("S1time_bot",		"S1maxposRawPMT2[0]/100.");	// [us]
	T1->SetAlias("S1time1_top",		"S1maxposRawPMT1[1]/100.");	// [us]
	T1->SetAlias("S1time1_bot",		"S1maxposRawPMT2[1]/100.");	// [us]
	T1->SetAlias("S2time_top",		"S2maxposRawPMT1[0]/100.");	// [us]
	T1->SetAlias("S2time_bot",		"S2maxposRawPMT2[0]/100.");	// [us]
	T1->SetAlias("S2time1_top",		"S2maxposRawPMT1[1]/100.");	// [us]
	T1->SetAlias("S2time1_bot",		"S2maxposRawPMT2[1]/100.");	// [us]
	T1->SetAlias("S1delay_top",		"(S1maxposRawPMT1[1]-S1maxposRawPMT1[0])/100.");	// [us]
	T1->SetAlias("S1delay_bot",		"(S1maxposRawPMT2[1]-S1maxposRawPMT2[0])/100.");	// [us]
	T1->SetAlias("S2delay_top",		"(S2maxposRawPMT1[1]-S2maxposRawPMT1[0])/100.");	// [us]
	T1->SetAlias("S2delay_bot",		"(S2maxposRawPMT2[1]-S2maxposRawPMT2[0])/100.");	// [us]
	T1->SetAlias("dt_top",			"(S2maxposRawPMT1[0]-S1maxposRawPMT1[0])/100.");	// [us]
	T1->SetAlias("dt_bot",			"(S2maxposRawPMT2[0]-S1maxposRawPMT2[0])/100.");	// [us]
	T1->SetAlias("dt1_top",			"(S2maxposRawPMT1[0]-S1maxposRawPMT1[1])/100.");	// [us]
	T1->SetAlias("dt1_bot",			"(S2maxposRawPMT2[0]-S1maxposRawPMT2[1])/100.");	// [us]
*/
/*	// TIMING using momenta of the peaks
	T1->SetAlias("S1time_top",		"S1sM1PMT1[0]/100.");	// [us]
	T1->SetAlias("S1time_bot",		"S1sM1PMT2[0]/100.");	// [us]
	T1->SetAlias("S1time1_top",		"S1sM1PMT1[1]/100.");	// [us]
	T1->SetAlias("S1time1_bot",		"S1sM1PMT2[1]/100.");	// [us]
	T1->SetAlias("S2time_top",		"S2sM1PMT1[0]/100.");	// [us]
	T1->SetAlias("S2time_bot",		"S2sM1PMT2[0]/100.");	// [us]
	T1->SetAlias("S2time1_top",		"S2sM1PMT1[1]/100.");	// [us]
	T1->SetAlias("S2time1_bot",		"S2sM1PMT2[1]/100.");	// [us]
	T1->SetAlias("S1delay_top",		"(S1sM1PMT1[1]-S1sM1PMT1[0])/100.");	// [us]
	T1->SetAlias("S1delay_bot",		"(S1sM1PMT2[1]-S1sM1PMT2[0])/100.");	// [us]
	T1->SetAlias("S2delay_top",		"(S2sM1PMT1[1]-S2sM1PMT1[0])/100.");	// [us]
	T1->SetAlias("S2delay_bot",		"(S2sM1PMT2[1]-S2sM1PMT2[0])/100.");	// [us]
	T1->SetAlias("dt_top",			"(S2sM1PMT1[0]-S1sM1PMT1[0])/100.");	// [us]
	T1->SetAlias("dt_bot",			"(S2sM1PMT2[0]-S1sM1PMT2[0])/100.");	// [us]
	T1->SetAlias("dt1_top",			"(S2sM1PMT1[0]-S1sM1PMT1[1])/100.");	// [us]
	T1->SetAlias("dt1_bot",			"(S2sM1PMT2[0]-S1sM1PMT2[1])/100.");	// [us]
*/
	// TIMING COMBINED using maxpos for S1, momenta for S2
	T1->SetAlias("S1time_top",		"S1maxposRawPMT1[0]/100.");	// [us]
	T1->SetAlias("S1time_bot",		"S1maxposRawPMT2[0]/100.");	// [us]
	T1->SetAlias("S1time1_top",		"S1maxposRawPMT1[1]/100.");	// [us]
	T1->SetAlias("S1time1_bot",		"S1maxposRawPMT2[1]/100.");	// [us]
	T1->SetAlias("S2time_top",		"S2sM1PMT1[0]/100.");	// [us]
	T1->SetAlias("S2time_bot",		"S2sM1PMT2[0]/100.");	// [us]
	T1->SetAlias("S2time1_top",		"S2sM1PMT1[1]/100.");	// [us]
	T1->SetAlias("S2time1_bot",		"S2sM1PMT2[1]/100.");	// [us]
	T1->SetAlias("S1delay_top",		"(S1maxposRawPMT1[1]-S1maxposRawPMT1[0])/100.");	// [us]
	T1->SetAlias("S1delay_bot",		"(S1maxposRawPMT2[1]-S1maxposRawPMT2[0])/100.");	// [us]
	T1->SetAlias("S2delay_top",		"(S2sM1PMT1[1]-S2sM1PMT1[0])/100.");	// [us]
	T1->SetAlias("S2delay_bot",		"(S2sM1PMT2[1]-S2sM1PMT2[0])/100.");	// [us]
	T1->SetAlias("dt_top",			"(S2sM1PMT1[0]-S1maxposRawPMT1[0])/100.");	// [us]
	T1->SetAlias("dt_bot",			"(S2sM1PMT2[0]-S1maxposRawPMT2[0])/100.");	// [us]
	T1->SetAlias("dt1_top",			"(S2sM1PMT1[1]-S1maxposRawPMT1[1])/100.");	// [us]
	T1->SetAlias("dt1_bot",			"(S2sM1PMT2[1]-S1maxposRawPMT2[1])/100.");	// [us]

	T1->SetAlias("S2width_top",		"S2fwhmPMT1[0]/100.");	// [us]
	T1->SetAlias("S2width_bot",		"S2fwhmPMT2[0]/100.");	// [us]
	T1->SetAlias("S2widthLow_top",	"S2fwtmPMT1[0]/100.");	// [us]
	T1->SetAlias("S2widthLow_bot",	"S2fwtmPMT2[0]/100.");	// [us]
	T1->SetAlias("S2M2top",			"S2sM2PMT1[0]/100.");	// [us]
	T1->SetAlias("S2M2bot",			"S2sM2PMT2[0]/100.");	// [us]

	T1->SetAlias("S21width_top",	"S2fwhmPMT1[1]/100.");	// [us]
	T1->SetAlias("S21width_bot",	"S2fwhmPMT2[1]/100.");	// [us]
	T1->SetAlias("S21widthLow_top",	"S2fwtmPMT1[1]/100.");	// [us]
	T1->SetAlias("S21widthLow_bot",	"S2fwtmPMT2[1]/100.");	// [us]
	T1->SetAlias("S21M2top",		"S2sM2PMT1[1]/100.");	// [us]
	T1->SetAlias("S21M2bot",		"S2sM2PMT2[1]/100.");	// [us]

	T1->SetAlias("S2top",			"S2sRawPMT1[0]");
	T1->SetAlias("S2bot",			"S2sRawPMT2[0]");
	T1->SetAlias("S2total",			"S2top+S2bot");
	T1->SetAlias("S2topPE",			"S2sPePMT1[0]");
	T1->SetAlias("S2botPE",			"S2sPePMT2[0]");
	T1->SetAlias("S2totalPE",		"S2topPE+S2botPE");
	T1->SetAlias("S2topPE1",		"S2sPePMT1[1]");
	T1->SetAlias("S2botPE1",		"S2sPePMT2[1]");
	T1->SetAlias("S2totalPE1",		"S2topPE1+S2botPE1");
	T1->SetAlias("S1asym",			"(S1topPE-S1botPE)/(S1topPE+S1botPE)");
	T1->SetAlias("S1asym1",			"(S1topPE1-S1botPE1)/(S1topPE1+S1botPE1)");
	T1->SetAlias("S2asym",			"(S2topPE-S2botPE)/(S2topPE+S2botPE)");
	//T1->SetAlias("cS1totalPE",		"S1totalPE/(0.7983+dt_top*0.00501+dt_top*dt_top*0.003377-dt_top*dt_top*dt_top*0.0001316)");	
	T1->SetAlias("cS1totalPE",		"S1totalPE/(0.772372 + dt_top*0.0138107 + dt_top*dt_top*4.2336e-05)");	
	T1->SetAlias("cS1totalPE1",		"S1totalPE1/(0.7983+dt1_top*0.00501+dt1_top*dt1_top*0.003377-dt1_top*dt1_top*dt1_top*0.0001316)");	

	// MPD4 tree
	T1->SetAlias("TOF",				"MaxAMP1[0]");
	T1->SetAlias("PSD",				"MaxTAC0[0]");
	T1->SetAlias("AMP",				"MaxAMP0[0]");
	
	//TAC0: should be the TAC output of the mpd4 channel 0


