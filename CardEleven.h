#pragma once
#include "card.h"

class Input;
class Output;
class CellPosition;

class CardEleven :
	public Card
{
	int cardprice;
	int cardfees;
	static bool bought;
	int owner;
public:
	CardEleven();
	CardEleven(const CellPosition &);
	virtual ~CardEleven(void);


	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void setprice( int cprice ); //Don't need a getter for now, add if needed.

	void setfees( int f);
	int getfees();

	static bool isbought() {return bought;} //Returns true if the card is bought, false if not.
	static void setbought(bool);

	int getowner();
	void setowner(Player* pPlayer);
};

