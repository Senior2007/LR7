#include "task4.h"
#define int long long

int x;

int mult(int a, int b) { //O(log b)
    int result = 0;

    while (b > 0) { //O(log b)
        if (b & 1) {
            result += a;
        }

        a <<= 1;
        b >>= 1;
    }

    return result;
}

void solve4() {
    std::cin >> x;

    int l = 0, r = 1e17;
    while (l < r) { //O(log^2 r)
        int m = ((l + r) >> 1);
        if (mult(3, m) < x) l = m + 1; else r = m; //O(log m)
    }

    if (mult(3, l) == x) { //O(log l)
        std::cout << "Введенное Вами число делится на 3\n";
    } else {
        std::cout << "Введенное Вами число не делится на 3\n";
    }

    l = 0; r = 1e16;
    while (l < r) { //O(log^2 r)
        int m = ((l + r) >> 1);
        if (mult(47, m) < x) l = m + 1; else r = m; //O(log m)
    }

    if (mult(47, l) == x) { //O(log l)
        std::cout << "Введенное Вами число делится на 47\n";
    } else {
        std::cout << "Введенное Вами число не делится на 47\n";
    }

    l = 0; r = 1e16;
    while (l < r) { //O(log^2 r)
        int m = ((l + r) >> 1);
        if (mult(197, m) < x) l = m + 1; else r = m; //O(log m)
    }

    if (mult(197, l) == x) { //O(log l)
        std::cout << "Введенное Вами число делится на 197\n";
    } else {
        std::cout << "Введенное Вами число не делится на 197\n";
    }
}