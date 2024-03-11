#ifndef SILVER_HPP_INCLUDED
#define SILVER_HPP_INCLUDED

#include "../headers/baseElement.h"

class Silver : public baseElement
{
public:
    Silver()
    {
        setElementName("Silver");
        
        setSpecificHeatLiquid(240); // J/kg.K
        setSpecificHeatSolid(240); // J/kg.K
        
        // No specific heat capacity for gas
        
        setLatentHeatOfFusion(104.72); // J/kg
        setLatentHeatOfVaporization( 2318.83); //J/kg
        
        setMeltingPoint(1234.8); // k
        setBoilingPoint(2485); // k
    }
    ~Silver();
};

#endif // SILVER_HPP_INCLUDED
