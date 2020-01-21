#ifndef __XENON10PPMTSENSITIVEDETECTOR_H__
#define __XENON10PPMTSENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "XuerichPmtHit.hh"

class G4Step;
class G4HCofThisEvent;

class XuerichPmtSensitiveDetector: public G4VSensitiveDetector
{
public:
	XuerichPmtSensitiveDetector(G4String hName);
	~XuerichPmtSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	XuerichPmtHitsCollection* m_pPmtHitsCollection;
};

#endif // __XENON10PPMTSENSITIVEDETECTOR_H__

