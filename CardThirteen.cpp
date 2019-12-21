#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"Card.h"
#include"CardThirteen.h"
#include "CellPosition.h"
#include "Player.h"

using namespace std;


CardThirteen::CardThirteen(const CellPosition & pos) : Card(pos)
{
	Card::SetCardNumber( 13 );
}


CardThirteen::~CardThirteen(void)
{
}

void CardThirteen :: setprice ( int cprice )
{
	if ( cprice > 0 )
		cardprice = cprice;
}

void CardThirteen :: setfees ( int f )
{
	if ( f > 0 )
		cardfees = f;
}

int CardThirteen :: getfees()
{
	return cardfees;
}


int CardThirteen :: getowner()
{
	return owner;
}

void CardThirteen :: ReadCardParameters( Grid * pGrid )
{
	Output * optr = pGrid->GetOutput();
	Input * inptr = pGrid ->GetInput();

	optr -> PrintMessage("Please enter card price");
	int priceofcard = inptr -> GetInteger(optr);
	setprice(priceofcard);

	optr -> PrintMessage("Now, enter card fees");
	int feesofcard =inptr -> GetInteger(optr);
	setfees(feesofcard);
	optr->PrintMessage("Card 13 is now set!");

}

void CardThirteen :: Apply(Grid* pGrid, Player* pPlayer)
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

void CardThirteen::setowner(Player* pPlayer)
{
	owner = pPlayer->GetPlayerNumber();
}

void CardThirteen::setbought(bool b)
{
	bought = b;
}