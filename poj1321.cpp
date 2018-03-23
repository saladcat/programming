//
// Created by zhu on 2018/3/13.
//
//todo
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>
// 有一个n*n的棋盘，放k个棋子，使得每一行列都只存在一个棋子，
// （有些棋子会不能放棋子，用.表示，能放的用#表示 ）
using namespace std;

void dfs(int scanRows);

int board[10][10];
int isPlacedCols[10];
int cnt, pieceCnt;
int n, k;

int main() {
//    fstream is("data.dat");
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        memset(board, 0, sizeof(board));
        memset(isPlacedCols, 0, sizeof(isPlacedCols));
        cnt = 0;
        pieceCnt = 0;
        for (int i = 0; i < n; i++) {//预处理，使得不能放的地方为0，能放的为1
            cin.get();
            for (int j = 0; j < n; j++) {
                char tem = static_cast<char>(cin.get());
                if (tem == '#') {
                    board[i][j] = 1;
                }
            }
        }
        dfs(0);
        cout << cnt << endl;
    }
    return 0;
}

// 使用dfs进行搜索
void dfs(int scanRows) {
    if (pieceCnt == k) {
        cnt++;
        return;
    }
    if (scanRows >= n) {
        return;
    }
    for (int j = 0; j < n; j++) {
        if (board[scanRows][j] == 1 && isPlacedCols[j] == 0) {
            isPlacedCols[j] = 1;
            pieceCnt++;
            dfs(scanRows + 1);
            pieceCnt--;
            isPlacedCols[j] = 0;
        }
    }
    dfs(scanRows + 1);
    return;
}
















