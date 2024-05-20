#ifndef CALCULATIONFUNCTION_H_INCLUDED
#define CALCULATIONFUNCTION_H_INCLUDED

#include <iostream>
#include "elementState.h"
#include "thermalProperties.h"
using namespace std;

class calculationFunctions : private elementState, public thermalProperties
{
public:
    double totalHeatNeeded(double mass, double fromTemp, double toTemp)
    {
        if (fromTemp < 0 || toTemp < 0)
        {
            cout << "Temperature cannot be less than 0 K" << endl;
            return 0;
        }

        double totalHeat = 0;
        askForState(fromTemp, toTemp, meltingPoint, boilingPoint);

        if (toTemp <= meltingPoint)
        {
            totalHeat += mass * specificHeatSolid * (toTemp - fromTemp);
            if (toTemp == meltingPoint && initialState == "Solid" && finalState == "Liquid")
                totalHeat += mass * latentHeatOfFusion;
        }
        else if (toTemp <= boilingPoint)
        {
            if (fromTemp < meltingPoint)
            {
                totalHeat += mass * specificHeatSolid * (meltingPoint - fromTemp);
                totalHeat += mass * latentHeatOfFusion;
            }
            if (fromTemp == meltingPoint && initialState == "Solid" && finalState != "Solid")
                totalHeat += mass * latentHeatOfFusion;
            if (fromTemp <= meltingPoint)
                totalHeat += mass * specificHeatLiquid * (toTemp - meltingPoint);
            else
                totalHeat += mass * specificHeatLiquid * (toTemp - fromTemp);
            if (toTemp == boilingPoint && initialState != "Gas" && finalState == "Gas")
                totalHeat += mass * latentHeatOfVaporization;
        }
        else
        {
            if (fromTemp < meltingPoint)
            {
                totalHeat += mass * specificHeatSolid * (meltingPoint - fromTemp);
                totalHeat += mass * latentHeatOfFusion;
            }
            if (fromTemp == meltingPoint && initialState == "Solid" && finalState != "Solid")
                totalHeat += mass * latentHeatOfFusion;

            if (fromTemp < boilingPoint)
            {
                if (fromTemp <= meltingPoint)
                    totalHeat += mass * specificHeatLiquid * (boilingPoint - meltingPoint);
                else
                    totalHeat += mass * specificHeatLiquid * (boilingPoint - fromTemp);
                totalHeat += mass * latentHeatOfVaporization;
            }
            if (fromTemp == boilingPoint && initialState != "Gas" && finalState == "Gas")
                totalHeat += mass * latentHeatOfVaporization;

            if (fromTemp > boilingPoint)
                totalHeat += mass * specificHeatGas * (toTemp - fromTemp);
            else
                totalHeat += mass * specificHeatGas * (toTemp - boilingPoint);
        }
        return totalHeat;
    }

    double totalEntropyChange(double mass, double fromTemp, double toTemp)
    {
        if (fromTemp < 0 || toTemp < 0)
        {
            cout << "Temperature cannot be less than 0 K" << endl;
            return 0;
        }

        double totalEntropy = 0;
        askForState(fromTemp, toTemp, meltingPoint, boilingPoint);

        if (toTemp <= meltingPoint)
        {
            totalEntropy += mass * specificHeatSolid * log(toTemp / fromTemp);
            if (toTemp == meltingPoint && initialState == "Solid" && finalState == "Liquid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
        }
        else if (toTemp <= boilingPoint)
        {
            if (fromTemp < meltingPoint)
            {
                totalEntropy += mass * specificHeatSolid * log(meltingPoint / fromTemp);
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
            }
            if (fromTemp == meltingPoint && initialState == "Solid" && finalState != "Solid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
            if (fromTemp <= meltingPoint)
                totalEntropy += mass * specificHeatLiquid * log(toTemp / meltingPoint);
            else
                totalEntropy += mass * specificHeatLiquid * log(toTemp / fromTemp);
            if (toTemp == boilingPoint && initialState != "Gas" && finalState == "Gas")
                totalEntropy += mass * latentHeatOfVaporization / boilingPoint;
        }
        else
        {
            if (fromTemp < meltingPoint)
            {
                totalEntropy += mass * specificHeatSolid * log(meltingPoint / fromTemp);
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
            }
            if (fromTemp == meltingPoint && initialState == "Solid" && finalState != "Solid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;

            if (fromTemp < boilingPoint)
            {
                if (fromTemp <= meltingPoint)
                    totalEntropy += mass * specificHeatLiquid * log(boilingPoint / meltingPoint);
                else
                    totalEntropy += mass * specificHeatLiquid * log(boilingPoint / fromTemp);
                totalEntropy += mass * latentHeatOfVaporization / boilingPoint;
            }
            if (fromTemp == boilingPoint && initialState != "Gas" && finalState == "Gas")
                totalEntropy += mass * latentHeatOfVaporization / boilingPoint;

            if (fromTemp > boilingPoint)
                totalEntropy += mass * specificHeatGas * log(toTemp / fromTemp);
            else
                totalEntropy += mass * specificHeatGas * log(toTemp / boilingPoint);
        }
        return totalEntropy;
    }
};

#endif  // CALCULATIONFUNCTION_H_INCLUDED
