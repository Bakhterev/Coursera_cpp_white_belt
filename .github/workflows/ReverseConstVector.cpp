#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v)
{
    vector<int> tmp = v;
    for (int i = 0; i < v.size(); ++i){
        v[i] = tmp[tmp.size() - i - 1];
    }
}

vector<int> Reversed(const vector<int>& v){
    vector<int> tmp = v;
    Reverse(tmp);
    return tmp;
}

/*int main(){
    vector<int> v = {1, 2, 4, 5, 10};
    Reverse(v);
    for (auto i : v){
        cout << i << " ";
    }
    return 0;
}*/
