//
// Created by 朱世杨 on 2019-03-02.
//

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;

    double getDistance(const Point &point) {
        double sum_sqrt = (x - point.x) * (x - point.x) + (y - point.y) * (y - point.y);
        return sqrt(sum_sqrt);
    }
};

double dist[200][200];
double forgDist[200];
int vis[200];
Point points[200];

int n;


void readData() {
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void initData() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = points[i].getDistance(points[j]);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
}

void dijkstra() {
    for (int i = 0; i < n; i++) {
        forgDist[i] = dist[0][i];
    }
    forgDist[0] = 0;
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        double minDist = 99999;
        for (int j = 0; j < n; j++) {//选出离当前选出的点最近的点
            if (vis[j] == 0 && minDist > forgDist[j]) {
                minDist = forgDist[j];
                minIndex = j;
            }
        }
        vis[minIndex] = 1; //加入集合
        for (int k = 0; k < n; ++k) {//更新通过新加入点能达到的新的forgDist
            if (vis[k] == 0) {
                forgDist[k] = min(max(forgDist[minIndex], dist[minIndex][k]), forgDist[k]);
            }
        }
    }
}

int main() {
    int time = 1;
    while (scanf("%d", &n) && n != 0) {
        readData();
        initData();
        dijkstra();
        printf("Scenario #%d\n", time);
        printf("Frog Distance = %.3lf\n\n", forgDist[1]);
        time++;
    }
    return 0;
}