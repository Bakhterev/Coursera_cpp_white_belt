
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void LinearSolver(double B, double C){
    if (B != 0){
        cout << -C/B;
    }
    /*else if (C = 0){
        cout << "All real line";
    }*/
    else{
        cout << "";
    }
}

void QuadraticSolver(double A, double B, double C){
    double D = B*B - 4*A*C;
    if (D < 0){
        cout << "";
    }
    else if (D == 0){
        cout << -B/(2*A);
    } 
    else {
        cout << (- B + sqrt(D))/(2*A) << " " << (- B - sqrt(D))/(2*A);
    }
}

int main()
{
    double A, B, C;
    cin >> A >> B >> C;
    
    if (A != 0){
        QuadraticSolver(A, B, C);
    }
    else {
        LinearSolver(B, C);
    }
    
    
    return 0;
}
