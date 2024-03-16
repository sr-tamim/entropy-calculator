// get all elements from elements folder

#pragma once
#ifndef ALL_ELEMENTS
#define ALL_ELEMENTS

#include <vector>
#include <memory>
#include "baseElement.h"

#include "../elements/water.h"
#include "../elements/Silver.h"
#include "../elements/Oxygen.h"
#include "../elements/Hydrogen.h"
#include "../elements/Diamond.h"
#include "../elements/Sugar.h"
#include "../elements/Gold.h"

std::vector<std::unique_ptr<baseElement>> getAllElements()
{
    std::vector<std::unique_ptr<baseElement>> elements;
    elements.push_back(std::make_unique<water>());
    elements.push_back(std::make_unique<Silver>());
    elements.push_back(std::make_unique<Oxygen>());
    elements.push_back(std::make_unique<Hydrogen>());
    elements.push_back(std::make_unique<Diamond>());
    elements.push_back(std::make_unique<Sugar>());
    elements.push_back(std::make_unique<Gold>());

    return elements;
}

#endif
