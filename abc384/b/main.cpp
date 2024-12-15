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
    int N, R;
    cin >> N >> R;
    for (int i = 0; i < N; i++) {
        int D, A;
        cin >> D >> A;
        if (D == 1) {
            if (1600 <= R && 2799 >= R) {
                R += A;
            }
        } else if (D == 2) {
            if (1200 <= R && 2399 >= R) {
                R += A;
            }
        }
    }
    cout << R << endl;
    return 0;
}
