#include <iostream>
#include <stdexcept>
#include "custom_exceptions.h"

// PROMPT 1

void check_twelve_to_fifteen(const std::array<int, 25> &numbers) {
    for (int i = 0; i < 25; i++) {
        if (numbers[i] >= 12 && numbers[i] <= 15) {
            throw TwelveToFifteenException("SELECTED EXCEPTION TRIGGERED: Number exists within from 12-15.");
        }
    }
}

// PROMPT 2

void check_max_or_min(const std::array<int, 25> &numbers) {
    for (int i = 0; i < 25; i++) {
        if (numbers[i] == 10) {
            throw MaxOrMinException("SELECTED EXCEPTION TRIGGERED: Minimum number exists within the array.");
        }

        if (numbers[i] == 100) {
            throw MaxOrMinException("SELECTED EXCEPTION TRIGGERED: Maximum number exists within the array.");
        }
    }
}

// PROMPT 3

void check_sixty_to_seventy(const std::array<int, 25> &numbers) {
    for (int i = 0; i < 25; i++) {
        if (numbers[i] >= 60 && numbers[i] <= 70) {
            throw SixtyToSeventyException("SELECTED EXCEPTION TRIGGERED: Number exists within from 60-70.");
        }
    }
}

// PROMPT 4

void check_ending_in_zero(const std::array<int, 25> &numbers) {
    for (int i = 0; i < 25; i++) {
        if (numbers[i] % 10 == 0) {
            throw EndingInZeroException("SELECTED EXCEPTION TRIGGERED: Number within ends in 0.");
        }
    }
}

// PROMPT 5

void check_all_numbers_even_or_odd(const std::array<int, 25> &numbers) {
    int amount_even = 0;
    int amount_odd = 0;

    for (int i = 0; i < 25; i++) {
        if (numbers[i] % 2 == 0) {
            amount_even++;
        }

        if (numbers[i] % 2 == 1) {
            amount_odd++;
        }
    }

    if (amount_even == 25) {
        throw AllNumbersEvenOrOddException("SELECTED EXCEPTION TRIGGERED: All numbers within are even!");
    }

    if (amount_odd == 25) {
        throw AllNumbersEvenOrOddException("SELECTED EXCEPTION TRIGGERED: All numbers within are odd!");
    }
}