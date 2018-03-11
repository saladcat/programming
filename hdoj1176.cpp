//
// Created by zhu on 2018/3/10.
//


#include <iostream>

#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100000;

struct Pie {
    int pos;
    int time;
};

int dp[12][MAX]; //dp[i][j] 第j秒在i的位置上时最多能接到的馅饼数
// dp[i][j]= max(dp[i][j-1]+sum(dat[位置在i-1到i+1时间在j的数量],dp[
int dat[12][MAX];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        int pos, time;
        memset(dat, 0, sizeof(dat));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pos, &time);
            dat[pos][time]++;
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < 12; i++) {
                dp[i][j] =
                        max(dp[i - 1][j - 1],
                            max(dp[i][j - 1],
                                dp[i + 1][j - 1]))
                        + dat[i][j] + dat[i - 1][j] + dat[i + 1][j];
            }
        }
    }

    return 0;
}
