#include <iomanip>
#include <iostream>
#include <string>
enum class Zone { Inner=1, Middle=2, Outer=3 };
constexpr long long MIN_BALANCE = 5000;
constexpr int PEAK_PERCENT = 20;
long long baseFarePaise(Zone z) {
    switch(z) { case Zone::Inner: return 1000; case Zone::Middle: return 2000; case Zone::Outer: return 3000; }
    return 0;
}
bool isPeak(int h) { return (h>=8 && h<10) || (h>=17 && h<20); }
long long farePaise(Zone z, int hour, int concessionPercent) {
    long long fare=baseFarePaise(z);
    if(isPeak(hour)) fare += fare*PEAK_PERCENT/100;
    fare -= fare*concessionPercent/100;
    return fare;
}
int main() {
    long long balance=10000; int hour=8; Zone zone=Zone::Middle;
    long long fare=farePaise(zone,hour,10);
    if(balance-fare<MIN_BALANCE) { std::cout<<"Journey denied\n"; return 0; }
    balance-=fare;
    std::cout<<"Fare (paise): "<<fare<<"\nBalance (paise): "<<balance<<"\n";
}