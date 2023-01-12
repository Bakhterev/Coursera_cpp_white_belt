#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word){
    map<char, int> res;
    for (auto letter : word){
        ++res[letter];
    }
    
    return res;
}

void PrintMap(const map<char, int>& mapper){
    for (const auto& item : mapper){
        cout << item.first << " " << item.second << endl;
    }
}

void PrintVector(const vector<string>& words){
    for (const auto& letter : words){
        cout << letter << endl;
    }
}

int main(){
    
    int N;
    cin >> N;
    
    vector<string> result;
    
    for (int i = 0; i < N; ++i){
        string s1, s2;
        
        cin >> s1;
        cin >> s2;
        
        map<char, int> counter_first;
        map<char, int> counter_second;
        
        counter_first = BuildCharCounters(s1);
        counter_second = BuildCharCounters(s2);
        
        if (counter_first == counter_second){
            result.push_back("YES");
        }
        else{
            result.push_back("NO");
        }
    }
    
    PrintVector(result);
    
    return 0;
}

