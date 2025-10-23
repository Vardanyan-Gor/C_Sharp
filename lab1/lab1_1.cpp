#include <iostream>
#include <string>

int main (){
    std::string name_secondname{};
    std::string city{};
    std::cout<<"Enter your name and second name: ";
    std::cout.flush();
    std::getline(std::cin, name_secondname);    
    std::cout<<"Enter your city: ";
    std::cout.flush();
    std::getline(std::cin,city);
    std::cout<<"I am "<<name_secondname<<", and i am living in "<<city<<std::endl;
    return 0;
}