//// Done By Abdullah

#include "CardTwo.h"


CardTwo::CardTwo(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber=2; // set the inherited cardNumber data member with the card number
}


CardTwo::~CardTwo(void)
{
}


void CardTwo::ReadCardParameters(Grid * pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output * optr = pGrid->GetOutput();
	Input * inptr = pGrid ->GetInput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	optr->PrintMessage("New CardTwo: Enter the increment amount ...");
	walletAmount= inptr->GetInteger(optr);

	// 3- Clear the status bar
	optr->ClearStatusBar();
}


void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	// 2- Increment the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet()+walletAmount);
}