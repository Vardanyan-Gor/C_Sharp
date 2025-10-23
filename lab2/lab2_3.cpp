#include <iostream>

int main(){
    int even;
    std::cout<<"Enter number: ";
    std::cout.flush();
    std::cin>>even;
    std::cout << (even % 2 == 0 ? "Number is even\n" : "Number is odd\n");
    std::cout.flush();  
}