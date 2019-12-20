//Done By Abdullah


#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number
}


CardFour::~CardFour(void)
{
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	if (UI.InterfaceMode==MODE_PLAY)
	{
		// 1- Call Apply() of the base class Card to print the message that you reached this card number
		Card::Apply(pGrid,pPlayer);
		// 2- Moving the player to start of the next snake

		Cell * PlayerCurrentCell = pPlayer->GetCell(); //A pointer to class Cell to get the current cell of the player         
		
		CellPosition * PlayerCellPosition = &(PlayerCurrentCell ->GetCellPosition()); //A pointer to class CellPosition to get the cellposition of the player
		
		Snake * NextSnake = pGrid->GetNextSnake(* PlayerCellPosition); //A pointer to class Snake to get the address of the next Snake object

		if(NextSnake != NULL) //If there is a Ladder object
		{
			CellPosition *NextSnakeCell = & (NextSnake->GetPosition()); //Get the CellPosition of the NextSnake through the pointer to CellPosition Class

			int NumberOfCellsToMove = NextSnakeCell->GetCellNumFromPosition(*NextSnakeCell) - PlayerCellPosition->GetCellNumFromPosition(*PlayerCellPosition); 
			//Get the number of cells to move the player by subtrcating the cell number of the next snake and the current cell number of the player

			pPlayer->Move(pGrid,NumberOfCellsToMove); //Moves the player to the start of the next snake
		}
	}

	else if (UI.InterfaceMode == MODE_DESIGN )
	{
		ReadCardParameters(pGrid);
	}
}