#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>

// The device will send your subroutine a datastream buffer (your puzzle input);
// your subroutine needs to identify the first position where the four most
// recently received characters were all different.
// Specifically, it needs to report the number of characters from the beginning
// of the buffer to the end of the first such four-character marker.

int check(std::string snippet, int position)
{
     int count;

    int l = snippet.length();
    for (int i = 0; i < l; i++)
    {
        count = 1; // Updates the count again to 1 for every new character

        for (int j = i + 1; j < l; j++)
        {
            if (snippet[i] == snippet[j] && snippet[i] != ' ')
            {
                count++;
                // Set string[j] to 0 to avoid printing the visited character
                snippet[j] = '0';
            }
        }
        // A character is considered as duplicate if count is greater than 1

        if (count > 1 && snippet[i] != '0')
            //std::cout <<"dupe here" <<" "<<snippet[i]<<" "<<position <<std::endl;
            return -1;
    }
    std::cout << snippet << " " <<position<<std::endl;
    return position;
}
const
void process(std::string filename, int bound)
{
    std::string nibble = "";
    int counter = 0;
    std::string stream;
    std::fstream file(filename);
    if (file.is_open())
    {
        file >> stream;
    }
    for (std::string::iterator it = stream.begin(); it != stream.end(); it++)
    {
        nibble.push_back(*it);
        // std::cout<<*it<<" counter: "<<counter<<std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ++counter;
        if (counter % bound == 0)
        {
            //std::cout<<nibble<<" "<<counter<<std::endl;
            if (int i = check(nibble, counter) != -1)
            {
                std::cout<<nibble<<" "<<counter<<std::endl;
                return;
            }
            
        }
    }
}

int main()
{
    process("data", 4);
    process("data", 14);
    return 0;
}