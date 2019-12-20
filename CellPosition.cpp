#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)                    //Done - Tarek//
	if ( v > -1 && v <= 8 ) //60 is the height of the status bar, 555 is the bottom of the toolbar.
	{
		vCell=v;
		return true;
	}
	else return false; 
	// this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)                     //Done - Tarek//
	if ( h > -1  && h <= 10 )
	{
		hCell = h;
		return true;
	}

	else return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file                                                    //Done - Tarek//
	if (vCell > -1 && vCell <= 8 && hCell > -1 && hCell <= 10 )
		return true;
	else return false;

	//return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file                             //Done - Tarek//

	int cellnum = ( 8 - cellPosition.VCell() ) * 11 + 1 + cellPosition.HCell();
	return cellnum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	int vcellvalue = 0;
	int hcellvalue = 0;

	/// (Done)TODO: Implement this function as described in the .h file

	vcellvalue = 8-(cellNum+cellNum/12)/12;
	position.SetVCell(vcellvalue);
	hcellvalue = cellNum-11*abs(vcellvalue-8)-1;
	position.SetHCell(hcellvalue);


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	CellPosition TheCellWereAddingto;	
	TheCellWereAddingto.vCell = vCell;
	TheCellWereAddingto.hCell = hCell;

	///(Done)TODO: Implement this function as described in the .h file

	int OriginalCellNumber = TheCellWereAddingto.GetCellNum();
	int NewCellNumber = OriginalCellNumber + addedNum;

	TheCellWereAddingto = TheCellWereAddingto.GetCellPositionFromNum(NewCellNumber);	

	vCell = TheCellWereAddingto.vCell;
	hCell = TheCellWereAddingto.hCell;

	// Note: this function updates the data members (vCell and hCell) of the calling object

}