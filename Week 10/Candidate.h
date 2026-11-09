//
// Created by harry on 11/9/2026.
//

#ifndef WEEK_10_CANDIDATE_H
#define WEEK_10_CANDIDATE_H
#include <string>


class Candidate {

public:
    // DEFAULT CONSTRUCTOR
    // Set initial values to 0.
    Candidate();

    // WHEN INDEXED
    // Use this constructor to format prompts correctly.
    explicit Candidate(int index);

    // SETTER: sets name.
    // Prompts the user for a name and validates for alphabetic characters
    // and spaces exclusively. Will also reprompt if the input is empty.
    void set_valid_name(int index = 0);

    // SETTER: sets num_votes.
    // Prompts the user to enter the number of votes a candidate received,
    // validating that it is non-negative and is a whole number.
    void set_valid_votes(int index = 0);

    // GETTER: returns name.
    [[nodiscard]] std::string get_name();

    // GETTER: returns num_votes.
    [[nodiscard]] int get_votes() const;

    // HELPER: neatly outputs candidate information on a single line.
    void print_candidate(double total_votes) const;

private:
    int num_votes{};
    std::string name;

    // HELPER: Checks whether or not there is more input beyond the first ::cin.
    static bool has_extra_input();

    // HELPER: Cleans up long ignore() call into short function call.
    static void ignore_line();

};


#endif //WEEK_10_CANDIDATE_H
