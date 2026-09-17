#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

// Class responsible for copying selected figures
class CopyAction : public Action
{
public:
    CopyAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};