#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CardFourteen.h"
#include "CellPosition.h"
#include "Player.h"
#include <iostream>

using namespace std;

bool CardFourteen::bought=false;
Player* CardFourteen::owner=NULL;
int CardFourteen::cardprice=0;
int CardFourteen::cardfees=0;

CardFourteen::CardFourteen(const CellPosition & pos) : Card(pos)
{
	Card::SetCardNumber( 14 );
}


CardFourteen::~CardFourteen(void)
{
}

void CardFourteen :: setprice ( int cprice )
{
	if ( cprice > 0 )
		cardprice = cprice;
}

void CardFourteen :: setfees ( int f )
{
	if ( f > 0 )
		cardfees = f;
}

int CardFourteen :: getfees()
{
	return cardfees;
}


void CardFourteen::setbought (bool b)  
{
	bought = b;
}

Player* CardFourteen :: getowner()
{
	return owner;
}

void CardFourteen :: ReadCardParameters( Grid * pGrid )
{
	Output * optr = pGrid->GetOutput();
	Input * inptr = pGrid ->GetInput();

	if (cardprice!=0)
	{}
	else 
	{
		optr -> PrintMessage("Please enter card price");
		int priceofcard = inptr -> GetInteger(optr);
		setprice(priceofcard);

		optr -> PrintMessage("Now, enter card fees");
		int feesofcard =inptr -> GetInteger(optr);
		setfees(feesofcard);
	}



}

void CardFourteen :: Apply(Grid* pGrid, Player* pPlayer)
{
	Output * optr = pGrid->GetOutput();
	Input * inptr = pGrid ->GetInput();

	if (UI.InterfaceMode==MODE_PLAY)
	{
		if ( bought == false && pPlayer->GetWallet() >= cardprice )
		{
			optr->PrintMessage("You have reached a station. Do you want to buy it ? (y/n) ");
			string choice = inptr->GetSrting(optr);
			if ( choice == "Y" || choice == "y" )
			{
				if (pPlayer->GetWallet() >= cardprice)
				{
					optr->PrintMessage("Card is now bought!");
					
					setbought(true);
					setowner(pPlayer);
					owner->SetWallet(owner->GetWallet() - cardprice); //Deducts the cards price from the player.
				}
			}

			else {} //If the card isn't bought and the user chooses to not buy it, do nothing.
		}
		else
		{
			if ( pPlayer != owner )
			{
				optr->PrintMessage("You have reached a bought station. Click to continue..");
				inptr->GetCellClicked();
				pPlayer->SetWallet(pPlayer->GetWallet() - cardfees);
				owner->SetWallet(owner->GetWallet() + cardfees);
			}

			else {} //If the card is bought and the owner is currently in it, do nothing.
		}

	}
	else if (UI.InterfaceMode == MODE_DESIGN )
	{
		ReadCardParameters(pGrid);
	}
}

void CardFourteen::setowner(Player* pPlayer)
{
	owner = pPlayer;
}