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
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    set<int64_t>    s;
    rep(i, 0, N) {
        cin >> A[i];
        s.insert(A[i]);
    }
    vector<int64_t> sorted_s(N);
    for (const auto& ss : s) sorted_s.push_back(ss);
    sort(sorted_s.begin(), sorted_s.end());

    auto    ptr   = upper_bound(sorted_s.begin(), sorted_s.end(), K);
    auto    start = sorted_s.begin();
    int64_t a_sum = 0;
    while (start != ptr) {
        a_sum += *start;
        ++start;
    }
    cout << (((K + 1) * K) / 2) - a_sum << endl;

    return 0;
}
