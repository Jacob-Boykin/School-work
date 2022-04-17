#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
void printUncomp(vector<string> words)
{
   int count = 0;
   for(int i = 0; i < words.size(); i++)
   {
      for(int k = 0; k < words.at(i).size(); k++)
      {
         count++;
      }
   }

}

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

   string filename = argv[1];
   ifstream file(filename);
   vector<string> words;
   string line, tempWord;
   while(getline(file, line))
   {
      istringstream iss(line);
      if(!line.empty())
      {
         while(getline(iss, tempWord, '\t'))
         {
            words.push_back(tempWord);
         }
      }
   }
   printUncomp(words);

   return 0;
}
