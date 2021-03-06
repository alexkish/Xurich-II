#ifndef __XENON10PEVENTDATA_H__
#define __XENON10PEVENTDATA_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

class XuerichEventData
{
public:
	 XuerichEventData();
	~XuerichEventData();

public:
	void Clear();

public:
	int m_iEventId;								// the event ID

	int m_iNbSteps;								// number of energy depositing steps
	int m_iNbStepsScint;						
	int m_iNbStepsTeflon;						
	int m_iNbStepsDeadXe;						
	int m_iNbStepsGXe;							
	int m_iNbStepsRest;							

	int m_iNbTopPmtHits;						// number of top pmt hits
	int m_iNbBottomPmtHits;						// number of bottom pmt hits
	vector<int> *m_pPmtHits;					// number of photon hits per pmt

	vector<int> *m_pTrackId;					// id of the particle
	vector<int> *m_pParentId;					// id of the parent particle

	vector<string> *m_pParticleType;			// type of particle
	vector<string> *m_pParticleTypeScint;		// type of particle

	vector<string> *m_pParentType;				// type of particle
	vector<string> *m_pCreatorProcess;			// interaction
	vector<string> *m_pDepositingProcess;		// energy depositing process

	vector<float> *m_pX;						// position of the step in Xe target
	vector<float> *m_pY;
	vector<float> *m_pZ;

	vector<float> *m_pXscint;					// position of the step in scintillator
	vector<float> *m_pYscint;
	vector<float> *m_pZscint;

	vector<float> *m_pKineticEnergy;			// particle kinetic energy after the step			

	vector<float> *m_pEnergyDeposited; 			// energy deposited in the step
	vector<float> *m_pEnergyDepositedScint;
	vector<float> *m_pEnergyDepositedTeflon;
	vector<float> *m_pEnergyDepositedDeadXe;
	vector<float> *m_pEnergyDepositedGXe;
	vector<float> *m_pEnergyDepositedRest;

	float m_fTotalEnergyDepositedER;				// total energy deposited in the ScintSD
	float m_fTotalEnergyDepositedNR;
	float m_fTotalEnergyDepositedScintER;
	float m_fTotalEnergyDepositedScintNR;
	float m_fTotalEnergyDepositedTeflon;
	float m_fTotalEnergyDepositedDeadXe;
	float m_fTotalEnergyDepositedGXe;
	float m_fTotalEnergyDepositedRest;

	vector<float> *m_pTime;						// time of the step
	vector<float> *m_pTimeScint;				
	vector<float> *m_pTimeTeflon;				
	vector<float> *m_pTimeDeadXe;
	vector<float> *m_pTimeGXe;			
	vector<float> *m_pTimeRest;			

	vector<string> *m_pPrimaryParticleType;		// type of particle
	float m_fPrimaryX;							// position of the primary particle
	float m_fPrimaryY;
	float m_fPrimaryZ;	
};

#endif // __XENON10PEVENTDATA_H__

