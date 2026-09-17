#include "PasteAction.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
    // Get a pointer to the input interface
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    pOut->PrintMessage("Click where you want to paste the figure");

    // Get the clicked point
    pIn->GetPointClicked(PastePoint.x, PastePoint.y);

    pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
    // Get the output interface
    Output* pOut = pManager->GetOutput();

    // Check if there's a figure in the clipboard
    CFigure* clipboardFig = pManager->GetClipboard();

    if (clipboardFig == NULL)
    {
        pOut->PrintMessage("Clipboard is empty. Copy a figure first");
        return;
    }

    // Read where to paste the figure
    ReadActionParameters();

    // Create a clone of the clipboard figure at the new location
    CFigure* newFig = clipboardFig->Clone(PastePoint);

    // If successfully created a clone
    if (newFig != NULL)
    {
        // Unselect all figures
        pManager->UnselectAll();

        // Add the new figure to the application manager
        pManager->AddFigure(newFig);

        // Select the newly pasted figure
        newFig->SetSelected(true);

        pOut->PrintMessage("Figure pasted successfully");
    }
    else
    {
        pOut->PrintMessage("Error: Could not paste figure");
    }

    // Update the interface
    pManager->UpdateInterface();
}