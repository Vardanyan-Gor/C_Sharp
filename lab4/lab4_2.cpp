#include <iostream>
#include <string>
#include <algorithm>

class Program {
public:
    static void main() {
        std::string str;
        std::cout<<"Enter string to reverse: ";
        std::cout.flush();
        std::getline(std::cin,str);
        std::cout<<Program::reverse(str)<<std::endl;
    }
    template<typename T>
    static const std::string& reverse(T&& str){
        std::reverse(str.begin(),str.end()); 
        return str;
    }
};

int main() {
    Program::main(); 
    return 0;
}
