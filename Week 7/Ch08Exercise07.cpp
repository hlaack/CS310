#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

// Since I used exclusively C-style arrays, returning them from functions can lead
// to unintended behavior, which I always want to avoid, even in assignments.
// I learned this thanks to my compilers warnings when I was trying to return a
// C-style array from an earlier rendition of calc_percentages.
// To get around this while still using C-style arrays, I looped through the indices
// within main, and just passed the index value into the functions. I always passed the arrays
// in as pointers so that they weren't ever copied and so they could be modified.
// I know std::array and std::vector would likely make my life much easier here, but I wanted
// to stick to the C-style array.

// Function declarations.
static bool valid_candidate_name(const std::string& candidate_name);
static void print_line_break();
static void get_candidates(std::string* candidates, int index);
static void get_votes(int* num_votes, int index);
static double calc_percentages(const int* num_votes, double sum, int index);
static void print_table(const std::string* candidates, const int* num_votes, const double* percentage_votes, int greatest_votes_index);

int main() {
    // Declare parallel arrays for names, votes, and percentages.
    std::string candidates[5];
    int num_votes[5];
    double percentages[5];

    print_line_break();

    // Can track sum and winner here so it doesn't need to be calculated
    // at any other time.
    double sum = 0;
    int greatest_votes_index = 0;
    int greatest_votes = 0;
    for (int i = 0; i < 5; i++) {
        get_candidates(candidates, i);
        get_votes(num_votes, i);
        sum += num_votes[i];

        if (greatest_votes < num_votes[i]) {
            greatest_votes_index = i;
            greatest_votes = num_votes[i];
        }

        std::cin.ignore(1000, '\n');
        std::cout << "\n";
    }

    for (int i = 0; i < 5; i++) {
        percentages[i] = calc_percentages(num_votes, sum, i);
    }

    print_line_break();

    print_table(candidates, num_votes, percentages, greatest_votes_index);

    print_line_break();

    std::cout << "Press enter to exit." << std::endl;
    std::getchar();

    return 0;
}

// This function iterates through each character in the candidate name
// and ensures it is either a letter or space.
static bool valid_candidate_name(const std::string& candidate_name) {
    // Runs the predicate (the return statement there) for each char
    // within the candidate_name string.
    const bool is_valid = std::ranges::all_of(candidate_name, [](const char& c) { return (isalpha(c) || isspace(c)); });
    return is_valid;

    // The for loop was my original implementation, but Clang-Tidy suggested
    // I use the C++20 std::ranges::all_of algorithm. Took me a little bit
    // to understand, but cppreference and this website helped me use it correctly:
    // https://www.studyplan.dev/pro-cpp/counting-algorithms#using-allof

    // for (const char c : candidate_name) {
    //     if (!isalpha(c) && !isspace(c)) {
    //         return false;
    //     }
    // }
}

// This function simply prints out a formatted line break.
static void print_line_break() {
    std::cout << "\n" << "========================================================" << "\n" << std::endl;
}

// This function prompts the user for the name, waits until the name is valid, and updates
// the value at passed in index within candidates array to the input.
static void get_candidates(std::string* candidates, const int index) {
    std::cout << "Enter the name of candidate " + std::to_string(index + 1) + ": ";
    std::getline(std::cin, candidates[index]);

    // Ensure there is a name and that it consists of only letters and spaces.
    // Learned that -> allows me to access a member function of an object via a pointer.
    while (!valid_candidate_name(candidates[index]) || candidates->empty()) {
        std::cout << "  ERROR: Only letters and spaces are accepted. Please try again." << std::endl;
        std::cout << "\nEnter the name of candidate " + std::to_string(index + 1) + ": ";
        std::getline(std::cin, candidates[index]);
    }
}

// This function prompts the user for the number of votes, waits until a number is received,
// and updates the value at passed in index within the num_votes array to the input.
static void get_votes(int* num_votes, const int index) {
    std::cout << "Enter the number of votes they received: ";

    // Verify the user input a number.
    while (!(std::cin >> num_votes[index])) {
        std::cout << "  ERROR: Enter whole numbers only. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nEnter the number of votes candidate " + std::to_string(index + 1) + " received: ";
    }
}

// Simply calculates the percentage value for a candidate's votes.
static double calc_percentages(const int* num_votes, const double sum, const int index) {
    return (num_votes[index] / sum) * 100.0;
}

// Cleanly formats a table output using iomanip functions.
static void print_table(const std::string* candidates, const int* num_votes, const double* percentage_votes, const int greatest_votes_index) {
    constexpr char separator = ' ';
    constexpr int width = 20;

    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Candidate";
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Votes Received";
    std::cout << std::left << std::setw(width) << std::setfill(separator) << "% of Total Votes";
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << std::fixed <<std::setprecision(2);
        std::cout << std::left << std::setw(width) << std::setfill(separator) << candidates[i];
        std::cout << std::left << std::setw(width) << std::setfill(separator) << num_votes[i];
        std::cout << std::left << std::setw(width) << std::setfill(separator) << percentage_votes[i];
        std::cout << std::endl;
    }

    std::cout << "\nThe Winner of the Election is " << candidates[greatest_votes_index] << "." << std::endl;
}