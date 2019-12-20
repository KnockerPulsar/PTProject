#include "SwitchToPlaymodeAction.h"


SwitchToPlaymodeAction::SwitchToPlaymodeAction(ApplicationManager *pApp) : Action(pApp)
{
}


SwitchToPlaymodeAction::~SwitchToPlaymodeAction(void)
{
}


void SwitchToPlaymodeAction :: ReadActionParameters() //No need for this function, Implemented because of the pure virtual function.
{
}

void SwitchToPlaymodeAction :: Execute()
{
	pManager->ExecuteAction(TO_PLAY_MODE);
}