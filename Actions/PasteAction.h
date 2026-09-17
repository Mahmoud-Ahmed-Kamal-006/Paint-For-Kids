#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

// Class responsible for pasting copied figures
class PasteAction : public Action
{
private:
    Point PastePoint; // Point where the figure will be pasted

public:
    PasteAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};