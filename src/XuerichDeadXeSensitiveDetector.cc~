#include <G4HCofThisEvent.hh>
#include <G4Step.hh>
#include <G4VProcess.hh>
#include <G4ThreeVector.hh>
#include <G4SDManager.hh>
#include <G4ios.hh>

#include <map>

using std::map;

#include "XuerichTeflonSensitiveDetector.hh"

XuerichTeflonSensitiveDetector::XuerichTeflonSensitiveDetector(G4String hName): G4VSensitiveDetector(hName)
{
	collectionName.insert("TeflonHitsCollection");
}

XuerichTeflonSensitiveDetector::~XuerichTeflonSensitiveDetector()
{
}

void XuerichTeflonSensitiveDetector::Initialize(G4HCofThisEvent* pHitsCollectionOfThisEvent)
{
	m_pTeflonHitsCollection = new XuerichTeflonHitsCollection(SensitiveDetectorName, collectionName[0]);

	static G4int iHitsCollectionID = -1;

	if(iHitsCollectionID < 0)
		iHitsCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
	
	pHitsCollectionOfThisEvent->AddHitsCollection(iHitsCollectionID, m_pTeflonHitsCollection);

	m_hParticleTypes.clear();
}

G4bool XuerichTeflonSensitiveDetector::ProcessHits(G4Step* pStep, G4TouchableHistory *pHistory)
{
	G4double dEnergyDeposited = pStep->GetTotalEnergyDeposit();
	G4Track *pTrack = pStep->GetTrack();

	XuerichTeflonHit* pHit = new XuerichTeflonHit();

	//pHit->SetTrackId(pTrack->GetTrackID());

	//if(!m_hParticleTypes.count(pTrack->GetTrackID()))
	//	m_hParticleTypes[pTrack->GetTrackID()] = pTrack->GetDefinition()->GetParticleName();

	//pHit->SetParentId(pTrack->GetParentID());
	pHit->SetParticleType(pTrack->GetDefinition()->GetParticleName());

	//if(pTrack->GetParentID())
	//	pHit->SetParentType(m_hParticleTypes[pTrack->GetParentID()]);
	//else
	//	pHit->SetParentType(G4String("none"));

	//if(pTrack->GetCreatorProcess())
	//	pHit->SetCreatorProcess(pTrack->GetCreatorProcess()->GetProcessName());
	//else
	//	pHit->SetCreatorProcess(G4String("Null"));

	//pHit->SetDepositingProcess(pStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName());
	pHit->SetPosition(pStep->GetPostStepPoint()->GetPosition());
	pHit->SetEnergyDeposited(dEnergyDeposited);
	pHit->SetKineticEnergy(pTrack->GetKineticEnergy());
	pHit->SetTime(pTrack->GetGlobalTime());

	m_pTeflonHitsCollection->insert(pHit);

	return true;
}

void XuerichTeflonSensitiveDetector::EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent)
{
//  if (verboseLevel>0) { 
//     G4int NbHits = trackerCollection->entries();
//     G4cout << "\n-------->Hits Collection: in this event they are " << NbHits 
//            << " hits in the tracker chambers: " << G4endl;
//     for (G4int i=0;i<NbHits;i++) (*trackerCollection)[i]->Print();
//    } 
}

