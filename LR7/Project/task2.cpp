#include "task2.h"

std::string s1, s2, s3;
int len = 1000;

std::string get(std::string s) { //O(len)
    if (s[0] == '-') {
        s[0] = '0';
        while(s.size() != len - 1) s = '0' + s; //O(len) в худшем случае
        s = '1' + s;

        for (int i = 1; i < len; i++) { //O(len)
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }

        int i = s.size() - 1;
        while (s[i] == '1') { //O(len) в худшем случае
            s[i] = '0';
            i--;
        }
        s[i] = '1';

        return s;
    }

    while(s.size() != len) s = '0' + s; //O(len) в худшем случае

    return s;
}

std::string sum(std::string s1, std::string s2) { //O(len)
    int ost = 0;
    std::string s = "";

    for (int i = len - 1; i >= 0; i--) { //O(len)
        s += std::to_string((s1[i] - '0' + s2[i] - '0' + ost) % 2);
        ost = (s1[i] - '0' + s2[i] - '0' + ost) > 1;
    }

    reverse(s.begin(), s.end()); //O(len)

    bool pr = 0;
    if (s[0] == '1') {
        for (int i = 0; i < len; i++) { //O(len)
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }

        int i = s.size() - 1;
        while (s[i] == '1') { //O(len) в худшем случае
            s[i] = '0';
            i--;
        }

        s[i] = '1';
        pr = 1;
    }

    while(s.size() > 1 && s[0] == '0') { //O(len) в худшем случае
        s.erase(0, 1);
    }


    if (pr) {
        s = '-' + s;
    }

    return s;
}

void solve2() {
    std::cin >> s1 >> s2;

    s1 = get(s1);
    s2 = get(s2);
    s3 = sum(s1, s2);

    std::cout << s3 << '\n';
}