//
// Created by harry on 11/2/2026.
//

#include "BankAccount.h"

#include <iomanip>
#include <ios>
#include <random>
#include <stdexcept>
#include <iostream>

// Constructors

BankAccount::BankAccount() {
    account_number = set_account_number();
    balance = 0.0;
}

BankAccount::BankAccount(const double input_balance) {
    account_number = set_account_number();
    balance = input_balance;
}

// Public Methods

int BankAccount::get_account_number() const {
    return account_number;
}

double BankAccount::get_balance() const {
    return balance;
}

    // You will see this validation workflow throughout my entire assignment.
    // I began by throwing errors, but I refactored after realizing that that
    // is better suited for catching program bugs as opposed to protecting the
    // user from misinput.

void BankAccount::deposit() {
    double input_amount;
    std::cout << "Enter the amount to be deposited to account #" << account_number << "\n" << "> $";

    while (!(std::cin >> input_amount) || input_amount < 0) {
        std::cout << "  ERROR: Please enter positive number values only (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Enter the amount to be deposited to account #" << account_number << "\n" << "> $";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << input_amount << "\n" << std::endl;
    }

    std::cout << "\n";

    balance += input_amount;
}

void BankAccount::withdraw() {
    double input_amount;
    std::cout << "Enter the amount to withdraw from account #" << account_number << "\n" << "> $";

    while (!(std::cin >> input_amount) || input_amount < 0 || balance < input_amount) {
        std::cout << "  ERROR: Please enter positive number values only (including decimals)\n"
                     "  that are less than or equal to the current balance.\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Enter the amount to withdraw from account #" << account_number << "\n" << "> $";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << input_amount << "\n" << std::endl;
    }

    std::cout << "\n";

    balance -= input_amount;
}

void BankAccount::print_account_info() const {
    constexpr char separator = ' ';
    constexpr int width = 20;

    std::cout << "\n";

    // Found this std::ostringstream logic here: https://stackoverflow.com/questions/78980048/how-to-output-a-character-in-front-of-my-number-with-setw
    // Was very useful because I could not figure out how to keep my dollar signs attached...

    std::ostringstream balance_dollars;
    balance_dollars << "$" << std::fixed << std::setprecision(2) << balance;

    std::cout << std::left << std::setw(width) << std::setfill(separator) << "ACCOUNT NUM:" << account_number << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "BALANCE:" << balance_dollars.str() << std::endl;
}

// Private Methods

int BankAccount::set_account_number() {
    std::random_device rnd;
    std::mt19937_64 engine(rnd());

    account_number = std::uniform_int_distribution<int>(10000, 99999)(engine);

    return account_number;
}

bool BankAccount::has_extra_input() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void BankAccount::ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
