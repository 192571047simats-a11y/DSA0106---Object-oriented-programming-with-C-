#include <iostream>
#include <string>
class BusTicket{static int issued;static constexpr int capacity=3;int seat;std::string name;
public:explicit BusTicket(std::string n):seat(issued<capacity?++issued:0),name(std::move(n)){}
static int count(){return issued;}void print()const{std::cout<<name<<": "<<(seat?"Seat "+std::to_string(seat):"Waiting")<<'\n';}};
int BusTicket::issued=0;
int main(){BusTicket t[]={BusTicket("Asha"),BusTicket("Bala"),BusTicket("Chitra"),BusTicket("Dev")};for(auto&x:t)x.print();std::cout<<"Issued: "<<BusTicket::count()<<'\n';}