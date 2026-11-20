#include <iostream>
#include <string>
double charge(double kg,bool express=false,bool insured=false){return kg*50+(express?40:0)+(insured?25:0);}
int main(){std::cout<<charge(2.0)<<'\n'<<charge(2.0,true)<<'\n'<<charge(2.0,true,true)<<'\n';}