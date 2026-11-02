//
// Created by harry on 11/2/2026.
//

#ifndef WEEK_9_BANKACCOUNT_H
#define WEEK_9_BANKACCOUNT_H


class BankAccount {

// Protected variables are shared with subclasses.
// So account_number and balance need to be exposed to them.

protected:
    int account_number;
    double balance;

    // Simple helper functions that every class uses.
    static bool has_extra_input(); // Checks for additional input after cin.
    static void ignore_line(); // Discards rest of stream.

public:

    // Basic constructor, sets all values to 0.
    BankAccount();

    // Constructor that can explicitly set the starting balance.
    explicit BankAccount(double input_balance);

    // Getter functions to access protected variables.
    [[nodiscard]] int get_account_number() const;
    [[nodiscard]] double get_balance() const;

    // Methods to manipulate balance.
    void deposit();
    void withdraw();

    // Prints out neatly formatted information.
    void print_account_info() const;

private:

    // Generates a randomized account number.
    // Used during instantiation.
    int set_account_number();

};


#endif //WEEK_9_BANKACCOUNT_H
