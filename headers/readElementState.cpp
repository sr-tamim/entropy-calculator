#include <iostream>
using namespace std;

string readElementState()
{
    string state;
    cout << "1. Solid\n2. Liquid\n3. Gas" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
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
        break;
    }
    return state;
}
