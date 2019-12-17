#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

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
    vector<int>::iterator it,it2;

    for(auto i = 0; i < current.size(); i++){

        int counter = std::count(current.begin(),current.end(), i);
        int value=i;
        if(counter==2){
            it = find(current.begin(),current.end(),value);
            it2 = find(it+1,current.end(),value);
            int pos1=distance(current.begin(),it);
            int pos2=distance(current.begin(),it2);

            int difference = pos1-pos2;
            if (abs(difference)==1){
                return true;
            }
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
//    string str="123789";
//    current=makeVector(str);


    for(int i = 134792; i < 675811; i++ ){
        current=makeVector(to_string(i));
        if(adjacentDigits(current)){
            if(checkDecrease(current)){
                if(checkNumDigits(current)){
                    counter++;
                }
            }
        }
        current.clear();
    }
    cout<<"Counter: "<<counter<<endl;
    return 0;
}