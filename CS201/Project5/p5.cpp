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

void heapify(vector<pair<char, int>> letters, int i)
{
   int n = letters.size();
   int smallest = i; // node being heaped
   int l = 2 * i + 1; // left child node 
	int r = 2 * i + 2; // right child node
   //cout << "1" << endl;

   if(l < n && letters.at(l).second < letters.at(smallest).second)
   {
      smallest = l;
   }

   if(r < n && letters.at(r).second < letters.at(smallest).second)
   {
      smallest = r;
   }
   if(smallest != i)
   {
      swap(letters.at(i), letters.at(smallest));
      heapify(letters,smallest);
   }
}

 vector<pair<char, int>> buildHeap(vector<pair<char, int>> letters)
{

   int n = letters.size();
   for(int i = n; i >= 0; i--)
   {
      heapify(letters, i);
   }
   return letters;
}


// vector<pair<char, int>> sortingLetters(vector<pair<char, int>> letters)
// {
//    pair<char, int> temp;
//    for(int i = 0; i < letters.size() - 1; i++)
//    {
//       for(int k = 0; k < letters.size() - i - 1; k++)
//       {
//          if(letters.at(k).first > letters.at(k + 1).first)
//          {
//             temp = letters.at(k);
//             letters.at(k) = letters.at(k + 1);
//             letters.at(k + 1) = temp;
//          }
//       }
//    }
//    return letters;
// }



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
   
   // for(int i = 0; i < letters.size(); i++)
   // {
   //    cout <<"'" << letters.at(i).first << "'" << " | " << letters.at(i).second << endl;
   // }
   letters = buildHeap(letters);
   for(int i = 0; i < letters.size(); i++)
   {
      cout <<"'" << letters.at(i).first << "'" << " | " << letters.at(i).second << endl;
   }
   return 0;



   
}
