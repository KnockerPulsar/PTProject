#include "CardFive.h"


CardFive::CardFive(const CellPosition & pos) : Card(pos)
{
	cardNumber = 5;
}

void CardFive::ReadCardParameters(Grid * pGrid)
{
	// No Parameters to Read
}

void CardFive::Apply(Grid * pGrid,Player * pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pPlayer = pGrid->GetCurrentPlayer();
	Cell * PlayerCell = pPlayer->GetCell();                           //Jimmy - Cell Pointer to Player cell//
	CellPosition Position = PlayerCell->GetCellPosition();            //Jimmy - CellPosition that points to Player CellPosition//
	Position.AddCellNum(pPlayer->GetJustRolledDiceNum());             //Jimmy - Update the CellPosition with the value of the JustRolledDiceNum - Since it's a positive Value, Player Moves Forward the same number of steps that he just rolled//
	pGrid->UpdatePlayerCell(pPlayer,Position);                        //Jimmy - Update PlayerCell with the Updated CellPosition//
}

CardFive::~CardFive(void)
{

}
