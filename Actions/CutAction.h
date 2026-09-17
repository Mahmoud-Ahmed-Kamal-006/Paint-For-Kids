#ifndef CUT_ACTION_H
#define CUT_ACTION_H

#include "Action.h"


class CutAction : public Action
{
public:
    CutAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual void Execute();
};

#endif