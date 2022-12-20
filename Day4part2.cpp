#include <iostream>
#include <fstream>
#include <string>
#include <set>
int main()
{
    std::ifstream file;
    file.open("Day4.txt");
    if (file.fail())
    {
        std::cout << "Unable to open the file" << std::endl;
    }
    std::string line;
    std::string str1;
    std::string str2;
    std::string str3;
    std::string str4;
    std::string str5;
    std::string str6;
    int counter2 = 0;
    while (file.good())
    {
        int counter = 0;
        std::set<int> buffer1;
        getline(file, line);
        str1 = line.substr(0, line.find(","));                 // stores the first half of the line before the comma
        str2 = line.substr(line.find(",") + 1, line.length()); // stores the second half of the line after the comma
        str3 = str1.substr(0, str1.find("-"));                 // stores the first number before the - of the first half of the line read
        str4 = str1.substr(str1.find("-") + 1, str1.length()); // stores the second number after the - of the first half of the line read
        str5 = str2.substr(0, str2.find("-"));                 // stores the first number before the - of the second half of the line read
        str6 = str2.substr(str2.find("-") + 1, str2.length()); // stores the second number after the - of the second half of the line read
        int num1 = stoi(str3);
        int num2 = stoi(str4);
        int num3 = stoi(str5); // changes the numbers to integer data type because they were stored as strings
        int num4 = stoi(str6);
        int buffer2[num4 - num3 + 1];
        for (int x = num1; x < num2 + 1; x++)
        {
            buffer1.insert(x); // inserts numbers contained in the first range of the line into a set
        }
        for (int x = num3; x < num4 + 1; x++)
        {
            buffer2[counter] = x; // inserts numbers contained in the second range of the line into an array
            counter++;
        }
        for (int x = 0; x < num4 - num3 + 1; x++)
        {
            if (buffer1.find(buffer2[x]) != buffer1.end()) // checks if any of the numbers in the array appears in the set if it appears it
            {                                              // means that the range of the first range over laps with the second range
                counter2++;                                // counter increases everytime time the condition is met to keep track of how many
                break;                                     // times it occured
            }                                              // we break out cause we only need one number to be found to know the ranges
        }                                                  // overlap
    }
    file.close();
    std::cout << counter2 << std::endl; // prints out the answer
}