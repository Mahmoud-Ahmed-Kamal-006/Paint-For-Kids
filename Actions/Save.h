#pragma once
#include "../Figures/CFigure.h"  
#include "Action.h"   
#include "..\ApplicationManager.h"





class Save : public Action {
	string filename;
public:
	Save(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
