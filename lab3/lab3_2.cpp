#include <iostream>

int summ_to(int num){
    return (num*(num+1)/2);
}

int main(){
    int num;
    std::cout<<"Enter number: ";
    std::cout.flush();
    std::cin>>num;
    std::cout<<"Summ of all numbers benween 1 and N is: "<<summ_to(num)<<std::endl;
    return 0;
}