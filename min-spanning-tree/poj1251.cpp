//
// Created by 朱世杨 on 2019-03-04.
// prim
#include <iostream>
#include <set>
#include <algorithm>

#define INF 0x3f3f3f3f
using namespace std;
int distMaze[30][30];
int dist[30];
int vis[30];
int res;
int nodeNum;

int getIndex(char input) {
    return input - 'A';
}

bool readData() {
    memset(distMaze, INF, sizeof(distMaze));
    cin >> nodeNum;
    if (nodeNum == 0) {
        return false;
    } else {
        for (int k = 0; k < nodeNum - 1; k++) {
            char nodeChar;
            int archNum;
            cin >> nodeChar >> archNum;
            for (int i = 0; i < archNum; i++) {
                char nxtNodeChar;
                int distance;
                cin >> nxtNodeChar >> distance;
                distMaze[getIndex(nodeChar)][getIndex(nxtNodeChar)] = distance;
                distMaze[getIndex(nxtNodeChar)][getIndex(nodeChar)] = distance;
            }
        }
        return true;
    }
}

void initData() {
    memset(vis, 0, sizeof(vis));
}

void prim() {
    vis[0] = 1;
    memcpy(dist, distMaze[0], sizeof(dist));
    for (int k = 0; k < nodeNum; k++) {
        // findMinIndex
        int minIndex = -1;
        int minDist = INF;
        for (int i = 0; i < nodeNum; i++) {
            if (vis[i] == 0 && minDist > dist[i]) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            break;
        }
        vis[minIndex] = 1;
        for (int i = 0; i < nodeNum; i++) {
            if (vis[i] == 0 && dist[i] > distMaze[minIndex][i]) {
                dist[i] = distMaze[minIndex][i];
            }
        }
    }
    res = 0;
    for (int i = 1; i < nodeNum; i++) {
        res += dist[i];
    }
}


int main(void) {
    while (readData()) {
        initData();
        prim();
        cout << res << endl;
    }
    return 0;
}