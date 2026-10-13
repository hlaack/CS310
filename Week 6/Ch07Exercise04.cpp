#include <iostream>
#include <string>

// Trying out the print header, an alternative to cout.
// Introduced print in C++20 and my used println in C++23.

// Scratch that. I get an error related to linking libstdc++exp,
// and since you are testing our programs manually, I want to avoid
// messing with my CMake file in any way that would restrict portability
// to whatever device you're testing on.

// For now I'll stick with the standard streams, and I'll experiment with
// the print library on my own time! :^)




// Declare all functions before main.
static void print_break();
static size_t get_vowel_index(const std::string &user_string, std::size_t start);
static std::string remove_vowels(const std::string& user_string);
static void main_loop();

int main() {

    std::string user_string;

    print_break();

    // Welcome user to program.
    std::cout << "Hello! Welcome to the Week 6 assignment." << std::endl;
    std::cout << "This program will remove all values from your input string." << std::endl;

    main_loop();

}

// This function prints a clean line break within the terminal.
static void print_break() {

    std::cout << "\n=============================================\n" << std::endl;

}

// This function takes in the user's input as const reference to avoid copying.
// It finds the next vowel's index beginning within the string at the specified start index.
static size_t get_vowel_index(const std::string &user_string, const std::size_t start) {

    std::size_t vowel_index = 0;
    const std::string vowels = "aeiouAEIOU";

    // For each letter from the specified start index until end...
    for (std::size_t i = start; i < user_string.length(); i++) {

        // if the current character is in vowels...
        if (vowels.find(user_string[i]) != std::string::npos) {

            // output the index of the vowel.
            vowel_index = i;
            return vowel_index;

        }

    }

    // Otherwise, return end of string.
    return std::string::npos;

}

// This function creates a new_string, concatenating a substring each loop that begins from
// the last consonant up until the next found vowel.
static std::string remove_vowels(const std::string& user_string) {

    // Find the index of the first vowel.
    std::size_t vowel_index = get_vowel_index(user_string, 0);
    // Initialize new_string from beginning of word until first vowel.
    std::string new_string = user_string.substr(0, vowel_index);

    // For every character within the user_string...
    std::size_t new_start = -1;
    while (vowel_index != std::string::npos) {

        // Start at the next consonant after the prior vowel and
        // find the next vowel's index.
        new_start = vowel_index + 1;
        vowel_index = get_vowel_index(user_string, new_start);

        // Add to new_string the substring from the current consonant
        // up until the next vowel.
        new_string += user_string.substr(new_start, vowel_index - new_start);

    }

    // Return the new string after looping.
    return new_string;

}

// This loops the program until the user quits.
// The user must enter '0' to continue, or any non-zero number to exit.
// Input validation checks the above.
static void main_loop() {

    int user_choice = 0;

    // While the user wishes to continue...
    while (user_choice == 0) {

        // Reset the user_string.
        std::string user_string;

        print_break();

        // Obtain user input.
        std::cout << "Enter your string: " << "\n>  ";
        getline(std::cin, user_string);

        // Cleanly output call to remove_vowels.
        std::cout << "\nHere is your input without vowels: " << std::endl;
        std::cout << ">  " << remove_vowels(user_string) << std::endl;

        // Prompt user to continue or exit.
        std::cout << "\nEnter 0 if you wish to continue." << std::endl;
        std::cout << "Otherwise, enter a non-zero number: " << "\n>  ";

        // If there is an error...
        while (!(std::cin >> user_choice)) {
            std::cout << "  Invalid input. Enter only numbers. Try again." << "\n  >  ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        // Clean up errors and toss prior input.
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

}
