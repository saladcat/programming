//
// Created by zhu on 2018/3/13.
//
//todo
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

bool isAllow2Place(int i, int j);

void dfs(int leftNum);

int board[10][10];
int cnt;
int n, k;

int main() {
    fstream is("data.dat");
    while (is >> n >> k && !(n == -1 && k == -1)) {
        memset(board, 0, sizeof(board));
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            is.get();
            for (int j = 1; j <= n; j++) {
                char tem = static_cast<char>(is.get());
                if (tem == '#') {
                    board[i][j] = 1;
                } else if (tem == '.') {}
                else {
                    cout << "djsklajdkl" << endl;
                }
            }
        }
        dfs(k);
        cout << cnt << endl;
    }
    return 0;
}

bool isAllow2Place(int i, int j) {
    for (int row = 1; row <= n; row++) {
        if (board[row][j] == -1) {
            return false;
        }
    }
    for (int col = 1; col <= n; col++) {
        if (board[i][col] == -1) {
            return false;
        }
    }
    return true;
}

void dfs(int leftNum) {
    if (leftNum == 0) {
        cnt++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 1) {
                if (isAllow2Place(i, j)) {
                    board[i][j] = -1;
                    dfs(leftNum - 1);
                    board[i][j] = 1;
                }
            }
        }
    }
}















