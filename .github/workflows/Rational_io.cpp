#include <iostream>
#include <sstream>
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

/*istream& operator>> (std::istream &in, Rational &r)
{
    string ss;
    in >> ss;
    int N = ss.size();
    int flag = 0;
    int numerator = 0;
    int denominator = 0;
    int sign = 1;
    int numflag = 0;
    int is_full =
    
    if (ss.size() == 0){
        return in;
    }
    
    for (int i = 0; i < N; ++i){ 
        char c = ss[i];
        
        //if (c != '-' && c != '/' && c > '9' && c < '0'){
            //denominator = 0;
            //break;
        //}
        
        if (flag == 0){
            if (c <= '9' && c>='0'){
                numerator *= 10;
                numerator += c - '0';
                ++numflag;
            }
            else if (c == '/' & flag == 0 & numflag != 0){
                ++flag;
            }
            else if(c == '/'& numflag == 0){
                denominator = 0;
                break;
            }
        }
        else if (c == '-' && i == 0){
            sign*= -1;
        }
        else if (flag == 1){
            if (c <= '9' && c>='0'){
                denominator *= 10;
                denominator += c - '0';
            }
        }
    }
    if (denominator == 0){
        r = {0,1};
        
        return in;
    }
    
    else{
        r = {numerator, denominator};
        return in;
    }
}*/


istream& operator >> (istream& in, Rational& r) {
	int a, b;
	char c;

	in >> a >> c >> b;

	if (in && c == '/')
		r = Rational(a, b);

	return (in);
}

/*{
int p, q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = { p, q };
    }
    return stream;
}*/

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
