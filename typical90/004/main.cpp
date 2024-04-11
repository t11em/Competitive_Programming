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
    int H, W;
    cin >> H >> W;
    vector<int64_t> row(H);
    vector<int64_t> col(W);
    vector<vector<int64_t>> g(H, vector<int64_t>(W));
    rep(i, 0, H) {
        rep(j, 0, W) {
            int64_t A;
            cin >> A;
            g[i][j] = A;
        }
    }
    rep(i, 0, H) { row[i] = accumulate(g[i].begin(), g[i].end(), 0l); }
    rep(j, 0, W) {
        int sum = 0;
        rep(i, 0, H) { sum += g[i][j]; }
        col[j] = sum;
    }
    rep(i, 0, H) {
        rep(j, 0, W) {
            cout << row[i] + col[j] - g[i][j];
            cout << (j == W - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
