#ifndef WATER_HPP_INCLUDED
#define WATER_HPP_INCLUDED

#include "../headers/genericElement.h"

class water : public genericElement
{
public:
    water()
    {
        setElementName("Water");
        setSpecificHeatLiquid(4184);
        setSpecificHeatSolid(2093);
        setSpecificHeatGas(2010);
        setLatentHeatOfFusion(334000);
        setLatentHeatOfVaporization(2260000);
        setMeltingPoint(273);
        setBoilingPoint(373);
    }
};


#endif // WATER_HPP_INCLUDED
