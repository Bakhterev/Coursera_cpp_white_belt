#include <iostream>
#include <map>
#include <vector>
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
private:
    map<int, string>  history_name;
    map<int, string>  history_surname;
};