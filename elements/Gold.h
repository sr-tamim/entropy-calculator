#ifndef GOLD_HPP_INCLUDED
#define GOLD_HPP_INCLUDED

#include "../headers/baseElement.h"

class Gold : public baseElement
{
public:
    Gold()
    {
        setElementName("Gold");
        
        setSpecificHeatLiquid(129); // J/kg.K
        setSpecificHeatSolid(129); // J/kg.K
        
        // GOLD typically does not exist as a gas under  normal conditions
        
        setLatentHeatOfFusion(63706); // J/Kg
        setLatentHeatOfVaporization(1698477); // J/Kg
        
        setMeltingPoint(1337.33); // K
        setBoilingPoint(3129); // K
    }
};

#endif // Gold_HPP_INCLUDED
