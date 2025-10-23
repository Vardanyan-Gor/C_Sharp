// main.cpp
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <ctime>

struct LibraryBook {
    std::string title;
    std::string author;
    int year;

    LibraryBook()
        : LibraryBook("", "", current_year()) {}

    LibraryBook(std::string t, std::string a)
        : LibraryBook(std::move(t), std::move(a), current_year()) {}

    LibraryBook(std::string t, std::string a, int y) {
        trim(t);
        trim(a);

        if (t.empty()) t = "Unknown Title";
        if (a.empty()) a = "Unknown Author";

        int cy = current_year();
        if (y < 1450 || y > cy)
            throw std::out_of_range("Year must be in [1450, current_year]");

        title  = std::move(t);
        author = std::move(a);
        year   = y;
    }

    static int current_year() {
        std::time_t now = std::time(nullptr);
        std::tm* lt = std::localtime(&now);
        return 1900 + lt->tm_year;
    }

    static void trim(std::string& s) {
        size_t i = 0, j = s.size();
        while (i < j && std::isspace((unsigned char)s[i])) ++i;
        while (j > i && std::isspace((unsigned char)s[j-1])) --j;
        s.assign(s.begin() + i, s.begin() + j);
    }

    std::string ToString() const {
        return '"' + title + "\" by " + author + " (" + std::to_string(year) + ')';
    }
};

int main() {
    try {
        LibraryBook b1;                                  
        LibraryBook b2("  Clean Code  ", "  Robert C. Martin  "); 
        LibraryBook b3("The Pragmatic Programmer", "Andrew Hunt", 1999); 

        std::cout << b1.ToString() << "\n";
        std::cout << b2.ToString() << "\n";
        std::cout << b3.ToString() << "\n";


    } catch (const std::exception& ex) {
        std::cerr << "error: " << ex.what() << "\n";
    }
    return 0;
}
