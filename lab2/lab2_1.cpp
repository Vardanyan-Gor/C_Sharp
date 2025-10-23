#include <iostream>

int area(int a, int b){
    return a*b;
}

int perimeter(int a, int b){
    return (2*(a+b));
}

int main (){
    int lenght,heigh;
    std::cout<< "Enter length: ";
    std::cout.flush();
    std::cin>>lenght;
    std::cout<< "Enter heigh: ";
    std::cout.flush();
    std::cin>>heigh;
    std::cout<<"area: "<<area(lenght,heigh)
             <<"\nperimeter: "<<perimeter(lenght,heigh)<<std::endl;
    return 0;
}