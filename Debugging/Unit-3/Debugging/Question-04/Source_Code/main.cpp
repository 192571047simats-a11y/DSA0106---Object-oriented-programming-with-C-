#include <iostream>
class StepCounter {
    int steps;
public:
    explicit StepCounter(int s=0):steps(s){}
    StepCounter& operator++(){++steps;return *this;}
    StepCounter operator++(int){StepCounter old=*this;++steps;return old;}
    void display(const char* label)const{std::cout<<label<<steps<<'\n';}
};
int main(){StepCounter c(10);StepCounter prefix=++c;prefix.display("Prefix result: ");c.display("Current: ");StepCounter old=c++;old.display("Postfix old value: ");c.display("After postfix: ");}