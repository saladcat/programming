//
// Created by 朱世杨 on 2019-06-02.
//
#include <iostream>

#define A "A"
#define B "B"
#define C "C"

/*
 * 汉诺塔问题是一个经典的问题。汉诺塔（Hanoi Tower），又称河内塔，源于印度一个古老传说。
 * 大梵天创造世界的时候做了三根金刚石柱子，
 * 在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。
 * 大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，任何时候，
 * 在小圆盘上都不能放大圆盘，且在三根柱子之间一次只能移动一个圆盘。问应该如何操作？
 * ABC,开始在A，想要移动到C
*/
using namespace std;


void movePlanet(int num, string src, string medium, string dest) {
    if (num > 0) {
        movePlanet(num - 1, src, dest, medium);
        cout << "move disk from " + src + " to " + dest + " through " + medium << endl;
        movePlanet(num - 1, medium, src, dest);
    }
}


int main() {
    movePlanet(3, A, B, C);
    return 0;
}

















