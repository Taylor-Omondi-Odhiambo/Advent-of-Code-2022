#include<iostream>
#include<fstream>
using namespace std;

int numbers[3000];//Array that will store the total calories of one elf in each index
int main(){
    ifstream file;
    file.open("Day1.txt");
  if(file.fail())//if file doesn't open display the message below
  {
    cout<<"Unable to open file"<<endl;
  }
  string line;//string used to store the value read in a line of the text file
  int num;//string used to store the values read from the file after they have been typecasted to integers from the above variable
  int sum;//used to compute the calories an elf carries
  int counter=0;
  while(getline(file,line)){//basically means that as long as a lines are still avalilabe to read from the file keep iterating
  if(line!=""){//if the line read in the file is empty execute the code below
  num= stoi (line);//convert the strings read from the file into integers
  sum+=num;//add the calories of an elf
  numbers[counter]=sum;//store the values calculated above in an index
  }else{//if a line read from a file is empty reset sum to 0 and move to the next index
  sum=0;
  counter++;
  }
  }
  file.close();
  int container;//Bubble sort to arrange the total calories per elf from largest to smallest 
    for(int x=0; x<3000; x++){
        for(int y=x+1; y<3000; y++){
            if(numbers[x]<numbers[y]){
                container=numbers[y];
                numbers[y]=numbers[x];
                numbers[x]=container;
            }
        }
    }
  for(int x=0; x<10; x++){//print out the total calories of the elves carrying the highest calories
    cout<<numbers[x]<<endl;
  }
cout<<"Total of top 3 elves is "<<numbers[0]+numbers[1]+numbers[2];// Add and displat the total calories carried by the top 3 elves
return 0;
}