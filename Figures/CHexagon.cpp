#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a rectangle on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}
bool CHexagon::IsInside(Point P) const
{
	//Check if the point is inside the hexagon
	int distance = sqrt(pow((P.x - Center.x), 2) + pow((P.y - Center.y), 2));
	if (distance <= 50) {
		
		return true;
	}
	return false;
}

string CHexagon::GetInfo() const
{
    string info = "Hexagon: ID=" + to_string(ID);
    info += ", Center=(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
    info += ", Radius=50";  // As defined in the drawing function

    // Calculate the area of the hexagon (using the formula for a regular hexagon)
    double area = (3 * sqrt(3) * pow(50, 2)) / 2;
    info += ", Area=" + to_string(int(area));

    

    return info;
}
string CHexagon::GetType() const {
	return "hexagon";
}

Point CHexagon::getCenter() {
	return Center;
}

void CHexagon::setCenter(int x, int y) {
	Center.x = x;
	Center.y = y;
}

void CHexagon::save(ofstream& outputFile) {
	outputFile << "HEXAGON " << ID << " " << Center.x << " " << Center.y << " " << "" << colortostring(FigGfxInfo.DrawClr) << " ";
    if (FigGfxInfo.isFilled)
        outputFile << colortostring(FigGfxInfo.FillClr) << " " << endl;
    else
        outputFile << "NO_FILL " << endl;

    
}

void CHexagon::load(ifstream& inputFile) {
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




CFigure* CHexagon::Clone() const
{
    // Create a new hexagon with the same center and graphics info
    CHexagon* newHexagon = new CHexagon(Center, FigGfxInfo);
    return newHexagon;
}

CFigure* CHexagon::Clone(Point newPos) const
{
    // Create new hexagon at the new center position
    CHexagon* newHexagon = new CHexagon(newPos, FigGfxInfo);
    return newHexagon;
}
