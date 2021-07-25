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
    int64_t n;
    cin >> n;
    vector<int64_t> a_vec(n + 1);
    rep(i, 0, n + 1) cin >> a_vec[i];
    vector<int64_t> b_vec(n);
    rep(i, 0, n) cin >> b_vec[i];
    rep(i, 1, n + 1) {
        int64_t diff = max(0l, (b_vec[i - 1] - a_vec[i - 1]));
        a_vec[i - 1] += min(diff, a_vec[i]);
        a_vec[i] -= min(diff, a_vec[i]);
    }
    int64_t ans = 0;
    rep(i, 0, n) { ans += min(b_vec[i], a_vec[i]); }
    cout << ans << endl;
    return 0;
}
