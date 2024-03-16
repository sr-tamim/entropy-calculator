#include <vector>
#include <memory>
#include "../elements/water.h"
#include "../elements/Silver.h"
#include "baseElement.h"

vector<unique_ptr<baseElement>> getAllElements()
{
	vector<unique_ptr<baseElement>> elements;
	elements.push_back(make_unique<water>());
	elements.push_back(make_unique<Silver>());
	return elements;
}
