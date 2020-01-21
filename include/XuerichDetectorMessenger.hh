#ifndef XuerichDetectorMessenger_h
#define XuerichDetectorMessenger_h 1

#include <G4UImessenger.hh>
#include <globals.hh>

class XuerichDetectorConstruction;

class G4UIcommand;
class G4UIdirectory;
class G4UIcmdWithoutParameter;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3Vector;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWithAnInteger;
class G4UIcmdWithADouble;
class G4UIcmdWithABool;
class G4UIcmdWithoutParameter;

class XuerichDetectorMessenger: public G4UImessenger
{
public:
	XuerichDetectorMessenger(XuerichDetectorConstruction *pXeDetector);
	~XuerichDetectorMessenger();

	void SetNewValue(G4UIcommand *pUIcommand, G4String hString);

private:
	XuerichDetectorConstruction* m_pXeDetector;

	G4UIdirectory *m_pDetectorDir;

	G4UIcmdWithADouble *m_pTeflonReflectivityCmd;
	G4UIcmdWithABool *m_pLXeScintillationCmd;
	G4UIcmdWithADoubleAndUnit *m_pLXeAbsorbtionLengthCmd;
	G4UIcmdWithADoubleAndUnit *m_pLXeRayScatterLengthCmd;

};

#endif

