#pragma once
#include "../Figures/CFigure.h"  
#include "Action.h"   
#include "..\ApplicationManager.h"

class Swap : public Action {
public:
	Swap(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
