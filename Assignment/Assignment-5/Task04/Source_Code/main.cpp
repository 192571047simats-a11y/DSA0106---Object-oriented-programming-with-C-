#include <iostream>
#include <stdexcept>
class BillingError:public std::runtime_error{public:using std::runtime_error::runtime_error;};
double calculate(double charge){if(charge<0)throw BillingError("negative charge");return charge*1.0;}
int main(){try{std::cout<<calculate(250)<<'\n';std::cout<<calculate(-5)<<'\n';}catch(const BillingError&e){std::cout<<"Billing error: "<<e.what()<<'\n';}}