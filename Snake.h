#pragma once                                                                                // Ayman added all of this
#include "GameObject.h"
#include "DEFS.h"

class Snake : public GameObject                      // inherited from gameobject
{

	CellPosition endCellPos;

public:
	
	Snake(CellPosition & startCell , CellPosition & endCell);      //a constructor for initialization
	
	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Snake(); // Virtual destructor
};

