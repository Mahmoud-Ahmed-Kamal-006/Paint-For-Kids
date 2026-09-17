#include "FillColorAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <string>

FillColorAction::FillColorAction(ApplicationManager* pApp) : Action(pApp)
{
}

void FillColorAction::ReadActionParameters()
{
    // Get a pointer to the Input / Output Interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    // Get the selected figures count
    int rectCount, circCount, triCount, hexCount, sqCount, totalSelected;
    CFigure* singleSelectedFig = NULL;
    pManager->GetSelectedFiguresCounts(rectCount, circCount, triCount, hexCount, sqCount, totalSelected, singleSelectedFig);

    // Check if any figure is selected
    if (totalSelected == 0)
    {
        pOut->PrintMessage("No figure is selected. Please select a figure first.");
        return;
    }

    // Prompt the user to enter a color
    pOut->PrintMessage("Enter a color (BLACK, RED, GREEN, BLUE, YELLOW, ORANGE): ");
    string colorStr = pIn->GetSrting(pOut);

    // Convert color string to uppercase for matching with string-to-color function
    for (auto& c : colorStr)
        c = toupper(c);

    // Use the existing CFigure utility function to convert string to color
    if (singleSelectedFig) // Use any selected figure to convert the string to color
        FillClr = singleSelectedFig->stringtocolor(colorStr);
    else
    {
        // Fallback if no figure is selected (shouldn't happen due to earlier check)
        if (colorStr == "BLACK") FillClr = BLACK;
        else if (colorStr == "RED") FillClr = RED;
        else if (colorStr == "GREEN") FillClr = GREEN;
        else if (colorStr == "BLUE") FillClr = BLUE;
        else if (colorStr == "YELLOW") FillClr = YELLOW;
        else if (colorStr == "ORANGE") FillClr = ORANGE;
        else
        {
            pOut->PrintMessage("Invalid color! Please choose from the available colors.");
            FillClr = BLUE; // Default color
        }
    }

    pOut->ClearStatusBar();
}

void FillColorAction::Execute()
{
    // Read action parameters
    ReadActionParameters();

    // Get a pointer to the Output Interface
    Output* pOut = pManager->GetOutput();

    // Get all figures
    CFigure* const* FigList = pManager->getFigList();
    int FigCount = pManager->getFigCount();

    int updatedCount = 0;

    // Loop through all figures and update selected ones
    for (int i = 0; i < FigCount; i++)
    {
        if (FigList[i]->IsSelected())
        {
            // Update the fill color (will automatically set isFilled to true as per your implementation)
            FigList[i]->ChngFillClr(FillClr);
            updatedCount++;
        }
    }

    // Display status message
    if (updatedCount > 0)
        pOut->PrintMessage(to_string(updatedCount) + " figure(s) filled with the selected color");
    else
        pOut->PrintMessage("No figures were updated. Please select a figure first.");

    // Update the interface
    pManager->UpdateInterface();
}