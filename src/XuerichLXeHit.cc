#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "XuerichLXeHit.hh"

G4Allocator<XuerichLXeHit> XuerichLXeHitAllocator;

XuerichLXeHit::XuerichLXeHit() {}

XuerichLXeHit::~XuerichLXeHit()
{
	if(m_pParticleType) delete m_pParticleType;
	if(m_pParentType) delete m_pParentType;
	if(m_pCreatorProcess) delete m_pCreatorProcess;
	if(m_pDepositingProcess) delete m_pDepositingProcess;
}

XuerichLXeHit::XuerichLXeHit(const XuerichLXeHit &hXuerichLXeHit):G4VHit()
{
	m_iTrackId = hXuerichLXeHit.m_iTrackId;
	m_iParentId = hXuerichLXeHit.m_iParentId;
	m_pParticleType = hXuerichLXeHit.m_pParticleType;
	m_pParentType = hXuerichLXeHit.m_pParentType ;
	m_pCreatorProcess = hXuerichLXeHit.m_pCreatorProcess ;
	m_pDepositingProcess = hXuerichLXeHit.m_pDepositingProcess ;
	m_hPosition = hXuerichLXeHit.m_hPosition;
	m_dEnergyDeposited = hXuerichLXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichLXeHit.m_dKineticEnergy ;
	m_dTime = hXuerichLXeHit.m_dTime;
}

const XuerichLXeHit &
XuerichLXeHit::operator=(const XuerichLXeHit &hXuerichLXeHit)
{
	m_iTrackId = hXuerichLXeHit.m_iTrackId;
	m_iParentId = hXuerichLXeHit.m_iParentId;
	m_pParticleType = hXuerichLXeHit.m_pParticleType;
	m_pParentType = hXuerichLXeHit.m_pParentType ;
	m_pCreatorProcess = hXuerichLXeHit.m_pCreatorProcess ;
	m_pDepositingProcess = hXuerichLXeHit.m_pDepositingProcess ;
	m_hPosition = hXuerichLXeHit.m_hPosition;
	m_dEnergyDeposited = hXuerichLXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichLXeHit.m_dKineticEnergy ;
	m_dTime = hXuerichLXeHit.m_dTime;
	
	return *this;
}

G4int
XuerichLXeHit::operator==(const XuerichLXeHit &hXuerichLXeHit) const
{
	return ((this == &hXuerichLXeHit) ? (1) : (0));
}

void XuerichLXeHit::Draw()
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

void XuerichLXeHit::Print()
{
	G4cout << "-------------------- LXe hit --------------------" 
		<< "Id: " << m_iTrackId
		<< " Particle: " << *m_pParticleType
		<< " ParentId: " << m_iParentId
		<< " ParentType: " << *m_pParentType << G4endl
		<< "CreatorProcess: " << *m_pCreatorProcess
		<< " DepositingProcess: " << *m_pDepositingProcess << G4endl
		<< "Position: " << m_hPosition.x()/mm
		<< " " << m_hPosition.y()/mm
		<< " " << m_hPosition.z()/mm
		<< " mm" << G4endl
		<< "EnergyDeposited: " << m_dEnergyDeposited/keV << " keV"
		<< " KineticEnergyLeft: " << m_dKineticEnergy/keV << " keV"
		<< " Time: " << m_dTime/s << " s" << G4endl;
}

