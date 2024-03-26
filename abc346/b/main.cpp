#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
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
#define rrep(i, m, n) for (int i = (int)(m); i > (int)(n); --i)

template <typename T, typename U>
pair<T, U> tp(T a, U b) {
    return std::make_pair(a, b);
}

constexpr int MOD = 1000000007;

int main() {
    int W, B;
    cin >> W >> B;
    std::string origin = "wbwbwwbwbwbw";
    std::string s      = origin;
    for (int i = 0; i < 100; i++) {
        s += origin;
    }
    int W_cnt = 0;
    int B_cnt = 0;
    for (size_t i = 0; i < s.size(); i++) {
        for (size_t j = i; j < s.size(); j++) {
            if (s[j] == 'w') {
                W_cnt++;
            } else {
                B_cnt++;
            }
            if (W_cnt == W && B_cnt == B) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        W_cnt = 0;
        B_cnt = 0;
    }
    cout << "No" << endl;
    return 0;
}
