#include <iostream>
#include <map>
#include <set>
#include <vector>
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
    
    bool operator<(const Rational& r) const{
        return (r.denom * num)<(r.num * denom);
    }
    
    friend std::ostream& operator<< (std::ostream &out, const Rational &r);
    friend std::istream& operator>> (std::istream &in, Rational &r);

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

ostream& operator<< (std::ostream &out, const Rational &r)
{
    out << r.num << "/" << r.denom;
 
    return out;
}



istream& operator >> (istream& in, Rational& r) {
	int a, b;
	char c;

	in >> a >> c >> b;

	if (in && c == '/')
		r = Rational(a, b);

	return (in);
}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
