#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <string>

std::map<int, int> loadData(std::string filePath)
{
    int id = 0;
    int calories = 0;
    std::string data;
    std::map<int, int> elves; 
    std::ifstream input(filePath);
    // Load the data
    while (getline(input, data))
    {
        if(data.empty()) // found a new elves inputs
        {
            elves.insert(std::pair<int, int>(id, calories));
            id++;
            calories = 0;
        }
        else{
        calories += std::stoi(data);
        }
    }
    return elves;
}

void findTop(std::map<int, int>elves, int counter){
    std::cout<<counter<<std::endl;
    auto max = std::max_element(
        elves.begin(),elves.end(),
        [](const std::pair<int,int>& p1, const std::pair<int,int> & p2)
        {
            return p1.second < p2.second;
        });
    std::cout<<max->second<<::std::endl;
    elves.erase(max->first);
    if (counter < 3)
    {
        findTop(elves,++counter);
    } 
    return;
}

int main()
{
    int totalTopThree = 0;
    std::map<int,int> elves = loadData("data");
    findTop(elves, 1);
    return 0;
}