#ifndef HYDROGEN_HPP_INCLUDED
#define HYDROGEN_HPP_INCLUDED

#include "../headers/baseElement.h"

class Hydrogen : public baseElement
{
public:
    Hydrogen()
    {
        setElementName("Hydrogen");

        setSpecificHeatLiquid(9690); // J/kg.K
        setSpecificHeatSolid(14300); // J/kg.K
        setSpecificHeatGas(14300); // J/kg.K

        setLatentHeatOfFusion(517.8); // J/mol
        setLatentHeatOfVaporization(452.0); // J/mol

        setMeltingPoint(14.01); // K
        setBoilingPoint(20.28); // K
    }
    ~Hydrogen();
};

#endif // HYDROGEN_HPP_INCLUDED