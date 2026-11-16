
#include <iostream>
using namespace std;

class IntStack {
private:
    int* niz;
    int broj;
    int kapacitet;

public:

    IntStack(int k = 2) {
        kapacitet = k;
        broj = 0;
        niz = new int[kapacitet];
    }


    ~IntStack() {
        delete[] niz;
    }


    IntStack(const IntStack& s) {
        broj = s.broj;
        kapacitet = s.kapacitet;
        niz = new int[kapacitet];

        for (int i = 0; i < broj; i++) {
            niz[i] = s.niz[i];
        }
    }


    void push(int x) {
        if (broj == kapacitet) {
            kapacitet *= 2;

            int* novi = new int[kapacitet];

            for (int i = 0; i < broj; i++) {
                novi[i] = niz[i];
            }

            delete[] niz;
            niz = novi;
        }

        niz[broj] = x;
        broj++;
    }


    void pop() {
        if (broj > 0) {
            broj--;
        }
    }


    int top() const {
        return niz[broj - 1];
    }


    bool empty() const {
        return broj == 0;
    }


    int size() const {
        return broj;
    }

    int capacity() const {
        return kapacitet;
    }
};

int main()
{
    IntStack s;

    for (int i = 1; i <= 5; ++i)
        s.push(i * 10);

    cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';

    IntStack c = s;
    c.pop();
    c.push(99);

    cout << s.top() << ' ' << c.top() << '\n';

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    cout << '\n';

    return 0;
}

