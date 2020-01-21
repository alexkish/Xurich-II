#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "XuerichDeadXeHit.hh"

G4Allocator<XuerichDeadXeHit> XuerichDeadXeHitAllocator;

XuerichDeadXeHit::XuerichDeadXeHit() {}

XuerichDeadXeHit::~XuerichDeadXeHit()
{
	if(m_pParticleType) delete m_pParticleType;
	//if(m_pParentType) delete m_pParentType;
	//if(m_pCreatorProcess) delete m_pCreatorProcess;
	//if(m_pDepositingProcess) delete m_pDepositingProcess;
}

XuerichDeadXeHit::XuerichDeadXeHit(const XuerichDeadXeHit &hXuerichDeadXeHit):G4VHit()
{
	//m_iTrackId = hXuerichDeadXeHit.m_iTrackId;
	//m_iParentId = hXuerichDeadXeHit.m_iParentId;
	m_pParticleType = hXuerichDeadXeHit.m_pParticleType;
	//m_pParentType = hXuerichDeadXeHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichDeadXeHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichDeadXeHit.m_pDepositingProcess ;
	m_hPosition = hXuerichDeadXeHit.m_hPosition;
	m_dEnergyDeposited = hXuerichDeadXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichDeadXeHit.m_dKineticEnergy ;
	m_dTime = hXuerichDeadXeHit.m_dTime;
}

const XuerichDeadXeHit &
XuerichDeadXeHit::operator=(const XuerichDeadXeHit &hXuerichDeadXeHit)
{
	//m_iTrackId = hXuerichDeadXeHit.m_iTrackId;
	//m_iParentId = hXuerichDeadXeHit.m_iParentId;
	m_pParticleType = hXuerichDeadXeHit.m_pParticleType;
	//m_pParentType = hXuerichDeadXeHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichDeadXeHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichDeadXeHit.m_pDepositingProcess ;
	m_hPosition = hXuerichDeadXeHit.m_hPosition;
	m_dEnergyDeposited = hXuerichDeadXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichDeadXeHit.m_dKineticEnergy ;
	m_dTime = hXuerichDeadXeHit.m_dTime;
	
	return *this;
}

G4int
XuerichDeadXeHit::operator==(const XuerichDeadXeHit &hXuerichDeadXeHit) const
{
	return ((this == &hXuerichDeadXeHit) ? (1) : (0));
}

void XuerichDeadXeHit::Draw()
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

void XuerichDeadXeHit::Print()
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

