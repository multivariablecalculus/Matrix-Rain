#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <unistd.h>

const int WIDTH = 80;
const int HEIGHT = 25;

void sleep(int ms) {
    usleep(ms * 1000);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> drops(WIDTH, 0);

    std::cout << "\033[32m";

    while (true) {
        std::cout << "\033[2J\033[1;1H"; 

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                if (drops[x] == y) {
                    char c = 33 + std::rand() % 94;
                    std::cout << c;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }

        for (int i = 0; i < WIDTH; ++i) {
            if (std::rand() % 100 > 95)
                drops[i] = 0;
            else
                drops[i] = (drops[i] + 2) % HEIGHT;
        }

        sleep(50);
    }

    return 0;
}

