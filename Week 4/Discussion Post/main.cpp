#include <iostream>

int main() {

    std::cout << "Hello friends! This program contains two errors." << std::endl;
    std::cout << "Are you able to find them?" << std::endl;

    for (i = 0; i < 10; i++) {
        std::cout << "Do this logic..." << std::endl;
    }

    bool aFruit = false;
    while (!aFruit) {
        int isThisTrue = false;
        std::cout << "Do this logic..." << std::endl;
        aFruit = true;
    }

    isThisTrue = aFruit;

    std::cout << "Good luck!" << std::endl;

}
