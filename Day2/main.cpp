#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
vector<int> input;
vector<int> testVector;

void ReadInVector(){
    //Read the vector in from a file
    ifstream myReadFile;
    myReadFile.open("C:\\Users\\jourdan.watson\\CLionProjects\\untitled\\cmake-build-debug\\day2.txt");
    string output,token;

    if (myReadFile.is_open()) {
        //cout<<"File is open"<<endl;
        myReadFile >> output;
        stringstream s_stream(output);
        string test_string="1,9,10,3,2,3,11,0,99,30,40,50";
        stringstream test_stream(test_string);

        while (s_stream.good()) {
            getline(s_stream,token,',');
            int tokenInt;
            tokenInt=stoi(token);
            input.push_back(tokenInt);
        }
    }
    else{
        cout<<"File is not open"<<endl;
    }
    myReadFile.close();
}
void Opcode(int start, int pos1, int pos2, int changePos){
    //Perform different operations based on Opcode value then change value in vector
    int returnValue=0;
    switch(start){
        case 1:
            //Case 1: addition
            returnValue=input.at(pos1)+input.at(pos2);
            break;
        case 2:
            //Case 2: Multiplication
            returnValue=input.at(pos1)*input.at(pos2);
            break;
    }
    input.at(changePos)=returnValue;
}
void printVector(vector<int> vectorName){
    //Print the values of the given vector
    cout<<"printing vector"<<endl;
    for(int i=0; i<vectorName.size();i++){
        cout<<vectorName.at(i)<<",";
        if(i%4==0){
            cout<<endl;
        }
    }
}
int runProgram(){
    //Iterate through vector to determine value changes, if it detects opcode 99: return the value found at the beginning of the vector
    //printVector(input);
    int posZero = 0;
    for(int i=0; i<input.size();i++){
        if(input.at(i)==99){
            //Stop program if 99 is found
            posZero=input.at(0);
           break;
        }
        else{
            //Input the values into the Opcode formula
            Opcode(input.at(i),input.at(i+1),input.at(i+2),input.at(i+3));
            i+=3;
        }
    }

    return posZero;
}

int main() {


   for (int noun=0; noun < 100; noun++){

        for(int verb=0; verb < 100; verb++){
            ReadInVector();
            input.at(1)=noun;
            input.at(2)=verb;

           // printVector(input);
            int value=runProgram();


            if(value==19690720){
                cout<<"Values found! "<<endl;
                cout<<"Noun: "<<noun<<endl;
                cout<<"Verb: "<<verb<<endl;
                return 0;
            }
          input.clear();

        }

    }
}