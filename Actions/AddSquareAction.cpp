#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSQAction::AddSQAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSQAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center of square");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	SQGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SQGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SQGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSQAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare* S = new CSquare(P1, SQGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(S);
}
