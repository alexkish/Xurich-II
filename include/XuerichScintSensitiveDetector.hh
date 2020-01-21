#ifndef __XENON10PSCINTSENSITIVEDETECTOR_H__
#define __XENON10PSCINTSENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "XuerichScintHit.hh"

class G4Step;
class G4HCofThisEvent;

class XuerichScintSensitiveDetector: public G4VSensitiveDetector
{
public:
	XuerichScintSensitiveDetector(G4String hName);
	~XuerichScintSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	XuerichScintHitsCollection* m_pScintHitsCollection;

	map<int,G4String> m_hParticleTypes;
};

#endif // __XENON10PLXESENSITIVEDETECTOR_H__
