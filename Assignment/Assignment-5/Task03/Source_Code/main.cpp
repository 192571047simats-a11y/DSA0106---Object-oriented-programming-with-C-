#include <iostream>
class Payer{public:virtual ~Payer()=default;virtual double covered(double bill)const=0;};
class SelfPay:public Payer{public:double covered(double b)const override{return 0.0*b;}};
class Insurance:public Payer{double limit;public:explicit Insurance(double l):limit(l){}double covered(double b)const override{return b<limit?b:limit;}};
int main(){Insurance p(1000);std::cout<<p.covered(1500)<<'\n';}