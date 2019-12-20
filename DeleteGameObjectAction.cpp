#include "DeleteGameObjectAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "CellPosition.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager *pApp) 
	: Action(pApp)
{

}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid * PGRID = pManager->GetGrid();                //Jimmy - Creation of an Grid pointer and it's initialisation//
	Input * PIN = PGRID->GetInput();                   //Jimmy - Creation of an Input pointer and it's initialisation// 
	Output * POUT = PGRID->GetOutput();                //Jimmy - Creation of an Output pointer and it's initialisation//
	CP = PIN->GetCellClicked();                        //Jimmy - Obtaining the CellPosition of the game object being deleted//
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();                            //Jimmy - Using this function to obtain the Position of the game object//
	Grid * PGRID = pManager->GetGrid();
	PGRID->RemoveObjectFromCell(CP);                   //Jimmy - Using Grid Function to remove The game object Pointer from the cell
}                                                      //I had to edit the function Cell::SetGameObject() so that it can remove game objects//  

DeleteGameObjectAction::~DeleteGameObjectAction()
{

}
