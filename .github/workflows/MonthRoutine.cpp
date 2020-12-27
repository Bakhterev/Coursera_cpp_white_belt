#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void PrintVectorWithSize(const vector<string>& vect){
    cout << vect.size() << " ";
    for (auto v : vect){
        cout << v << " ";
    }
    cout << endl;
}

int main(){
	int n;
	cin >> n;
	
	vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> tasks(31);
	
	int month_ind = 0;
	for (int i = 0; i < n; ++i){
	    string command;
	    cin >> command;
	    if (command == "NEXT"){
	        ++month_ind;
	        month_ind %= 12;
	        int diff  = days_in_month[month_ind] - days_in_month[month_ind - 1];
	        if (diff > 0){
	            tasks.resize(days_in_month[month_ind]);
	        }
	        else {
	            vector<string> temp;
	            for (int j = days_in_month[month_ind - 1] - 1; j >= days_in_month[month_ind]; --j ){
	                temp.insert(end(temp), begin(tasks[j]), end(tasks[j]));
	            }
	            
	            tasks.resize(days_in_month[month_ind]);
	            tasks[days_in_month[month_ind]-1].insert(end(tasks[days_in_month[month_ind]-1]),
	                                                   begin(temp), end(temp));
	        }
	        
	    }
	    else if (command == "ADD"){
	        string task;
	        int day;
	        cin >> day >> task;
	        
	        tasks[day-1].push_back(task);
	    }
	    else{
	        int day;
	        cin >> day;
	        
	        PrintVectorWithSize(tasks[day-1]);
	    }
	}
	
	return 0;
}


