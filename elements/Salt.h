#ifndef Salt_HPP_INCLUDED
#define Salt_HPP_INCLUDED

#include "../headers/baseElement.h"

class Salt : public baseElement
{
public:
    Salt()
    {
        
        // NaCl (Sodium Chloride -> Common Salt)
        
        setElementName("Salt");
        
        setSpecificHeatLiquid(880); // J/kg.K
        setSpecificHeatSolid(1220); // J/kg.K
        
        // No specific heat capacity for gas
        
        setLatentHeatOfFusion(506.4); // J/kg
        setLatentHeatOfVaporization(13761.5); //J/kg
        
        setMeltingPoint(1074.15); // k
        setBoilingPoint(1738.15); // k
    }
};

#endif // SALT_HPP_INCLUDED
