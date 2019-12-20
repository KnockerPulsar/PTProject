#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include <iostream>
#include "Card.h"
#include "CardTwelve.h"
#include "CellPosition.h"
#include "Player.h" 

using namespace std;

bool CardTwelve::bought=false;
Player* CardTwelve::owner=NULL;
int CardTwelve::cardprice=0;
int CardTwelve::cardfees=0;

CardTwelve::CardTwelve(const CellPosition & pos) : Card(pos)
{
	Card::SetCardNumber( 12 );
}


CardTwelve::~CardTwelve(void)
{
}

void CardTwelve :: setprice ( int cprice )
{
	if ( cprice > 0 )
		cardprice = cprice;
}

void CardTwelve :: setfees ( int f )
{
	if ( f > 0 )
		cardfees = f;
}

int CardTwelve :: getfees()
{
	return cardfees;
}


void CardTwelve::setbought (bool b)  
{
	bought = b;
}

Player* CardTwelve :: getowner()
{
	return owner;
}

void CardTwelve :: ReadCardParameters( Grid * pGrid )
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

void CardTwelve :: Apply(Grid* pGrid, Player* pPlayer)
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

void CardTwelve::setowner(Player* pPlayer)
{
	owner = pPlayer;
}