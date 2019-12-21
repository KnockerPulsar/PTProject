#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"
#include "Input.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp)
	: Action(pApp)
{

}

void InputDiceValueAction::ReadActionParameters()
{
	//No parameters are needed
}

void InputDiceValueAction::Execute()
{
	Grid* PGRID = pManager->GetGrid();                //Jimmy - Creation of an Grid pointer and it's initialisation//
	Input* PIN = PGRID->GetInput();                   //Jimmy - Creation of an Input pointer and it's initialisation// 
	Output* POUT = PGRID->GetOutput();                //Jimmy - Creation of an Output pointer and it's initialisation//
	bool GameState = PGRID->GetEndGame();              //Jimmy - Checking weather the game has ended or not//
	if (GameState != true)                            //Jimmy - If the game hasn't ended// 
	{
		POUT->PrintMessage("Please enter a dice value between 1-6");
		int diceNumber = PIN->GetInteger(POUT);
		if (diceNumber >= 1 && diceNumber <= 6)       //Jimmy - Validation for Dice value//  
		{
			Player* PP;
			PP = PGRID->GetCurrentPlayer();
			if (PP->getcardeightflag() == true)                            //Ayman - if condition to check card8 effect
			{
				PP->setcardeightflag(false);                            //Ayman - resetting card8 flag again
			}
			else
			{

				PP->Move(PGRID, diceNumber);               //Jimmy - Moving the players by the value of the diceNumber that they have rolled//
			}
			if (PP->getcardsevenflag() == true)                            //Ayman - if condition to check card7 effect
			{
				PP->setcardsevenflag(false);                            //Ayman - resetting card7 flag again
			}
			else
			{

				PGRID->AdvanceCurrentPlayer();            //Jimmy - Changing the player number//
			}
		}
		else                                          //Jimmy - Invalid Dice Value//
		{
			POUT->PrintMessage("Invalid Input : Click to Continue");
			pManager->GetUserAction();                //Jimmy - Small Pause so that the player can see the message above this line//
			Execute();                                //Jimmy - call this function again so the player can input the correct values//
		}

	}
	else                                              //Jimmy - If the game has ended//
	{
		Output* POUT = PGRID->GetOutput();
		Player* PP;
		PP = PGRID->GetCurrentPlayer();                //Jimmy - Not sure what i'm supposed to do in this case//
		POUT->PrintMessage("The Winner is Player ");
		POUT->PrintInteger(PP->GetPlayerNumber(), "The Winner is Player ");
	}
}

InputDiceValueAction::~InputDiceValueAction()
{

}
