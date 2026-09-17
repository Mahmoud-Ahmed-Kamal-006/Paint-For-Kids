#ifndef FILL_COLOR_ACTION_H
#define FILL_COLOR_ACTION_H

#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class FillColorAction : public Action
{
private:
    color FillClr;  // The color to fill with

public:
    FillColorAction(ApplicationManager* pApp);

    // Reads parameters required for action to execute
    virtual void ReadActionParameters();

    // Execute action
    virtual void Execute();
};

#endif