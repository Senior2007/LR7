#include "task1.h"

std::string s;

void solve1() { //O(s.size())
    std::cin >> s;

    if (s[0] == '1') {
        //O(s.size())
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }

        //O(s.size()) в худшем случае
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        if (i >= 0) s[i] = '1';
    }

    std::cout << s << '\n';
}