//
// Created by zhu on 2018/1/22.
// WA!!!!!!!!!!!!!!!

#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cstdio>
#include <fstream>

#define MAX 100000
using namespace std;
struct Data {
    int num;
    int value;
} dad;


int main() {
    int KIND = 0;

    int pre[MAX];
    int cur[MAX];
    ifstream is("data.dat");
    Data data[1000];
    while (is >> KIND && KIND >= 0) {
        int sum = 0;
        for (int i = 0; i < KIND; i++) {
            is >> data[i].value >> data[i].num;
            sum += data[i].value * data[i].num;
        }
        memset(pre, 0, sizeof(pre));
        memset(cur, 0, sizeof(cur));
        for (int i = 0; i <= data[0].num; i++) {
            pre[i * data[0].value] = 1;
        }
        for (int i = 1; i < KIND; i++) {
            for (int j = 0; j <= data[i].num && j * data[i].value <= sum; j++) {
                for (int k = 0; k + j * data[i].value <= sum; k++) {
                    cur[k + j * data[i].value] += pre[k];
                }
            }
            memcpy(pre, cur, sizeof(int) * sum);
            memset(cur, 0, sizeof(int) * sum);
        }
        int first = static_cast<int>(ceil(sum / 2));
        for (; pre[first] == 0; first++);
        if (first > sum - first) {
            cout << first << " " << sum - first << endl;
        } else {
            cout << sum - first << " " << first << endl;
        }
    }
    return 0;
}
