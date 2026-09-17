#pragma once  
#include "Action.h"  
#include "../Figures/CFigure.h"
#include <ctime>
#include <cstdlib>
#include <conio.h>
class MissingShapes : public Action {
	CFigure** Templist;
	CFigure* const* OriginalList;
	int numfigsleft;
	int tempnum;
	int score;
public:
	MissingShapes(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	string setlowercase(string text);
	~MissingShapes();
};