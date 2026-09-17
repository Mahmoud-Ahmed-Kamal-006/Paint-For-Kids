#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3 ,FigGfxInfo, Selected);
}
bool CTriangle::IsInside(Point P) const
{
	//Check if the point is inside the triangle
	float area = 0.5 * (-Corner2.y * Corner3.x + Corner1.y * (-Corner2.x + Corner3.x) + Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * Corner3.y);
	float s = 1 / (2 * area) * (Corner1.y * Corner3.x - Corner1.x * Corner3.y + (Corner3.y - Corner1.y) * P.x + (Corner1.x - Corner3.x) * P.y);
	float t = 1 / (2 * area) * (Corner1.x * Corner2.y - Corner1.y * Corner2.x + (Corner1.y - Corner2.y) * P.x + (Corner2.x - Corner1.x) * P.y);
	if (s >= 0 && t >= 0 && (s + t <= 1)){
		
		return true;
	}
	return false;
}

string CTriangle::GetInfo() const
{
	string info = "Triangle: ID=" + to_string(ID);
	info += ", Points=(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
	info += " to (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	info += " to (" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")";
	// Calculate width and height
	int width = abs(Corner2.x - Corner1.x);
	int height = abs(Corner3.y - Corner1.y);
	info += ", Width=" + to_string(width) + ", Height=" + to_string(height);

	return info;
}
string CTriangle::GetType() const {
	return "triangle";
}

Point CTriangle::getCenter() {
	Point Center;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return Center;
}

void CTriangle::setCenter(int x, int y) {
	Point currentCenter = getCenter();

	int a = x - currentCenter.x;
	int b = y - currentCenter.y;

	Corner1.x += a;
	Corner1.y += b;
	Corner2.x += a;
	Corner2.y += b;
	Corner3.x += a;
	Corner3.y += b;

}

void CTriangle::save(ofstream& outputFile) {
	outputFile << "TRIANGLE " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " " << colortostring(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		outputFile << colortostring(FigGfxInfo.FillClr) << " " << endl;
	else
		outputFile << "NO_FILL " << endl;

}

void CTriangle::load(ifstream& inputFile) {
	string drawColorStr, fillColorStr;
	inputFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> drawColorStr >> fillColorStr;
	FigGfxInfo.DrawClr = stringtocolor(drawColorStr);
	if (fillColorStr == "NO_FILL") {
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = stringtocolor(fillColorStr);
	}
}


CFigure* CTriangle::Clone() const
{
	CTriangle* newTriangle = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
	return newTriangle;
}

CFigure* CTriangle::Clone(Point newPos) const
{
	// Calculate the center of the current triangle
	Point currentCenter;
	currentCenter.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	currentCenter.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

	// Calculate the offset from current center to new position
	int offsetX = newPos.x - currentCenter.x;
	int offsetY = newPos.y - currentCenter.y;

	// Calculate new corners
	Point newCorner1, newCorner2, newCorner3;
	newCorner1.x = Corner1.x + offsetX;
	newCorner1.y = Corner1.y + offsetY;
	newCorner2.x = Corner2.x + offsetX;
	newCorner2.y = Corner2.y + offsetY;
	newCorner3.x = Corner3.x + offsetX;
	newCorner3.y = Corner3.y + offsetY;

	// Create new triangle at the new position
	CTriangle* newTriangle = new CTriangle(newCorner1, newCorner2, newCorner3, FigGfxInfo);
	return newTriangle;
}