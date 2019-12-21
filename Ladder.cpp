#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() > endCellPos.VCell()) 
	{   // done - Ayman
		this->endCellPos = endCellPos;
	}
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
    Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a ladder.");     //done - Ayman
																		// missing wait mouse clicked and below
	                                                                    // getcellclicked
	pIn->GetCellClicked();                                              // done - Ayman
	pOut->PrintMessage("click anywhere to continue");                    // done - Ayman 
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);                               //done - Ayman
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Save(ofstream &OutFile , ObjectType LadderType , Ladder * pLadder)
{
	int startCell = pLadder->GetPosition().GetCellNumFromPosition(pLadder->GetPosition());
	int endCell = pLadder->GetEndPosition().GetCellNumFromPosition(pLadder->GetEndPosition());
	
}



Ladder::~Ladder()
{
}
