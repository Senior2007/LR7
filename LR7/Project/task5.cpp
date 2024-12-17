#include "task5.h"

int idx, ans, ost = 5;
std::vector<int> num[10], num2[10], b;
bool used[10];

std::string str3(int x) { //O(log3 x)
    std::string res = "";
    while (x > 0) { //O(log3 x)
        res += std::to_string(x % 3);
        x /= 3;
    }

    reverse(res.begin(), res.end());

    while(res.size() != 5) res = '0' + res;
    return res;
}

std::string str2(int x) { //O(log x)
    std::string res = "";
    while (x > 0) { //O(log x)
        res += std::to_string(x % 2);
        x /= 2;
    }

    reverse(res.begin(), res.end());

    while(res.size() != ost) res = '0' + res;
    return res;
}

void step_1() { //~O(1200 * log3 240) оценка сверху
    //~O(1200 * log3 240) оценка сверху
    for (int i = 0; i < 240; i++) { //O(240)
        std::string s = str3(i); //O(log3 i)
        for (int j = 0; j < 5; j++) { //O(5)
            if (s[j] == '0') {
                num[j].push_back(i);
            }
        }
    }

    //~O(1200) оценка сверху
    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << "-й раб выпил бочки : ";
        for (auto u : num[i]) std::cout << u + 1 << ' '; //O(num[i].size())
        std::cout << '\n';
    }
    std::cout << '\n';

    //~O(1200)
    for (int i = 0; i < 5; i++) {
        bool pr = 1;
        for (auto u : num[i]) { //O(num[i].size())
            if (u == idx) {
                pr = 0;
            }
        }
        if (!pr) {
            std::cout << i + 1 << "-й раб умер\n";
            ost--;
            used[i] = 1;
        }
    }

    //~O(1200 * log3 240) оценка сверху
    for (int i = 0; i < 240; i++) { //O(240)
        std::string s = str3(i); //O(log3 i)
        bool pr = 1;
        for (int j = 0; j < 5; j++) { //O(5)
            if (used[j] && s[j] != '0') {
                pr = 0;
            }
            if (!used[j] && s[j] == '0') {
                pr = 0;
            }
        }
        if (pr) {
            b.push_back(i);
        }
    }

    std::cout << "Рабов осталось : " << ost << '\n';
    std::cout << "Подозрительных бочек осталось : " << b.size() << "\n";
    std::cout << "Подозрительные бочки : ";
    for (auto u : b) std::cout << u + 1 << ' ';
    std::cout << "\n\n";
}

int st(int idx) {
    return (1 << (ost - idx - 1));
}

void step_2() { //O(b.size() * log 240 * ost) оценка сверху
    if (ost != 0) {
        std::cout << "Дадим оставшимся рабам номера от 1 до " << ost << '\n';
    }
    //O(b.size() * log 240 * ost) оценка сверху
    for (int i = 0; i < b.size(); i++) { //O(b.size())
        std::string s = str2(i); //O(log i)
        for (int j = 0; j < ost; j++) { //O(ost)
            if (s[j] == '0') {
                num2[j].push_back(b[i]);
            }
        }
    }

    //~O(ost * b.size()) оценка сверху
    for (int i = 0; i < ost; i++) {
        std::cout << i + 1 << "-й раб выпил бочки : ";
        for (auto u : num2[i]) std::cout << u + 1 << ' '; //O(num2[i].size())
        std::cout << '\n';
    }
    std::cout << '\n';

    //O(ost * b.size())
    for (int i = 0; i < ost; i++) { //O(ost)
        bool pr = 1;
        for (auto u : num2[i]) { //O(num2[i].size())
            if (u == idx) {
                pr = 0;
            }
        }
        if (!pr) {
            std::cout << i + 1 << "-й раб умер\n";
        } else {
            ans += st(i);
        }
    }

    ans = b[ans];
}

void solve5() {
    ost = 5;
    for (int i = 0; i < 5; i++) {
        num[i].clear();
        num2[i].clear();
        used[i] = 0;
    }
    b.clear();
    ans = 0;

    std::cout << "Какую бочку Вы собираетесь отравить?\n";
    std::cin >> idx;
    idx--;

    step_1(); //~O(1200 * log3 240) оценка сверху
    step_2(); //O(b.size() * log 240 * ost) оценка сверху

    std::cout << "Отравленная бочка имеет номер : " << ans + 1 << '\n';
}