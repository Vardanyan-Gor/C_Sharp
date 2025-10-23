#include <string>
#include <stdexcept>
#include <cctype>
#include <iostream>

struct Email {
    std::string addr;

    explicit Email(const char* address) {
        if (!address) throw std::invalid_argument("address is null");
        addr = address;
        trim(addr);
        if (addr.empty()) throw std::invalid_argument("address is empty");
        to_lower(addr); 
    }

    bool IsValid() const {
        for(const char& c : addr){
            if(c == '@'){
                return true;
            }
        }
        return false;
    }

    std::string ToString() const { return addr; }

private:
    static void trim(std::string& s) {
        size_t i = 0, j = s.size();
        while (i < j && std::isspace((unsigned char)s[i])) ++i;
        while (j > i && std::isspace((unsigned char)s[j - 1])) --j;
        s.assign(s.begin() + i, s.begin() + j);
    }
    static void to_lower(std::string& s) {
        for (char& c : s) c = (char)std::tolower((unsigned char)c);
    }
};

int main() {
    Email e1("  User.Name@Example.COM  ");
    std::cout << e1.ToString() << "  valid=" << (e1.IsValid() ? "true" : "false") << "\n";

    Email e2("bad-address-no-at");
    std::cout << e2.ToString() << "  valid=" << (e2.IsValid() ? "true" : "false") << "\n";

    // Email e3(nullptr);

    return 0;
}

