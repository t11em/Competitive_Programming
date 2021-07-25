#include <bits/stdint-intn.h>
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
    vector<vector<int64_t>> dp(s.size() + 1, vector<int64_t>(13));
    int64_t                 amari_of_prev = 0;
    rep(num, 0, 13) { dp[0][num] = 1; }
    rep(i, 1, s.size() + 1) {
        if (s[i] == '?') {
            rep(num, 0, 13) {
                if ((amari_of_prev * 10 + num) % 13 == 5) {
                    dp[i][num] = dp[i - 1][num] + 1;
                } else {
                    dp[i][num] = 0;
                }
            }
        } else {
            int current_digit = int64_t(s[i]);
            rep(num, 0, 13) {
                dp[i][num] = (amari_of_prev * 10 + current_digit) % 13 == 5;
            }
        }
    }
    return 0;
}
