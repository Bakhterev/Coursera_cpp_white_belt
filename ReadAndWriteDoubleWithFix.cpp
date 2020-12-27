#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadAll(const string& path){
    ifstream input(path);
    
    if (input){
        string line;
        
        while (getline(input, line)){
            cout << fixed << setprecision(3);
            cout << stod(line) << endl;
        }
    }
}

int main(){
    const string path = "input.txt";
    
    ReadAll(path);
}

