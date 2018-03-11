//
// Created by zhu on 2018/2/28.
//
#include<algorithm>
#include<cstring>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

struct Data {
    int _point;
    int _ddl;
};
Data data[1005];
int used[1005];

int main() {
    int T, N;
    fstream is("data.dat");
    cin >> T;
    int i = 0;
    while (i++ < T && cin >> N) {
        memset(data, 0, sizeof(data));
        memset(used, 0, sizeof(used));
        for (int j = 0; j < N; j++) {
            cin >> data[j]._ddl;
        }
        for (int j = 0; j < N; j++) {
            cin >> data[j]._point;
        }
        sort(data, data + N, [](Data data1, Data data2) {
            if (data1._point != data2._point) {
                return data1._point > data2._point;
            } else {
                return data1._ddl < data2._ddl;
            }
        });
        int reducedPoint = 0;
        for (int index = 0; index < N; index++) {
            int do_day = data[index]._ddl;
            while (do_day) {
                if (used[do_day] == 0) {
                    used[do_day] = 1;
                    break;
                } else {
                    do_day--;
                }
            }
            if (do_day == 0) {
                reducedPoint += data[index]._point;
            }
        }
        cout << reducedPoint << endl;
    }
    return 0;
}