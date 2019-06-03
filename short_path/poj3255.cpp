//
// Created by 朱世杨 on 2019-06-03.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory>
#include <vector>

#define MAX 5005
#define INF 0x3f3f3f3f
#define CostDest pair<int,int>
using namespace std;
struct Edge {
    int dest;
    int weight;
};
int N, R;//N节点数量，R边的数量
int dist1[MAX]; //最短
int dist2[MAX];//次短
vector<Edge> maze[MAX];

void readData() {
    memset(dist1, INF, sizeof(dist1));
    memset(dist2, INF, sizeof(dist2));
    cin >> N >> R;
    int x, y, cost;
    for (int i = 0; i < R; i++) {
        cin >> x >> y >> cost;
        Edge edge1;
        edge1.dest = y - 1;
        edge1.weight = cost;
        Edge edge2;
        edge1.dest = x - 1;
        edge1.weight = cost;
        maze[x - 1].push_back(edge1);
        maze[y - 1].push_back(edge2);
    }
}

void solve() {
    priority_queue<CostDest, vector<CostDest >, greater<CostDest>> que;
    for (int i = 0; i <= N; i++) {
        dist1[i] = INF;
        dist2[i] = INF;
    }
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
        for (int i = 0; i < maze[dest].size(); i++) {
            int newDest = maze[dest][i].dest;
            int curMinDist = cost + maze[dest][i].weight;
            if (dist1[newDest] > curMinDist) {
                swap(dist1[newDest], curMinDist); // 记录最近距离，将次近距离放在curMinDist里面
                que.push(CostDest(dist1[newDest], newDest));
            }
            if (dist2[newDest] > curMinDist) {
                dist2[newDest] = curMinDist;
                que.push(CostDest(dist2[newDest], newDest));
            }
        }
    }
    printf("%d\n", dist2[N - 1]);
}


int main() {
    while (~scanf("%d%d", &N, &R)) {
        for (int i = 0; i <= N; i++)
            maze[i].clear();
        int u, v, cost;
        Edge tmp;
        for (int i = 0; i < R; i++) {
            scanf("%d%d%d", &u, &v, &cost);
            tmp.dest = v-1;
            tmp.weight = cost;
            maze[u-1].push_back(tmp);
            tmp.dest = u-1;
            maze[v-1].push_back(tmp);
        }
        solve();
    }

    return 0;
}

