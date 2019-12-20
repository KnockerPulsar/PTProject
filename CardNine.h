#pragma once
#include "Card.h"
class CardNine
	: public Card
{
	int CellNum;        //Jimmy - Number of the cell that the player will to go to//
public:
	CardNine(const CellPosition & pos);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~CardNine();
};

