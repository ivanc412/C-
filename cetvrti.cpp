#include <iostream>

void my_transform(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int twice(int x) {
    return x * 2;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    my_transform(arr, n, twice);

    std::cout << "Nakon twice: ";
    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    my_transform(arr, n, [](int x) {
        if (x % 2 == 0) {
            return x / 2;
        } else {
            return x * 2;
        }
    });

    std::cout << "Nakon lambda izraza: ";
    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    int suma = 0;
    int produkt = 1;

    [&]() {
        for (int x : arr) {
            suma += x;
            produkt *= x;
        }
    }();

    std::cout << "Suma: " << suma << '\n';
    std::cout << "Produkt: " << produkt << '\n';

    int prag;
    int s = 0;

    std::cout << "Unesi prag: ";
    std::cin >> prag;

    [prag, &s, &arr, n]() {
        for (int i = 0; i < n; i++) {
            if (arr[i] > prag) {
                s += arr[i];
            }
        }
    }();

    std::cout << "Suma vecih od praga: " << s << '\n';

    return 0;
}
