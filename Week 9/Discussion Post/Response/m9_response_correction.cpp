
#include <iostream>
using namespace std;


class Family {
public:
    string name;

    void input() {
        cout << "Enter family member name: ";
        cin >> name;
    }

    void display() {
        cout << "Family Member Name: " << name << endl;
    }
};

class child : public Family {
public:
    void speak() {
        cout << name << " says: Goodbye!" << endl;
    }
};

int main() {
    child child1, child2;

    cout << "--- Child 1 ---" << endl;
    child1.input();
    child1.display();
    child1.speak();

    cout << endl;

    cout << "--- Child 2 ---" << endl;
    child2.input();
    child2.display();
    child2.speak();

    return 0;
}
