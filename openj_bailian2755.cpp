//
// Created by zhu on 2018/3/10.
//
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int dat[25];
int dp[25][45]; //dp[i][j]前i个物体达到体积j有多少种
// dp[i][j]=dp[i-1][j-dat[i]]

int main() {
    int n;
//    fstream cin("data.dat");
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(dat, 0, sizeof(dat));
    for (int i = 1; i <= n; i++) {
        cin >> dat[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][dat[i]] = 1;
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 40; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= dat[i]) {
                dp[i][j] += dp[i - 1][j - dat[i]];
            }
        }
    }
    cout << dp[n][40] << endl;
    return 0;
}
