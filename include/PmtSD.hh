#ifndef PmtSD_h
#define PmtSD_h 1

#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"


class PmtSD : public G4VSensitiveDetector
{
  public:
    PmtSD(const G4String& name);
    ~PmtSD() override = default;

    void   Initialize(G4HCofThisEvent*) override;
    G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;
    void   EndOfEvent(G4HCofThisEvent*) override;

  private:
    const G4double quantumEfficiency = 0.28;
    G4int count;
    G4int GetCounter();
};


#endif