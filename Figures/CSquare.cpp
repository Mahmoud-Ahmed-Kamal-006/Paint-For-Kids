#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a rectangle on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
bool CSquare::IsInside(Point P) const
{
	//Check if the point is inside the square
	if (P.x >= (Center.x - 50) && P.x <= (Center.x + 50) &&
		P.y >= (Center.y - 50) && P.y <= (Center.y + 50)) {
		return true;
	}
	return false;
}

string CSquare::GetInfo() const
{
	string info = "Square: ID=" + to_string(ID);
	info += ", Center=(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
	// Calculate width and height
	int width = 100; // Assuming a fixed size for the square
	int height = 100; // Assuming a fixed size for the square
	info += ", Width=" + to_string(width) + ", Height=" + to_string(height);
	return info;
}
string CSquare::GetType() const {
	return "square";
}

Point CSquare::getCenter() {
	return Center;
}

void CSquare::setCenter(int x, int y) {
	Center.x = x;
	Center.y = y;
}

void CSquare::save(ofstream& outputFile) {
	outputFile << "SQUARE " << ID << " " << Center.x << " " << Center.y << " " << colortostring(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		outputFile << colortostring(FigGfxInfo.FillClr) << " " << endl;
	else
		outputFile << "NO_FILL " << endl;

	
}


void CSquare::load(ifstream& inputFile) {
	string drawColorStr, fillColorStr;
	inputFile >> ID >> Center.x >> Center.y >> drawColorStr >> fillColorStr;
	FigGfxInfo.DrawClr = stringtocolor(drawColorStr);
	if (fillColorStr == "NO_FILL") {
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = stringtocolor(fillColorStr);
	}
}





CFigure* CSquare::Clone() const
{
	// Create a new square with the same center and graphics info
	CSquare* newSquare = new CSquare(Center, FigGfxInfo);
	return newSquare;
}

CFigure* CSquare::Clone(Point newPos) const
{
	// Create new square at the new center position
	CSquare* newSquare = new CSquare(newPos, FigGfxInfo);
	return newSquare;
}