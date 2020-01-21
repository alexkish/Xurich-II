#include "XuerichEventData.hh"

XuerichEventData::XuerichEventData()
{
	m_iEventId 			= 0;
	m_iNbStepsScint 	= 0;
	m_iNbStepsTeflon 	= 0;
	m_iNbStepsDeadXe 	= 0;
	m_iNbStepsGXe 		= 0;
	m_iNbStepsRest 		= 0;

	m_iNbTopPmtHits = 0;
	m_iNbBottomPmtHits = 0;
	m_pPmtHits = new vector<int>;

	m_fTotalEnergyDepositedER 		= 0.;
	m_fTotalEnergyDepositedNR 		= 0.;
	m_fTotalEnergyDepositedScintER 	= 0.;
	m_fTotalEnergyDepositedScintNR 	= 0.;
	m_fTotalEnergyDepositedTeflon 	= 0.;
	m_fTotalEnergyDepositedDeadXe 	= 0.;
	m_fTotalEnergyDepositedGXe 		= 0.;
	m_fTotalEnergyDepositedRest 	= 0.;


	m_pTrackId = new vector<int>;
	m_pParentId = new vector<int>;

	m_pParticleType = new vector<string>;
	m_pParticleTypeScint = new vector<string>;

	m_pParentType = new vector<string>;
	m_pCreatorProcess = new vector<string>;
	m_pDepositingProcess = new vector<string>;

	m_pX = new vector<float>;
	m_pY = new vector<float>;
	m_pZ = new vector<float>;

	m_pXscint = new vector<float>;
	m_pYscint = new vector<float>;
	m_pZscint = new vector<float>;

	m_pEnergyDeposited 			= new vector<float>;
	m_pEnergyDepositedScint 	= new vector<float>;
	m_pEnergyDepositedTeflon 	= new vector<float>;
	m_pEnergyDepositedDeadXe 	= new vector<float>;
	m_pEnergyDepositedGXe 		= new vector<float>;
	m_pEnergyDepositedRest 		= new vector<float>;

	m_pKineticEnergy 			= new vector<float>;

	m_pTime 		= new vector<float>;
	m_pTimeScint 	= new vector<float>;
	m_pTimeTeflon 	= new vector<float>;
	m_pTimeDeadXe 	= new vector<float>;
	m_pTimeGXe 		= new vector<float>;
	m_pTimeRest 	= new vector<float>;

	m_pPrimaryParticleType = new vector<string>;
	m_fPrimaryX = 0.;
	m_fPrimaryY = 0.;
	m_fPrimaryZ = 0.;	
}

XuerichEventData::~XuerichEventData()
{
	delete m_pPmtHits;
	delete m_pTrackId;
	delete m_pParentId;
	
	delete m_pParticleType;
	delete m_pParticleTypeScint;

	delete m_pParentType;
	delete m_pCreatorProcess;
	delete m_pDepositingProcess;
	delete m_pKineticEnergy;

	delete m_pX;
	delete m_pY;
	delete m_pZ;

	delete m_pXscint;
	delete m_pYscint;
	delete m_pZscint;

	delete m_pEnergyDeposited;
	delete m_pEnergyDepositedScint;
	delete m_pEnergyDepositedTeflon;
	delete m_pEnergyDepositedDeadXe;
	delete m_pEnergyDepositedGXe;
	delete m_pEnergyDepositedRest;

	delete m_pTime;
	delete m_pTimeScint;
	delete m_pTimeTeflon;
	delete m_pTimeDeadXe;
	delete m_pTimeGXe;
	delete m_pTimeRest;

	delete m_pPrimaryParticleType;
}

void
XuerichEventData::Clear()
{
	m_iEventId = 0;
	m_iNbSteps 			= 0;
	m_iNbStepsScint 	= 0;
	m_iNbStepsTeflon 	= 0;
	m_iNbStepsDeadXe 	= 0;
	m_iNbStepsGXe 		= 0;
	m_iNbStepsRest 		= 0;


	m_iNbTopPmtHits = 0;
	m_iNbBottomPmtHits = 0;

	m_pPmtHits->clear();

	m_fTotalEnergyDepositedER 		= 0.0;
	m_fTotalEnergyDepositedNR 		= 0.0;
	m_fTotalEnergyDepositedScintER 	= 0.0;
	m_fTotalEnergyDepositedScintNR 	= 0.0;
	m_fTotalEnergyDepositedTeflon 	= 0.0;
	m_fTotalEnergyDepositedDeadXe 	= 0.0;
	m_fTotalEnergyDepositedGXe 		= 0.0;
	m_fTotalEnergyDepositedRest 	= 0.0;

	m_pTrackId->clear();
	m_pParentId->clear();

	m_pParticleType->clear();
	m_pParticleTypeScint->clear();

	m_pParentType->clear();
	m_pCreatorProcess->clear();
	m_pDepositingProcess->clear();

	m_pX->clear();
	m_pY->clear();
	m_pZ->clear();

	m_pXscint->clear();
	m_pYscint->clear();
	m_pZscint->clear();

	m_pEnergyDeposited->clear();
	m_pEnergyDepositedScint->clear();
	m_pEnergyDepositedTeflon->clear();
	m_pEnergyDepositedDeadXe->clear();
	m_pEnergyDepositedGXe->clear();
	m_pEnergyDepositedRest->clear();
	m_pKineticEnergy->clear();

	m_pTime->clear();
	m_pTimeScint->clear();
	m_pTimeTeflon->clear();
	m_pTimeDeadXe->clear();
	m_pTimeGXe->clear();
	m_pTimeRest->clear();

	m_pPrimaryParticleType->clear();
	m_fPrimaryX = 0.;
	m_fPrimaryY = 0.;
	m_fPrimaryZ = 0.;	
}

