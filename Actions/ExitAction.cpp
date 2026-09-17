#include "ExitAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
    // No parameters needed for this action
}

void ExitAction::Execute()
{
    Output* pOut = pManager->GetOutput();

    // Display a message indicating that the application is exiting
    pOut->PrintMessage("Exiting application...");

    // Clear the drawing area one last time
    pOut->ClearDrawArea();
}