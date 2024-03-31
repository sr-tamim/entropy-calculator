#ifndef ELEMENTSTATE_H_INCLUDED
#define ELEMENTSTATE_H_INCLUDED

#include <iostream>
using namespace std;

class elementState
{
public:
    string readElementState() {
    string state;
    cout << "1. Solid\n2. Liquid\n3. Gas" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        state = "Solid";
        break;
    case 2:
        state = "Liquid";
        break;
    case 3:
        state = "Gas";
        break;
    default:
        cout << "Invalid choice" << endl;
        state = readElementState();
        break;
    }
    return state;
}

protected:
    string initialState = "";
    string finalState = "";

    void askForState(double fromTemp, double toTemp, double meltingPoint, double boilingPoint)
    {
        if (initialState == "" && (fromTemp == meltingPoint || fromTemp == boilingPoint))
        {
            cout << "What is the state of the element at the initial temperature?" << endl;
            initialState = readElementState();
        }
        if (finalState == "" && (toTemp == meltingPoint || toTemp == boilingPoint))
        {
            cout << "What is the state of the element at the final temperature?" << endl;
            finalState = readElementState();
        }
    }
};

#endif  // ELEMENTSTATE_H_INCLUDED
