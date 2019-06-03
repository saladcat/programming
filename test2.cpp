//
// Created by 朱世杨 on 2019-03-23.
//
#include <iostream>
#include <memory>
#define MAXN 100
#define MAXM 200
#define INF 0x3f3f3f3f
// dp[i][j] 表示前i个硬币中，组成额度为j的最少用的硬币数量
// dp[i][j] = min(dp[i-1][j-a[i]]+1,dp[i-1][j]);


using namespace std;

int dp[MAXN][MAXM];


int main() {

}