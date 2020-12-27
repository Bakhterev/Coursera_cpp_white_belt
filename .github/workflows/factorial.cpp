#include <iostream>
#include <vector>
using namespace std;

int Factorial(int a){
    if (a <= 1)
    {
        return 1;
    }
    else
    {
        return a*Factorial(a-1);
    }
}
