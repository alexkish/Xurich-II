#ifndef __XENON10PDEADXESENSITIVEDETECTOR_H__
#define __XENON10PDEADXESENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "XuerichDeadXeHit.hh"

class G4Step;
class G4HCofThisEvent;

class XuerichDeadXeSensitiveDetector: public G4VSensitiveDetector
{
public:
	XuerichDeadXeSensitiveDetector(G4String hName);
	~XuerichDeadXeSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	XuerichDeadXeHitsCollection* m_pDeadXeHitsCollection;

	map<int,G4String> m_hParticleTypes;
};

#endif // __XENON10PLXESENSITIVEDETECTOR_H__
