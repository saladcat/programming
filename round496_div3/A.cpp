//
// Created by zhu on 2018/7/9.
//
//WA

#include<iostream>
#include <vector>

using namespace std;
vector<int> output;

int main(void) {
    int n;
    cin >> n;
    int pre = -1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (pre != -1 && cur == 1) {
            output.push_back(pre);
        }
        pre = cur;
    }
    output.push_back(cur);
    cout << output.size() << endl;
    for (auto &item:output) {
        cout << item << ' ';
    }
    return 0;
}