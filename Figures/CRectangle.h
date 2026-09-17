#ifndef CRECT_H
#define CRECT_H
#include <fstream>
#include "CFigure.h"
#include "../CMUgraphicsLib/colors.h" 
class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P) const;	//check whether a point is inside the figure
	virtual string GetInfo() const;
	string GetType() const;
	Point getCenter() override;
	void setCenter(int x, int y) override;
	void save(ofstream& outputFile) override;
	void load(ifstream& inputFile) override;

	virtual CFigure* Clone() const override;
	virtual CFigure* Clone(Point newPos) const override;
};

#endif