#include <iomanip>
#include <iostream>

/*Option one:
 *  $5,000 on delivery of manuscript, $20,000 when published.
 *Option two:
 *  12.5% of the net price for each copy sold.
 *Option three:
 *  10% of the net price for the first 4,000 copies sold,
 *  and 14% of the net price for copies sold over 4,000.
*/

int main() {

    // Initialize constant variables.
    // constexpr are evaluated at compile time.
    constexpr int option_one_delivery = 5000;
    constexpr int option_one_published = 20000;
    constexpr double option_two_per_copy_percent = 0.125;
    constexpr double option_three_first_four = 0.10;

    // User input variables.
    int num_of_copies;
    double net_price_per;

    // Declared in main() scope because it is set in
    // one of two possible locations.
    double result_option_three;

    // Set global locale for number formatting and set decimal precision to 2 always.
    std::cout << std::fixed << std::setprecision(2) << std::showpoint;
    std::locale::global(std::locale(""));

    std::cout << "Please enter the number of copies to be sold: ";
    std::cin >> num_of_copies;

    std::cout << "Please enter the net price per copy: ";
    std::cin >> net_price_per;

    std::cout << "\n========================================================\n" << std::endl;

    // Calculate and display the result for option one.
    constexpr int result_option_one = option_one_delivery + option_one_published;
    // result_option_one can be a constexpr since the added variables are also evaluated at compilation.
    std::cout << "  Result of option one: $" << result_option_one << std::endl;
    std::cout << "    (Flat rate on manuscript delivery and publishing.)" << std::endl;

    // Calculate and display the result for option two.
    const double result_option_two = (net_price_per * option_two_per_copy_percent) * num_of_copies;
    // result_option_two can be a const because it is unchanging after assignment.
    std::cout << "  Result of option two: $" << result_option_two << std::endl;
    std::cout << "    (12.5% of net price per copy.)" << std::endl;

    // If copies to be sold is less than or equal to 4,000...
    if (num_of_copies <= 4000) {
        result_option_three = (net_price_per * option_three_first_four) * num_of_copies;
        std::cout << "  Result of option three: $" << result_option_three << std::endl;
        std::cout << "    (Input copies less or equal to 4000, so 10% of net price per copy.)" << std::endl;
    }
    // If copies to be sold is greater than 4,000...
    else {
        // Variables declared and assigned in else{} scope so they are deconstructed after }.
        constexpr double option_three_after_four = 0.14;
        const double result_option_three_first_four = (net_price_per * option_three_first_four) * 4000;
        const double result_option_three_after_four = (net_price_per * option_three_after_four) * (num_of_copies - 4000);
        result_option_three = result_option_three_first_four + result_option_three_after_four;

        std::cout << "  Result of option three: $" << result_option_three << std::endl;
        std::cout << "    (Input copies greater than 4000, so 10% of first 4000, then 14% of rest.)" << std::endl;
    }

    std::cout << "\n========================================================\n" << std::endl;

    system("pause");

    return 0;
}
