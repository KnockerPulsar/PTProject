#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

#include "CellPosition.h"

using namespace std;

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	//Done??? - Tarek

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid *pGrid = pManager->GetGrid();
	Input * inptr = pGrid->GetInput();
	Output * optr = pGrid->GetOutput();
	// 2- Read the "cardNumber" parameter and set its data member

	optr->PrintMessage("Please enter the card number");
	int cardnum = inptr->GetInteger(optr);
	int* cardnumptr = new int;
	*cardnumptr = cardnum;
	//while ( *cardnumptr >14 || *cardnumptr <1 ) //Might need this later.
	//{
	//	optr->PrintMessage("Invalid card number, please enter a value between 1 and 14");
	//	*cardnumptr = inptr->GetInteger(optr);
	//}
	cardNumber=*cardnumptr;

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	optr->PrintMessage("Please click the cell you'd like to add the card to");
	CellPosition cardpos = inptr->GetCellClicked();
	cardPosition = cardpos;


	// 4- Make the needed validations on the read parameters
	if ( cardnum > 14 &&  cardnum < 1 )
		cardnum = -1;

	// 5- Clear status bar
	optr->ClearStatusBar();

	delete cardnumptr;
}



void AddCardAction::Execute() 
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	//WIP-Tarek

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
		// A- Add the remaining cases	//Done-Tarek, unfinished classes were commented, please uncomment as you finish each class.

		//================================================================//

		//Added by Abduallah
	case 2:
		pCard = new CardTwo(cardPosition);
		break;

	case 3:
		pCard = new CardThree(cardPosition);
		break;

	case 4:
		pCard = new CardFour(cardPosition);
		break;

		//================================================================//

		//Need to be added by Jimmy
	case 5:
		pCard = new CardFive(cardPosition);
		break;

	case 6:
		pCard = new CardSix(cardPosition);
		break;

		//================================================================//

		//Need to be added by Ayman, done
		case 7:                                                        //Ayman added this
		pCard = new CardSeven(cardPosition);
		break;
		
		case 8:                                                        //Ayman added this
		pCard = new CardEight(cardPosition);
		break;

		//================================================================//

		//Needs to be added by Jimmy 2: Electric Boogaloo
	case 9:
		pCard = new CardNine(cardPosition);
		break;

		//================================================================//

		//Need to be added by Tarek //Done - Tarek

	case 10:
		pCard = new CardTen(cardPosition);
		break;

	case 11:
		pCard = new CardEleven(cardPosition);
		break;

	case 12:
		pCard = new CardTwelve(cardPosition);
		break;

	case 13:
		pCard = new CardThirteen(cardPosition);
		break;

	case 14:
		pCard = new CardFourteen(cardPosition);
		break;


	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if ( pCard != NULL )
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid * pGrid =  pManager->GetGrid();

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);

		// C- Add the card object to the GameObject of its Cell:
		if (pGrid->AddObjectToCell(pCard) == true) {} //Adding the object is already done inside the if statement, no need to invoke the function again.

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		else 
		{ 
			Output * optr = pGrid->GetOutput();
			optr->PrintMessage("Error: Invalid card position");
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
