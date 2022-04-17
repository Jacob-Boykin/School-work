#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
// void printUncomp()
// {

// }
// void printComp()
// {

// }
// void printLetters()
// {

// }
// int count()
// {

// }


int main(int argc, char *argv[]) {
   string filename(argv[2]);
   fstream file(filename);
   vector<string> words;
   string temp, line, reset = "";
   int size;
   
   while(getline(file, line))
   {
      temp = reset;
      istringstream iss(line);
      while(getline(iss, temp, '\t'))
      {
         words.push_back(temp);
      }
   }
   size = words.size();
   for(int i = 0; i < size; i++)
   {
      cout << words.at(i) << endl;
   }
   return 0;
}
