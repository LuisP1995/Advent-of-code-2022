#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>

// X A is rock = 1
// Y B is paper = 2
// Z C is scissors = 3
// Loss is 0
// Draw is 3
// Win is 6

int process (std::string problem, int score)
{
    std::string delimiter = " ";
    std::string opponent;
    std::string myChoice;
    size_t pos = 0;
    std::string token;
    while ((pos = problem.find(delimiter)) != std::string::npos)
    {
        token = problem.substr(0, pos);
        opponent = token;
        problem.erase(0, pos+delimiter.length());
    }
    myChoice = problem;
    if (myChoice == "X") // we now lose
    {
        score +=1;
        if (opponent == "A") // draw
        {
            score += 3;
        }
        else if (opponent == "C") // we won
        {
            score+=6;
        }
    }
    else if (myChoice == "Y")
    {
        score += 2;
        if (opponent == "B")
        {
            score +=3;
        }
        else if (opponent == "A")
        {
            score +=6;
        }
    }
    else // assume it's Z
    {
        score += 3;
        if (opponent == "C")
        {
            score += 3;
        }
        else if (opponent == "B")
        {
            score +=6;
        }
    }
    // we have drawn
    // if (myChoice == "X" && opponent == "A"  || myChoice == "Y" && opponent == "B" || myChoice == "Z" && opponent == "C")
    // {
    //     std::cout<<myChoice<<std::endl;
    //     score += 3;
    // }
    // we won 
    // else if (myChoice == "X" && opponent == "C" || myChoice == "Y" && opponent == "A" || myChoice == "Z" && opponent == "B")
    // {
    //     if (myChoice == "X")
    //     {
    //         std::cout<<myChoice<<std::endl;
    //         score += 1;
    //     }
    //     else if (myChoice == "Y")
    //     {
    //         std::cout<<myChoice<<std::endl;

    //         score += 2;
    //     }
    //     else
    //     {
    //         std::cout<<myChoice<<std::endl;

    //         score += 3;
    //     }

    //     score += 6;
    // }
    // // we lost
    // else{
    //     std::cout<<myChoice<<std::endl;
    //     score += 0;
    // }
    
    return score;   
}

int rps (std::string filepath){
    int score = 0;
    std::string data;
    std::ifstream input (filepath);
    while(getline(input,data))
    {
        if (data.empty())
        {
            continue;
        }
        else
        {
            score = process(data, score);
        }
    }
    return score;
} 

int main()
{
    int score = rps("data");
    std::cout<<score<<std::endl;
    return 0;
}