#include <iostream>
#include <string>

enum class Environment { Dev, Stage, Prod };

struct AppSettings {
    const Environment Environment_;
    const std::string Version_;

    AppSettings(Environment env, std::string version)
        : Environment_(env), Version_(std::move(version)) {}

    std::string ToString() const {
        return "Environment=" + EnvToString(Environment_) + ", Version=" + Version_;
    }

private:
    static std::string EnvToString(Environment e) {
        switch (e) {
            case Environment::Dev:   return "Dev";
            case Environment::Stage: return "Stage";
            case Environment::Prod:  return "Prod";
        }
        return "UNDEFINED"; 
    }
};

// Демонстрация
int main() {
    AppSettings s1(Environment::Prod, "1.2.0");
    AppSettings s2(Environment::Dev,  "0.1.0");
    std::cout << s1.ToString() << "\n"; 
    std::cout << s2.ToString() << "\n"; 
    return 0;
}
