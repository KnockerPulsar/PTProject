//Done By Abdullah


#include "CardThree.h"
#include "Cell.h"
#include "CellPosition.h"
#include "Ladder.h"
#include "GameObject.h"

CardThree::CardThree(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number
}


CardThree::~CardThree(void)
{
}


void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	if (UI.InterfaceMode==MODE_PLAY)
	{
		// 1- Call Apply() of the base class Card to print the message that you reached this card number
		Card::Apply(pGrid,pPlayer);
		// 2- Moving the player to start of the next ladder
		Cell * PlayerCurrentCell = pPlayer->GetCell(); //A pointer to class Cell to get the current cell of the player         
		CellPosition * PlayerCellPosition = &(PlayerCurrentCell ->GetCellPosition()); //A pointer to class CellPosition to get the cellposition of the player
		Ladder * NextLadder = pGrid->GetNextLadder(*PlayerCellPosition); //A pointer to class Ladder to get the address of the next Ladder object
		if(NextLadder != NULL) //If there is a Ladder object
		{
			CellPosition *NextLadderCell = & (NextLadder->GetPosition()); //Get the CellPosition of the NextLadder through the pointer to CellPosition Class
			int NumberOfCellsToMove = NextLadderCell->GetCellNumFromPosition(*NextLadderCell) - PlayerCellPosition->GetCellNumFromPosition(*PlayerCellPosition); 
			//Get the number of cells to move the player by subtrcating the cell number of the next ladder and the current cell number of the player
			pPlayer->Move(pGrid,NumberOfCellsToMove); //Moves the player to the start of the next ladder
		}
	}

	else if (UI.InterfaceMode == MODE_DESIGN )
	{
		ReadCardParameters(pGrid);
	}

}