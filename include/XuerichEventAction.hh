#ifndef __XENON10PEVENTACTION_H__
#define __XENON10PEVENTACTION_H__

#include <G4UserEventAction.hh>

#include "XuerichAnalysisManager.hh"

class G4Event;

class XuerichEventAction : public G4UserEventAction
{
public:
	XuerichEventAction(XuerichAnalysisManager *pAnalysisManager = 0);
	~XuerichEventAction();

public:
	void BeginOfEventAction(const G4Event *pEvent);
	void EndOfEventAction(const G4Event *pEvent);

private:
	XuerichAnalysisManager *m_pAnalysisManager;
};

#endif // __XENON10PEVENTACTION_H__

