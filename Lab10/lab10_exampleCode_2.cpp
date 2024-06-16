#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
public:
    Employee(const string& _name, float _years_of_service): name(_name), years_of_service(_years_of_service) {}

    virtual void calculateSalary() = 0;

    void printInfo() const {
        cout << name << " " << years_of_service << " " << salary << endl;
    }
    bool operator>(const Employee& other) const {
        return salary > other.salary;
    }

protected:
    float years_of_service;
    int salary;
    string name;
};

class Parttimer : public Employee {
public:
    Parttimer(const string& _name, float _years_of_service): Employee(_name, _years_of_service) {}

    void calculateSalary() override {
        salary = 20000 + 1000 * years_of_service;
    }
};

class Manager : public Employee {
public:
    Manager(const string& _name, float _years_of_service): Employee(_name,  _years_of_service) {}

    void calculateSalary() override {
        salary = 20000 + 15000 + 5000 * years_of_service;
    }
};

class Chairman : public Manager {
public:
    Chairman(const string& _name, float _years_of_service): Manager(_name, _years_of_service) {}

    void calculateSalary() override {
        Manager::calculateSalary();
        salary += 50000;
    }
};

int main()
{
    int n;
    string name, title;
    float years_of_service;

    cin >> n;
    vector<Employee*> employees(n);
    for (int i = 0; i < n; ++i) {
        cin >> name >> title >> years_of_service;
        if (title == "P") {
            employees[i] = new Parttimer(name, years_of_service);
        } else if (title == "M") {
            employees[i] = new Manager(name, years_of_service);
        } else if (title == "C") {
            employees[i] = new Chairman(name, years_of_service);
        }
        employees[i]->calculateSalary();
    }

    sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
        return *a > *b;
    });

    for (const auto& employee : employees) {
        employee->printInfo();
    }

    return 0;
}
