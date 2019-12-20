#pragma once
#include "Card.h"
class CardSix
	: public Card
{
public:
	CardSix(const CellPosition & pos);
	void virtual ReadCardParameters(Grid * pGrid);
	void virtual Apply(Grid * pGrid,Player * pPlayer);
	~CardSix();
};

