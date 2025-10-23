// main.cpp
#include <iostream>
#include <string>
#include <cstddef>

struct Point {
    const int x;
    const int y;

    Point(int x_, int y_) : x(x_), y(y_) {}

    bool Equals(const Point& other) const {
        return x == other.x && y == other.y;
    }

    std::size_t GetHashCode() const {
        return static_cast<std::size_t>(x) * 1315423911u ^ static_cast<std::size_t>(y);
    }

    std::string ToString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

inline bool operator==(const Point& a, const Point& b) { return a.Equals(b); }
inline bool operator!=(const Point& a, const Point& b) { return !(a.Equals(b)); }
inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << '(' << p.x << ", " << p.y << ')';
}

int main() {
    Point p1(3, 4);
    Point p2(3, 4);
    Point p3(4, 3);

    std::cout << "p1 = " << p1 << "\n";
    std::cout << "p2 = " << p2 << "\n";
    std::cout << "p3 = " << p3 << "\n\n";

    std::cout << "p1.Equals(p2) = " << (p1.Equals(p2) ? "true" : "false") << "\n"; 
    std::cout << "p1.Equals(p3) = " << (p1.Equals(p3) ? "true" : "false") << "\n"; 

    std::cout << "hash(p1) = " << p1.GetHashCode() << "\n";
    std::cout << "ToString(p1) = " << p1.ToString() << "\n";

    return 0;
}

