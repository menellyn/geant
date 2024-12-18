#include "PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolumeStore.hh"
#include "Randomize.hh"
#include "G4Orb.hh"

 
PrimaryGeneratorAction::PrimaryGeneratorAction(const G4String& pName, const G4double& pEnergy, const G4String& posType): pName(pName), pEnergy(pEnergy), posType(posType)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

G4ThreeVector PrimaryGeneratorAction::GenerateRandomDirection(){
  G4double theta = acos(2 * G4UniformRand() - 1); 
  G4double phi = 2 * M_PI * G4UniformRand();
  return G4ThreeVector(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
}

G4ThreeVector PrimaryGeneratorAction::UniformGenerateParticlePosition(){
  auto store = G4LogicalVolumeStore::GetInstance();
  G4double R = dynamic_cast<G4Orb*>(store->GetVolume("LAB_ADMIXTURE")->GetSolid())->GetRadius();
  return GenerateRandomDirection()*R*pow(G4UniformRand(), 1.0 / 3.0);
}

G4ThreeVector PrimaryGeneratorAction::FixedGenerateParticlePosition(){
  auto store = G4LogicalVolumeStore::GetInstance();
  G4double R = dynamic_cast<G4Orb*>(store->GetVolume("LAB_ADMIXTURE")->GetSolid())->GetRadius();
  return primaryPosition * R;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle(pName);
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(pEnergy);
  fParticleGun->SetParticleMomentumDirection(GenerateRandomDirection());

  if (posType == "uniform") fParticleGun->SetParticlePosition(UniformGenerateParticlePosition());
  else if (posType == "fixed") fParticleGun->SetParticlePosition(FixedGenerateParticlePosition());

  fParticleGun->GeneratePrimaryVertex(anEvent);
  
}




