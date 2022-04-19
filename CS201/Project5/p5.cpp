#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
void printUncomp(vector<string> words)
{
   int size = words.size();
   int count = 0;
   for(int i = 0; i < size; i++)
   {
      count += words.at(i).size();
   }
   cout << "Uncompressed length: " << count * 8 <<  " bits" << endl;
}

vector<char> uniqueLetters(vector<string> words)
{
   vector<char> vec;
  bool inVec = false;
  int k = 0;
   if(vec.empty())
   {
   vec.push_back(words.at(0).at(0));
   }
   for (int i=0;i<words.size();i++)
   {
      inVec = false;
      for(int j = 0; j < words.at(i).size(); j++)
      {
         for(int k = 0; k < vec.size(); k++)
         {
            if(vec.at(k) == words.at(i).at(j))
            {
               inVec = true;
               break;
            }
         }
         if(inVec == false)
         {
            vec.push_back(words.at(i).at(k));
         }
      }
   }
        
    
  return vec;
}



int main(int argc, char *argv[]) {

   string filename = argv[1];
   ifstream file(filename);
   vector<string> words;
   string line, tempWord;
   while(getline(file, line))
   {
      istringstream iss(line);
      while(getline(iss, tempWord, '\t'))
      {
         words.push_back(tempWord);
      }
   }
   printUncomp(words);
   vector<char> letters = uniqueLetters(words);
   for(int i = 0; i < letters.size(); i++)
   {
      cout << letters.at(i) << " ";
   }
   return 0;
}
