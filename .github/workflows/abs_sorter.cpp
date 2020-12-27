
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void PrintVector(const vector<int>& vect){
    for (const auto& item : vect){
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    
    vector<int> init;
    
    for (int i = 0; i < N; ++i){
        int j;
        cin >> j;
        
        init.push_back(j);
    }
    
    sort(begin(init), end(init), [](int x, int y){return abs(x) < abs(y);});
    
    PrintVector(init);

    return 0;
}
