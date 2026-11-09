#include <iostream>

int main() {
    std::cout << "There are two errors regarding pointers within this program..." << std::endl;
    std::cout << "Can you find them and fix them?" << std::endl;

    double grade_percentage = 89.91;
    int* ptr = &grade_percentage;

    double test_score_a = 92.23;
    double test_score_b = 88.19;

    double* p1 = &test_score_a;
    double* p2 = &test_score_b;
    const double* p3 = p1 + p2;

    std::cout << "Average between A and B: " << *p3 / 2 << std::endl;

    std::cout << "Press enter to exit..." << std::endl;
    std::getchar();
}
