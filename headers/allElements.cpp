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
    elements.push_back(new Oxygen());
    elements.push_back(new Hydrogen());
    elements.push_back(new Diamond());
    elements.push_back(new Sugar());
    elements.push_back(new Gold());

	return elements;
}
