#include <iostream>
#include <string>
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

