#ifndef Cupper_HPP_INCLUDED
#define Cupper_HPP_INCLUDED

#include "../headers/baseElement.h"

class Cupper : public baseElement
{
public:
    Cupper()
    {
        setElementName("Cupper");
        
        setSpecificHeatLiquid(385); // J/kg.K
        setSpecificHeatSolid(385);//J/kg.K
        setSpecificHeatGas(205);//J/kg.K
        
        setLatentHeatOfFusion(210000); // J/kg (range 200000 to 210000)
        setLatentHeatOfVaporization(5000000);  //J/kg (range 4700000 to 5000000
        
        setMeltingPoint(1357.77); //K
        setBoilingPoint(2835); // K
        
    }
    
    ~Cupper();
};


#endif // Cupper_HPP_INCLUDED
