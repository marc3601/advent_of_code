#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    fstream text_file;
    text_file.open("input.txt");
    if (text_file.is_open()) {
        string line;
        int largestNumber {0};
        vector<string> calories;
        vector<int> elf;
        vector<vector<int>> elfs;

        while (getline(text_file, line))
        {
            calories.push_back(line);
        }
   
        for (string str : calories) {
            if (str.empty()) {
                elfs.push_back(elf);
                elf.clear();
            } else {
                elf.push_back(stoi(str));
            }
        }

        vector<int> sortable;
         for (vector<int> i : elfs)
        {
            int value = reduce(i.begin(), i.end());
            sortable.push_back(value);
        } 
        sort(sortable.begin(),sortable.end());

        cout << "Elf carrying the most Calories, carries " << sortable[sortable.size()-1] << " calories.\n";
        cout << "Three top elves carry " << sortable[sortable.size()-1] + sortable[sortable.size()-2] + sortable[sortable.size()-3] << " calories.";
    }
    return 0;
}