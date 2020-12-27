
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void PrintVector(const vector<string>& vect){
    for (const auto& item : vect){
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    
    vector<string> init;
    
    for (int i = 0; i < N; ++i){
        string word;
        cin >> word;
        
        init.push_back(word);
    }
    
    sort(begin(init), end(init), [](string x, string y){
        for (auto& item : x){
            item = tolower(item);
        }
        
        for (auto& item : y){
            item = tolower(item);
        }
        
        return x < y;
    });
    
    PrintVector(init);
    return 0;
}
