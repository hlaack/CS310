//
// Created by harry on 11/2/2026.
//

#ifndef WEEK_9_CHECKINGACCOUNT_H
#define WEEK_9_CHECKINGACCOUNT_H
#include <string>

#include "BankAccount.h"


class CheckingAccount: public BankAccount {

public:

    // Basic constructor sets all values to 0.
    CheckingAccount();

    // Avoid user input by setting all values
    // at instantiation.
    CheckingAccount(
        double input_interest_rate,
        double input_minimum_balance,
        double input_service_charge,
        double input_balance
    );

    // Setter functions to access private variables.
    void set_interest_rate();
    void set_minimum_balance();
    void set_service_charge();

    // Getter functions to access private variables.
    [[nodiscard]] double get_interest_rate() const;
    [[nodiscard]] double get_minimum_balance() const;
    [[nodiscard]] double get_service_charge() const;

    // Returns whether or not the balance is greater than the min.
    [[nodiscard]] bool is_greater_than_min() const;

    // Add interest to the balance.
    void post_interest();

    // Digital check workflow, takes user input.
    void write_check() const;

    // Overloaded withdraw function.
    // Does not stop user from withdrawing in excess,
    // just adds overdrawn fee.
    void withdraw();

    void print_account_info() const;

    // Static validator function used for the check payee's name.
    static bool validate_name(const std::string &name);

private:

    double interest_rate;
    double minimum_balance;
    double service_charge;

    // const value hard coded within the header file
    // because it is important to know when working
    // with the class.
    const double overdraft_fee = 35.00;

};


#endif //WEEK_9_CHECKINGACCOUNT_H
