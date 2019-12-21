#pragma once
#include "Action.h"
class CopyCardAction :
	public Action
{
	Card *copiedcard;
	CellPosition CardPosition;
public:
	CopyCardAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

