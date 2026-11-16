#include <fstream>
#include <iostream>
#include <string>

class Money {
private:
    int cents;

public:
    Money(int euros = 0, int cents = 0) {
        this->cents = euros * 100 + cents;
    }
    Money& operator+=(const Money& other) {
        cents += other.cents;
        return *this;
    }


    Money operator+(const Money& other) const {
        return Money(0, cents + other.cents);
    }
     bool operator<(const Money& other) const {
        return cents < other.cents;
    }


    friend std::ostream& operator<<(std::ostream& out, const Money& m) {
        int euros = m.cents / 100;
        int centi = m.cents % 100;

        out << euros << '.'
            << std::setw(2) << std::setfill('0') << centi
            << " EUR";

        return out;
    }
 friend std::istream& operator>>(std::istream& in, Money& m) {
        int euros, centi;
        char znak;

        if (in >> euros >> znak >> centi) {
            if (znak != '.') {
                in.setstate(std::ios::failbit);
            }
            else {
                m.cents = euros * 100 + centi;
            }
        }

        return in;
    }

};

int main()
{
    Money a(1, 5);
    Money b(0, 95);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    std::ifstream in("racun.txt");
    if (!in) {
        std::cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    std::string item;
    Money price;
    Money total;
    Money max_price;
    std::string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        std::cout << "Neispravan zapis: " << item << '\n';

    std::cout << "Stavki: " << count << '\n';
    std::cout << "Ukupno: " << total << '\n';
    std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}

