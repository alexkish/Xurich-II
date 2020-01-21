#ifndef __XENON10PLXESENSITIVEDETECTOR_H__
#define __XENON10PLXESENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "XuerichLXeHit.hh"

class G4Step;
class G4HCofThisEvent;

class XuerichLXeSensitiveDetector: public G4VSensitiveDetector
{
public:
	XuerichLXeSensitiveDetector(G4String hName);
	~XuerichLXeSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	XuerichLXeHitsCollection* m_pLXeHitsCollection;

	map<int,G4String> m_hParticleTypes;
};

#endif // __XENON10PLXESENSITIVEDETECTOR_H__
