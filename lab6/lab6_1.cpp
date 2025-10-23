// main.cpp
#include <iostream>
#include <string>
#include <stdexcept>

struct Student {
    std::string Name;
    int Age;
    int StudentId;

    static int Count; 

    Student()
        : Student("Unknown", 0, Count + 1) {}

    Student(std::string name, int age)
        : Student(std::move(name), age, Count + 1) {}

    Student(std::string name, int age, int id)
        : Name(std::move(name)), Age(age), StudentId(id)
    {
        if (StudentId < Count) {
            throw std::invalid_argument("StudentId must be >= current Count");
        }
        ++Count;
    }
};

int Student::Count = 0;

int main() {
    try {
        Student s1;                    
        Student s2("Alice", 19);       
        Student s3("Bob", 20, 10);     

        std::cout << "s1: " << s1.Name << ", " << s1.Age << ", id=" << s1.StudentId << "\n";
        std::cout << "s2: " << s2.Name << ", " << s2.Age << ", id=" << s2.StudentId << "\n";
        std::cout << "s3: " << s3.Name << ", " << s3.Age << ", id=" << s3.StudentId << "\n";
        std::cout << "Created students (Count): " << Student::Count << "\n";

        // Пример ошибки:
        // Student bad("X", 18, 0); // бросит исключение: 0 < Count

    } catch (const std::exception& ex) {
        std::cerr << "error: " << ex.what() << "\n";
    }
    return 0;
}
