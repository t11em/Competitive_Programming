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

uint64_t calc(uint64_t i, uint64_t n) { return (n * (n + 1)) / 2; }

int main() {
    uint64_t n;
    cin >> n;
    uint64_t ans = 0;
    rep(i, 1, n + 1) { ans += calc(i, n / i) * i; }
    cout << ans << endl;
    return 0;
}
