//
// Created by zhu on 2018/3/26.
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <fstream>
/*
 * 1000-9999的素数先求出来
 * 对于任意两个素数，中间所有的素数也可以有序的找到
 *
 * */

using namespace std;
bool primeTable[10005];

int stepCnt = 0;
int beginPrime = 0, endPrime = 0;
queue<int> que;

int modifyI2N(int num, int i, int n) {
    int pos[4];
    for (int index = 0; index < 4; index++) {
        pos[index] = num % 10;
        num /= 10;
    }
    pos[i] = n;
    int res = 0;
    for (int index = 0; index < 4; index++) {
        res += pos[index] * pow(10, index);
    }
    return res;
}

void init() {
    for (int num = 1001; num < 10005; num++) {
        primeTable[num] = true;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                primeTable[num] = false;
                break;
            }
        }
    }
}

bool bfs() {
    bool temTable[10005];
    memcpy(temTable, primeTable, sizeof(temTable));
    while (!que.empty()) {
        int curState = que.front();
        que.pop();
        stepCnt++;
        if (curState == endPrime) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            for (int n = 0; n < 10; n++) {
                int nextStep = modifyI2N(curState, i, n);
                if (temTable[nextStep]) {
                    que.push(nextStep);
                    temTable[nextStep] = false;
                }
            }
        }
    }
    return false;
}

int main(void) {
    fstream is("data.dat");
    init();
    int N = 0;
    is >> N;
    for (int line = 0; line < N; line++) {
        is >> beginPrime >> endPrime;
        stepCnt = 0;
        while (!que.empty()) {
            que.pop();
        }
        if (beginPrime == endPrime) {
            cout << 0 << endl;
        } else if (bfs()) {

        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
