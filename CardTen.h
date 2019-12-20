#pragma once
#include "card.h"

class Input;
class Output;
class CellPosition;

class CardTen :
	public Card
{
	static int cardprice;
	static int cardfees;
	static bool bought;
	static Player* owner;
public:
	CardTen();
	CardTen(const CellPosition &);
	virtual ~CardTen(void);


	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static void setprice( int cprice ); //Don't need a getter for now, add if needed.

	static void setfees( int f);
	static int getfees();

	static bool isbought() {return bought;} //Returns true if the card is bought, false if not.
	static void setbought(bool);

	static Player* getowner();
	static void setowner(Player* pPlayer);
};
