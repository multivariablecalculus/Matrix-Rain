#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>

const int WIDTH = 80;
const int HEIGHT = 24;

int main() {
    std::srand(std::time(0));
    std::vector<int> drops(WIDTH, 0);

    while (true) {
        std::cout << "\033[2J\033[1;1H"; // Clear screen
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                if (drops[x] == y)
                    std::cout << (char)(33 + std::rand() % 93);
                else
                    std::cout << " ";
            }
            std::cout << "\n";
        }

        for (int i = 0; i < WIDTH; ++i) {
            if (drops[i] < HEIGHT && std::rand() % 10 > 2)
                ++drops[i];
            else
                drops[i] = 0;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(75));
    }
}

