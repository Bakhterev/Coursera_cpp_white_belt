#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s){
    bool bool_palindrom = true;
    for (int i = 0; i <= s.size()/2; ++i)
    {
        if (s[i] != s[s.size() - (i + 1)])
        {
            bool_palindrom = false;
            break;
        }
    }
    return bool_palindrom;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> result;
    for (auto w : words){
        if (IsPalindrom(w) && w.size() >= minLength){
            result.push_back(w);
        }
    }
    
    return result;
}

/* int main(){
    vector<string> s1 = {"abacaba", "aba"};
    vector<string> s2 = {"weew", "bro", "code"};
    
    for (auto w : PalindromFilter(s1, 5)){
        cout << w << " ";
    }
    cout << endl;
    for (auto w : PalindromFilter(s1, 2)){
        cout << w << " ";
    }
    cout << endl;
    for (auto w : PalindromFilter(s2, 4)){
        cout << w << " ";
    }
    
    return 0;
    
}
*/