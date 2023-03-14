#pragma once
#include "Shop_repo.h"
#include<stack>//pt undo,redo
#include<iostream>
#include<fstream>
using namespace std;

enum class ActionType {
	ADD,
	REMOVE
};

class Shop_controller
{
public:
	//default constructor
	Shop_controller();

	//constructor with parameters
    Shop_controller(Shop_repo repository);

	//adds an item to the repository
	void add(Clothes* item);

	//removes an item from the repository by id
	bool remove(int id);

	//display the content of the repository
	void displayAll();

	//undo the last action performed.
	//if the action was ADD, the item wich wass added will be removed
	//if the action was REMOVE, the item wich was removed will de added
	bool undo();

	//redo the last action that was previously undone
	//if the action was REMOVE, the item which was added after the undo() will be removed once again
	//if the action was ADD, the item which was removed by the undo() will be added once again
	bool redo();

	
	//read the data from the .csv file where the clothes are stored in
	void read();

	
	//save the changes in the .csv file where the clothes are stored in
	void save();
	

	//returns the number of items in the shop
	int size();

	//void dump_to_csv(string fname);

	vector<Clothes*> filter(FilterCriteria& fp);
private:
	Shop_repo param_repo;//declari un repository
	std::stack<pair<ActionType, Clothes*>> undo_on_Stack;//asa se declara stacku pereche actiune+clasa de baza
	std::stack<pair<ActionType, Clothes*>> redo_on_Stack;
};

