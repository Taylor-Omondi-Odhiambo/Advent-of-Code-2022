#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

ifstream file;
file.open("Day2.txt");
if(file.fail()){
    cout<<"Unable to open the file"<<endl;
}
string line;//variable that stores a line from the file given.     
char letter[2];
int num=0;
int sum=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
while(getline(file,line)){//Rock=1, Paper=2, Scissors=3, //Win=6, Draw=3 , Loss=0, //X=lose, Y=draw, Z=win
letter[0]=line[0];//stores the first character of the string //A =rock, B =paper, C=scissors for player1
letter[1]=line[2];//stores the third character of the string
if(letter[0]=='A'&&letter[1]=='X'){ 
num=3;
sum+=num;
}
else if(letter[0]=='A'&&letter[1]=='Y'){
num=4;
sum+=num;
}
else if(letter[0]=='A'&&letter[1]=='Z'){
num=8;
sum+=num;
}
else if(letter[0]=='B'&&letter[1]=='X'){
num=1;
sum+=num;
}
else if(letter[0]=='B'&&letter[1]=='Y'){
num=5;
sum+=num;
}
else if(letter[0]=='B'&&letter[1]=='Z'){
num=9;
sum+=num;
}
else if(letter[0]=='C'&&letter[1]=='X'){
num=2;
sum+=num;
}
else if(letter[0]=='C'&&letter[1]=='Y'){
num=6;
sum+=num;
}
else if(letter[0]=='C'&&letter[1]=='Z'){
num=7;
sum+=num;
}
}
file.close();
cout<<sum;
}