#include "AddSnakeAction.h"                                                          //Ayman added all of this
#include "Input.h"
#include "Output.h"
#include "Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{

}
AddSnakeAction ::~AddSnakeAction() {

}


void AddSnakeAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	StartPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	EndPos = pIn->GetCellClicked();
	if (EndPos.HCell() == StartPos.HCell() && EndPos.VCell() > StartPos.VCell())        // done - Ayman
	{}
	else
	{
		EndPos.SetHCell(-1);
		EndPos.SetVCell(-1);
	}

		pOut->ClearStatusBar();

}

void AddSnakeAction::Execute() {
	ReadActionParameters();
	Snake* pSnake = new Snake(StartPos, EndPos);
	Grid* pGrid = pManager->GetGrid();
	bool Added = pGrid->AddObjectToCell(pSnake);
	if (!Added)
		pGrid->PrintErrorMessage("Error: Cell already has an object , click to continue ...");

}











