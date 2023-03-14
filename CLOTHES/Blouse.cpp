#include "Blouse.h"
#include <sstream>


Blouse::Blouse() : Clothes()
{
	color = "";
	size = 0;
}

Blouse::Blouse(string color, int size, float price, int id) : Clothes(price, id)
{
	this->color = color;
	this->size = size;
}

string Blouse::to_string() const
{
	std::ostringstream s;
	s << "The blouse with id " << this->id << " has color " << this->color << " and is of size " << this->size <<"; it costs " << this->price<<" lei";
	return s.str();
}


