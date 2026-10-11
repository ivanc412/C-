

#include <iostream>
#include <cstdlib>

int& find_max(int arr[], int n) {
    int max = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
    }

    return arr[max];
}

int main() {
    int numbers[] = {4, -7, 12, 0, 9, -3};
    int n = 6;

    for (int x : numbers) {
        std::cout << x << " ";
    }

    std::cout << "\n";

    for (int i = 0; i < n; i++) {
        if (numbers[i] < 0) {
            numbers[i] = abs(numbers[i]);
        }
    }

    for (int x : numbers) {
        std::cout << x << " ";
    }

    std::cout << "\n";

    find_max(numbers, n) = 0;

    for (int x : numbers) {
        std::cout << x << " ";
    }

    return 0;
}
