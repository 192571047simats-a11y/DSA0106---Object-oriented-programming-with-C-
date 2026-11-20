#include <chrono>
#include <iostream>
#include <vector>
struct Item{virtual ~Item()=default;virtual int value()const{return 1;}};
struct A:Item{int value()const override{return 2;}};
int main(){std::vector<Item*> v;A a;for(int i=0;i<100000;++i)v.push_back(&a);long long sum=0;auto t=std::chrono::steady_clock::now();for(auto p:v)sum+=p->value();auto us=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-t).count();std::cout<<"items="<<v.size()<<" sum="<<sum<<" elapsed_us="<<us<<'\n';}