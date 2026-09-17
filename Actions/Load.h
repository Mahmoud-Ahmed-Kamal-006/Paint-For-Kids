#pragma once
#include "../Figures/CFigure.h"  
#include "Action.h"   
#include "..\ApplicationManager.h"



class Load : public Action {
	string filename;
public:
	Load(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
    color StringToColor(string colorName) {
        if (colorName == "BLACK") return BLACK;
        if (colorName == "BLUE") return BLUE;
        if (colorName == "GREEN") return GREEN;
        if (colorName == "RED") return RED;
        if (colorName == "WHITE") return WHITE;
        return BLACK; 
    }
};
