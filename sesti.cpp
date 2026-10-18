#include <iostream>
#include <string>

struct Student {
    std::string ime;
    std::string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void print_student(Student& s) {
    std::cout << s.ime
              << ", JMBAG: " << s.jmbag
              << ", godina: " << s.godina
              << ", ECTS: " << s.ects
              << ", prosjek: " << s.prosjek
              << '\n';
}

void next_year(Student& s) {
    s.godina++;
}

void filter_students(
    Student s[],
    int n,
    void (*action)(Student&),
    bool (*cond)(const Student&)
) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

int main() {
    Student studenti[] = {
        {"Ana Horvat", "001", 1, 30, 4.2},
        {"Ivan Ilic", "002", 2, 50, 3.8},
        {"Marko Maric", "003", 1, 0, 3.1},
        {"Petra Peric", "004", 3, 45, 4.5},
        {"Luka Lukic", "005", 1, 15, 3.6}
    };

    int n = 5;

    std::cout << "Studenti prve godine koji su polozili barem jedan ispit:\n";

    filter_students(
        studenti, n,
        print_student,
        [](const Student& s) {
            return s.godina == 1 && s.ects > 0;
        }
    );

    std::cout << "\nStudenti s prosjekom vecim od 3.5:\n";

    filter_students(
        studenti, n,
        print_student,
        [](const Student& s) {
            return s.prosjek > 3.5;
        }
    );

    filter_students(
        studenti, n,
        next_year,
        [](const Student& s) {
            return s.ects >= 45;
        }
    );

    std::cout << "\nStudenti nakon povecanja godine studija:\n";

    for (int i = 0; i < n; i++) {
        print_student(studenti[i]);
    }

    return 0;
}
