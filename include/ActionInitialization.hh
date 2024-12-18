#ifndef ActionInitialization_h
#define ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"


class ActionInitialization : public G4VUserActionInitialization
{
  public:
  ActionInitialization() = default;
  ~ActionInitialization() override = default;
  void Actions(PrimaryGeneratorAction* pga, RunAction* ra);

  void Build() const override;
private:
  PrimaryGeneratorAction* userPGA;
  RunAction* userRA;
};


#endif
