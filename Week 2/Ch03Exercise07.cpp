#include <iomanip>
#include <iostream>
#include <locale>

int main() {
    double net_balance;
    double payment;
    double d1;
    double d2;
    double monthly_interest_rate;
    double average_daily_balance;
    double interest;

    std::cout << "Please enter the net balance (the balance shown on the bill): $";
    std :: cin >> net_balance;

    std::cout << "Please enter the payment amount: $";
    std :: cin >> payment;

    std::cout << "Please enter the number of days in the billing cycle: ";
    std :: cin >> d1;

    std::cout << "Please enter the number of days that payment is made before the billing cycle: ";
    std :: cin >> d2;

    std::cout << "Finally, please enter the monthly interest rate: %";
    std :: cin >> monthly_interest_rate;
    monthly_interest_rate = monthly_interest_rate / 100.0;

    average_daily_balance = ((net_balance * d1) - (payment * d2)) / d1;
    interest = average_daily_balance * monthly_interest_rate;

    // After much research and attempts, it seems that my system does not
    // have the correct locale setup. Despite trying to change the global locale,
    // moving it away from the automated C locale, and even adjusting os settings,
    // regardless the std::locale().name.c_str() always returns 'C'. From my research,
    // imbuing the cout with locale("") should adjust it to the operating system's
    // defined locale. This is the exact example given in the documentation.
    // https://en.cppreference.com/cpp/locale/locale

    std::cout << std::fixed << std::setprecision(2) << std::showpoint;
    std::cout.imbue(std::locale(""));

    std::cout << "The interest on the unpaid balance is $" << interest << "." << std::endl;

    return 0;
}
