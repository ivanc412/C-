
#include <iostream>
#include <string>

int main() {
    int godina;
    std::string ime;

    std::cout << "Unesi godinu rodenja: ";
    std::cin >> godina;

    std::cin.ignore();

    std::cout << "Unesi ime i prezime: ";
    std::getline(std::cin, ime);

    std::cout << "Inicijali: " << ime[0] << ".";

    for (int i = 0; i < ime.length(); i++) {
        if (ime[i] == ' ') {
            std::cout << ime[i + 1] << ".";
            break;
        }
    }

    int broj = 0;

    for (char c : ime) {
        if (c != ' ') {
            broj++;
        }
    }

    std::cout << "\nBroj znakova bez razmaka: " << broj;
    std::cout << "\nGodina koju navrsava: " << 2026 - godina;

    return 0;
}

