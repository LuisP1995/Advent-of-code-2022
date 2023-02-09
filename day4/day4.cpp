#include <iostream>
#include <fstream>
#include <map>
#include <string>

std::pair<int,int>split(std::string values)
{
    std::string delimiter = "-";
    std::string token;
    std::pair<int,int> bounds;
    size_t pos = 0;
    while ((pos = values.find(delimiter)) != std::string::npos)
    {
        token = values.substr(0, pos);
        bounds.first = std::stoi(token);
        values.erase(0, pos+delimiter.length());
    }
    bounds.second = std::stoi(values);
    return bounds;
}

int compare(std::string filename)
{
    int overlaps = 0;
    std::string line;
    std::ifstream input(filename);

    while(getline(input, line))
    {
        bool contained = false;
        std::string groupA = line.substr(0, line.find(","));
        std::pair<int,int> pairA = split(groupA);
        std::string groupB = line.substr(line.find(",")+1, line.length());
        std::pair<int,int> pairB = split(groupB);
        //std::cout<<"group A: "<<groupA<<std::endl<<"groupB: "<<groupB<<std::endl;
        if((pairA.first >= pairB.first && pairA.second <= pairB.second) || 
            (pairB.first >= pairA.first && pairB.second <= pairA.second))
        {
            std::cout<<pairA.first<<"\t"<<pairA.second<<std::endl;
            std::cout<<pairB.first<<"\t"<<pairB.second<<std::endl;
            overlaps++;
        }


    }
    return overlaps;
}

int main()
{
    std::cout<<compare("subset")<<std::endl;
    return 0;
}