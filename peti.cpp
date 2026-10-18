#include <iostream>

inline double add(double a, double b) {
    return a + b;
}

inline double subtract(double a, double b) {
    return a - b;
}

inline double multiply(double a, double b) {
    return a * b;
}

inline double divide(double a, double b) {
    return a / b;
}

int main() {
    double (*operacije[4])(double, double) = {
        add, subtract, multiply, divide
    };

    double a, b;
    int izbor;

    std::cout << "Unesi dva broja: ";
    std::cin >> a >> b;

    std::cout << "Odaberi operaciju (0-zbroj, 1-razlika, "
              << "2-produkt, 3-kolicnik): ";
    std::cin >> izbor;

    if (izbor < 0 || izbor > 3) {
        std::cout << "Neispravna operacija!\n";
    } else if (izbor == 3 && b == 0) {
        std::cout << "Dijeljenje nulom nije dozvoljeno!\n";
    } else {
        std::cout << "Rezultat: "
                  << operacije[izbor](a, b) << '\n';
    }

    return 0;
}
