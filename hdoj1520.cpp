//
// Created by zhu on 2018/3/7.
//
/*
 * 简单树状DP
 * 树状DP就是将DP放在树上
 * 一般是从底部算起，最终状态放在根上
 * 其他的普通DP差不多，一般会用到DFS
 * */
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int maxN = 6005;


struct Staff {
    int father = -1;
    vector<int> son;
    int point;
};

Staff staffs[maxN];
int dp[maxN][2]; //dp[i][j]表示第i个人来或不来(1/0)时最大的活跃因子

void dfs(int root) {
    if (staffs[root].son.empty()) {
        dp[root][0] = 0;
        dp[root][1] = staffs[root].point;
        return;
    }
    for (const auto &item :staffs[root].son) {
        dfs(item);
    }
    dp[root][0] = 0;
    dp[root][1] = staffs[root].point;
    for (const auto &item :staffs[root].son) {
        dp[root][0] += max(dp[item][0], dp[item][1]);
        dp[root][1] += dp[item][0];
    }
}

int main() {
//    fstream is("data.dat");
    int N;
    while (cin >> N && N) {
        for (int i = 1; i <= N; i++) {
            staffs[i].father = -1;
            staffs[i].son.clear();
            cin >> staffs[i].point;
        }
        int temFather, temSon;
        while (cin >> temSon >> temFather && (temSon + temFather) != 0) {
            staffs[temFather].son.push_back(temSon);
            staffs[temSon].father = temFather;
        }
        int root;
        for (root = 1; root <= N; root++) {
            if (staffs[root].father == -1) {
                break;
            }
        }
        dfs(root);
        cout << max(dp[root][0], dp[root][1])<<endl;
    }
    return 0;
}