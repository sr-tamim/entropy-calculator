#ifndef SILVER_HPP_INCLUDED
#define SILVER_HPP_INCLUDED

#include "../headers/baseElement.h"

class Silver : public baseElement
{
public:
    Silver()
    {
        setElementName("Silver");
        
        setSpecificHeatLiquid(0.24); // J/g°C
        setSpecificHeatSolid(0.24); // J/g°C
        
        // No specific heat capacity for gas
        
        setLatentHeatOfFusion(11.3); // kJ/mol
        setLatentHeatOfVaporization(250); // kJ/mol
        
        setMeltingPoint(1234.8); // °C
        setBoilingPoint(2485); // °C
    }
    ~Silver();
};

#endif // SILVER_HPP_INCLUDED
