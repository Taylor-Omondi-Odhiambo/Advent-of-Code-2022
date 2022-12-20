#include <iostream>
#include <fstream>
#include <string>
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
    int counter = 0;
    while (file.good())
    {
        getline(file, line);
        str1 = line.substr(0, line.find(","));                 // stores the first half of the line before the comma
        str2 = line.substr(line.find(",") + 1, line.length()); // stores the second half of the line after the comma
        str3 = str1.substr(0, str1.find("-"));                 // stores the first number before the - of the first half of the line read
        str4 = str1.substr(str1.find("-") + 1, str1.length()); // stores the second number after the - of the first half of the line read
        str5 = str2.substr(0, str2.find("-"));                 // stores the first number before the - of the second half of the line read
        str6 = str2.substr(str2.find("-") + 1, str2.length()); // stores the second number after the - of the second half of the line read
        int num1 = stoi(str3);
        int num2 = stoi(str4); // changes the numbers to integer data type because they were stored as strings
        int num3 = stoi(str5);
        int num4 = stoi(str6);
        if (num1 <= num3 && num2 >= num4 || num3 <= num1 && num4 >= num2) // some logic to detect whether a range in the pair of ranges
        {
            counter++; // fully contains the other range e.g 2-4, 2-7 the range 2-4 is fully contained inside 2-7
        }              // counter increases if the condition has been met to find out how many times it has been met
    }
    file.close();
    std::cout << counter << std::endl; // print the answer
}