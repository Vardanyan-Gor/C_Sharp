#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct IPayable {
    virtual ~IPayable() = default;
    virtual void PaySalary() = 0; 
};

struct Employee : IPayable {
    std::string Name;
    double MonthlySalary;

    Employee(std::string name, double salary)
        : Name(std::move(name)), MonthlySalary(salary) {}

    void PaySalary() override {
        std::cout << "Employee " << Name << ": pay " << MonthlySalary << "\n";
    }
};

struct Freelancer : IPayable {
    std::string Name;
    double HourRate;
    int Hours;

    Freelancer(std::string name, double rate, int hours)
        : Name(std::move(name)), HourRate(rate), Hours(hours) {}

    void PaySalary() override {
        std::cout << "Freelancer " << Name << ": pay " << (HourRate * Hours) << "\n";
    }
};

int main() {
    std::vector<std::unique_ptr<IPayable>> payroll;
    payroll.emplace_back(std::make_unique<Employee>("Alice", 3000));
    payroll.emplace_back(std::make_unique<Freelancer>("Bob", 25.0, 120));
    payroll.emplace_back(std::make_unique<Employee>("Carol", 2800));

    for (auto& p : payroll) {
        p->PaySalary();
    }
    return 0;
}


