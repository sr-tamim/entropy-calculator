#ifndef BASEELEMENT_H_INCLUDED
#define BASEELEMENT_H_INCLUDED

#include <iostream>
#include <math.h>
#include "readElementState.h"
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
    string initialState = "";
    string finalState = "";

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
        if (fromTemp < 0 || toTemp < 0)
        {
            cout << "Temperature cannot be less than 0 K" << endl;
            return 0;
        }

        double totalHeat = 0;
        if (fromTemp == meltingPoint || fromTemp == boilingPoint)
        {
            cout << "What is the state of the element at the initial temperature?" << endl;
            initialState = readElementState();
        }
        if (toTemp == meltingPoint || toTemp == boilingPoint)
        {
            cout << "What is the state of the element at the final temperature?" << endl;
            finalState = readElementState();
        }

        if (toTemp <= meltingPoint)
        {
            totalHeat += mass * specificHeatSolid * (toTemp - fromTemp);
            if (toTemp == meltingPoint && finalState != "Solid")
                totalHeat += mass * latentHeatOfFusion;
        }
        else if (toTemp <= boilingPoint)
        {
            if (fromTemp < meltingPoint)
                totalHeat += mass * specificHeatSolid * (meltingPoint - fromTemp);
            if (fromTemp == meltingPoint && initialState != "Liquid")
                totalHeat += mass * latentHeatOfFusion;
            if (fromTemp <= meltingPoint)
                totalHeat += mass * specificHeatLiquid * (toTemp - meltingPoint);
            else
                totalHeat += mass * specificHeatLiquid * (toTemp - fromTemp);
            if (toTemp == boilingPoint && finalState != "Liquid")
                totalHeat += mass * latentHeatOfVaporization;
        }
        else
        {
            if (fromTemp < meltingPoint)
                totalHeat += mass * specificHeatSolid * (meltingPoint - fromTemp);
            if (fromTemp == meltingPoint && initialState != "Liquid")
                totalHeat += mass * latentHeatOfFusion;

            if (fromTemp < boilingPoint)
                totalHeat += mass * specificHeatLiquid * (fromTemp - meltingPoint);
            if (fromTemp == boilingPoint && initialState != "Gas")
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
        string initialState = "";
        string finalState = "";
        if (fromTemp == meltingPoint || fromTemp == boilingPoint)
        {
            cout << "What is the state of the element at the initial temperature?" << endl;
            if (initialState != "")
                initialState = readElementState();
        }
        if (toTemp == meltingPoint || toTemp == boilingPoint)
        {
            cout << "What is the state of the element at the final temperature?" << endl;
            if (finalState != "")
                finalState = readElementState();
        }

        if (toTemp <= meltingPoint)
        {
            totalEntropy += mass * specificHeatSolid * log(toTemp / fromTemp);
            if (toTemp == meltingPoint && finalState != "Solid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
        }
        else if (toTemp <= boilingPoint)
        {
            if (fromTemp < meltingPoint)
                totalEntropy += mass * specificHeatSolid * log(meltingPoint / fromTemp);
            if (fromTemp == meltingPoint && initialState != "Liquid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
            if (fromTemp <= meltingPoint)
                totalEntropy += mass * specificHeatLiquid * log(toTemp / meltingPoint);
            else
                totalEntropy += mass * specificHeatLiquid * log(toTemp / fromTemp);
            if (toTemp == boilingPoint && finalState != "Liquid")
                totalEntropy += mass * latentHeatOfVaporization / boilingPoint;
        }
        else
        {
            if (fromTemp < meltingPoint)
                totalEntropy += mass * specificHeatSolid * log(meltingPoint / fromTemp);
            if (fromTemp == meltingPoint && initialState != "Liquid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;

            if (fromTemp < boilingPoint)
                totalEntropy += mass * specificHeatLiquid * log(fromTemp / meltingPoint);
            if (fromTemp == boilingPoint && initialState != "Gas")
                totalEntropy += mass * latentHeatOfVaporization / boilingPoint;

            if (fromTemp > boilingPoint)
                totalEntropy += mass * specificHeatGas * log(toTemp / fromTemp);
            else
                totalEntropy += mass * specificHeatGas * log(toTemp / boilingPoint);
        }
        return totalEntropy;
    }
};

#endif // BASEELEMENT_H_INCLUDED
