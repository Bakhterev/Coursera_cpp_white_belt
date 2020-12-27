
#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString{
    private:
        string ss;
    
    public:
        ReversibleString() {}
        
        ReversibleString(const string& item){
            ss = item;
        }
        
        void Reverse(){
            reverse(ss.begin(), ss.end());
        }
        
        string ToString() const{
            return ss;
        }
};

