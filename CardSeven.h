#pragma once
#include "Card.h"
class CardSeven :
	public Card
{
public:
	CardSeven(const CellPosition& pos);                            //constructor to display cardnumber
	void Apply(Grid* pGrid, Player* pPlayer);                      //to apply the effect of the card on the passed player pointer
};

