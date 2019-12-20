#include "NewGameAction.h"
#include "Player.h"
#include "Grid.h"


NewGameAction::NewGameAction(ApplicationManager *pApp)
	: Action(pApp)
{

}

void NewGameAction::ReadActionParameters()
{
	//Jimmy - No Parameters are needed//
}

void NewGameAction::Execute()
{
	Grid * PGRID = pManager->GetGrid();
	for (int i = 0;i<4;i++)                         //Jimmy - This loop Resets all player wallets to the initial 100//
	{
		Player * PP = PGRID->GetCurrentPlayer();
		PP->SetWallet(100);
		PGRID->AdvanceCurrentPlayer();
	}
	CellPosition Start (8,0);                       //Jimmy - intial Player position at the start of the game//
	for (int i = 0;i<4;i++)                         //Jimmy - This loop resets the player positions and their turncount//
	{
		Player * PP = PGRID->GetCurrentPlayer();
		PGRID->UpdatePlayerCell(PP,Start);
		PP->SetTurnCount(0);
		PGRID->AdvanceCurrentPlayer();
	}
	for (int i = 0;i<4;i++)                           //Jimmy - This loop resets the current player number to zero//
	{
		Player * PP = PGRID->GetCurrentPlayer();
		if (PP->GetPlayerNumber() != 0)
		{
			PGRID->AdvanceCurrentPlayer();
		}
	}
}

NewGameAction::~NewGameAction()
{

}
