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
#include "../elements/Gold.h"
#include "../elements/Sugar.h"
#include "../elements/Salt.h"
#include "../elements/Copper.h"
#include "../elements/EthanoicAcid.h"
#include "../elements/Iron.h"

std::vector<std::unique_ptr<baseElement>> getAllElements()
{
    std::vector<std::unique_ptr<baseElement>> elements;
    elements.push_back(std::make_unique<water>());
    elements.push_back(std::make_unique<Silver>());
    elements.push_back(std::make_unique<Oxygen>());
    elements.push_back(std::make_unique<Hydrogen>());
    elements.push_back(std::make_unique<Diamond>());
    elements.push_back(std::make_unique<Gold>());
    elements.push_back(std::make_unique<Sugar>());
    elements.push_back(std::make_unique<Salt>());
    elements.push_back(std::make_unique<Copper>());
    elements.push_back(std::make_unique<EthanoicAcid>());
    elements.push_back(std::make_unique<Iron>());

    return elements;
}

#endif
