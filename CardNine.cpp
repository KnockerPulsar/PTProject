#include "CardNine.h"


CardNine::CardNine(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid * pGrid)
{
	Output * pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter CellNumber");
	CellNum = pIn->GetInteger(pOut);  //Get the CellNumber that the player wants to teleport to
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	if (UI.InterfaceMode == MODE_PLAY)
	{
	Card::Apply(pGrid,pPlayer);  
	pPlayer = pGrid->GetCurrentPlayer();
	CellPosition Destination = Destination.GetCellPositionFromNum(CellNum);  //Jimmy - Create a CellPosition and set it to the CellPosition
	pGrid->UpdatePlayerCell(pPlayer,Destination);                            //corresponding to the CellNumber that the player inputed//
	Cell* pCell = pPlayer->GetCell();
	GameObject* PGO = pCell->GetGameObject();
	if (PGO != NULL)                                                         //Jimmy - Validation to check if the player's new cell has a game object 
	{                                                                        //and applies it if it does have a game object//
		PGO->Apply(pGrid, pPlayer);
	}
	}
	if (UI.InterfaceMode == MODE_DESIGN )
	{
		ReadCardParameters(pGrid);
	}
	}

CardNine::~CardNine()
{
}
