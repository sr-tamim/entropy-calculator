#include<vector>
#include "../elements/water.h"
#include "../elements/Silver.h"
#include "baseElement.h"


vector<baseElement*> getAllElements()
{
    vector<baseElement*> elements;
    elements.push_back(new water());
    elements.push_back(new Silver());
    return elements;
}
