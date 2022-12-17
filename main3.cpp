#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

#define LOWERCASE_START 97   
#define LOWERCASE_STOP  122
#define UPPERCASE_START 65
#define UPPERCASE_STOP 90
#define PRIORITIES_SIZE 26


struct itemPriority
{
    char item;
    int priority;
};

char getAsciiChar(int asciiValue) {
  return static_cast<char>(asciiValue);
}

char findDuplicate(string lineOne, string lineTwo) {
    unordered_set<char> set;
    vector<char> result;
    for (char c : lineOne)
    {
        set.insert(c);
    }

    for (char c : lineTwo)
    {
        if(set.count(c)) {
            result.push_back(c);
        }
    }
    return result[0];
    
}

int getCharacterPriority(char character) {
    int priority = 1;
    itemPriority prioritiesU[PRIORITIES_SIZE];
    itemPriority prioritiesL[PRIORITIES_SIZE];
    int index {0};
    for (size_t i = LOWERCASE_START; i <= LOWERCASE_STOP; i++)
    {
        itemPriority itemU = {getAsciiChar(i), priority};
        prioritiesL[index] = itemU;
        priority+=1;
        index+=1;   
    }
    index = 0;
    for (size_t i = UPPERCASE_START; i <= UPPERCASE_STOP; i++)
    {
        itemPriority itemL = {getAsciiChar(i), priority};
        prioritiesU[index] = itemL;
        priority+=1;
        index+=1;
    }
    size_t arrayLength = sizeof(prioritiesU)/sizeof(itemPriority);

    for (size_t i = 0; i < arrayLength; i++)
    {
        if (prioritiesL[i].item == character) {
            return prioritiesL[i].priority;
        } else if(prioritiesU[i].item == character) {
            return prioritiesU[i].priority;
        }
    }
    
    return ' ';
}

int main() {
    fstream text_file;
    text_file.open("input3.txt");
    if (text_file.is_open()) {
        string line;
        int sum {0};
        while (getline(text_file, line))
        {
            string partOne = line.substr(0, (line.size())/2);
            string partTwo = line.substr((line.size())/2, (line.size()));
            sum += getCharacterPriority(findDuplicate(partOne, partTwo));
        }
        cout << "Sum of priorities is " << sum;
    }
    return 0;
}