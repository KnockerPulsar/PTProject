#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		     // Add Ladder Action
	ADD_SNAKE,		     // Add Snake Action	
	ADD_CARD,		     // Add Card Action	
	COPY_CARD,           //Jimmy - Copy Card Action//
	CUT_CARD,            //Jimmy - Cut Card Action//
	PASTE_CARD,          //Jimmy - Paste Card Action//	
	EDIT_CARD,           //Jimmy - Edit Card Action//
	DELETE_GAME_OBJECT,  //Jimmy - Delete Game Object Action//
	SAVE_GRID,           //Jimmy - Save Grid Action//
	OPEN_GRID,           //Jimmy -Open Grid Action//
	TO_PLAY_MODE,	     // Go to Play Mode
	EXIT,			     // Exit Application  

	///TODO: Add more action types of Design Mode    //Jimmy - Done//

	//  [2] Actions of Play Mode

	ROLL_DICE,		     // Roll Dice Action
	INPUT_DICE_VALUE,     //Jimmy - Input Dice Value Action//
	NEW_GAME,            //Jimmy - Opens a New game//
	TO_DESIGN_MODE,	     // Go to Design Mode

	///TODO: Add more action types of Play Mode      //Jimmy - Done//

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

enum ObjectType  //Type of the game objects
{
	LadderType,      //Ladder Object
	SnakeType,       //Snake Object
	CardType         //Card Object
};

#endif