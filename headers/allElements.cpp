#include <vector>
#include <memory>
#include "../elements/water.h"
#include "../elements/Silver.h"
#include "../elements/Oxygen.h"
#include "../elements/Hydrogen.h"
#include "../elements/Diamond.h"
#include "../elements/Sugar.h"
#include "../elements/Gold.h"
#include "baseElement.h"

vector<unique_ptr<baseElement>> getAllElements()
{
	vector<unique_ptr<baseElement>> elements;
	elements.push_back(make_unique<water>());
	elements.push_back(make_unique<Silver>());
    elements.push_back(make_unique<Oxygen>());
    elements.push_back(make_unique<Hydrogen>());
    elements.push_back(make_unique<Diamond>());
    elements.push_back(make_unique<Sugar>());
    elements.push_back(make_unique<Gold>());

	return elements;
}
