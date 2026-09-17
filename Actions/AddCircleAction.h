#pragma once
#ifndef ADD_CIRC_ACTION_H  
#define ADD_CIRC_ACTION_H  

#include "Action.h"  

//Add circle Action class  
class AddCircAction : public Action
{
private:
    Point P1, P2; //circle's center and point on the circle  
    GfxInfo CircGfxInfo;
public:
    AddCircAction(ApplicationManager* pApp);

    //Reads circle parameters  
    virtual void ReadActionParameters();

    //Add circle to the ApplicationManager  
    virtual void Execute();

};

#endif
