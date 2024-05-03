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
#define rrep(i, m, n) for (int i = (int)(m); i > (int)(n); --i)

template <typename T, typename U>
pair<T, U> tp(T a, U b) {
    return std::make_pair(a, b);
}

constexpr int MOD = 1000000007;

int main() {
    int64_t N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    string ans       = "";
    int    min_index = -1;
    while (ans.size() != K) {
        char tmp = 'z';
        for (int index = min_index + 1; index < s.size() - K + ans.size() + 1;
             index++) {
            if (s[index] < tmp) {
                tmp       = s[index];
                min_index = index;
            }
        }
        ans += tmp;
    }
    printf("%s\n", ans.c_str());

    return 0;
}
