#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void PrintMapCountries(const map<string, string>& mapper){
    for (const auto& item : mapper){
        cout << item.first << "/" << item.second << " ";
    }
}

int main(){
    
    int N;
    cin >> N;
    
    map<string, string> capitals;
    
    for (int i = 0; i < N; ++i){
        string command;
        
        cin >> command;
        
        if (command == "CHANGE_CAPITAL"){
            string country, capital;
            cin >> country >> capital;
            
            if (capitals[country] == capital){
                cout << "Country " << country << " hasn't changed its capital" << endl;
            }
            else if (capitals[country] == ""){
                cout << "Introduce new country " << country << " with capital " << capital << endl;
                
                capitals[country] = capital;
            }
            else {
                string old_capital;
                old_capital = capitals[country];
                
                cout << "Country " << country << " has changed its capital from ";
                cout << old_capital << " to " << capital << endl;
                
                capitals.erase(country);
                capitals[country] = capital;
            }
        }
        else if (command == "RENAME"){
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            
            if (old_country_name == new_country_name){
                cout << "Incorrect rename, skip" << endl;
            }
            else if (capitals[old_country_name] == ""){
                capitals.erase(old_country_name);
                cout << "Incorrect rename, skip" << endl;
            }
            else if (capitals[new_country_name] != "") {
                cout << "Incorrect rename, skip" << endl;
            }
            else{
                string capital;
                capital = capitals[old_country_name];
            
                capitals.erase(old_country_name);
                capitals[new_country_name] = capital;
                
                cout << "Country " << old_country_name << " with capital " << capital << " ";
                cout << "has been renamed to " << new_country_name << endl;
            }
        }
        else if (command == "ABOUT"){
            string country;
            cin >> country;
            
            if (capitals[country] == ""){
                cout << "Country " << country << " doesn't exist" << endl;
                capitals.erase(country);
            }
            else{
                string capital = capitals[country];
                cout << "Country " << country << " has capital " << capital << endl;
            }
        }
        else{
            if (capitals.size() == 0){
                cout << "There are no countries in the world" << endl;
            }
            else{
                PrintMapCountries(capitals);
                cout << endl;
            }
        }
    }
    
    
    return 0;
}

