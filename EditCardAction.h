#pragma once
#include "action.h"
class EditCardAction :
	public Action
{
public:
	~EditCardAction(void);

	EditCardAction ( ApplicationManager* pApp );
	void ReadActionParameters();
	void Execute();
};

