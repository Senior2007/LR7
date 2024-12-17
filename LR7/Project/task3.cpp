#include "task3.h"

int base, leng = 1000;
std::string str1, str2;
char zn;
char a[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
              'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
              'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
              'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::map<char, int> mp;

std::string sum_task3(std::string s1, std::string s2) {
    while(s1.size() != leng) s1 = '0' + s1; //O(leng) в худшем случае
    while(s2.size() != leng) s2 = '0' + s2; //O(leng) в худшем случае
    std::string res = "";
    int ost = 0;

    for (int i = leng - 1; i >= 0; i--) { //O(leng)
        int s = (mp[s1[i]] + mp[s2[i]] + ost) % base;
        res += a[s];
        ost = ((mp[s1[i]] + mp[s2[i]] + ost) >= base);
    }

    reverse(res.begin(), res.end()); //O(leng)
    while(res.size() > 1 && res[0] == '0') res.erase(0, 1); //O(leng) в худшем случае

    return res;
}

std::string dif(std::string s1, std::string s2) {
    while(s1.size() != leng) s1 = '0' + s1; //O(leng) в худшем случае
    while(s2.size() != leng) s2 = '0' + s2; //O(leng) в худшем случае
    std::string res = "";
    int ost = 0;

    bool bad = 0;
    for (int i = leng - 1; i >= 0; i--) { //O(leng)
        int s = (mp[s1[i]] - mp[s2[i]] - ost);
        if (s < 0) {
            if (i == 0) {
                bad = 1;
            }
            s += base;
            ost = 1;
        } else {
            ost = 0;
        }

        res += a[s];
    }

    if (bad) {
        return '-' + dif(s2, s1); //O(leng) в худшем случае
    } else {
        reverse(res.begin(), res.end()); //O(leng)
        while(res.size() > 1 && res[0] == '0') res.erase(0, 1); //O(leng) в худшем случае

        return res;
    }
}

void solve3() {
    for (int i = 0; i < 36; i++) mp[a[i]] = i;
    std::cin >> base;
    std::cin >> str1 >> zn >> str2;

    if (zn == '+') {
        if (str1[0] == '-' && str2[0] == '-') {
            str1.erase(0, 1);
            str2.erase(0, 1);
            std::cout << '-' << sum_task3(str1, str2) << '\n'; //O(leng) в худшем случае
            return;
        }

        if (str1[0] != '-' && str2[0] != '-') {
            std::cout << sum_task3(str1, str2) << '\n'; //O(leng) в худшем случае
            return;
        }

        if (str1[0] == '-'){
            str1.erase(0, 1);
            std::cout << dif(str2, str1) << '\n'; //O(leng) в худшем случае
            return;
        }

        str2.erase(0, 1);
        std::cout << dif(str1, str2) << '\n'; //O(leng) в худшем случае
        return;
    }

    if (str1[0] == '-' && str2[0] == '-') {
        str1.erase(0, 1);
        str2.erase(0, 1);
        std::cout << dif(str2, str1) << '\n'; //O(leng) в худшем случае
        return;
    }

    if (str1[0] == '-') {
        str1.erase(0, 1);
        std::cout << '-' << sum_task3(str1, str2) << '\n'; //O(leng) в худшем случае
        return;
    }

    if (str1[0] != '-' && str2[0] == '-') {
        str2.erase(0, 1);
        std::cout << sum_task3(str1, str2) << '\n'; //O(leng) в худшем случае
        return;
    }

    std::cout << dif(str1, str2) << '\n'; //O(leng) в худшем случае
}