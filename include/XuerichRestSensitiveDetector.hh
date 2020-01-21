#ifndef __XENON10PRESTSENSITIVEDETECTOR_H__
#define __XENON10PRESTSENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "XuerichRestHit.hh"

class G4Step;
class G4HCofThisEvent;

class XuerichRestSensitiveDetector: public G4VSensitiveDetector
{
public:
	XuerichRestSensitiveDetector(G4String hName);
	~XuerichRestSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	XuerichRestHitsCollection* m_pRestHitsCollection;

	map<int,G4String> m_hParticleTypes;
};

#endif
