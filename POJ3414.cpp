//
// Created by zhu on 2018/4/15.
//

#include <iostream>

/*
 * 一个class-Node 储存当前步数和上一次的行为
 * 一个数组，Node* （board[i][j]） 表示 A，B的水量为i,j时最小的步数，如果是nullptr就是没到过
 * 行为：1. 灌满A 2.灌满B 3.倒掉A 4. 倒掉B 5.把水从A倒到B 6. 把水从B倒到A
 *
 *
 *
 * */
using namespace std;

struct Node {
    int cntStep;
    int lastAct;

};

int main() {
    while
}