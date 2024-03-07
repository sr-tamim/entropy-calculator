#ifndef BASEELEMENT_H_INCLUDED
#define BASEELEMENT_H_INCLUDED


#include <iostream>
#include <math.h>
using namespace std;

class baseElement
{
private:
    string elementName;
    double latentHeatOfFusion;
    double latentHeatOfVaporization;
    double specificHeatSolid;
    double specificHeatLiquid;
    double specificHeatGas;
    double meltingPoint;
    double boilingPoint;

protected:
    void setElementName(string value) { elementName = value; }
    void setLatentHeatOfFusion(double value) { latentHeatOfFusion = value; }
    void setLatentHeatOfVaporization(double value) { latentHeatOfVaporization = value; }
    void setSpecificHeatSolid(double value) { specificHeatSolid = value; }
    void setSpecificHeatLiquid(double value) { specificHeatLiquid = value; }
    void setSpecificHeatGas(double value) { specificHeatGas = value; }
    void setMeltingPoint(double value) { meltingPoint = value; }
    void setBoilingPoint(double value) { boilingPoint = value; }

public:
    string getElementName() { return elementName; }
    double getLatentHeatOfFusion() { return latentHeatOfFusion; }
    double getLatentHeatOfVaporization() { return latentHeatOfVaporization; }
    double getSpecificHeatSolid() { return specificHeatSolid; }
    double getSpecificHeatLiquid() { return specificHeatLiquid; }
    double getSpecificHeatGas() { return specificHeatGas; }
    double getMeltingPoint() { return meltingPoint; }
    double getBoilingPoint() { return boilingPoint; }

    double totalHeatNeeded(double mass, double fromTemp, double toTemp)
    {
        double totalHeat = 0;
        if (fromTemp <= meltingPoint && toTemp <= meltingPoint)
        {
            totalHeat = mass * specificHeatSolid * (toTemp - fromTemp);
        }
        else if (fromTemp <= meltingPoint && toTemp >= meltingPoint && toTemp <= boilingPoint)
        {
            totalHeat = mass * specificHeatSolid * (meltingPoint - fromTemp);
            totalHeat += mass * latentHeatOfFusion / meltingPoint;
            totalHeat += mass * specificHeatLiquid * (toTemp - meltingPoint);
        }
        else if (fromTemp <= meltingPoint && toTemp >= boilingPoint)
        {
            totalHeat = mass * specificHeatSolid * (meltingPoint - fromTemp);
            totalHeat += mass * latentHeatOfFusion;
            totalHeat += mass * specificHeatLiquid * (boilingPoint - meltingPoint);
            totalHeat += mass * latentHeatOfVaporization;
            totalHeat += mass * specificHeatGas * (toTemp - boilingPoint);
        }
        else if (fromTemp >= meltingPoint && fromTemp <= boilingPoint && toTemp >= meltingPoint && toTemp <= boilingPoint)
        {
            totalHeat = mass * specificHeatLiquid * (toTemp - fromTemp);
        }
        else if (fromTemp >= meltingPoint && fromTemp <= boilingPoint && toTemp >= boilingPoint)
        {
            totalHeat = mass * specificHeatLiquid * (boilingPoint - fromTemp);
            totalHeat += mass * latentHeatOfVaporization;
            totalHeat += mass * specificHeatGas * (toTemp - boilingPoint);
        }
        else if (fromTemp >= boilingPoint && toTemp >= boilingPoint)
        {
            totalHeat = mass * specificHeatGas * (toTemp - fromTemp);
        }
        return totalHeat;
    }

    double totalEntropyChange(double mass, double fromTemp, double toTemp)
    {
        double totalEntropy = 0;
        if (fromTemp <= meltingPoint && toTemp <= meltingPoint)
        {
            totalEntropy = mass * specificHeatSolid * log(toTemp / fromTemp);
        }
        else if (fromTemp <= meltingPoint && toTemp >= meltingPoint && toTemp <= boilingPoint)
        {
            totalEntropy = mass * specificHeatSolid * log(meltingPoint / fromTemp);
            totalEntropy += mass * latentHeatOfFusion / meltingPoint;
            totalEntropy += mass * specificHeatLiquid * log(toTemp / meltingPoint);
        }
        else if (fromTemp <= meltingPoint && toTemp >= boilingPoint)
        {
            totalEntropy = mass * specificHeatSolid * log(meltingPoint / fromTemp);
            totalEntropy += mass * latentHeatOfFusion;
            totalEntropy += mass * specificHeatLiquid * log(boilingPoint / meltingPoint);
            totalEntropy += mass * latentHeatOfVaporization;
            totalEntropy += mass * specificHeatGas * log(toTemp / boilingPoint);
        }
        else if (fromTemp >= meltingPoint && fromTemp <= boilingPoint && toTemp >= meltingPoint && toTemp <= boilingPoint)
        {
            totalEntropy = mass * specificHeatLiquid * log(toTemp / fromTemp);
        }
        else if (fromTemp >= meltingPoint && fromTemp <= boilingPoint && toTemp >= boilingPoint)
        {
            totalEntropy = mass * specificHeatLiquid * log(boilingPoint / fromTemp);
            totalEntropy += mass * latentHeatOfVaporization;
            totalEntropy += mass * specificHeatGas * log(toTemp / boilingPoint);
        }
        else if (fromTemp >= boilingPoint && toTemp >= boilingPoint)
        {
            totalEntropy = mass * specificHeatGas * log(toTemp / fromTemp);
        }
        return totalEntropy;
    }
};

#endif // BASEELEMENT_H_INCLUDED
