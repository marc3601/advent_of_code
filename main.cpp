#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
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

        for (vector<int> i : elfs)
        {
            int sum = reduce(i.begin(), i.end());
            if (largestNumber < sum) {
                largestNumber = sum;
            }
        } 

        cout << "Elf carrying the most Calories, carries " << largestNumber << " calories.";
  
    }
    return 0;
}