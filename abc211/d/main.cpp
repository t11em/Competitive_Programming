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
    int64_t n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>());
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    int             start = 1;
    queue<int>      que;
    vector<int64_t>     distance(n + 1, INT64_MAX);
    vector<int64_t> count(n + 1, 0);

    distance[start] = 0;
    count[start]    = 1;
    que.push(start);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (const auto& nv : graph[now]) {
            if (distance[nv] == distance[now] + 1) {
                count[nv] += count[now];
                count[nv] %= MOD;
            } else if (distance[nv] >= distance[now] + 1) {
                count[nv] = count[now];
                count[nv] %= MOD;
                distance[nv] = distance[now] + 1;
                que.push(nv);
            }
        }
    }
    cout << count[n] << endl;
    return 0;
}
