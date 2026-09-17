#include "CutAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../Figures/CFigure.h"

CutAction::CutAction(ApplicationManager* pApp) : Action(pApp) {}

void CutAction::ReadActionParameters()
{
    
}

void CutAction::Execute()
{
    ReadActionParameters();

    
    Output* pOut = pManager->GetOutput();

    // Get counts of selected figures
    int rectCount, circCount, triCount, hexCount, sqCount, totalSelected;
    CFigure* singleSelectedFig = NULL;

    pManager->GetSelectedFiguresCounts(rectCount, circCount, triCount, hexCount, sqCount, totalSelected, singleSelectedFig);

    // Check if exactly one figure is selected
    if (totalSelected != 1)
    {
        pOut->PrintMessage("Please select exactly one figure to cut");
        return;
    }

    // Set the selected figure to the clipboard
    pManager->SetClipboard(singleSelectedFig);

    // Delete the selected figure from the drawing area
    pManager->DeleteSelectedFigures();

    pOut->PrintMessage("Figure cut successfully. Use paste to place it in a new location.");
}