#include "ActionInitialization.hh"


void ActionInitialization::Actions(PrimaryGeneratorAction* pga, RunAction* ra){
  userPGA = pga;
  userRA = ra;
}

void ActionInitialization::Build() const
{
    SetUserAction(userPGA);
    SetUserAction(userRA);
}


