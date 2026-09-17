#pragma once  
#include "../Figures/CFigure.h"  
#include "Action.h"   


class SelectAction : public Action  
{  
protected:  
   Point ClickedP; //clicked point  

   CFigure* SelectedFig; // Pointer to the selected figure

public:  
   SelectAction(ApplicationManager* pApp);  
   virtual void ReadActionParameters();  
   virtual void Execute();  
   //good
};