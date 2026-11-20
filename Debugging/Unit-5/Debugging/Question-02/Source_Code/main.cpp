#include <iostream>
#include <string>
class BankingException {std::string msg;public:explicit BankingException(std::string m):msg(std::move(m)){}virtual ~BankingException()=default;virtual std::string message()const{return msg;}};
class InsufficientFundsException:public BankingException {double shortfall;public:InsufficientFundsException(std::string m,double s):BankingException(std::move(m)),shortfall(s){}double getShortfall()const{return shortfall;}};
void withdraw(double balance,double amount){if(amount>balance)throw InsufficientFundsException("Account overdrawn!",amount-balance);}
int main(){try{withdraw(500,750);}catch(const InsufficientFundsException& e){std::cout<<"Shortfall of: $"<<e.getShortfall()<<'\n';}catch(const BankingException& e){std::cout<<"General Banking Error: "<<e.message()<<'\n';}catch(...){std::cout<<"Unknown banking error\n";}}