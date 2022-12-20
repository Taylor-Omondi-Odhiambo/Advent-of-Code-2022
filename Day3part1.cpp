#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::ifstream file;
    file.open("Day3.txt");
    if (file.fail())
    {
        std::cout << "Unable to open the file" << std::endl;
    }
    std::string line;
    std::string buffer;
    std::string alfabeti = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; /*a string that we will use to give priority to the
     letters by use of their index values +1*/
    int len;
    int num;
    int sum;
    int flag;
    while (file.good())
    {
        getline(file, line);
        len = line.length();
        flag = 0; // a flag that we will use to set a condition for breaking out of the outer loop of the nested loop
        for (int x = 0; x < len / 2; x++)
        {
            for (int y = len / 2; y < len; y++)
            {
                if (line[x] == line[y])
                {
                    flag = 1;
                    buffer += line[x]; // a loop that compares the first half of the line to the second half finds the common element and
                    break;             // adds it to the string buffer. It then changes the value of flag to 1 and breaks out of the inner
                }                      // loop
            }
            if (flag == 1) // checks that the flag condition has been met and breaks out of the outer loop of the nested loop
            {
                break;
            }
        }
    }
    file.close();
    for (int x = 0; x < buffer.length(); x++)
    {
        for (int y = 0; y < 52; y++)
        {
            if (buffer[x] == alfabeti[y])
            {
                num = y + 1; // compares the characters in the buffer string to the characters in the alfabeti string if a common element is
                sum += num;  // found it is assigned the index value of that letter in the alfabeti string +1. e.g if a is found to be the
            }                // common element a is stored in index 0 in the alfabeti string we add 1 and give a the priority 1 which is then
        }                    // stored in num.
    }
    std::cout << sum << std::endl;
}