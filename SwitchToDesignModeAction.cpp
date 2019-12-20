#include "SwitchToDesignModeAction.h"


SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
}


SwitchToDesignModeAction::~SwitchToDesignModeAction(void)
{
}

void SwitchToDesignModeAction :: ReadActionParameters()
{
}

void SwitchToDesignModeAction::Execute()
{
	pManager->ExecuteAction(TO_DESIGN_MODE);
}