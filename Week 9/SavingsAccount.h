//
// Created by harry on 11/2/2026.
//

#ifndef WEEK_9_SAVINGSACCOUNT_H
#define WEEK_9_SAVINGSACCOUNT_H
#include <chrono>
#include <ctime>

#include "BankAccount.h"


class SavingsAccount: public BankAccount {

public:

    // Basic constructor that sets everything to 0.
    SavingsAccount();

    // Allows pre-setting of interest rate and starting balance.
    // Avoids user input.
    explicit SavingsAccount(double input_interest_rate, double input_balance);

    // For DEBUG PURPOSES ONLY.
    // Allows me to test the convenient transactions fee.
    explicit SavingsAccount(double input_interest_rate, double input_balance, int start_counter);

    // Setter function for private interest rate variable.
    void set_interest_rate();

    // Getter function for private interest rate variable.
    [[nodiscard]] double get_interest_rate() const;

    // Add interest to the balance.
    void post_interest();

    // Overloaded withdraw.
    // Has convenient transaction fee functionality.
    void withdraw();
    void print_account_info() const;

private:

    double interest_rate;
    int withdrawal_counter;

    // const values are hard coded in the header file,
    // because they're important values to know when working
    // with the class.
    const int MAX_WITHDRAWALS = 6;
    const double withdrawal_fee = 10.00;

};


#endif //WEEK_9_SAVINGSACCOUNT_H
