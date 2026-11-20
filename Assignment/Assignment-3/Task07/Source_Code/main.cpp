#include <iostream>
class Complex{double re,im;public:Complex(double r=0,double i=0):re(r),im(i){}
Complex operator+(const Complex&o)const{return {re+o.re,im+o.im};}
friend std::ostream& operator<<(std::ostream&o,const Complex&z){return o<<z.re<<(z.im<0?"":"+")<<z.im<<'i';}
bool operator==(const Complex&o)const{return re==o.re&&im==o.im;}};
int main(){Complex a(2,3),b(1,-4);std::cout<<(a+b)<<'\n';}