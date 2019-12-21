#include "CardEight.h"                                             //Ayman added all of this
CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;                                                 //constructor to draw cardnumber
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("you have reached card eight, you can't play next turn, click to continue");
	pIn->GetCellClicked();
	pPlayer->setcardeightflag(true);                                     //the flag so that the player cannot move next turn
	pOut->ClearStatusBar();                                            	// 3- Clear the status bar
}
