//
// Created by 朱世杨 on 2019-03-04.
// AC dijkstra 划分区间

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>

#define INF 0x3f3f3f3f
using namespace std;
struct ReplaceInfo {
    int id;
    int price;
};
struct Gift {
    int id;
    int price;
    int replaceNum;
    int place;
    vector<ReplaceInfo *> replaceList;
};
int M, N;
int P, L, X;
int T, V;
Gift gift[105];
int distMaze[105][105];
int vis[105];
int dist[105];
int globeLowCost = INF;

void readData() {
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P >> L >> X;
        gift[i].id = i;
        gift[i].price = P;
        gift[i].place = L;
        gift[i].replaceNum = X;
        for (int j = 0; j < X; j++) {
            cin >> T >> V;
            ReplaceInfo *temp = new ReplaceInfo;
            temp->id = T;
            temp->price = V;
            gift[i].replaceList.push_back(temp);
        }
    }
}

void initData() {
    memset(distMaze, INF, sizeof(distMaze));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < gift[i].replaceNum; j++) {
            int id = gift[i].replaceList[j]->id;
            distMaze[id][i] = gift[i].replaceList[j]->price;
        }
        distMaze[0][i] = gift[i].price;
    }
}


int dijkstra(int lowBoundPlace, int highBoundPlace) {
    memset(vis, 0, sizeof(vis));
    // init vis
    for (int i = 1; i <= N; i++) {
        if (gift[i].place < lowBoundPlace || gift[i].place > highBoundPlace) {
            vis[i] = 1;
        } else {
            dist[i] = distMaze[0][i];
        }
    }
    // find min dist index
    for (int time = 0; time < N; time++) {
        int minIndex = -1;
        int minDist = INF;
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0 && dist[i] < minDist) {
                minIndex = i;
                minDist = dist[i];
            }
        }
        if (minIndex < 0) {
            break;
        }
        vis[minIndex] = 1;
        // update minDist cause of  every other point through minPoint
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0 && dist[i] > minDist + distMaze[minIndex][i]) {
                dist[i] = minDist + distMaze[minIndex][i];
            }
        }
    }
    return dist[1];
}

int main() {
    readData();
    initData();
    for (int i = 0; i <= M; i++) {
        int lowBound = gift[1].place - M + i;
        int highBound = gift[1].place + i;
        int curLowCost = dijkstra(lowBound, highBound);
        if (globeLowCost > curLowCost) {
            globeLowCost = curLowCost;
        }
    }
    cout << globeLowCost << endl;
    return 0;
}