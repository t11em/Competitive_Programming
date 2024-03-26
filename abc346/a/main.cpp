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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    for (size_t i = 0; i < a.size() - 1; ++i) {
        cout << a[i] * a[i + 1] << " ";
    }
    cout << endl;
    return 0;
}
