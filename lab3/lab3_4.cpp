#include <iostream>
#include <random>

int create_pure_random_num(){
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0,100);
    return dist(rd);
}

void guess_number(){
    int random=create_pure_random_num();
    int inserted=150;
    std::cout<<"Enter number to between 0 and 100 to guess: ";
    std::cout.flush();
    while(inserted != random){
        std::cin>>inserted;
        if(inserted>random){
            std::cout<<"Too big! try smaller one :";
            std::cout.flush();
        }
        if(inserted<random){
            std::cout<<"Too small! try bigger one: ";
            std::cout.flush();
        }
    }
    std::cout<<"Congratulations! You have guessed, the number is: "<< random<<std::endl;
}

int main(){
    guess_number();
}