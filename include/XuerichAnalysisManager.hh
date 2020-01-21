#ifndef __XENON10PANALYSISMANAGER_H__
#define __XENON10PANALYSISMANAGER_H__

#include <globals.hh>

#include <TParameter.h>

class G4Run;
class G4Event;
class G4Step;

class TFile;
class TTree;

class XuerichEventData;
class XuerichPrimaryGeneratorAction;

class XuerichAnalysisManager
{
public:
	XuerichAnalysisManager(XuerichPrimaryGeneratorAction *pPrimaryGeneratorAction);
	virtual ~XuerichAnalysisManager();

public:
	virtual void BeginOfRun(const G4Run *pRun); 
	virtual void EndOfRun(const G4Run *pRun); 
	virtual void BeginOfEvent(const G4Event *pEvent); 
	virtual void EndOfEvent(const G4Event *pEvent); 
	virtual void Step(const G4Step *pStep);	

	void SetDataFilename(const G4String &hFilename) { m_hDataFilename = hFilename; }
	void SetNbEventsToSimulate(G4int iNbEventsToSimulate) { m_iNbEventsToSimulate = iNbEventsToSimulate; }

private:
	G4bool FilterEvent(XuerichEventData *pEventData);

private:
	G4int m_iLXeHitsCollectionID;
	G4int m_iPmtHitsCollectionID;
	G4int m_iScintHitsCollectionID;
	G4int m_iTeflonHitsCollectionID;
	G4int m_iDeadXeHitsCollectionID;
	G4int m_iGXeHitsCollectionID;
	G4int m_iRestHitsCollectionID;

	G4String m_hDataFilename;
	G4int m_iNbEventsToSimulate;

	TFile *m_pTreeFile;
	TTree *m_pTree;
	TParameter<int> *m_pNbEventsToSimulateParameter;

	XuerichPrimaryGeneratorAction *m_pPrimaryGeneratorAction;

	XuerichEventData *m_pEventData;
};

#endif // __XENON10PANALYSISMANAGER_H__

