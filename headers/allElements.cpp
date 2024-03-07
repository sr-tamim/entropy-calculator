#include<vector>
#include "../elements/water.h"
#include "baseElement.h"


vector<baseElement*> getAllElements()
{
    vector<baseElement*> elements;
    elements.push_back(new water());
    return elements;
}
