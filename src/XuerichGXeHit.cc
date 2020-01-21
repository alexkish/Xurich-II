#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "XuerichGXeHit.hh"

G4Allocator<XuerichGXeHit> XuerichGXeHitAllocator;

XuerichGXeHit::XuerichGXeHit() {}

XuerichGXeHit::~XuerichGXeHit()
{
	if(m_pParticleType) delete m_pParticleType;
	//if(m_pParentType) delete m_pParentType;
	//if(m_pCreatorProcess) delete m_pCreatorProcess;
	//if(m_pDepositingProcess) delete m_pDepositingProcess;
}

XuerichGXeHit::XuerichGXeHit(const XuerichGXeHit &hXuerichGXeHit):G4VHit()
{
	//m_iTrackId = hXuerichGXeHit.m_iTrackId;
	//m_iParentId = hXuerichGXeHit.m_iParentId;
	m_pParticleType = hXuerichGXeHit.m_pParticleType;
	//m_pParentType = hXuerichGXeHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichGXeHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichGXeHit.m_pDepositingProcess ;
	m_hPosition = hXuerichGXeHit.m_hPosition;
	m_dEnergyDeposited = hXuerichGXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichGXeHit.m_dKineticEnergy ;
	m_dTime = hXuerichGXeHit.m_dTime;
}

const XuerichGXeHit &
XuerichGXeHit::operator=(const XuerichGXeHit &hXuerichGXeHit)
{
	//m_iTrackId = hXuerichGXeHit.m_iTrackId;
	//m_iParentId = hXuerichGXeHit.m_iParentId;
	m_pParticleType = hXuerichGXeHit.m_pParticleType;
	//m_pParentType = hXuerichGXeHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichGXeHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichGXeHit.m_pDepositingProcess ;
	m_hPosition = hXuerichGXeHit.m_hPosition;
	m_dEnergyDeposited = hXuerichGXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichGXeHit.m_dKineticEnergy ;
	m_dTime = hXuerichGXeHit.m_dTime;
	
	return *this;
}

G4int
XuerichGXeHit::operator==(const XuerichGXeHit &hXuerichGXeHit) const
{
	return ((this == &hXuerichGXeHit) ? (1) : (0));
}

void XuerichGXeHit::Draw()
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

void XuerichGXeHit::Print()
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

