#include "Swap.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

Swap::Swap(ApplicationManager* pApp) : Action(pApp) {
	
}

void Swap::ReadActionParameters() {
   
}

void Swap::Execute() {
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();

    CFigure* selectedFigs[2] = { nullptr, nullptr };
    int selectedCount = 0;

    // Count all selected figures and save the first two
    for (int i = 0; i < pManager->getFigCount(); ++i) {
        CFigure* fig = pManager->getFigList()[i];
        if (fig && fig->IsSelected()) {
            if (selectedCount < 2) {
                selectedFigs[selectedCount] = fig;
            }
            selectedCount++;
        }
    }

    if (selectedCount != 2) {
        pOut->PrintMessage("Please select exactly TWO figures to swap.");
        return;
    }

    if (!selectedFigs[0] || !selectedFigs[1]) {
        pOut->PrintMessage("Error: Invalid figure pointers.");
        return;
    }

   
    Point center1 = selectedFigs[0]->getCenter();
    Point center2 = selectedFigs[1]->getCenter();

   
    selectedFigs[0]->setCenter(center2.x, center2.y);
    selectedFigs[1]->setCenter(center1.x, center1.y);

 
    pOut->ClearDrawArea();
    pManager->UpdateInterface();

    pOut->PrintMessage("Figures swapped successfully.");
}