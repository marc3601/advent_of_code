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

char findDuplicate(string lineOne, string lineTwo, string lineThree) {
  vector<char> result;
  for (int i = 0; i < lineOne.length(); i++) {
    if (lineTwo.find(lineOne[i]) != string::npos 
    && lineThree.find(lineOne[i]) != string::npos) {
      result.push_back(lineOne[i]);
    }
  }
  for (int i = 0; i < lineTwo.length(); i++) {
    if (lineOne.find(lineTwo[i]) != string::npos 
    && lineThree.find(lineTwo[i]) != string::npos) {
      result.push_back(lineTwo[i]);
    }
  }
  for (int i = 0; i < lineThree.length(); i++) {
    if (lineOne.find(lineThree[i]) != string::npos 
    && lineTwo.find(lineThree[i]) != string::npos) {
      result.push_back(lineThree[i]);
    }
  }

    return result[2];
    
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

int main(int argc, char** argv) {
    fstream text_file;
    if(argv[1]) {
        text_file.open(argv[1]);
    } else {
        cout << "Program closed with status code 0\n";
        return 0;
    }
    if (text_file.is_open()) {
        string line;
        int index {0};
        vector<string> group;
        vector<vector<string>> groups;
        while (getline(text_file, line))
        {
            index++;
            group.push_back(line);
            if(index == 3) {
                groups.push_back(group);
                group.clear();
                index = 0;
            }
         
        }
        string one,two,three;
        int total{0};
        for (vector<string> group : groups)
        {
            for (size_t i = 0; i < group.size(); i++)
            {
                if (i == 0) one = group[i];
                if (i == 1) two = group[i];
                if (i == 2) three = group[i];
            }
            total += getCharacterPriority(findDuplicate(one, two, three));  
        }

        cout << "Sum of priorities of those item types is: " << total << '.' <<endl;
        
    }
    return 1;
}