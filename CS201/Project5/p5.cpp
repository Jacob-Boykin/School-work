#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class Huff
{
private:
   vector<pair<char,int>> letters;
  
   int Parent(int i){
   return(i - 1) / 2;  
   }
   
   int Left(int i)
   {
      return (2 * i + 1);
   }
   int Right(int i)
   {
      return(2 * i + 2);
   }

   void heapify_down(int i)
    {
        int left = Left(i);
        int right = Right(i);
 
        int largest = i;
 

        if (left < letters.size() && letters.at(Left(i)).second > letters.at(i).second) {
            largest = left;
        }
 
        if (right < letters.size() && letters.at(Right(i)).second > letters.at(largest).second) {
            largest = right;
        }
 
        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            swap(letters[i], letters[largest]);
            heapify_down(largest);
        }
    }

   void heapify_up(int i)
    {
        // check if the node at index `i` and its parent violate the heap property
        if (i && letters.at(Parent(i)).second < letters.at(i).second)
        {
            // swap the two if heap property is violated
            swap(letters[i], letters[Parent(i)]);
 
            // call heapify-up on the parent
            heapify_up(Parent(i));
        }
    }
public:
   Huff(/* args */);
   ~Huff();
};

Huff::Huff(/* args */)
{
}

Huff::~Huff()
{
}

void printUncomp(string content)
{
   
   cout << "Uncompressed length: " << content.size() * 8 <<  " bits" << endl;
}
void printComp(vector<pair<char, int>> letters)
{
   
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
   letters = (letters);
   for(int i = 0; i < letters.size(); i++)
   {
      cout <<"'" << letters.at(i).first << "'" << " | " << letters.at(i).second << endl;
   }
   return 0;



   
}
