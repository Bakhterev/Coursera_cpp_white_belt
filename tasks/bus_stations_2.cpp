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
    
    map<vector<string>, int> bus_paths;
    int counter = 1;
    
    
    for (int i = 0; i < N; ++i){
        int n;
        cin >> n;
        
        vector<string> stops;
        
        for (int j = 0; j < n; ++j){
            string stop;
            
            cin >> stop;
            stops.push_back(stop);
        }
        
        if (bus_paths[stops] == 0){
            bus_paths[stops] = counter;
            cout << "New bus " << counter << endl;
            
            ++counter;
        }
        else{
            cout << "Already exists for " << bus_paths[stops] << endl;
        }
        
    }
    
    
    return 0;
}


