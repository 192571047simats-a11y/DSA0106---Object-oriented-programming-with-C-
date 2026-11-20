#include <iostream>
class Base {public:virtual ~Base()=default;virtual void show()const{std::cout<<"Base display\n";}};
class Derived:public Base {public:int extra=42;void show()const override{std::cout<<"Derived display, extra="<<extra<<'\n';}};
void display(const Base& obj){obj.show();}
int main(){Derived d;display(d);Base* p=&d;p->show();}