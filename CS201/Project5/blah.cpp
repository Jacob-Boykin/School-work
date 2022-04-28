#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {

   string filename = argv[1];
   ifstream file(filename);
   vector<int> freq(127);
   stringstream buffer;
   buffer <<file.rdbuf();
   string contents(buffer.str());
   
    for(int i = 0; i < contents.size(); i++)
    {
        freq.at(contents[i])++;
    }

   return 0;
}