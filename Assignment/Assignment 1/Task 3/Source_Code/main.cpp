#include <climits>
#include <iostream>
#include <type_traits>
int main() {
    long long balancePaise=125000; int journeys=3000000; bool peak=true;
    std::cout<<"sizeof(int)="<<sizeof(int)<<"\nsizeof(long long)="<<sizeof(long long)
             <<"\nINT_MAX="<<INT_MAX<<"\njourneys="<<journeys
             <<"\nbalancePaise="<<balancePaise<<"\npeak="<<std::boolalpha<<peak<<"\n";
}