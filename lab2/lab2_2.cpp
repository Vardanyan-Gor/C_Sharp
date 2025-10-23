#include <iostream>

int area(int R){
    return (3.14*(R*R)); 
}

int main(){
    int radius;
    std::cout<<"Enter radius: ";
    std::cout.flush();
    std::cin>>radius;
    std::cout<<"area: "<<area(radius)<<std::endl;
    return 0;
}