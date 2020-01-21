#include <G4SDManager.hh>
#include <G4Run.hh>
#include <G4Event.hh>
#include <G4HCofThisEvent.hh>
#include <G4Step.hh>

#include <numeric>

#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TParameter.h>

#include "XuerichDetectorConstruction.hh"
#include "XuerichPrimaryGeneratorAction.hh"
#include "XuerichEventData.hh"

#include "XuerichLXeHit.hh"
#include "XuerichPmtHit.hh"
#include "XuerichScintHit.hh"
#include "XuerichTeflonHit.hh"
#include "XuerichDeadXeHit.hh"
#include "XuerichGXeHit.hh"
#include "XuerichRestHit.hh"


#include "XuerichAnalysisManager.hh"

XuerichAnalysisManager::XuerichAnalysisManager(XuerichPrimaryGeneratorAction *pPrimaryGeneratorAction)
{
	m_iLXeHitsCollectionID 		= -1;
	m_iPmtHitsCollectionID 		= -1;
	m_iScintHitsCollectionID 	= -1;
	m_iTeflonHitsCollectionID 	= -1;
	m_iDeadXeHitsCollectionID 	= -1;
	m_iGXeHitsCollectionID 		= -1;
	m_iRestHitsCollectionID 	= -1;

	m_hDataFilename = "events.root";

	m_pPrimaryGeneratorAction = pPrimaryGeneratorAction;

	m_pEventData = new XuerichEventData();
}

XuerichAnalysisManager::~XuerichAnalysisManager()
{
}

void
XuerichAnalysisManager::BeginOfRun(const G4Run *pRun)
{
	m_pTreeFile = new TFile(m_hDataFilename.c_str(), "RECREATE", "File containing event data for Xuerich");
	m_pTree = new TTree("t1", "Tree containing event data for Xuerich");

	gROOT->ProcessLine("#include <vector>");

	m_pTree->Branch("eventid", &m_pEventData->m_iEventId, "eventid/I");
	m_pTree->Branch("ntpmthits", &m_pEventData->m_iNbTopPmtHits, "ntpmthits/I");
	m_pTree->Branch("nbpmthits", &m_pEventData->m_iNbBottomPmtHits, "nbpmthits/I");
	m_pTree->Branch("pmthits", "vector<int>", &m_pEventData->m_pPmtHits);
	m_pTree->Branch("nsteps", &m_pEventData->m_iNbSteps, "nsteps/I");

	m_pTree->Branch("etotER", &m_pEventData->m_fTotalEnergyDepositedER, "etotER/F");
	m_pTree->Branch("etotNR", &m_pEventData->m_fTotalEnergyDepositedNR, "etotNR/F");
	
	m_pTree->Branch("trackid", "vector<int>", &m_pEventData->m_pTrackId);
	m_pTree->Branch("type", "vector<string>", &m_pEventData->m_pParticleType);
	m_pTree->Branch("parentid", "vector<int>", &m_pEventData->m_pParentId);
	m_pTree->Branch("parenttype", "vector<string>", &m_pEventData->m_pParentType);
	m_pTree->Branch("creaproc", "vector<string>", &m_pEventData->m_pCreatorProcess);
	m_pTree->Branch("edproc", "vector<string>", &m_pEventData->m_pDepositingProcess);
	m_pTree->Branch("xp", "vector<float>", &m_pEventData->m_pX);
	m_pTree->Branch("yp", "vector<float>", &m_pEventData->m_pY);
	m_pTree->Branch("zp", "vector<float>", &m_pEventData->m_pZ);
	m_pTree->Branch("ed", "vector<float>", &m_pEventData->m_pEnergyDeposited);
	m_pTree->Branch("time", "vector<float>", &m_pEventData->m_pTime);

	m_pTree->Branch("type_pri", "vector<string>", &m_pEventData->m_pPrimaryParticleType);
	m_pTree->Branch("xp_pri", &m_pEventData->m_fPrimaryX, "xp_pri/F");
	m_pTree->Branch("yp_pri", &m_pEventData->m_fPrimaryY, "yp_pri/F");
	m_pTree->Branch("zp_pri", &m_pEventData->m_fPrimaryZ, "zp_pri/F");

	m_pTree->Branch("EJ_nsteps", &m_pEventData->m_iNbStepsScint, "EJ_nsteps/I");
	m_pTree->Branch("EJ_ed", 	"vector<float>", &m_pEventData->m_pEnergyDepositedScint);
	m_pTree->Branch("EJ_etotER", 	&m_pEventData->m_fTotalEnergyDepositedScintER, "EJ_etotER/F");
	m_pTree->Branch("EJ_etotNR", 	&m_pEventData->m_fTotalEnergyDepositedScintNR, "EJ_etotNR/F");
	m_pTree->Branch("EJ_time", 	"vector<float>", &m_pEventData->m_pTimeScint);
	m_pTree->Branch("EJ_xp", 	"vector<float>", &m_pEventData->m_pXscint);
	m_pTree->Branch("EJ_yp", 	"vector<float>", &m_pEventData->m_pYscint);
	m_pTree->Branch("EJ_zp", 	"vector<float>", &m_pEventData->m_pZscint);

	m_pTree->Branch("Teflon_nsteps", &m_pEventData->m_iNbStepsTeflon, "Teflon_nsteps/I");
	m_pTree->Branch("Teflon_ed", "vector<float>", &m_pEventData->m_pEnergyDepositedTeflon);
	m_pTree->Branch("Teflon_etot", &m_pEventData->m_fTotalEnergyDepositedTeflon, "Teflon_etot/F");
	m_pTree->Branch("Teflon_time", "vector<float>", &m_pEventData->m_pTimeTeflon);

	m_pTree->Branch("DeadXe_nsteps", &m_pEventData->m_iNbStepsDeadXe, "DeadXe_nsteps/I");
	m_pTree->Branch("DeadXe_ed", "vector<float>", &m_pEventData->m_pEnergyDepositedDeadXe);
	m_pTree->Branch("DeadXe_etot", &m_pEventData->m_fTotalEnergyDepositedDeadXe, "EJ_etot/F");
	m_pTree->Branch("DeadXe_time", "vector<float>", &m_pEventData->m_pTimeDeadXe);

	m_pTree->Branch("GXe_nsteps", &m_pEventData->m_iNbStepsGXe, "GXe_nsteps/I");
	m_pTree->Branch("GXe_ed", "vector<float>", &m_pEventData->m_pEnergyDepositedGXe);
	m_pTree->Branch("GXe_etot", &m_pEventData->m_fTotalEnergyDepositedGXe, "EJ_etot/F");
	m_pTree->Branch("GXe_time", "vector<float>", &m_pEventData->m_pTimeGXe);

	m_pTree->Branch("Rest_nsteps", &m_pEventData->m_iNbStepsRest, "Rest_nsteps/I");
	m_pTree->Branch("Rest_ed", "vector<float>", &m_pEventData->m_pEnergyDepositedRest);
	m_pTree->Branch("Rest_etot", &m_pEventData->m_fTotalEnergyDepositedRest, "EJ_etot/F");
	m_pTree->Branch("Rest_time", "vector<float>", &m_pEventData->m_pTimeRest);

	m_pTree->SetMaxTreeSize(10e9);
	m_pTree->AutoSave();

	m_pNbEventsToSimulateParameter = new TParameter<int>("nbevents", m_iNbEventsToSimulate);
	m_pNbEventsToSimulateParameter->Write();
}

void
XuerichAnalysisManager::EndOfRun(const G4Run *pRun)
{
	m_pTreeFile->Write();
	m_pTreeFile->Close();
}

void
XuerichAnalysisManager::BeginOfEvent(const G4Event *pEvent)
{
	if(m_iLXeHitsCollectionID == -1)
	{
		G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
		m_iLXeHitsCollectionID = pSDManager->GetCollectionID("LXeHitsCollection");
	} 

	if(m_iPmtHitsCollectionID == -1)
	{
		G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
		m_iPmtHitsCollectionID = pSDManager->GetCollectionID("PmtHitsCollection");
	}

	if(m_iScintHitsCollectionID == -1)
	{
		G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
		m_iScintHitsCollectionID = pSDManager->GetCollectionID("ScintHitsCollection");
	} 

	if(m_iTeflonHitsCollectionID == -1)
	{
		G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
		m_iTeflonHitsCollectionID = pSDManager->GetCollectionID("TeflonHitsCollection");
	} 

	if(m_iDeadXeHitsCollectionID == -1)
	{
		G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
		m_iDeadXeHitsCollectionID = pSDManager->GetCollectionID("DeadXeHitsCollection");
	} 

	if(m_iGXeHitsCollectionID == -1)
	{
		G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
		m_iGXeHitsCollectionID = pSDManager->GetCollectionID("GXeHitsCollection");
	} 

	if(m_iRestHitsCollectionID == -1)
	{
		G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
		m_iRestHitsCollectionID = pSDManager->GetCollectionID("RestHitsCollection");
	} 

}

void
XuerichAnalysisManager::EndOfEvent(const G4Event *pEvent)
{
	G4HCofThisEvent* pHCofThisEvent = pEvent->GetHCofThisEvent();
	XuerichLXeHitsCollection	* pLXeHitsCollection 	= 0;
	XuerichPmtHitsCollection	* pPmtHitsCollection 	= 0;
	XuerichScintHitsCollection	* pScintHitsCollection 	= 0;
	XuerichTeflonHitsCollection	* pTeflonHitsCollection = 0;
	XuerichDeadXeHitsCollection	* pDeadXeHitsCollection = 0;
	XuerichGXeHitsCollection	* pGXeHitsCollection 	= 0;
	XuerichRestHitsCollection	* pRestHitsCollection 	= 0;

	G4int iNbLXeHits 	= 0.;
	G4int iNbPmtHits 	= 0.;
	G4int iNbScintHits 	= 0.;
	G4int iNbTeflonHits = 0.;
	G4int iNbDeadXeHits = 0.;
	G4int iNbGXeHits 	= 0.;
	G4int iNbRestHits 	= 0.;
	
	if(pHCofThisEvent)
	{
		if(m_iLXeHitsCollectionID != -1)
		{
			pLXeHitsCollection = (XuerichLXeHitsCollection *)(pHCofThisEvent->GetHC(m_iLXeHitsCollectionID));
			iNbLXeHits = (pLXeHitsCollection)?(pLXeHitsCollection->entries()):(0);
		}

		if(m_iPmtHitsCollectionID != -1)
		{
			pPmtHitsCollection = (XuerichPmtHitsCollection *)(pHCofThisEvent->GetHC(m_iPmtHitsCollectionID));
			iNbPmtHits = (pPmtHitsCollection)?(pPmtHitsCollection->entries()):(0);
		}

		if(m_iScintHitsCollectionID != -1)
		{
			pScintHitsCollection = (XuerichScintHitsCollection *)(pHCofThisEvent->GetHC(m_iScintHitsCollectionID));
			iNbScintHits = (pScintHitsCollection)?(pScintHitsCollection->entries()):(0);
		}

		if(m_iTeflonHitsCollectionID != -1)
		{
			pTeflonHitsCollection = (XuerichTeflonHitsCollection *)(pHCofThisEvent->GetHC(m_iTeflonHitsCollectionID));
			iNbTeflonHits = (pTeflonHitsCollection)?(pTeflonHitsCollection->entries()):(0);
		}

		if(m_iDeadXeHitsCollectionID != -1)
		{
			pDeadXeHitsCollection = (XuerichDeadXeHitsCollection *)(pHCofThisEvent->GetHC(m_iDeadXeHitsCollectionID));
			iNbDeadXeHits = (pDeadXeHitsCollection)?(pDeadXeHitsCollection->entries()):(0);
		}

		if(m_iGXeHitsCollectionID != -1)
		{
			pGXeHitsCollection = (XuerichGXeHitsCollection *)(pHCofThisEvent->GetHC(m_iGXeHitsCollectionID));
			iNbGXeHits = (pGXeHitsCollection)?(pGXeHitsCollection->entries()):(0);
		}

		if(m_iRestHitsCollectionID != -1)
		{
			pRestHitsCollection = (XuerichRestHitsCollection *)(pHCofThisEvent->GetHC(m_iRestHitsCollectionID));
			iNbRestHits = (pRestHitsCollection)?(pRestHitsCollection->entries()):(0);
		}

	}

	//if(iNbLXeHits || iNbPmtHits || iNbScintHits || iNbTeflonHits || iNbDeadXeHits || iNbGXeHits)
	if(iNbLXeHits)
	{
		m_pEventData->m_iEventId = pEvent->GetEventID();

		m_pEventData->m_pPrimaryParticleType->push_back(m_pPrimaryGeneratorAction->GetParticleTypeOfPrimary());

		m_pEventData->m_fPrimaryX = m_pPrimaryGeneratorAction->GetPositionOfPrimary().x();
		m_pEventData->m_fPrimaryY = m_pPrimaryGeneratorAction->GetPositionOfPrimary().y();
		m_pEventData->m_fPrimaryZ = m_pPrimaryGeneratorAction->GetPositionOfPrimary().z();

		G4int iNbSteps 			= 0;
		G4int iNbStepsScint 	= 0;
		G4int iNbStepsTeflon 	= 0;
		G4int iNbStepsDeadXe 	= 0;
		G4int iNbStepsGXe 		= 0;
		G4int iNbStepsRest 		= 0;

		G4float fTotalEnergyDepositedER 		= 0.;
		G4float fTotalEnergyDepositedNR 		= 0.;
		G4float fTotalEnergyDepositedScintER 	= 0.;
		G4float fTotalEnergyDepositedScintNR 	= 0.;
		G4float fTotalEnergyDepositedTeflon 	= 0.;
		G4float fTotalEnergyDepositedDeadXe 	= 0.;
		G4float fTotalEnergyDepositedGXe 		= 0.;
		G4float fTotalEnergyDepositedRest 		= 0.;

		// LXe hits
		for(G4int i=0; i<iNbLXeHits; i++)
		{
			XuerichLXeHit *pHit = (*pLXeHitsCollection)[i];

			if(pHit->GetParticleType()=="gamma" || pHit->GetParticleType()=="e-" || pHit->GetParticleType()=="e+")
			{
				m_pEventData->m_pTrackId->push_back(pHit->GetTrackId());
				m_pEventData->m_pParentId->push_back(pHit->GetParentId());

				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());
				m_pEventData->m_pParentType->push_back(pHit->GetParentType());
				m_pEventData->m_pCreatorProcess->push_back(pHit->GetCreatorProcess());
				m_pEventData->m_pDepositingProcess->push_back(pHit->GetDepositingProcess());

				m_pEventData->m_pX->push_back(pHit->GetPosition().x()/mm);
				m_pEventData->m_pY->push_back(pHit->GetPosition().y()/mm);
				m_pEventData->m_pZ->push_back(pHit->GetPosition().z()/mm);

				fTotalEnergyDepositedER += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDeposited->push_back(pHit->GetEnergyDeposited()/keV);

				m_pEventData->m_pKineticEnergy->push_back(pHit->GetKineticEnergy()/keV);
				m_pEventData->m_pTime->push_back(pHit->GetTime()/second);

				iNbSteps++;
			}

			if(pHit->GetParticleType()!="gamma" && pHit->GetParticleType()!="e-" && pHit->GetParticleType()!="e+")
			{
				m_pEventData->m_pTrackId->push_back(pHit->GetTrackId());
				m_pEventData->m_pParentId->push_back(pHit->GetParentId());

				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());
				m_pEventData->m_pParentType->push_back(pHit->GetParentType());
				m_pEventData->m_pCreatorProcess->push_back(pHit->GetCreatorProcess());
				m_pEventData->m_pDepositingProcess->push_back(pHit->GetDepositingProcess());

				m_pEventData->m_pX->push_back(pHit->GetPosition().x()/mm);
				m_pEventData->m_pY->push_back(pHit->GetPosition().y()/mm);
				m_pEventData->m_pZ->push_back(pHit->GetPosition().z()/mm);

				fTotalEnergyDepositedNR += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDeposited->push_back(pHit->GetEnergyDeposited()/keV);

				m_pEventData->m_pKineticEnergy->push_back(pHit->GetKineticEnergy()/keV);
				m_pEventData->m_pTime->push_back(pHit->GetTime()/second);

				iNbSteps++;
			}

			/*if(pHit->GetParticleType() != "opticalphoton")
			{
				m_pEventData->m_pTrackId->push_back(pHit->GetTrackId());
				m_pEventData->m_pParentId->push_back(pHit->GetParentId());

				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());
				m_pEventData->m_pParentType->push_back(pHit->GetParentType());
				m_pEventData->m_pCreatorProcess->push_back(pHit->GetCreatorProcess());
				m_pEventData->m_pDepositingProcess->push_back(pHit->GetDepositingProcess());

				m_pEventData->m_pX->push_back(pHit->GetPosition().x()/mm);
				m_pEventData->m_pY->push_back(pHit->GetPosition().y()/mm);
				m_pEventData->m_pZ->push_back(pHit->GetPosition().z()/mm);

				fTotalEnergyDeposited += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDeposited->push_back(pHit->GetEnergyDeposited()/keV);

				m_pEventData->m_pKineticEnergy->push_back(pHit->GetKineticEnergy()/keV);
				m_pEventData->m_pTime->push_back(pHit->GetTime()/second);

				iNbSteps++;
			}*/
		};

		// scintillator hits
		for(G4int i=0; i<iNbScintHits; i++)
		{
			XuerichScintHit *pHit = (*pScintHitsCollection)[i];

			//if(pHit->GetParticleType() != "opticalphoton")
			if(pHit->GetParticleType()=="gamma" || pHit->GetParticleType()=="e-" || pHit->GetParticleType()=="e+")
			{
				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());

				fTotalEnergyDepositedScintER += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDepositedScint->push_back(pHit->GetEnergyDeposited()/keV);
				m_pEventData->m_pTimeScint->push_back(pHit->GetTime()/second);

				m_pEventData->m_pXscint->push_back(pHit->GetPosition().x()/mm);
				m_pEventData->m_pYscint->push_back(pHit->GetPosition().y()/mm);
				m_pEventData->m_pZscint->push_back(pHit->GetPosition().z()/mm);

				iNbStepsScint++;
			}

			if(pHit->GetParticleType()!="gamma" && pHit->GetParticleType()!="e-" && pHit->GetParticleType()!="e+")
			{
				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());

				fTotalEnergyDepositedScintNR += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDepositedScint->push_back(pHit->GetEnergyDeposited()/keV);
				m_pEventData->m_pTimeScint->push_back(pHit->GetTime()/second);

				m_pEventData->m_pXscint->push_back(pHit->GetPosition().x()/mm);
				m_pEventData->m_pYscint->push_back(pHit->GetPosition().y()/mm);
				m_pEventData->m_pZscint->push_back(pHit->GetPosition().z()/mm);

				iNbStepsScint++;
			}
		};

		// teflon hits
		for(G4int i=0; i<iNbTeflonHits; i++)
		{
			XuerichTeflonHit *pHit = (*pTeflonHitsCollection)[i];

			if(pHit->GetParticleType() != "opticalphoton")
			{
				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());

				fTotalEnergyDepositedTeflon += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDepositedTeflon->push_back(pHit->GetEnergyDeposited()/keV);
				m_pEventData->m_pTimeTeflon->push_back(pHit->GetTime()/second);

				iNbStepsTeflon++;
			}
		};

		// dead Xe hits
		for(G4int i=0; i<iNbDeadXeHits; i++)
		{
			XuerichDeadXeHit *pHit = (*pDeadXeHitsCollection)[i];

			if(pHit->GetParticleType() != "opticalphoton")
			{
				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());

				fTotalEnergyDepositedDeadXe += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDepositedDeadXe->push_back(pHit->GetEnergyDeposited()/keV);
				m_pEventData->m_pTimeDeadXe->push_back(pHit->GetTime()/second);

				iNbStepsDeadXe++;
			}
		};

		// gas GXe hits
		for(G4int i=0; i<iNbGXeHits; i++)
		{
			XuerichGXeHit *pHit = (*pGXeHitsCollection)[i];

			if(pHit->GetParticleType() != "opticalphoton")
			{
				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());

				fTotalEnergyDepositedGXe += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDepositedGXe->push_back(pHit->GetEnergyDeposited()/keV);
				m_pEventData->m_pTimeGXe->push_back(pHit->GetTime()/second);

				iNbStepsGXe++;
			}
		};

		// hits in the rest of materials
		for(G4int i=0; i<iNbRestHits; i++)
		{
			XuerichRestHit *pHit = (*pRestHitsCollection)[i];

			if(pHit->GetParticleType() != "opticalphoton")
			{
				m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());

				fTotalEnergyDepositedRest += pHit->GetEnergyDeposited()/keV;
				m_pEventData->m_pEnergyDepositedRest->push_back(pHit->GetEnergyDeposited()/keV);
				m_pEventData->m_pTimeRest->push_back(pHit->GetTime()/second);

				iNbStepsRest++;
			}
		};

		m_pEventData->m_iNbSteps 		= iNbSteps;
		m_pEventData->m_iNbStepsScint 	= iNbStepsScint;
		m_pEventData->m_iNbStepsTeflon 	= iNbStepsTeflon;
		m_pEventData->m_iNbStepsDeadXe 	= iNbStepsDeadXe;
		m_pEventData->m_iNbStepsGXe 	= iNbStepsGXe;
		m_pEventData->m_iNbStepsRest 	= iNbStepsRest;

		m_pEventData->m_fTotalEnergyDepositedER 		= fTotalEnergyDepositedER;
		m_pEventData->m_fTotalEnergyDepositedNR 		= fTotalEnergyDepositedNR;
		m_pEventData->m_fTotalEnergyDepositedScintER  	= fTotalEnergyDepositedScintER;
		m_pEventData->m_fTotalEnergyDepositedScintNR  	= fTotalEnergyDepositedScintNR;
		m_pEventData->m_fTotalEnergyDepositedTeflon 	= fTotalEnergyDepositedTeflon;
		m_pEventData->m_fTotalEnergyDepositedDeadXe 	= fTotalEnergyDepositedDeadXe;
		m_pEventData->m_fTotalEnergyDepositedGXe 		= fTotalEnergyDepositedGXe;
		m_pEventData->m_fTotalEnergyDepositedRest 		= fTotalEnergyDepositedRest;

		const G4int NbPmts = 2;

		//m_pEventData->m_pPmtHits->resize(iNbTopPmts+iNbBottomPmts+iNbTopVetoPmts+iNbBottomVetoPmts, 0);

/*		// Pmt hits
		for(G4int i=0; i<iNbPmtHits; i++)
			(*(m_pEventData->m_pPmtHits))[(*pPmtHitsCollection)[i]->GetPmtNb()]++;

		m_pEventData->m_iNbTopPmtHits =
			accumulate(m_pEventData->m_pPmtHits->begin(), m_pEventData->m_pPmtHits->begin()+iNbTopPmts, 0);
		m_pEventData->m_iNbBottomPmtHits =
			accumulate(m_pEventData->m_pPmtHits->begin()+iNbTopPmts, m_pEventData->m_pPmtHits->end(), 0);
*/
		//if(fTotalEnergyDeposited > 0. || iNbPmtHits > 0)
		if((fTotalEnergyDepositedER>0. || fTotalEnergyDepositedNR>0.) && (fTotalEnergyDepositedScintER>0. || fTotalEnergyDepositedScintNR>0.))
		m_pTree->Fill();


		m_pEventData->Clear();
	}
}

void
XuerichAnalysisManager::Step(const G4Step *pStep)
{
/*	G4StepPoint* point1 = pStep->GetPreStepPoint();
    G4StepPoint* point2 = pStep->GetPostStepPoint();

	G4TouchableHandle touch1 	= point1->GetTouchableHandle();
	G4VPhysicalVolume *volume1 	= touch1->GetVolume();
	G4String name1 = volume1->GetName();
	
	G4cout << name1 << G4endl; 
*/
}

/*
G4bool
XuerichAnalysisManager::FilterEvent(XuerichEventData *pEventData)
{
	G4double dEnergyDepositedSensitiveRegion = 0.;

	vector<float> *pX = pEventData->m_pX;
	vector<float> *pY = pEventData->m_pY;
	vector<float> *pZ = pEventData->m_pZ;
	vector<float> *pEnergyDeposited = pEventData->m_pEnergyDeposited;

	const G4double dDriftLength = XuerichDetectorConstruction::GetGeometryParameter("DriftLength");
	const G4double dRadius = XuerichDetectorConstruction::GetGeometryParameter("TeflonCylinderInnerRadius");

	for(G4int i=0; i<pEnergyDeposited->size(); i++)
	{
		if((*pZ)[i] < 0. && (*pZ)[i] > -dDriftLength && std::sqrt((*pX)[i]*(*pX)[i] + (*pY)[i]*(*pY)[i]) < dRadius)
			dEnergyDepositedSensitiveRegion += (*pEnergyDeposited)[i];
	}

	if(dEnergyDepositedSensitiveRegion > 0.)
		return false;
	else
		return true;
}
*/
	
