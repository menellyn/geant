#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

#include "G4RunManager.hh"
#include "G4SteppingVerbose.hh"
#include "G4UImanager.hh"
#include "PhysicsList.hh"
#include "G4SystemOfUnits.hh" 

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"

int main(int argc,char** argv)
{

  auto runManager = new G4RunManager();

  runManager->SetUserInitialization(new DetectorConstruction());
  runManager->SetUserInitialization(new PhysicsList());

  ActionInitialization* AI = new ActionInitialization();
  G4String file_name = "/home/polina/B1/build/test.csv";
  PrimaryGeneratorAction* PGA = new PrimaryGeneratorAction("e+", 3.*MeV, "uniform");
  RunAction* RA = new RunAction(file_name);
  RA->setHistName("count");
  AI->Actions(PGA, RA);

  runManager->SetUserInitialization(AI);

  runManager->Initialize();
  //runManager->BeamOn(5000);

  // std::vector<double> pos = {-0.99, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.99};

  //  for (const double& z : pos){
  //    PGA->SetPosition(G4ThreeVector(0, 0, z));
  //    RA->setHistName(std::to_string(z));
  //    runManager->GeometryHasBeenModified();
  //    runManager->BeamOn(1000);
  //  }

  G4UIExecutive* ui = new G4UIExecutive(argc, argv);
  auto visManager = new G4VisExecutive();
  visManager->Initialize();
  auto UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/control/execute init_vis.mac");
  ui->SessionStart();


  delete visManager;
  delete runManager;
}
