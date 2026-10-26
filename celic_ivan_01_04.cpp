#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void input_vector(vector<int> &v)
{
    int broj;
    do
    {
        cin>>broj;
        if(broj!=0)
        {
            v.push_back(broj);

        }
    } while(broj!=0);
}
int main()
{
    vector <int> v;

    cout << "Unesite brojeve (0 za kraj): ";
    input_vector(v);

    int k;

    cout << "k: ";
    cin >> k;

    int negativnih=count_if(v.begin(),v.end(),[](int x){return x<0;});
    cout << "negativnih:" << negativnih << endl;
    auto it=find_if(v.begin(),v.end(),[k](int x){return x%k==0;});
    if (it != v.end())
    {
        cout << "prvi visekratnik od " << k << ": " << *it << " (pozicija " << it - v.begin() << ")" << endl;

    }
    else
    {
        cout << "Nema visekratnika broja " << k << endl;
    }
    if (!v.empty())
    {
        auto min_it = min_element(v.begin(), v.end());
        auto max_it = max_element(v.begin(), v.end());
        cout << "min " << *min_it << " (pozicija " << min_it - v.begin() << "), ";
        cout << "max " << *max_it << " (pozicija " << max_it - v.begin() << ")" << endl;

    }
    v.erase(remove_if(v.begin(),v.end(),[k](int x){return x%k==0;}),v.end());
    for(int x:v)
    {
        cout << "bez visekratnika" << x << endl;
    }


}
