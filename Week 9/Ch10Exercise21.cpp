#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

static void print_line_break();

int main() {
    print_line_break();

    std::cout << "This main function demonstrates the BankAccount parent class and the two\n"
                 "related subclasses, CheckingAccount and SavingsAccount.\n" << std::endl;

    std::cout << "We'll begin with the BankAccount parent class which has support for\n"
                 "account number generation, balance storage, balance manipulation,\n"
                 "and output of account information.\n" << std::endl;

    std::cout << "Creating test BankAccount object with starting balance $0.00...\n" << std::endl;

    BankAccount test_bank_account;

    std::cout << "Beginning BankAccount object testing..." << std::endl;

    print_line_break();

    test_bank_account.deposit();
    test_bank_account.withdraw();
    test_bank_account.print_account_info();

    print_line_break();

    std::cout << "Next is the CheckingAccount subclass which has support for\n"
                 "account number generation, balance storage, balance manipulation,\n"
                 "output of account information, interest rate features, minimum balance,\n"
                 "service charges, and digital check drafting.\n" << std::endl;

    std::cout << "Creating test CheckingAccount object with starting values at 0.00...\n" << std::endl;

    CheckingAccount test_checking_account;

    std::cout << "Beginning CheckingAccount object testing..." << std::endl;

    print_line_break();

    test_checking_account.set_interest_rate();
    test_checking_account.set_minimum_balance();
    test_checking_account.set_service_charge();
    test_checking_account.deposit();
    test_checking_account.withdraw();
    test_checking_account.write_check();

    std::cout << "Posting interest for the test CheckingAccount..." << std::endl;
    test_checking_account.post_interest();

    if (!test_checking_account.is_greater_than_min()) {
        std::cout << "Because the checking account is currently not above the\n"
                     "minimum balance ($" << test_checking_account.get_minimum_balance() << "), the monthly service charge\n($"
                  << test_checking_account.get_service_charge() << ") would apply." << std::endl;

    }
    else {
        std::cout << "Because the checking account is currently above the\n"
                     "minimum balance ($" << test_checking_account.get_minimum_balance() << "), the monthly service charge\n($"
                  << test_checking_account.get_service_charge() << ") would not apply." << std::endl;
    }

    test_checking_account.print_account_info();

    print_line_break();

    std::cout << "Next is the SavingsAccount subclass which has support for\n"
                 "account number generation, balance storage, balance manipulation,\n"
                 "output of account information, and interest rate features.\n" << std::endl;

    std::cout << "Creating test SavingsAccount object with starting values 0.00...\n" << std::endl;

    SavingsAccount test_savings_account;

    std::cout << "Beginning SavingsAccount object testing..." << std::endl;

    print_line_break();

    test_savings_account.set_interest_rate();
    test_savings_account.deposit();
    test_savings_account.withdraw();

    std::cout << "Posting interest for the test SavingsAccount..." << std::endl;
    test_savings_account.post_interest();
    test_savings_account.print_account_info();

    std::cout << "Creating new SavingsAccount object with max withdrawals exceeded.\n"
                 "View new account details below and test withdrawal functionality.\n" << std::endl;

    SavingsAccount exceeding_savings_account(0.09, 35000, 7);

    exceeding_savings_account.print_account_info();
    exceeding_savings_account.withdraw();
    exceeding_savings_account.print_account_info();

    print_line_break();

    std::cin.ignore(1000, '\n');
    std::cout << "\nPress enter to exit." << std::endl;
    std::cin.get();

    return 0;
}

void print_line_break() {
    std::cout << "\n=====================================================\n" << std::endl;
}