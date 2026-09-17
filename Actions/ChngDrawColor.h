#ifndef CHNG_DRAW_COLOR_ACTION_H
#define CHNG_DRAW_COLOR_ACTION_H

#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class ChngDrawColor : public Action
{
private:
    color FillClr;  // The color to fill with

public:
    ChngDrawColor(ApplicationManager* pApp);

    // Reads parameters required for action to execute
    virtual void ReadActionParameters();

    // Execute action
    virtual void Execute();
};

#endif