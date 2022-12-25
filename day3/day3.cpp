#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <string>

int compare(std::string a, std::string b, std::map<char, int> priority)
{
    int priorityScore = 0;
        char commonLetter;

        for (int i = 0; i < a.length(); i++)
        {
            for (int j = 0; j < b.length(); j++)
            {
                if (a[i] == b[j])
                {
                    commonLetter = a[i];
                }
            }
        }

        priorityScore += a[commonLetter];
    return priorityScore;

    }



int partA(std::string filepath, std::map<char,int> priority){
    std::string inputLine;
    std::ifstream input (filepath);
    int priorityScore = 0;

    while (getline(input, inputLine))
    {

        // store first half of input line in a string and second half in a string
        // for example if there are 12 characters in the input line, the first half will be 6 characters and the second half will be 6 characters from the next character
        std::string compartmentA = inputLine.substr(0, inputLine.length() / 2);
        std::string compartmentB = inputLine.substr(inputLine.length() / 2, inputLine.length() / 2);
        // find the common letter between the two halfs
        char commonLetter;

        for (int i = 0; i < compartmentA.length(); i++)
        {
            for (int j = 0; j < compartmentB.length(); j++)
            {
                if (compartmentA[i] == compartmentB[j])
                {
                    commonLetter = compartmentA[i];
                }
            }
        }

        priorityScore += priority[commonLetter];
    }

    std::cout << priorityScore;
    return priorityScore;
}

int main()
{
    std::map<char, int> priorities = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}, {'A', 27}, {'B', 28}, {'C', 29}, {'D', 30}, {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34}, {'I', 35}, {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40}, {'O', 41}, {'P', 42}, {'Q', 43}, {'R', 44}, {'S', 45}, {'T', 46}, {'U', 47}, {'V', 48}, {'W', 49}, {'X', 50}, {'Y', 51}, {'Z', 52}};
    int sum = partA("data", priorities);
    std::cout<<sum<<std::endl;
    return 0;
}