#ifndef Sugar_HPP_INCLUDED
#define Sugar_HPP_INCLUDED

#include "../headers/baseElement.h"

class Sugar : public baseElement
{
public:
    Sugar()
    {
        
        setElementName("Sugar");
        
        setSpecificHeatLiquid(1750); // J/kg.K
        setSpecificHeatSolid(1490); // J/kg.K
        
        // No specific heat capacity for gas
        
        setLatentHeatOfFusion(36000); // J/kg
        setLatentHeatOfVaporization(0); // No vaporization
        
        setMeltingPoint(366.8); // K
        setBoilingPoint(0); // Sugar decomposes before boiling
    }
};

#endif // SUGAR_HPP_INCLUDED
