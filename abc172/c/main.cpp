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
#define rrep(i, m, n) for (int i = (int)(n - 1); i >= (int)(m); --i)

template <typename T, typename U>
pair<T, U> tp(T a, U b) {
    return std::make_pair(a, b);
}

constexpr int MOD = 1000000007;

int main() {
    int64_t a, b, k;
    cin >> a >> b >> k;
    vector<int64_t> a_vec(a);
    rep(i, 0, a) { cin >> a_vec[i]; }

    vector<int64_t> b_vec(b);
    rep(i, 0, b) { cin >> b_vec[i]; }

    int64_t sum = accumulate(a_vec.begin(), a_vec.end(), 0l);
    int     ai  = a;
    int64_t res = 0;
    rep(bi, 0, b) {
        while (sum > k && ai >= 1) {
            sum -= a_vec[ai - 1];
            ai--;
        }
        // cout << ai << " " << bi << endl;
        if (sum > k) break;

        res = max(static_cast<int64_t>(ai + bi), res);
        sum += b_vec[bi];
    }
    if (sum <= k) res = max(static_cast<int64_t>(ai + b), res);
    cout << res << endl;

    return 0;
}
