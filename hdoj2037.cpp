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

struct Items {
    int begin;
    int end;
};


Items data[105];

int main() {
    int n;
//    fstream is("data.dat");
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> data[i].begin >> data[i].end;
        }
        // 读入数据
        sort(data, data + n, [](Items data1, Items data2) {
            return data1.end < data2.end;
        });
        int cur = data[0].end;
        int sum = 1;
        for (int index = 1; index < n; index++) {
            if (cur <= data[index].begin) {
                sum += 1;
                cur = data[index].end;
            }
        }
        cout << sum << endl;
    }
    return 0;
}