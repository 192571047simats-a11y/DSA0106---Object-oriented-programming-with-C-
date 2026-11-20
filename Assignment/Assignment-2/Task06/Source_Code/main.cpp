#include <iostream>
class Time{int h,m;public:Time(int hh,int mm):h(hh),m(mm){}
friend int minutesBetween(const Time&a,const Time&b){return std::abs((a.h*60+a.m)-(b.h*60+b.m));}
friend bool earlier(const Time&a,const Time&b){return a.h*60+a.m<b.h*60+b.m;}};
int main(){Time a(9,45),b(13,10);std::cout<<minutesBetween(a,b)<<' '<<std::boolalpha<<earlier(b,a)<<'\n';}