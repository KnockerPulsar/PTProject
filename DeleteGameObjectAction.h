#pragma once
#include "Action.h"
#include "CellPosition.h"
class DeleteGameObjectAction
	: public Action
{
private:
	CellPosition CP;                 //Jimmy - Parameter1 - Position of the Game Object being deleted//
public:                              //Jimmy - Snakes and ladders are defined by their first Cell position
	                                 //and not any other cell position//
	DeleteGameObjectAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DeleteGameObjectAction();
};

