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
    int64_t N;
    cin >> N;
    std::vector<int64_t> scores_1(1, 0);
    std::vector<int64_t> scores_2(1, 0);
    rep(i, 0, N) {
        int64_t C, P;
        cin >> C >> P;
        if (C == 1) {
            scores_1.emplace_back(P + scores_1.back());
            scores_2.emplace_back(scores_2.back());
        } else {
            scores_1.emplace_back(scores_1.back());
            scores_2.emplace_back(P + scores_2.back());
        }
    }
    int64_t Q;
    cin >> Q;
    std::vector<std::pair<int64_t, int64_t>> p;
    rep(i, 0, Q) {
        int64_t L, R;
        cin >> L >> R;
        L--;
        printf("%ld %ld\n", scores_1[R] - scores_1[L],
               scores_2[R] - scores_2[L]);
    }
    return 0;
}
