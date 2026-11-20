#include <iostream>
class Base{public:virtual ~Base()=default;virtual void show()const{std::cout<<"Base\n";}};
class Derived:public Base{public:void show()const override{std::cout<<"Derived\n";}};
int main(){Derived d;Base* p=&d;p->show();Derived* q=dynamic_cast<Derived*>(p);if(q)q->show();}