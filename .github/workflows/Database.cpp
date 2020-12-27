#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

class Date {
public:
    Date(int new_year, int new_month, int new_day){
        if (new_month > 12 || new_month < 1){
            throw logic_error("Month value is invalid: " + to_string(new_month));
        }
        if (new_day < 1 || new_day > 31){
            throw logic_error("Day value is invalid: " + to_string(new_day));
        }
        year = new_year;
        month = new_month;
        day = new_day;
    }
    

    int GetYear() const{
      return year;
    }
  
    int GetMonth() const{
      return month;
    }
  
    int GetDay() const{
      return day;
    }
  
private:
    int day;
    int year;
    int month;
};

ostream& operator<<(ostream& stream, const Date& date){
        stream << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2) << setfill('0') << date.GetMonth() << '-' << setw(2) << setfill('0') << date.GetDay();
        return stream;
}

bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetYear() < rhs.GetYear()){
        return true;
    }
    else if (lhs.GetYear() > rhs.GetYear()){
        return false;
    }
    else{ 
        if (lhs.GetMonth() < rhs.GetMonth()){
            return true;
        }
        else if (lhs.GetMonth() > rhs.GetMonth()){
            return false;
        }
        else{
            if (lhs.GetDay() < rhs.GetDay()){
                return true;
            }
            else {
                return false;
            }
        }
    }
}

class Database {
public:
  void AddEvent(const Date& date, const string& event){
      repository[date].insert(event);
  }
  
  bool DeleteEvent(const Date& date, const string& event){
      if (repository.count(date) > 0 && repository[date].count(event) > 0){
          repository[date].erase(event);
          return true;
      }
      else{
          return false;
      }
  }
  
  int  DeleteDate(const Date& date){
      if (repository.count(date) == 0){
          return 0;
      }
      else{
          const int N = repository[date].size();
          repository.erase(date);
          return N;
      }
  }

  set<string> Find(const Date& date) const{
      if (repository.count(date) > 0){
          return repository.at(date);
      }
      else{
          return {};
      }
  }
  
  void Print() const{
      for (auto& item : repository){
          for (auto & event : item.second){
              cout << item.first << " " << event << endl;
          }
      }
  }

private:
    map<Date, set<string>> repository;
};

Date ParseDate(const string& s){
        istringstream date_stream(s);
        
        int year;
        int month;
        int day;
        
        bool good = true;
        
        good = good && (date_stream >> year);
        good = good && (date_stream.peek() == '-');
        date_stream.ignore(1);
        
        good = good && (date_stream >> month);
        good = good && (date_stream.peek() == '-');
        date_stream.ignore(1);
        
        good = good && (date_stream >> day);
        good = good && (date_stream.eof());
        
        if (!good){
            throw logic_error("Wrong date format: " + s);
        }
        else{
            return Date{year, month, day};
        }
}

int main() {
try{
  Database db;
    
  string command_line;
  while (getline(cin, command_line)) {
    stringstream ss(command_line);
    
    string command;
    ss >> command;
    
    if (command == "Add"){
        string date;
        string event;
        
        ss >> date >> event;
        
        const Date date1 = ParseDate(date);
        db.AddEvent(date1, event);
    }
    else if (command == "Del"){
        string date;
        string event;
        
        ss >> date;
        const Date date1 = ParseDate(date);
        
        if (!ss.eof()){
            ss >> event;
            
            bool good = db.DeleteEvent(date1, event);
            
            if (good){
                cout << "Deleted successfully" << endl;
            }
            else{
                cout << "Event not found" << endl;
            }
        }
        else{
            const int N  = db.DeleteDate(date1);
            cout << "Deleted " << N << " events" << endl;
        }
    }
    else if (command == "Find"){
        string date;
        
        ss >> date;
        const Date date1 = ParseDate(date);
        
        for (const string& event : db.Find(date1)){
            cout << event << endl;
        }
        
    }
    else if (command == "Print"){
        db.Print();
    }
    else if (!command.empty()){
        throw logic_error("Unknown command: " + command);
    }
  }
}
catch(const exception& ex){
    cout << ex.what() << endl;
}
  return 0;
}

