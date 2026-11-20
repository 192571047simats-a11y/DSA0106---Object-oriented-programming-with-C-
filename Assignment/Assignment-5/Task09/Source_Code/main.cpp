#include <iostream>
#include <memory>
#include <vector>
class Bill{public:virtual ~Bill()=default;virtual double total()const=0;virtual const char* type()const=0;};
class OPBill:public Bill{double consult,tests;public:OPBill(double c,double t):consult(c),tests(t){}double total()const override{return consult+tests;}const char*type()const override{return "OP";}};
class IPBill:public Bill{int days;double rate;public:IPBill(int d,double r):days(d),rate(r){}double total()const override{return days*rate;}const char*type()const override{return "IP";}};
int main(){std::vector<std::unique_ptr<Bill>> bills;bills.push_back(std::make_unique<OPBill>(500,250));bills.push_back(std::make_unique<IPBill>(3,1200));double sum=0;for(auto&b:bills){std::cout<<b->type()<<' '<<b->total()<<'\n';sum+=b->total();}std::cout<<"Total "<<sum<<'\n';}