#ifndef __XENON10PGXESENSITIVEDETECTOR_H__
#define __XENON10PGXESENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "XuerichGXeHit.hh"

class G4Step;
class G4HCofThisEvent;

class XuerichGXeSensitiveDetector: public G4VSensitiveDetector
{
public:
	XuerichGXeSensitiveDetector(G4String hName);
	~XuerichGXeSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	XuerichGXeHitsCollection* m_pGXeHitsCollection;

	map<int,G4String> m_hParticleTypes;
};

#endif
