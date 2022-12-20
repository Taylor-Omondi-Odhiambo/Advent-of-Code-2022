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
    std::string line1;
    std::string line2;
    std::string line3;
    std::string buffer;
    std::string alfabeti = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; /*a string that we will use to give priority to the
      letters by use of their index values +1*/
    int counter = 0;
    int flag = 0; // a flag that we will use to set a condition for breaking out of the second loop of the nested loop
    int num;
    int sum;
    while (file.good())
    {
        counter++;        // a variable that we will use to keep track of whether or not line1,2 and 3 have stored lines from the file.
        flag = 0;         // if the counter is 1 it means store the file line in line1 and so on till line3. Once we reach line 3 and store
        if (counter == 1) // the fileline we look through the strings line1,2 and 3 to find the element that appears in all of them
        {
            getline(file, line1);
        }
        else if (counter == 2)
        {
            getline(file, line2);
        }
        else if (counter == 3)
        {
            getline(file, line3);
            for (int x = 0; x < line1.length(); x++)
            {
                for (int y = 0; y < line2.length(); y++)
                {
                    for (int z = 0; z < line3.length(); z++)
                    {
                        if (line1[x] == line2[y] && line2[y] == line3[z])
                        {
                            buffer += line1[x]; // we add the element found in all 3 strings to another string called buffer
                            flag++;             // make the value of flag 1 to set the condition for breaking out of the loop
                            counter = 0;        // reset counter to 0 to restart the process for the next 3 lines in the file
                            line1 = "";
                            line2 = ""; // delete the data stored in the the three strings line1,2 and 3
                            line3 = "";
                            break; // breaks out of the inner loop Note:we break out of the loops to avoid repeating elements
                        }
                    }
                    if (flag == 1) // breaks out of the second inner loop
                    {
                        break; // you would think that i need to set the flag again to break out of the outer loop but for some reason
                    }          // it works just fine even if you don't. Note that if you do duplicate this flag in the outerloop the program
                }              // still functions and thats how I think it should be but no complaints its less lines of code
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