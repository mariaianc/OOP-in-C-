#pragma once
#include <vector>
using std::vector;
#include "Clothes.h"
class FilterCriteria
{
public:
	virtual vector <Clothes*> filter(vector<Clothes*>& all) = 0;

};

class Filtering_price: virtual public FilterCriteria 
{
private:
	float price;

public:
	Filtering_price(float p) { price = p; }
	vector <Clothes*> filter(vector<Clothes*>& item) override;
};