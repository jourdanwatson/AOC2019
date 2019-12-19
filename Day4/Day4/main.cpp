#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> makeVector(const string& integer){
    vector<int> current;
    for(char i : integer){
        int temp= i-'0';
        current.push_back(temp);
    }
    return current;
}
bool checkForDouble(vector<int> current){
    //Check to see if there are 2 equal digits
    for (int i =0; i<10;i++){
        if(count(current.begin(),current.end(),i)==2){
            return true;
        }
    }
    return false;
}
bool adjacentDigits(vector<int> current){
    //Check to see if there are 2 digits that are equal and adjacent
    //Part 1 answer: 1955
    vector<int>::iterator it,it2,it3;
    it = adjacent_find(current.begin(),current.end());
    if(it!=current.end()){
        if(checkForDouble(current)){
            return true;
        }
    }
    return false;


}
bool checkDecrease(vector<int> current){
    //Check to see if the i+1 digit is lower than the previous
    for(auto i=0;i < current.size()-1;i++){
        if(current[i] > current[i+1]){
            return false;
        }
    }
    return true;
}
bool checkNumDigits(const vector<int>& current){
    //Check to see if the number of digits is 6
    return current.size() == 6;
}
int main() {

    vector<int> current;
    int counter=0;

    for(int i = 134792; i < 675811; i++ ){
        current=makeVector(to_string(i));
        if(is_sorted(current.begin(),current.end())){
            if(adjacentDigits(current) && checkDecrease(current) && checkNumDigits(current)){
                counter++;
                current.clear();
            }
        }
    }
    cout<<"Counter: "<<counter<<endl;

    return 0;
}