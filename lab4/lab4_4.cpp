#include <iostream>
#include <assert.h>
class Program{
public:
    static void main(){
        int num1, num2;
        char action;
        std::cout<<"Enter first number: ";
        std::cout.flush();
        std::cin>>num1;
        std::cout<<"Enter second number: ";
        std::cout.flush();
        std::cin>>num2;
        std::cout<<"Enter action type by symbol +, -, /, *: ";
        std::cout.flush();
        std::cin>>action;
        std::cout<<Program::do_action(action,num1,num2)<<std::endl;
    }

    static int do_action(char action, int num1, int num2){
        switch (action)
        {
        case '+':
            return add(num1,num2);
        case '-':
            return substract(num1,num2);
        case '*':
            return muliply(num1,num2);
        case '/':
            return divide(num1,num2);
        default:
            std::cout<<"Something went wrong, return value is -1"<<std::endl;
            return -1;
        }
    }

    static int add(int a, int b){
        return a+b;
    }

    static int substract(int a, int b){
        return a-b;
    }

    static int divide(int a, int b){
        assert(b != 0);
        return a/b;
    }
    
    static int muliply(int a, int b){
        return a*b;
    }
};

int main(){
    Program::main();
    return 0;
}       