#include "headers/allElements.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<baseElement *> elements = getAllElements();
	cout << "Choose an element: " << endl;
	for (int i = 0; i < int(elements.size()); i++)
	{
		cout << i + 1 << ". " << elements[i]->getElementName() << endl;
	}
	int choice;
	cout << "Write the number of the element: ";
	cin >> choice;
	cout << endl
		 << elements[choice - 1]->getElementName() << " Selected" << endl;

	double mass, fromTemp, toTemp;
	cout << "Enter the mass of the element (in Kg): ";
	cin >> mass;
	if (mass <= 0)
	{
		cout << "Mass must be a positive value" << endl;
		return 0;
	}
	cout << "Enter the initial temperature of the element (in K): ";
	cin >> fromTemp;
	cout << "Enter the final temperature of the element (in K): ";
	cin >> toTemp;
	if (fromTemp > toTemp)
	{
		cout << "Initial temperature can not be greater than final temperature"
			 << endl;
		return 0;
	}

	double totalHeat =
		elements[choice - 1]->totalHeatNeeded(mass, fromTemp, toTemp);
	double totalEntropy =
		elements[choice - 1]->totalEntropyChange(mass, fromTemp, toTemp);
	cout << "The total heat needed is: " << totalHeat << " J" << endl;
	cout << "The total entropy change is: " << totalEntropy << " J/K" << endl;
	return 0;

	// thank you.. feel free to contribute here..:)
}
