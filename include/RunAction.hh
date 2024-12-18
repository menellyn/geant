#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Run.hh"

class RunAction : public G4UserRunAction{
public:

  RunAction(const G4String& fileName);
  ~RunAction();
  void BeginOfRunAction(const G4Run*) override;
  void EndOfRunAction(const G4Run*) override;
  void setHistName(const G4String& hist_name){ histName = hist_name; }
private:
  G4String histName;
};

#endif 