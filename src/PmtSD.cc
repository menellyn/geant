#include "PmtSD.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4RandomTools.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"


PmtSD::PmtSD(const G4String& name): count(0), G4VSensitiveDetector(name){}

void PmtSD::Initialize(G4HCofThisEvent*)
{
  count = 0;
}

G4int PmtSD::GetCounter(){
  return count;
}

G4bool PmtSD::ProcessHits(G4Step* aStep, G4TouchableHistory* history)
{
  G4Track* track = aStep->GetTrack();

  if (track->GetParticleDefinition()->GetParticleName() == "opticalphoton") {
    double randomValue = G4UniformRand();
    if (randomValue < quantumEfficiency) {
        count++;
    }
  }

  track->SetTrackStatus(fStopAndKill);
  return true;
}

void PmtSD::EndOfEvent(G4HCofThisEvent*)
{
  auto *manager = G4AnalysisManager::Instance();
  auto EvtId =  G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
  G4int count = GetCounter();
  auto lastNtupleId = G4AnalysisManager::Instance()->GetNofNtuples() - 1;
  if(lastNtupleId == -1){
    return;
  }
  manager->FillNtupleDColumn(lastNtupleId, 0, count);
  manager->AddNtupleRow(lastNtupleId);
}
