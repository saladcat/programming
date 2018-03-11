//
// Created by zhu on 2018/3/10.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int dat[105][105];

int main() {
    int N;
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        memset(dat, 0, sizeof(dat));
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> dat[i][j];
            }
        }
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dat[i][j] += max(dat[i + 1][j], dat[i + 1][j + 1]);
            }
        }
        cout << dat[0][0] << endl;
    }
    return 0;
}