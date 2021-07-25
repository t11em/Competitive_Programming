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
    int64_t         n, q;
    vector<int64_t> a_vec(n - 1);
    vector<int64_t> b_vec(n - 1);
    rep(i, 0, n) {
        cin >> a_vec[i];
        cin >> b_vec[i];
    }
    vector<int64_t> p_vec(q);
    vector<int64_t> x_vec(q);
    rep(i, 0, q) {
        cin >> p_vec[i];
        cin >> x_vec[i];
    }

    return 0;
}
