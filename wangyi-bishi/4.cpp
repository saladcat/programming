//
// Created by 朱世杨 on 2019-03-17.
//


#include <iostream>
#include <algorithm>

#define min(a, b) a<b ? a:b
#define max(a, b) a>b ? a:b

using namespace std;
int dp[105][1005];
int N, H;
int x, y, z;
int x_list[105];
int y_list[105];
int z_list[105];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        x_list[i] = x;
        y_list[i] = y;
        z_list[i] = z;
    }
    for (int i = 1; i < N; i++) {
        for (int k = y_list[i]; k < H; k++) {
            dp[k][i] = max(dp[k - y_list[i]][i - 1] + y_list[i], dp[k - z_list[i]][i - 1]);
        }
    }
    int res = *max_element(*dp, *dp + sizeof(dp) / sizeof(int));
    cout << res << endl;
}