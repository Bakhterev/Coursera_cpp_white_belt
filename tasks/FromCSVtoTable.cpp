#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void ReadTable(const string& path){
    ifstream input(path);
    
    if (input){
        int N, M;
        
        input >> N;
        input.ignore(1);
        
        input >> M;
        input.ignore(1);
        
        for (int i = 0; i < N; ++i){
            
            string line;
            getline(input, line);
            
            for (int j = 0; j < M; ++j){
                
                if (line[0] == ','){
                    line.erase(line.begin());
                }
                
                if (line[0] != ','){
                    string number;
                    while(line[0] != ',' & line.size() != 0){
                        number.push_back(line[0]);
                        line.erase(line.begin());
                    }
                    //int n = stoi(number);
                    if (!line.empty()){
                        cout << setw(10) << number << ' ';
                    }
                    else{
                        cout << setw(10) << number;
                    }
                }
                
            }
            cout << endl;
        }
    }

}

int main()
{
    const string path = "input.txt";
    
    ReadTable(path);
    return 0;
}
