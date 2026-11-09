//
// Created by harry on 11/9/2026.
//

#include "Candidate.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>

// DEFAULT CONSTRUCTOR
// Set initial values to 0.
Candidate::Candidate() {
    name = "";
    num_votes = 0;
}

// WHEN INDEXED
// Use this constructor to format prompts correctly.
Candidate::Candidate(const int index) {
    set_valid_name(index);
    set_valid_votes(index);
}

// SETTER: sets name.
// Prompts the user for a name and validates for alphabetic characters
// and spaces exclusively. Will also reprompt if the input is empty.
void Candidate::set_valid_name(const int index) {
    if (index == 0) {
        std::cout << "Enter the name of the candidate: ";
        std::getline(std::cin, name);
    }
    else {
        std::cout << "Enter the name of candidate " + std::to_string(index + 1) + ": ";
        std::getline(std::cin, name);
    }

    bool is_valid = std::ranges::all_of(name, [](const char& c) { return isalpha(c) || isspace(c); });
    while (!is_valid || name.empty()) {
        std::cout << "  ERROR: Only letters and spaces are accepted. Please try again.\n" << std::endl;

        if (index == 0) {
            std::cout << "Enter the name of the candidate: ";
            std::getline(std::cin, name);
            is_valid = std::ranges::all_of(name, [](const char& c) { return isalpha(c) || isspace(c); });
        }
        else {
            std::cout << "Enter the name of candidate " + std::to_string(index + 1) + ": ";
            std::getline(std::cin, name);
            is_valid = std::ranges::all_of(name, [](const char& c) { return isalpha(c) || isspace(c); });
        }
    }

    std::cout << "\n";
}

// SETTER: sets num_votes.
// Prompts the user to enter the number of votes a candidate received,
// validating that it is non-negative and is a whole number.
void Candidate::set_valid_votes(const int index) {
    if (index == 0) {
        std::cout << "Enter the number of votes they received: ";
    }
    else {
        std::cout << "Enter the number of votes candidate " + std::to_string(index + 1) + " received: ";
    }

    while (!(std::cin >> num_votes) || num_votes < 0) {
        std::cout << "  ERROR: Enter positive whole numbers only. Please try again.\n" << std::endl;
        std::cin.clear();
        ignore_line();

        if (index == 0) {
            std::cout << "Enter the number of votes they received: ";
        }
        else {
            std::cout << "Enter the number of votes candidate " + std::to_string(index + 1) + " received: ";
        }
    }

    if (has_extra_input()) {
        ignore_line();
        std::cout << "  NOTE: Discarding additional input. Using first number: " << num_votes << "\n" << std::endl;
    }

    ignore_line();
    std::cout << "\n";
}

// GETTER: returns name.
std::string Candidate::get_name() {
    return name;
}

// GETTER: returns num_votes.
int Candidate::get_votes() const {
    return num_votes;
}

// HELPER: neatly outputs candidate information on a single line.
void Candidate::print_candidate(const double total_votes) const {
    constexpr char separator = ' ';
    constexpr int width = 20;
    const double percent_vote = (num_votes / total_votes) * 100;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(width) << std::setfill(separator) << name;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << num_votes;
    std::cout << std::left << std::setw(width) << std::setfill(separator) << percent_vote;
    std::cout << std::endl;
}

// HELPER: Checks whether or not there is more input beyond the first ::cin.
bool Candidate::has_extra_input() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

// HELPER: Cleans up long ignore() call into short function call.
void Candidate::ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
