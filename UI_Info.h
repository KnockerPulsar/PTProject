#ifndef UI_INFO_H
#define UI_INFO_H

#include "CMUgraphicsLib\CMUgraphics.h"
#include "Output.h"
#include "Input.h"

// User Interface information file.
// This file contains info that is needed by Input and Output classes to
// handle the user interface

#define NumHorizontalCells 11
#define NumVerticalCells 9
#define MaxPlayerCount 4

enum GUI_MODE		// Graphical user interface mode
{
	MODE_DESIGN,	// Design mode (startup mode)
	MODE_PLAY       // Play mode
};

enum  DESIGN_MODE_ITEMS // The items of the Design Mode (you should add more items)
{
	// Note: Items MUST be ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_ADD_LADDER,                                                                          //Jimmy - Order - 1//
	ITM_ADD_SNAKE,                                                                           //Jimmy - Order - 2//
	ITM_ADD_CARD,                                                                            //Jimmy - Order - 3//
	ITM_COPY_CARD,           //Jimmy - Added Item//                                          //Jimmy - Order - 4//
	ITM_CUT_CARD,            //Jimmy - Added Item//                                          //Jimmy - Order - 5//
	ITM_PASTE_CARD,          //Jimmy - Added Item//                                          //Jimmy - Order - 6//
	ITM_EDIT_CARD,           //Jimmy - Added Item//                                          //Jimmy - Order - 7//
	ITM_DELETE_GAME_OBJECT,  //Jimmy - Added Item//                                          //Jimmy - Order - 8//
	ITM_SAVE_GRID,           //Jimmy - Added Item//                                          //Jimmy - Order - 9//
	ITM_OPEN_GRID,           //Jimmy - Added Item//                                          //Jimmy - Order - 10//
	ITM_SWITCH_TO_PLAY_MODE,                                                                 //Jimmy - Order - 11//
	ITM_EXIT,                //Jimmy - Changed Order to match the Phase1 Doccument//         //Jimmy - Order - 12//

	
	///TODO: Add more items names here                    //Jimmy - Done//

	DESIGN_ITM_COUNT	// no. of items ==> This should be the last line in this enum
};

enum  PLAY_MODE_ITEMS // The items of the Play Mode (you should add more items)
{
	// Note: Items are ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_ROLL_DICE,                                                                           //Jimmy - Order - 1//
	ITM_INPUT_DICE_VALUE,    //Jimmy - Added Item//                                          //Jimmy - Order - 2//
	ITM_NEW_GAME,            //Jimmy - Added Item//                                          //Jimmy - Order - 3//
	ITM_SWITCH_TO_DESIGN_MODE,                                                               //Jimmy - Order - 4//
	//ITM_EXIT,                /Jimmy - This item should be added but conflicts             //Jimmy - Order - 5//
	                           //with DESIGN_MODE_ITEMS since it has the same name//
							   //For now i'm testing another//
    ITM_EXIT_PM,

	///TODO: Add more items names here                    //Jimmy - Done//

	PLAY_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};

__declspec(selectany) // This line to prevent "redefinition error"

struct UI_Info	// User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,			// Window width and height
		wx , wy,				// Window starting coordinates
		StatusBarHeight,		// Status Bar Height
		ToolBarHeight,			// Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;			// Width of each item in toolbar menu
	
	int CellHeight;				// Height of 1 CELL
	int CellWidth;				// Width of 1 CELL
	
	color MsgColor;				// Messages color (usually used in statusbar)
	color PlayerInfoColor;		// Players' Info color (used in the toolbar - right-indented)

	color CellColor_HasCard;	// Cell color if it has a card
	color CellColor_NoCard;		// Cell color if it does not have card

	color ToolBarColor;			// Toolbar color (toolbar background)
	color StatusBarColor;		// Statusbar color (statusbar background)

	color GridLineColor;		// Color of the Lines separating adjacent cells

	int CellNumFont;			// Font size of cell numbers
	color CellNumColor;			// Cell number color

	int CardNumFont;			// Font size of card numbers
	color CardNumColor;			// Card number color

	int LadderXOffset;			// Size of the horizontal space before drawing the ladder
	int LadderYOffset;			// Size of the vertical space before drawing the ladder
	int LadderlineWidth;		// Width of the lines of the ladder
	color LadderColor;			// Ladder color
	int SnakelineWidth;			// Width of the line and polygon of the snake
	color SnakeColor;			// Snake color

	color PlayerColors[MaxPlayerCount];		// Color of each player
 


	///TODO: Add more members if needed

} UI ;	// create a global object UI

#endif