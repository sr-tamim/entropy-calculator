#include<vector>
#include "../elements/water.h"
#include "../elements/Silver.h"
#include "../elements/Diamond.h"
#include "../elements/Suger.h"

#include "baseElement.h"


vector<baseElement*> getAllElements()
{
    vector<baseElement*> elements;
    elements.push_back(new water());
    elements.push_back(new Silver());
    elements.push_back(new Diamond());
    elements.push_back(new Suger());
    
    return elements;
}
