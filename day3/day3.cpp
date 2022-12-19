#include <iostream>
#include <fstream>
#include <map>
#include <string>

std::map<std::string, std::string> parse(std::string filepath){
    int length;
    std::string data;
    std::map<std::string, std::string> rucksacks; 
    std::ifstream input(filepath);
    // Load the data
    while (getline(input, data))
    {
        length = data.length();
        std::cout<<length;
    }
    return rucksacks;
}

int main()
{
    parse("data");
    return 0;
}