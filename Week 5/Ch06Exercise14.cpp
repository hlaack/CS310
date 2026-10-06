#include <iomanip>
#include <iostream>

// Static keyword grants internal linkage so that the function can't be used from another file
// it also helps to avoid naming collisions and is generally good practice:
// https://www.learncpp.com/cpp-tutorial/internal-linkage/
static double calc_billing_amount(const double hourly, const int consulting_time, const bool is_low_income) {

    if (is_low_income) {

        // no charges if low income and consulting time <= 30 minutes.
        if (consulting_time <= 30) {
            return 0;
        }

        // 40% of hourly for time over 30 minutes.
        const double over_thirty = consulting_time - 30;
        return (hourly * 0.40) * (over_thirty / 60);

    }

    // Not low income:

    if (consulting_time <= 20) {
        return 0;
    }

    // 70% of hourly for time over 20 minutes.
    const double over_twenty = consulting_time - 20;
    return (hourly * 0.70) * (over_twenty / 60);

}

int main() {

    double hourly;
    bool is_low_income;
    int consulting_time;

    std::cout << "====================================================" << std::endl;

    // Finally introducing some input validation logic.
    // Pattern learned from https://www.w3schools.com/cpp/cpp_input_validation.asp
    std::cout << "Please enter the hourly rate: $";
    while (!(std::cin >> hourly)) {
        std::cout << "!! Please ensure you are entering a number only." << std::endl;
        std::cout << "Please enter the hourly rate: $";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }

    std::cout << "Please enter the total consulting time in minutes: ";
    while (!(std::cin >> consulting_time)) {
        std::cout << "Please enter only whole number values of minutes." << std::endl;
        std::cout << "!! Please enter the total consulting time in minutes: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    // This "solves" the case where a user enters a floating point number.
    // I'm not sure currently how to handle input validation to ensure whether or not
    // a user has entered a whole number into an int object.
    // If this isn't here and the user does enter a floating point number,
    // the input overflows and interferes with getting the income_input.
    std::cin.ignore(100, '\n');

    std::cout << "Does the client fall under low-income (less than or equal to $25,000)?" << std::endl;
    std::cout << "  Please enter yes or no (Y/n): ";
    char income_input = std::cin.get();

    while (income_input != 'Y' && income_input != 'n') {
        std::cout << "!! Unmatched input: please ensure you are entering either 'Y' or 'n'." << std::endl;
        std::cout << "Does the client fall under low-income (less than or equal to $25,000)?" << std::endl;
        std::cout << "  Please enter yes or no (Y/n): ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        income_input = std::cin.get();
    }

    if (income_input == 'Y') {
        is_low_income = true;
    }
    else {
        is_low_income = false;
    }

    const double billing_amount = calc_billing_amount(hourly, consulting_time, is_low_income);

    std::cout << "====================================================" << std::endl;
    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "The amount to bill for this client is $" << billing_amount << "." << std::endl;

    std::cout << "====================================================" << std::endl;

}
