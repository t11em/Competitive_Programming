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
#define rrep(i, m, n) for (int i = (int)(n-1); i >= (int)(m); --i)

template <typename T, typename U>
pair<T, U> tp(T a, U b) {
    return std::make_pair(a, b);
}

constexpr int MOD = 1000000007;

int main() {
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    map<string , int> m;
    m["H"] = 0;
    m["2B"] = 0;
    m["3B"] = 0;
    m["HR"] = 0;
    m[s1]++;
    m[s2]++;
    m[s3]++;
    m[s4]++;
    string ans = "Yes";
    for(const auto &item: m){
        if (item.second != 1)ans = "No";
    }
    cout << ans << endl;
    return 0;
}
