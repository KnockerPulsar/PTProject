#pragma once
#include "Action.h"
class PasteCardAction :
	public Action
{
	Card* pastedcard;
	CellPosition pastedcardpos;
public:
	PasteCardAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

