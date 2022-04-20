#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void printUncomp(string content)
{
   
   cout << "Uncompressed length: " << content.size() * 8 <<  " bits" << endl;
}
void printComp(vector<pair<char, int>> letters)
{
   
}

vector<pair<char, int>> sortingLetters(vector<pair<char, int>> letters)
{
   pair<char, int> temp;
   for(int i = 0; i < letters.size() - 1; i++)
   {
      for(int k = 0; k < letters.size() - i - 1; k++)
      {
         if(letters.at(k).first > letters.at(k + 1).first)
         {
            temp = letters.at(k);
            letters.at(k) = letters.at(k + 1);
            letters.at(k + 1) = temp;
         }
      }
   }
   return letters;
}

int HuffmanTree()
{

}

int main(int argc, char *argv[]) {

   string filename = argv[1];
   ifstream file(filename);
   vector<pair<char, int>> letters;
   char c;
   bool inLetter = false;
   stringstream buffer;
   buffer <<file.rdbuf();
   string contents(buffer.str());
   for(int i = 0; i < contents.size(); i++)
   {
      c = contents[i];
      inLetter = false;
      for(int k = 0; k < letters.size(); k++)
      {
         if(c == letters.at(k).first)
         {
            letters.at(k).second++;
            inLetter = true;
         }
      }
      if(inLetter == false)
      {
         letters.push_back(make_pair(c, 1));
      }
   }
   printUncomp(contents);
   printComp(letters);
   letters = sortingLetters(letters);
   for(int i = 0; i < letters.size(); i++)
   {
      cout <<"'" << letters.at(i).first << "'" << " | " << letters.at(i).second << endl;
   }
   return 0;
}
