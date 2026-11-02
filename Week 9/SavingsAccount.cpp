//
// Created by harry on 11/2/2026.
//

#include "SavingsAccount.h"

#include <iostream>
#include <stdexcept>


// Constructors

SavingsAccount::SavingsAccount() {
    interest_rate = 0.0;
    withdrawal_counter = 0;
}

SavingsAccount::SavingsAccount(const double input_interest_rate, const double input_balance) {
    interest_rate = input_interest_rate;
    balance = input_balance;
    withdrawal_counter = 0;
}

// DEBUG ONLY
SavingsAccount::SavingsAccount(const double input_interest_rate, const double input_balance, const int start_counter) {
    interest_rate = input_interest_rate;
    balance = input_balance;
    withdrawal_counter = start_counter;
}

// Public Methods

void SavingsAccount::set_interest_rate() {
    double input_interest_rate;
    std::cout << "Please enter the interest rate: " << "\n" << "> ";

    while (!(std::cin >> input_interest_rate) || input_interest_rate < 0.0) {
        std::cout << "  ERROR: Please enter only positive numbers (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the interest rate: " << "\n" << "> ";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: " << input_interest_rate << "\n" << std::endl;
    }

    interest_rate = input_interest_rate;

    std::cout << std::endl;
}

double SavingsAccount::get_interest_rate() const {
    return interest_rate;
}

void SavingsAccount::post_interest() {
    balance += (balance * interest_rate);
}

// For the withdraw function, I really wanted to add functionality that
// tracked the current month and reset the counter if a new month
// had started since it was last called. But I couldn't for the life of me
// find great documentation for std::chrono. It's nothing like working with
// SQL datetimes!

void SavingsAccount::withdraw() {
    double input_amount;
    const bool exceeds_max_withdrawals = (withdrawal_counter > MAX_WITHDRAWALS);

    if (exceeds_max_withdrawals) {
        std::cout << "  WARNING: Convenient transactions exceeded. Withdrawal fee will be applied (" << withdrawal_fee << ").\n" << std::endl;
    }

    std::cout << "Enter the amount to withdraw from account #" << account_number << "\n" << "> $";

    // Scariest while loop condition of all time...
    // There's probably a better way to do this.
    while (!(std::cin >> input_amount) || input_amount < 0.0 || balance < input_amount || (exceeds_max_withdrawals && balance < input_amount + withdrawal_fee)) {
        if (exceeds_max_withdrawals && balance < input_amount + withdrawal_fee) {
            std::cout << "  ERROR: Withdrawal amount plus applied fee exceeds balance.\n"
                         "  Please try again.\n" << std::endl;
        }
        else {
            std::cout << "  ERROR: Please enter positive number values only (including decimals)\n"
                         "  that are less than or equal to the current balance.\n" << std::endl;
        }
        std::cin.clear();
        ignore_line();
        std::cout << "Enter the amount to withdraw from account #" << account_number << "\n" << "> $";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: " << input_amount << "\n" << std::endl;
    }

    if (exceeds_max_withdrawals) {
        balance -= input_amount + withdrawal_fee;
    }
    else {
        balance -= input_amount;
    }

    std::cout << "\n";

    withdrawal_counter++;
}

void SavingsAccount::print_account_info() const {
    constexpr char separator = ' ';
    constexpr int width = 20;

    std::cout << "\n";

    std::ostringstream balance_dollars;
    balance_dollars << "$" << std::fixed << std::setprecision(2) << balance;

    std::ostringstream percentage_interest_rate;
    percentage_interest_rate << "%" << std::fixed << std::setprecision(2) << interest_rate * 100.0;

    std::cout << std::left << std::setw(width) << std::setfill(separator) << "ACCOUNT TYPE:" << "Savings" << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "ACCOUNT NUM:" << account_number << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "BALANCE:" << balance_dollars.str() << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "INTEREST RATE:" << percentage_interest_rate.str() << std::endl;

    std::cout << "\n";
}
