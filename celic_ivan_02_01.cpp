#include <iostream>
#include <string>
#define MAX(a, b) ((a) > (b) ? (a) : (b))


inline int my_max(int a, int b)
{
    return (a>b) ? a:b;
}
template<typename T>
T my_maxx(T& a, T& b)
{
    return (a>b) ? a:b;
}
int main()
{
    int i=3;
    MAX(++i,2);
    int rezultat=MAX(++i,2);
    std::cout<<rezultat;
    my_max(++i,2);
    int rezultat2=my_max(++i,2);
    std::cout << rezultat2;
    int x=2, y=1;
    my_maxx(x,y);
    int rezultat3=my_maxx(x,y);
    std::cout << rezultat3;
    double m=4, n=2;
    my_maxx(m,n);
    int rezultat4=my_maxx(m,n);
    std::cout << rezultat4;
    const char* c="a";
    const char* v="b";
    my_maxx(c,v);
    const char* rezultat5=my_maxx(c,v);
    std::cout << rezultat5;
    std::string s1{"ok"};
    std::string s2{"da"};
    my_maxx(s1,s2);
    std::string rezultat6=my_maxx(s1,s2);
    std::cout << rezultat6;
}
