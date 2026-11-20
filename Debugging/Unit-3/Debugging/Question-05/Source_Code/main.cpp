#include <iostream>
class MathVector {
    double x,y;
public:
    MathVector(double a,double b):x(a),y(b){}
    MathVector operator+(const MathVector& r)const{return {x+r.x,y+r.y};}
    bool operator==(const MathVector& r)const{return x==r.x&&y==r.y;}
    double dot(const MathVector& r)const{return x*r.x+y*r.y;}
    void display()const{std::cout<<'('<<x<<", "<<y<<")\n";}
};
int main(){MathVector a(2,3),b(4,5);(a+b).display();std::cout<<std::boolalpha<<(a==b)<<'\n'<<"Dot product: "<<a.dot(b)<<'\n';}