#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    history_name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    history_surname[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string name = "";
    string surname = "";
    
    for (auto& item : history_name){
        if (item.first <= year){
            name = item.second;
        }
    }
    for (auto& item : history_surname){
        if (item.first <= year){
            surname = item.second;
        }
    }
    
    string result;
    
    if (name == "" & surname == ""){
        result = "Incognito";
    }
    else if (name != "" & surname == ""){
        result = name;
        result += " with unknown last name";
    }
    else if (name == "" & surname != ""){
        result = surname;
        result += " with unknown first name";
    }
    else{
        result = name;
        result += " ";
        result += surname;
    }
    return result;
  }
  
  string GetFullNameWithHistory(int year) {
    if (GetFullName(year) == "Incognito"){
        return "Incognito";
    }
    else{
        vector<string> hist_name;
        vector<string> hist_surname;
        
        for (const auto& item : history_name){
            if (item.first <= year){
                hist_name.push_back(item.second);
            }
        }
        for (const auto& item : history_surname){
            if (item.first <= year){
                hist_surname.push_back(item.second);
            }
        }
        
        hist_name.erase( unique( hist_name.begin(), hist_name.end() ), hist_name.end() );
        hist_surname.erase( unique( hist_surname.begin(), hist_surname.end() ), hist_surname.end() );
        
        string result = "";
        string empt = "";
        if (! hist_name.empty()){
            result += hist_name.back();
            hist_name.pop_back();
            if (! hist_name.empty()){
                result += " (";
                result += hist_name.back();
                hist_name.pop_back();
                for (int i = 0; i < hist_name.size(); ++i){
                        result += ", ";
                        result += hist_name.back();
                        hist_name.pop_back();
                }
                result += ")";
            }
            
        }
        else{
            empt += " with unknown first name";
        }
        
        if (empt.empty()){
            result += " ";
        }
        
        if (! hist_surname.empty()){
            result += hist_surname.back();
            hist_surname.pop_back();
            if (! hist_surname.empty()){
                result += " (";
                result += hist_surname.back();
                hist_surname.pop_back();
                for (int i = 0; i < hist_surname.size(); ++i){
                        result += ", ";
                        result += hist_surname.back();
                        hist_surname.pop_back();
                }
                result += ")";
            }
            
        }
        else{
            empt += "with unknown last name";
        }
        
        if (!empt.empty()){
            result += empt;
        }
        
        
        return result;
    }
  }
private:
    map<int, string>  history_name;
    map<int, string>  history_surname;
};