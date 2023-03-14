#pragma once
#include "Clothes.h"
class Blouse : public Clothes
{
public:
    Blouse();
    Blouse(string color, int size, float price, int id);

    string get_color()const;
    int get_size()const;

    string to_string()const;//suprascrie functia din clasa de baza 

private:
    string color;
    int size;

};

