#include <iostream>
#include <memory>
class Vehicle {public:virtual ~Vehicle()=default;int maxSpeed;explicit Vehicle(int s):maxSpeed(s){}virtual void honk()const{std::cout<<"General Horn\n";}};
class SportsCar:public Vehicle {public:bool turbo;SportsCar(int s,bool t):Vehicle(s),turbo(t){}void engageTurbo()const{std::cout<<"Turbo Engaged!\n";}};
int main(){std::unique_ptr<Vehicle> p=std::make_unique<SportsCar>(300,true);p->honk();if(auto* car=dynamic_cast<SportsCar*>(p.get()))car->engageTurbo();SportsCar car(250,true);const Vehicle& ref=car;std::cout<<"Speed through base reference: "<<ref.maxSpeed<<'\n';}