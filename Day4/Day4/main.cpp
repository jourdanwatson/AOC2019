#include <iostream>
#include <string>
#include <cstdlib>
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
bool adjacentDigits(vector<int> current){
    //Check to see if there are 2 digits that are equal and adjacent
    vector<int>::iterator it,it2,it3;
    it = adjacent_find(current.begin(),current.end());
    it2=adjacent_find(it,current.end());
    it3=adjacent_find(it2,current.end());
    if(it!=current.end()){
        if(count(current.begin(),current.end(),*it)==2 || count(current.begin(),current.end(),*it2)==2 || count(current.begin(),current.end(),*it3)==2){
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
    return current.size() == 6;
}
int main() {

    vector<int> current;
    int counter=0;
//    string str="112333";
//    current=makeVector(str);
//    cout<<"Check decrease: "<<checkDecrease(current)<<endl;
//    cout<<"adjacent? "<<adjacentDigits(current)<<endl;
//    cout<<"check Nums: "<<checkNumDigits(current)<<endl;


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