#ifndef __XENON10PTEFLONSENSITIVEDETECTOR_H__
#define __XENON10PTEFLONSENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "XuerichTeflonHit.hh"

class G4Step;
class G4HCofThisEvent;

class XuerichTeflonSensitiveDetector: public G4VSensitiveDetector
{
public:
	XuerichTeflonSensitiveDetector(G4String hName);
	~XuerichTeflonSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	XuerichTeflonHitsCollection* m_pTeflonHitsCollection;

	map<int,G4String> m_hParticleTypes;
};

#endif // __XENON10PLXESENSITIVEDETECTOR_H__
