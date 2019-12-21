#include "CopyCardAction.h"
#include "Card.h"
#include "Grid.h"
#include "AddCardAction.h"
#include "CellPosition.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{

}


void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("please click on the card you would like to copy");
	CardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void CopyCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	copiedcard = dynamic_cast<Card*>(pGrid->GetCellObject(CardPosition));
	pGrid->SetClipboard(copiedcard);
}