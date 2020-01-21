#ifndef __XENON10PRUNACTION_H__
#define __XENON10PRUNACTION_H__

#include <G4UserRunAction.hh>

class G4Run;

class XuerichAnalysisManager;

class XuerichRunAction: public G4UserRunAction
{
public:
	XuerichRunAction(XuerichAnalysisManager *pAnalysisManager=0);
	~XuerichRunAction();

public:
	void BeginOfRunAction(const G4Run *pRun);
	void EndOfRunAction(const G4Run *pRun);

private:
	XuerichAnalysisManager *m_pAnalysisManager;
};

#endif // __XENON10PRUNACTION_H__

