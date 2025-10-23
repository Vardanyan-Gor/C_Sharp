#include <iostream>

template <typename T>
T add(T a, T b){
    return a+b;
}

template <typename T>
T difference(T a, T b){
    return  a-b;
}

template <typename T>
T muliply(T a, T b){
    return a*b;
}

template <typename T>
T divide(T a, T not_null){
    return not_null!=0 ? a/not_null : (std::cout<<"Can devide to 0, return value is -1 "<<std::endl, -1);
}

int main (){
    int a,b;
    std::cout<<"Enter two nums"<<std::endl;
    std::cin>>a>>b;
    std::cout<<"Divide result: "<<divide(a,b)<<std::endl;;
    std::cout<<"Addition result: "<<add(a,b)<<std::endl;;
    std::cout<<"Muliply result: "<<muliply(a,b)<<std::endl;;
    std::cout<<"Diffierense result: "<<difference(a,b)<<std::endl;;

}