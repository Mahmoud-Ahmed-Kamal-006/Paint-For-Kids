#pragma once
#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P) const;	//check whether a point is inside the figure
	virtual string GetInfo() const ; // Return the type of figure as a string
	string GetType() const;
	Point getCenter() override;
	void setCenter(int x, int y) override;
	void save(ofstream& outputFile) override;
	void load(ifstream& inputFile) override;


	virtual CFigure* Clone() const override;
	virtual CFigure* Clone(Point newPos) const override;
};

#endif