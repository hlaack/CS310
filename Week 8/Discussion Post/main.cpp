#include <iostream>

class Animal {

public:
    void set_sound() {
        std::cout << "Tell us what sound it makes: ";
        std::getline(std::cin, sound);
    }

    std::string get_sound() {
        return sound;
    }

    void set_name() {
        std::cout << "Tell us the type of animal: ";
        std::getline(std::cin, name);
    }

    std::string get_name() {
        return name;
    }

private:
    std::string name;
    std::string sound;

};

class Dog: public Animal {

public:
    void set_breed() {
        std::cout << "Tell us the breed: ";
        std::getline(std::cin, breed);
    }

    std::string get_breed() {
        return breed;
    }

private:
    std::string name = "Dog";
    std::string sound = "Woof!";
    std::string breed;

};

int main() {

    Dog jeffrey;
    std::cout << "Jeffrey is a hound, though..." << std::endl;
    jeffrey.sound = "Awoo!";

    Animal cat;
    cat.set_breed();

    return 0;
}
