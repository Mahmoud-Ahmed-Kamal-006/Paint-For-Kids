#include "Load.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures/CRectangle.h"  
#include "..\Figures/CCircle.h"  
#include "..\Figures/CTriangle.h"  
#include "..\Figures/CHexagon.h"  
#include "..\Figures/CSquare.h"

Load::Load(ApplicationManager* pApp) : Action(pApp) {

}

void Load::ReadActionParameters() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMessage("Enter filename to load ");
	filename = pIn->GetSrting(pOut);
}

void Load::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		pOut->PrintMessage("Error: File not found.");
		return;
	}
	pManager->ClearAllFigures();
	pOut->ClearDrawArea();
	pManager->loadAll(inputFile);
	inputFile.close();
	pOut->PrintMessage("File loaded successfully.");

}


