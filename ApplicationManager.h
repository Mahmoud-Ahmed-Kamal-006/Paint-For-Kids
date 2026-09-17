#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void UnselectAll(); //Unselect all figures	
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	void ClearAllFigures();

	void GetSelectedFiguresCounts(int& rectCount, int& circCount, int& triCount, int& hexCount, int& sqCount, int& totalSelected, CFigure*& singleSelectedFig) const;
	//edits
	int getMax() const;
	int getFigCount() const;
	CFigure* const* getFigList() const;
	void saveAll(string filename);
	void loadAll(ifstream& inputFile);
	void SetClipboard(CFigure* fig);      // Set the clipboard pointer
	CFigure* GetClipboard() const;        // Get the clipboard pointer

	void DeleteSelectedFigures(); // Delete selected figures

	//end of edits
};

#endif