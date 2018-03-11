//
// Created by zhu on 2018/1/22.
// AC!!!!!!!!!!!!!

#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cstdio>

using namespace std;
const int targetMax = 8000;
const int KIND = 3;

int main() {
    int num[KIND] = {1, 2, 5};
    int uBound[KIND];
    int res[targetMax], nxt[targetMax];
    while (cin >> uBound[0] >> uBound[1] >> uBound[2] &&
           !(uBound[0] == 0 && uBound[1] == 0 && uBound[2] == 0)) {
        int max = uBound[0] + 2 * uBound[1] + 5 * uBound[2];
        memset(res, 0, sizeof(int) * max);
        memset(nxt, 0, sizeof(int) * max);
        for (int i = 0; i <= uBound[0]; i++) {
            res[i] = 1;
        }
        for (int i = 0; i <= uBound[0]; i++) {
            for (int j = 0; j <= uBound[1] * 2; j += 2) {
                nxt[i + j] += res[i];
            }
        }
        for (int i = 0; i <= uBound[1] * 2 + uBound[0] * 1; ++i)       // 看到范围的变化了吗？
        {
            res[i] = nxt[i];
            nxt[i] = 0;
        }

        for (int i = 0; i <= uBound[1] * 2 + uBound[0]; i++) {
            for (int j = 0; j <= uBound[2] * 5; j += 5) {
                nxt[i + j] += res[i];
            }
        }

        int i = 0;
        for (i = 0; i <= max; i++) {
            if (nxt[i] == 0) {
                cout << i << endl;
                break;
            }
        }
        if (i == max + 1) {
            cout << i << endl;
        }
    }
    return 0;
}












