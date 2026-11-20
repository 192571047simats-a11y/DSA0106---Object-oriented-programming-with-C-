#include <iostream>
#include <string>
class Device {protected:std::string mac;public:explicit Device(std::string m):mac(std::move(m)){std::cout<<"Device configured with MAC: "<<mac<<'\n';}};
class Sensor:public Device {int rate;public:Sensor(std::string m,int r):Device(std::move(m)),rate(r){}void display()const{std::cout<<"MAC: "<<mac<<", Rate: "<<rate<<" Hz\n";}};
int main(){Sensor s("00:1A:2B:3C:4D:5E",100);s.display();}