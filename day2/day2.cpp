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

int process2(std::string problem, int score)
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
    if (myChoice == "X") // lose
    {
        if (opponent == "A") // rock
        {
            score += 3; // pick 
        }
        else if (opponent == "B") // paper
        {
            score +=1;
        }
        else
        {
            score +=2;
        }
    }
    else if (myChoice == "Y") // draw
    {
        if (opponent == "A") // rock
        {
            score += 4;
        }
        else if (opponent == "B") // paper
        {
            score +=5;
        }
        else
        {
            score += 6;
        }
    }
    else // we win
    {
        if (opponent == "A") // rock
        {
            score += 8;
        }
        else if (opponent == "B") // paper
        {
            score += 9;
        }
        else
        {
            score += 7;
        }
    }
    return score;
}

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
    if (myChoice == "X")
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
    return score;   
}

int rps (std::string filepath){
    int score = 0;
    int trueScore = 0;
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
            trueScore = process2(data, trueScore);
        }
    }
    return trueScore;
} 

int main()
{
    int score = rps("data");
    std::cout<<score<<std::endl;
    return 0;
}