//
// Created by zhu on 2018/7/10.
//

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 20005;
int n;
int m;
vector<int> a;

long long greaterCount(int m);

int main() {
    cin >> n >> m;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << greaterCount(m) - greaterCount(m + 1) << endl;
}

long long greaterCount(int m) {
    vector<int> s(2 * n + 1);
    int sum = n;
    long long result = 0;
    s[sum] = 1;
    long long add = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < m) {
            sum--;
            add -= s[sum];
        } else {
            add += s[sum];
            sum++;
        }
        result += add;
        s[sum]++;
    }
    return result;
}
