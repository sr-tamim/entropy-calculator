#include <iostream>
#include <vector>
#include "headers/allElements.h"
#include "headers/genericElement.h"

using namespace std;

int main()
{
    vector<genericElement*> elements = getAllElements();
    cout << "Choose an element: " << endl;
    for (int i = 0; i < elements.size(); i++)
    {
        cout << i + 1 << ". " << elements[i]->getElementName() << endl;
    }
    int choice;
    cout << "Write the number of the element: ";
    cin >> choice;
    cout << endl << elements[choice - 1]->getElementName() << " Selected" << endl;

    double mass, fromTemp, toTemp;
    cout << "Enter the mass of the element (in Kg): ";
    cin >> mass;
    cout << "Enter the initial temperature of the element (in K): ";
    cin >> fromTemp;
    cout << "Enter the final temperature of the element (in K): ";
    cin >> toTemp;

    cout << "The total entropy change is: " << elements[choice - 1]->totalEntropyChange(mass, fromTemp, toTemp) << " J/K" << endl;
}
