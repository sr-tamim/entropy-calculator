#ifndef Diamond_HPP_INCLUDED
#define Diamond_HPP_INCLUDED

#include "../headers/baseElement.h"

class Diamond : public baseElement
{
public:
    
    Diamond()
    {
        // Diamond (Carbon)
        
        setElementName("Diamond");
        
        setSpecificHeatLiquid(0); // No liquid state
        setSpecificHeatSolid(502); // J/kg.K
        
        // No specific heat capacity for gas
        
        setLatentHeatOfFusion(11700); // J/kg
        setLatentHeatOfVaporization(0); // No vaporization
        
        setMeltingPoint(0); // Diamond sublimes at 3915 K
        setBoilingPoint(0); // Diamond sublimes before boiling
    }
};

#endif // DIAMOND_HPP_INCLUDED
