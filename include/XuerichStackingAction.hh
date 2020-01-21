#ifndef __XENON10PSTACKINGACTION_H__
#define __XENON10PSTACKINGACTION_H__

#include <globals.hh>
#include <G4UserStackingAction.hh>

class XuerichAnalysisManager;

class XuerichStackingAction: public G4UserStackingAction
{
public:
	XuerichStackingAction(XuerichAnalysisManager *pAnalysisManager=0);
	~XuerichStackingAction();
  
	virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack);
	virtual void NewStage();
	virtual void PrepareNewEvent();

private:
	XuerichAnalysisManager *m_pAnalysisManager;
};

#endif // __XENON10PSTACKINGACTION_H__

