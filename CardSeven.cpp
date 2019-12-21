#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;                                                         //constructor to draw cardnumber
}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("you have reached card seven, you can roll dice again, click to continue");
	pIn->GetCellClicked();
	pPlayer->cardsevenflag = true;                                          //flagging to enable card7 effect
	pOut->ClearStatusBar();
}