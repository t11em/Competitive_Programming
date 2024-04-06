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
std::vector<std::vector<int>> bracket_vec;
int N;

enum Bracket {
  OPEN = 0,
  CLOSE = 1,
};

bool check(vector<int> brackets) {
  if (brackets.size() % 2 != 0) {
    return false;
  }
  if (brackets[0] == CLOSE) {
    return false;
  }
  if (std::count(brackets.begin(), brackets.end(), OPEN) !=
      brackets.size() / 2) {
    return false;
  }
  const auto is_parenthetical_forward = [](vector<int> brackets) {
    int open_count = 0;
    int close_count = 0;
    for (int i = 0; i < brackets.size(); i++) {
      if (brackets[i] == OPEN) {
        open_count++;
      } else {
        if (0 < open_count) {
          open_count--;
        } else {
          close_count++;
        }
      }
    }
    return open_count == 0 && close_count == 0;
  };
  const auto is_parenthetical_backward = [](vector<int> brackets) {
    int open_count = 0;
    int close_count = 0;
    for (int i = brackets.size() - 1; i >= 0; i--) {
      if (brackets[i] == CLOSE) {
        close_count++;
      } else {
        if (0 < close_count) {
          close_count--;
        } else {
          open_count++;
        }
      }
    }
    return open_count == 0 && close_count == 0;
  };

  if (!is_parenthetical_forward(brackets)) {
    return false;
  }
  if (!is_parenthetical_backward(brackets)) {
    return false;
  }
  return true;
}

void f(const vector<int> &brackets) {
  if (brackets.size() == N) {
    if (check(brackets)) {
      bracket_vec.emplace_back(brackets);
    }
    return;
  } else {
    rep(i, 0, 2) {
      vector<int> new_brackets = brackets;
      new_brackets.emplace_back(i);
      f(new_brackets);
    }
  }
}

int main() {
  cin >> N;
  vector<int> brackets;
  f(brackets);
  if(bracket_vec.size() == 0) {
    cout << endl;
    return 0;
  }
  for (auto brackets : bracket_vec) {
    for (auto bracket : brackets) {
      if (bracket == OPEN) {
        cout << "(";
      } else {
        cout << ")";
      }
    }
    cout << endl;
  }
  return 0;
}
