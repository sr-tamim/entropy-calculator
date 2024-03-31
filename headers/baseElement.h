#ifndef BASEELEMENT_H_INCLUDED
#define BASEELEMENT_H_INCLUDED

#include <iostream>
#include <math.h>
#include "calculationFunctions.h"
using namespace std;

class baseElement : public calculationFunctions
{
private:
    string elementName;

protected:
    void setElementName(string value) { elementName = value; }

public:
    string getElementName() { return elementName; }

    baseElement()
    {
        elementName = "Unknown Element";
        latentHeatOfFusion = 0;
        latentHeatOfVaporization = 0;
        specificHeatSolid = 0;
        specificHeatLiquid = 0;
        specificHeatGas = 0;
        meltingPoint = 0;
        boilingPoint = 0;
    }
};
#endif // BASEELEMENT_H_INCLUDED
