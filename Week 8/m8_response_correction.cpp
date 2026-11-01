#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;

public:
    void setName(string studentName)
    {
        name = studentName;
    }

    void displayName()
    {
        cout << "Student: " << name << endl;
    }
};

class Course
{
private:
    string courseName;

public:
    void setCourse(string name)
    {
        courseName = name;
    }

    void displayCourse()
    {
        cout << "Course: " << courseName << endl;
    }
};

int main()
{
    Student student1;
    Course course1;

    student1.setName("John");
    course1.setCourse("Computer Science");

    // student1.name = "Mike";
    student1.setName("Mike");

    // course1.showCourse();
    course1.displayCourse();

    return 0;
}
