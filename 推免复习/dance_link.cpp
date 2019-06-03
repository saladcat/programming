#include <iostream>
#include <stdio.h>
#include <string.h>

const int MN = 1005;
const int MM = 1005;
const int MNN = 1e5 + 5 + MM; //最大点数

struct DLX {//todo
    int n, m, si;//n行数m列数si目前有的节点数
    //十字链表组成部分
    int U[MNN], D[MNN], L[MNN], R[MNN], Row[MNN], Col[MNN];
    //第i个结点的U向上指针D下L左R右，所在位置Row行Col列
    int H[MN], S[MM]; //记录行的选择情况和列的覆盖情况
    int ansd, ans[MN];

    void init(int _n, int _m) { //初始化空表
        n = _n;
        m = _m;
        for (int i = 0; i <= m; i++) //初始化第一横行（表头）
        {
            S[i] = 0;
            U[i] = D[i] = i;      //目前纵向的链是空的
            L[i] = i - 1;
            R[i] = i + 1;         //横向的连起来
        }
        R[m] = 0;
        L[0] = m;
        si = m;                 //目前用了前0~m个结点
        for (int i = 1; i <= n; i++)
            H[i] = -1;
    }

    void link(int r, int c) {//插入点(r,c)
        ++S[Col[++si] = c];     //si++;Col[si]=c;S[c]++;
        Row[si] = r;
        D[si] = D[c];
        U[D[c]] = si;
        U[si] = c;
        D[c] = si;
        if (H[r] < 0)
            H[r] = L[si] = R[si] = si;
        else {
            R[si] = R[H[r]];
            L[R[H[r]]] = si;
            L[si] = H[r];
            R[H[r]] = si;
        }
    }

    void remove(int c)        //列表中删掉c列
    {
        L[R[c]] = L[c];//表头操作
        R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i])
            for (int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
    }

    void resume(int c) {        //恢复c列
        for (int i = U[c]; i != c; i = U[i])
            for (int j = L[i]; j != i; j = L[j])
                ++S[Col[U[D[j]] = D[U[j]] = j]];
        L[R[c]] = R[L[c]] = c;
    }

    bool dance(int d) {//选取了d行
        if (R[0] == 0) {//全部覆盖了
            //全覆盖了之后的操作
            ansd = d;
            return 1;
        }
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i])
            if (S[i] < S[c])
                c = i;
        remove(c);
        for (int i = D[c]; i != c; i = D[i]) {
            ans[d] = Row[i];
            for (int j = R[i]; j != i; j = R[j])
                remove(Col[j]);
            if (dance(d + 1))
                return 1;
            for (int j = L[i]; j != i; j = L[j])
                resume(Col[j]);
        }
        resume(c);
        return 0;
    }
} dlx;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        dlx.init(n, m);
        for (int i = 1; i <= n; i++) {
            int k;
            scanf("%d", &k);
            while (k--) {
                int kk;
                scanf("%d", &kk);
                dlx.link(i, kk);
            }
        }
        dlx.ansd = -1;
        if (dlx.dance(0)) {
            printf("%d", dlx.ansd);
            for (int i = 0; i < dlx.ansd; i++)
                printf(" %d", dlx.ans[i]);
            printf("\n");
        } else
            printf("NO\n");
    }
    return 0;
}