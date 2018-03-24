//
// Created by zhu on 2018/3/24.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
    int pos;
    int time;
};


int N, K;
Node cur;
queue<Node> queue1;
int vis[100000];

void bfs();

int main() {//todo
//    fstream fis("data.dat");
    while (cin >> N >> K) {
        memset(vis, 0, sizeof(vis));
        if (N >= K) {
            cout << N - K << endl;
            continue;
        }
        while (!queue1.empty()) {
            queue1.pop();
        }
        cur.pos = N;
        cur.time = 0;
        queue1.push(cur);
        bfs();
        cout << cur.time << endl;
    }
    return 0;
}


void bfs() {
    while (!queue1.empty()) {
        cur = queue1.front();
        queue1.pop();
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
            if (vis[next.pos] == 0 && next.pos >= 0 && next.pos <= 100000) {
                vis[next.pos] = 1;
                queue1.push(next);
            }
        }
    }
}

































