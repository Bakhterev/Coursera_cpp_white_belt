#include <iostream>
#include <vector>
using namespace std;

vector <int> decimal_to_binary(int a){
    int quotient = a;
    vector <int> binary;
    while (quotient > 0)
    {
        binary.push_back(quotient % 2);
        quotient /= 2; 
    }
    return binary;
}

int main()
{
    int a;
    cin >> a;
    
    vector <int> bin_vec = decimal_to_binary(a);
    
    for (int i = bin_vec.size() - 1; i >= 0; --i){
        cout << bin_vec[i];
    }
    
    return 0;
}