#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include "BankAccount.h"

int main() {

    // BankAccount bank_account;
    //
    // bank_account.make_deposit();
    // bank_account.make_withdrawal();
    // bank_account.apply_monthly_interest();

    std::cout << "This main function demonstrates how to utilize the BankAccount class.\n" << std::endl;

    std::cout << "The constructor makes calls to multiple member functions to allow for\n"
                 "user input-customized accounts.\n" << std::endl;

    std::cout << "By using these functions within the constructor, the inputs can be validated\n"
                 "during execution which supports, for example, a full program that allows the\n"
                 "user to create new accounts when clicking within a GUI or so forth.\n" << std::endl;

    std::cout << "None of the variables may be modified directly, and instead must be interacted\n"
                 "with via the setter functions to enforce input validation.\n" << std::endl;

    std::cout << "However, the account number and account type setters are privatized, because\n"
                 "those values should never change once established.\n" << std::endl;

    std::cout << "Common operations made upon a bank account are supported, such as deposits,\n"
                 "withdrawals, and monthly interest accrual.\n" << std::endl;

    std::cout << "Next, the program is going to prompt you to enter the information of \n"
                 "10 new customers. Afterwards, it will prompt you to enact some of the\n"
                 "aforementioned operations upon the first customer you entered." << std::endl;

    BankAccount customers[10] {};

    std::cout << "\n" << std::endl;

    customers[0].make_deposit();
    customers[0].make_withdrawal();
    customers[0].apply_monthly_interest();

    customers[0].print_account_details();

    std::cin.ignore(1000, '\n');
    std::cout << "\nPress enter to exit." << std::endl;
    std::cin.get();

    return 0;

}

