#include "CutCardAction.h"
#include "Grid.h"
#include "DeleteGameObjectAction.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}
void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the card you would like to cut");
	cutcardpos = pIn->GetCellClicked();

}
void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->RemoveObjectFromCell(cutcardpos);

}