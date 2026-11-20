#include <iostream>
#include <string>
class BankAccount {
    std::string accHolder;
    double balance;
    inline static double totalBankReserves = 0.0;
public:
    BankAccount(std::string name, double deposit):accHolder(std::move(name)),balance(deposit){totalBankReserves+=deposit;}
    static void displayAudit(){std::cout<<"Total Reserves in Vault: $"<<totalBankReserves<<'\n';}
    void displayHolder() const {std::cout<<"Account Holder: "<<accHolder<<", Balance: $"<<balance<<'\n';}
};
int main(){BankAccount a("Alice",5000),b("Bob",3000);BankAccount::displayAudit();a.displayHolder();b.displayHolder();}