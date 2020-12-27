#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void PrintVector(const vector<string>& vect){
    for (const auto& index : vect){
        cout << index << " ";
    }
    cout << endl;
}

int main(){
    
    int N;
    cin >> N;
    
    map<string, vector<string>> bus_stops;
    
    for (int i = 0; i < N; ++i){
        string command;
        cin >> command;
        
        if (command == "NEW_BUS"){
            string bus;
            int stop_count;
            
            cin >> bus >> stop_count;
            
            for (int j = 0; j < stop_count; ++j){
                string bus_stop;
                cin >> bus_stop;
                
                bus_stops[bus].push_back(bus_stop);
            }
        }
        
        else if (command == "BUSES_FOR_STOP"){
            string stop;
            cin >> stop;
            
            vector<string> answer;
            int counter = 0;
            
            for (const auto& item : bus_stops){
                counter = count(item.second.begin(), item.second.end(), stop);
                
                if (counter >= 1){
                    answer.push_back(item.first);
                }
            }
            
            if (answer.size() == 0){
                cout << "No stop";
            }
            else{
                PrintVector(answer);
            }
        }
        else if (command == "STOPS_FOR_BUS"){
            
        }
    }
    return 0;
}

