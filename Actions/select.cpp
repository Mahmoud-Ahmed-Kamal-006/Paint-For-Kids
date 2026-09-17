#include "select.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{
	SelectedFig = NULL;
    ClickedP.x = 0;
    ClickedP.y = 0;
}


void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a Figure");

	// read the point selected
	pIn->GetPointClicked(ClickedP.x, ClickedP.y);

}
void SelectAction::Execute()
{
    ReadActionParameters();

    // Get the pointer to input and output
    Output* pOut = pManager->GetOutput();

    // Get the figure at the clicked point (if any)
    CFigure* clickedFig = pManager->GetFigure(ClickedP.x, ClickedP.y);

    // Check if a figure was found
    if (clickedFig != NULL)
    {
        // If the figure is already selected, unselect it
        if (clickedFig->IsSelected())
        {
            clickedFig->SetSelected(false);
            pOut->PrintMessage("Figure unselected");
        }
        else
        {
            // Select the figure without unselecting others
            clickedFig->SetSelected(true);

            // Get info about selected figures and display on status bar
            int rectCount, circCount, triCount, hexCount, sqCount, totalSelected;
            CFigure* singleSelectedFig = NULL;

            pManager->GetSelectedFiguresCounts(rectCount, circCount, triCount, hexCount, sqCount, totalSelected, singleSelectedFig);

            if (totalSelected == 1)
            {
                // Only one figure is selected, show its detailed info
                pOut->PrintMessage("Figure selected: " + singleSelectedFig->GetInfo());
            }
            else
            {
                // Multiple figures are selected, show count by type
                string msg = "Selected: ";

                if (rectCount > 0)
                    msg += to_string(rectCount) + " Rectangle(s), ";

                if (circCount > 0)
                    msg += to_string(circCount) + " Circle(s), ";

                if (triCount > 0)
                    msg += to_string(triCount) + " Triangle(s), ";

                if (hexCount > 0)
                    msg += to_string(hexCount) + " Hexagon(s), ";

                if (sqCount > 0)
                    msg += to_string(sqCount) + " Square(s), ";

                // Remove the trailing comma and space
                if (msg.length() > 10) // Length of "Selected: "
                    msg = msg.substr(0, msg.length() - 2);

                pOut->PrintMessage(msg);
            }
        }
    }
    else
    {
        // If clicked on empty area, unselect all figures
        pManager->UnselectAll();
        pOut->PrintMessage("All figures unselected");
    }


    // Update the interface to show the selections
    pManager->UpdateInterface();
}

