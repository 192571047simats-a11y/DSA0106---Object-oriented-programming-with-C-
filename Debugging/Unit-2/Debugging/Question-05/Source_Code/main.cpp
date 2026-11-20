#include <iostream>
class Box {
    int value;
public:
    explicit Box(int v):value(v){}
    friend void showBox(const Box& b);
};
void showBox(const Box& b){std::cout<<"Value: "<<b.value<<'\n';}
int main(){Box b(42);showBox(b);}