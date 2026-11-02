//
// Created by harry on 11/2/2026.
//

#include "CheckingAccount.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>


// Constructors

CheckingAccount::CheckingAccount() {
    interest_rate = 0.0;
    minimum_balance = 0.0;
    service_charge = 0.0;
}

CheckingAccount::CheckingAccount(
    const double input_interest_rate,
    const double input_minimum_balance,
    const double input_service_charge,
    const double input_balance
) {
    interest_rate = input_interest_rate;
    minimum_balance = input_minimum_balance;
    service_charge = input_service_charge;
    balance = input_balance;
}

// Public Methods

void CheckingAccount::set_interest_rate() {
    double input_interest_rate;
    std::cout << "Please enter the interest rate (as a decimal): " << "\n" << "> ";

    while (!(std::cin >> input_interest_rate) || input_interest_rate < 0.0) {
        std::cout << "  ERROR: Please enter only positive numbers (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the interest rate (as a decimal): " << "\n" << "> ";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: " << input_interest_rate << "\n" <<std::endl;
    }

    interest_rate = input_interest_rate;

    std::cout << std::endl;
}

void CheckingAccount::set_minimum_balance() {
    double input_minimum_balance;
    std::cout << "Please enter the minimum balance: " << "\n" << "> $";

    while (!(std::cin >> input_minimum_balance) || input_minimum_balance < 0.0) {
        std::cout << "  ERROR: Please enter only positive numbers (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the minimum balance: " << "\n" << "> $";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << input_minimum_balance << "\n" << std::endl;
    }

    minimum_balance = input_minimum_balance;

    std::cout << std::endl;
}

void CheckingAccount::set_service_charge() {
    double input_service_charge;
    std::cout << "Please enter the service charge amount: " << "\n" << "> $";

    while (!(std::cin >> input_service_charge) || input_service_charge < 0.0) {
        std::cout << "  ERROR: Please enter only positive numbers (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the service charge amount: " << "\n" << "> $";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << input_service_charge << "\n" << std::endl;
    }

    service_charge = input_service_charge;

    std::cout << std::endl;
}

double CheckingAccount::get_interest_rate() const {
    return interest_rate;
}

double CheckingAccount::get_minimum_balance() const {
    return minimum_balance;
}

double CheckingAccount::get_service_charge() const {
    return service_charge;
}

void CheckingAccount::post_interest() {
    balance += (balance * interest_rate);
}

bool CheckingAccount::is_greater_than_min() const {
    return (balance >= minimum_balance);
}

// For the check writing portion of the CheckingAccount assignment,
// I was not sure how far or to what extent you wanted the implementation,
// so I went with what was feasible solely within the class.

void CheckingAccount::write_check() const {
    std::cout << "Writing check from Account #" << account_number << std::endl;

    std::string payee_name;
    double check_amount;
    std::string memo;

    ignore_line();

    std::cout << "  Enter the full name of the payee: ";
    std::getline(std::cin, payee_name);

    while (!validate_name(payee_name)) {
        std::cout << "    ERROR: Not a valid name. Only letters and spaces are accepted. Please try again.\n" << std::endl;
        std::cout << "  Enter the full name of the payee: ";
        std::getline(std::cin, payee_name);
    }

    std::cout << "  Enter the amount: $";
    while (!(std::cin >> check_amount)) {
        std::cout << "    ERROR: Please enter only numbers (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Enter the amount: $";
    }

    // if (!std::cin.eof() && std::cin.peek() != '\n') {
    if (has_extra_input()) {
        std::cout << "    Discarding additional input. Using first number: $" << check_amount << "\n" << std::endl;
    }

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ignore_line();

    std::cout << "  Enter a memo: ";
    std::getline(std::cin, memo);

    std::cout << "\n";

    std::cout << "Digital check created:" << std::endl;
    std::cout << "  Pay to the Order of " << payee_name << "." << std::endl;
    std::cout << "  Amount: $" << check_amount << std::endl;
    std::cout << "  Memo: " << memo << std::endl;

    std::cout << "\n";

    // This function doesn't actually charge the account, because
    // usually checks don't withdraw the full amount until they are cashed.

}

void CheckingAccount::withdraw() {
    // balance -= amount;

    double input_amount;
    std::cout << "Enter the amount to withdraw from account #" << account_number << "\n" << "> $";

    while (!(std::cin >> input_amount) || input_amount < 0) {
        std::cout << "  ERROR: Please enter positive number values only (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Enter the amount to withdraw from account #" << account_number << "\n" << "> $";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << input_amount << "\n" << std::endl;
    }

    balance -= input_amount;

    if (balance < 0.0) {
        balance -= overdraft_fee;
        std::cout << "  Overdraft Fee applied to transaction." << std::endl;
    }

    std::cout << "\n";
}

void CheckingAccount::print_account_info() const {
    constexpr char separator = ' ';
    constexpr int width = 20;

    std::cout << "\n";

    std::ostringstream balance_dollars;
    balance_dollars << "$" << std::fixed << std::setprecision(2) << balance;

    std::ostringstream percentage_interest_rate;
    percentage_interest_rate << "%" << std::fixed << std::setprecision(2) << interest_rate * 100.0;

    std::ostringstream min_balance_dollars;
    min_balance_dollars << "$" << std::fixed << std::setprecision(2) << minimum_balance;

    std::ostringstream service_charge_dollars;
    service_charge_dollars << "$" << std::fixed << std::setprecision(2) << service_charge;

    std::cout << std::left << std::setw(width) << std::setfill(separator) << "ACCOUNT TYPE:" << "Checking" << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "ACCOUNT NUM:" << account_number << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "BALANCE:" << balance_dollars.str() << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "INTEREST RATE:" << percentage_interest_rate.str() << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "MIN. BALANCE:" << min_balance_dollars.str() << std::endl;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "SERVICE CHARGE:" << service_charge_dollars.str() << std::endl;
}

// The validate_name function is only used within this class and
// only ever used within the check writing function.

bool CheckingAccount::validate_name(const std::string &name) {
    const bool is_valid_holder_name = std::ranges::all_of(name, [](const char& c) { return (isalpha(c) || isspace(c)); });
    return is_valid_holder_name;
}