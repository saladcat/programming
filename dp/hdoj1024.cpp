//
// Created by 朱世杨 on 2019-03-18.
//
#include <iostream>
#include <string>

#define ll long long
#define INF 0x3f3f3f3f
#define MAX 1000005
#define ms(x, n) memset(x,n,sizeof(x));
using namespace std;

ll input[MAX];
int m, n;// m代表找m对，n代表数字的个数
ll dp[MAX]; //dp[i] 前i个数之和最大的
// dp[i] = max(dp[i-1],dp[i-1]+input[i])
int main() {
    while (cin >> m >> n) {
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }
        ms(dp, 0);
        for (int i=0;)
    }

}