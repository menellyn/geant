#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ThreeVector.hh"

class G4ParticleGun;
class G4Event;


class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction(const G4String& pName, const G4double& pEnergy, const G4String& posType);
    ~PrimaryGeneratorAction() override;
    void GeneratePrimaries(G4Event*) override;
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
    void SetPosition(const G4ThreeVector& position) { primaryPosition = position; }
    G4ThreeVector GenerateRandomDirection();
    G4ThreeVector UniformGenerateParticlePosition();
    G4ThreeVector FixedGenerateParticlePosition();

  private:
    G4ParticleGun* fParticleGun; 
    G4String pName;
    G4double pEnergy;
    G4String posType;
    G4ThreeVector primaryPosition;

};


#endif
