#include <iostream>
#include "BankAccount.h"
#include <random>
#include <algorithm>
#include <iomanip>

static bool has_extra_input();
static void ignore_line();
static void print_divider();

/*
 * CONSTRUCTOR
*/

BankAccount::BankAccount() {
    print_divider();

    set_account_number();
    set_holder_name();
    set_account_type();
    set_balance();
    set_interest_rate();

    print_account_details();

    ignore_line();
}

/*
 * PUBLIC SETTER MEMBER FUNCTIONS
*/

void BankAccount::set_holder_name() {
    std::string input_holder_name;

    std::cout << "Please enter the holder's full name: ";
    std::getline(std::cin, input_holder_name);

    while (!validate_name(input_holder_name)) {
        std::cout << "  ERROR: Only letters and spaces are accepted. Please try again.\n" << std::endl;
        std::cout << "Please enter the holder's full name: ";
        std::getline(std::cin, input_holder_name);
    }

    holder_name = input_holder_name;

    std::cout << "\n";
}

void BankAccount::set_balance() {
    double input_balance;
    std::cout << "Please enter the balance: ";

    while (!(std::cin >> input_balance)) {
        std::cout << "  ERROR: Please enter only numbers (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the balance: ";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << input_balance << std::endl;
    }

    balance = input_balance;

    std::cout << "\n";
}

void BankAccount::set_interest_rate() {
    double input_interest_rate;
    std::cout << "Please enter the interest rate (as a decimal): ";

    while (!(std::cin >> input_interest_rate)) {
        std::cout << "  ERROR: Please enter only valid interest rates (as a decimal).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the interest rate: ";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: " << input_interest_rate << std::endl;
    }

    interest_rate = input_interest_rate;

}

/*
 * PUBLIC GETTER MEMBER FUNCTIONS
*/

int BankAccount::get_account_number() const {
    return account_number;
}

std::string BankAccount::get_holder_name() const {
    return holder_name;
}

std::string BankAccount::get_account_type() const {
    return account_type;
}

double BankAccount::get_balance() const {
    return balance;
}

double BankAccount::get_interest_rate() const {
    return interest_rate;
}

/*
 * PUBLIC OTHER MEMBER FUNCTIONS
*/

void BankAccount::make_deposit() {
    double deposit_amount;
    std::cout << "Please enter the deposit amount: ";

    while (!(std::cin >> deposit_amount) || deposit_amount <= 0) {
        std::cout << "  ERROR: Please enter only positive numbers (including decimals).\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the deposit amount: ";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << deposit_amount << std::endl;
    }

    balance += deposit_amount;

    std::cout << "  Deposit Successful. New Balance: $" << balance << std::endl;

    std::cout << "\n";
}

void BankAccount::make_withdrawal() {
    double withdrawal_amount;
    std::cout << "Please enter the withdrawal amount: ";

    while (!(std::cin >> withdrawal_amount) || withdrawal_amount <= 0 || withdrawal_amount > balance) {
        std::cout << "  ERROR: Please enter only positive numbers (including decimals) that are less than the current balance." << std::endl;
        std::cout << "    (Current Balance: $" << balance << ")\n" << std::endl;
        std::cin.clear();
        ignore_line();
        std::cout << "Please enter the withdrawal amount: ";
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  Discarding additional input. Using first number: $" << withdrawal_amount << std::endl;
    }

    balance -= withdrawal_amount;

    std::cout << "  Withdrawal Successful. New Balance: $" << balance << std::endl;

    std::cout << "\n";
}

void BankAccount::apply_monthly_interest() {
    std::cout << "Applying monthly interest..." << std::endl;

    const double monthly_interest = interest_rate / 12.0;
    balance += (balance * monthly_interest);

    std::cout << "  Monthly Interest Applied. New Balance: $" << balance << std::endl;

    std::cout << "\n";
}

void BankAccount::print_account_details() const {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nACCOUNT DETAILS:" << std::endl;
    std::cout << "  Account Number: " << get_account_number() << std::endl;
    std::cout << "  Holder: " << get_holder_name() << std::endl;
    std::cout << "  Account Type: " << get_account_type() << std::endl;
    std::cout << "  Balance: $" << get_balance() << std::endl;
    std::cout << "  Interest Rate: %" << 100.0 * get_interest_rate() << std::endl;
}

/*
 * PRIVATE MEMBER FUNCTIONS
*/

void BankAccount::set_account_number() {
    std::random_device rnd;
    std::mt19937_64 engine(rnd());

    account_number = std::uniform_int_distribution<int>(1, 100)(engine);
}

void BankAccount::set_account_type() {
    std::string output_account_type;
    std::string input;

    std::cout << "Please select the account type:" << std::endl;
    std::cout << "[1] CHECKING" << std::endl;
    std::cout << "[2] SAVINGS" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, input);

    while (input != "1" && input != "2") {
        std::cout << "  ERROR: Only enter 1 or 2.\n" << std::endl;
        std::cout << "Please select the account type:" << std::endl;
        std::cout << "[1] CHECKING" << std::endl;
        std::cout << "[2] SAVINGS" << std::endl;
        std::cout << "> ";
        std::getline(std::cin, input);
    }

    if (input == "1") {
        output_account_type = "CHECKING";
    }
    else if (input == "2") {
        output_account_type = "SAVINGS";
    }

    // std::cin.ignore(1000, '\n');

    account_type = output_account_type;

    std::cout << "\n";
}

bool BankAccount::validate_name(const std::string &name) {
    const bool is_valid_holder_name = std::ranges::all_of(name, [](const char& c) { return (isalpha(c) || isspace(c)); });
    return is_valid_holder_name;
}

// Checks if there is any remaining input in the stream.
static bool has_extra_input() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

// Compartmentalize lengthy call to ignore maximum streamsize.
static void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prints out a dividing line that cleans up the terminal a bit.
void print_divider() {
    std::cout << "\n=========================================================\n" << std::endl;
}
