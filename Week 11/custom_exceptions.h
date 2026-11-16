//
// Created by harry on 11/16/2026.
//

#ifndef WEEK_11_CUSTOM_EXCEPTIONS_H
#define WEEK_11_CUSTOM_EXCEPTIONS_H
#include <stdexcept>

// All of these classes simply inherit from runtime_error to preserve
// how it handles try/catch integration.

class TwelveToFifteenException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

void check_twelve_to_fifteen(const std::array<int, 25> &numbers);

class MaxOrMinException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

void check_max_or_min(const std::array<int, 25> &numbers);

class SixtyToSeventyException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

void check_sixty_to_seventy(const std::array<int, 25> &numbers);

class EndingInZeroException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

void check_ending_in_zero(const std::array<int, 25> &numbers);

class AllNumbersEvenOrOddException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

void check_all_numbers_even_or_odd(const std::array<int, 25> &numbers);

#endif //WEEK_11_CUSTOM_EXCEPTIONS_H
