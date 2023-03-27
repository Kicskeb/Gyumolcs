#include <iostream>
#include <array>
#include <random>
#include <set>

class Table {
private:
    std::array<char, 25> arr = {};
public:
    Table() {
        std::random_device r;
        std::default_random_engine gen(r());
        std::uniform_int_distribution<size_t> dist(0, 24);
        std::uniform_int_distribution<size_t> dist_2(0, 6);
        std::set<unsigned int> things;
        unsigned int x1, x2;
        do {
            x1 = dist_2(gen);
            x2 = dist_2(gen);
        } while (x1 != x2);
        while (things.size() < 7) {
            things.insert(dist(gen));
        };
        int i = 0;
        for (auto j: things) {
            arr[j] = (i == x1 || i == x2) ? 'X' : 'G';
            i++;
        };
    };

    void printer() {
        for (auto i: arr) {
            std::cout << i << " ";
        };
        std::cout << std::endl;
    }

    void play() {
        int g_szam = 0, steps = 0;
        for (auto i: arr) {
            if (i == 'X') steps += 3;
            else if (i == 'G') g_szam++;
            steps++;
            if (g_szam == 5) break;
        };
        std::cout << "Required steps: " << steps;
    }
};

int main() {
    Table jatek;
//    jatek.printer();
    jatek.play();
    return 0;
}