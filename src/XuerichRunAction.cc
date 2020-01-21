#include <Randomize.hh>

#include <sys/time.h>

#include "XuerichAnalysisManager.hh"

#include "XuerichRunAction.hh"

XuerichRunAction::XuerichRunAction(XuerichAnalysisManager *pAnalysisManager)
{
	m_pAnalysisManager = pAnalysisManager;
}

XuerichRunAction::~XuerichRunAction()
{

}

void
XuerichRunAction::BeginOfRunAction(const G4Run *pRun)
{
	if(m_pAnalysisManager)
		m_pAnalysisManager->BeginOfRun(pRun);

	struct timeval hTimeValue;
	gettimeofday(&hTimeValue, NULL);

	CLHEP::HepRandom::setTheEngine(new CLHEP::DRand48Engine);
	CLHEP::HepRandom::setTheSeed(hTimeValue.tv_usec);
}

void
XuerichRunAction::EndOfRunAction(const G4Run *pRun)
{
	if(m_pAnalysisManager)
		m_pAnalysisManager->EndOfRun(pRun);
}

