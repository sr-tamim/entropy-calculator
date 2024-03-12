#ifndef BASEELEMENT_H_INCLUDED
#define BASEELEMENT_H_INCLUDED

#include <iostream>
#include <math.h>
#ifdef _USE_GMP
#   include <gmp.h>
#   include <gmpxx.h>
#endif // _USE_GMP
#include "readElementState.h"
using namespace std;

#ifdef _USE_GMP
    typedef mpf_class bigfloat;
#   define bigfloat_unwrap(X) (bigfloat(X)).get_d()
#else
    typedef double bigfloat;
#   define bigfloat_unwrap(X) (X)
#endif // _USE_GMP

class baseElement
{
private:
    string elementName;
    bigfloat latentHeatOfFusion;
    bigfloat latentHeatOfVaporization;
    bigfloat specificHeatSolid;
    bigfloat specificHeatLiquid;
    bigfloat specificHeatGas;
    bigfloat meltingPoint;
    bigfloat boilingPoint;
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
    bigfloat getLatentHeatOfFusion() { return latentHeatOfFusion; }
    bigfloat getLatentHeatOfVaporization() { return latentHeatOfVaporization; }
    bigfloat getSpecificHeatSolid() { return specificHeatSolid; }
    bigfloat getSpecificHeatLiquid() { return specificHeatLiquid; }
    bigfloat getSpecificHeatGas() { return specificHeatGas; }
    bigfloat getMeltingPoint() { return meltingPoint; }
    bigfloat getBoilingPoint() { return boilingPoint; }

    bigfloat totalHeatNeeded(double mass, double fromTemp, double toTemp)
    {
        if (fromTemp < 0 || toTemp < 0)
        {
            cout << "Temperature cannot be less than 0 K" << endl;
            return 0;
        }

        bigfloat totalHeat = 0;
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

    bigfloat totalEntropyChange(double mass, double fromTemp, double toTemp)
    {
        if (fromTemp < 0 || toTemp < 0)
        {
            cout << "Temperature cannot be less than 0 K" << endl;
            return 0;
        }

        bigfloat totalEntropy = 0;
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
            totalEntropy += mass * specificHeatSolid * log(bigfloat_unwrap(toTemp / fromTemp));
            if (toTemp == meltingPoint && finalState != "Solid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
        }
        else if (toTemp <= boilingPoint)
        {
            if (fromTemp < meltingPoint)
                totalEntropy += mass * specificHeatSolid * log(bigfloat_unwrap(meltingPoint / fromTemp));
            if (fromTemp == meltingPoint && initialState != "Liquid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;
            if (fromTemp <= meltingPoint)
                totalEntropy += mass * specificHeatLiquid * log(bigfloat_unwrap(toTemp / meltingPoint));
            else
                totalEntropy += mass * specificHeatLiquid * log(bigfloat_unwrap(toTemp / fromTemp));
            if (toTemp == boilingPoint && finalState != "Liquid")
                totalEntropy += mass * latentHeatOfVaporization / boilingPoint;
        }
        else
        {
            if (fromTemp < meltingPoint)
                totalEntropy += mass * specificHeatSolid * log(bigfloat_unwrap(meltingPoint / fromTemp));
            if (fromTemp == meltingPoint && initialState != "Liquid")
                totalEntropy += mass * latentHeatOfFusion / meltingPoint;

            if (fromTemp < boilingPoint)
                totalEntropy += mass * specificHeatLiquid * log(bigfloat_unwrap(fromTemp / meltingPoint));
            if (fromTemp == boilingPoint && initialState != "Gas")
                totalEntropy += mass * latentHeatOfVaporization / boilingPoint;

            if (fromTemp > boilingPoint)
                totalEntropy += mass * specificHeatGas * log(bigfloat_unwrap(toTemp / fromTemp));
            else
                totalEntropy += mass * specificHeatGas * log(bigfloat_unwrap(toTemp / boilingPoint));
        }
        return totalEntropy;
    }
};
#endif // BASEELEMENT_H_INCLUDED
