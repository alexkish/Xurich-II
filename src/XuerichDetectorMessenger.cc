#include <G4ThreeVector.hh>
#include <G4RotationMatrix.hh>
#include <G4ParticleTable.hh>
#include <G4UIdirectory.hh>
#include <G4UIcmdWithoutParameter.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWith3Vector.hh>
#include <G4UIcmdWith3VectorAndUnit.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithABool.hh>
#include <G4Tokenizer.hh>
#include <G4ios.hh>
#include <fstream>
#include <iomanip>

#include "XuerichDetectorMessenger.hh"

#include "XuerichDetectorConstruction.hh"

XuerichDetectorMessenger::XuerichDetectorMessenger(XuerichDetectorConstruction *pXeDetector)
:m_pXeDetector(pXeDetector)
{ 
	m_pDetectorDir = new G4UIdirectory("/xe/detector/");
	m_pDetectorDir->SetGuidance("detector control.");

	m_pTeflonReflectivityCmd = new G4UIcmdWithADouble("/xe/detector/setTeflonReflectivity", this);
	m_pTeflonReflectivityCmd->SetGuidance("Define teflon reflectivity.");
	m_pTeflonReflectivityCmd->SetParameterName("R", false);
	m_pTeflonReflectivityCmd->SetRange("R >= 0. && R <= 1.");
	m_pTeflonReflectivityCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

	m_pLXeScintillationCmd = new G4UIcmdWithABool("/xe/detector/setLXeScintillation", this);
	m_pLXeScintillationCmd->SetGuidance("Switch on/off LXe scintillation in the sensitive volume.");
	m_pLXeScintillationCmd->SetParameterName("LXeScint", false); 
	m_pLXeScintillationCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

	m_pLXeAbsorbtionLengthCmd = new G4UIcmdWithADoubleAndUnit("/xe/detector/setLXeAbsorbtionLength", this);
	m_pLXeAbsorbtionLengthCmd->SetGuidance("Define LXe absorbtion length.");
	m_pLXeAbsorbtionLengthCmd->SetParameterName("AbsL", false);
	m_pLXeAbsorbtionLengthCmd->SetRange("AbsL >= 0.");
	m_pLXeAbsorbtionLengthCmd->SetUnitCategory("Length");
	m_pLXeAbsorbtionLengthCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

	m_pLXeRayScatterLengthCmd = new G4UIcmdWithADoubleAndUnit("/xe/detector/setLXeRayScatterLength", this);
	m_pLXeRayScatterLengthCmd->SetGuidance("Define LXe Rayleigh Scattering length.");
	m_pLXeRayScatterLengthCmd->SetParameterName("ScatL", false);
	m_pLXeRayScatterLengthCmd->SetRange("ScatL >= 0.");
	m_pLXeRayScatterLengthCmd->SetUnitCategory("Length");
	m_pLXeRayScatterLengthCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

}

XuerichDetectorMessenger::~XuerichDetectorMessenger()
{
	delete m_pTeflonReflectivityCmd;
	delete m_pLXeScintillationCmd;
	delete m_pLXeAbsorbtionLengthCmd;
	delete m_pLXeRayScatterLengthCmd;


	delete m_pDetectorDir;
}

void XuerichDetectorMessenger::SetNewValue(G4UIcommand *pUIcommand, G4String hNewValue)
{
	if(pUIcommand == m_pLXeScintillationCmd)
		m_pXeDetector->SetLXeScintillation(m_pLXeScintillationCmd->GetNewBoolValue(hNewValue));

		if(pUIcommand == m_pTeflonReflectivityCmd)
			m_pXeDetector->SetTeflonReflectivity(m_pTeflonReflectivityCmd->GetNewDoubleValue(hNewValue));		
		
		if(pUIcommand == m_pLXeAbsorbtionLengthCmd)
			m_pXeDetector->SetLXeAbsorbtionLength(m_pLXeAbsorbtionLengthCmd->GetNewDoubleValue(hNewValue));

		if(pUIcommand == m_pLXeRayScatterLengthCmd)
			m_pXeDetector->SetLXeRayScatterLength(m_pLXeRayScatterLengthCmd->GetNewDoubleValue(hNewValue));
}


