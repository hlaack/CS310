#include <functional>
#include <iostream>
#include <random>
#include <vector>
#include "custom_exceptions.h"
#include <algorithm>

static std::array<int, 25> generate_real_numbers();
static std::array<int, 5> handle_prompts();
static void print_divider();
static void validate_set_prompt_input(std::array<int, 5> &prompt_choices, int index);
static void print_generated_numbers(const std::array<int, 25> &numbers);
static void ignore_input();
static bool has_extra_input();

int main() {
    // Generate random numbers and prompt the user to select which exceptions to use.
    const std::array<int, 25> numbers = generate_real_numbers();
    const std::array<int, 5> prompt_choices = handle_prompts();

    // This was really neat to learn about. I had an inkling something like this was
    // possible because of my Python experience, so learning about std::function was
    // relatively smooth.
    // Create a vector of functions who all return nothing and take the same array as
    // an argument.
    const std::vector<std::function<void(const std::array<int, 25>&)>> prompt_actions = {
        check_twelve_to_fifteen,
        check_max_or_min,
        check_sixty_to_seventy,
        check_ending_in_zero,
        check_all_numbers_even_or_odd
    };

    print_divider();

    // Handle the case where no prompts are selected by the user.
    if (std::ranges::max(prompt_choices) == 0) {
        std::cout << "No prompts selected. Continuing forward." << std::endl;
    }

    // Looking at the chosen prompts (those set to 1 in the index), try to execute them,
    // catching any errors thrown and printing them without terminating the program.
    bool no_exceptions_triggered = true;
    for (int i = 0; i < 5; i++) {
        if (prompt_choices[i] == 1) {
            try {
                prompt_actions[i](numbers);
            } catch (const TwelveToFifteenException& e) {
                no_exceptions_triggered = false;
                std::cout << e.what() << std::endl;
            } catch (const MaxOrMinException& e) {
                no_exceptions_triggered = false;
                std::cout << e.what() << std::endl;
            } catch (const SixtyToSeventyException& e) {
                no_exceptions_triggered = false;
                std::cout << e.what() << std::endl;
            } catch (const EndingInZeroException& e) {
                no_exceptions_triggered = false;
                std::cout << e.what() << std::endl;
            } catch (const AllNumbersEvenOrOddException& e) {
                no_exceptions_triggered = false;
                std::cout << e.what() << std::endl;
            } catch (const std::exception& e) {
                no_exceptions_triggered = false;
                std::cout << e.what() << std::endl;
            }
        }
    }

    // Handle the case where none of the chosen exceptions are thrown.
    if (no_exceptions_triggered) {
        std::cout << "None of the chosen exceptions triggered! Congrats!" << std::endl;
    }

    print_divider();

    // Show the array to the user.
    print_generated_numbers(numbers);

    print_divider();

    std::cout << "Press enter to exit..." << std::endl;
    std::getchar();

    return 0;
}

// generate_real_numbers returns a 25-count double array of random
// int numbers on a range from 10 to 100 using the mersenne twister
// engine from <random>.
std::array<int, 25> generate_real_numbers() {
    std::cout << "Generating real int numbers...\n" << std::endl;

    // Clang-Tidy reminded me to initialize all fields to zero on declaration.
    std::array<int, 25> numbers = {};
    std::random_device rd;

    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 100);

    for (int i = 0; i < 25; i++) {
        numbers[i] = dis(gen);
    }

    // Returning a fixed-size array since the assignment demands 25!
    return numbers;
}

// handle_prompts asks the user for confirmation on five different prompts.
// The user's choices are represented in the returned array where 0 is no, and
// 1 is yes. The choices are later used to call certain indices of a vector of functions.
std::array<int, 5> handle_prompts() {
    std::array<int, 5> prompt_choices = {};

    std::cout << "For the following prompts, please enter y or n (yes or no) to select applicable conditions." <<
            std::endl;

    print_divider();

    std::cout << "Raise an error if a number exists within the array from 12-15? [y/n]: ";
    validate_set_prompt_input(prompt_choices, 0);

    std::cout << "\nRaise an error if the maximum or minimum (10 or 100) exists within the array? [y/n]: ";
    validate_set_prompt_input(prompt_choices, 1);

    std::cout << "\nRaise an error if a number exists within the array between 60-70 (inclusive)? [y/n]: ";
    validate_set_prompt_input(prompt_choices, 2);

    std::cout << "\nRaise an error if a number ending in -0 exists within the array? [y/n]: ";
    validate_set_prompt_input(prompt_choices, 3);

    std::cout << "\nRaise an error if all numbers in the array are even or odd? [y/n]: ";
    validate_set_prompt_input(prompt_choices, 4);

    return prompt_choices;
}

// validate_set_prompt_input validates the user input after every prompt within handle_prompts,
// ensuring that either lowercase y or n was entered, reprompting if not.
// If and only if the user input was y, then set the passed by reference prompt choices
// array at the passed in index to 1.
void validate_set_prompt_input(std::array<int, 5> &prompt_choices, const int index) {
    char user_input;
    std::cin >> user_input;

    while (user_input != 'y' && user_input != 'n') {
        std::cout << "  ERROR: Please enter 'y' for yes or an 'n' for no. [y/n]: ";
        std::cin.clear();
        ignore_input();
        std::cin >> user_input;
    }

    if (has_extra_input()) {
        std::cout << "  EXTRA INPUT: The entered text has extra input. Using the first entry: " << user_input <<
                std::endl;
    }

    if (user_input == 'y') {
        prompt_choices[index] = 1;
    }

    ignore_input();
}

// print_generated_numbers simply outputs the array numbers in a neatly formatted way.
void print_generated_numbers(const std::array<int, 25> &numbers) {
    std::cout << "This was the array:\n[" << std::endl;

    int line_break_counter = 0;
    for (int i = 0; i < 25; i++) {
        // Don't print the comma after the final number.
        if (i == 24) {
            std::cout << std::to_string(numbers[i]) << std::endl;
            break;
        }

        std::cout << std::to_string(numbers[i]) + ", ";
        line_break_counter++;

        // Break the line every five numbers.
        if (line_break_counter == 5) {
            line_break_counter = 0;
            std::cout << std::endl;
        }
    }

    std::cout << "]\n";
}

void print_divider() {
    std::cout << "\n============================================================================\n" << std::endl;
}

// Helper function to ignore any leftover input.
void ignore_input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Helper function to check whether or not any text exists within the stream
// beyond the first character. Used within handle_prompts().
bool has_extra_input() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}


