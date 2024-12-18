#include "G4AnalysisManager.hh"
#include "RunAction.hh"

RunAction::RunAction(const G4String& fileName){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->OpenFile(fileName);
}

void RunAction::BeginOfRunAction(const G4Run *run){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->CreateNtuple(histName, histName);
    manager->CreateNtupleDColumn(histName);
    manager->FinishNtuple();
}

void RunAction::EndOfRunAction(const G4Run *run){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    G4int nofEvents = run->GetNumberOfEvent();
    if (nofEvents == 0) return;
}

RunAction::~RunAction(){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->Write();
    manager->CloseFile();

}