#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int counter = -2;
    int position = 0;
    
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == 'f'){
            counter++;
            if (counter == 0){
                position = i;
                break;
            }
        }
    }
    
    if (counter >= 0){
        cout << position;
    }
    else{
        cout << counter;
    }
    
    return 0;
}