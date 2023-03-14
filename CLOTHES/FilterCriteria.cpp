#include "FilterCriteria.h"

vector<Clothes*> Filtering_price::filter(vector<Clothes*>& all)
{
    vector<Clothes*> result;
    //for(int i = 0; i<item.size();i++)
    for (auto i : all)//i e elementul in sine, nu index
    {
        if (i->get_price() <= this->price)
        {
            result.push_back(i);
        }
    }
    return result;
}
