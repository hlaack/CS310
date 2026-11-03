#include <iostream>

class Employee {

protected:
    //...

public:
    Employee() {
        salary = 0;
        emp_id = 0;
        first_name = "";
    }

    Employee(const int input_salary, const int input_emp_id, const std::string& input_first_name) {
        salary = input_salary;
        emp_id = input_emp_id;
        first_name = input_first_name;
    }

private:
    int salary;
    int emp_id;
    std::string first_name;
};

class Manager: public Employee {
public:
    Manager() {
        department_id = 0;
        department_name = "";
    }

    Manager(
        const int input_salary,
        const int input_emp_id,
        const std::string input_first_name,
        const int input_department_id,
        const std::string input_department_name)
    {
        salary = input_salary;
        emp_id = input_emp_id;
        first_name = input_first_name;
        department_id = input_department_id;
        department_name = input_department_name;
    }

private:
    int department_id;
    std::string department_name;
};

int main() {

    std::cout << "Are the employees being recognized?" << std::endl;
    Manager manager;
    Employee employee(42000, 1);

    return 0;
}
