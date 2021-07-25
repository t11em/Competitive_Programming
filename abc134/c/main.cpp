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
    int64_t n;
    cin >> n;
    vector<int64_t> a_vec(n);
    rep(i, 0, n) cin >> a_vec[i];
    priority_queue<int64_t> a_pq(a_vec.begin(), a_vec.end());
    int64_t                 a_max_first = a_pq.top();
    a_pq.pop();
    int64_t a_max_second = a_pq.top();
    rep(i, 0, n) {
        if (a_vec[i] == a_max_first)
            cout << a_max_second << endl;
        else
            cout << a_max_first << endl;
    }

    return 0;
}
