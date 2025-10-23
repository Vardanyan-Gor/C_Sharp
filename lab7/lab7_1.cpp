#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Employee {
protected:
    std::string name_;
    double salary_;
public:
    Employee(std::string name, double salary)
        : name_(std::move(name)), salary_(salary) {}

    virtual ~Employee() = default;

    virtual void Work() const {
        std::cout << name_ << " works. Salary: " << salary_ << "\n";
    }
};

class Manager : public Employee {
public:
    Manager(std::string name, double salary)
        : Employee(std::move(name), salary) {}

    void Work() const override {
        std::cout << "Manager " << name_ << " plans and coordinates. Salary: " << salary_ << "\n";
    }
};

class Developer : public Employee {
public:
    Developer(std::string name, double salary)
        : Employee(std::move(name), salary) {}

    void Work() const override {
        std::cout << "Developer " << name_ << " writes code. Salary: " << salary_ << "\n";
    }
};

class Designer : public Employee {
public:
    Designer(std::string name, double salary)
        : Employee(std::move(name), salary) {}

    void Work() const override {
        std::cout << "Designer " << name_ << " creates UI/UX. Salary: " << salary_ << "\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Employee>> staff;
    staff.emplace_back(std::make_unique<Manager>("Alice", 3000));
    staff.emplace_back(std::make_unique<Developer>("Bob", 2500));
    staff.emplace_back(std::make_unique<Designer>("Carol", 2400));

    for (const auto& e : staff) {
        e->Work();
    }
    return 0;
}
