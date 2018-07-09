//
// Created by zhu on 2018/7/9.
//


#include <iostream>
#include <queue>

#define DEP1 0
#define DEP2 1
#define FORB 2
#define ROAD 3
#define KFC 4

using namespace std;

const int MAX = 205;
struct Node {
  int x;
  int y;
  int step;
};
int ROW, COL;
int MAP[MAX][MAX];
int vis1[MAX][MAX];
int vis2[MAX][MAX];
queue<Node> que1;
queue<Node> que2;
Node dep1;
Node dep2;
Node curNode1;
Node curNode2;
int curX;
int curY;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void pop1() {
    curNode1 = que1.front();
    que1.pop();
}

void pop2() {
    curNode2 = que2.front();
    que2.pop();
}

void bfs(void);

int main(void) {
    while (cin >> ROW >> COL) {//loop
        // get input data block
        memset(vis1, 0, sizeof(vis1));
        memset(MAP, 0, sizeof(MAP));
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; ++j) {
                int tem;
                cin >> tem;
                switch (tem) {
                    case 'Y':MAP[i][j] = DEP1;
                        dep1.x = i;
                        dep1.y = j;
                        dep1.step = 0;
                        break;
                    case 'M':MAP[i][j] = DEP2;
                        dep2.x = i;
                        dep2.y = j;
                        dep2.step = 0;
                        break;
                    case '#':MAP[i][j] = FORB;
                        break;
                    case '.':MAP[i][j] = ROAD;
                        break;
                    case '@':MAP[i][j] = KFC;
                        break;
                    default:throw (1);
                        break;
                }
            }
        }
        // end block

    }
    return 0;
}

void bfs(void) {
    que1.push(dep1);
    que2.push(dep2);
    while (!(que1.empty() && que2.empty())) {
        pop1();
        int nxtX, nxtY;
        for (int i = 0; i < 4; i++) {
            nxtX = curNode1.x + dx[i];
            nxtY = curNode1.y + dy[i];
            if ((nxtX < 0 || nxtY < 0 || nxtX >= ROW || nxtY >= COL)
                    || vis1[nxtX][nxtY] == 1 || MAP[nxtX][nxtY] == FORB) {
                continue;
            }
            Node temNode;
            temNode.x = nxtX;
            temNode.y = nxtY;
            temNode.step = curNode1.step + 1;
        }
    }
}
