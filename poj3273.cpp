//
// Created by zhu on 2018/3/5.
//

#include <iostream>
#include <algorithm>
#include <fstream>


using namespace std;

bool C(int mid);

const int maxN = 100005;
int n, m;
int money[maxN];

int main() {
//    fstream is("data.dat");
    cin >> n >> m;
    int maxDayCost = -1;
    int sum = 0;
    for (int index = 0; index < n; index++) {
        cin >> money[index];
        maxDayCost = std::max(maxDayCost, money[index]);
        sum += money[index];
    }
    int lowBound = maxDayCost;
    int highBound = sum;
    int mid = (lowBound + highBound) / 2;
    while (lowBound < highBound) {
        if (C(mid)) {
            lowBound = mid + 1;
        } else {
            highBound = mid - 1;
        }
        mid = (lowBound + highBound) / 2;
    }

    cout << mid << endl;
    return 0;
}

bool C(int mid) {//测试如果最大值是mid能分多少组，如果分的组太多了，说明mid小了
    int sum = 0, count = 1;
    for (int i = 0; i < n; i++) {
        if (money[i] + sum <= mid) {
            sum += money[i];
        } else {
            sum = money[i];
            count++;
        }
    }
    return count > m;
}
