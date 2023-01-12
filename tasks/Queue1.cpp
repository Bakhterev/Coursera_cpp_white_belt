#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> worry_queue;
	
	for (int i = 0; i < n; ++i){
	    //int number;
	    string command;
	    
	    cin >> command;
	    if (command == "WORRY_COUNT"){
	        cout << count(worry_queue.begin(), worry_queue.end(), 1) << endl;
	    }
	    else{
	        int number;
	        cin >> number;
	    
	        if (command == "COME"){
	            int s = worry_queue.size();
	            if (number >= 0){
	                for (int j = 0; j < number; ++j){
	                    worry_queue.push_back(0);
	                }
	            }
	            else {
	                worry_queue.resize(s + number);     
	            }
	        }
	    
	        else if (command == "WORRY"){
	            worry_queue[number] = 1;    
	        }
	    
	        else {
	            worry_queue[number] = 0;
	        }
	   }
	}
	
	return 0;
}


