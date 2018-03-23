//
// Created by zhu on 2018/3/23.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void dfs(void);

struct Point {
    Point(int x0, int y0, int z0) : x(x0), y(y0), z(z0) {}

    int x;
    int y;
    int z;

};


int space[10][10][10];
int X, Y, Z;

int main() {
    while (cin >> Z >> X >> Y && !(X == 0 && Y == 0 && Z == 0)) {
        cin.get();
        for (int k = 0; k < Z; k++) {
            for (int i = 0; i < X; i++) {
                string tem;
                cin >> tem;
                for (int j = 0; j < Y; j++) {
                    space[i][j][k] = tem[j];
                }
            }
        }
    }
}

void dfs(Point curPlace) {
    if ()
}


