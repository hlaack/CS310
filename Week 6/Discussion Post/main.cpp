#include <iostream>

int main() {

    std::cout << "Hello, everyone!" << std::endl;
    std::cout << "This program contains two errors specifically relating to the enum type." << std::endl;
    std::cout << "Can you find them?" << std::endl;

    enum healthLevels(
        CRITICAL = 25,
        INJURED = 50,
        HEALTHY = 75
    );

    enum creatureDifficulty {
        EASY = 1,
        MEDIUM,
        HARD,
        EXTREME
    };

    enum creatureType first_creature = WILD;

}
