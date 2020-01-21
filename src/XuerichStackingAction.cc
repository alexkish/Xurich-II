#include <G4ios.hh>
#include <G4ParticleDefinition.hh>
#include <G4ParticleTypes.hh>
#include <G4Track.hh>
#include <G4Event.hh>
#include <G4VProcess.hh>
#include <G4StackManager.hh>

#include "XuerichAnalysisManager.hh"

#include "XuerichStackingAction.hh"

XuerichStackingAction::XuerichStackingAction(XuerichAnalysisManager *pAnalysisManager)
{
	m_pAnalysisManager = pAnalysisManager;
}

XuerichStackingAction::~XuerichStackingAction()
{
}

G4ClassificationOfNewTrack
XuerichStackingAction::ClassifyNewTrack(const G4Track *pTrack)
{
	G4ClassificationOfNewTrack hTrackClassification = fUrgent;

	if(pTrack->GetDefinition()->GetParticleType() == "nucleus" && !pTrack->GetDefinition()->GetPDGStable())
	{
		if(pTrack->GetParentID() > 0 && pTrack->GetCreatorProcess()->GetProcessName() == "RadioactiveDecay")
			hTrackClassification = fPostpone;
	}

	return hTrackClassification;
}

void
XuerichStackingAction::NewStage()
{
}

void
XuerichStackingAction::PrepareNewEvent()
{ 
}








