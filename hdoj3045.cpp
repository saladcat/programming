#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
long long sum[500005];
long long a[500005], queue[500005], dp[500005];

long long getx(long long x) {
    return a[x + 1];
}

long long gety(long long x) {
    return dp[x] - sum[x] + x * a[x + 1];
}

long long cross(long long x1, long long y1, long long x2, long long y2, long long x3,
                long long y3) {
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

int main() {
    long long i, j, k, n, m, head, tail;              //dp[i]为到第i个数的最小值
    while (scanf("%lld%lld", &n, &m) !=
           EOF) {      //dp[i]=min(dp[j]+(sum[i]-sum[j]-(i-j)*a[j+1]));
        for (i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + n + 1);
        sum[0] = 0;
        for (i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        dp[0] = 0;
        head = tail = 0;
        queue[tail++] = 0;
        for (i = 1; i <= n; i++) {
            k = i;
            while ((head + 1 < tail) && ((gety(queue[head + 1]) - gety(queue[head])) <=
                                         k *
                                         (getx(queue[head + 1]) - getx(queue[head])))) {
                head++;
            }                             //找切点
            dp[i] = gety(queue[head]) - k * getx(queue[head]);
            dp[i] += sum[i];
            j = i - m + 1;                            //一定要注意，只有当j>T时才会用到之前的dp值
            if (j < m) {                             //也就是这时候才会更新凸包，而且一次只能添加
                continue;                            //一个，否则可能最优值会被删掉
            }
            while ((head + 1 < tail) &&
                   cross(getx(queue[tail - 2]), gety(queue[tail - 2]),
                         getx(queue[tail - 1]), gety(queue[tail - 1]),
                         getx(j), gety(j)) <= 0ll) {
                tail--;
            }
            queue[tail++] = j;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}