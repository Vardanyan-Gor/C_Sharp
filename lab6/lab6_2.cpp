#include <iostream>
#include <string>
#include <stdexcept>

struct Car {
    std::string Model;
    int Year;
    int Speed;

    Car(std::string model, int year, int speed = 0)
        : Model(std::move(model)), Year(year), Speed(speed)
    {
        if (Year < 1900)
            throw std::invalid_argument("Year must be >= 1900");
    }

    void Accelerate(int amount = 10) {
        Speed += amount;
        std::cout << Model << " accelerated to " << Speed << " km/h\n";
    }

    void Brake(int amount = 10) {
        Speed -= amount;
        if (Speed < 0) Speed = 0;
        std::cout << Model << " slowed down to " << Speed << " km/h\n";
    }

    std::string ToString() const {
        return Model + " (" + std::to_string(Year) + "), Speed=" + std::to_string(Speed);
    }
};

int main() {
    try {
        Car c1("Toyota", 2015);
        Car c2("Ford", 1999, 20);
        Car c3("BMW", 2023);

        std::cout << c1.ToString() << "\n";
        std::cout << c2.ToString() << "\n";
        std::cout << c3.ToString() << "\n\n";

        c1.Accelerate();
        c1.Accelerate(15);
        c1.Brake(5);

        c2.Brake(25);
        c3.Accelerate(50);

        std::cout << "\nFinal states:\n";
        std::cout << c1.ToString() << "\n";
        std::cout << c2.ToString() << "\n";
        std::cout << c3.ToString() << "\n";

        // Проверка исключения
        // Car bad("OldTimer", 1800); // бросит исключение

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}

