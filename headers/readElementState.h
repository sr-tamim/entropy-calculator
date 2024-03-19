
#pragma once
#ifndef READ_ELEMENT_STATE
#define READ_ELEMENT_STATE

#include <iostream>
std::string readElementState() {
    std::string state;
    std::cout << "1. Solid\n2. Liquid\n3. Gas" << std::endl;
    int choice;
    std::cin >> choice;
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
        std::cout << "Invalid choice" << std::endl;
        state = readElementState();
        break;
    }
    return state;
}

#endif
