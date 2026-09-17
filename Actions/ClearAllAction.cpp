#include "ClearAllAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ClearAllAction::ClearAllAction(ApplicationManager* pApp) : Action(pApp) {}

void ClearAllAction::ReadActionParameters()
{
	// No parameters to read for this action
}
void ClearAllAction::Execute()
{
    ReadActionParameters();
    pManager->ClearAllFigures();
    pManager->GetOutput()->ClearDrawArea();
    pManager->GetOutput()->PrintMessage("All figures cleared.");
}

