//
// Created by 朱世杨 on 2019-03-17.
//

//
// Created by 朱世杨 on 2019-03-17.
//

#include <iostream>
#include <algorithm>

#define min(a, b) a<b ? a:b

using namespace std;


int main() {
    long long x, y;
    while (cin >> x >> y) {
        long long res = 0;
        if (x > 0) {
            long long n = 2 * x - 1;
            res = n * n + (n - 1) / 2;
        } else if (x < 0) {
            long long n = -2 * x;
            res = n * n + n / 2;
        } else {
            res = 0;
        }
        res -= y;
        cout << res << endl;
    }
    return 0;
}