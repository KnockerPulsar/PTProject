#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid * PGRID = pManager->GetGrid();
	bool GameState = PGRID->GetEndGame();                                                     //Jimmy - Check if the game has ended//
	// -- If not ended, do the following --:
	if ( GameState != true)
	{
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

		// 3- Get the "current" player from pGrid
		Player * PP;

		PP = PGRID->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		if (PP->cardeightflag == true)                                    //Ayman - if condition to check card8 flag
		{ 
		     PP->cardeightflag = false;                                   //Ayman - resetting card8 flag again (if card eight -> dont move next turn)
		}
		else
		{
			PP->Move(PGRID, diceNumber);
		}
		// 5- Advance the current player number of pGrid
		if (PP->cardsevenflag == true)                                    //Ayman - if condition to check card7 flag
		{
			PP->cardsevenflag = false;                                    //Ayman - resetting card7 flag again
		}
		else
		{
			PGRID->AdvanceCurrentPlayer();                                //Ayman - if card7flag is true,player can play again
		}

		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
	else                                                                                  //Jimmy - If the game has ended//
	{
		Output * POUT = PGRID->GetOutput();
		Player * PP;
		PP = PGRID->GetCurrentPlayer();
		POUT->PrintMessage("The Winner is Player ");
		POUT->PrintInteger(PP->GetPlayerNumber(),"The Winner is Player ");
	}
}

RollDiceAction::~RollDiceAction()
{
}
