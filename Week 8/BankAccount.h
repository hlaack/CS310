//
// Created by harry on 10/26/2026.
//

#ifndef WEEK_8_BANKACCOUNT_H
#define WEEK_8_BANKACCOUNT_H
#include <string>

class BankAccount {

    public:
        /*
         * The constructor makes calls to all five setter functions
         * in order to perform input validation during execution time.
        */
        BankAccount();

        /*
         * These three public setter functions follow the same pattern:
         * 1. Prompt the user for input.
         * 2. Validate the user's input.
         * 3. Update the variable's value.
        */
        void set_holder_name();
        void set_balance();
        void set_interest_rate();

        /*
         * These two operations gather the desired deposit or withdrawal
         * amount, validate the user's input, and then perform the
         * respective operation, updating the balance and printing out
         * the new balance.
        */
        void make_deposit();
        void make_withdrawal();

        /*
         * This function adds to the balance the (current balance
         * times the (interest rate / 12)), then prints out the
         * new balance.
        */
        void apply_monthly_interest();

        /*
         * Prints out the details of the account object.
        */
        void print_account_details() const;

        /*
         * All of these getter functions simply return the associated
         * values as a means of safely accessing the private variables.
         * [[nodiscard]] warns the user when a returned value is not being used.
        */
        [[nodiscard]] int get_account_number() const;
        [[nodiscard]] std::string get_holder_name() const;
        [[nodiscard]] std::string get_account_type() const;
        [[nodiscard]] double get_balance() const;
        [[nodiscard]] double get_interest_rate() const;

    private:
        int account_number{};
        std::string holder_name;
        std::string account_type;
        double balance{};
        double interest_rate{};

        /*
         * These setter functions are privatized because, after construction,
         * they should never be altered, or it fundamentally ruins the system.
         * Otherwise, they help in constructing the object.
         *
         * set_account_number uses a mersenne_twister_engine to generate a
         * random integer value for the new account object.
        */
        void set_account_number();
        void set_account_type();

        /*
         * This function compartmentalizes predicate-based ranges logic
         * that validates name-type inputs.
        */
        static bool validate_name(const std::string &name);
};

#endif //WEEK_8_BANKACCOUNT_H
