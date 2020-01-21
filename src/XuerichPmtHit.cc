#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "XuerichPmtHit.hh"

G4Allocator<XuerichPmtHit> XuerichPmtHitAllocator;

XuerichPmtHit::XuerichPmtHit() {}

XuerichPmtHit::~XuerichPmtHit() {}

XuerichPmtHit::XuerichPmtHit(const XuerichPmtHit &hXuerichPmtHit):G4VHit()
{
	m_hPosition = hXuerichPmtHit.m_hPosition;
	m_dTime = hXuerichPmtHit.m_dTime;
	m_iPmtNb = hXuerichPmtHit.m_iPmtNb;
}

const XuerichPmtHit &
XuerichPmtHit::operator=(const XuerichPmtHit &hXuerichPmtHit)
{
	m_hPosition = hXuerichPmtHit.m_hPosition;
	m_dTime = hXuerichPmtHit.m_dTime;
	m_iPmtNb = hXuerichPmtHit.m_iPmtNb;
	
	return *this;
}

G4int
XuerichPmtHit::operator==(const XuerichPmtHit &hXuerichPmtHit) const
{
	return ((this == &hXuerichPmtHit) ? (1) : (0));
}

void XuerichPmtHit::Draw()
{
//    G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
//    
//    if(pVVisManager)
//    {
//        G4Circle hCircle(m_hPosition);
//        G4Colour hColour(1.000, 0.973, 0.184);
//        G4VisAttributes hVisAttributes(hColour);
//        
//        hCircle.SetScreenSize(0.1);
//        hCircle.SetFillStyle(G4Circle::filled);
//        hCircle.SetVisAttributes(hVisAttributes);
//        pVVisManager->Draw(hCircle);
//    }
}

void XuerichPmtHit::Print()
{
	G4cout << "Pmt hit ---> " 
		<< "Pmt#" << m_iPmtNb
		<< " Position: " << m_hPosition.x()/mm
		<< " " << m_hPosition.y()/mm
		<< " " << m_hPosition.z()/mm
		<< " mm"
		<< " Time: " << m_dTime/s << " s" << G4endl;
}

