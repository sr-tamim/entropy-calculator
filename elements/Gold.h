#ifndef GOLD_HPP_INCLUDED
#define GOLD_HPP_INCLUDED

#include "../headers/baseElement.h"

class Gold : public baseElement
{
public:
    Gold()
    {
        setElementName("Silver");
        
        setSpecificHeatLiquid(129); // J/kg.K
        setSpecificHeatSolid(129); // J/kg.K
        
        // GOLD typically does not exist as a gas under  normal conditions
        
        setLatentHeatOfFusion(12500); // J/mol
        setLatentHeatOfVaporization(334000); // J/mol
        
        setMeltingPoint(1337.33); // K
        setBoilingPoint(3129); // K
    }
    ~Gold();
};

#endif // Gold_HPP_INCLUDED
