#include <iostream>
class NetworkPacket {public:virtual ~NetworkPacket()=default;virtual void serialize()const=0;virtual int getPacketSize()const=0;};
class VideoPacket:public NetworkPacket {int bytes;public:explicit VideoPacket(int n):bytes(n){}void serialize()const override{std::cout<<"Video packet serialized\n";}int getPacketSize()const override{return bytes;}};
int main(){VideoPacket packet(1024);NetworkPacket* p=&packet;p->serialize();std::cout<<"Packet size: "<<p->getPacketSize()<<" bytes\n";}