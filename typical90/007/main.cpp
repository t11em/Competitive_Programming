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
    int N;
    cin >> N;
    vector<int64_t> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;
    vector<int64_t> B(Q);
    rep(i, 0, Q) cin >> B[i];
    rep(i, 0, Q) {
        int base =
            std::distance(A.begin(), lower_bound(A.begin(), A.end(), B[i]));
        auto lower = std::max(0, base - 1);
        auto upper = std::min(N - 1, base + 1);
        auto res = min(
            {abs(A[lower] - B[i]), abs(A[upper] - B[i]), abs(A[base] - B[i])});
        printf("%ld\n", res);
    }

    return 0;
}
