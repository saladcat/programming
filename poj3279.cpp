//
// Created by zhu on 2018/3/25.
//不知道为什么WA TODO
/*  https://blog.csdn.net/STILLxjy/article/details/52155213
    题目大意：有一个 M * N 的格子，每个格子可以翻转正反面，它们有一面是黑色，另一面是白色。黑色翻转之后变成白色
    ，白色翻转之后则变成黑色。
 游戏要做的是把所有的格子翻转为白色。不过因为牛蹄很大，所以每次翻转一个格子，与它上下左右相邻接的格子也会被翻转。
    求用最小的步数完成时，每个格子的翻转次数。最小步数的解有多个时，输出字典序最小的一组；解不存在的话，
    则输出IMPOSSIBLE

    题目样例：0表示白色，1表示黑色

            1 0 0 1
            0 1 1 0
            0 1 1 0
            1 0 0 1

    题目思路：首先，同一个格子翻转两次就会恢复原状，所以多次翻转是多余的。此外，翻转的格子的集合相同的话，
    其次序是无关紧要的。
    不妨先指定好最上面一行的翻转方法。此时，能翻转（1，1）的只剩下了（2，1），所以可以直接判断（2，1）
        是否需要翻转。类似的（2，1）~（2，N）都能这样判断，
    如此反复下去就能确定所有格子的翻转方法，最后（M,1）~(M,N)并非全为白色，则意味着不存在可行的操作方法。

            像这样，先确定第一行的翻转方式，然后可以很容易判断这样是否存在解以及解的最小步数是多少，
            这样将第一行的所有翻转方式都尝试一次就能求出整个问题的最小步数。这个算法中最上面
        一行的翻转方式共有2^N种，复杂度为O（M * N * 2^N）
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <queue>

using namespace std;
int M, N;
const int maxMN = 17;
int board[maxMN][maxMN];
int curStateBoard[maxMN][maxMN];
int res[maxMN][maxMN];
int opt[maxMN][maxMN];
int optCnt = 0xffffff;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void reverse(int i, int j);

void step(int i, int j);

int main() {
//    fstream is("data.dat");
    while (cin >> M >> N) {
        memset(board, 0, sizeof(board));
        memset(opt, 0, sizeof(opt));
        optCnt = 0xffffff;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        for (int state = 0; state < (1 << N); state++) {
            int cnt = 0;
            memset(res, 0, sizeof(res));
            memcpy(curStateBoard, board, sizeof(curStateBoard));
            for (int cols = 0; cols < N; cols++) {
                int tem = state >> cols;
                tem = tem & 1;
                if (tem == 1) {
                    step(0, cols);
                    cnt++;
                    res[0][cols] = 1;
                }
            }
            for (int i = 1; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (curStateBoard[i - 1][j] == 1) {
                        step(i, j);
                        cnt++;
                        res[i][j] = 1;
                    }
                }
            }
            int sum = 0;
            for (int cols = 0; cols < N; cols++) {
                sum += curStateBoard[N - 1][cols];
            }

            if (sum == 0) {
                if (cnt < optCnt) {
                    optCnt = cnt;
                    memcpy(opt, res, sizeof(opt));
                }
            }
        }
        if (optCnt == 0xffffff) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cout << opt[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}


void reverse(int i, int j) {
    if (i < 0 || j < 0 || i >= M || j >= N) {
    } else {
        curStateBoard[i][j] = curStateBoard[i][j] == 1 ? 0 : 1;
    }

}

void step(int i, int j) {
    reverse(i, j);
    for (int index = 0; index < 4; index++) {
        reverse(i + dx[index], j + dy[index]);
    }
}













