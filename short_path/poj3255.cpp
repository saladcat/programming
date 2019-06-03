//
// Created by 朱世杨 on 2019-06-03.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory>

#define MAX 5010
#define INF 0x3f3f3f3f
#define CostDest pair<int,int>
using namespace std;
int N, R;//N节点数量，R边的数量
int maze[MAX][MAX];//距离矩阵
int dist1[MAX]; //最短
int dist2[MAX];//次短
int vis[MAX];// 不能用vis剪枝，因为vis限制了求次短路径
typedef struct Edge {
    int src;
    int dest;
    int weight;

    bool operator<(const Edge a) const {
        return weight < a.weight;
    }
} Edge;

void readData() {
    memset(dist1, INF, sizeof(dist1));
    memset(maze, INF, sizeof(maze));
    memset(dist2, INF, sizeof(dist2));
    memset(vis, 0, sizeof(vis));
    cin >> N >> R;
    int x, y;
    for (int i = 0; i < R; i++) {
        cin >> x >> y;
        cin >> maze[x - 1][y - 1];
    }
}

void solve() {
    priority_queue<CostDest, vector<CostDest >, greater<CostDest>> que;
    que.push(CostDest(0, 0));
    dist1[0] = 0;
//    dist2[0] = 0;
    while (!que.empty()) {
        CostDest costDest = que.top();
        que.pop();
        int cost = costDest.first;
        int dest = costDest.second;
        if (dist2[dest] < cost) {//剪枝，如果到2的花费，比之前次短的还多，那就不用了
            continue;
        }
        for (int i = 0; i < N; i++) {// foreach node
            int curMinDist = cost + maze[dest][i];
            if (dist1[i] > curMinDist) {
                swap(dist1[i], curMinDist); // 记录最近距离，将次近距离放在curMinDist里面
                que.push(CostDest(dist1[i], i));
            }
            if (dist2[i] > curMinDist) {
                dist2[i] = curMinDist;
                que.push(CostDest(dist2[i], i));
            }
        }
    }
    printf("%d\n", dist2[N - 1]);
}


int main() {
    readData();
    solve();
    return 0;
}

