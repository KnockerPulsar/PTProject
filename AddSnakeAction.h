#pragma once                                                           //Ayman added all of this
#include "Action.h"
class AddSnakeAction : public Action
{
	CellPosition StartPos;
	CellPosition EndPos;
public :
	AddSnakeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddSnakeAction();


};

