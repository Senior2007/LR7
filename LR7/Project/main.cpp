#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

int main() {
    std::string type;

    while(1) {
        std::cout << "Введите номер задачи, которую хотите запустить\n";
        std::cout << "При любом другом вводе программа завершится\n\n";

        std::getline(std::cin, type);

        if (type != "1" && type != "2" && type != "3" && type != "4" && type != "5") {
            break;
        }

        if (type == "1") {
            solve1();
            std::cout << '\n';
            std::getline(std::cin, type);
        } else if (type == "2") {
            solve2();
            std::cout << '\n';
            std::getline(std::cin, type);
        } else if (type == "3"){
            solve3();
            std::cout << '\n';
            std::getline(std::cin, type);
        } else if (type == "4"){
            solve4();
            std::cout << '\n';
            std::getline(std::cin, type);
        } else if (type == "5"){
            solve5();
            std::cout << '\n';
            std::getline(std::cin, type);
        }
    }

    return 0;
}