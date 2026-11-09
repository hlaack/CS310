#include <iomanip>
#include <iostream>
#include "Candidate.h"

// While std::vector is more safe to work with, the textbook this
// week uses pointer-based dynamic arrays, so that is what I will use!

// Declare useful functions.
static int get_num_candidates();
static void print_table_header();
static void print_divider();

int main() {
    print_divider();

    const int num_candidates = get_num_candidates();

    // Clang-Tidy suggested using auto instead of the class name in order
    // to avoid duplicating the type name.
    auto* candidates = new Candidate[num_candidates];

    // Define variables needed to track sum of votes and the winner.
    double total_votes = 0;
    int current_winner_index = 0;

    print_divider();

    for (int i = 0; i < num_candidates; ++i) {
        candidates[i].set_valid_name(i);
        candidates[i].set_valid_votes(i);
        total_votes += candidates[i].get_votes();

        // Update who is in the lead if necessary.
        if (candidates[i].get_votes() > candidates[current_winner_index].get_votes()) {
            current_winner_index = i;
        }
    }

    print_divider();

    // Output cleanly formatted table.
    print_table_header();
    for (int i = 0; i < num_candidates; ++i) {
        candidates[i].print_candidate(total_votes);
    }

    std::cout << "\nThe winner of the election is " << candidates[current_winner_index].get_name() << "." << std::endl;

    print_divider();

    // Prevent auto-closing terminal...
    std::cout << "Press enter to exit..." << std::endl;
    std::getchar();

    // Clean up memory.
    delete[] candidates;
    candidates = nullptr;

    return 0;
}

// Prompts the user to enter the number of candidates, validating that
// it is a positive whole number while handling the tossing of extra
// input.
static int get_num_candidates() {
    int num_candidates;
    std::cout << "Enter the number of candidates that ran: ";

    while (!(std::cin >> num_candidates) || num_candidates <= 0) {
        std::cout << "  ERROR: Only enter a positive, non-zero whole number.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter the number of candidates that ran: ";
    }

    if (!std::cin.eof() && std::cin.peek() != '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  NOTE: Discarding additional input. Using first number: " << num_candidates << "\n" << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n";

    return num_candidates;
}

// Cleanly outputs header information for the Candidates table.
// Formatted just like the class, but separated as to not be called
// every time a Candidate's print function is needed.
static void print_table_header() {
    constexpr char separator = ' ';
    constexpr int width = 20;

    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Candidate";
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Votes Received";
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "% of Total Votes";
    std::cout << "\n" << std::endl;
}

// Simply prints a dividing line of equal signs for nice formatting.
static void print_divider() {
    std::cout << "\n============================================================\n" << std::endl;
}