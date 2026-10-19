#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void input_vector(std::vector<int>& v)
{
    int broj=1;
    while(broj!=0)
    {
        cin>>broj;
        v.push_back(broj);
    }
    v.pop_back();


}


void print_vector(const std::vector<int>& v)
 {
    for(const auto& x:v)
    {
        cout<<x<<" ";
        cout<<endl;
    }

    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";

 }



 void shrink_to_fit()
 {

 }

 int main()
 {
    vector<int>v;
    input_vector(v);
    print_vector(v);
    std::vector<int> c;
    for (int i = 0; i < 20; ++i)
        {
            c.push_back(i);
            std::cout << c.size() << "/"
            << c.capacity() << " ";
        }
    c.reserve(100);
    c.shrink_to_fit();
    std::cout << c.capacity();



     return 0;
 }
