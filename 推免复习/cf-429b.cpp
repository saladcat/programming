//
// Created by zhu on 2019/9/8.
//

#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <cstring>

#define MAX 1005

using namespace std;
int n, m;
int a[MAX][MAX];
int dp[4][MAX][MAX];

int main() {
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    // dp calc
    // left up
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
        }
    }
    //left down
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j - 1]) + a[i][j];
        }
    }
    //right down
    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j + 1]) + a[i][j];
        }
    }
    // right left
    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            dp[3][i][j] = max(dp[3][i - 1][j], dp[3][i][j + 1]) + a[i][j];
        }
    }
    // foreach inter-point
    int ans = -1;
    // 思考：原实现为dp[k][i][j] k in 0-3, 但这样未考虑可能不同方向的入口同一个坐标上，会出现重复，不符合我们的要求
    // 因此考虑该四个点是如何进入的，左上角的可能从左边和上面进入，以此类推，所以一共有两种情况。
    // for 循环必须从[2,n) 不知道为什么 todo
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            ans = max(ans, dp[0][i - 1][j] + dp[1][i][j - 1]
                           + dp[2][i + 1][j] + dp[3][i][j + 1]);
            ans = max(ans, dp[0][i][j - 1] + dp[1][i + 1][j]
                           + dp[2][i][j + 1] + dp[3][i - 1][j]);
        }
    }
    cout << ans << endl;
    return 0;
}