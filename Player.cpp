#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	cardeightflag = false;
	cardsevenflag = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet >= 0)                        //Jimmy - Validation that wallet isn't a negative value//
		this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"

	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);                         //Jimmy - Added this - Draws the player
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);                         //Jimmy - Added this - Draws the player with cell coor
	//To clear it away//
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;                                                                                                 //Jimmy - Increment turnCount everytime Move is executed//

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	if (GetTurnCount() >= 3)                                                                                     //Jimmy - Every 3 turns players do not move but recharge their wallet
	{                                                                                                            //This is that validation//
		int Charge = diceNumber*10;
		wallet += Charge;
		turnCount = 0;                                                                                            //Jimmy - Reset turnCount//
		diceNumber = 0;                                                                                           //Jimmy - Set diceNumber to zero so that players don't move//
	}
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber
	SetJustRolledDiceNum(diceNumber);
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	CellPosition Position = pCell->GetCellPosition();                                                             //Jimmy - Get player Position//
	//    Using the appropriate function of CellPosition class to update "pos"
	Position.AddCellNum(diceNumber);                                                                               //Jimmy - change the position to new poistion with diceNumber value//
	if (Position.GetCellNum() > 99)                                                                                //Jimmy - Validation to make sure that player doesn't
	{                                                                                                              //Get out of the boundary of the cells//
		Position = Position.GetCellPositionFromNum(99);                                                            //Jimmy - Set the player cell to the end cell//
	}
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	pGrid->UpdatePlayerCell(this,Position);                                                                         //Jimmy - Update player cell with the new position//
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)
	GameObject * PGO = pCell->GetGameObject();                                                                       //Jimmy - Check if there is a game object in the new position//
	if (PGO != NULL)
	{
		PGO->Apply(pGrid,this);                                                                                      //Jimmy - If there is, Apply it//
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (Position.GetCellNum() >= 99)                                                                                 //Jimmy - Check if the player has reached end cell//
	{
		pGrid->SetEndGame(true);
	}
}

void Player::SetJustRolledDiceNum(int DN)
{
	justRolledDiceNum = DN;
}

int Player::GetPlayerNumber()
{
	return playerNum;
}

void Player::SetTurnCount(int TC)
{
	if (TC >= 0 && TC <=3)
		turnCount = TC;
}

int Player::GetJustRolledDiceNum()
{
	return justRolledDiceNum;
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}