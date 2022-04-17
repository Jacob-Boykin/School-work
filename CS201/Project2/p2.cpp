#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <limits.h>
#include <string.h>
using namespace std;

void MergeInt(int numbers[], int i, int j, int k) {
int mergedSize;   // size of partition
int mergePos;     // position of insert merged number
int leftPos;      // position of elements in left
int rightPos;     // postition of elements in right
int* mergedNumbers = nullptr;

mergePos = 0;
mergedSize = k - i + 1;
leftPos = i;
rightPos = j + 1;
mergedNumbers = new int[mergedSize];

while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
   delete[] mergedNumbers;
}

void MergeWords(string words[], int i, int j, int k) {
int mergedSize;   // size of partition
int mergePos;     // position of insert merged number
int leftPos;      // position of elements in left
int rightPos;     // postition of elements in right
string* mergedwords = nullptr;

mergePos = 0;
mergedSize = k - i + 1;
leftPos = i;
rightPos = j + 1;
mergedwords = new string[mergedSize];

while (leftPos <= j && rightPos <= k) {
      if (words[leftPos] < words[rightPos]) {
         mergedwords[mergePos] = words[leftPos];
         ++leftPos;
      }
      else {
         mergedwords[mergePos] = words[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedwords[mergePos] = words[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedwords[mergePos] = words[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      words[i + mergePos] = mergedwords[mergePos];
   }
   delete[] mergedwords;
}

void MergeSortInt(int numbers[], int i, int k) {
int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSortInt(numbers, i, j);
      MergeSortInt(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      MergeInt(numbers, i, j, k);
   }
}

void MergeSortWords(string words[], int i, int k) {
int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSortWords(words, i, j);
      MergeSortWords(words, j + 1, k);
      
      // Merge left and right partition in sorted order
      MergeWords(words, i, j, k);
   }
}


int main(int argc, char *argv[]) {
    ifstream in1;
    ifstream in2;
    // variable for numbers
    int nums[20000];
    int nums2[20000];
    //variable for words
    string words[20000];
    string words2[20000];
    //counts for while loops
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    //bools for dups
    bool dupes = false;
    //variables for dupes
    int numDupes[20000];
    string wordDupes[20000];
// Opening the files
    in1.open(argv[2]);
    in2.open(argv[3]);
//Reading in the files with if statements deciding whether the information is words or numbers.   
    if(argv[1]  == string("i")) {
        while(in1 >> nums[count]) {
            count++;
            
        }
        while(in2 >> nums2[count2]) {
            count2++;
        }

        for(int i = 0; i < count; i++) {
            
            dupes = false;
            for(int j = 0; j < count2; j++) {
                if(nums[i] == nums2[j]) {
                    
                    for(int k = 0; k < count3; k++) {
                        if(nums[i] == numDupes[k]) {
                            dupes = true;
                        }
                    }
                    if(dupes == false) {
                            numDupes[count3] = nums[i];
                            count3++;
                        }
                }
            }
        }



        MergeSortInt(numDupes, 0, count3 - 1);

        for(int i = 0; i < count3; i++) {
            cout << numDupes[i] << endl;
        }

        
    }
    else if(argv[1] == string("s")) {
        while(in1 >> words[count]) {
            count++;
        }

        while(in2 >> words2[count2]) {
            count2++;
        }
        for(int i = 0; i < count; i++) {
            dupes = false;
            for(int j = 0; j < count2; j++) {
                if(words[i] == words2[j]) {
                    for(int k = 0; k < count3; k++) {
                        if(words[i] == wordDupes[k]) {
                            dupes = true;
                        }
                    }
                    if(dupes == false) {
                            wordDupes[count3] = words[i];
                            //cout<< wordDupes[count3]<< endl;
                            count3++;
                        }    
                }
            }
        }


        MergeSortWords(wordDupes, 0, count3 - 1);

        for(int i = 0; i < count3; i++) {
            cout << wordDupes[i] << endl;
        }

    }
    
    


    return 0;
}