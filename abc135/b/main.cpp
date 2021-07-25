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
    int64_t         n;
    cin >> n;
    vector<int64_t> vec(n);
    rep(i, 0, n) cin >> vec[i];
    vector<int64_t> sorted_vec = vec;
    sort(sorted_vec.begin(), sorted_vec.end());
    //reverse(sorted_vec.begin(), sorted_vec.end());

    int64_t cnt = 0;
    rep(i, 0, n) {
        if (vec[i] != sorted_vec[i]) ++cnt;
    }
    if (cnt == 0 || cnt == 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
