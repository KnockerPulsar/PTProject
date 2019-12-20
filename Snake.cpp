#include "Snake.h"                                                                 //Ayman added all of this

Snake::Snake(CellPosition & StartCellPos, CellPosition& EndCellPos) : GameObject(StartCellPos)
{
	if (StartCellPos.HCell() == EndCellPos.HCell() && StartCellPos.VCell() < EndCellPos.VCell()){
		this->endCellPos = EndCellPos;
	}
}
void Snake::Draw(Output * pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("you have reached a snake...");
	pIn->GetCellClicked();
	pOut->PrintMessage("click anywhere");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}


Snake :: ~Snake() 
{
}