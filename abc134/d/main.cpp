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
    int64_t n;
    cin >> n;
    vector<int64_t> n_vec(n);
    vector<int64_t> ans_vec(n);

    rep(i, 0, n) cin >> n_vec[i];
    auto calc = [&](int index) {
        int accumulate = 0;
        for (int i = index; i < n; i += (1 + index)) {
            accumulate += ans_vec[i];
        }
        return accumulate % 2;
    };
    rrep(i, n - 1, -1) {
        if (calc(i) != n_vec[i]) ans_vec[i] = 1;
    }
    if (all_of(
            ans_vec.begin(), ans_vec.end(), [](int ans) { return ans == 0; }))
        cout << 0 << endl;
    else {
        cout << count(ans_vec.begin(), ans_vec.end(), 1) << endl;
        rep(i, 0, n) {
            if (ans_vec[i] != 0) cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
