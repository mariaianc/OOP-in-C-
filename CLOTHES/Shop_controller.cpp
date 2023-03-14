#include "Shop_controller.h"

Shop_controller::Shop_controller()
{
	//nmc
}

Shop_controller::Shop_controller(Shop_repo repo)
{
	this->param_repo = repo;//din privarte
}

void Shop_controller::add(Clothes* item)
{
	this->param_repo.add(item);
	undo_on_Stack.push(std::make_pair(ActionType::ADD, item));
}

bool Shop_controller::remove(int id)
{
	Clothes* haina = param_repo.remove(id);
	if (haina)
	{
		undo_on_Stack.push(std::make_pair(ActionType::REMOVE, haina));
	}
	return true;
}

void Shop_controller::displayAll()
{
	param_repo.display(cout, [](Clothes* i)
		{
			cout << endl;
			return true;
		});
}

bool Shop_controller::undo()
{
	///ADD:
	if (this->undo_on_Stack.top().first == ActionType::ADD) {
		this->redo_on_Stack.push(std::make_pair(ActionType::ADD, this->redo_on_Stack.top().second));
		this->undo_on_Stack.pop();
		this->param_repo.remove(this->redo_on_Stack.top().second->get_id());
		return true;
	}
	///REMOVE:
	else if (this->undo_on_Stack.top().first == ActionType::REMOVE) {
		this->redo_on_Stack.push(std::make_pair(ActionType::REMOVE, this->undo_on_Stack.top().second));
		this->undo_on_Stack.pop();
		this->param_repo.add(this->redo_on_Stack.top().second);
		return true;
	}
	else if (this->undo_on_Stack.size() == 0) {
		return false;
	}
}

bool Shop_controller::redo()
{
	if (this->redo_on_Stack.size() == 0) {
		return false;
	}
	///ADD:
	if (this->redo_on_Stack.top().first == ActionType::ADD) {
		this->undo_on_Stack.push(std::make_pair(ActionType::ADD, this->redo_on_Stack.top().second));
		this->redo_on_Stack.pop();
		this->param_repo.add(this->undo_on_Stack.top().second);
		return true;
	}
	///REMOVE:
	if (this->redo_on_Stack.top().first == ActionType::REMOVE) {
		this->undo_on_Stack.push(std::make_pair(ActionType::REMOVE, this->redo_on_Stack.top().second));
		this->redo_on_Stack.pop();
		this->param_repo.remove(this->undo_on_Stack.top().second->get_id());
		return true;
	}
}



void Shop_controller::read()
{
	this->param_repo.reading_from_file("fisier.csv");
}


void Shop_controller::save()
{
	this->param_repo.write_to_file("fisier.csv");
}


int Shop_controller::size()
{
	return this->param_repo.size();
}



/*
void Shop_controller::dump_to_csv(string fname)
{
	ofstream myFile;
	myFile.open(fname);
	if (!myFile.is_open())
		cout << "Could not open the file\n";
	else
		this->param_repo.dump_to_csv(fname);
}
*/

vector<Clothes*> Shop_controller::filter(FilterCriteria& fp)
{
	return param_repo.filter(fp);
}
