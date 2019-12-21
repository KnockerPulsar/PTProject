#include "CardSix.h"


CardSix::CardSix(const CellPosition & pos) : Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid * pGrid)
{
	// No Parameters to Read
}

void CardSix::Apply(Grid * pGrid,Player * pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pPlayer = pGrid->GetCurrentPlayer();
	Cell * PlayerCell = pPlayer->GetCell();                          //Jimmy - Cell Pointer to Player cell//
	CellPosition Position = PlayerCell->GetCellPosition();           //Jimmy - CellPosition that points to Player CellPosition//
	Position.AddCellNum(-(pPlayer->GetJustRolledDiceNum()));         //Jimmy - Update the CellPosition with the negative value of the JustRolledDiceNum - So, Player moves backward the same number of steps that he just rolled//
	pGrid->UpdatePlayerCell(pPlayer,Position);                       //Jimmy - Update PlayerCell with the Updated CellPosition//
	Cell* pCell = pPlayer->GetCell();
	GameObject* PGO = pCell->GetGameObject();
	if (PGO != NULL)                                                         //Jimmy - Validation to check if the player's new cell has a game object 
	{                                                                        //and applies it if it does have a game object//
		PGO->Apply(pGrid, pPlayer);
	}
}

CardSix::~CardSix()
{

}
