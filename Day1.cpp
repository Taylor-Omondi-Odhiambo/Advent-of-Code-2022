#include<iostream>
#include<fstream>
using namespace std;

int numbers[3000];
int main(){
    ifstream file;
    file.open("Day1.txt");
  if(file.fail())
  {
    cout<<"Unable to open file"<<endl;
  }
  string line;
  int num;
  int sum;
  int counter=0;
  while(getline(file,line)){
  if(line!=""){
  num= stoi (line);
  sum+=num;
  numbers[counter]=sum;
  }else{
  sum=0;
  counter++;
  }
  }
  file.close();
  int container;
    for(int x=0; x<3000; x++){
        for(int y=x+1; y<3000; y++){
            if(numbers[x]<numbers[y]){
                container=numbers[y];
                numbers[y]=numbers[x];
                numbers[x]=container;
            }
        }
    }
  for(int x=0; x<10; x++){
    cout<<numbers[x]<<endl;
  }
cout<<"Total of top 3 elves is "<<numbers[0]+numbers[1]+numbers[2];
return 0;
}