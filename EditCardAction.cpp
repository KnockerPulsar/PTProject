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

	Cell ClickedCell(CardPosition);
	ClickedCell.SetGameObject(pGO);

	if ( ClickedCell.HasCard() != NULL)
	{
		pGO->Apply(pGrid,NULL);
	}
	else if (ClickedCell.HasLadder() != NULL) {optr->PrintMessage("Card editing doesn't work on ladders..");}
	else if (ClickedCell.HasSnake() != NULL) {optr->PrintMessage("Card editing doesn't work on snakes..");}
	else {optr->PrintMessage("This cell has no card!");}
}

void EditCardAction::Execute()
{
	ReadActionParameters();
}
