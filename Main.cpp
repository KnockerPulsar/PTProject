#include "ApplicationManager.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include "ApplicationManager.h"
bool CardTen::bought=false;
bool CardEleven::bought=false;
bool CardTwelve::bought=false;
bool CardThirteen::bought=false;
bool CardFourteen::bought=false;
// This Main Function Must NOT be Changed

int main()
{
	ActionType ActType;

	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action

		AppManager.ExecuteAction(ActType);

		//Update the drawings of the window after executing the action
		AppManager.UpdateInterface();

	} while(ActType != EXIT);


	return 0;
}


