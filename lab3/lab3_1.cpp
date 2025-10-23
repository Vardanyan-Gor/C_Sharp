#include <iostream>

void is_not_prime(long long int num){
    std::cout<<"Number: "<< num <<" is not prime"<<std::endl;
}

void is_prime(long long int num){
    std::cout<<"Number: "<< num <<" is prime"<<std::endl;
}

void prime(long long int num){
    if(num<2){
        return is_not_prime(num);
    }
    if(num == 2 || num == 3){
        return is_not_prime(num);
    }
    if(num % 2 == 0 || num % 3 == 0){
        return is_not_prime(num);
    }

    for (long long i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0)
        return is_not_prime(num);

    }
    return is_prime(num);
}

int main() {
    long long n;
    std::cout << "Enter the number: ";
    std::cout.flush();
    std::cin >> n;
    prime(n);
    return 0;
}