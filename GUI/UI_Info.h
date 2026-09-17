#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,//Recangle item in menu
	ITM_CIRC,//Circle item in menu
	ITM_SQ,//Square item in menu
	ITM_TRI,//Triangle item in menu
	ITM_HEX,//Hexagon item in menu
	ITM_CHANGE_COLOR,//Change color item in menu
	ITM_FILL_COLOR,//Fill color item in menu
	ITM_SEL,//Select item in menu
	ITM_SWAP,//Swap item in menu
	ITM_ROT,//Rotate item in menu
	ITM_COPY,//Copy item in menu
	ITM_CUT,//Cut item in menu
	ITM_PASTE,//Paste item in menu
	ITM_SAVE,//Save item in menu
	ITM_LOAD,//Load item in menu
	ITM_SWITCH_TO_PLAY,//Switch to play mode item in menu
	//TODO: Add more items names here
	ITM_CLRALL,//Clear all item in menu
	ITM_DEL,//Delete item in menu
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_MISSING_SHAPE,//Missing shape item in menu
	ITM_MATCHING_SHAPE,//Matching shape item in menu
	ITM_SWITCH_TO_DRAW,//Switch to draw mode item in menu
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};






__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif