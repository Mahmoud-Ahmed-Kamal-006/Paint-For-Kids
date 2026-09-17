#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddHexagonAction.h"
#include "Actions\SwitchToPlay.h"
#include "Actions\SwitchToDraw.h"
#include "Actions\select.h"
#include "Actions\ClearAllAction.h"
#include "Figures\CRectangle.h"
#include "Figures\CCircle.h"
#include "Figures\CTriangle.h"
#include "Figures\CHexagon.h"
#include "Figures\CSquare.h"
#include "Actions\MatchingPairs.h"
#include "Actions\MissingShapes.h"
#include "Actions\Swap.h"
#include "Actions\Save.h"
#include "Actions\Load.h"
#include "Actions\DeleteAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\FillColorAction.h"
#include "Actions/ChngDrawColor.h"
#include "Actions\CutAction.h"
#include "Actions\ExitAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	Clipboard = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_CIRC:
		///create AddCircAction here
		pAct = new AddCircAction(this);
		break;
	case DRAW_TRI:
		///create AddTriAction here
		pAct = new AddTriAction(this);
		break;
	case DRAW_HEX:
		///create AddHexAction here
		pAct = new AddHexAction(this);
		break;
	case DRAW_SQ:
		///create AddSquareAction here
		pAct = new AddSQAction(this);
		break;
	case SWAP:
		pAct = new Swap(this);
		break;
	case SAVE:
		pAct = new Save(this);
		break;
	case LOAD:
		pAct = new Load(this);
		break;
	case TO_PLAY:
		///create SwitchToPlay here
		pAct = new SwitchToPlay(this);
		break;
	case PLAY_MATCHING_SHAPE:
		pAct = new MatchingPairs(this);
		break;
	case PLAY_MISSING_SHAPE:
		pAct = new MissingShapes(this);
		break;
	case TO_DRAW:
		///create SwitchToDraw here
		pAct = new SwitchToDraw(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new FillColorAction(this);
		break;

	case CHNG_DRAW_CLR:
		pAct = new ChngDrawColor(this);
		break;

	
	case SELECT:
		///create SelectAction here
		pAct = new SelectAction(this);
		break;

	case CLR_ALL:
		pAct = new ClearAllAction(this);
		break;

	case COPY:
		//Copies the selected figure
		pAct = new CopyAction(this);
		break;

	case CUT:
		//Cut the selected figure
		pAct = new CutAction(this);
		break;

	case PASTE:
		// Paste The copied or cut figure
		pAct = new PasteAction(this);
		break;
	case DEL:
		//Delete the selected figure
		pAct = new DeleteAction(this);
		break;

	case EXIT:
		///create ExitAction here
		pAct = new ExitAction(this);

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount++] = pFig;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	Point P;
	P.x = x;
	P.y = y;

	// Loop through all figures starting from the most recently added (top figure)
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->IsInside(P))
		{
			return FigList[i];  // Return pointer to the figure
		}
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteSelectedFigures()
{
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i] && FigList[i]->IsSelected())
		{
			delete FigList[i];
			// Shift elements left to keep the array compact
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			FigList[FigCount - 1] = nullptr;
			FigCount--;
		}
	}
	pOut->ClearDrawArea();  // Clears the drawing area
	UpdateInterface();      // Redraws all figures
}

void ApplicationManager::SetClipboard(CFigure* fig)
{
	// If there's already something in the clipboard, delete it
	if (Clipboard != NULL)
		delete Clipboard;

	// If the figure is not NULL, create a clone
	if (fig != NULL)
		Clipboard = fig->Clone();
	else
		Clipboard = NULL;
}

CFigure* ApplicationManager::GetClipboard() const
{
	return Clipboard;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
// Unselect all figures This function is used when the user clicks on an empty area in the drawing area
void ApplicationManager::UnselectAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->SetSelected(false);
	}
}

void ApplicationManager::GetSelectedFiguresCounts(int& rectCount, int& circCount, int& triCount, int& hexCount, int& sqCount, int& totalSelected, CFigure*& singleSelectedFig) const
{
	// Initialize all counts to zero
	rectCount = 0;
	circCount = 0;
	triCount = 0;
	hexCount = 0;
	sqCount = 0;
	totalSelected = 0;
	singleSelectedFig = NULL;

	// Loop through all figures
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			// Increment total count
			totalSelected++;

			// If we have exactly one selected figure so far, store it
			if (totalSelected == 1)
				singleSelectedFig = FigList[i];
			else
				singleSelectedFig = NULL; // More than one figure is selected

			// Use the instanceof pattern to determine figure type
			// Check the class type of each figure
			if (dynamic_cast<CRectangle*>(FigList[i]) != NULL)
				rectCount++;

			else if (dynamic_cast<CTriangle*>(FigList[i]) != NULL)
				triCount++;
			else if (dynamic_cast<CHexagon*>(FigList[i]) != NULL)
				hexCount++;
			else if (dynamic_cast<CSquare*>(FigList[i]) != NULL)
				sqCount++;
			else if (dynamic_cast<CCircle*>(FigList[i]) != NULL)
				circCount++;
		}
	}
}

void ApplicationManager::ClearAllFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = nullptr;
	}
	FigCount = 0;
}

int ApplicationManager::getMax() const
{
	return MaxFigCount;
}
int ApplicationManager::getFigCount() const
{
	return FigCount;
}
CFigure* const* ApplicationManager::getFigList() const
{
	return FigList;
}

void  ApplicationManager::saveAll(string filename) {
	ofstream outputFile(filename);


	if (FigCount == 0) {
		pOut->PrintMessage("There no figures to be saved.");
		return;
	}

	for (int i = 0; i < FigCount; i++) {
		FigList[i]->save(outputFile);
	}
	outputFile.close();
}

void ApplicationManager::loadAll(ifstream& inputFile) {
	string type;
	while (inputFile >> type) {
		CFigure* pFig = nullptr;
		if (type == "RECTANGLE") {
			pFig = new CRectangle({}, {}, {});
		}
		else if (type == "SQUARE") {
			pFig = new CSquare({}, {});
		}
		else if (type == "CIRCLE") {
			pFig = new CCircle({}, {}, {});
		}
		else if (type == "TRIANGLE") {
			pFig = new CTriangle({}, {}, {}, {});
		}
		else if (type == "HEXAGON") {
			pFig = new CHexagon({}, {});
		}
		if (pFig) {
			pFig->load(inputFile);
			AddFigure(pFig);
		}
		else {
			break;
		}
	}
}

//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}


////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

	delete Clipboard;

}
