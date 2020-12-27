#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0){
            throw invalid_argument("Division by zero.");
        }
        num = numerator/gcd(numerator, denominator);
        denom = denominator/gcd(numerator, denominator);
        
        if (denom <0){
            num = -num;
            denom = -denom;
        }
    }
    
    Rational operator/(const Rational& r) const{
        if (r.num == 0){
            throw domain_error("Division by zero.");
        }
        return Rational {num*r.denom, denom*r.num};
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

private:
    int num;
    int denom;
};

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
