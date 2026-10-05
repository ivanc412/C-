#include <iostream>

int main(){
    int a{}, b{};
    std::cin >> a >> b;
    int zbroj=a+b;
    double sredina = (a+b)/2.0;
    bool usporedba = a<b;

    std::cout <<"Zbroj"<<zbroj<<std::endl;
    std::cout<<"Aritmeticka sredina"<<sredina<<std::endl;
    std::cout<<"a<b"<<usporedba<<std::endl;
    return 0;
}
