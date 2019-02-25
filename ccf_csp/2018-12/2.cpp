//
// Created by zhu on 2019/1/18.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long r, y, g;
long long n;
long long k, t;
const long long NOR = 0;
const long long RED = 1;
const long long YELLOW = 2;
const long long GREEN = 3;

vector<long long> k_list, t_list;
long long curTime = 0;

long long light_type = 0;
long long left_time = 0;

void readData() {
    cin >> r >> y >> g;
    cin >> n;
    for (long long i = 0; i < n; ++i) {
        cin >> k >> t;
        k_list.push_back(k);
        t_list.push_back(t);
    }
}

void costTime(long long roadType, long long time) {
    switch (roadType) {
        case NOR:
            curTime += time;
            break;
        case RED:
            curTime += time;
            break;
        case YELLOW:
            curTime += time + r;
            break;
        case GREEN:
            curTime += 0;
            break;
        default:
            break;
    }
}

void getCurLightType(long long beginRoadType, long long beginLightLeftTime) {
    long long tempTime = 0;
    switch (beginRoadType) {
        case NOR:
            light_type = NOR;
            left_time = beginLightLeftTime;
            return;
        case RED:
            tempTime = r - beginLightLeftTime;
            break;
        case GREEN:
            tempTime = r + g - beginLightLeftTime;
            break;
        case YELLOW:
            tempTime = r + g + y - beginLightLeftTime;
            break;
        default:
            break;
    }
    tempTime += curTime;
    tempTime = tempTime % (r + g + y);
    if (tempTime < r) {
        light_type = RED;
        left_time = r - tempTime;
    } else if (tempTime < r + g) {
        light_type = GREEN;
        left_time = g + r - tempTime;

    } else if (tempTime < r + g + y) {
        light_type = YELLOW;
        left_time = y + g + r - tempTime;
    }
}

int main() {
    readData();
    for (long long i = 0; i < n; i++) {
        k = k_list[i];
        t = t_list[i];
        getCurLightType(k, t);
        costTime(light_type, left_time);
    }
    cout << curTime << endl;
    return 0;
}
