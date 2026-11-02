#include <iostream>
#include <cassert>
class Volume {
    private:
    int level;
    int previous;

static int limit(int l) {
    if (l < 0) return 0;
    if (l > 100) return 100;
    return l;
}

bool valid() const {
    return level >= 0 && level <= 100;
}

public:
    Volume(int l) : level(limit(l)), previous(50) {
    assert(valid());
}

Volume() : Volume(50) {}

void up(int step = 10) {
    level = limit(level + step);
    assert(valid());
}

void down(int step = 10) {
    level = limit(level - step);
    assert(valid());
}

void mute() {
    previous = level;
    level = 0;
    assert(valid());
}

void unmute() {
    level = previous;
    assert(valid());
}

int get() const {
    return level;
}
};
int main()
{
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}
