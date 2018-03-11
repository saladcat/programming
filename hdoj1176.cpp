
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>

using namespace std;
int dp[100005][15];

int main(void) {
    int time, pos;
    int n;

    while (scanf("%d", &n) == 1 && n) {
        memset(dp, 0, sizeof(dp));
        int end_Time = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &pos, &time);
            dp[time][pos]++;
            if (time > end_Time) {
                end_Time = time;
            }
        }
        for (int i = end_Time - 1; i >= 0; i--) {
            dp[i][0] += max(dp[i + 1][1], dp[i + 1][0]);
            for (int j = 1; j <= 10; j++) {
                dp[i][j] += max(dp[i + 1][j],
                                max(dp[i + 1][j + 1],
                                    dp[i + 1][j - 1]));
            }
        }
        printf("%d\n", dp[0][5]);
    }
    return 0;
}