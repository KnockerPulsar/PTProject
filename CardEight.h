#pragma once                                        //Ayman added all of this
#include "Card.h"
class CardEight :
	public Card
{
public:
	CardEight(const CellPosition& pos);                       //non default constructor to draw cardnumber
	
	                                                          // we dont need readcardparameters()
	void Apply(Grid* pGrid, Player* pPlayer);                 // to apply the effect of the card on the passed player pointer
};

