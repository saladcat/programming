//
// Created by zhu on 2018/3/10.
//

#include <iostream>
#include <fstream>

#define ll long long

using namespace std;

ll quick_power(ll a, ll b, ll c);

ll dat[45000][2];

int main() {
    int Z, M, H;
//    fstream is("data.dat");
    cin >> Z;
    for (int z = 0; z < Z; z++) {
        cin >> M >> H;
        for (int h = 0; h < H; h++) {
            cin >> dat[h][0] >> dat[h][1];
        }
        ll tem = 0;
        for (int i = 0; i < H; i++) {
            tem = (tem + quick_power(dat[i][0], dat[i][1], M)) % M;
        }
        cout << tem << endl;
    }
    return 0;
}

ll quick_power(ll a, ll b, ll c) {
    if (b == 0) {
        return 1;
    }
    ll tem = quick_power(a, b / 2, c) % c;
    if (b % 2 == 1) {
        return tem * tem * a % c;
    } else {
        return tem * tem % c;
    }
}
