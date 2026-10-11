
#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};


void move_by(Point* p, double dx, double dy) {
    p->x = p->x + dx;
    p->y = p->y + dy;
}

double dist(const Point* a, const Point* b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;

    return std::sqrt(dx * dx + dy * dy);
}


void move_by(Point& p, double dx, double dy) {
    p.x = p.x + dx;
    p.y = p.y + dy;
}

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point a = {1, 2};
    Point b = {4, 6};


    move_by(&a, 2, 3);
    std::cout << dist(&a, &b) << "\n";


    move_by(a, -2, -3);
    std::cout << dist(a, b) << "\n";


    Point points[5] = {
        {3, 4},
        {1, 2},
        {-2, 1},
        {0.5, 0.5},
        {5, 1}
    };

    int najbliza = 0;

    for (int i = 1; i < 5; i++) {
        if (dist(points[i], {0, 0}) <
            dist(points[najbliza], {0, 0})) {
            najbliza = i;
        }
    }

    std::cout << "Najbliza tocka: ";
    std::cout << points[najbliza].x << " ";
    std::cout << points[najbliza].y << "\n";

    return 0;
}

