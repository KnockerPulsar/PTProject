#pragma once
#include "Card.h"
class CardFive
	: public Card
{
public:
	CardFive(const CellPosition & pos);
	void virtual ReadCardParameters(Grid * pGrid);
	void virtual Apply(Grid * pGrid,Player * pPlayer);
	~CardFive();
};

