//
// Created by zhu on 2018/7/10.
//
//dp[i] means the

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    int n = input.length();
    int lastIndex[3] = {0, -1, -1};
    vector<int> dp(n + 1);
    int prefixMod = 0;
    for (int i = 1; i <= n; i++) {
        prefixMod = (prefixMod + input[i - 1] - '0') % 3;
        dp[i] = dp[i - 1];
        if (lastIndex[prefixMod] != -1) {
            dp[i] = max(dp[i], dp[lastIndex[prefixMod]] + 1);
        }
        lastIndex[prefixMod] = i;
    }
    cout << dp[n] << endl;
    return 0;
}


