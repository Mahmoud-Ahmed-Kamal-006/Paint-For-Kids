#include "CFigure.h"


int CFigure::LastID = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	// Increment the static LastID and assign it to this figure
	
	ID = LastID;
	LastID++;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	
	Selected = s; 
}

bool CFigure::IsSelected() const
{	
	return Selected; 
}



void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure::GetFillClr() const
{
	return FigGfxInfo.FillClr;
}

string CFigure::colortostring(color c) {
	if (c == BLACK) return "BLACK";
	if (c == RED) return "RED";
	if (c == GREEN) return "GREEN";
	if (c == BLUE) return "BLUE";
	if (c == YELLOW) return "YELLOW";
	if (c == ORANGE) return "ORANGE";
	return "BLUE";
}

color CFigure::stringtocolor(string colorname) {
	if (colorname == "BLACK") return BLACK;
	if (colorname == "BLUE") return BLUE;
	if (colorname == "GREEN") return GREEN;
	if (colorname == "RED") return RED;
	if (colorname == "ORANGE") return ORANGE;
	if (colorname == "YELLOW") return YELLOW;
	return BLACK;
}
bool CFigure::getIsFilled() {
	return FigGfxInfo.isFilled;
}