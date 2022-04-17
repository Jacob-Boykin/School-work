#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

uint64_t djb2(string str) {
    const char* ptr = str.c_str();
    uint64_t hash = 5381;
    int c;
    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

class Person {
public:
    string id;
    string first;
    string last;
    string email;
    string phone;
    string city;
    string state;
    string postalCode;

};


class HashTable {
public:
    int buckets;
    vector<vector<vector<string>>>* table;

    void printHash(int spot);

    bool lookup(string key, int spot);

    HashTable(int n);

    void insertItem(vector<string> person, int spot);

    int hashFunction(uint64_t num)
    {
        return (num % buckets);
    }


};

int keyCount(const vector<vector<string>> vec, int index, string key){
  int count=0;
  for (int i=0;i<vec.size();i++){
    if (vec.at(i).at(index)==key){
      count++;
    }
  }
  return count;
}
vector<string> uniqueKeys(vector<vector<string>> bucket, int spot){
  vector<string> vec;
  bool inVec = false;
  int k = 0;
    if(vec.empty())
    {
        vec.push_back(bucket.at(0).at(spot));
    }
    for (int i=0;i<bucket.size();i++){
        inVec = false;
        for(k = 0; k < vec.size(); k++)
        {
            if (vec[k] == bucket.at(i).at(spot)){
            inVec = true;
            }
        }
        if(inVec == false)
        {
        vec.push_back(bucket.at(i).at(spot));
        }
        
    }
  return vec;
}
void HashTable::printHash(int spot)
{
    for(int i = 0; i < buckets; i++)
    {
        if(!table->at(i).empty())
        {   
            vector<string> keys = uniqueKeys(table->at(i),spot);
            for (int j=0;j<keys.size();j++){
                if(j == 0)
                {
                cout << i << ": " << keys.at(j) << " " << "(" << keyCount(table->at(i),spot,keys.at(j))<< ")" << ",";
                }
                else 
                    cout << keys.at(j) << " " << "(" << keyCount(table->at(i),spot,keys.at(j))<< ")" << ",";
            }
            cout << endl;
        }
    }
}


bool HashTable::lookup(string key, int spot)
{
    bool found = false;
    for (int i = 0; i < table->size(); i++) {
        if(!table->at(i).empty())
        {
            for(int j = 0; j < table->at(i).size(); j++)
            {
                if(table->at(i).at(j).at(spot) == key)
                {
                    if(found == false)
                    {
                        cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                    }
                    found = true;
                    for(int k = 0; k < 8; k++)
                    {
                        if(k < 7)
                        {
                            cout << table->at(i).at(j).at(k) << ",";
                        }
                        else
                        {
                            cout << table->at(i).at(j).at(k) << endl;
                        }
                    }
                }
            }       
        }
    }

    if(found == true)
    {
        return true;
    }
    return false;
}

HashTable::HashTable(int n)
{
    this->buckets = n;
    table = new vector<vector<vector<string>>>[n];

}

void HashTable::insertItem(vector<string> person, int spot)
{
    int index = hashFunction(djb2(person.at(spot)));
    //table->at(index).resize(table->at(index).size() + 1);
    table->at(index).push_back(person);
}









void getVal(istream& is, string& str) {
    char ch;
    string line;

    is >> ch;
    getline(is, line);

    str = ch + line;
}

bool isValidKey(const string& key) {
    string validKeys[8] = { "Id", "FirstName", "LastName", "Email", "Phone", "City", "State", "PostalCode" };
    for (int i = 0; i < 8; i++) {
        if (key == validKeys[i]) {
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Usage: ./a.out filename.txt table_size key" << endl;
        return 1;
    }

    string filename = argv[1];
    int tableSize = stoi(argv[2]);

    HashTable h(tableSize);
    string key = argv[3];

    ifstream file(filename);
    if (!file) {
        cout << "Unable to open " << filename << endl;
        return 2;
    }

    if (!isValidKey(key)) {
        cout << "Invalid key: " << key << endl;
        return 3;
    }

    // This is an example of how to retreive the tokens from the input file
    // You will need to modify this to fit your needs to build the hash table
    vector<string> person;
    int i = 0;
    int spot;
    string line, token, keySpot[8];
    getline(file, line); // consume header line
    istringstream kss(line);
    while (getline(kss, token, '\t')) {
        keySpot[i] = token;
        if (keySpot[i] == key)
        {
            spot = i;
        }
        i++;
    }

    while (getline(file, line)) {
        istringstream iss(line);
        person.clear();

        while (getline(iss, token, '\t')) {
            person.push_back(token);
        }
        h.insertItem(person, spot);
    }



    cout << "Commands:" << endl << "\tprint" << endl << "\tlookup <key>" << endl << "\tquit" << endl;
    string cmd, val;
    while (1) {
        cout << endl << "Enter a command:" << endl;
        cin >> cmd;
        if (cmd == "quit") {
            break;
        }
        else if (cmd == "print") {
            h.printHash(spot);
        }
        else if (cmd == "lookup") {
            getVal(cin, val);
            if(!h.lookup(val, spot))
                cout << "No results" << endl;
        }
        else {
            getline(cin, val);
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}