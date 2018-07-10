//
// Created by zhu on 2018/7/10.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    int n, median;
    cin >> n >> median;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    map<int, int> MAP;
    MAP[0] = 1;
    bool has = false;
    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (input[i] < median)
            sum--;
        else if (input[i] > median)
            sum++;

        if (input[i] == median)
            has = true;
        if (has)
            ans += MAP[sum] + MAP[sum - 1];
        else
            MAP[sum]++;
    }

    cout << ans << endl;
}