#ifndef IRON_HPP_INCLUDED
#define IRON_HPP_INCLUDED

#include "../headers/baseElement.h"

class Iron : public baseElement
{
public:
    Iron()
    {
        setElementName("Iron");
        
        // Specific heat capacities for iron (Fe) in J/kg.K
        setSpecificHeatLiquid(490); // Approximate value
        setSpecificHeatSolid(449); // Approximate value
        
        // No specific heat capacity for gas
        
        // Latent heats of fusion and vaporization for iron (Fe) in J/kg
        setLatentHeatOfFusion(273); // Approximate value
        setLatentHeatOfVaporization(6190); // Approximate value
        
        setMeltingPoint(1811); // K (Approximate value)
        setBoilingPoint(3134); // K (Approximate value)
    }
  ~Iron();
};

#endif // IRON_HPP_INCLUDED
