#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>
#include<stdlib.h>
#include<queue>

using namespace std;


int main() {
    int a;
    int dp[100005][15];
    int time, pos;
    int n;

    while (scanf("%d", &n) == 1 && n) {
        int endTime = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &pos, &time);
            dp[time][pos]++;
            if (time > endTime) {
                endTime = time;
            }
        }
        for (int i = endTime - 1; i >= 0; i--) {
            dp[i][0] += max(dp[i + 1][1], dp[i + 1][0]);
            for (int j = 1; j <= 10; j++) {
//                int temp = 0;
//                temp = max(dp[i + 1][j], dp[i + 1][j + 1]);
//                temp = max(dp[i + 1][j - 1], temp);
//                dp[i][j] += temp;
                dp[i][j] += max(dp[i + 1][j],
                                max(dp[i + 1][j + 1],
                                    dp[i + 1][j - 1]));
            }
        }
        printf("%d\n", dp[0][5]);
    }
    return 0;
}