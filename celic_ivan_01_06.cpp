
#include <iostream>
#include <cstdlib>

int nzd(int a, int b) {
    while (b != 0) {
        int ostatak = a % b;
        a = b;
        b = ostatak;
    }

    return a;
}

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {
        int n = nzd(std::abs(numerator),
                    std::abs(denominator));

        if (n != 0) {
            numerator = numerator / n;
            denominator = denominator / n;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    double value() {
        return (double) numerator / denominator;
    }

    void print() {
        std::cout << numerator << "/" << denominator;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {
    Fraction rezultat;

    rezultat.numerator =
        a.numerator * b.denominator +
        b.numerator * a.denominator;

    rezultat.denominator =
        a.denominator * b.denominator;

    rezultat.reduce();

    return rezultat;
}

int main() {
    Fraction a = {1, 2};
    Fraction b = {1, 4};

    std::cout << "Prvi razlomak: ";
    a.print();

    std::cout << "\nDecimalna vrijednost: "
              << a.value() << "\n";

    Fraction c = sum(a, b);

    std::cout << "Zbroj: ";
    c.print();

    std::cout << "\nDecimalna vrijednost zbroja: "
              << c.value() << "\n";

    return 0;
}

