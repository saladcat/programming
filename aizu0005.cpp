//
// Created by zhu on 2018/3/10.
//

#include <iostream>

#include <algorithm>

using namespace std;
using ll=long long;

ll gcd(ll a, ll b);

int main(void) {
    ll a, b;
    while (cin >> a >> b) {
        ll gcd_a_b = gcd(a, b);
        cout << gcd_a_b << " " << a / gcd_a_b * b << endl;
    }
    return 0;
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
