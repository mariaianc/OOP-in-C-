#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <istream>//citire fisier
#include<iomanip>//setw
using std::string;
using std::cout;
using namespace std;


class Clothes
{
public:
	//default constructor
	//returns nothing 
	Clothes();

	// Constructor with parameters
	//price= the price of an item
	//id=the id of an item
	Clothes(float price, int id);

	//getters for price and id
	//returns the price and the id of an item
	float get_price()const;
	int get_id()const;

	//setter for the price
	//podifies the price of an item and returns nothing
	void set_price(float other);

	void set_id(int other);
	
	//makes an virtual method to transform the object in a string 
	//virtual to be easyer to overload the method in the subclasses
	virtual string to_string()const;

	
	bool operator==(const Clothes& other);

	// Overloading the << operator
	friend ostream& operator<<(ostream& s, const Clothes& item);

	//display method
	//"s" : the ostream operator
	virtual void display(ostream& s)const;

	//saves the data into a .csv file
	//"outputFile" : the name of the .csv file
	virtual void saveToCSV(std::ostream& outputFile) {
		outputFile << price << ", " << id;
	}

protected:
	float price;
	int id;
};

