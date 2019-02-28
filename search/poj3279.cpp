//
// Created by zhu on 2018/3/25.
//
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

int matrix[15][15]; //表示每个点初识状态
int curMatrix[15][15]; //表示每个点的状态
int stepMatrix[15][15]; //标记每个点是否踩过
int stepCnt = 0; //踩过的次数
int minStepCnt = 99999; //所有情况中踩过次数最小的
int minStepMatrix[15][15];
int M, N;

void init() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
//            cout << matrix[i][j] << " ";
        }
//        cout << endl;
    }

}

void turn(int i, int j) {
    if (i < 0 || i >= M ||
        j < 0 || j >= N) {
        return;
    } else {
        curMatrix[i][j] = (curMatrix[i][j] == 0) ? 1 : 0;
    }
}

void step(int i, int j) {
    stepCnt++;
    stepMatrix[i][j] = 1;
    turn(i, j);
    turn(i - 1, j);
    turn(i, j - 1);
    turn(i, j + 1);
    turn(i + 1, j);
}


void solve() {
    int comp = 0;
    for (comp = 0; comp < 1 << N; comp++) {//状态压缩
        bool isPossible = true;
        memcpy(curMatrix, matrix, sizeof(matrix));
        memset(stepMatrix, 0, sizeof(stepMatrix));
        stepCnt = 0;
        int tempCode = comp;
        for (int i = N - 1; i >= 0; --i) {
            int isStep = tempCode % 2;
            tempCode = tempCode / 2;
            if (isStep == 1) {
                step(0, i);
            }
        }//针对第一行不同的状态进行后续操作

        for (int i = 1; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (curMatrix[i - 1][j] == 1) {//观察上方的点是否为0
                    step(i, j);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (curMatrix[M - 1][i] == 1) {//观察最后一行，能否翻过来
                isPossible = false;
            }
        }

        if (isPossible) {
            if (stepCnt < minStepCnt) {//是否为最小的
                memcpy(minStepMatrix, stepMatrix, sizeof(stepMatrix));
                minStepCnt = stepCnt;
            }
        }
    }
}

int main(void) {
    init();
    solve();
    if (minStepCnt < 9999) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << minStepMatrix[i][j];
                if (j != N - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}