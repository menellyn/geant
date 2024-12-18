#include "PhysicsList.hh"

#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"



PhysicsList::PhysicsList()
{
  RegisterPhysics(new G4EmStandardPhysics_option4());
  RegisterPhysics(new G4OpticalPhysics());

}
