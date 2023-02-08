#include <iostream>
#include <fstream>
#include <map>
#include <string>

int compare(std::string filename)
{
    int overlaps = 0;

    std::string line;
    std::ifstream input(filename);
    

    while(getline(input, line))
    {
        std::string groupA = line.substr(0, line.find(","));
        std::string groupB = line.substr(line.find(",")+1, line.length());
        std::cout<<"group A: "<<groupA<<std::endl<<"groupB: "<<groupB<<std::endl;
    }   
    return 0;
}

int main()
{
    std::cout<<compare("data")<<std::endl;
    return 0;
}