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

std::pair<int64_t, int64_t> search(int64_t start,
                                   const vector<vector<int64_t>>& g) {
    priority_queue<int64_t> pq;
    pq.push(start);
    vector<int64_t> distance(g.size(), INT64_MAX);
    distance[start] = 0;
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        rep(i, 0, g[now].size()) {
            int next = g[now][i];
            if (distance[now] + 1 < distance[next]) {
                distance[next] = distance[now] + 1;
                pq.push(next);
            }
        }
    }
    const auto& max_iter = max_element(distance.begin(), distance.end());
    const auto& max_index = std::distance(distance.begin(), max_iter);
    return tp(max_index, *max_iter);
}

int main() {
    int64_t N;
    cin >> N;
    vector<vector<int64_t>> g(N, std::vector<int64_t>());
    rep(i, 0, N - 1) {
        int64_t A, B;
        cin >> A >> B;
        g[A - 1].emplace_back(B - 1);
        g[B - 1].emplace_back(A - 1);
    }

    auto [index, _] = search(0, g);
    auto [__, res] = search(index, g);

    printf("%ld\n", res + 1);

    return 0;
}
