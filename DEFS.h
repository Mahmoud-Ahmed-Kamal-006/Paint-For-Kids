#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,      //Draw Circle
	DRAW_SQ,		//Draw Square
	DRAW_TRI,		//Draw Triangle
	DRAW_HEX,		//Draw Hexagon
	CHNG_DRAW_CLR,	//Change color
	CHNG_FILL_CLR,	//Change fill color
	SELECT,			//Select
	SWAP,			//Swap
	ROTATE,		    //Rotate
	COPY,			//Copy
	CUT,			//Cut
	PASTE,			//Paste
	SAVE,			//Save
	LOAD,			//Load
	CLR_ALL,		//Clear all
	DEL,			//Delete
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS, //A click on the status bar
	PLAYING_AREA,		//Play a game
	PLAY_MISSING_SHAPE,	//Missing shape
	PLAY_MATCHING_SHAPE,	//Matching shape

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
public:
	color getDrawClr(){
		return DrawClr;
	}
};

#endif