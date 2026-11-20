#include <iostream>
#include <stdexcept>
class Counter{int v;public:explicit Counter(int x=0):v(x){}Counter& operator++(){++v;return *this;}Counter operator++(int){Counter old=*this;++v;return old;}
bool operator<(const Counter&o)const{return v<o.v;}int& operator[](int i){if(i!=0)throw std::out_of_range("index");return v;}int value()const{return v;}};
int main(){Counter c(4);Counter old=c++;++c;c[0]=9;std::cout<<old.value()<<' '<<c.value()<<' '<<std::boolalpha<<(old<c)<<'\n';}