#include "EditCardAction.h"
#include "Grid.h"
#include "Card.h"
#include "CellPosition.h"
#include "AddCardAction.h"

EditCardAction::EditCardAction( ApplicationManager* pApp ) : Action(pApp) 
{
}


EditCardAction::~EditCardAction(void)
{
}

void EditCardAction :: ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* optr = pGrid->GetOutput();
	Input* inptr = pGrid->GetInput();

	optr->PrintMessage("Please click on the card you'd like to edit ");
	CellPosition CardPosition = inptr->GetCellClicked(); //Gets the position of the card clicked.
	GameObject* pGO = pGrid->GetCellObject(CardPosition);

	pGO->Apply(pGrid,NULL);
}

void EditCardAction::Execute()
{
	ReadActionParameters();
}
