//Done By Abdullah


#pragma once

#include "card.h"

// [ CardFour ] Summary:
// Its Apply() Function: Moves the player to the Start of the next Snake
// It has no Parameters
class CardFour :
	public Card
{
public:
	CardFour(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
	                                                  // by moving the player's to the  start of the next Snake
	
	
	virtual ~CardFour(void);
};

