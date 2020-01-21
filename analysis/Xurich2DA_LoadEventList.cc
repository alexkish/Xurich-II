	const char *EventListFolder = "./EventList";
	Char_t  char_EventList[500];
	sprintf(char_EventList,	"%s/%s_%s.root", EventListFolder, DataSet1, CutName);
	
	TFile *EventListFile = new TFile(char_EventList, "READ");

	TEventList *EventList = (TEventList*)EventListFile->Get("EventList");
	T1->SetEventList(EventList);
