#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    map<string, set<string>> synonyms;
    
    for (int i = 0; i < N; ++i){
        string command;
        cin >> command;
        
        if (command == "ADD"){
            string s1, s2;
            cin >> s1 >> s2;
            
            synonyms[s1].insert(s2);
            synonyms[s2].insert(s1);
        }
        else if (command == "COUNT"){
            string word;
            cin >> word;
            
            cout << synonyms[word].size() << endl;
        }
        else{
            string word1, word2;
            cin >> word1 >> word2;
            
            string checker = "NO";
            
            for (auto item : synonyms[min(word1, word2)]){
                if (item == max(word1, word2)){
                    checker = "YES";
                }
            }
            
            cout << checker << endl;
        }
    }
}
