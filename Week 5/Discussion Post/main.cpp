#include <iostream>

void an_incorrect_function() {
    int number_of_puppies = 3;

    std::cout << number_of_puppies << "?!" << std::endl;
    std::cout << "That's a lot of puppies to handle at once!" << std::endl;

    return number_of_puppies;

}

int main() {

    double new_double = improperly_declared_function();
    int number_of_puppies = an_incorrect_function();

    std::cout << "There are two errors regarding these two user created functions." << std::endl;
    std::cout << "Can you find them?" << std::endl;

}

double improperly_declared_function() {
    std::cout << "Ugh... I'm being declared so late!" << std::endl;
    std::cout << "This is so humiliating." << std::endl;

    return 400.0;
}