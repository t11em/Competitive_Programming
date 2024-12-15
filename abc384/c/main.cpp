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

std::string generate_name(std::bitset<5> b) {
    std::string name = "";
    if (b[0]) {
        name += "A";
    }
    if (b[1]) {
        name += "B";
    }
    if (b[2]) {
        name += "C";
    }
    if (b[3]) {
        name += "D";
    }
    if (b[4]) {
        name += "E";
    }
    return name;
}
int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    // std::vector<int> v = {a, b, c, d, e};
    // sort(v.begin(), v.end());
    // std::map<string, int> m;
    // m["0"] = v[0];
    // m["1"] = v[1];
    // m["2"] = v[2];
    // m["3"] = v[3];
    // m["4"] = v[4];

    auto comparer =

        [](std::pair<int, string> a, std::pair<int, string> b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };
    priority_queue<std::pair<int, string>, std::vector<std::pair<int, string>>,
                   decltype(comparer)>
        pq(comparer);

    for (int i = 0; i < (1 << 5); i++) {
        bitset<5> bits(i);
        int sum = 0;
        if (bits[0]) {
            sum += a;
        }
        if (bits[1]) {
            sum += b;
        }
        if (bits[2]) {
            sum += c;
        }
        if (bits[3]) {
            sum += d;
        }
        if (bits[4]) {
            sum += e;
        }
        auto name = generate_name(bits);
        pq.push(tp(sum, name));
    }

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        cout << p.second << endl;
    }
    return 0;
}
