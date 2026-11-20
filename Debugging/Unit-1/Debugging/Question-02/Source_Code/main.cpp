#include <iomanip>
#include <iostream>
double taxRate = 0.18;
int main() {
    const double itemPrice = 1000.0;
    const double subsidizedRate = 0.05;
    const double globalTotal = itemPrice + itemPrice * ::taxRate;
    {
        const int corporateRatePercent = 12;
        const double corporateTotal = itemPrice + itemPrice * corporateRatePercent / 100.0;
        std::cout << "Corporate total: " << corporateTotal << '\n';
    }
    std::cout << "Local Rate: " << subsidizedRate << '\n';
    std::cout << "Global Rate: " << ::taxRate << '\n';
    std::cout << "Final Global Calculation: " << globalTotal << '\n';
}