#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CardTen.h"
#include "CellPosition.h"
#include "Player.h" 

using namespace std;

bool CardTen::bought=false;
Player* CardTen::owner=NULL;
int CardTen::cardprice=0;
int CardTen::cardfees=0;

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


void CardTen::setbought (bool b)  
{
	bought = b;
}

Player* CardTen :: getowner()
{
	return owner;
}

void CardTen :: ReadCardParameters( Grid * pGrid )
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

void CardTen :: Apply(Grid* pGrid, Player* pPlayer)
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

void CardTen::setowner(Player* pPlayer)
{
	owner = pPlayer;
}