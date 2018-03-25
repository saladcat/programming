#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int visit[100005] = {0};

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(visit, 0, sizeof(visit));
        queue<int> q;
        q.push(n);
        int t;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            if (t == m) {
                break;
            }
            if (t > 0 && !visit[t - 1]) {
                int z;
                z = t - 1;
                visit[z] = visit[t] + 1;
                q.push(z);
            }
            if (t < m && !visit[t + 1]) {
                int z;
                z = t + 1;
                visit[z] = visit[t] + 1;
                q.push(z);
            }
            if (t * 2 < 100005 && !visit[t * 2]) {
                int z;
                z = t * 2;
                visit[z] = visit[t] + 1;
                q.push(z);
            }
        }
        printf("%d\n", visit[m]);
    }
    return 0;
}
