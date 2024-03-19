#ifndef EthanoicAcid_HPP_INCLUDED
#define EthanoicAcid_HPP_INCLUDED

#include "../headers/baseElement.h"

class EthanoicAcid : public baseElement
{
public:
    EthanoicAcid()
    {
        setElementName("Ethanoic Acid");
        
        setSpecificHeatLiquid(2400); // J/kg.K
        setSpecificHeatSolid(2400); // J/kg.K (Approximately)
        setSpecificHeatGas(1630); // J/kg.K (Approximately)
        
        setLatentHeatOfFusion(120000); // J/kg (Approximately)
        setLatentHeatOfVaporization(363000);  // J/kg (Approximately)
        
        setMeltingPoint(290); // K (Approximately)
        setBoilingPoint(391); // K (Approximately)
    }
};

#endif // EthanoicAcid_HPP_INCLUDED
