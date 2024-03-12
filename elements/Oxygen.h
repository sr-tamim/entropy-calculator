#ifndef OXYGEN_HPP_INCLUDED
#define OXYGEN_HPP_INCLUDED

#include "../headers/baseElement.h"

class Oxygen : public baseElement
{
public:
    Oxygen()
    {
        setElementName("Oxygen");
        
        setSpecificHeatLiquid(919); // J/kg.K
        setSpecificHeatSolid(918); // J/kg.K
        setSpecificHeatGaseous(918); // J.kg.K
        
        setLatentHeatOfFusion(13100); // J/mol
        setLatentHeatOfVaporization(213000); // J/mol
        
        setMeltingPoint(54.36); // k
        setBoilingPoint(90.19); // k
    }
    ~Oxygen();
};

#endif // OXYGEN_HPP_INCLUDED
