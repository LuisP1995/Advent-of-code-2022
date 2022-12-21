#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <string>

std::string compare(std::string a, std::string b, int index)
{
    std::string letter;
    for (int i = 0; i < b.length(); i++)
    {
        if (a.c_str()[index] == b.c_str()[i])
        {
            std::cout<<"found "<<a.c_str()[index]<<std::endl;
            
        }

    }
    if (index != a.length())
    {
        compare(a,b, ++index);
    }
    return "";

}

std::unordered_map<std::string, std::string> parse(std::string filepath){
    int length;
    int id = 1;
    std::string data;
    std::string aCompartment;
    std::string bCompartment;
    std::ifstream input(filepath);
    std::unordered_map<std::string, std::string> rucksacks; 

    // Load the data
    while (getline(input, data))
    {
        length = data.length();
        aCompartment = data.substr(0, length/2);
        bCompartment = data.substr(length/2, length);
        rucksacks.insert(std::pair<std::string, std::string>(aCompartment,bCompartment));
    }
    std::string line;
    std::map<int, std::string> bagPriority;
    std::ifstream priority("priority");
    while (getline(priority, line))
    {
        bagPriority.insert(std::pair<int, std::string>(id,line));
    }
    std::unordered_map<std::string, std::string>::iterator it;
    for (it = rucksacks.begin(); it != rucksacks.end(); it++)
    {
        compare(it->first,it->second, 0);
    }
    return rucksacks;
}

int main()
{
    parse("data");
    return 0;
}