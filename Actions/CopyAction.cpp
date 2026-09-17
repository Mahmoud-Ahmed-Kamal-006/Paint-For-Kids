#include "CopyAction.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"

CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
    // No parameters to read for copy action
    // We just need to check if any figure is selected, which we'll do in Execute
}

void CopyAction::Execute()
{
    ReadActionParameters();

    // Get the output interface
    Output* pOut = pManager->GetOutput();

    // Check if there's a single selected figure to copy
    int rectCount, circCount, triCount, hexCount, sqCount, totalSelected;
    CFigure* selectedFig = NULL;

    // This function will fill the counts and set selectedFig if exactly one figure is selected
    pManager->GetSelectedFiguresCounts(rectCount, circCount, triCount, hexCount, sqCount, totalSelected, selectedFig);

    if (totalSelected == 0)
    {
        pOut->PrintMessage("No figure selected to copy");
        return;
    }
    else if (totalSelected > 1)
    {
        pOut->PrintMessage("Please select only one figure to copy");
        return;
    }

    // Copy the selected figure to the clipboard
    pManager->SetClipboard(selectedFig);

    pOut->PrintMessage("Figure copied to clipboard");
}