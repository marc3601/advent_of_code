#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int roundTotalScore(string line) {
    int toralScore {0};
    char opponent = line[0];
    char me = line[2];

    switch (me)
    {
    case 'X':
        toralScore = 1;
        if (opponent == 'A') toralScore += 3;
        if (opponent == 'B') toralScore += 0;
        if (opponent == 'C') toralScore += 6;
        return toralScore;
        break;
    case 'Y':
        toralScore = 2;
        if (opponent == 'A') toralScore += 6;
        if (opponent == 'B') toralScore += 3;
        if (opponent == 'C') toralScore += 0;
        return toralScore;
        break;
    case 'Z':
        toralScore = 3;
        if (opponent == 'A') toralScore += 0;
        if (opponent == 'B') toralScore += 6;
        if (opponent == 'C') toralScore += 3;
        return toralScore;
        break;
    default:
        return 0;
        break;
    }
    
}

int main() {
    fstream text_file;
    text_file.open("input2.txt");
    if (text_file.is_open()) {
        string line;
        int totalGameScore = 0;
        while (getline(text_file, line))
        {
           totalGameScore += roundTotalScore(line);
        } 
        cout << "If played according to strategy, total score would be: " << totalGameScore << "." << endl;
    }
    return 0;
}