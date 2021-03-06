#include <cassert>
#include <cmath>
#include <cstddef>

#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using schar  = signed char;
using uchar  = unsigned char;
using shrt   = short int;
using ushrt  = unsigned short int;
using uint   = unsigned int;
using ulong  = unsigned long int;
using llong  = long long int;
using ullong = unsigned long long int;
using flt    = float;
using dbl    = double;
using ldbl   = long double;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cerr.tie(nullptr);
    cin.tie(nullptr);

    ullong n;
    cin >> n;
    vector<pair<string, llong>> game(n);
    map<string, llong> name_score;

    for (auto &[name, score] : game) {
        cin >> name >> score;
        name_score[name] += score;
    }

    const llong m = max_element(name_score.cbegin(), name_score.cend(), [](
        const pair<string, llong> &a,
        const pair<string, llong> &b
    ) constexpr noexcept -> bool {
        return a.second < b.second;
    })->second;

    set<string> winner;
    for_each(name_score.cbegin(), name_score.cend(), [&winner, m](
        const pair<string, llong> &a
    ) constexpr noexcept -> void {
        if (a.second == m)
            winner.insert(a.first);
    });

    name_score.clear();
    for (const auto &[name, score] : game) {
        const llong current_score = name_score[name] += score;
        if (current_score >= m && winner.find(name) != winner.end()) {
            cout << name << '\n';
            break;
        }
    }

    return 0;
}
