#include "DeleteAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp) {}

void DeleteAction::ReadActionParameters()
{
    // No parameters to read for this action
}

void DeleteAction::Execute()
{
    ReadActionParameters();

    pManager->DeleteSelectedFigures();
    pManager->GetOutput()->PrintMessage("Selected figure(s) deleted.");
}
