//
// Created by zhu on 2018/1/23.
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include <fstream>

using namespace std;
const int MAX = 17;
int pre[300 + 10];
int nxt[300 + 10];

int main() {
//    ifstream is("data.dat");
    int KIND[MAX];
    for (int i = 0; i < MAX; i++) {
        KIND[i] = (i + 1) * (i + 1);
    }
    int target;
    memset(pre, 0, sizeof(pre));
    memset(nxt, 0, sizeof(nxt));
    while (cin >> target && target != 0) {
        for (int i = 0; i <= target; i++) {
            pre[i] = 1;
        }
        for (int i = 1; i < MAX; i++) {

            for (int j = 0; j * KIND[i] <= target; j++) {
                for (int k = 0; k + j * KIND[i] <= target; k++) {
                    nxt[k + j * KIND[i]] += pre[k];
                }
            }
            memcpy(pre, nxt, sizeof(pre));
            memset(nxt, 0, sizeof(nxt));
        }
        cout << pre[target] << endl;
    }
    return 0;
}


