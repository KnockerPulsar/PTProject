#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CardEleven.h"
#include "CellPosition.h"
#include "Player.h" 

using namespace std;

bool CardEleven::bought=false;
Player* CardEleven::owner=NULL;
int CardEleven::cardprice=0;
int CardEleven::cardfees=0;

CardEleven::CardEleven(const CellPosition & pos) : Card(pos)
{
	Card::SetCardNumber( 11 );
}


CardEleven::~CardEleven(void)
{
}

void CardEleven :: setprice ( int cprice )
{
	if ( cprice > 0 )
		cardprice = cprice;
}

void CardEleven :: setfees ( int f )
{
	if ( f > 0 )
		cardfees = f;
}

int CardEleven :: getfees()
{
	return cardfees;
}


void CardEleven::setbought (bool b)  
{
	bought = b;
}

Player* CardEleven :: getowner()
{
	return owner;
}

void CardEleven :: ReadCardParameters( Grid * pGrid )
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

void CardEleven :: Apply(Grid* pGrid, Player* pPlayer)
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

void CardEleven::setowner(Player* pPlayer)
{
	owner = pPlayer;
}