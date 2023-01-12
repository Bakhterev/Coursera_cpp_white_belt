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

void PrintMapBuses(const map<string, vector<string>>& mapper){
    for (const auto& item : mapper){
        cout << "Bus " << item.first << ": ";
        PrintVector(item.second);
        
    }
}

int main(){
    
    int N;
    cin >> N;
    
    map<string, vector<string>> bus_stops;
    vector<string> buses_vec;
    
    for (int i = 0; i < N; ++i){
        string command;
        cin >> command;
        
        if (command == "NEW_BUS"){
            string bus;
            int stop_count;
            
            cin >> bus >> stop_count;
            
            buses_vec.push_back(bus);
            
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
                cout << "No stop" << endl;
            }
            else{
                vector<string> tmp;
                for (const auto& buses : buses_vec){
                    int buses_in_answer = count(answer.begin(), answer.end(), buses);
                    if (buses_in_answer > 0){
                        tmp.push_back(buses);
                    }
                }
                PrintVector(tmp);
            }
        }
        else if (command == "STOPS_FOR_BUS"){
            string bus;
            cin >> bus;
            
            if (bus_stops[bus].size() == 0){
                cout << "No bus" << endl;
                bus_stops.erase(bus);
            }
            else{
                    for(const auto& index : bus_stops[bus]){
                        cout << "Stop " << index << ": ";
                        
                        int other_bus = 0;
                        vector<string> other_stops;
                        for (const auto& item : bus_stops){
                            if (count(item.second.begin(), item.second.end(), index) >= 1){
                                ++other_bus;
                                if (bus != item.first){
                                    other_stops.push_back(item.first);
                                }
                            }
                        }
                        
                        if (other_bus == 1){
                            cout << "no interchange" << endl;
                        }
                        else{
                            
                            //PrintVector(other_stops);
                            vector<string> tmp;
                            for (const auto& buses : buses_vec){
                                int buses_in_stops = count(other_stops.begin(), other_stops.end(), buses);
                                if (buses_in_stops > 0){
                                    tmp.push_back(buses);
                                }
                            }
                            PrintVector(tmp);
                        }
                    }
                }
        }
        else{
            if (bus_stops.size() == 0){
                cout << "No buses" << endl;
            }
            else{
                PrintMapBuses(bus_stops);
            }
        }
    }
    return 0;
}


