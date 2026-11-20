#include <iostream>
class Person {public:explicit Person(int n):id(n){}int id;};
class Employee:public Person {public:using Person::Person;};
int main(){Employee e(42);Person* p=&e;std::cout<<"Person ID: "<<p->id<<'\n';}