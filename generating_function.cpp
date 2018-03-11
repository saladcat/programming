//
// Created by zhu on 2018/1/22.
//


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

const int lmax = 300;

int main() {
    int c1[lmax + 2], c2[lmax + 2];
    int n;
    while (cin >> n && n) {
        for (int i = 0; i <= n; i++) {
            c1[i] = 1;
            c2[i] = 0;
        }
        for (int i = 2; i <= 17; i++) {


            for (int j = 0; j <= n; j++) {
                for (int k = 0; k + j <= n; k += i * i) {
                    c2[j + k] += c1[j];
                }
            }
            for (int j = 0; j <= n; j++) {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout << c1[n] << endl;
    }
    return 0;
}