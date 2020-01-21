/////////////////////////////////////////////////////////
//													   //
//   ++++++++++++++++++++++++++++++++++++++++++++++++  //
//   + Alexander Kish for XENON-XUERICH experiment	+  //
//   + UZH, 2008									+  //
// 	 ++++++++++++++++++++++++++++++++++++++++++++++++  //
//													   //
/////////////////////////////////////////////////////////

#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4Orb.hh"
#include "G4Polyhedra.hh"
#include "G4Trd.hh"
#include "G4Cons.hh"

#include "G4UnionSolid.hh"
#include "G4IntersectionSolid.hh"
#include "G4SubtractionSolid.hh"

#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"

#include "G4VisAttributes.hh"

#include "G4OpBoundaryProcess.hh"
#include "G4SDManager.hh"

#include "G4Colour.hh"
#include "globals.hh"

#include "G4ios.hh"

#include "vector"
#include "numeric"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"

using std::vector;
using std::stringstream;
using std::max;

#include "XuerichDetectorConstruction.hh"
#include "XuerichDetectorMessenger.hh"

#include "XuerichLXeSensitiveDetector.hh"
#include "XuerichGXeSensitiveDetector.hh"
#include "XuerichPmtSensitiveDetector.hh"
#include "XuerichScintSensitiveDetector.hh"
#include "XuerichTeflonSensitiveDetector.hh"
#include "XuerichDeadXeSensitiveDetector.hh"
#include "XuerichGXeSensitiveDetector.hh"
#include "XuerichRestSensitiveDetector.hh"

#include "TMath.h"

XuerichDetectorConstruction::XuerichDetectorConstruction()
{
	m_pDetectorMessenger = new XuerichDetectorMessenger(this);
}

XuerichDetectorConstruction::~XuerichDetectorConstruction()
{
	delete m_pDetectorMessenger;
}


G4VPhysicalVolume *XuerichDetectorConstruction::Construct()
{
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
G4cout 																			<< G4endl;
G4cout << 	" ============================================================"		<< G4endl;
G4cout <<	"|   XUERICH detector model :   Double Phase (Xenon) version  |"	<< G4endl;
G4cout <<	"|  ------------------------                                  |"	<< G4endl;
G4cout <<	"|                              Alexander Kish, UZH 2008-10   |"	<< G4endl;
G4cout <<	" ============================================================"		<< G4endl;
G4cout <<	"| "																<< G4endl;
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

	G4double	density,	// density
    			a,			// atomic weight (g/mole)
    			z;			// atomic number
	G4String	name,		// name
 				symbol;		// symbol
	G4int		ncomponents,
 				natoms;          
	G4double	temperature,
				pressure;    


//----------	Define elements		--------------------------------
	G4Element *H  = new G4Element(name= "Hydrogen",   symbol= "H",  z= 1.,  a= 1.008   *g/mole);
	G4Element *B  = new G4Element(name= "Boron",		symbol= "B",  z= 5.,  a= 10.811  *g/mole);
	G4Element *C  = new G4Element(name= "Carbon",     symbol= "C",  z= 6.,  a= 12.011  *g/mole);
	G4Element *N  = new G4Element(name= "Nitrogen",   symbol= "N",  z= 7.,  a= 14.01   *g/mole);
	G4Element *O  = new G4Element(name= "Oxygen",     symbol= "O",  z= 8.,  a= 16.00   *g/mole);
	G4Element *F  = new G4Element(name= "Fluorine",   symbol= "F",  z= 9.,  a= 18.998  *g/mole);
	G4Element *Al = new G4Element(name= "Aluminium",  symbol= "Al", z= 13., a= 26.98   *g/mole);
	G4Element *Si = new G4Element(name= "Silicon",    symbol= "Si", z= 14., a= 28.0855 *g/mole);
	G4Element *P  = new G4Element(name= "Phosphorus", symbol= "P",  z= 15., a= 30.9738 *g/mole);
	G4Element *S  = new G4Element(name= "Sulphur",    symbol= "S",  z= 16., a= 32.065  *g/mole);
	G4Element *Ar = new G4Element(name= "Argon",	  symbol= "Ar", z= 18., a= 39.948  *g/mole);
	G4Element *Ti = new G4Element(name= "Titanium",	  symbol= "Ti", z= 22., a= 47.867  *g/mole);
	G4Element *Cr = new G4Element(name= "Chromium",   symbol= "Cr", z= 24., a= 51.9962 *g/mole);
	G4Element *Mn = new G4Element(name= "Manganese",  symbol= "Mn", z= 25., a= 54.9381 *g/mole);
	G4Element *Fe = new G4Element(name= "Iron",       symbol= "Fe", z= 26., a= 55.845  *g/mole);
	G4Element *Co = new G4Element(name= "Cobalt",     symbol= "Co", z= 27., a= 58.9332 *g/mole);
	G4Element *Ni = new G4Element(name= "Nickel",     symbol= "Ni", z= 28., a= 58.6934 *g/mole);
	G4Element *Mo = new G4Element(name= "Molybdenum", symbol= "Mo", z= 42., a= 95.94   *g/mole);
	G4Element *Xe = new G4Element(name= "Xenon",      symbol= "Xe", z= 54., a= 131.29  *g/mole);
	G4Element *Pb = new G4Element(name= "Lead",       symbol= "Pb", z= 82., a= 207.2   *g/mole);


	////////////////////////////////////////////////////////////////////////////////////////////
	// Define Materials

   // Air
	G4Material *Air = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");

    // Vacuum
	G4Material *Vacuum 	= new G4Material(name = "Vacuum", z = 1., a = 1. *g/mole, density = 1.e-20 *g/cm3, kStateGas, temperature = 0.1 * kelvin, pressure = 1.e-20 * bar);

	// scintillator EJ301
  	G4Material* EJ301=new G4Material("EJ301", density=0.874*g/cm3, ncomponents=2);
	EJ301->AddElement(H, 54.8*perCent);
	EJ301->AddElement(C, 45.2*perCent);

	// Concrete
	G4Material *Concrete = G4NistManager::Instance()->FindOrBuildMaterial("G4_CONCRETE");

    // Lead	
    G4Material *Lead_m 	= new G4Material(name = "Lead_m", density = 11.34 *g/cm3, ncomponents =1);
    Lead_m-> AddElement(Pb, 1); 

    // Polyethylene	
	G4Material *Poly 	= new G4Material(name = "Poly", density = 0.95 *g/cm3, ncomponents =2);
	Poly->AddElement(C, 1);
	Poly->AddElement(H, 2);

	// paraffin
	G4Material *Paraffin = G4NistManager::Instance()->FindOrBuildMaterial("G4_PARAFFIN");
	//G4Material *paraffin = new G4Material("paraffin", density=0.93*g/cm3, ncomponents = 2);
	//paraffin->AddElement(H, 14.8605* perCent);
	//paraffin->AddElement(C, 85.1395* perCent);

    // Borated polyethylene (PE 1000 X-Protect, 15% Bortrioxid)
	G4Material *BPE = new G4Material(name = "BPE", density = 1.010 *g/cm3, ncomponents =4);
	BPE->AddElement(C, 0.30);
	BPE->AddElement(H, 0.55);
	BPE->AddElement(B, 0.06);
	BPE->AddElement(O, 0.09);
	
	// wood
	G4Material *wood = new G4Material("wood", density=0.7*g/cm3, ncomponents=3 );
	wood->AddElement(C, 28.57* perCent);
	wood->AddElement(H, 47.61* perCent);
	wood->AddElement(O, 23.82* perCent);
 
	// copper
	G4Material *Copper	= new G4Material(name= "Copper", z= 29., a= 63.5463 *g/mole, 8.92 *g/cm3);
    //----------	Xenon	----------------------------------------
	//G4Material* LXe    = new G4Material(name = "LXe",   2.85*g/cm3, 1, kStateLiquid, 177.15 *kelvin, 1.87 *atmosphere);
	//G4Material* LiqXe  = new G4Material(name = "LiqXe", 2.85*g/cm3, 1, kStateLiquid, 177.15 *kelvin, 1.87 *atmosphere);
	//G4Material* GasXe  = new G4Material("GasXe", 0.005887 * g / cm3, 1, kStateGas, 177.15 * kelvin, 1.5 * atmosphere);
	//LiqXe->AddElement(Xe, 1);	//Liquid Xenon with no scintillation
	//LXe->AddElement(Xe, 1);		//Liquid Xenon with scintillation
	//GasXe->AddElement(Xe, 1);	//Gas Xenon with no Scintillation
	
	// liquid xenon
	G4Material *LXe = new G4Material("LXe", 2.9172*g/cm3, 1, kStateLiquid, 168.15*kelvin, 1.8*atmosphere);
	LXe->AddElement(Xe, 1);

	const G4int iNbEntries = 3;

	G4double pdLXePhotonMomentum[]   	= {6.91*eV, 6.98*eV, 7.05*eV};
	G4double pdLXeScintillation[]    	= {0.1,     1.0,     0.1};
	G4double pdLXeRefractiveIndex[]		= {1.63,    1.61,    1.58};
	G4double pdLXeAbsorbtionLength[] 	= {100.*cm, 100.*cm, 100.*cm};
	G4double pdLXeScatteringLength[] 	= {30.*cm,  30.*cm,  30.*cm};
	
	G4MaterialPropertiesTable *pLXePropertiesTable = new G4MaterialPropertiesTable();
	
	pLXePropertiesTable->AddProperty("FASTCOMPONENT", pdLXePhotonMomentum, pdLXeScintillation, iNbEntries);
	pLXePropertiesTable->AddProperty("SLOWCOMPONENT", pdLXePhotonMomentum, pdLXeScintillation, iNbEntries);
	pLXePropertiesTable->AddProperty("RINDEX", pdLXePhotonMomentum, pdLXeRefractiveIndex, iNbEntries);
	pLXePropertiesTable->AddProperty("ABSLENGTH", pdLXePhotonMomentum, pdLXeAbsorbtionLength, iNbEntries);
	pLXePropertiesTable->AddProperty("RAYLEIGH", pdLXePhotonMomentum, pdLXeScatteringLength, iNbEntries);
	
	pLXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 0./(21.6*eV));
	pLXePropertiesTable->AddConstProperty("RESOLUTIONSCALE", 0);
	pLXePropertiesTable->AddConstProperty("FASTTIMECONSTANT", 3.*ns);
	pLXePropertiesTable->AddConstProperty("SLOWTIMECONSTANT", 27.*ns);
	pLXePropertiesTable->AddConstProperty("YIELDRATIO", 1.0);
	
	LXe->SetMaterialPropertiesTable(pLXePropertiesTable);

	// gaseous xenon
	G4Material *GXe = new G4Material("GXe", 0.005887*g/cm3, 1, kStateGas, 173.15*kelvin, 1.5*atmosphere);
	GXe->AddElement(Xe, 1);

	G4double pdGXePhotonMomentum[]   = {6.91*eV, 6.98*eV, 7.05*eV};
	G4double pdGXeScintillation[]    = {0.1,     1.0,     0.1};
	G4double pdGXeRefractiveIndex[]  = {1.00,    1.00,    1.00};
	G4double pdGXeAbsorbtionLength[] = {100*m,   100*m,   100*m};
	G4double pdGXeScatteringLength[] = {100*m,   100*m,   100*m};

	G4MaterialPropertiesTable *pGXePropertiesTable = new G4MaterialPropertiesTable();

	pGXePropertiesTable->AddProperty("FASTCOMPONENT", pdGXePhotonMomentum, pdGXeScintillation, iNbEntries);
	pGXePropertiesTable->AddProperty("SLOWCOMPONENT", pdGXePhotonMomentum, pdGXeScintillation, iNbEntries);
	pGXePropertiesTable->AddProperty("RINDEX", pdGXePhotonMomentum, pdGXeRefractiveIndex, iNbEntries);
	pGXePropertiesTable->AddProperty("ABSLENGTH", pdGXePhotonMomentum, pdGXeAbsorbtionLength, iNbEntries);
	pGXePropertiesTable->AddProperty("RAYLEIGH", pdGXePhotonMomentum, pdGXeScatteringLength, iNbEntries);

	pGXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 0./(keV));
	pGXePropertiesTable->AddConstProperty("RESOLUTIONSCALE", 0);
	pGXePropertiesTable->AddConstProperty("FASTTIMECONSTANT", 3.*ns);
	pGXePropertiesTable->AddConstProperty("SLOWTIMECONSTANT", 27.*ns);
	pGXePropertiesTable->AddConstProperty("YIELDRATIO", 1.0);

    GXe->SetMaterialPropertiesTable(pGXePropertiesTable);	

	// argon
	G4Material *LAr		= new G4Material(name = "LAr",		1.40*g/cm3, 1,	kStateLiquid, 87* kelvin,	1. * atmosphere);
	G4Material *LiqAr	= new G4Material(name = "LiqAr",	1.40*g/cm3, 1,	kStateLiquid, 87* kelvin,	1. * atmosphere);
	G4Material *GasAr	= new G4Material(name = "GasAr",	0.001786 * g / cm3, 1, kStateGas, 150.15 * kelvin,1.5 * atmosphere);
	LiqAr	->AddElement(Ar, 1);	//Liquid Argon with no scintillation
	LAr		->AddElement(Ar, 1);	//Liquid Argon with scintillation
	GasAr	->AddElement(Ar, 1);	//Gas Argon with no Scintillation
    // stainless steel
	G4Material *SSteel  = new G4Material(name = "SSteel", density = 7.7 *g/cm3, ncomponents = 3);
	SSteel->AddElement(C,  0.04);
	SSteel->AddElement(Fe, 0.88);
	SSteel->AddElement(Co, 0.08);
	
    // PTFE
	G4Material *Teflon	= new G4Material("Teflon", 2.16*g/cm3, 2, kStateSolid); // (density for the plain PTFE, i.e. from Boedeker); previously was 2.20g/cm3
	Teflon->AddElement(C, 0.240183);
	Teflon->AddElement(F, 0.759817);

	G4double pdTeflonPhotonMomentum[]  = {6.91*eV, 6.98*eV, 7.05*eV};
	G4double pdTeflonRefractiveIndex[] = {1.63,    1.61,    1.58};
	G4double pdTeflonReflectivity[]    = {0.95,    0.95,    0.95};
	G4double pdTeflonSpecularLobe[]    = {0.01,    0.01,    0.01};
	G4double pdTeflonSpecularSpike[]   = {0.01,    0.01,    0.01};
	G4double pdTeflonBackscatter[]     = {0.01,    0.01,    0.01};
	G4double pdTeflonEfficiency[]      = {1.0,     1.0,     1.0};
	G4MaterialPropertiesTable *pTeflonPropertiesTable = new G4MaterialPropertiesTable();

	pTeflonPropertiesTable->AddProperty("RINDEX", pdTeflonPhotonMomentum, pdTeflonRefractiveIndex, iNbEntries);
	pTeflonPropertiesTable->AddProperty("REFLECTIVITY", pdTeflonPhotonMomentum, pdTeflonReflectivity, iNbEntries);
	pTeflonPropertiesTable->AddProperty("SPECULARLOBECONSTANT", pdTeflonPhotonMomentum, pdTeflonSpecularLobe, iNbEntries);
	pTeflonPropertiesTable->AddProperty("SPECULARSPIKECONSTANT", pdTeflonPhotonMomentum, pdTeflonSpecularSpike, iNbEntries);
	pTeflonPropertiesTable->AddProperty("BACKSCATTERCONSTANT", pdTeflonPhotonMomentum, pdTeflonBackscatter, iNbEntries);
	pTeflonPropertiesTable->AddProperty("EFFICIENCY", pdTeflonPhotonMomentum, pdTeflonEfficiency, iNbEntries);
	Teflon->SetMaterialPropertiesTable(pTeflonPropertiesTable);
		
    // Quartz
	//G4Material* Quartz = new G4Material(name = "Quartz", density = 2.200 *g/cm3, ncomponents = 2);
	//Quartz->AddElement(Si, 1);
	//Quartz->AddElement(O,  2);

	// ref: http://www.sciner.com/Opticsland/FS.htm
	G4Material *Quartz = new G4Material("Quartz", 2.201*g/cm3, 2, kStateSolid, 168.15*kelvin, 1.5*atmosphere);
	Quartz->AddElement(Si, 1);
	Quartz->AddElement(O, 2);

	G4double pdQuartzPhotonMomentum[]   = {6.91*eV, 6.98*eV, 7.05*eV};
	G4double pdQuartzRefractiveIndex[]  = {1.50,    1.56,    1.60};
	G4double pdQuartzAbsorbtionLength[] = {30*m,    30*m,    30*m};

	G4MaterialPropertiesTable *pQuartzPropertiesTable = new G4MaterialPropertiesTable();

	pQuartzPropertiesTable->AddProperty("RINDEX", pdQuartzPhotonMomentum, pdQuartzRefractiveIndex, iNbEntries);
	pQuartzPropertiesTable->AddProperty("ABSLENGTH", pdQuartzPhotonMomentum, pdQuartzAbsorbtionLength, iNbEntries);

	Quartz->SetMaterialPropertiesTable(pQuartzPropertiesTable);

    //----------	Photocathode Aluminium	------------------------
	G4Material *metalAl	= new G4Material(name = "MetalAluminium", density = 2.700 *g/cm3, ncomponents = 1);
	metalAl->AddElement(Al, 1);
	
	G4Material *Alwire	= new G4Material(name = "Alwire", density = 0.174 *g/cm3, ncomponents = 1);
	Alwire->AddElement(Al, 1);


	G4Material *PhotoCathodeAluminium = new G4Material("PhotoCathodeAluminium", 8.00*g/cm3, 1, kStateSolid);
	PhotoCathodeAluminium->AddElement(Al, 1);

	G4double pdPhotoCathodePhotonMomentum[]   = {6.91*eV, 6.98*eV, 7.05*eV};
	G4double pdPhotoCathodeRefractiveIndex[]  = {1.50,    1.56,    1.60};
	G4double pdPhotoCathodeAbsorbtionLength[] = {1.*nm,   1.*nm,   1.*nm};

	G4MaterialPropertiesTable *pPhotoCathodePropertiesTable = new G4MaterialPropertiesTable();

	pPhotoCathodePropertiesTable->AddProperty("RINDEX", pdPhotoCathodePhotonMomentum, pdPhotoCathodeRefractiveIndex, iNbEntries);
	pPhotoCathodePropertiesTable->AddProperty("ABSLENGTH", pdPhotoCathodePhotonMomentum, pdPhotoCathodeAbsorbtionLength, iNbEntries);

	PhotoCathodeAluminium->SetMaterialPropertiesTable(pPhotoCathodePropertiesTable);


//***** Material Optical Properties *****//
	const G4int NUMENTRIES = 3;

//----- Stainless Steel Reflectivity to UV light ---------------------------
	G4double ssteel_PP[NUMENTRIES] = { 6.91 * eV, 6.98 * eV, 7.05 * eV };
	G4double ssteel_REFL[NUMENTRIES] = { 0.15, 0.2, 0.15 };
	G4MaterialPropertiesTable *ssteel_mt = new G4MaterialPropertiesTable();

	ssteel_mt->AddProperty("REFLECTIVITY", ssteel_PP, ssteel_REFL, NUMENTRIES);
	SSteel->SetMaterialPropertiesTable(ssteel_mt);

//----- Quartz Window Transparency -----------------------------------------
	G4double quartz_PP[NUMENTRIES]   = { 6.91 * eV, 6.98 * eV, 7.05 * eV };  // lambda range 4 ri
	G4double quartz_RIND[NUMENTRIES] = { 1.50, 1.56, 1.60 };	             // ref index
	G4double quartz_ABSL[NUMENTRIES] = { 30 * m, 30 * m, 30 * m };	         // atten length (remove Quartz)
	G4MaterialPropertiesTable *quartz_mt = new G4MaterialPropertiesTable();

	quartz_mt->AddProperty("RINDEX", quartz_PP, quartz_RIND, NUMENTRIES);
	quartz_mt->AddProperty("ABSLENGTH", quartz_PP, quartz_ABSL, NUMENTRIES);
	Quartz->SetMaterialPropertiesTable(quartz_mt);

//----- PMT Photocathode Absorption ----------------------------------------
	G4double cathmetal_PP[NUMENTRIES] = { 6.91 * eV, 6.98 * eV, 7.05 * eV };
	G4double cathmetal_RIND[NUMENTRIES] = { 1.50, 1.56, 1.60 };	                   // ref index
	G4double cathmetal_ABSL[NUMENTRIES] = { 1.e-20 * m, 1.e-20 * m, 1.e-20 * m };  // atten length
	G4MaterialPropertiesTable *cathmetal_mt = new G4MaterialPropertiesTable();

	cathmetal_mt->AddProperty("RINDEX", cathmetal_PP, cathmetal_RIND, NUMENTRIES);
	cathmetal_mt->AddProperty("ABSLENGTH", cathmetal_PP, cathmetal_ABSL, NUMENTRIES);
	metalAl->SetMaterialPropertiesTable(cathmetal_mt);
	
//----- Mesh Transparency --------------------------------------------------
	G4double mesh_PP[NUMENTRIES]   = { 6.91 * eV, 6.98 * eV, 7.05 * eV };	// lambda range 4 ri
	G4double mesh_RIND[NUMENTRIES] = { 1.63, 1.61, 1.58 };	                // ref index, set same as LXe
	G4double absl_len = 1.61615;	                       //atten length, correspond to 94% transparency
	G4double mesh_ABSL[NUMENTRIES] = { absl_len, absl_len, absl_len };
	G4MaterialPropertiesTable *mesh_mt = new G4MaterialPropertiesTable();

	mesh_mt->AddProperty("RINDEX", mesh_PP, mesh_RIND, NUMENTRIES);
	mesh_mt->AddProperty("ABSLENGTH", mesh_PP, mesh_ABSL, NUMENTRIES);
	Alwire->SetMaterialPropertiesTable(mesh_mt);

//////////////////////////////////////////////////////////////////////////////


//--------------	colours		--------------------------------
	G4Colour white  (1.0,	1.0,	1.0);
	G4Colour grey   (0.5,	0.5,	0.5);
	G4Colour lgrey  (.85,	.85,	.85);
	G4Colour red    (1.0,	0.0,	0.0);
	G4Colour lred   (0.75,	0.0,	0.0);
	G4Colour xlred  (0.5,	0.0,	0.0);
	G4Colour cyan   (0.0,	1.0,	1.0);
	G4Colour blue   (0.0,	0.0,	1.0);
	G4Colour lblue  (.5,	0.5,	1.,		1.);
	G4Colour xlblue (.5,	0.5,	1.,		0.2);
	G4Colour magenta(1.0,	0.0,	1.0);
	G4Colour yellow (1.0,	1.0,	0.0);
	G4Colour green  (0.,	.1,		0.);
	G4Colour lgreen (0.0,	.75,	0.0);
	G4Colour xlgreen(0.0,	0.5,	0.0);
	G4Colour brown  (0.7,	0.4,	0.1);
	G4Colour orange (1.0,	0.5,	0.0);

	// rotations
	G4RotationMatrix ZeroRot;
	ZeroRot.rotateX(0. *deg);
	ZeroRot.rotateY(0. *deg);
	ZeroRot.rotateZ(0. *deg);

	G4RotationMatrix RotationXPlus90;
	RotationXPlus90.rotateX(90.*deg);
	RotationXPlus90.rotateY(0.*deg);
	RotationXPlus90.rotateZ(0.*deg);

	G4double opendeg	= 0.0 *deg;
	G4double closedeg	= 360.0 *deg;

	// Laboratory
	G4double Lab_HalfX = 20.0 *m;
	G4double Lab_HalfY = 20.0 *m;
	G4double Lab_HalfZ = 10.0 *m;

	G4Box *Laboratory = new G4Box("Laboratory", Lab_HalfX, Lab_HalfY, Lab_HalfZ);

	////////////////////////////////////////
	// Concrete shield
	G4double ConcreteShield_thick 	= 350 *mm;
	G4double ConcreteShield_height 	= 3000 *mm;
	G4double ConcreteShield_width	= 2120 *mm;
	G4double ConcreteShield_depth	= 2120 *mm;
	G4double ConcreteWindow_oD		= 100 *mm;
	G4double ConcreteWindow_iD		= 0 *mm;
	G4double ConcreteWindow_height	= 1100 *mm;

	G4Box *ConcreteBox		= new G4Box("ConcreteBox", ConcreteShield_width/2, ConcreteShield_depth/2, ConcreteShield_height/2);
	G4Tubs *ConcreteWindow	= new G4Tubs("ConcreteWindow", ConcreteWindow_iD/2, ConcreteWindow_oD/2, ConcreteShield_thick, opendeg, closedeg);

	G4ThreeVector ConcreteWindow_V	(0.0, -ConcreteShield_depth/2+ConcreteShield_thick/2, -ConcreteShield_height/2+ConcreteWindow_height);
	G4Transform3D ConcreteWindow_T	(RotationXPlus90, ConcreteWindow_V);
	
	G4SubtractionSolid *ConcreteShield	= new G4SubtractionSolid( "ConcreteShield",	ConcreteBox, ConcreteWindow, ConcreteWindow_T);
	
	////////////////////////////////////////
	// BPE shield
	G4double BPEshield_thick 	= 200 *mm;
	G4double BPEshield_height 	= ConcreteShield_height - ConcreteShield_thick;
	G4double BPEshield_width	= ConcreteShield_width - 2*ConcreteShield_thick;
	G4double BPEshield_depth	= ConcreteShield_depth - 2*ConcreteShield_thick;
	G4double BPEwindow_oD		= 100 *mm;	
	G4double BPEwindow_iD		= 0 *mm;	
	G4double BPEwindow_height	= 1100 *mm;

	G4Box *BPEbox		= new G4Box("BPEbox", BPEshield_width/2, BPEshield_depth/2, BPEshield_height/2);
	G4Tubs *BPEwindow	= new G4Tubs("BPEwindow", BPEwindow_iD/2, BPEwindow_oD/2, BPEshield_thick, opendeg, closedeg);

	G4ThreeVector BPEwindow_V	(0.0, -BPEshield_depth/2+BPEshield_thick/2, -BPEshield_height/2+BPEwindow_height);
	G4Transform3D BPEwindow_T	(RotationXPlus90, BPEwindow_V);
	
	G4SubtractionSolid *BPEshield = new G4SubtractionSolid( "BPEshield",	BPEbox, BPEwindow, BPEwindow_T);

	G4Box *ConcreteShieldCavity		= new G4Box("ConcreteShieldCavity", BPEshield_width/2, BPEshield_depth/2, BPEshield_height/2);

	/////////////////////////////////////////
	// Shield cavity
	G4double ShieldCavity_height	= ConcreteShield_height - ConcreteShield_thick - BPEshield_thick;
	G4double ShieldCavity_width		= ConcreteShield_width - ConcreteShield_thick*2 - BPEshield_thick*2;
	G4double ShieldCavity_depth		= ConcreteShield_depth - ConcreteShield_thick*2 - BPEshield_thick*2;

	G4Box *ShieldCavity		= new G4Box("ShieldCavity", ShieldCavity_width/2, ShieldCavity_depth/2, ShieldCavity_height/2);

	/////////////////////////////////////////
	// Steel platform
	G4double Platform_height 	= 350 *mm;
	G4double Platform_width		= 1000 *mm;
	G4double Platform_depth		= 1000 *mm;

	G4Box *Platform		= new G4Box("Platform", Platform_width/2, Platform_depth/2, Platform_height/2);

	////////////////////////////////////////
	// paraffin shield
	G4double Paraffin_thick 			= 300 *mm;
	G4double ParaffinCylinder_height 	= 1400 *mm; 
	G4double ParaffinCylinder_oD		= 900 *mm;
	G4double ParaffinCylinder_iD		= 0 *mm;
	G4double ParaffinCut_oD				= ParaffinCylinder_oD - Paraffin_thick*2;
	G4double ParaffinCut_iD				= 0 *mm;
	G4double ParaffinCut_depth			= 1135 *mm;
	G4double ParaffinWindow_oD			= 100 *mm;
	G4double ParaffinWindow_iD			= 0 *mm;
	G4double ParaffinWindow_height		= 750 *mm;
	G4double ParaffinWindow_depth		= 400 *mm;

	G4Tubs *ParaffinCylinder 	= new G4Tubs("ParaffinCylinder", ParaffinCylinder_iD/2, ParaffinCylinder_oD/2, ParaffinCylinder_height/2, opendeg, closedeg);
	G4Tubs *ParaffinCut			= new G4Tubs("ParaffinCut", ParaffinCut_iD/2, ParaffinCut_oD/2, ParaffinCut_depth/2, opendeg, closedeg);	
	G4Tubs *ParaffinWindow		= new G4Tubs("ParaffinWindow", ParaffinWindow_iD/2, ParaffinWindow_oD/2, ParaffinWindow_depth/2, opendeg, closedeg);	

	G4ThreeVector ParaffinCut_V	(0.0, 0.0,	ParaffinCylinder_height/2 - ParaffinCut_depth/2);
	G4Transform3D ParaffinCut_T	(ZeroRot, ParaffinCut_V);

	G4ThreeVector ParaffinWindow_V	(0.0, -ParaffinCylinder_oD/2+ParaffinWindow_depth/2,	-ParaffinCylinder_height/2 + ParaffinWindow_height);
	G4Transform3D ParaffinWindow_T	(RotationXPlus90, ParaffinWindow_V);

	G4SubtractionSolid *ParaffinContainer1	= new G4SubtractionSolid( "ParaffinContainer1",	ParaffinCylinder, ParaffinCut, ParaffinCut_T);
	G4SubtractionSolid *ParaffinContainer	= new G4SubtractionSolid( "ParaffinContainer",	ParaffinContainer1, ParaffinWindow, ParaffinWindow_T);

	////////////////////////////////////////
	// concrete walls
	G4double Wall_height 		= 2760 *mm;
	G4double Wall_thick			= 200 *mm;
	G4double WallLeft_length 	= 5699 *mm;
	G4double WallFront_length	= 3257 *mm;
	G4double WallRight_length	= 3579 *mm;
	G4double WallBack_length	= 948 *mm;
	
	G4Box *WallLeft 	= new G4Box("WallLeft", Wall_thick/2, WallLeft_length/2, Wall_height/2);
	G4Box *WallFront 	= new G4Box("WallFront", WallFront_length/2, Wall_thick/2, Wall_height/2);
	G4Box *WallRight 	= new G4Box("WallRight", Wall_thick/2, WallRight_length/2, Wall_height/2);
	G4Box *WallBack 	= new G4Box("WallBack", WallBack_length/2, Wall_thick/2, Wall_height/2);

	/////////////////////////////////
	// generator
	G4double GeneratorContainer_height 	= 815 *mm;
	G4double GeneratorContainer_iD		= 0 *mm;
	G4double GeneratorContainer_oD		= 134 *mm;
	G4double GeneratorCavity_height		= 45 *mm;
	G4double GeneratorCavity_iD			= 0 *mm;
	G4double GeneratorCavity_oD			= 73 *mm;

	G4Tubs *GeneratorContainer	= new G4Tubs("GeneratorContainer", GeneratorContainer_iD/2, GeneratorContainer_oD/2, GeneratorContainer_height/2, opendeg, closedeg);	
	G4Tubs *GeneratorCavity		= new G4Tubs("GeneratorCavity", GeneratorCavity_iD/2, GeneratorCavity_oD/2, GeneratorCavity_height/2, opendeg, closedeg);	
	

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SCiNTILLATOR (NEUTRON DETECTOR)
	G4double scin_height 	= 84.074*mm;
	G4double scin_OR 		= 39.624*mm;
	G4double scin_IR 		= 0.*mm;

	G4double EJ_height 		= 76.2*mm;
	G4double EJ_OR 			= 38.1*mm;
	G4double EJ_IR			= 0.*cm;

	G4Tubs 	*scintillator 	= new G4Tubs("scintillator", scin_IR, scin_OR, scin_height/2, opendeg, closedeg);
	G4Tubs 	*EJ 			= new G4Tubs("EJ", EJ_IR, EJ_OR, EJ_height/2, opendeg, closedeg);


	/////////////////////////////////
	// XUERICH DETECTOR
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Cryostat: Inner Can
	G4double InnerCanTube_WallThick		= 2.0 *mm;
	G4double InnerCanTube_height		= 180.0 *mm;
	G4double InnerCanTube_iR			= 74.5 *mm;
	G4double InnerCanTube_oR			= InnerCanTube_iR + InnerCanTube_WallThick;
	G4double InnerCanBottom_thick		= InnerCanTube_WallThick;
	G4double InnerCanBottom_iR			= 0.0 *mm;
	G4double InnerCanBottom_oR			= InnerCanTube_oR;	
	G4double InnerCanLowerFlange_iR		= InnerCanTube_iR;
	G4double InnerCanLowerFlange_oR		= 101.5 *mm;
	G4double InnerCanLowerFlange_thick	= 22.0 *mm;
	G4double InnerCanUpperFlange_iR		= 0.0 *mm;
	G4double InnerCanUpperFlange_oR		= InnerCanLowerFlange_oR;
	G4double InnerCanUpperFlange_thick	= InnerCanLowerFlange_thick;
	G4double InnerCan_height			= InnerCanTube_height + InnerCanBottom_thick + InnerCanLowerFlange_thick + InnerCanUpperFlange_thick;
	
	G4Tubs *InnerCanTube 		= new G4Tubs("InnerCanTube", InnerCanTube_iR, InnerCanTube_oR, InnerCanTube_height/2, opendeg, closedeg);
	G4Tubs *InnerCanBottom 		= new G4Tubs("InnerCanBottom", InnerCanBottom_iR, InnerCanBottom_oR, InnerCanBottom_thick/2, opendeg, closedeg);
	G4Tubs *InnerCanLowerFlange	= new G4Tubs("InnerCanLowerFlange", InnerCanLowerFlange_iR, InnerCanLowerFlange_oR, InnerCanLowerFlange_thick/2, opendeg, closedeg);
	G4Tubs *InnerCanUpperFlange	= new G4Tubs("InnerCanUpperFlange", InnerCanUpperFlange_iR, InnerCanUpperFlange_oR, InnerCanUpperFlange_thick/2, opendeg, closedeg);
	
	// Cryostat: Outer Can
	G4double OuterCanTube_WallThick		= 3.0 *mm;
	G4double OuterCanTube_height		= 380.0 *mm;
	G4double OuterCanTube_iR			= 125.0 *mm;
	G4double OuterCanTube_oR			= OuterCanTube_iR + OuterCanTube_WallThick;
	G4double OuterCanBottom_thick		= OuterCanTube_WallThick;
	G4double OuterCanBottom_iR			= 0.0 *mm;
	G4double OuterCanBottom_oR			= OuterCanTube_oR;
	G4double OuterCanLowerFlange_thick	= 12.0 *mm;
	G4double OuterCanLowerFlange_iR		= OuterCanTube_iR;
	G4double OuterCanLowerFlange_oR		= 145.0 *mm;
	G4double OuterCanUpperFlange_thick	= 12.0 *mm;
	G4double OuterCanUpperFlange_iR		= 0.0 *mm;
	G4double OuterCanUpperFlange_oR		= 145.0 *mm;
	G4double OuterCan_height			= OuterCanTube_height + OuterCanBottom_thick + OuterCanLowerFlange_thick + OuterCanUpperFlange_thick;
	
	G4Tubs *OuterCanTube		= new G4Tubs("OuterCanTube", OuterCanTube_iR, OuterCanTube_oR, OuterCanTube_height/2, opendeg, closedeg);
	G4Tubs *OuterCanBottom		= new G4Tubs("OuterCanBottom", OuterCanBottom_iR, OuterCanBottom_oR, OuterCanBottom_thick/2, opendeg, closedeg);
	G4Tubs *OuterCanLowerFlange	= new G4Tubs("OuterCanLowerFlange", OuterCanLowerFlange_iR, OuterCanLowerFlange_oR, OuterCanLowerFlange_thick/2, opendeg, closedeg);
	G4Tubs *OuterCanUpperFlange	= new G4Tubs("OuterCanUpperFlange", OuterCanUpperFlange_iR, OuterCanUpperFlange_oR, OuterCanUpperFlange_thick/2, opendeg, closedeg);
	
	//--------------	Cryostat: Vacuum	------------------------
	G4double CryostatVacuum_iR		= 0.0 *mm;
	G4double CryostatVacuum_oR		= OuterCanTube_iR;
	G4double CryostatVacuum_height	= OuterCanTube_height;

	G4Tubs *CryostatVacuum	= new G4Tubs("CryostatVacuum", CryostatVacuum_iR, CryostatVacuum_oR, CryostatVacuum_height/2, opendeg, closedeg);

	//--------------	SteelHolder			------------------------
	G4double SteelHolder_thick				= 3.0 *mm;
	G4double SteelHolder_height				= 38.0 *mm;
	G4double SteelHolderTube_iR				= 28.5 *mm;	
	G4double SteelHolderTube_oR				= SteelHolderTube_iR + SteelHolder_thick;
	G4double SteelHolderTube_height			= SteelHolder_height - 2*SteelHolder_thick;
	G4double SteelHolderUpperSquare_side	= 65.0 *mm;
	G4double SteelHolderUpperSquare_thick	= SteelHolder_thick;
	G4double SteelHolderLowerSquare_side	= 65.0 *mm;
	G4double SteelHolderLowerSquare_thick	= SteelHolder_thick;
	G4double SteelHolderUpperCutout_iR		= 0.0 *mm;
	G4double SteelHolderUpperCutout_oR		= SteelHolderTube_iR;
	G4double SteelHolderUpperCutout_thick	= SteelHolder_thick;
	G4double SteelHolderLowerCutout_iR		= 0.0 *mm;
	G4double SteelHolderLowerCutout_oR		= SteelHolderTube_iR;
	G4double SteelHolderLowerCutout_thick	= SteelHolder_thick;

	G4Tubs *SteelHolderTube			= new G4Tubs("SteelHolderTube", SteelHolderTube_iR, SteelHolderTube_oR, SteelHolderTube_height/2, opendeg, closedeg);
	G4Box *SteelHolderUpperSquare 	= new G4Box("SteelHolderUpperSquare", SteelHolderUpperSquare_side/2, SteelHolderUpperSquare_side/2, SteelHolderUpperSquare_thick/2);
	G4Box *SteelHolderLowerSquare	= new G4Box("SteelHolderLowerSquare", SteelHolderLowerSquare_side/2, SteelHolderLowerSquare_side/2, SteelHolderLowerSquare_thick/2);
	G4Tubs *SteelHolderUpperCutout	= new G4Tubs("SteelHolderUpperCutout", SteelHolderUpperCutout_iR, SteelHolderUpperCutout_oR, SteelHolderUpperCutout_thick/2, opendeg, closedeg);
	G4Tubs *SteelHolderLowerCutout	= new G4Tubs("SteelHolderLowerCutOut", SteelHolderLowerCutout_iR, SteelHolderLowerCutout_oR, SteelHolderLowerCutout_thick/2, opendeg, closedeg);

	G4ThreeVector SteelHolderUpperCutout_V	(0.0, 0.0,	0.0);	
	G4Transform3D SteelHolderUpperCutout_T	(ZeroRot, 	SteelHolderUpperCutout_V);

	G4ThreeVector SteelHolderLowerCutout_V	(0.0, 0.0,	0.0);	
	G4Transform3D SteelHolderLowerCutout_T	(ZeroRot, 	SteelHolderLowerCutout_V);

	G4SubtractionSolid
	* SteelHolderUpperSquare1
	= new G4SubtractionSolid(	"SteelHolderUpperSquare1",	SteelHolderUpperSquare,	SteelHolderUpperCutout,		SteelHolderUpperCutout_T);

	G4SubtractionSolid
	* SteelHolderLowerSquare1
	= new G4SubtractionSolid(	"SteelHolderLowerSquare1",	SteelHolderLowerSquare,	SteelHolderLowerCutout,		SteelHolderLowerCutout_T);

	//--------------	Supports			------------------------
	G4double Support_height		= 34.0 *mm;
	G4double Support_iR			= 0.0 *mm;
	G4double Support_oR			= 8.0 *mm;
	G4double Washer_iR			= 0.0 *mm;
	G4double Washer_oR			= 6.0 *mm;
	G4double Washer_thick		= 2.0 *mm;
	
	G4Tubs *Support = new G4Tubs("Support", Support_iR, Support_oR, Support_height/2, opendeg, closedeg);
	G4Tubs *Washer	= new G4Tubs("Washer", Washer_iR, Washer_oR, Washer_thick/2, opendeg, closedeg);

	//--------------	Top PMT Clamp		------------------------
	G4double TopClamp_iR	= 22.5 *mm;
	G4double TopClamp_oR	= 30.0 *mm;
	G4double TopClamp_thick	= 2.0 *mm;
	
	G4Tubs *TopClamp = new G4Tubs("TopClamp", TopClamp_iR, TopClamp_oR, TopClamp_thick/2, opendeg, closedeg);
	
	//--------------	Top PMT Holder		------------------------
	G4double TopHolderTube_oR				= 60.0 *mm;
	G4double TopHolderTube_iR				= 0.0 *mm;
	G4double TopHolderTube_height			= 33.0 *mm;
	
	G4double TopHolderUpperTube_iR			= 28.5 *mm;	
	G4double TopHolderUpperTube_oR			= TopHolderTube_oR;
	G4double TopHolderUpperTube_height		= 28.0 *mm;
	G4double TopHolderLowerTube_iR			= 17.5 *mm;
	G4double TopHolderLowerTube_oR			= TopHolderTube_oR;
	G4double TopHolderLowerTube_height		= TopHolderTube_height - TopHolderUpperTube_height;
	
	G4double TopHolderSquare_side			= 58.5 *mm;
	G4double TopHolderSquare_thick			= 2.5 *mm;
	G4double TopHolderSquareCutout_iR		= 0.0 *mm;
	G4double TopHolderSquareCutout_oR		= 17.5 *mm;
	G4double TopHolderSquareCutout_thick	= TopHolderSquare_thick;	
	
	G4double TopHolder_height				= TopHolderTube_height + TopHolderSquare_thick;
	
	G4Tubs *TopHolderUpperTube 		= new G4Tubs("TopHolderUpperTube", TopHolderUpperTube_iR, TopHolderUpperTube_oR, TopHolderUpperTube_height/2, opendeg, closedeg);
	G4Tubs *TopHolderLowerTube		= new G4Tubs("TopHolderLowerTube", TopHolderLowerTube_iR, TopHolderLowerTube_oR, TopHolderLowerTube_height/2, opendeg, closedeg);
	G4Box *TopHolderSquare			= new G4Box("TopHolderSquare", TopHolderSquare_side/2, TopHolderSquare_side/2, TopHolderSquare_thick/2);
	G4Tubs *TopHolderSquareCutout	= new G4Tubs("TopHolderSquareCutout", TopHolderSquareCutout_iR, TopHolderSquareCutout_oR, TopHolderSquareCutout_thick/2, opendeg, closedeg);
	
	G4ThreeVector TopHolderSquareCutout_V	(0.0, 0.0,  0.0);
	G4Transform3D TopHolderSquareCutout_T	(ZeroRot, TopHolderSquareCutout_V);

	G4SubtractionSolid *TopHolderSquare1 = new G4SubtractionSolid("TopHolderSquare1",	TopHolderSquare,	TopHolderSquareCutout,	TopHolderSquareCutout_T);

	//--------------	Extraction Spacer	------------------------
	G4double ExtractionSpacer_iR		= 17.5 *mm;
	G4double ExtractionSpacer_oR		= 60.0 *mm;
	G4double ExtractionSpacer_height	= 5.0 *mm;
	
	G4double ExtractionHalfSpacer_iR		= ExtractionSpacer_iR;
	G4double ExtractionHalfSpacer_oR		= ExtractionSpacer_oR;
	G4double ExtractionHalfSpacer_height	= ExtractionSpacer_height/2;
	
	G4Tubs *ExtractionHalfSpacer = new G4Tubs("ExtractionHalfSpacer", ExtractionHalfSpacer_iR, ExtractionHalfSpacer_oR, ExtractionHalfSpacer_height/2, opendeg, closedeg);

	// Drift Spacer (normal big spacer)
	G4double DriftSpacerTube_iR				= 17.5 *mm;
	G4double DriftSpacerTube_oR				= 60.0 *mm;
	G4double DriftSpacerTube_height			= 24.0 *mm;	

	G4double DriftSpacerUpperTube_iR		= DriftSpacerTube_iR;
	G4double DriftSpacerUpperTube_oR		= DriftSpacerTube_oR;
	G4double DriftSpacerUpperTube_height	= 11.0 *mm;
	
	G4double DriftSpacerMiddleTube_iR		= DriftSpacerTube_iR;
	G4double DriftSpacerMiddleTube_oR		= 30.0 *mm;
	G4double DriftSpacerMiddleTube_height	= 2.0 *mm;
	
	
	G4double DriftSpacerLowerTube_iR		= DriftSpacerTube_iR;
	G4double DriftSpacerLowerTube_oR		= DriftSpacerTube_oR;
	G4double DriftSpacerLowerTube_height	= 11.0 *mm;

	G4double DriftSpacerUpperSquare_side	= 58.5 *mm;
	G4double DriftSpacerUpperSquare_thick	= 2.5 *mm;
	G4double DriftSpacerLowerSquare_side	= 58.5 *mm;
	G4double DriftSpacerLowerSquare_thick	= 2.5 *mm;

	G4double DriftSpacerUpperSquareCutout_iR	= 0.0 *mm;
	G4double DriftSpacerUpperSquareCutout_oR	= 17.5 *mm;
	G4double DriftSpacerUpperSquareCutout_thick	= DriftSpacerUpperSquare_thick;
	G4double DriftSpacerLowerSquareCutout_iR	= 0.0 *mm;
	G4double DriftSpacerLowerSquareCutout_oR	= 17.5 *mm;
	G4double DriftSpacerLowerSquareCutout_thick	= DriftSpacerLowerSquare_thick;
	
	G4Tubs *DriftSpacerUpperTube 		= new G4Tubs("DriftSpacerUpperTube",	DriftSpacerUpperTube_iR, DriftSpacerUpperTube_oR, DriftSpacerUpperTube_height/2, opendeg, closedeg);
	G4Tubs *DriftSpacerMiddleTube		= new G4Tubs("DriftSpacerMiddleTube",	DriftSpacerMiddleTube_iR, DriftSpacerMiddleTube_oR, DriftSpacerMiddleTube_height/2, opendeg, closedeg);
	G4Tubs *DriftSpacerLowerTube		= new G4Tubs("DriftSpacerLowerTube",	DriftSpacerLowerTube_iR, DriftSpacerLowerTube_oR, DriftSpacerLowerTube_height/2, opendeg, closedeg);
	G4Box *DriftSpacerUpperSquare		= new G4Box("DriftSpacerUpperSquare",	DriftSpacerUpperSquare_side/2, DriftSpacerUpperSquare_side/2, DriftSpacerUpperSquare_thick/2);
	G4Box *DriftSpacerLowerSquare		= new G4Box("DriftSpacerLowerSquare",	DriftSpacerLowerSquare_side/2, DriftSpacerLowerSquare_side/2, DriftSpacerLowerSquare_thick/2);
	G4Tubs *DriftSpacerUpperSquareCutout= new G4Tubs("DriftSpacerUpperSquareCutout",	DriftSpacerUpperSquareCutout_iR, DriftSpacerUpperSquareCutout_oR, DriftSpacerUpperSquareCutout_thick/2, opendeg, closedeg);
	G4Tubs *DriftSpacerLowerSquareCutout= new G4Tubs("DriftSpacerLowerSquareCutout",	DriftSpacerLowerSquareCutout_iR, DriftSpacerLowerSquareCutout_oR, DriftSpacerLowerSquareCutout_thick/2, opendeg, closedeg);

	G4ThreeVector DriftSpacerUpperSquareCutout_V	(0.0, 0.0, 0.0);
	G4ThreeVector DriftSpacerLowerSquareCutout_V	(0.0, 0.0, 0.0 );
	
	G4Transform3D DriftSpacerUpperSquareCutout_T	(ZeroRot, DriftSpacerUpperSquareCutout_V);
	G4Transform3D DriftSpacerLowerSquareCutout_T	(ZeroRot, DriftSpacerLowerSquareCutout_V);

	G4SubtractionSolid *DriftSpacerUpperSquare1 = new G4SubtractionSolid("DriftSpacerUpperSquare1",	DriftSpacerUpperSquare,	DriftSpacerUpperSquareCutout,	DriftSpacerUpperSquareCutout_T);
	G4SubtractionSolid *DriftSpacerLowerSquare1 = new G4SubtractionSolid("DriftSpacerLowerSquare1",	DriftSpacerLowerSquare,	DriftSpacerLowerSquareCutout,	DriftSpacerLowerSquareCutout_T);

/*	// Drift Spacer (small spacer)
	G4double DriftSpacerTube_iR				= 17.5 *mm;
	G4double DriftSpacerTube_oR				= 60.0 *mm;
	G4double DriftSpacerTube_height			= 24.0 *mm;	

	G4double DriftSpacerUpperTube_iR		= DriftSpacerTube_iR;
	G4double DriftSpacerUpperTube_oR		= 30.0 *mm;
	G4double DriftSpacerUpperTube_height	= 11.0 *mm;
	
	G4double DriftSpacerMiddleTube_iR		= DriftSpacerTube_iR;
	G4double DriftSpacerMiddleTube_oR		= 30.0 *mm;
	G4double DriftSpacerMiddleTube_height	= 2.0 *mm;
	
	G4double DriftSpacerLowerTube_iR		= DriftSpacerTube_iR;
	G4double DriftSpacerLowerTube_oR		= 30.0 *mm;
	G4double DriftSpacerLowerTube_height	= 11.0 *mm;

	G4double DriftSpacerUpperSquare_side	= 58.5 *mm;
	G4double DriftSpacerUpperSquare_thick	= 2.5 *mm;
	G4double DriftSpacerLowerSquare_side	= 58.5 *mm;
	G4double DriftSpacerLowerSquare_thick	= 2.5 *mm;

	G4double DriftSpacerUpperSquareCutout_iR	= 0.0 *mm;
	G4double DriftSpacerUpperSquareCutout_oR	= 17.5 *mm;
	G4double DriftSpacerUpperSquareCutout_thick	= DriftSpacerUpperSquare_thick;
	G4double DriftSpacerLowerSquareCutout_iR	= 0.0 *mm;
	G4double DriftSpacerLowerSquareCutout_oR	= 17.5 *mm;
	G4double DriftSpacerLowerSquareCutout_thick	= DriftSpacerLowerSquare_thick;
	
	G4Tubs *DriftSpacerUpperTube 		= new G4Tubs("DriftSpacerUpperTube",	DriftSpacerUpperTube_iR, DriftSpacerUpperTube_oR, DriftSpacerUpperTube_height/2, opendeg, closedeg);
	G4Tubs *DriftSpacerMiddleTube		= new G4Tubs("DriftSpacerMiddleTube",	DriftSpacerMiddleTube_iR, DriftSpacerMiddleTube_oR, DriftSpacerMiddleTube_height/2, opendeg, closedeg);
	G4Tubs *DriftSpacerLowerTube		= new G4Tubs("DriftSpacerLowerTube",	DriftSpacerLowerTube_iR, DriftSpacerLowerTube_oR, DriftSpacerLowerTube_height/2, opendeg, closedeg);
	G4Box *DriftSpacerUpperSquare		= new G4Box("DriftSpacerUpperSquare",	DriftSpacerUpperSquare_side/2, DriftSpacerUpperSquare_side/2, DriftSpacerUpperSquare_thick/2);
	G4Box *DriftSpacerLowerSquare		= new G4Box("DriftSpacerLowerSquare",	DriftSpacerLowerSquare_side/2, DriftSpacerLowerSquare_side/2, DriftSpacerLowerSquare_thick/2);
	G4Tubs *DriftSpacerUpperSquareCutout= new G4Tubs("DriftSpacerUpperSquareCutout",	DriftSpacerUpperSquareCutout_iR, DriftSpacerUpperSquareCutout_oR, DriftSpacerUpperSquareCutout_thick/2, opendeg, closedeg);
	G4Tubs *DriftSpacerLowerSquareCutout= new G4Tubs("DriftSpacerLowerSquareCutout",	DriftSpacerLowerSquareCutout_iR, DriftSpacerLowerSquareCutout_oR, DriftSpacerLowerSquareCutout_thick/2, opendeg, closedeg);

	G4ThreeVector DriftSpacerUpperSquareCutout_V	(0.0, 0.0, 0.0);
	G4ThreeVector DriftSpacerLowerSquareCutout_V	(0.0, 0.0, 0.0 );
	
	G4Transform3D DriftSpacerUpperSquareCutout_T	(ZeroRot, DriftSpacerUpperSquareCutout_V);
	G4Transform3D DriftSpacerLowerSquareCutout_T	(ZeroRot, DriftSpacerLowerSquareCutout_V);

	G4SubtractionSolid *DriftSpacerUpperSquare1 = new G4SubtractionSolid("DriftSpacerUpperSquare1",	DriftSpacerUpperSquare,	DriftSpacerUpperSquareCutout,	DriftSpacerUpperSquareCutout_T);
	G4SubtractionSolid *DriftSpacerLowerSquare1 = new G4SubtractionSolid("DriftSpacerLowerSquare1",	DriftSpacerLowerSquare,	DriftSpacerLowerSquareCutout,	DriftSpacerLowerSquareCutout_T);
*/
	
	// Bottom PMT Holder
	G4double BottomHolderTube_iR				= 0.0 *mm;
	G4double BottomHolderTube_oR				= 60.0 *mm;
	G4double BottomHolderTube_height			= 33.0 *mm;
	
	G4double BottomHolderUpperTube_iR			= 17.5 *mm;
	G4double BottomHolderUpperTube_oR			= 60.0 *mm;
	G4double BottomHolderUpperTube_height		= 5.0 *mm;

	G4double BottomHolderMiddleTube_iR			= 28.5 *mm;
	G4double BottomHolderMiddleTube_oR			= 60.0 *mm;
	G4double BottomHolderMiddleTube_height		= 26.0 *mm;

	G4double BottomHolderLowerTube_iR			= 28.5 *mm;
	G4double BottomHolderLowerTube_oR			= 60.0 *mm;
	G4double BottomHolderLowerTube_height		= 2.0 *mm;
	
	G4Tubs *BottomHolderUpperTube 	= new G4Tubs("BottomHolderUpperTube", BottomHolderUpperTube_iR, BottomHolderUpperTube_oR, BottomHolderUpperTube_height/2, opendeg, closedeg);
	G4Tubs *BottomHolderMiddleTube	= new G4Tubs("BottomHolderMiddleTube", BottomHolderMiddleTube_iR, BottomHolderMiddleTube_oR, BottomHolderMiddleTube_height/2, opendeg, closedeg);
	G4Tubs *BottomHolderLowerTube	= new G4Tubs("BottomHolderLowerTube", BottomHolderLowerTube_iR, BottomHolderLowerTube_oR, BottomHolderLowerTube_height/2, opendeg, closedeg);
	
	// Bottom PMT Clamp
	G4double BottomClamp_height				= 9.0 *mm;
	G4double BottomClamp_iR					= 22.5 *mm;

	G4double BottomClampUpperPart_height	= 2.0 *mm;
	G4double BottomClampUpperPart_oR		= 30.0 *mm;
	
	G4double BottomClampLowerPart_height	= 2.0 *mm;
	G4double BottomClampLowerPart_oR		= 23.5 *mm;
	
	G4double BottomClampMiddlePart_height	= 5.0 *mm;
	G4double BottomClampMiddlePart_oR		= 23.5 *mm;
	
	G4Tubs *BottomClampMiddlePart	= new G4Tubs("BottomClampMiddlePart", BottomClamp_iR, BottomClampMiddlePart_oR, BottomClampMiddlePart_height/2, opendeg, closedeg);
	G4Tubs *BottomClampUpperPart	= new G4Tubs("BottomClampUpperPart", BottomClamp_iR, BottomClampUpperPart_oR, BottomClampUpperPart_height/2, opendeg, closedeg);
	G4Tubs *BottomClampLowerPart	= new G4Tubs("BottomClampLowerPart", BottomClamp_iR, BottomClampLowerPart_oR, BottomClampLowerPart_height/2, opendeg, closedeg);
	
	//--------------	Filler, with cut filled with GXe and LXe
	G4double Filler_oR				= 73.75 *mm;
	G4double Filler_height			= 65.0 *mm;	
	G4double FillerUpperPart_iR		= 60.5 *mm;
	G4double FillerUpperPart_oR		= Filler_oR;
	G4double FillerUpperPart_height	= 63.0 *mm;
	G4double FillerLowerPart_iR		= 58.0 *mm;
	G4double FillerLowerPart_oR		= Filler_oR;
	G4double FillerLowerPart_height	= 2.0 *mm;
	G4double FillerCut_iR			= 63.125 *mm;
	G4double FillerCut_oR			= 71.125 *mm;
	G4double FillerCut_depth		= 50.0 *mm;

	G4Tubs *FillerUpperPart	= new G4Tubs("FillerUpperPart", FillerUpperPart_iR, FillerUpperPart_oR, FillerUpperPart_height/2, opendeg, closedeg);
	G4Tubs *FillerLowerPart	= new G4Tubs("FillerLowerPart", FillerLowerPart_iR, FillerLowerPart_oR, FillerLowerPart_height/2, opendeg, closedeg);

	G4ThreeVector FillerLowerPart_V		(0.0, 0.0, -FillerUpperPart_height/2-FillerLowerPart_height/2 );	
	G4Transform3D FillerLowerPart_T		(ZeroRot, FillerLowerPart_V);

	G4UnionSolid *Filler1	= new G4UnionSolid(	"Filler1",	FillerUpperPart,	FillerLowerPart,	FillerLowerPart_T);

	G4Tubs *FillerCut	= new G4Tubs("FillerCut", FillerCut_iR, FillerCut_oR, FillerCut_depth/2, opendeg, closedeg);

	G4ThreeVector FillerCut_V	(0.0, 0.0,	Filler_height/2 - FillerCut_depth/2);
	G4Transform3D FillerCut_T	(ZeroRot, FillerCut_V);

	G4SubtractionSolid *Filler = new G4SubtractionSolid( "Filler",	Filler1, FillerCut,	FillerCut_T);

/*	//--------------	Filler, solid tube without cut
	G4double Filler_oR				= 73.75 *mm;
	G4double Filler_height			= 65.0 *mm;	
	G4double FillerUpperPart_iR		= 60.5 *mm;
	G4double FillerUpperPart_oR		= Filler_oR;
	G4double FillerUpperPart_height	= 63.0 *mm;
	G4double FillerLowerPart_iR		= 58.0 *mm;
	G4double FillerLowerPart_oR		= Filler_oR;
	G4double FillerLowerPart_height	= 2.0 *mm;
	G4double FillerCut_iR			= 63.25 *mm;
	G4double FillerCut_oR			= 67.25 *mm;
	G4double FillerCut_depth		= 50.0 *mm;

	G4Tubs *FillerUpperPart	= new G4Tubs("FillerUpperPart", FillerUpperPart_iR, FillerUpperPart_oR, FillerUpperPart_height/2, opendeg, closedeg);
	G4Tubs *FillerLowerPart	= new G4Tubs("FillerLowerPart", FillerLowerPart_iR, FillerLowerPart_oR, FillerLowerPart_height/2, opendeg, closedeg);

	G4ThreeVector FillerLowerPart_V		(0.0, 0.0, -FillerUpperPart_height/2-FillerLowerPart_height/2 );	
	G4Transform3D FillerLowerPart_T		(ZeroRot, FillerLowerPart_V);

	G4UnionSolid *Filler	= new G4UnionSolid(	"Filler",	FillerUpperPart,	FillerLowerPart,	FillerLowerPart_T);
*/
	// Grids
	G4double GridFrame_thick		= 3.0 *mm;
	G4double GridFrame_side			= 84.0 *mm;
	G4double GridFrameCutout_thick	= GridFrame_thick;
	G4double GridFrameCutout_side	= 59.0 *mm;

	G4Box *GridFrameBox		= new G4Box("GridFrameBox", GridFrame_side/2, GridFrame_side/2, GridFrame_thick/2);
	G4Box *GridFrameCutout	= new G4Box("GridFrameCutout", GridFrameCutout_side/2, GridFrameCutout_side/2, GridFrameCutout_thick/2);

	G4ThreeVector GridFrameCutout_V	(0.0, 0.0,	0.0 );	
	G4Transform3D GridFrameCutout_T	(ZeroRot, GridFrameCutout_V);

	G4SubtractionSolid *GridFrame	= new G4SubtractionSolid( "GridFrame",	GridFrameBox,	GridFrameCutout,	GridFrameCutout_T);
	
	// Photomultiplier Tube
	G4double PMTcasing_height	= 32.5 *mm;
	G4double PMTcasing_iR		= 0.0 *mm;
	G4double PMTcasing_oR		= 28.5 *mm;
	G4double PMTcasing_thick	= 0.5 *mm;
	G4double PMTinterior_height	= PMTcasing_height-PMTcasing_thick;
	G4double PMTinterior_iR		= 0.0 *mm;
	G4double PMTinterior_oR		= PMTcasing_oR-PMTcasing_thick;
	G4double PMTcathode_thick	= 0.5 *mm;
	G4double PMTcathode_iR		= 0.0 *mm;
	G4double PMTcathode_oR		= 22.5 *mm;
	G4double PMTwindow_thick	= 1.5 *mm;
	G4double PMTwindow_iR		= 0.0 *mm;
	G4double PMTwindow_oR		= 25.25 *mm;

	G4Tubs *PMTcasing	= new G4Tubs("PMTcasing",	PMTcasing_iR, PMTcasing_oR, PMTcasing_height/2, opendeg, closedeg);
	G4Tubs *PMTinterior	= new G4Tubs("PMTinterior",	PMTinterior_iR, PMTinterior_oR, PMTinterior_height/2, opendeg, closedeg);
	G4Tubs *PMTcathode 	= new G4Tubs("PMTcathode",	PMTcathode_iR, PMTcathode_oR, PMTcathode_thick/2, opendeg, closedeg);
	G4Tubs *PMTwindow	= new G4Tubs("PMTwindow",	PMTwindow_iR, PMTwindow_oR, PMTwindow_thick/2, opendeg, closedeg);

	// PMT base
	G4double PMTbase_thick	= 5.0 *mm;
	G4double PMTbase_iR		= 7.5 *mm;
	G4double PMTbase_oR		= 20.0 *mm;

	G4Tubs *PMTbase	= new G4Tubs("PMTbase", PMTbase_iR, PMTbase_oR, PMTbase_thick/2, opendeg, closedeg);	
	
	
	//==============================================================================================
	//==============	Logical Volumes (declared in 'XuerichDetectorGeometry.hh')	================
	//==============================================================================================
	G4LogicalVolume *Laboratory_log				= new G4LogicalVolume( Laboratory, 				Air, 		"Laboratory_log");

	G4LogicalVolume *ConcreteShield_log			= new G4LogicalVolume(ConcreteShield, 			Concrete, 	"ConcreteShield_log");
	G4LogicalVolume *ConcreteShieldCavity_log	= new G4LogicalVolume(ConcreteShieldCavity, 	Air, 		"ConcreteShieldcavity_log");
	G4LogicalVolume *BPEshield_log				= new G4LogicalVolume(BPEshield, 				BPE, 		"BPEshield_log");
	G4LogicalVolume *ShieldCavity_log			= new G4LogicalVolume(ShieldCavity, 			Air, 		"ShieldCavity_log");
	G4LogicalVolume *ParaffinContainer_log 		= new G4LogicalVolume(ParaffinContainer,		Paraffin, 	"ParaffinContainer_log");
	G4LogicalVolume *Platform_log 				= new G4LogicalVolume(Platform, 				SSteel, 	"Platform_log");
	
	G4LogicalVolume *WallLeft_log 				= new G4LogicalVolume(WallLeft, 				Concrete, 	"WallLeft_log");
	G4LogicalVolume *WallFront_log 				= new G4LogicalVolume(WallFront, 				Concrete, 	"WallFront_log");
	G4LogicalVolume *WallRight_log 				= new G4LogicalVolume(WallRight, 				Concrete, 	"WallRight_log");
	G4LogicalVolume *WallBack_log 				= new G4LogicalVolume(WallBack, 				Concrete, 	"WallBack_log");

	G4LogicalVolume *GeneratorContainer_log 	= new G4LogicalVolume(GeneratorContainer, 		SSteel, 	"GeneratorContainer_log");
	G4LogicalVolume *GeneratorCavity_log 		= new G4LogicalVolume(GeneratorCavity, 			Vacuum, 	"GeneratorCavity_log");

	G4LogicalVolume *scintillator1_log 			= new G4LogicalVolume(scintillator, 			metalAl, 	"scintillator1_log");
	G4LogicalVolume *scintillator2_log 			= new G4LogicalVolume(scintillator, 			metalAl, 	"scintillator2_log");
	G4LogicalVolume *EJ1_log 					= new G4LogicalVolume(EJ, 						EJ301, 		"EJ1_log");
	G4LogicalVolume *EJ2_log 					= new G4LogicalVolume(EJ, 						EJ301, 		"EJ2_log");

	G4LogicalVolume	*OuterCanTube_log			= new G4LogicalVolume( OuterCanTube,			SSteel,		"OuterCanTube_log");
	G4LogicalVolume	*OuterCanBottom_log			= new G4LogicalVolume( OuterCanBottom,			SSteel,		"OuterCanBottom_log");
	G4LogicalVolume	*OuterCanLowerFlange_log	= new G4LogicalVolume( OuterCanLowerFlange,		SSteel,		"OuterCanLowerFlange_log");
	G4LogicalVolume	*OuterCanUpperFlange_log	= new G4LogicalVolume( OuterCanUpperFlange,		SSteel,		"OuterCanUpperFlange_log");

	G4LogicalVolume	*CryostatVacuum_log			= new G4LogicalVolume( CryostatVacuum,			Vacuum,		"CryostatVacuum_log");

	G4LogicalVolume	*InnerCanTube_log			= new G4LogicalVolume( InnerCanTube,			SSteel, 	"InnerCanTube_log");
	G4LogicalVolume	*InnerCanBottom_log			= new G4LogicalVolume( InnerCanBottom,			SSteel, 	"InnerCanBottom_log");
	G4LogicalVolume	*InnerCanLowerFlange_log	= new G4LogicalVolume( InnerCanLowerFlange,		SSteel, 	"InnerCanLowerFlange_log");
	G4LogicalVolume	*InnerCanUpperFlange_log	= new G4LogicalVolume( InnerCanUpperFlange,		SSteel, 	"InnerCanUpperFlange_log");

	G4LogicalVolume	*SteelHolderUpperSquare_log	= new G4LogicalVolume( SteelHolderUpperSquare1,	SSteel, 	"SteelHolderUpperSquare_log");
	G4LogicalVolume	*SteelHolderLowerSquare_log	= new G4LogicalVolume( SteelHolderLowerSquare1,	SSteel, 	"SteelHolderLowerSquare_log");
	G4LogicalVolume	*SteelHolderTube_log		= new G4LogicalVolume( SteelHolderTube,			SSteel, 	"SteelHolderTube_log");

	G4LogicalVolume	* Support1_log				= new G4LogicalVolume( Support,					Teflon, 	"Support1_log");
	G4LogicalVolume	* Support2_log				= new G4LogicalVolume( Support,					Teflon, 	"Support2_log");
	G4LogicalVolume	* Support3_log				= new G4LogicalVolume( Support,					Teflon, 	"Support3_log");
	G4LogicalVolume	* Support4_log				= new G4LogicalVolume( Support,					Teflon,		"Support4_log");

	G4LogicalVolume *Washer1_log				= new G4LogicalVolume( Washer,					Teflon, 	"Washer1_log");
	G4LogicalVolume	*Washer2_log				= new G4LogicalVolume( Washer,					Teflon, 	"Washer2_log");
	G4LogicalVolume	*Washer3_log				= new G4LogicalVolume( Washer,					Teflon, 	"Washer3_log");
	G4LogicalVolume	*Washer4_log				= new G4LogicalVolume( Washer,					Teflon, 	"Washer4_log");

	G4LogicalVolume *TopClamp_log				= new G4LogicalVolume( TopClamp,				Teflon, 	"TopClamp_log");

	G4LogicalVolume	*TopHolderUpperTube_log		= new G4LogicalVolume( TopHolderUpperTube,		Teflon, 	"TopHolderUpperTube_log");
	G4LogicalVolume	*TopHolderLowerTube_log		= new G4LogicalVolume( TopHolderLowerTube,		Teflon, 	"TopHolderLowerTube_log");
	G4LogicalVolume	*TopHolderSquare_log		= new G4LogicalVolume( TopHolderSquare1,		Teflon, 	"TopHolderSquare_log");

	G4LogicalVolume	*ExtractionSpacerUpperHalf_log	= new G4LogicalVolume( ExtractionHalfSpacer,	Teflon, 	"ExtractionSpacerUpperHalf_log");
	G4LogicalVolume *ExtractionSpacerLowerHalf_log	= new G4LogicalVolume( ExtractionHalfSpacer,	Teflon, 	"ExtractionSpacerLowerHalf_log");

	G4LogicalVolume	*DriftSpacerUpperTube_log	= new G4LogicalVolume( DriftSpacerUpperTube,	Teflon, 	"DriftSpacerUpperTube_log");	
	G4LogicalVolume	*DriftSpacerMiddleTube_log	= new G4LogicalVolume( DriftSpacerMiddleTube,	Teflon, 	"DriftSpacerMiddleTube_log");	
	G4LogicalVolume *DriftSpacerLowerTube_log	= new G4LogicalVolume( DriftSpacerLowerTube,	Teflon, 	"DriftSpacerLowerTube_log");	
	G4LogicalVolume	*DriftSpacerUpperSquare_log	= new G4LogicalVolume( DriftSpacerUpperSquare1,	Teflon, 	"DriftSpacerUpperSquare_log");	
	G4LogicalVolume	*DriftSpacerLowerSquare_log	= new G4LogicalVolume( DriftSpacerLowerSquare1,	Teflon, 	"DriftSpacerLowerSquare_log");	

	G4LogicalVolume	*BottomHolderUpperTube_log	= new G4LogicalVolume( BottomHolderUpperTube,	Teflon, 	"BottomHolderUpperTube_log");
	G4LogicalVolume	*BottomHolderMiddleTube_log	= new G4LogicalVolume( BottomHolderMiddleTube,	Teflon, 	"BottomHolderMiddleTube_log");
	G4LogicalVolume	*BottomHolderLowerTube_log	= new G4LogicalVolume( BottomHolderLowerTube,	Teflon, 	"BottomHolderLowerTube_log");

	G4LogicalVolume	*BottomClampUpperPart_log	= new G4LogicalVolume( BottomClampUpperPart,	Teflon, 	"BottomClampUpperPart_log");
	G4LogicalVolume	*BottomClampMiddlePart_log	= new G4LogicalVolume( BottomClampMiddlePart,	Teflon, 	"BottomClampMiddlePart_log");
	G4LogicalVolume	*BottomClampLowerPart_log	= new G4LogicalVolume( BottomClampLowerPart,	Teflon, 	"BottomClampLowerPart_log");

	G4LogicalVolume	*Filler_log					= new G4LogicalVolume( Filler,					Teflon, 	"Filler_log");
	G4LogicalVolume	*topPMTbase_log				= new G4LogicalVolume( PMTbase,					Teflon,		"topPMTbase_log");
	G4LogicalVolume	*bottomPMTbase_log			= new G4LogicalVolume( PMTbase,					Teflon,		"bottomPMTbase_log");

	G4LogicalVolume	*AnodeGrid_log				= new G4LogicalVolume( GridFrame,				SSteel,		"AnodeGrid_log");
	G4LogicalVolume	*CathodeGrid_log			= new G4LogicalVolume( GridFrame,				SSteel,		"CathodeGrid_log");
	G4LogicalVolume	*GateGrid_log				= new G4LogicalVolume( GridFrame,				SSteel,		"GateGrid_log");

	G4LogicalVolume	*topPMTcasing_log			= new G4LogicalVolume( PMTcasing,				SSteel,		"topPMTcasing_log");
	G4LogicalVolume	*topPMTinterior_log			= new G4LogicalVolume( PMTinterior,				Vacuum,		"topPMTinterior_log");
	G4LogicalVolume	*topPMTwindow_log			= new G4LogicalVolume( PMTwindow,				Quartz,		"topPMTwindow_log");
	G4LogicalVolume	*topPMTcathode_log			= new G4LogicalVolume( PMTcathode,				metalAl,	"topPMTcathode_log");

	G4LogicalVolume	*bottomPMTcasing_log		= new G4LogicalVolume( PMTcasing,				SSteel,		"bottomPMTcasing_log");
	G4LogicalVolume *bottomPMTinterior_log		= new G4LogicalVolume( PMTinterior,				Vacuum,		"bottomPMTinterior_log");
	G4LogicalVolume	*bottomPMTwindow_log		= new G4LogicalVolume( PMTwindow,				Quartz,		"bottomPMTwindow_log");
	G4LogicalVolume	*bottomPMTcathode_log		= new G4LogicalVolume( PMTcathode,				metalAl,	"bottomPMTcathode_log");





	//==============================================================================================
	//==============	CONSTRUCTION (Z-dependent from top to bottom)		========================
	//==============================================================================================
	G4double Xuerich_distance	= 1.5 *m;
	G4double Xuerich_x 			= 0 *mm;
	G4double Xuerich_y 			= -ConcreteShield_depth/2 - Xuerich_distance;
	G4double Xuerich_z 			= 1.175 *m;

	G4double Scintillator_distance 	= 1.0 *m;
	G4double ScatterAngle 			= 100;// *deg;
	//G4double Scintillator_x		= Xuerich_x*cos(ScatterAngle*TMath::Pi()/180)-(Xuerich_y-Scintillator_distance)*sin(ScatterAngle*TMath::Pi()/180);
	//G4double Scintillator_y		= Xuerich_x*sin(ScatterAngle*TMath::Pi()/180)+(Xuerich_y-Scintillator_distance)*cos(ScatterAngle*TMath::Pi()/180);
	G4double Scintillator1_x			= Xuerich_x - Scintillator_distance * sin(ScatterAngle*TMath::Pi()/180);
	G4double Scintillator1_y			= Xuerich_y - Scintillator_distance * cos(ScatterAngle*TMath::Pi()/180);
	G4double Scintillator1_z			= 1.175 *m;

	G4double Scintillator2_x			= Xuerich_x + Scintillator_distance * sin(ScatterAngle*TMath::Pi()/180);
	G4double Scintillator2_y			= Xuerich_y - Scintillator_distance * cos(ScatterAngle*TMath::Pi()/180);
	G4double Scintillator2_z			= 1.175 *m;
	
	G4double OuterCanTube_offsetZ = Xuerich_z;

	G4double ConcreteShield_x 	= 0 *mm;
	G4double ConcreteShield_y 	= 0 *mm;
	G4double ConcreteShield_z	= ConcreteShield_height/2;

	G4double ConcreteShieldCavity_x 	= 0.0 *mm;
	G4double ConcreteShieldCavity_y 	= 0.0 *mm;
	G4double ConcreteShieldCavity_z		= -ConcreteShield_height/2+BPEshield_height/2;

	G4double BPEshield_x 	= 0 *mm;
	G4double BPEshield_y 	= 0 *mm;
	G4double BPEshield_z	= 0 *mm;

	G4double ShieldCavity_x = 0 *mm;
	G4double ShieldCavity_y = 0 *mm;
	G4double ShieldCavity_z	= -BPEshield_height/2 + ShieldCavity_height/2;

	G4double Platform_x 	= 0 *mm;
	G4double Platform_y 	= 0 *mm;
	G4double Platform_z		= -ShieldCavity_height/2 + Platform_height/2;

	G4double Paraffin_x 	= 0 *mm;
	G4double Paraffin_y 	= 0 *mm;
	G4double Paraffin_z		= -ShieldCavity_height/2 + Platform_height + ParaffinCylinder_height/2;

	G4double WallLeft_x 	= -ConcreteShield_width/2 + Wall_thick/2 - 589*mm;
	G4double WallLeft_y 	= ConcreteShield_depth/2 - WallLeft_length/2;
	G4double WallLeft_z		= Wall_height/2;

	G4double WallRight_x 	= ConcreteShield_width/2 + Wall_thick/2 + 748*mm;
	G4double WallRight_y 	= -ConcreteShield_depth/2 - WallRight_length/2;
	G4double WallRight_z	= Wall_height/2;

	G4double WallFront_x 	= -ConcreteShield_width/2 - 589*mm + WallFront_length/2 + Wall_thick;
	G4double WallFront_y 	= -ConcreteShield_depth/2 - 3579*mm + Wall_thick/2;
	G4double WallFront_z	= Wall_height/2;

	G4double WallBack_x 	= ConcreteShield_width/2 + WallBack_length/2;
	G4double WallBack_y 	= -ConcreteShield_depth/2 + Wall_thick/2;
	G4double WallBack_z		= Wall_height/2;

	G4double GeneratorContainer_x 	= 0 *mm;
	G4double GeneratorContainer_y 	= 0 *mm;
	G4double GeneratorContainer_z	= Paraffin_z - ParaffinCylinder_height/2 + 750*mm + 68*mm;

	G4double GeneratorCavity_x 	= 0 *mm;
	G4double GeneratorCavity_y 	= 0 *mm;
	G4double GeneratorCavity_z	= GeneratorContainer_height/2 - 475.5*mm;

	G4double	InnerPipes_height					= 101 *mm;
	G4double	PMTpins_length						= 2.0*mm;	
	
	G4double	OuterCanBottom_offsetZ				= OuterCanTube_offsetZ - OuterCanTube_height/2 - OuterCanBottom_thick/2;
	G4double	OuterCanLowerFlange_offsetZ			= OuterCanTube_offsetZ + OuterCanTube_height/2 + OuterCanLowerFlange_thick/2;
	G4double	OuterCanUpperFlange_offsetZ			= OuterCanLowerFlange_offsetZ + OuterCanLowerFlange_thick/2 + OuterCanUpperFlange_thick/2;
	
	G4double	CryostatVacuum_offsetZ				= OuterCanTube_offsetZ;	
	
	G4double	InnerCanUpperFlange_offsetZ			= OuterCanTube_height/2 - InnerPipes_height - InnerCanUpperFlange_thick/2;
	G4double	InnerCanLowerFlange_offsetZ			= InnerCanUpperFlange_offsetZ - InnerCanLowerFlange_thick/2 - InnerCanLowerFlange_thick/2;
	G4double	InnerCanTube_offsetZ				= InnerCanLowerFlange_offsetZ - InnerCanLowerFlange_thick/2 - InnerCanTube_height/2;
	G4double	InnerCanBottom_offsetZ				= InnerCanTube_offsetZ - InnerCanTube_height/2 - InnerCanBottom_thick/2;
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//--------------	XENON	(SCINTILLATOR CONSTRUCTION - needs to be here, sorry( )	------------////
	G4double GXeVol_height = Washer_thick + SteelHolder_height + Support_height + TopHolderTube_height + GridFrame_thick + ExtractionHalfSpacer_height;
	G4double GXeVol_iR		= 0.0 *mm;
	G4double GXeVol_oR		= InnerCanTube_iR;													
																		
	G4double LXeVol_iR		= 0.0 *mm;															
	G4double LXeVol_oR		= InnerCanTube_iR;													
	G4double LXeVol_height	= InnerCanTube_height + InnerCanLowerFlange_thick - GXeVol_height;	
																							
	G4Tubs *LXeVol		= new G4Tubs("LXeVol", LXeVol_iR, LXeVol_oR, LXeVol_height/2, opendeg, closedeg);																		
	G4Tubs *GXeVol		= new G4Tubs("GXeVol", GXeVol_iR, GXeVol_oR, GXeVol_height/2, opendeg, closedeg);
																				
	G4LogicalVolume	*LXeVol_log		= new G4LogicalVolume( LXeVol,		LXe,	"LXeVol_log");
	G4LogicalVolume	*GXeVol_log		= new G4LogicalVolume( GXeVol,		LXe,	"GXeVol_log");
	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////
	
	G4double	GArVol_offsetZ						= InnerCanTube_offsetZ;	
	
	G4double	Washer_offsetZ						= GXeVol_height/2 - Washer_thick/2;
	G4double	Washer1_offsetX						= -35.0 *mm;
	G4double	Washer1_offsetY						=  35.0 *mm;
	G4double	Washer2_offsetX						=  35.0 *mm;
	G4double	Washer2_offsetY						=  35.0 *mm;
	G4double	Washer3_offsetX						= -35.0 *mm;
	G4double	Washer3_offsetY						= -35.0 *mm;
	G4double	Washer4_offsetX						=  35.0 *mm;
	G4double	Washer4_offsetY						= -35.0 *mm;

	G4double	SteelHolderUpperSquare_offsetZ		= Washer_offsetZ - Washer_thick/2 - SteelHolderUpperSquare_thick/2;
	G4double	SteelHolderTube_offsetZ				= Washer_offsetZ - Washer_thick/2 - SteelHolderUpperSquare_thick - SteelHolderTube_height/2;	
	G4double	SteelHolderLowerSquare_offsetZ		= Washer_offsetZ - Washer_thick/2 - SteelHolderUpperSquare_thick - SteelHolderTube_height - SteelHolderLowerSquare_thick/2;		
	
	G4double	Support_offsetZ						= SteelHolderLowerSquare_offsetZ - SteelHolderLowerSquare_thick/2 - Support_height/2;
	G4double	Support1_offsetX					= -35.5 *mm;
	G4double	Support1_offsetY					=  35.5 *mm;
	G4double	Support2_offsetX					=  35.5 *mm;
	G4double	Support2_offsetY					=  35.5 *mm;
	G4double	Support3_offsetX					= -35.5 *mm;
	G4double	Support3_offsetY					= -35.5 *mm;
	G4double	Support4_offsetX					=  35.5 *mm;
	G4double	Support4_offsetY					= -35.5 *mm;

	G4double	TopHolderUpperTube_offsetZ			= Support_offsetZ - Support_height/2 - TopHolderUpperTube_height/2;
	G4double	TopHolderLowerTube_offsetZ			= TopHolderUpperTube_offsetZ - TopHolderUpperTube_height/2 - TopHolderLowerTube_height/2;
	G4double	TopHolderSquare_offsetZ				= TopHolderLowerTube_offsetZ - TopHolderLowerTube_height/2 - TopHolderSquare_thick/2;
	
	G4double	GapForWires							= 0.5 *mm;
	G4double	AnodeGrid_offsetZ					= TopHolderLowerTube_offsetZ - TopHolderLowerTube_height/2 - GridFrame_thick/2;
	G4double	ExtractionSpacerUpperHalf_offsetZ	= AnodeGrid_offsetZ - GridFrame_thick/2 - ExtractionHalfSpacer_height/2;
		
	G4double	ExtractionSpacerLowerHalf_offsetZ	= LXeVol_height/2 - ExtractionHalfSpacer_height/2;
	G4double	GateGrid_offsetZ					= ExtractionSpacerLowerHalf_offsetZ - ExtractionHalfSpacer_height/2 - GridFrame_thick/2;
	
	G4double	DriftSpacerUpperSquare_offsetZ		= GateGrid_offsetZ - GridFrame_thick/2 + DriftSpacerUpperSquare_thick/2;
	G4double	DriftSpacerUpperTube_offsetZ		= DriftSpacerUpperSquare_offsetZ - DriftSpacerUpperSquare_thick/2 - DriftSpacerUpperTube_height/2;
	G4double	DriftSpacerMiddleTube_offsetZ		= DriftSpacerUpperTube_offsetZ - DriftSpacerUpperTube_height/2 - DriftSpacerMiddleTube_height/2;
	G4double	DriftSpacerLowerTube_offsetZ		= DriftSpacerMiddleTube_offsetZ - DriftSpacerMiddleTube_height/2 - DriftSpacerLowerTube_height/2;
	G4double	DriftSpacerLowerSquare_offsetZ		= DriftSpacerLowerTube_offsetZ - DriftSpacerLowerTube_height/2 - DriftSpacerLowerSquare_thick/2;
	
	G4double	CathodeGrid_offsetZ					= DriftSpacerLowerTube_offsetZ - DriftSpacerLowerTube_height/2 - GridFrame_thick/2;

	G4double	BottomHolderUpperTube_offsetZ		= CathodeGrid_offsetZ - GridFrame_thick/2 - BottomHolderUpperTube_height/2;
	G4double	BottomHolderMiddleTube_offsetZ		= BottomHolderUpperTube_offsetZ - BottomHolderUpperTube_height/2 - BottomHolderMiddleTube_height/2;
	G4double	BottomHolderLowerTube_offsetZ		= BottomHolderMiddleTube_offsetZ - BottomHolderMiddleTube_height/2 - BottomHolderLowerTube_height/2;
	
	G4double	Filler_offsetZ						= BottomHolderLowerTube_offsetZ - BottomHolderLowerTube_height/2 + Filler_height/2;
	
	G4double	topPMTcasing_offsetZ				= TopHolderUpperTube_offsetZ - TopHolderUpperTube_height/2 + PMTcasing_height/2;
	G4double	topPMTinterior_offsetZ				= -PMTcasing_height/2 + PMTinterior_height/2;
	G4double	topPMTwindow_offsetZ				= -PMTinterior_height/2 + PMTwindow_thick/2;
	G4double	topPMTcathode_offsetZ				= PMTwindow_thick/2 - PMTcathode_thick/2;
	
	G4double	topPMTbase_offsetZ					= topPMTcasing_offsetZ + PMTcasing_height/2 + PMTpins_length + PMTbase_thick/2;	
	G4double	TopClamp_offsetZ					= topPMTcasing_offsetZ + PMTcasing_height/2 + TopClamp_thick/2;

	G4double	bottomPMTcasing_offsetZ				= BottomHolderMiddleTube_offsetZ + BottomHolderMiddleTube_height/2 - PMTcasing_height/2;
	G4double	bottomPMTinterior_offsetZ			= PMTcasing_height/2 - PMTinterior_height/2;
	G4double	bottomPMTwindow_offsetZ				= PMTinterior_height/2 - PMTwindow_thick/2;
	G4double	bottomPMTcathode_offsetZ			= -PMTwindow_thick/2 + PMTcathode_thick/2;

	G4double	BottomClampUpperPart_offsetZ		= bottomPMTcasing_offsetZ - PMTcasing_height/2 - BottomClampUpperPart_height/2;
	G4double	BottomClampMiddlePart_offsetZ		= BottomClampUpperPart_offsetZ - BottomClampUpperPart_height/2 - BottomClampMiddlePart_height/2;
	G4double	BottomClampLowerPart_offsetZ		= BottomClampMiddlePart_offsetZ - BottomClampMiddlePart_height/2 - BottomClampLowerPart_height/2;
	
	G4double	bottomPMTbase_offsetZ				= bottomPMTcasing_offsetZ - PMTcasing_height/2 - PMTpins_length - PMTbase_thick/2;
	
	/////////////////////////////////////////////////////////////////////////////////////////////
	// TARGET VOLUME
	G4double LXeTarget_iR		= 0.0 *mm;
	G4double LXeTarget_oR		= DriftSpacerMiddleTube_iR;
	//G4double LXeTarget_height	= DriftSpacerLowerSquare_thick + DriftSpacerLowerTube_height + DriftSpacerMiddleTube_height + DriftSpacerUpperTube_height + DriftSpacerUpperSquare_thick;	
	G4double LXeTarget_height	= DriftSpacerLowerTube_height + DriftSpacerMiddleTube_height + DriftSpacerUpperTube_height + ExtractionHalfSpacer_height + GridFrame_thick*2 + BottomHolderUpperTube_height;	

	G4double LXeGate_iR			= 0.0 *mm;															
	G4double LXeGate_oR			= ExtractionSpacer_iR;	
	//G4double LXeGate_height	= ExtractionHalfSpacer_height;	
	G4double LXeGate_height		= ExtractionHalfSpacer_height + GridFrame_thick + TopHolderLowerTube_height;	

	//G4double LXeCathode_iR		= 0.0 *mm;															
	//G4double LXeCathode_oR		= BottomHolderUpperTube_iR;;													
	//G4double LXeCathode_height	= BottomHolderUpperTube_height;	

	G4double LXeVol_offsetZ	= InnerCanTube_offsetZ - InnerCanTube_height/2 + LXeVol_height/2;	
	G4double GXeVol_offsetZ	= InnerCanTube_offsetZ + InnerCanLowerFlange_thick + InnerCanTube_height/2 - GXeVol_height/2;

	//G4double LXeTarget_offsetZ	= DriftSpacerUpperSquare_offsetZ + DriftSpacerUpperSquare_thick/2 - LXeTarget_height/2;
	G4double LXeTarget_offsetZ		= LXeVol_height/2 - LXeTarget_height/2;
	//G4double LXeGate_offsetZ		= ExtractionSpacerLowerHalf_offsetZ;
	G4double LXeGate_offsetZ		= -GXeVol_height/2 + LXeGate_height/2;
	//G4double LXeCathode_offsetZ	= BottomHolderUpperTube_offsetZ;
	
	G4Tubs *LXeTarget	= new G4Tubs("LXeTarget", 	LXeTarget_iR, LXeTarget_oR, LXeTarget_height/2, opendeg, closedeg);																		
	G4Tubs *LXeGate		= new G4Tubs("LXeGate", 	LXeGate_iR, LXeGate_oR, LXeGate_height/2, opendeg, closedeg);																		
	//G4Tubs *LXeCathode	= new G4Tubs("LXeCathode", 	LXeCathode_iR, LXeCathode_oR, LXeCathode_height/2, opendeg, closedeg);																		

	G4LogicalVolume	*LXeTarget_log	= new G4LogicalVolume( LXeTarget,	LXe,	"LXeTarget_log");
	G4LogicalVolume	*LXeGate_log	= new G4LogicalVolume( LXeGate,		LXe,	"LXeGate_log");
	//G4LogicalVolume	*LXeCathode_log	= new G4LogicalVolume( LXeCathode,	LXe,	"LXeCathode_log");
	///////////////////////////////////////////////////////////////////////////////////////////////


	//==============================================================================================
	//==============	Physical Volumes (declared in 'XuerichDetectorGeometry.hh')	================
	//==============================================================================================
	G4PVPlacement *Laboratory_phys			= new G4PVPlacement(0, G4ThreeVector(0, 0, 0), Laboratory_log, "Laboratory_phys", 0, false, 0);

	G4PVPlacement *ConcreteShield_phys 		= new G4PVPlacement(0, G4ThreeVector(ConcreteShield_x, ConcreteShield_y, ConcreteShield_z), ConcreteShield_log, "ConcreteShield_phys", Laboratory_log, false, 0);
	G4PVPlacement *ConcreteShieldCavity_phys= new G4PVPlacement(0, G4ThreeVector(ConcreteShieldCavity_x, ConcreteShieldCavity_y, ConcreteShieldCavity_z), ConcreteShieldCavity_log, "ConcreteShieldCavity_phys", ConcreteShield_log, false, 0);
	G4PVPlacement *BPEshield_phys 			= new G4PVPlacement(0, G4ThreeVector(BPEshield_x, BPEshield_y, BPEshield_z), BPEshield_log, "BPEshield_phys", ConcreteShieldCavity_log, false, 0);
	G4PVPlacement *ShieldCavity_phys 		= new G4PVPlacement(0, G4ThreeVector(ShieldCavity_x, ShieldCavity_y, ShieldCavity_z), ShieldCavity_log, "ShieldCavity_phys", BPEshield_log, false, 0);
	G4PVPlacement *Platform_phys 			= new G4PVPlacement(0, G4ThreeVector(Platform_x, Platform_y, Platform_z), Platform_log, "Platform_phys", ShieldCavity_log, false, 0);
	G4PVPlacement *ParaffinContainer_phys 	= new G4PVPlacement(0, G4ThreeVector(Paraffin_x, Paraffin_y, Paraffin_z), ParaffinContainer_log, "ParaffinContainer_phys", ShieldCavity_log, false, 0);
	G4PVPlacement *WallLeft_phys 			= new G4PVPlacement(0, G4ThreeVector(WallLeft_x, WallLeft_y, WallLeft_z), WallLeft_log, "WallLeft_phys", Laboratory_log, false, 0);
	G4PVPlacement *WallRight_phys 			= new G4PVPlacement(0, G4ThreeVector(WallRight_x, WallRight_y, WallRight_z), WallRight_log, "WallRight_phys", Laboratory_log, false, 0);
	G4PVPlacement *WallFront_phys 			= new G4PVPlacement(0, G4ThreeVector(WallFront_x, WallFront_y, WallFront_z), WallFront_log, "WallFront_phys", Laboratory_log, false, 0);
	G4PVPlacement *WallBack_phys 			= new G4PVPlacement(0, G4ThreeVector(WallBack_x, WallBack_y, WallBack_z), WallBack_log, "WallBack_phys", Laboratory_log, false, 0);
	G4PVPlacement *GeneratorContainer_phys 	= new G4PVPlacement(0, G4ThreeVector(GeneratorContainer_x, GeneratorContainer_y, GeneratorContainer_z), GeneratorContainer_log, "GeneratorContainer_phys", ShieldCavity_log, false, 0);
	G4PVPlacement *GeneratorCavity_phys 	= new G4PVPlacement(0, G4ThreeVector(GeneratorCavity_x, GeneratorCavity_y, GeneratorCavity_z), GeneratorCavity_log, "GeneratorCavity_phys", GeneratorContainer_log, false, 0);

	G4PVPlacement *scintillator1_phys 		= new G4PVPlacement(0, G4ThreeVector(Scintillator1_x, Scintillator1_y, Scintillator1_z), scintillator1_log,"scintillator1_phys", Laboratory_log, false, 0);
	G4PVPlacement *scintillator2_phys 		= new G4PVPlacement(0, G4ThreeVector(Scintillator2_x, Scintillator2_y, Scintillator2_z), scintillator2_log,"scintillator2_phys", Laboratory_log, false, 0);
	G4PVPlacement *EJ1_phys 				= new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), EJ1_log, "EJ1_phys", scintillator1_log, false, 0);
	G4PVPlacement *EJ2_phys 				= new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), EJ2_log, "EJ2_phys", scintillator2_log, false, 0);

	G4PVPlacement *OuterCanTube_phys		= new G4PVPlacement(0, G4ThreeVector(Xuerich_x, Xuerich_y, Xuerich_z), OuterCanTube_log, "OuterCanTube_phys", Laboratory_log, false, 0);
	G4PVPlacement *OuterCanBottom_phys		= new G4PVPlacement(0, G4ThreeVector(Xuerich_x, Xuerich_y, OuterCanBottom_offsetZ),	OuterCanBottom_log, "OuterCanBottom_phys", Laboratory_log, false, 0);
	G4PVPlacement *OuterCanLowerFlange_phys	= new G4PVPlacement(0, G4ThreeVector(Xuerich_x, Xuerich_y, OuterCanLowerFlange_offsetZ), OuterCanLowerFlange_log, "OuterCanLowerFlange_phys", Laboratory_log, false, 0);
	G4PVPlacement *OuterCanUpperFlange_phys	= new G4PVPlacement(0, G4ThreeVector(Xuerich_x, Xuerich_y, OuterCanUpperFlange_offsetZ), OuterCanUpperFlange_log, "OuterCanUpperFlange_phys", Laboratory_log, false, 0);
	G4PVPlacement *CryostatVacuum_phys		= new G4PVPlacement(0, G4ThreeVector(Xuerich_x, Xuerich_y, CryostatVacuum_offsetZ), CryostatVacuum_log, "CryostatVacuum_phys",	Laboratory_log,	false, 0);
	G4PVPlacement *InnerCanTube_phys		= new G4PVPlacement(0, G4ThreeVector(0, 0, InnerCanTube_offsetZ), InnerCanTube_log, "InnerCanTube_phys", CryostatVacuum_log, false, 0);
	G4PVPlacement *InnerCanBottom_phys		= new G4PVPlacement(0, G4ThreeVector(0, 0, InnerCanBottom_offsetZ),	InnerCanBottom_log, "InnerCanBottom_phys", CryostatVacuum_log, false, 0);
	G4PVPlacement *InnerCanLowerFlange_phys	= new G4PVPlacement(0, G4ThreeVector(0, 0, InnerCanLowerFlange_offsetZ), InnerCanLowerFlange_log, "InnerCanLowerFlange_phys", CryostatVacuum_log, false, 0);
	G4PVPlacement *InnerCanUpperFlange_phys	= new G4PVPlacement(0, G4ThreeVector(0, 0, InnerCanUpperFlange_offsetZ), InnerCanUpperFlange_log, "InnerCanUpperFlange_phys", CryostatVacuum_log, false, 0);

	G4PVPlacement *LXeVol_phys				= new G4PVPlacement(0, G4ThreeVector(0, 0, LXeVol_offsetZ),	LXeVol_log, "LXeVol_phys", CryostatVacuum_log, false, 0);
	G4PVPlacement *GXeVol_phys				= new G4PVPlacement(0, G4ThreeVector(0, 0, GXeVol_offsetZ),	GXeVol_log, "GXeVol_phys", CryostatVacuum_log, false, 0);
	G4PVPlacement *LXeTarget_phys			= new G4PVPlacement(0, G4ThreeVector(0, 0, LXeTarget_offsetZ),	LXeTarget_log, "LXeTarget_phys", LXeVol_log, false, 0);
	G4PVPlacement *LXeGate_phys				= new G4PVPlacement(0, G4ThreeVector(0, 0, LXeGate_offsetZ),	LXeGate_log, "LXeGate_phys", GXeVol_log, false, 0);
	//G4PVPlacement *LXeCathode_phys			= new G4PVPlacement(0, G4ThreeVector(0, 0, LXeCathode_offsetZ),	LXeCathode_log, "LXeCathode_phys", LXeVol_log, false, 0);

	G4PVPlacement *Washer1_phys						= new G4PVPlacement(0, G4ThreeVector(Washer1_offsetX, Washer1_offsetY, Washer_offsetZ), Washer1_log, "Washer1_phys", GXeVol_log, false, 0);
	G4PVPlacement *Washer2_phys						= new G4PVPlacement(0, G4ThreeVector(Washer2_offsetX, Washer2_offsetY, Washer_offsetZ), Washer2_log, "Washer2_phys", GXeVol_log, false, 0);
	G4PVPlacement *Washer3_phys						= new G4PVPlacement(0, G4ThreeVector(Washer3_offsetX, Washer3_offsetY, Washer_offsetZ), Washer3_log, "Washer3_phys", GXeVol_log, false, 0);
	G4PVPlacement *Washer4_phys						= new G4PVPlacement(0, G4ThreeVector(Washer4_offsetX, Washer4_offsetY, Washer_offsetZ), Washer4_log, "Washer4_phys", GXeVol_log, false, 0);
	G4PVPlacement *SteelHolderUpperSquare_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, SteelHolderUpperSquare_offsetZ), SteelHolderUpperSquare_log,	"SteelHolderUpperSquare_phys", GXeVol_log, false, 0);
	G4PVPlacement *SteelHolder_phys					= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, SteelHolderTube_offsetZ), SteelHolderTube_log, "SteelHolderTube_phys", GXeVol_log, false, 0);	
	G4PVPlacement *SteelHolderLowerSquare_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, SteelHolderLowerSquare_offsetZ),	SteelHolderLowerSquare_log,	"SteelHolderLowerSquare_phys", GXeVol_log, false, 0);
	G4PVPlacement *Support1_phys					= new G4PVPlacement(0, G4ThreeVector(Support1_offsetX, Support1_offsetY, Support_offsetZ), Support1_log, "Support1_phys", GXeVol_log, false, 0);
	G4PVPlacement *Support2_phys					= new G4PVPlacement(0, G4ThreeVector(Support2_offsetX, Support2_offsetY, Support_offsetZ), Support2_log, "Support2_phys", GXeVol_log, false, 0);
	G4PVPlacement *Support3_phys					= new G4PVPlacement(0, G4ThreeVector(Support3_offsetX, Support3_offsetY, Support_offsetZ), Support1_log, "Support3_phys", GXeVol_log, false, 0);
	G4PVPlacement *Support4_phys					= new G4PVPlacement(0, G4ThreeVector(Support4_offsetX,	Support4_offsetY,	Support_offsetZ),	Support4_log, "Support4_phys", GXeVol_log, false, 0);
	G4PVPlacement *TopClamp_phys					= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, TopClamp_offsetZ), TopClamp_log, "TopClamp_phys", GXeVol_log, false, 0);
	G4PVPlacement *TopHolderUpperTube_phys			= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, TopHolderUpperTube_offsetZ),	TopHolderUpperTube_log, "TopHolderUpperTube_phys", GXeVol_log, false, 0);
	G4PVPlacement *TopHolderLowerTube_phys			= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, TopHolderLowerTube_offsetZ),	TopHolderLowerTube_log, "TopHolderLowerTube_phys", GXeVol_log, false, 0);
	G4PVPlacement *TopHolderSquare_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, TopHolderSquare_offsetZ), TopHolderSquare_log, "TopHolderSquare_phys", GXeVol_log, false, 0);
	G4PVPlacement *AnodeGrid_phys					= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, AnodeGrid_offsetZ), AnodeGrid_log, "AnodeGrid_phys", GXeVol_log, false, 0);
	G4PVPlacement *ExtractionSpacerUpperHalf_phys	= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, ExtractionSpacerUpperHalf_offsetZ), ExtractionSpacerUpperHalf_log, "ExtractionSpacerUpperHalf_phys",	GXeVol_log, false, 0);

	G4PVPlacement *ExtractionSpacerLowerHalf_phys	= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, ExtractionSpacerLowerHalf_offsetZ), ExtractionSpacerLowerHalf_log,	"ExtractionSpacerLowerHalf_phys",	LXeVol_log,		false, 0);
	G4PVPlacement *GateGrid_phys					= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, GateGrid_offsetZ), GateGrid_log, "GateGrid_phys", LXeVol_log, false, 0);
	G4PVPlacement *DriftSpacerUpperSquare_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, DriftSpacerUpperSquare_offsetZ),	DriftSpacerUpperSquare_log, "DriftSpacerUpperSquare_phys", LXeVol_log, false, 0);
	G4PVPlacement *DriftSpacerUpperTube_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, DriftSpacerUpperTube_offsetZ), DriftSpacerUpperTube_log, "DriftSpacerUpperTube_phys", LXeVol_log, false, 0);
	G4PVPlacement *DriftSpacerMiddleTube_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, DriftSpacerMiddleTube_offsetZ), DriftSpacerMiddleTube_log, "DriftSpacerMiddleTube_phys", LXeVol_log, false, 0);	
	G4PVPlacement *DriftSpacerLowerTube_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, DriftSpacerLowerTube_offsetZ), DriftSpacerLowerTube_log, "DriftSpacerLowerTube_phys", LXeVol_log, false, 0);
	G4PVPlacement *DriftSpacerLowerSquare_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, DriftSpacerLowerSquare_offsetZ), DriftSpacerLowerSquare_log, "DriftSpacerLowerSquare_phys", LXeVol_log, false, 0);
	G4PVPlacement *CathodeGrid_phys					= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, CathodeGrid_offsetZ), CathodeGrid_log, "CathodeGrid_phys", LXeVol_log, false, 0);
	G4PVPlacement *BottomHolderUpperTube_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, BottomHolderUpperTube_offsetZ), BottomHolderUpperTube_log, "BottomHolderUpperTube_phys", LXeVol_log, false, 0);
	G4PVPlacement *BottomHolderMiddleTube_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, BottomHolderMiddleTube_offsetZ), BottomHolderMiddleTube_log, "BottomHolderMiddleTube_phys", LXeVol_log, false, 0);
	G4PVPlacement *BottomHolderLowerTube_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, BottomHolderLowerTube_offsetZ), BottomHolderLowerTube_log, "BottomHolderLowerTube_phys", LXeVol_log, false, 0);
	G4PVPlacement *Filler_phys						= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, Filler_offsetZ),	Filler_log, "Filler_phys", LXeVol_log, false, 0);
	G4PVPlacement *BottomClampUpperPart_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, BottomClampUpperPart_offsetZ), BottomClampUpperPart_log, "BottomClampUpperPart_phys", LXeVol_log, false, 0);
	G4PVPlacement *BottomClampMiddlePart_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, BottomClampMiddlePart_offsetZ), BottomClampMiddlePart_log, "BottomClampMiddlePart_phys", LXeVol_log, false, 0);
	G4PVPlacement *BottomClampLowerPart_phys		= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, BottomClampLowerPart_offsetZ), BottomClampLowerPart_log, "BottomClampLowerPart_phys", LXeVol_log, false, 0);

	G4PVPlacement *topPMTcasing_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, topPMTcasing_offsetZ), topPMTcasing_log, "topPMTcasing_phys", GXeVol_log, false, 0);
	G4PVPlacement *topPMTinterior_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, topPMTinterior_offsetZ), topPMTinterior_log, "topPMTinterior_phys", topPMTcasing_log, false, 0);
	G4PVPlacement *topPMTwindow_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, topPMTwindow_offsetZ), topPMTwindow_log, "topPMTwindow_phys", topPMTinterior_log, false, 0);
	G4PVPlacement *topPMTcathode_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, topPMTcathode_offsetZ), topPMTcathode_log, "topPMTcathode_phys",	topPMTwindow_log, false, 0);
	G4PVPlacement *bottomPMTcasing_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, bottomPMTcasing_offsetZ), bottomPMTcasing_log, "bottomPMTcasing_phys", LXeVol_log, false, 0);
	G4PVPlacement *bottomPMTinterior_phys			= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, bottomPMTinterior_offsetZ), bottomPMTinterior_log, "bottomPMTinterior_phys",	bottomPMTcasing_log, false, 0);
	G4PVPlacement *bottomPMTwindow_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, bottomPMTwindow_offsetZ), bottomPMTwindow_log, "bottomPMTwindow_phys", bottomPMTinterior_log, false, 0);
	G4PVPlacement *bottomPMTcathode_phys			= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, bottomPMTcathode_offsetZ), bottomPMTcathode_log, "bottomPMTcathode_phys", bottomPMTwindow_log, false, 0);
	G4PVPlacement *topPMTbase_phys					= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, topPMTbase_offsetZ),	topPMTbase_log, "topPMTbase_phys",	GXeVol_log, false, 0);
	G4PVPlacement *bottomPMTbase_phys				= new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, bottomPMTbase_offsetZ), bottomPMTbase_log, "bottomPMTbase_phys",	LXeVol_log, false, 0);


/*	//==============================================================================================
	//==============	Visual Attributes	========================================================
	//==============================================================================================
	Laboratory_log			->SetVisAttributes(G4VisAttributes::Invisible);
	CryostatVacuum_log		->SetVisAttributes(G4VisAttributes::Invisible);
	topPMTinterior_log		->SetVisAttributes(G4VisAttributes::Invisible);
	bottomPMTinterior_log	->SetVisAttributes(G4VisAttributes::Invisible);

	//OuterCan_log			->SetVisAttributes(G4VisAttributes::Invisible);
	//InnerCan_log			->SetVisAttributes(G4VisAttributes::Invisible);

	//ConcreteShield_log	->SetVisAttributes(G4VisAttributes::Invisible);		
	//BPEshield_log		->SetVisAttributes(G4VisAttributes::Invisible);		
	//ShieldCavity_log	->SetVisAttributes(G4VisAttributes::Invisible);		
	//WallLeft_log		->SetVisAttributes(G4VisAttributes::Invisible);
	//WallRight_log		->SetVisAttributes(G4VisAttributes::Invisible);
	//WallFront_log		->SetVisAttributes(G4VisAttributes::Invisible);
	//WallBack_log		->SetVisAttributes(G4VisAttributes::Invisible);
	//Scintillator_log	->SetVisAttributes(G4VisAttributes::Invisible);

	G4VisAttributes *Concrete_vis = new G4VisAttributes(grey);
	Concrete_vis	->SetVisibility(true);
	Concrete_vis	->SetForceSolid(false);
		ConcreteShield_log	->SetVisAttributes(Concrete_vis);
		WallLeft_log		->SetVisAttributes(Concrete_vis);
		WallRight_log		->SetVisAttributes(Concrete_vis);
		WallFront_log		->SetVisAttributes(Concrete_vis);
		WallBack_log		->SetVisAttributes(Concrete_vis);
	
	G4VisAttributes *BPE_vis = new G4VisAttributes(white);
	BPE_vis	->SetVisibility(true);
	BPE_vis	->SetForceSolid(false);
		BPEshield_log	->SetVisAttributes(BPE_vis);

	G4VisAttributes *Cavity_vis = new G4VisAttributes(lgrey);
	Cavity_vis	->SetVisibility(true);
	Cavity_vis	->SetForceSolid(false);
		ShieldCavity_log			->SetVisAttributes(Cavity_vis);
		ConcreteShieldCavity_log	->SetVisAttributes(Cavity_vis);
		
	G4VisAttributes *Paraffin_vis = new G4VisAttributes(blue);
	Paraffin_vis	->SetVisibility(true);
	Paraffin_vis	->SetForceSolid(false);
		ParaffinContainer_log	->SetVisAttributes(Paraffin_vis);

	G4VisAttributes *Steel_vis = new G4VisAttributes(grey);
	Steel_vis	->SetVisibility(true);
	Steel_vis	->SetForceSolid(false);
		Platform_log	->SetVisAttributes(Steel_vis);

	G4VisAttributes *GeneratorContainer_vis = new G4VisAttributes(xlred);
	GeneratorContainer_vis	->SetVisibility(true);
	GeneratorContainer_vis	->SetForceSolid(false);
		GeneratorContainer_log	->SetVisAttributes(GeneratorContainer_vis);

		// SENSITIVE VOLUMES
		LXeVol_log		->SetVisAttributes(GeneratorContainer_vis);
		LXeTarget_log	->SetVisAttributes(GeneratorContainer_vis);
		LXeGate_log		->SetVisAttributes(GeneratorContainer_vis);
		//LXeCathode_log	->SetVisAttributes(GeneratorContainer_vis);

	G4VisAttributes *GeneratorCavity_vis = new G4VisAttributes(xlgreen);
	GeneratorCavity_vis	->SetVisibility(true);
	GeneratorCavity_vis	->SetForceSolid(false);
		GeneratorCavity_log	->SetVisAttributes(GeneratorCavity_vis);
	
	G4VisAttributes	*Teflon_vis	= new G4VisAttributes(magenta);
	Teflon_vis	->SetVisibility(true);
	Teflon_vis	->SetForceSolid(false);
		Washer1_log						->SetVisAttributes(Teflon_vis);
		Washer2_log						->SetVisAttributes(Teflon_vis);
		Washer3_log						->SetVisAttributes(Teflon_vis);
		Washer4_log						->SetVisAttributes(Teflon_vis);
		Support1_log					->SetVisAttributes(Teflon_vis);
		Support2_log					->SetVisAttributes(Teflon_vis);
		Support3_log					->SetVisAttributes(Teflon_vis);
		Support4_log					->SetVisAttributes(Teflon_vis);
		TopClamp_log					->SetVisAttributes(Teflon_vis);
		TopHolderUpperTube_log			->SetVisAttributes(Teflon_vis);
		TopHolderLowerTube_log			->SetVisAttributes(Teflon_vis);
		TopHolderSquare_log				->SetVisAttributes(Teflon_vis);
		ExtractionSpacerUpperHalf_log	->SetVisAttributes(Teflon_vis);
		ExtractionSpacerLowerHalf_log	->SetVisAttributes(Teflon_vis);
		DriftSpacerUpperSquare_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerUpperTube_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerMiddleTube_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerLowerTube_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerLowerSquare_log		->SetVisAttributes(Teflon_vis);
		BottomHolderUpperTube_log		->SetVisAttributes(Teflon_vis);
		BottomHolderMiddleTube_log		->SetVisAttributes(Teflon_vis);
		BottomHolderLowerTube_log		->SetVisAttributes(Teflon_vis);
		Filler_log						->SetVisAttributes(Teflon_vis);
		BottomClampUpperPart_log		->SetVisAttributes(Teflon_vis);
		BottomClampMiddlePart_log		->SetVisAttributes(Teflon_vis);
		BottomClampLowerPart_log		->SetVisAttributes(Teflon_vis);
		topPMTbase_log					->SetVisAttributes(Teflon_vis);
		bottomPMTbase_log				->SetVisAttributes(Teflon_vis);
		
	G4VisAttributes *Cryostat_vis = new G4VisAttributes(xlblue);
	Cryostat_vis	->SetVisibility(true);
	Cryostat_vis	->SetForceSolid(false);
		OuterCanTube_log		->SetVisAttributes(Cryostat_vis);
		OuterCanBottom_log		->SetVisAttributes(Cryostat_vis);
		OuterCanLowerFlange_log	->SetVisAttributes(Cryostat_vis);
		OuterCanUpperFlange_log	->SetVisAttributes(Cryostat_vis);
		InnerCanTube_log		->SetVisAttributes(Cryostat_vis);
		InnerCanBottom_log		->SetVisAttributes(Cryostat_vis);
		InnerCanLowerFlange_log	->SetVisAttributes(Cryostat_vis);
		InnerCanUpperFlange_log	->SetVisAttributes(Cryostat_vis);

	G4VisAttributes	*SteelHolder_vis = new G4VisAttributes(blue);
	SteelHolder_vis	->SetVisibility(true);
	SteelHolder_vis	->SetForceSolid(false);	
		SteelHolderTube_log			->SetVisAttributes(SteelHolder_vis);
		SteelHolderUpperSquare_log	->SetVisAttributes(SteelHolder_vis);
		SteelHolderLowerSquare_log	->SetVisAttributes(SteelHolder_vis);
		
	G4VisAttributes	*PMTcasing_vis = new G4VisAttributes(cyan);
	PMTcasing_vis	->SetVisibility(true);
	PMTcasing_vis	->SetForceSolid(false);
		topPMTcasing_log	->SetVisAttributes(PMTcasing_vis);	
		bottomPMTcasing_log	->SetVisAttributes(PMTcasing_vis);	

	G4VisAttributes	*PMTinterior_vis = new G4VisAttributes(grey);
	PMTinterior_vis	->SetVisibility(true);
	PMTinterior_vis	->SetForceSolid(false);
		//topPMTinterior_log		->SetVisAttributes(PMTinterior_vis);	
		//bottomPMTinterior_log	->SetVisAttributes(PMTinterior_vis);	

	G4VisAttributes	* PMTwindow_vis	= new G4VisAttributes(grey);
	PMTwindow_vis	->SetVisibility(true);
	PMTwindow_vis	->SetForceSolid(false);
		topPMTwindow_log	->SetVisAttributes(PMTwindow_vis);
		bottomPMTwindow_log	->SetVisAttributes(PMTwindow_vis);

	G4VisAttributes	*PMTcathode_vis	= new G4VisAttributes(xlgreen);
	PMTcathode_vis	->SetVisibility(true);
	PMTcathode_vis	->SetForceSolid(false);
		topPMTcathode_log		->SetVisAttributes(PMTcathode_vis);
		bottomPMTcathode_log	->SetVisAttributes(PMTcathode_vis);
		
	G4VisAttributes	*Grids_vis = new G4VisAttributes(blue);
	Grids_vis	->SetVisibility(true);
	Grids_vis	->SetForceSolid(false);
		AnodeGrid_log	->SetVisAttributes(Grids_vis);
		GateGrid_log	->SetVisAttributes(Grids_vis);
		CathodeGrid_log	->SetVisAttributes(Grids_vis);
		
*/


	// Visual Attributes (CRYOSTAT ONLY)
	Laboratory_log			->SetVisAttributes(G4VisAttributes::Invisible);
	CryostatVacuum_log		->SetVisAttributes(G4VisAttributes::Invisible);
	topPMTinterior_log		->SetVisAttributes(G4VisAttributes::Invisible);
	bottomPMTinterior_log	->SetVisAttributes(G4VisAttributes::Invisible);

	OuterCanTube_log		->SetVisAttributes(G4VisAttributes::Invisible);
	OuterCanBottom_log		->SetVisAttributes(G4VisAttributes::Invisible);
	OuterCanLowerFlange_log	->SetVisAttributes(G4VisAttributes::Invisible);
	OuterCanUpperFlange_log	->SetVisAttributes(G4VisAttributes::Invisible);

	ConcreteShield_log		->SetVisAttributes(G4VisAttributes::Invisible);		
	BPEshield_log			->SetVisAttributes(G4VisAttributes::Invisible);		
	ShieldCavity_log		->SetVisAttributes(G4VisAttributes::Invisible);		
	ConcreteShieldCavity_log->SetVisAttributes(G4VisAttributes::Invisible);		
	GeneratorContainer_log	->SetVisAttributes(G4VisAttributes::Invisible);		
	GeneratorCavity_log		->SetVisAttributes(G4VisAttributes::Invisible);		
	WallLeft_log			->SetVisAttributes(G4VisAttributes::Invisible);
	WallRight_log			->SetVisAttributes(G4VisAttributes::Invisible);
	WallFront_log			->SetVisAttributes(G4VisAttributes::Invisible);
	WallBack_log			->SetVisAttributes(G4VisAttributes::Invisible);
	ParaffinContainer_log	->SetVisAttributes(G4VisAttributes::Invisible);
	Platform_log			->SetVisAttributes(G4VisAttributes::Invisible);
		
	scintillator1_log	->SetVisAttributes(G4VisAttributes::Invisible);
	scintillator2_log	->SetVisAttributes(G4VisAttributes::Invisible);
	EJ1_log				->SetVisAttributes(G4VisAttributes::Invisible);
	EJ2_log				->SetVisAttributes(G4VisAttributes::Invisible);

	G4VisAttributes *LXe_vis = new G4VisAttributes(xlred);
	LXe_vis	->SetVisibility(true);
	LXe_vis	->SetForceSolid(false);

	LXeVol_log		->SetVisAttributes(LXe_vis);
	GXeVol_log		->SetVisAttributes(LXe_vis);
	
	G4VisAttributes	*Teflon_vis	= new G4VisAttributes(magenta);
	Teflon_vis	->SetVisibility(true);
	Teflon_vis	->SetForceSolid(false);
		Washer1_log						->SetVisAttributes(Teflon_vis);
		Washer2_log						->SetVisAttributes(Teflon_vis);
		Washer3_log						->SetVisAttributes(Teflon_vis);
		Washer4_log						->SetVisAttributes(Teflon_vis);
		Support1_log					->SetVisAttributes(Teflon_vis);
		Support2_log					->SetVisAttributes(Teflon_vis);
		Support3_log					->SetVisAttributes(Teflon_vis);
		Support4_log					->SetVisAttributes(Teflon_vis);
		TopClamp_log					->SetVisAttributes(Teflon_vis);
		TopHolderUpperTube_log			->SetVisAttributes(Teflon_vis);
		TopHolderLowerTube_log			->SetVisAttributes(Teflon_vis);
		TopHolderSquare_log				->SetVisAttributes(Teflon_vis);
		ExtractionSpacerUpperHalf_log	->SetVisAttributes(Teflon_vis);
		ExtractionSpacerLowerHalf_log	->SetVisAttributes(Teflon_vis);
		DriftSpacerUpperSquare_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerUpperTube_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerMiddleTube_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerLowerTube_log		->SetVisAttributes(Teflon_vis);
		DriftSpacerLowerSquare_log		->SetVisAttributes(Teflon_vis);
		BottomHolderUpperTube_log		->SetVisAttributes(Teflon_vis);
		BottomHolderMiddleTube_log		->SetVisAttributes(Teflon_vis);
		BottomHolderLowerTube_log		->SetVisAttributes(Teflon_vis);
		Filler_log						->SetVisAttributes(Teflon_vis);
		BottomClampUpperPart_log		->SetVisAttributes(Teflon_vis);
		BottomClampMiddlePart_log		->SetVisAttributes(Teflon_vis);
		BottomClampLowerPart_log		->SetVisAttributes(Teflon_vis);
		topPMTbase_log					->SetVisAttributes(Teflon_vis);
		bottomPMTbase_log				->SetVisAttributes(Teflon_vis);
		
	G4VisAttributes *Cryostat_vis = new G4VisAttributes(xlblue);
	Cryostat_vis	->SetVisibility(true);
	Cryostat_vis	->SetForceSolid(false);
		InnerCanTube_log		->SetVisAttributes(Cryostat_vis);
		InnerCanBottom_log		->SetVisAttributes(Cryostat_vis);
		InnerCanLowerFlange_log	->SetVisAttributes(Cryostat_vis);
		InnerCanUpperFlange_log	->SetVisAttributes(Cryostat_vis);

	G4VisAttributes	*SteelHolder_vis = new G4VisAttributes(blue);
	SteelHolder_vis	->SetVisibility(true);
	SteelHolder_vis	->SetForceSolid(false);	
		SteelHolderTube_log			->SetVisAttributes(SteelHolder_vis);
		SteelHolderUpperSquare_log	->SetVisAttributes(SteelHolder_vis);
		SteelHolderLowerSquare_log	->SetVisAttributes(SteelHolder_vis);
		
	G4VisAttributes	*PMTcasing_vis = new G4VisAttributes(cyan);
	PMTcasing_vis	->SetVisibility(true);
	PMTcasing_vis	->SetForceSolid(false);
		topPMTcasing_log	->SetVisAttributes(PMTcasing_vis);	
		bottomPMTcasing_log	->SetVisAttributes(PMTcasing_vis);	

	G4VisAttributes	*PMTinterior_vis = new G4VisAttributes(grey);
	PMTinterior_vis	->SetVisibility(true);
	PMTinterior_vis	->SetForceSolid(false);
		//topPMTinterior_log		->SetVisAttributes(PMTinterior_vis);	
		//bottomPMTinterior_log	->SetVisAttributes(PMTinterior_vis);	

	G4VisAttributes	* PMTwindow_vis	= new G4VisAttributes(grey);
	PMTwindow_vis	->SetVisibility(true);
	PMTwindow_vis	->SetForceSolid(false);
		topPMTwindow_log	->SetVisAttributes(PMTwindow_vis);
		bottomPMTwindow_log	->SetVisAttributes(PMTwindow_vis);

	G4VisAttributes	*PMTcathode_vis	= new G4VisAttributes(xlgreen);
	PMTcathode_vis	->SetVisibility(true);
	PMTcathode_vis	->SetForceSolid(false);
		topPMTcathode_log		->SetVisAttributes(PMTcathode_vis);
		bottomPMTcathode_log	->SetVisAttributes(PMTcathode_vis);
		
	G4VisAttributes	*Grids_vis = new G4VisAttributes(blue);
	Grids_vis	->SetVisibility(true);
	Grids_vis	->SetForceSolid(false);
		AnodeGrid_log	->SetVisAttributes(Grids_vis);
		GateGrid_log	->SetVisAttributes(Grids_vis);
		CathodeGrid_log	->SetVisAttributes(Grids_vis);
		

//--------------	DETECTOR DESCRIPTION	------------
	G4double Mass_Laboratory				= Laboratory_log				->GetMass(false, false, 0)/kg;	
	G4double Mass_OuterCanTube				= OuterCanTube_log				->GetMass(false, false, 0)/kg;		
	G4double Mass_OuterCanBottom			= OuterCanBottom_log			->GetMass(false, false, 0)/kg;		
	G4double Mass_OuterCanLowerFlange		= OuterCanLowerFlange_log		->GetMass(false, false, 0)/kg;		
	G4double Mass_OuterCanUpperFlange		= OuterCanUpperFlange_log		->GetMass(false, false, 0)/kg;		
	G4double Mass_InnerCanTube				= InnerCanTube_log				->GetMass(false, false, 0)/kg;
	G4double Mass_InnerCanBottom			= InnerCanBottom_log			->GetMass(false, false, 0)/kg;
	G4double Mass_InnerCanLowerFlange		= InnerCanLowerFlange_log		->GetMass(false, false, 0)/kg;
	G4double Mass_InnerCanUpperFlange		= InnerCanUpperFlange_log		->GetMass(false, false, 0)/kg;
	G4double Mass_SteelHolderUpperSquare	= SteelHolderUpperSquare_log	->GetMass(false, false, 0)/kg;		
	G4double Mass_SteelHolderLowerSquare	= SteelHolderLowerSquare_log	->GetMass(false, false, 0)/kg;		
	G4double Mass_SteelHolderTube			= SteelHolderTube_log			->GetMass(false, false, 0)/kg;		
	G4double Mass_Support					= Support1_log					->GetMass(false, false, 0)/kg;
	G4double Mass_Washer					= Washer1_log					->GetMass(false, false, 0)/kg;
	G4double Mass_TopClamp					= TopClamp_log					->GetMass(false, false, 0)/kg;
	G4double Mass_TopHolderUpperTube		= TopHolderUpperTube_log		->GetMass(false, false, 0)/kg;
	G4double Mass_TopHolderLowerTube		= TopHolderLowerTube_log		->GetMass(false, false, 0)/kg;
	G4double Mass_TopHolderSquare			= TopHolderSquare_log			->GetMass(false, false, 0)/kg;
	G4double Mass_AnodeGrid					= AnodeGrid_log					->GetMass(false, false, 0)/kg;
	G4double Mass_ExtractionSpacerUpperHalf	= ExtractionSpacerUpperHalf_log	->GetMass(false, false, 0)/kg;
	G4double Mass_ExtractionSpacerLowerHalf	= ExtractionSpacerLowerHalf_log	->GetMass(false, false, 0)/kg;
	G4double Mass_GateGrid					= GateGrid_log					->GetMass(false, false, 0)/kg;	
	G4double Mass_DriftSpacerUpperSquare	= DriftSpacerUpperSquare_log	->GetMass(false, false, 0)/kg;
	G4double Mass_DriftSpacerUpperTube		= DriftSpacerUpperTube_log		->GetMass(false, false, 0)/kg;
	G4double Mass_DriftSpacerMiddleTube		= DriftSpacerMiddleTube_log		->GetMass(false, false, 0)/kg;
	G4double Mass_DriftSpacerLowerTube		= DriftSpacerLowerTube_log		->GetMass(false, false, 0)/kg;
	G4double Mass_DriftSpacerLowerSquare	= DriftSpacerLowerSquare_log	->GetMass(false, false, 0)/kg;
	G4double Mass_BottomHolderUpperTube		= BottomHolderUpperTube_log		->GetMass(false, false, 0)/kg;
	G4double Mass_BottomHolderMiddleTube	= BottomHolderMiddleTube_log	->GetMass(false, false, 0)/kg;
	G4double Mass_BottomHolderLowerTube		= BottomHolderLowerTube_log		->GetMass(false, false, 0)/kg;
	G4double Mass_BottomClampUpperPart		= BottomClampUpperPart_log		->GetMass(false, false, 0)/kg;
	G4double Mass_BottomClampMiddlePart		= BottomClampMiddlePart_log		->GetMass(false, false, 0)/kg;
	G4double Mass_BottomClampLowerPart		= BottomClampLowerPart_log		->GetMass(false, false, 0)/kg;
	G4double Mass_Filler					= Filler_log					->GetMass(false, false, 0)/kg;
	G4double Mass_topPMTbase				= topPMTbase_log				->GetMass(false, false, 0)/kg;
	G4double Mass_topPMTcasing				= topPMTcasing_log				->GetMass(false, false, 0)/kg;
	G4double Mass_topPMTinterior			= topPMTinterior_log			->GetMass(false, false, 0)/kg;
	G4double Mass_topPMTwindow				= topPMTwindow_log				->GetMass(false, false, 0)/kg;
	G4double Mass_topPMTcathode				= topPMTcathode_log				->GetMass(false, false, 0)/kg;
	G4double Mass_CathodeGrid				= CathodeGrid_log				->GetMass(false, false, 0)/kg;
	G4double Mass_GXe						= GXeVol_log					->GetMass(false, false, 0)/kg;
	G4double Mass_LXe						= LXeVol_log					->GetMass(false, false, 0)/kg;
	G4double Mass_Target					= LXeTarget_log					->GetMass(false, false, 0)/kg;
	G4double Mass_Gate						= LXeGate_log					->GetMass(false, false, 0)/kg;
	//G4double Mass_Cathode					= LXeCathode_log				->GetMass(false, false, 0)/kg;
	G4double Mass_TargetTotal				= Mass_Target + Mass_Gate;
	
	
	G4cout	<< "|   DETECTOR PARTS (AS CODED) AND WEIGHT: "													<< G4endl
			<< "|   Laboratory                      "	<<	Mass_Laboratory					<< " kg"		<< G4endl
			<< "|   Outer Can Tube                  "	<<	Mass_OuterCanTube				<< " kg"		<< G4endl
			<< "|   Outer Can Bottom                "	<<	Mass_OuterCanBottom				<< " kg"		<< G4endl
			<< "|   Outer Can Upper Flange          "	<<	Mass_OuterCanLowerFlange		<< " kg"		<< G4endl
			<< "|   Outer Can Lower Flange          "	<<	Mass_OuterCanUpperFlange		<< " kg"		<< G4endl
			<< "|   Inner Can Tube                  "	<<	Mass_InnerCanTube				<< " kg"		<< G4endl
			<< "|   Inner Can Bottom                "	<<	Mass_InnerCanBottom				<< " kg"		<< G4endl
			<< "|   Inner Can LowerFlange           "	<<	Mass_InnerCanLowerFlange		<< " kg"		<< G4endl
			<< "|   Inner Can Upper Flange          "	<<	Mass_InnerCanUpperFlange		<< " kg"		<< G4endl
			<< "|   Steel Holder Tube               "	<<	Mass_SteelHolderTube			<< " kg"		<< G4endl
			<< "|   Steel Holder Upper Square       "	<<	Mass_SteelHolderUpperSquare		<< " kg"		<< G4endl
			<< "|   Steel Holder Lower Square       "	<<	Mass_SteelHolderLowerSquare		<< " kg"		<< G4endl
			<< "|   Support (x 4)                   "	<<	Mass_Support					<< " kg"		<< G4endl
			<< "|   Washer (x 4)                    "	<<  Mass_Washer						<< " kg"		<< G4endl
			<< "|   Top PMT Clamp                   "	<<	Mass_TopClamp					<< " kg"		<< G4endl
			<< "|   Top PMT Holder Upper Tube       "	<<	Mass_TopHolderUpperTube			<< " kg"		<< G4endl
			<< "|   Top PMT Holder Lower Tube       "	<<	Mass_TopHolderLowerTube			<< " kg"		<< G4endl
			<< "|   Top PMT Holder Square           "	<<	Mass_TopHolderSquare			<< " kg"		<< G4endl
			<< "|   Anode Grid Frame                "	<<	Mass_AnodeGrid					<< " kg"		<< G4endl
			<< "|   Extraction Spacer Upper Half    "	<<	Mass_ExtractionSpacerUpperHalf	<< " kg"		<< G4endl
			<< "|   Extraction Spacer Lower Half    "	<<	Mass_ExtractionSpacerLowerHalf	<< " kg"		<< G4endl
			<< "|   Gate Grid Frame                 "	<<	Mass_GateGrid					<< " kg"		<< G4endl
			<< "|   Drift Spacer Upper Square       "	<<	Mass_DriftSpacerUpperSquare		<< " kg"		<< G4endl
			<< "|   Drift Spacer Upper Tube         "	<<	Mass_DriftSpacerUpperTube		<< " kg"		<< G4endl
			<< "|   Drift Spacer Middle Tube        "	<<	Mass_DriftSpacerMiddleTube		<< " kg"		<< G4endl
			<< "|   Drift Spacer Lower Tube         "	<<	Mass_DriftSpacerLowerTube		<< " kg"		<< G4endl
			<< "|   Drift Spacer Lower Square       "	<<	Mass_DriftSpacerLowerSquare		<< " kg"		<< G4endl
			<< "|   Bottom PMT Holder Upper Tube    "	<<	Mass_BottomHolderUpperTube		<< " kg"		<< G4endl
			<< "|   Bottom PMT Holder Middle Tube   "	<<	Mass_BottomHolderMiddleTube		<< " kg"		<< G4endl
			<< "|   Bottom PMT Holder Lower Tube    "	<<	Mass_BottomHolderLowerTube		<< " kg"		<< G4endl
			<< "|   Bottom PMT Clamp Upper Part     "	<<	Mass_BottomClampUpperPart		<< " kg"		<< G4endl
			<< "|   Bottom PMT Clamp Middle Part    "	<<	Mass_BottomClampMiddlePart		<< " kg"		<< G4endl
			<< "|   Bottom PMT Clamp Lower Part     "	<<	Mass_BottomClampLowerPart		<< " kg"		<< G4endl
			<< "|   Filler                          "	<<	Mass_Filler						<< " kg"		<< G4endl
			<< "|   Grid Frame                      "	<<	Mass_CathodeGrid				<< " kg"		<< G4endl
			<< "|   PMT base                        "	<<	Mass_topPMTbase					<< " kg"		<< G4endl
			<< "|   PMT casing                      "	<<	Mass_topPMTcasing				<< " kg"		<< G4endl
			<< "|   PMT interior                    "	<<	Mass_topPMTinterior				<< " kg"		<< G4endl
			<< "|   PMT window                      "	<<	Mass_topPMTwindow				<< " kg"		<< G4endl
			<< "|   PMT cathode                     "	<<	Mass_topPMTcathode				<< " kg"		<< G4endl
			<< "|   GXe                             "	<<	Mass_GXe						<< " kg"		<< G4endl
			<< "|   LXe                             "	<<	Mass_LXe						<< " kg"		<< G4endl
			<< "|   LXe_Target                      "	<<	Mass_Target						<< " kg"		<< G4endl
			<< "|   LXe_Gate                        "	<<	Mass_Gate						<< " kg"		<< G4endl
			//<< "|   LXe_Cathode                     "	<<	Mass_Cathode					<< " kg"		<< G4endl
			<< "|   TargetTotal                     "	<<	Mass_TargetTotal		  		<< " kg"		<< G4endl
			<< "| "																							<< G4endl
			<< 	" ============================================================"								<< G4endl;

	// G4cout << G4endl << "The materials defined are : "	<< G4endl << G4endl;	
	//G4cout << *(G4Material::GetMaterialTable())			<< G4endl;
	
	
/*	// paraffin block next to the scintillator
	G4double paraffin_x 	= 50.*cm;
	G4double paraffin_y 	= 28.*cm;
	G4double paraffin_z 	= 30.*cm;
	G4double beta 			= 20.; // degrees
	G4double paraffin_distance 	= EJ_distance + 10.; // cm
	G4double paraffin_angle 	= EJ_scatterAngle - beta;//in degrees
	G4double paraffin_posX 		= (paraffin_distance*cos(paraffin_angle*3.14/180.))*cm;
	G4double paraffin_posY 		= (paraffin_distance*sin(paraffin_angle*3.14/180.))*cm;
	G4double paraffin_posZ 		= wood_posZ + paraffin_z/2 + wood_z/2;

	G4RotationMatrix *rot_paraffin = new G4RotationMatrix;
	rot_paraffin->rotateZ(-70.*deg);

	G4Box 			*paraffin_box 	= new G4Box("paraffin_box", paraffin_x/2, paraffin_y/2, paraffin_z/2);
	G4LogicalVolume *paraffin_log 	= new G4LogicalVolume(paraffin_box, Paraffin, "paraffin_log");
	//G4PVPlacement	*paraffin_phys 	= new G4PVPlacement(rot_paraffin, G4ThreeVector(paraffin_posX, paraffin_posY, paraffin_posZ), paraffin_log, "paraffin_phys", Laboratory_log, false, 0);
*/


	/////////////////////////
	// Sensitive Detectors //
	///////////////////////////////////////////////////////////////////////////////////////////////////
	// xenon sensitivity
	G4SDManager *pSDManager = G4SDManager::GetSDMpointer();

	// target
	XuerichLXeSensitiveDetector *pLXeSD = new XuerichLXeSensitiveDetector("Xuerich/LXeSD");
	pSDManager->AddNewDetector(pLXeSD);
	LXeTarget_log	->SetSensitiveDetector(pLXeSD);
	LXeGate_log		->SetSensitiveDetector(pLXeSD);
	//LXeCathode_log	->SetSensitiveDetector(pLXeSD);

	// dead xenon
	XuerichDeadXeSensitiveDetector *pDeadXeSD = new XuerichDeadXeSensitiveDetector("Xuerich/DeadXeSD");
	pSDManager->AddNewDetector(pDeadXeSD);
	LXeVol_log->SetSensitiveDetector(pDeadXeSD);

	// gas xenon
	XuerichGXeSensitiveDetector *pGXeSD = new XuerichGXeSensitiveDetector("Xuerich/GXeSD");
	pSDManager->AddNewDetector(pGXeSD);
	//GXeVol_log->SetSensitiveDetector(pGXeSD);
	ConcreteShield_log			->SetSensitiveDetector(pGXeSD);
	WallLeft_log				->SetSensitiveDetector(pGXeSD);
	WallRight_log				->SetSensitiveDetector(pGXeSD);
	WallFront_log				->SetSensitiveDetector(pGXeSD);
	WallBack_log				->SetSensitiveDetector(pGXeSD);

	// pmt sensitivity
	XuerichPmtSensitiveDetector *pPmtSD = new XuerichPmtSensitiveDetector("Xuerich/PmtSD");
	pSDManager->AddNewDetector(pPmtSD);
	topPMTcathode_log		->SetSensitiveDetector(pPmtSD);
	bottomPMTcathode_log	->SetSensitiveDetector(pPmtSD);

	// scintillator sensitivity
	XuerichScintSensitiveDetector *pScintSD = new XuerichScintSensitiveDetector("Xuerich/ScintSD");
	pSDManager->AddNewDetector(pScintSD);
	EJ1_log->SetSensitiveDetector(pScintSD);
	EJ2_log->SetSensitiveDetector(pScintSD);

	// teflon sensitivity
	XuerichTeflonSensitiveDetector *pTeflonSD = new XuerichTeflonSensitiveDetector("Xuerich/TeflonSD");
	pSDManager->AddNewDetector(pTeflonSD);
	Washer1_log						->SetSensitiveDetector(pTeflonSD);
	Washer2_log						->SetSensitiveDetector(pTeflonSD);
	Washer3_log						->SetSensitiveDetector(pTeflonSD);
	Washer4_log						->SetSensitiveDetector(pTeflonSD);
	Support1_log					->SetSensitiveDetector(pTeflonSD);
	Support2_log					->SetSensitiveDetector(pTeflonSD);
	Support3_log					->SetSensitiveDetector(pTeflonSD);
	Support4_log					->SetSensitiveDetector(pTeflonSD);
	TopClamp_log					->SetSensitiveDetector(pTeflonSD);
	TopHolderUpperTube_log			->SetSensitiveDetector(pTeflonSD);
	TopHolderLowerTube_log			->SetSensitiveDetector(pTeflonSD);
	TopHolderSquare_log				->SetSensitiveDetector(pTeflonSD);
	ExtractionSpacerUpperHalf_log	->SetSensitiveDetector(pTeflonSD);
	ExtractionSpacerLowerHalf_log	->SetSensitiveDetector(pTeflonSD);
	DriftSpacerUpperSquare_log		->SetSensitiveDetector(pTeflonSD);
	DriftSpacerUpperTube_log		->SetSensitiveDetector(pTeflonSD);
	DriftSpacerMiddleTube_log		->SetSensitiveDetector(pTeflonSD);
	DriftSpacerLowerTube_log		->SetSensitiveDetector(pTeflonSD);
	DriftSpacerLowerSquare_log		->SetSensitiveDetector(pTeflonSD);
	BottomHolderUpperTube_log		->SetSensitiveDetector(pTeflonSD);
	BottomHolderMiddleTube_log		->SetSensitiveDetector(pTeflonSD);
	BottomHolderLowerTube_log		->SetSensitiveDetector(pTeflonSD);
	Filler_log						->SetSensitiveDetector(pTeflonSD);
	BottomClampUpperPart_log		->SetSensitiveDetector(pTeflonSD);
	BottomClampMiddlePart_log		->SetSensitiveDetector(pTeflonSD);
	BottomClampLowerPart_log		->SetSensitiveDetector(pTeflonSD);
	topPMTbase_log					->SetSensitiveDetector(pTeflonSD);
	bottomPMTbase_log				->SetSensitiveDetector(pTeflonSD);

	// sensitivity IN THE REST OF MATERIALS
	XuerichRestSensitiveDetector *pRestSD = new XuerichRestSensitiveDetector("Xuerich/RestSD");
	pSDManager->AddNewDetector(pRestSD);
	
	OuterCanTube_log			->SetSensitiveDetector(pRestSD);
	OuterCanBottom_log			->SetSensitiveDetector(pRestSD);
	OuterCanLowerFlange_log		->SetSensitiveDetector(pRestSD);
	OuterCanUpperFlange_log		->SetSensitiveDetector(pRestSD);
	InnerCanTube_log			->SetSensitiveDetector(pRestSD);
	InnerCanBottom_log			->SetSensitiveDetector(pRestSD);
	InnerCanLowerFlange_log		->SetSensitiveDetector(pRestSD);
	InnerCanUpperFlange_log		->SetSensitiveDetector(pRestSD);

	SteelHolderUpperSquare_log	->SetSensitiveDetector(pRestSD);
	SteelHolderLowerSquare_log	->SetSensitiveDetector(pRestSD);
	SteelHolderTube_log			->SetSensitiveDetector(pRestSD);
	AnodeGrid_log				->SetSensitiveDetector(pRestSD);
	CathodeGrid_log				->SetSensitiveDetector(pRestSD);
	GateGrid_log				->SetSensitiveDetector(pRestSD);

	topPMTcasing_log			->SetSensitiveDetector(pRestSD);
	bottomPMTcasing_log			->SetSensitiveDetector(pRestSD);

	topPMTwindow_log			->SetSensitiveDetector(pRestSD);
	bottomPMTwindow_log			->SetSensitiveDetector(pRestSD);	

	topPMTcathode_log			->SetSensitiveDetector(pRestSD);
	bottomPMTcathode_log			->SetSensitiveDetector(pRestSD);	

//--------------	END PROGRAM	------------------------
return Laboratory_phys;
//------------------------------------------------------

}



  ////////////////////////
 // Optical parameters //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XuerichDetectorConstruction::SetTeflonReflectivity(G4double dReflectivity)
{
	//G4Material *Teflon = G4Material::GetMaterial(G4String("Teflon"));

	if(Teflon)
	{
		G4cout << "\n----> Setting Teflon reflectivity to " << dReflectivity << G4endl;

		G4MaterialPropertiesTable *pTeflonPropertiesTable = Teflon->GetMaterialPropertiesTable();
		
		G4double teflon_PP[] = { 6.91 * eV, 6.98 * eV, 7.05 * eV };
		G4double teflon_REFL[] = {dReflectivity, dReflectivity, dReflectivity};
		pTeflonPropertiesTable->RemoveProperty("REFLECTIVITY");
		pTeflonPropertiesTable->AddProperty("REFLECTIVITY", teflon_PP, teflon_REFL, 3);
	}
	else
	{
		G4cout << "!!!!> Teflon material not found!" << G4endl;
		exit(-1);
	}
}

void XuerichDetectorConstruction::SetSS304LSteelReflectivity(G4double dSteelReflectivity)
{
	//G4Material *SSteel = G4Material::GetMaterial(G4String("SS304LSteel"));

	if(SSteel)
	{
		G4cout << "\n----> Setting SS304LSteel reflectivity to " << dSteelReflectivity << G4endl;

		G4MaterialPropertiesTable *pSteelPropertiesTable = SSteel->GetMaterialPropertiesTable();
		
		G4double Steel_PP[] = { 6.91 * eV, 6.98 * eV, 7.05 * eV };
		G4double Steel_REFL[] = {dSteelReflectivity, dSteelReflectivity, dSteelReflectivity};
		pSteelPropertiesTable->RemoveProperty("REFLECTIVITY");
		pSteelPropertiesTable->AddProperty("REFLECTIVITY", Steel_PP, Steel_REFL, 3);
	}
	else
	{
		G4cout << "!!!!> SS304LSteel material not found!" << G4endl;
		exit(-1);
	}
}


void XuerichDetectorConstruction::SetLXeScintillation(G4bool bScintillation)
{
	G4cout << "----> Setting LXe(GXe) scintillation to " << bScintillation << G4endl;
			
	G4Material *pLXeMaterial = G4Material::GetMaterial(G4String("LXe"));
	if(pLXeMaterial)
	{	
		G4MaterialPropertiesTable *pLXePropertiesTable = pLXeMaterial->GetMaterialPropertiesTable();
		if(bScintillation)
			pLXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 1000./(1.0*keV));
	}
	else
	{
		G4cout << "ls!> LXe materials not found!" << G4endl;
		exit(-1);
	}
	
	G4Material *pGXeMaterial = G4Material::GetMaterial(G4String("GXe"));
	if(pGXeMaterial)
	{	
		G4MaterialPropertiesTable *pGXePropertiesTable = pGXeMaterial->GetMaterialPropertiesTable();
		if(bScintillation)
			pGXePropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 1000/(1.0*keV));
	}
	else
	{
		G4cout << "ls!> GXe materials not found!" << G4endl;
		exit(-1);
	}


}



void XuerichDetectorConstruction::SetLXeAbsorbtionLength(G4double dAbsorbtionLength)
{
	G4Material *pLXeMaterial = G4Material::GetMaterial(G4String("LXe"));

	if(pLXeMaterial)
	{
		G4cout << "----> Setting LXe absorbtion length to " << dAbsorbtionLength/cm << " cm" << G4endl;

		G4MaterialPropertiesTable *pLXePropertiesTable = pLXeMaterial->GetMaterialPropertiesTable();
			
			G4double LXe_PP[] = {6.91*eV, 6.98*eV, 7.05*eV};
			G4double LXe_ABSL[] = {dAbsorbtionLength, dAbsorbtionLength, dAbsorbtionLength};
			pLXePropertiesTable->RemoveProperty("ABSLENGTH");
			pLXePropertiesTable->AddProperty("ABSLENGTH", LXe_PP, LXe_ABSL, 3);
	}
	else
	{
		G4cout << "ls!> LXe materials not found!" << G4endl;
		exit(-1);
	}
}

void XuerichDetectorConstruction::SetLXeRayScatterLength(G4double dRayScatterLength)
{
  G4Material *pLXeMaterial = G4Material::GetMaterial(G4String("LXe"));
  
  if(pLXeMaterial)
    {
      
      G4cout << "----> Setting LXe scattering length to " << dRayScatterLength/cm << " cm" << G4endl;
      
      G4MaterialPropertiesTable *pLXePropertiesTable = pLXeMaterial->GetMaterialPropertiesTable();
              
               G4double LXe_PP[] = {6.91*eV, 6.98*eV, 7.05*eV};
               G4double LXe_SCAT[] = {dRayScatterLength, dRayScatterLength, dRayScatterLength};
               pLXePropertiesTable->RemoveProperty("RAYLEIGH");
               pLXePropertiesTable->AddProperty("RAYLEIGH", LXe_PP, LXe_SCAT, 3); 
    }
  else
    {
      G4cout << "ls!> LXe materials not found!" << G4endl;
      exit(-1);
    }

}




