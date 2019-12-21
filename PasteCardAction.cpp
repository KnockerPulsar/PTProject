#include "PasteCardAction.h"
#include "Card.h"
#include "Grid.h"
#include "AddCardAction.h"
#include "CellPosition.h"

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
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the cell where you would like to paste the card");
	pastedcardpos = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}
void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pastedcard = pGrid->GetClipboard();
	Card* pCard = NULL; // will point to the card object type
	switch (pastedcard->GetCardNumber())
	{
	case 1:
		pCard = new CardOne(pastedcardpos);
		break;
		// A- Add the remaining cases	//Done-Tarek, unfinished classes were commented, please uncomment as you finish each class.

		//================================================================//

		//Added by Abduallah
	case 2:
		pCard = new CardTwo(pastedcardpos);
		break;

	case 3:
		pCard = new CardThree(pastedcardpos);
		break;

	case 4:
		pCard = new CardFour(pastedcardpos);
		break;

		//================================================================//

		//Need to be added by Jimmy
	case 5:
		pCard = new CardFive(pastedcardpos);
		break;

	case 6:
		pCard = new CardSix(pastedcardpos);
		break;

		//================================================================//

		//Need to be added by Ayman, done
	case 7:                                                        //Ayman added this
		pCard = new CardSeven(pastedcardpos);
		break;

	case 8:                                                        //Ayman added this
		pCard = new CardEight(pastedcardpos);
		break;

		//================================================================//

		//Needs to be added by Jimmy 2: Electric Boogaloo
	case 9:
		pCard = new CardNine(pastedcardpos);
		break;

		//================================================================//

		//Need to be added by Tarek //Done - Tarek

	case 10:
		pCard = new CardTen(pastedcardpos);
		break;

	case 11:
		pCard = new CardEleven(pastedcardpos);
		break;

	case 12:
		pCard = new CardTwelve(pastedcardpos);
		break;

	case 13:
		pCard = new CardThirteen(pastedcardpos);
		break;

	case 14:
		pCard = new CardFourteen(pastedcardpos);
		break;


	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard != NULL)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);

		// C- Add the card object to the GameObject of its Cell:
		if (pGrid->AddObjectToCell(pCard) == true) {} //Adding the object is already done inside the if statement, no need to invoke the function again.

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		else
		{
			Output* optr = pGrid->GetOutput();
			optr->PrintMessage("Error: Invalid card position");
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
