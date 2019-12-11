#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;



int mass_equation(int fuel){
    fuel/=3;
    fuel=ceil(fuel)-2;
    cout<<"Fuel in mass equation: "<<fuel<<endl;
    if(fuel<0){
        fuel=0;
    }
    return fuel;
}

int calc_fuel(int calculated){
    int total=calculated;
    int temp;
    while(calculated>0){
        cout<<"total: "<<total<<endl;
       temp=mass_equation(calculated);
       total+=temp;
       cout<<"total after addition: "<<total<<endl;
       calculated=temp;
    }

    return total;
}
int main() {
    cout << "This is a test" << endl;

    int total_mass=0;

    ifstream myReadFile;
    myReadFile.open("C:\\Users\\jourdan.watson\\CLionProjects\\AOC2019-1\\day1.txt");
    string output;
    if (myReadFile.is_open()) {
        cout<<"File is open"<<endl;
        while (!myReadFile.eof()) {
            myReadFile >> output;
            int to_int = stoi(output);
            //total_mass+=mass_equation(to_int);
            total_mass+=calc_fuel(mass_equation(to_int));

        }
    }
    else{
        cout<<"File is not open"<<endl;
    }
    myReadFile.close();
    cout<<"Total Mass: "<<total_mass<<endl;

    int temp1,temp2,temp3;
   // temp1=mass_equation(14);
    //temp2=mass_equation(1969);
    //temp3=mass_equation(100756);
    //cout<<"14: "<<calc_fuel(temp1)+temp1<<endl;
    //cout<<"1969: "<<calc_fuel(temp2)<<endl;
   // cout<<"100756: "<<calc_fuel(temp3)<<endl;
    return 0;
}