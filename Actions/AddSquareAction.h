#pragma once
#ifndef ADD_SQ_ACTION_H
#define ADD_SQ_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSQAction : public Action
{
private:
	Point P1; //Square Center
	GfxInfo SQGfxInfo;
public:
	AddSQAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

};

#endif