#include "Shop_repo.h"

#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;


Shop_repo::Shop_repo()
{
	Repo = vector<Clothes*>();//un vector gol
}

Shop_repo::Shop_repo(vector<Clothes*> Repo)
{
	this->Repo = Repo;
    this->write_to_file("est1.csv");
}


void Shop_repo::add(Clothes* item)
{
    auto it = std::find(this->Repo.begin(), this->Repo.end(), item);//find din algorithm inceput->sf caita item in repo
    if (it != this->Repo.end()) {//iteratoru daca a ajuns la final inseamna ca nu esista obiectul item in repo 
        throw std::runtime_error("Not in repo");
    }
    this->Repo.push_back(item);//pune la capat in stack FILO
}

Clothes* Shop_repo::remove(int id)
{
    Clothes* item = nullptr;
    auto index = find_if(this->Repo.begin(), this->Repo.end(), [id](Clothes* item)->bool {return item->get_id() == id; });
    if (index != this->Repo.end()) {
        item = *index;
        this->Repo.erase(index);
    }
    return item;
    throw std::runtime_error("doesn't exist");
}

Clothes* Shop_repo::get(int index)
{
    if (index >= Repo.size())
        throw std::out_of_range("Index out of range");
    return this->Repo[index];
    
}


ostream& Shop_repo::display(ostream& s, bool(*function)(Clothes* item))
{
    for (auto i = 0; i < Repo.size(); i++)
    {
        if (function(Repo[i]))
        {
            s << *Repo[i];
        }
    }
    return s;
}


/*
bool Shop_repo::readData(const char* csv)
{
    ifstream inputFile;
    string data;
    inputFile.open(csv, fstream::in);
    if (inputFile.is_open()) {
        while (getline(inputFile, data)) {
            stringstream ls(data);
            string el;
            vector<string> v;
            while (getline(ls, el, ',')) {
                v.push_back(el);
            }
            //Clothes i;
            //i.set_id(stoi(v[0]));
            //this->add(&i);
        }
    }
    inputFile.close();
    return true;

}


/*
bool Shop_repo::saveData(const char* csv, Clothes* item)
{
    ofstream outputFile;
    outputFile.open(csv, fstream::out);
    outputFile << item->get_id() << ", " << item->get_price();
    outputFile.close();
    return true;
}
*/
/*
void Shop_repo::iterateAndSave(const char* csv)
{
    //ifstream oldFile(csv);
    ofstream
        outputFile(csv);
    if (!outputFile.is_open())
    {
        throw ("not open");
    }
    for (auto i = 0; i < this->Repo.size(); i++) {
        this->Repo[i]->saveToCSV(outputFile);
        outputFile << endl;
    }

    outputFile.close();

}

bool Shop_repo::load_from_csv(string fname)
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file(fname, ios::in);
    if (file.is_open())
    {
        if (file.is_open())
        {
            while (getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                    row.push_back(word);
                Clothes* b = new Clothes{ stoi(row.at(0)),stof(row.at(1)) };
                this->add(b);
                //content.push_back(row);
            }
        }
    }
    else
        cout << "Could not open the file\n";
    file.close();
    return 0;
}


void Shop_repo::dump_to_csv(string fname)
{
    ofstream myFile;
    myFile.open(fname);
        for (auto it : this->Repo) {
            myFile << it->get_price() << ",";
            myFile <<  it->get_id() << endl;
            //return 1;
        }
    myFile.close();
}
*/
bool Shop_repo::write_to_file(string path)
{
    ofstream output(path);//output operations
    if (!output.is_open())
        return false;
    for (Clothes* i : Repo)
    {
        output << i->get_id() << "," << i->get_price() << endl;
    }
    output.close();
    return true;

}

bool Shop_repo::reading_from_file(string path)
{
    ifstream inputFile;
    string data;
    inputFile.open(path, fstream::in);
    if (inputFile.is_open()) {
        while (getline(inputFile, data)) {
            stringstream ls(data);
            string el;
            vector<string> v;
            while (getline(ls, el, ',')) {
                v.push_back(el);
            }
            Clothes i;
            i.set_id(stoi(v[0]));
            this->add(&i);
        }
    }
    return true;
}
/*
vector<string> tokenize(string str, char delimiter)
{
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}
*/

int Shop_repo::size()
{
    return this->Repo.size();
}

vector<Clothes*> Shop_repo::filter(FilterCriteria& criteria)
{
    return criteria.filter(this->Repo);
}


