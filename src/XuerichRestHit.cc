#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "XuerichRestHit.hh"

G4Allocator<XuerichRestHit> XuerichRestHitAllocator;

XuerichRestHit::XuerichRestHit() {}

XuerichRestHit::~XuerichRestHit()
{
	if(m_pParticleType) delete m_pParticleType;
	//if(m_pParentType) delete m_pParentType;
	//if(m_pCreatorProcess) delete m_pCreatorProcess;
	//if(m_pDepositingProcess) delete m_pDepositingProcess;
}

XuerichRestHit::XuerichRestHit(const XuerichRestHit &hXuerichRestHit):G4VHit()
{
	//m_iTrackId = hXuerichRestHit.m_iTrackId;
	//m_iParentId = hXuerichRestHit.m_iParentId;
	m_pParticleType = hXuerichRestHit.m_pParticleType;
	//m_pParentType = hXuerichRestHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichRestHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichRestHit.m_pDepositingProcess ;
	m_hPosition = hXuerichRestHit.m_hPosition;
	m_dEnergyDeposited = hXuerichRestHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichRestHit.m_dKineticEnergy ;
	m_dTime = hXuerichRestHit.m_dTime;
}

const XuerichRestHit &
XuerichRestHit::operator=(const XuerichRestHit &hXuerichRestHit)
{
	//m_iTrackId = hXuerichRestHit.m_iTrackId;
	//m_iParentId = hXuerichRestHit.m_iParentId;
	m_pParticleType = hXuerichRestHit.m_pParticleType;
	//m_pParentType = hXuerichRestHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichRestHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichRestHit.m_pDepositingProcess ;
	m_hPosition = hXuerichRestHit.m_hPosition;
	m_dEnergyDeposited = hXuerichRestHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichRestHit.m_dKineticEnergy ;
	m_dTime = hXuerichRestHit.m_dTime;
	
	return *this;
}

G4int
XuerichRestHit::operator==(const XuerichRestHit &hXuerichRestHit) const
{
	return ((this == &hXuerichRestHit) ? (1) : (0));
}

void XuerichRestHit::Draw()
{
	G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
	
	if(pVVisManager)
	{
		G4Circle hCircle(m_hPosition);
		G4Colour hColour(1.000, 0.973, 0.184);
		G4VisAttributes hVisAttributes(hColour);
		
		hCircle.SetScreenSize(0.1);
		hCircle.SetFillStyle(G4Circle::filled);
		hCircle.SetVisAttributes(hVisAttributes);
		pVVisManager->Draw(hCircle);
	}
}

void XuerichRestHit::Print()
{
	G4cout << "-------------------- LXe hit --------------------" 
		//<< "Id: " << m_iTrackId
		//<< " Particle: " << *m_pParticleType
		//<< " ParentId: " << m_iParentId
		//<< " ParentType: " << *m_pParentType << G4endl
		//<< "CreatorProcess: " << *m_pCreatorProcess
		//<< " DepositingProcess: " << *m_pDepositingProcess << G4endl
		<< "Position: " << m_hPosition.x()/mm
		<< " " << m_hPosition.y()/mm
		<< " " << m_hPosition.z()/mm
		<< " mm" << G4endl
		<< "EnergyDeposited: " << m_dEnergyDeposited/keV << " keV"
		<< " KineticEnergyLeft: " << m_dKineticEnergy/keV << " keV"
		<< " Time: " << m_dTime/s << " s" << G4endl;
}

