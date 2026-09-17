#include "CRectangle.h"
#include <fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInside(Point P) const
{
	//Check if the point is inside the rectangle
	if (P.x >= Corner1.x && P.x <= Corner2.x && P.y >= Corner1.y && P.y <= Corner2.y) {
		
		return true;
	}
	else if (P.x >= Corner2.x && P.x <= Corner1.x && P.y >= Corner2.y && P.y <= Corner1.y) {
		return true;
	}
	else if (P.x >= Corner1.x && P.x <= Corner2.x && P.y >= Corner2.y && P.y <= Corner1.y) {
		return true;
	}
	else if (P.x >= Corner2.x && P.x <= Corner1.x && P.y >= Corner1.y && P.y <= Corner2.y)
	{
		return true;
	}
	return false;
}

string CRectangle::GetInfo() const
{
    string info = "Rectangle: ID=" + to_string(ID);
    info += ", Points=(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
    info += " to (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";

    // Calculate width and height
    int width = abs(Corner2.x - Corner1.x);
    int height = abs(Corner2.y - Corner1.y);
    info += ", Width=" + to_string(width) + ", Height=" + to_string(height);


    return info;
}
string CRectangle::GetType() const {
	return "rectangle";
}

Point CRectangle::getCenter() {
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	return Center;
}

void CRectangle::setCenter(int x, int y) {
	int width = abs(Corner2.x - Corner1.x);
	int height = abs(Corner2.y - Corner1.y);

	Corner1.x = x - width / 2;
	Corner1.y = y - height / 2;
	Corner2.x = x + width / 2;
	Corner2.y = y + height / 2;
}

void CRectangle::save(ofstream& outputFile) {
	outputFile << "RECTANGLE "
		<< ID << " "
		<< Corner1.x << " "
		<< Corner1.y << " "
		<< Corner2.x << " "
		<< Corner2.y << " "
		<< colortostring(FigGfxInfo.DrawClr) << " ";

	
	if (FigGfxInfo.isFilled)
		outputFile << colortostring(FigGfxInfo.FillClr) << " " << endl;
	else
		outputFile << "NO_FILL " << endl;

	
}


void CRectangle::load(ifstream& inputFile) {
	string drawColorStr, fillColorStr;
	inputFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y>> drawColorStr >> fillColorStr;
	FigGfxInfo.DrawClr = stringtocolor(drawColorStr);
	if (fillColorStr == "NO_FILL") {
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = stringtocolor(fillColorStr);
	}
}

CFigure* CRectangle::Clone() const
{
    CRectangle* newRect = new CRectangle(Corner1, Corner2, FigGfxInfo);
    return newRect;
}

CFigure* CRectangle::Clone(Point newPos) const
{
    // Calculate width and height of current rectangle
    int width = abs(Corner2.x - Corner1.x);
    int height = abs(Corner2.y - Corner1.y);

    // Calculate center of current rectangle
    Point currentCenter;
    currentCenter.x = (Corner1.x + Corner2.x) / 2;
    currentCenter.y = (Corner1.y + Corner2.y) / 2;

    // Calculate offset from current center to new position
    int offsetX = newPos.x - currentCenter.x;
    int offsetY = newPos.y - currentCenter.y;

    // Calculate new corners
    Point newCorner1, newCorner2;
    newCorner1.x = Corner1.x + offsetX;
    newCorner1.y = Corner1.y + offsetY;
    newCorner2.x = Corner2.x + offsetX;
    newCorner2.y = Corner2.y + offsetY;

    // Create new rectangle at the new position
    CRectangle* newRect = new CRectangle(newCorner1, newCorner2, FigGfxInfo);
    return newRect;
}