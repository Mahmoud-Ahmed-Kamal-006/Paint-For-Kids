#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	PRadius = P2;

}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pOut->DrawCircle(Center, PRadius, FigGfxInfo, Selected);
}
bool CCircle::IsInside(Point P) const
{
	//Check if the point is inside the circle
	int radius = sqrt(pow((PRadius.x - Center.x), 2) + pow((PRadius.y - Center.y), 2));
	int distance = sqrt(pow((P.x - Center.x), 2) + pow((P.y - Center.y), 2));
	if (distance <= radius) {
		
		return true;
	}
	return false;
}

string CCircle::GetInfo() const
{
	string info = "Circle: ID=" + to_string(ID);
	info += ", Center=(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
	info += ", Radius=(" + to_string(PRadius.x) + "," + to_string(PRadius.y) + ")";
	// Calculate radius
	int radius = sqrt(pow((PRadius.x - Center.x), 2) + pow((PRadius.y - Center.y), 2));
	info += ", Radius=" + to_string(radius);
	return info;
}
string CCircle::GetType() const {
	return "circle";
}




CFigure* CCircle::Clone() const
{
	CCircle* newCircle = new CCircle(Center, PRadius, FigGfxInfo);
	return newCircle;
}

CFigure* CCircle::Clone(Point newPos) const
{
	// Calculate the offset from original center to new center
	int offsetX = newPos.x - Center.x;
	int offsetY = newPos.y - Center.y;

	// Move PRadius by the same offset
	Point newPRadius;
	newPRadius.x = PRadius.x + offsetX;
	newPRadius.y = PRadius.y + offsetY;

	// Create new circle with same radius but at new center position
	CCircle* newCircle = new CCircle(newPos, newPRadius, FigGfxInfo);
	return newCircle;
}

Point CCircle::getCenter() {
	return Center;
}

void CCircle::setCenter(int x, int y) {
	int a = x - Center.x;
	int b = y - Center.y;
	Center.x = x;
	Center.y = y;
	PRadius.x += a;
	PRadius.y += b;
}

void CCircle::save(ofstream& outputFile) {
	outputFile << "CIRCLE " << ID << " " << Center.x << " " << Center.y << " " << PRadius.x << " " << PRadius.y << " " << colortostring(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		outputFile << colortostring(FigGfxInfo.FillClr) << " " << endl;
	else
		outputFile << "NO_FILL " << endl;

	
}


void CCircle::load(ifstream& inputFile) {
	string drawColorStr, fillColorStr;
	inputFile >> ID >> Center.x >> Center.y >> PRadius.x >> PRadius.y >> drawColorStr >> fillColorStr;
	FigGfxInfo.DrawClr = stringtocolor(drawColorStr);
	if (fillColorStr == "NO_FILL") {
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = stringtocolor(fillColorStr);
	}
}

