//
// Created by 朱世杨 on 2019-03-01.
//
// simple bfs

#include <iostream>

#include <string>
#include <queue>
#include <memory>
#include <cstring>
using namespace std;

struct Node {
    Node *lastNode;
    int x;
    int y;
    int cntStep;

    Node(Node *lastNode, int x, int y, int cntStep) {
        this->lastNode = lastNode;
        this->x = x;
        this->y = y;
        this->cntStep = cntStep;
    }
};

int matrix[5][5];
int usedMatrix[5][5];

int M, N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
Node *curNode;

queue<Node *> queueList;

bool isLegalPos(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return false;
    } else {
        if (usedMatrix[x][y] == 1 || matrix[x][y] == 1) {
            return false;
        } else {
            return true;
        }
    }
}

void initData(void) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    memset(usedMatrix, 0, sizeof(usedMatrix));
}

void print(Node *node) {
    if (node == NULL) {
        return;
    } else {
        print(node->lastNode);
    }
    cout << "(" << node->x << ", " << node->y << ")" << endl;
}

void bfs(void) {
    queueList.push(new Node(NULL, 0, 0, 0));
    usedMatrix[0][0] = 1;
    while (!queueList.empty()) {
        curNode = queueList.front();
        queueList.pop();
        if (curNode->x == 4 && curNode->y == 4) {
            break;
        } else {
            for (int i = 0; i < 4; i++) {
                int nxtX = curNode->x + dx[i];
                int nxtY = curNode->y + dy[i];
                if (isLegalPos(nxtX, nxtY)) {
                    Node *nextNode = new Node(curNode, nxtX, nxtY, curNode->cntStep + 1);
                    queueList.push(nextNode);
                }
            }
        }
    }
    print(curNode);
}


int main(void) {
    M = 5;
    N = 5;
    initData();
    bfs();
    return 0;
}