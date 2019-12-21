#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"Card.h"
#include"CardTen.h"
#include "CellPosition.h"
#include "Player.h"
#include "SwitchToDesignModeAction.h"
#include "SwitchToPlaymodeAction.h"
using namespace std;


CardTen::CardTen(const CellPosition & pos) : Card(pos)
{
	Card::SetCardNumber( 10 );
}


CardTen::~CardTen(void)
{
}

void CardTen :: setprice ( int cprice )
{
	if ( cprice > 0 )
		cardprice = cprice;
}

void CardTen :: setfees ( int f )
{
	if ( f > 0 )
		cardfees = f;
}

int CardTen :: getfees()
{
	return cardfees;
}

//bool CardTen :: isbought() 
//{
//	return bought;
//}

void CardTen::setbought (bool b)  
{
	bought = b;
}

int CardTen :: getowner()
{
	return owner;
}

void CardTen :: ReadCardParameters( Grid * pGrid )
{
	Output * optr = pGrid->GetOutput();
	Input * inptr = pGrid ->GetInput();

	optr -> PrintMessage("Please enter card price");
	int priceofcard = inptr -> GetInteger(optr);
	setprice(priceofcard);

	optr -> PrintMessage("Now, enter card fees");
	int feesofcard =inptr -> GetInteger(optr);
	setfees(feesofcard);

	optr->PrintMessage("Card 10 is now set!");

	

}

void CardTen :: Apply(Grid* pGrid, Player* pPlayer)
{
	Output * optr = pGrid->GetOutput();
	Input * inptr = pGrid ->GetInput();

	if (UI.InterfaceMode==MODE_PLAY)
	{

		if ( isbought() == false )
		{
			optr->PrintMessage("Do you want to buy this card? (y/n) ");
			string choice = inptr->GetSrting(optr);
			if ( choice == "Y" || choice == "y" )
			{
				if (pPlayer->GetWallet() >= cardprice)
				{
					optr->PrintMessage("Card is now bought!");
					setbought(true);
					pPlayer->SetWallet(pPlayer->GetWallet() - cardprice); //Deducts the cards price from the player.
					setowner(pPlayer);

				}
				else		
				{
					optr->PrintMessage("Not enough funds");
				}
			}

			else {} //If the card isn't bought and the user chooses to not buy it, do nothing.
		}
		else
		{
			if ( pPlayer->GetPlayerNumber() != owner )
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - cardfees);
			}

			else {} //If the card is bought and the owner is currently in it, do nothing.
		}

	}
	else if (UI.InterfaceMode == MODE_DESIGN )
	{
		ReadCardParameters(pGrid);
	}
}

void CardTen::setowner(Player* pPlayer)
{
	owner = pPlayer->GetPlayerNumber();
}