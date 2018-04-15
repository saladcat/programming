//
// Created by zhu on 2018/3/26.
//
#define ll long long

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

queue<ll> q;

ll bfs(int n) {
    while (!q.empty()) {
        ll divider = q.front();
        q.pop();
        if (divider % n != 0) {
            q.push(divider * 10);
            q.push(divider * 10 + 1);
        } else {
            return divider;
        }
    }
    return 0;
}

int main() {
//    fstream is("data.dat");
    int n;
    while (cin >> n && n != 0) {
        while (!q.empty()) {
            q.pop();
        }
        q.push(1);
        cout << bfs(n) << endl;
    }
    return 0;
}
