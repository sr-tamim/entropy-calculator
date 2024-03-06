#include<vector>
#include "../elements/water.h"
#include "genericElement.h"


vector<genericElement*> getAllElements()
{
    vector<genericElement*> elements;
    elements.push_back(new water());
    return elements;
}
