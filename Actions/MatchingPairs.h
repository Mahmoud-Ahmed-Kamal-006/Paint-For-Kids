#pragma once
#include "Action.h"  
#include "../Figures/CFigure.h"  

class MatchingPairs : public Action
{
private:
	Point P1, P2;
	int score;
	int numfigs;
	CFigure** SelectedFigs;
	int indx;
public:
	MatchingPairs(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~MatchingPairs();
};
