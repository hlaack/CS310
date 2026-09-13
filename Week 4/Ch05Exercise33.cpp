#include <iostream>

int main() {

    // Initialize user input variables.
    int minutes_for_first;
    int extra_per_dish;
    int total_time;

    std::cout << "\n====================================================\n" << std::endl;

    std::cout << "Enter the time (in minutes) the first dish will take to finish: ";
    std::cin >> minutes_for_first;

    std::cout << "Enter the extra time (in minutes) it takes for each dish after the first: ";
    std::cin >> extra_per_dish;

    std::cout << "Enter the total time (in minutes) Bianca has to prepare dishes: ";
    std::cin >> total_time;

    // Handle case where the total time is less than the
    // minutes required to prepare even the first dish.
    if (total_time < minutes_for_first) {
        std::cout << "Bianca doesn't have enough time to even begin!" << std::endl;
        return 0;
    }

    // time_remaining begins after first dish is prepared.
    int time_remaining = total_time - minutes_for_first;
    // next_dish_time begins at the time for the second dish.
    int next_dish_time = minutes_for_first + extra_per_dish;
    // Since the first dish was subtracted from time_remaining,
    // begin the counter at 1 dish prepared.
    int dishes_prepared = 1;

    // While there is enough time left to prepare the next dish,
    // remove the time it took to make that next dish from time_remaining,
    // increase the time it takes to make the next dish,
    // and increment the counter.
    while (time_remaining >= next_dish_time) {
        time_remaining -= next_dish_time;
        next_dish_time += extra_per_dish;
        dishes_prepared++;
    }

    // Output the amount of dishes that Bianca was able to prepare.
    std::cout << "Bianca was able to prepare " << dishes_prepared << " dishes." << std::endl;

    std::cout << "\n====================================================\n" << std::endl;

    return 0;

}
