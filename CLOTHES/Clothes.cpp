#include "Clothes.h"
#include <sstream>//asta are std::stringstream ss;

using namespace std;


Clothes::Clothes()
{
    price = 0;
    id = -1;
}

Clothes::Clothes(float price, int id)
{
    this->price = price;
    this->id = id;
}

float Clothes::get_price() const
{
    return this->price;
}

int Clothes::get_id() const
{
    return this->id;
}

void Clothes::set_price(float other)
{
    this->price = other;
}

void Clothes::set_id(int other)
{
    try {
        if (isalpha(other)) {
            throw exception();
        }
        else {
            this->id = other;
        }
    }
    catch (int) {
        cout << "The id introduced is not valid";
    }
}

bool Clothes::operator==(const Clothes& other)
{
    return this->id == other.id;
}

void Clothes::display(ostream& s) const
{
    s << setw(10);
    s << std::left << "PRICE: " << price << endl;
    s << setw(10);
    s << std::left << "ID: " << id << endl;
}

ostream& operator<<(ostream& s, const Clothes& item)
{
    item.display(s);
    return s;
}

string Clothes::to_string() const
{
    stringstream buff;
    buff << this->id << " " << this->price;
    return buff.str();
}