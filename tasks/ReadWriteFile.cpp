#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void ReadWriteAll(const string& path, const string& outpath){
    ifstream input(path);
    
    if (input){
        string line;
        ofstream output(outpath);
        while (getline(input, line)){
            output << line << endl;
        }
    }
}

int main(){
    const string path = "input.txt";
    const string outpath = "output.txt";
    ReadWriteAll(path, outpath);
    
    return 0;
}

