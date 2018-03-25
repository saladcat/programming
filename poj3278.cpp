#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
// 完全不明白我写的为什么不对
using namespace std;

int visit[100005] = {0};

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(visit, 0, sizeof(visit));
        queue<int> q;
        q.push(n);
        int t;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            if (t == m) {
                break;
            }
            if (t > 0 && !visit[t - 1]) {
                int z;
                z = t - 1;
                visit[z] = visit[t] + 1;
                q.push(z);
            }
            if (t < m && !visit[t + 1]) {
                int z;
                z = t + 1;
                visit[z] = visit[t] + 1;
                q.push(z);
            }
            if (t * 2 < 100005 && !visit[t * 2]) {
                int z;
                z = t * 2;
                visit[z] = visit[t] + 1;
                q.push(z);
            }
        }
        printf("%d\n", visit[m]);
    }
    return 0;
}









/*
//
// Created by zhu on 2018/3/24.
//


#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int Nmax = 100005;
struct Node {
    int pos;
    int time;
};


int N, K;
Node cur;
queue<Node> que;
int vis[100000];

void bfs();

int main() {//todo
//    fstream fis("data.dat");
    while (cin >> N >> K) {
        if (N >= K) {
            cout << N - K << endl;
            continue;
        }
        memset(vis, 0, sizeof(vis));
        while (!que.empty()) {
            que.pop();
        }
        cur.pos = N;
        cur.time = 0;
        que.push(cur);
        vis[cur.pos] = 1;
        bfs();
        cout << cur.time << endl;
    }
    return 0;
}


void bfs() {
    while (!que.empty()) {
        cur = que.front();
        que.pop();
        if (cur.pos == K) {
            break;
        }
        Node next;
        for (int i = 0; i < 3; i++) {
            next.time = cur.time + 1;
            if (i == 0) {
                next.pos = cur.pos + 1;
            } else if (i == 1) {
                next.pos = cur.pos * 2;
            } else if (i == 2) {
                next.pos = cur.pos - 1;
            }
            if (next.pos >= 0 && next.pos <= 100000 && vis[next.pos] == 0) {
                vis[next.pos] = 1;
                que.push(next);
            }
        }
    }
}

































*/
