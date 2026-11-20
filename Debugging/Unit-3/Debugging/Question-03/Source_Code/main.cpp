#include <iostream>
class Fraction {
    int numerator,denominator;
public:
    Fraction(int n,int d):numerator(n),denominator(d){}
    friend std::ostream& operator<<(std::ostream& os,const Fraction& f){return os<<f.numerator<<'/'<<f.denominator;}
};
int main(){Fraction f(3,4);std::cout<<f<<'\n';}