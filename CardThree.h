//Done By Abdullah


#pragma once

#include "card.h"

// [ CardThree ] Summary:
// Its Apply() Function: Moves the player to the Start of the next Ladder
// It has no Parameters
class CardThree :
	public Card
{
public:
	CardThree(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	                                                  // by moving the player's to the  start of the next ladder
	
	
	virtual ~CardThree(void);
};

