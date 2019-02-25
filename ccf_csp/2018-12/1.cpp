//
// Created by zhu on 2019/1/18.
//

#include <iostream>

using namespace std;


int main(void) {
    int red, yellow, green;
    int n;
    int type, time;
    int totalTime = 0;
    cin >> red >> yellow >> green;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> type >> time;
        int thisTimeCostTime = 0;
        if (type == 3) {//绿

        } else if (type == 2) {//黄
            thisTimeCostTime = time + red;
        } else if (type == 1) {//红
            thisTimeCostTime = time;
        } else if (type == 0) {
            thisTimeCostTime = time;
        }
        totalTime += thisTimeCostTime;
    }
    cout << totalTime << endl;
    return 0;
}
