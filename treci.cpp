#include <iostream>

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (!cmp(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
bool ascending(T a, T b) {
    return a < b;
}

template <typename T>
bool descending(T a, T b) {
    return a > b;
}

int main() {
    int a[] = {4, 1, 3, 2};
    double b[] = {2.5, 1.1, 4.8, 3.2};
    char c[] = {'z', 'a', 'm', 'b'};

    my_sort(a, 4, ascending<int>);
    my_sort(b, 4, ascending<double>);
    my_sort(c, 4, descending<char>);

    std::cout << "Int uzlazno: ";
    for (int x : a) {
        std::cout << x << ' ';
    }

    std::cout << "\nDouble uzlazno: ";
    for (double x : b) {
        std::cout << x << ' ';
    }

    std::cout << "\nChar silazno: ";
    for (char x : c) {
        std::cout << x << ' ';
    }

    std::cout << '\n';

    return 0;
}
