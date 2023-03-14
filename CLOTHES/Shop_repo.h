#pragma once
#include <vector>
#include <ostream>
#include<iostream>
#include<fstream>
#include<cstdio>
#include "Clothes.h"
#include "FilterCriteria.h"
using std::vector;
using namespace std;


class Shop_repo
{
private:
	//use a vector for the repository to be easier to work with the objects
	vector<Clothes*> Repo;
	
public:

	//default constructor
	//reads data from the .csv file
	Shop_repo();

	//constructor with parameters
	Shop_repo(vector<Clothes*> Repo);

	//adds an intem into the reopsitory
	//item = the object wich will be added into the repository
	void add(Clothes* item);

	//remove an item from the repository by id
	//id=The id of the item you want to delete
	//return the element you deleted
	Clothes* remove(int id);

	//gets the object at a given index from the repository
	Clothes* get(int index);

	//displays an item 
	//"os" : the ostream operator we will use to display the item 
	//"function" : the property the item shall fulfill in order to be eligible for display
	//return the item
	ostream& display(ostream& s, bool(*function)(Clothes* item));

	/*
	//read data from a .csv file
	//csv = the path of the .csv file
	//return true if the data has been successfully read from the file
	bool readData(const char* csv);
	void iterateAndSave(const char* csv);
	void dump_to_csv(string fname);
	*/

	bool write_to_file(string path);
	bool reading_from_file(string path);
	

	//computes the size of the repository
	int size();

	vector <Clothes*> filter(FilterCriteria& criteria);

};

