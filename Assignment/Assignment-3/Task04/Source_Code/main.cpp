#include <iomanip>
#include <iostream>
class Money{long long paise;
public:explicit Money(long long p=0):paise(p){}friend Money operator+(Money a,Money b){return Money(a.paise+b.paise);}
Money& operator+=(Money b){paise+=b.paise;return *this;}friend bool operator==(Money a,Money b){return a.paise==b.paise;}
friend std::ostream& operator<<(std::ostream&o,Money m){return o<<"Rs "<<m.paise/100<<'.'<<std::setw(2)<<std::setfill('0')<<m.paise%100;}};
int main(){Money a(75),b(50);std::cout<<(a+b)<<'\n';a+=b;std::cout<<a<<' '<<std::boolalpha<<(a==Money(125))<<'\n';}