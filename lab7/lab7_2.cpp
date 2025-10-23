#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Appliance {
public:
    virtual ~Appliance() = default;

    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
};

class TV : public Appliance {
public:
    void TurnOn() override {
        std::cout << "TV turned on. Showing channels...\n";
    }
    void TurnOff() override {
        std::cout << "TV turned off.\n";
    }
};

class WashingMachine : public Appliance {
public:
    void TurnOn() override {
        std::cout << "Washing machine started washing.\n";
    }
    void TurnOff() override {
        std::cout << "Washing machine stopped.\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Appliance>> appliances;
    appliances.emplace_back(std::make_unique<TV>());
    appliances.emplace_back(std::make_unique<WashingMachine>());

    std::cout << "--- Turning ON all appliances ---\n";
    for (auto& a : appliances) a->TurnOn();

    std::cout << "\n--- Turning OFF all appliances ---\n";
    for (auto& a : appliances) a->TurnOff();

    return 0;
}

