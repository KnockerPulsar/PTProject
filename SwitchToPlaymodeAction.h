#pragma once
#include "action.h"
class SwitchToPlaymodeAction :
	public Action
{
public:
	SwitchToPlaymodeAction(void);
	~SwitchToPlaymodeAction(void);

	SwitchToPlaymodeAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

