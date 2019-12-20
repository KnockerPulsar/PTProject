#pragma once
#include "action.h"
class SwitchToDesignModeAction :
	public Action
{
public:
	SwitchToDesignModeAction(void);
	~SwitchToDesignModeAction(void);

	SwitchToDesignModeAction( ApplicationManager* pApp );
	void ReadActionParameters();
	void Execute();

};

