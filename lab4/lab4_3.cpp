#include <iostream>

class Program{
    public:
    static void main(){
        int num,pow;
        std::cout<<"Enter num: ";
        std::cout.flush();
        std::cin>>num;
        std::cout<<"Enter pow: ";
        std::cout.flush();
        std::cin>>pow;
        std::cout<<Program::pow(num,pow)<<std::endl;
    }
    static const int pow(int num, int pow){
        int result = num;
        for(int i =1; i < pow; i++){
            result*=num;
        }
        return result;
    }
};

int main(){
    Program::main();
    return 0;
}