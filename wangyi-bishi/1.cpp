//
// Created by 朱世杨 on 2019-03-17.
//

#include <iostream>
#include <algorithm>

#define min(a, b) a<b ? a:b

using namespace std;
int W, H;
int N;

struct Rect {
    int w;
    int h;
    double rate;
    int sqr;

    void prt() {
        cout << w << " " << h << " ";
    }
};

Rect input[105];

bool cmp(const Rect &a, const Rect &b) {
    if (a.sqr == b.sqr) {
        if (a.rate == b.rate) {
            return a.w < b.w;
        } else {
            return a.rate < b.rate;
        }
    } else {
        return a.sqr < b.sqr;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> W >> H;
        input[i].w = W;
        input[i].h = H;
        input[i].rate = min(W * 1.0 / H, H * 1.0 / W);
        input[i].sqr = W * H;
    }
    sort(input, input + N, cmp);
    for (int i = 0; i < N; i++) {
        input[i].prt();
    }
    return 0;
}