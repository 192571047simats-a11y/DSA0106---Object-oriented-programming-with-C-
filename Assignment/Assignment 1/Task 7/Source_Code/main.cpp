#include <iostream>
#include <memory>
#include <vector>
class Staff{protected:double basic;public:explicit Staff(double b):basic(b){}virtual ~Staff()=default;virtual double pay()const=0;};
class Professor:public Staff{double research;public:Professor(double b,double r):Staff(b),research(r){}double pay()const override{return basic*1.42+research;}};
class LabAssistant:public Staff{public:using Staff::Staff;double pay()const override{return basic*1.42;}};
int main(){std::vector<std::unique_ptr<Staff>> s;s.push_back(std::make_unique<Professor>(50000,5000));s.push_back(std::make_unique<LabAssistant>(30000));for(auto&x:s)std::cout<<x->pay()<<'\n';}