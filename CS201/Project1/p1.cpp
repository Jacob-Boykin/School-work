#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main (int argc, char **argv) {
    string words[10001];
    //string wordCountWords[10001];
    string temp;
    string word;
    //string word2;
    string reset = "";
    bool done = false;
    bool n = false;

    ifstream inputFile;
    istringstream iss(word);
    inputFile.open(argv[1]);

    int index = 0;
    int subtract = 0;
    //int index2 = 0;
    while (inputFile >> temp) {
        //if (inputFile.eof()) break;
        n = false;
        word = reset;
        //inputFile >> temp;
        //word2 = reset;
        for (int j = 0; j < temp.length(); j++) {
            temp[j] = tolower(temp[j]);
            if (!isalpha(temp[j])) {
                if (word != reset && word != " ") {
                    n = true;
                    words[index] = word;
                    //wordCountWords[index2] = word2;
                    //cout << words[index] << "/";
                    word = reset;
                    //word2 = reset;
                    index++;
                    //index2++;
                    done = true;
                }
                // else {
                //     wordCountWords[index2] = word2;
                //     word2 = reset;
                //     index2++;
                // }
            }
            else {
                n = true;
                done = false;
                word += temp[j];
                //word2 += temp[j];
            }
        }
        if (done == false && n == true) {
            words[index] = word;
            //wordCountWords[index2] = word2;
            //cout << words[index] << "/";
            word = reset;
            //word2 = reset;
            index++;
            //index2++;
        }
    }
    cout << "The number of words found was " << index << endl;
    inputFile.close();

    int distinctWordsIndex = 0;
    int count = 0;
    //int distinctWordsCounts[10001];
    string distinctWords[10001];
    bool repeat = false;
    for (int i = 0; i < index; i++) {
        repeat = false;
        //count = 1;
        for (int j = 0; j < distinctWordsIndex; j++) {
            if (words[i] == distinctWords[j]) repeat = true;
        }
        if (repeat == false) {
            distinctWords[distinctWordsIndex] = words[i];
            // for (int k = i + 1; k < index; k++) {
            //     if (words[i] == words[k]) count++;
            // }
            // distinctWordsCounts[distinctWordsIndex] = count;
            distinctWordsIndex++;
        }
    }
    cout << "The number of distinct words was " << distinctWordsIndex << endl;

    string input;
    bool diff = false;
    bool appeared = false;
    while (1) {
        appeared = false;
        cout << "Enter a word: " << endl;
        cin >> input;
        count = 0;
        if (input == "STOP") break;
        for (int i = 0; i < distinctWordsIndex; i++) {
            diff = false;
            for (int k = 0; k < distinctWords[i].length(); k++) {
                if (input[k] != '?') {
                    if (input[k] != distinctWords[i][k]) {
                        diff = true;
                    }
                }
            }
            if (diff == false && input.length() == distinctWords[i].length()) {
                appeared = true;
                for (int j = 0; j < index; j++) {
                    //if (distinctWords[i] == wordCountWords[j]) count++;
                    if (distinctWords[i] == words[j]) count++;
                }
                //cout << "The word " << distinctWords[i] << " appears " << distinctWordsCounts[i] << " times" << endl;
                cout << "The word " << distinctWords[i] << " appears " << count << " times" << endl;
                count = 0;
            }
        }
        if (appeared == false) {
            cout << "The word " << input << " appears 0 times" << endl;
        }
    }

    return 0;
}