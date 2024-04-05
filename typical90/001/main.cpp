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

template <typename T, typename U> pair<T, U> tp(T a, U b) {
  return std::make_pair(a, b);
}

constexpr int MOD = 1000000007;

int main() {
  int64_t N, L;
  cin >> N >> L;
  int64_t K;
  cin >> K;
  vector<int64_t> A(N);
  rep(i, 0, N) cin >> A[i];

  const auto CanSeparated = [&](int64_t threshold) {
    int prev = 0;
    int separated = 0;
    for (int64_t i = 0; i < N; i++) {
      if (A[i] - prev > threshold) {
        prev = A[i];
        separated++;
      }
    }
    if (L - prev > threshold) {
      separated++;
    }
    return separated >= K + 1;
  };

  int64_t left = -1;
  int64_t right = L;
  while (left < right) {
    int64_t mid = (left + right) / 2;
    if (CanSeparated(mid)) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  printf("%lld\n", left);

  return 0;
}
