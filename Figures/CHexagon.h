#pragma once


#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P) const ;	//check whether a point is inside the figure
	virtual string GetInfo() const;
	string GetType() const;
	Point getCenter() override;
	void setCenter(int x, int y) override;
	void save(ofstream& outputFile) override;
	void load(ifstream& inputFile) override;


	virtual CFigure* Clone() const override;
	virtual CFigure* Clone(Point newPos) const override;
};
