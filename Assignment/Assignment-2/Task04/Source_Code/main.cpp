#include <array>
#include <iostream>
class SavingsAccount{long long balance=0;std::array<long long,10> tx{};int count=0;
public:void deposit(long long p){if(p<=0)return;balance+=p;add(p);}void withdraw(long long p){if(p<=0||p>balance)return;balance-=p;add(-p);}
void add(long long p){if(count<10)tx[count++]=p;else{for(int i=1;i<10;++i)tx[i-1]=tx[i];tx[9]=p;}}
void statement()const{std::cout<<"Balance "<<balance<<"\n";for(int i=0;i<count;++i)std::cout<<tx[i]<<'\n';}};
int main(){SavingsAccount a;a.deposit(10000);a.withdraw(2500);a.deposit(500);a.statement();}