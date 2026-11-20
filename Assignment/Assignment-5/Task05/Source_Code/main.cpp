#include <iostream>
#include <stdexcept>
struct Guard{const char*name;explicit Guard(const char*n):name(n){}~Guard(){std::cout<<'~'<<name<<' ';}};
void work(){Guard g("work");throw std::runtime_error("failure");}
int main(){try{Guard g("main");work();}catch(const std::exception&e){std::cout<<"caught "<<e.what();}std::cout<<'\n';}