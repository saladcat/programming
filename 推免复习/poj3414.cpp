//
// Created by 朱世杨 on 2019-06-29.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int A, B, C;
int contentA, contentB;

void fill(int i) {
    if (i == 1) {
        contentA = A;
    }
    if (i == 2) {
        contentB = B;
    }
}

void drop(int i) {
    if (i == 1) {
        contentA = 0;
    }
    if (i == 2) {
        contentB = 0;
    }

}

void pour(int i, int j) {
    if (i == 1 && j == 2) {
        //case 1
        if (contentA < (B - contentB)) {
            contentA = 0;
            contentB = contentA + contentB;
            return;
        }
        //case 2
        if (contentA > (B - contentB)) {
            contentA = contentA - (B - contentB);
            contentB = B;
            return;
        }
    }
    if (i == 2 && j == 1) {
        if (contentB < (A - contentA)) {
            contentB = 0;
            contentA = contentA + contentB;
            return;
        }
        if (contentB > (A - contentA)) {
            contentB = contentB - (A - contentA);
            contentA = A;
            return;
        }
    }
}


struct Node {
    int contA;
    int contB;
    int opcode;// 1-fill 2-drop 3-A->B(B的取相反数)
    int step;
    Node *lastNode;
};

queue<Node *> que;
Node *curNode = nullptr;

void prt(Node *ptr) {
    if (ptr == nullptr || ptr->opcode == 0) {
        return;
    }
    prt(ptr->lastNode);
    string str;
    switch (ptr->opcode) {
        case 1:
            str = "FILL(1)";
            break;
        case 2:
            str = "DROP(1)";
            break;
        case 3:
            str = "POUR(1,2)";
            break;
        case -1:
            str = "FILL(2)";
            break;
        case -2:
            str = "DROP(2)";
            break;
        case -3:
            str = "POUR(2,1)";
            break;
        default:
            break;
    }
    cout << str << endl;
}

void op(int opcode) {
    switch (opcode) {
        case 1:
            fill(1);
            break;
        case 2:
            drop(1);
            break;
        case 3:
            pour(1, 2);
            break;
        case -1:
            fill(2);
            break;
        case -2:
            drop(2);
            break;
        case -3:
            pour(2, 1);
            break;
        default:
            break;
    }

}

void freshContent() {
    contentA = curNode->contA;
    contentB = curNode->contB;
}

Node *nxtNode;

Node *newNode() {
    nxtNode = new Node();
    nxtNode->contA = contentA;
    nxtNode->contB = contentB;
    nxtNode->step = curNode->step + 1;
    nxtNode->lastNode = curNode;
    return curNode;
}

void bfs() {
    Node *node = new Node();
    node->lastNode = nullptr;
    queue<int> a;
    a.push(1);
    que.push(node);
    while (!que.empty()) {
        curNode = que.front();
        que.pop();
        if (curNode->contA == C || curNode->contB == C) {
            prt(curNode);
            break;
        }
        freshContent();
        for (int i = 1; i < 4; ++i) {
            op(i);
            que.push(newNode());
            op(-i);
            que.push(newNode());
        }
    }
}

int main() {
    cin >> A >> B >> C;
    bfs();
    return 0;
}