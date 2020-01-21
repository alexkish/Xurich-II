#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "XuerichTeflonHit.hh"

G4Allocator<XuerichTeflonHit> XuerichTeflonHitAllocator;

XuerichTeflonHit::XuerichTeflonHit() {}

XuerichTeflonHit::~XuerichTeflonHit()
{
	if(m_pParticleType) delete m_pParticleType;
	//if(m_pParentType) delete m_pParentType;
	//if(m_pCreatorProcess) delete m_pCreatorProcess;
	//if(m_pDepositingProcess) delete m_pDepositingProcess;
}

XuerichTeflonHit::XuerichTeflonHit(const XuerichTeflonHit &hXuerichTeflonHit):G4VHit()
{
	//m_iTrackId = hXuerichTeflonHit.m_iTrackId;
	//m_iParentId = hXuerichTeflonHit.m_iParentId;
	m_pParticleType = hXuerichTeflonHit.m_pParticleType;
	//m_pParentType = hXuerichTeflonHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichTeflonHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichTeflonHit.m_pDepositingProcess ;
	m_hPosition = hXuerichTeflonHit.m_hPosition;
	m_dEnergyDeposited = hXuerichTeflonHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichTeflonHit.m_dKineticEnergy ;
	m_dTime = hXuerichTeflonHit.m_dTime;
}

const XuerichTeflonHit &
XuerichTeflonHit::operator=(const XuerichTeflonHit &hXuerichTeflonHit)
{
	//m_iTrackId = hXuerichTeflonHit.m_iTrackId;
	//m_iParentId = hXuerichTeflonHit.m_iParentId;
	m_pParticleType = hXuerichTeflonHit.m_pParticleType;
	//m_pParentType = hXuerichTeflonHit.m_pParentType ;
	//m_pCreatorProcess = hXuerichTeflonHit.m_pCreatorProcess ;
	//m_pDepositingProcess = hXuerichTeflonHit.m_pDepositingProcess ;
	m_hPosition = hXuerichTeflonHit.m_hPosition;
	m_dEnergyDeposited = hXuerichTeflonHit.m_dEnergyDeposited;
	m_dKineticEnergy = hXuerichTeflonHit.m_dKineticEnergy ;
	m_dTime = hXuerichTeflonHit.m_dTime;
	
	return *this;
}

G4int
XuerichTeflonHit::operator==(const XuerichTeflonHit &hXuerichTeflonHit) const
{
	return ((this == &hXuerichTeflonHit) ? (1) : (0));
}

void XuerichTeflonHit::Draw()
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

void XuerichTeflonHit::Print()
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

