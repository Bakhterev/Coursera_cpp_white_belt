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
        num = numerator/gcd(numerator, denominator);
        denom = denominator/gcd(numerator, denominator);
        
        if (denom <0){
            num = -num;
            denom = -denom;
        }
    }
    
    Rational operator+(const Rational& r){
        return Rational {r.num*denom + num*r.denom, r.denom * denom};
    }
    
    Rational operator-(const Rational& r){
        return Rational {- r.num*denom + num*r.denom, r.denom * denom};
    }
    
    Rational operator*(const Rational& r) const{
        return Rational {r.num*num, r.denom * denom};
    }
    
    Rational operator/(const Rational& r) const{
        return Rational {num*r.denom, denom*r.num};
    }
    
    bool operator==(const Rational& r) const{
        return (r.num == num)&&(r.denom == denom);
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
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
