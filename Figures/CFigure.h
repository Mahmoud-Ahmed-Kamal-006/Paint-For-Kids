#ifndef CFIGURE_H
#define CFIGURE_H
#include <fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"
#include "../CMUgraphicsLib/colors.h" 

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	static int LastID;
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool IsInside(Point P) const =0;	//check whether a point is inside the figure

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	// Get figure specific information as a string for the status bar
	virtual string GetInfo() const = 0;
	color GetFillClr() const;
	virtual string GetType() const = 0;


	virtual CFigure* Clone() const = 0;           // Create an exact copy of the figure
	virtual CFigure* Clone(Point newPos) const = 0; // Create a copy at a new position
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	
	virtual Point getCenter() = 0;
	virtual void setCenter(int x, int y) = 0;

	virtual void save(ofstream& outputFile) = 0;
	virtual void load(ifstream& inputFile) = 0;

	string colortostring(color c);
	color stringtocolor(string colorname);
	bool getIsFilled();

	// ID-related methods
	int GetID() const { return ID; }



	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif