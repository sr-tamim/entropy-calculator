#ifndef Iron_HPP_INCLUDED
#define Iron_HPP_INCLUDED

#include "../headers/baseElement.h"

class Iron : public baseElement
{
public:
    Iron()
    {
        setElementName("Iron");
        
        setSpecificHeatLiquid(444); // J/kg.K
        setSpecificHeatSolid(449);//J/kg.K
        setSpecificHeatGas(275);//J/kg.K
        
        setLatentHeatOfFusion(272000); // J/kg (range 260000 to 275000)
        setLatentHeatOfVaporization(6100000);  //J/kg (range 5800000 to 6200000)
        
        setMeltingPoint(1811); //K
        setBoilingPoint(3134); // K
        
    }
};

#endif // Iron_HPP_INCLUDED
