#ifndef CCIRCLE_H
#define CCIRCLE_H
#include <fstream>
#include "CFigure.h"


class CCircle : public CFigure
{
private:
	Point Center;	//Center of the circle  
	Point PRadius;	//point at a distance equal to Radius of the circle
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P) const ;	//check whether a point is inside the figure
	virtual string GetInfo() const ; // Return the type of figure as a string
	string GetType() const;

	virtual CFigure* Clone() const override;
	virtual CFigure* Clone(Point newPos) const override;
	Point getCenter() override;
	void setCenter(int x, int y) override;
	void save(ofstream& outputFile) override;
	void load(ifstream& inputFile) override;
};

#endif
