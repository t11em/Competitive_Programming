#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define rrep(i, m, n) for (int i = (int)(n - 1); i >= (int)(m); --i)

template <typename T, typename U>
pair<T, U> tp(T a, U b) {
    return std::make_pair(a, b);
}

constexpr int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    map<char, int> m;
    m['c'] = 0;
    m['h'] = 0;
    m['o'] = 0;
    m['k'] = 0;
    m['u'] = 0;
    m['d'] = 0;
    m['a'] = 0;
    m['i'] = 0;

    for (const auto& c : s) {
        switch (c) {
            case 'c':
                m[c]++;
                m[c] %= MOD;
                break;
            case 'h':
                m[c] += m['c'];
                m[c] %= MOD;
                break;
            case 'o':
                m[c] += m['h'];
                m[c] %= MOD;
                break;
            case 'k':
                m[c] += m['o'];
                m[c] %= MOD;
                break;
            case 'u':
                m[c] += m['k'];
                m[c] %= MOD;
                break;
            case 'd':
                m[c] += m['u'];
                m[c] %= MOD;
                break;
            case 'a':
                m[c] += m['d'];
                m[c] %= MOD;
                break;
            case 'i':
                m[c] += m['a'];
                m[c] %= MOD;
                break;
        }
    }
    cout << m['i'] % MOD << endl;
    return 0;
}
