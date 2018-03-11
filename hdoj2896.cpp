//
// Created by zhu on 2018/1/24.
//


// Created by zhu on 2018/1/23.
//
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include <queue>
#include <fstream>

using namespace std;
struct Node {
    int cnt;//是否为该单词的最后一个结点
    Node *fail;//失败指针
    Node *next[129];//Trie中每个结点的各个节点
};


void init(Node *root);

void buildTrie(char *keyword, int num);

void buildAcAutomation(Node *root);

int query(Node *root);

Node *Queue[500005];//队列，方便用BFS构造失败指针
char mainStr[10005];//主字符串
char keyword[205];//需要查找的单词
int res[5];//子串编号
Node *root;//头结点

int main() {
    ifstream is("data.dat");
    int N, M;
    root = new Node();
    init(root);
    is >> N;
    for (int i = 1; i <= N; i++) {
        is >> keyword;
        buildTrie(keyword, i);
    }
    buildAcAutomation(root);
    int count = 0;
    is >> M;

    for (int i = 1; i < M; i++) {
        is >> mainStr;
        bool flag = false;
        int num = query(root);
        if (num != 0) {
            flag = true;
            cout << "web " << i << ":";
            sort(res, res + num);
        }
    }
    return 0;
}


void init(Node *root) {//每个结点的初始化
    root->cnt = 0;
    root->fail = nullptr;
    for (int i = 0; i < 26; i++) {
        root->next[i] = nullptr;
    }
}


void buildTrie(char *keyword, int num) {//构建Trie树
    Node *cur, *next;
    int i, nextWord;
    int len = strlen(keyword);
    for (i = 0, cur = root; i < len; i++) {
        nextWord = keyword[i] - 'a';
        if (cur->next[nextWord] == nullptr) {
            next = (struct Node *) malloc(sizeof(Node));
            init(next);
            cur->next[nextWord] = next;//结点链接
        }
        cur = cur->next[nextWord];//指针移动到下一个结点
    }
    cur->cnt++;//单词最后一个结点cnt++，代表一个单词
}

void buildAcAutomation(Node *root) {
    int uBound = 0, lBound = 0;//队列头、尾指针
    Queue[uBound++] = root;//先将root入队
    while (uBound != lBound) {
        Node *reBackPtr = nullptr;
        Node *cur = Queue[lBound++];//弹出队头结点
        for (int i = 0; i < 26; i++) {
            if (cur->next[i] != nullptr) {//找到实际存在的字符结点
                //cur->next[i] 为该结点，temp为其父结点
                if (cur == root) {//若是第一层中的字符结点，则把该结点的失败指针指向root
                    cur->next[i]->fail = root;
                } else {//依次回溯该节点的父节点的失败指针直到某节点的next[i]与该节点相同，
                    //则把该节点的失败指针指向该next[i]节点；
                    //若回溯到 root 都没有找到，则该节点的失败指针指向 root
                    reBackPtr = cur->fail;//将该结点的父结点的失败指针给p
                    while (reBackPtr != nullptr) {
                        if (reBackPtr->next[i] != nullptr) {
                            cur->next[i]->fail = reBackPtr->next[i];
                            break;
                        }
                        reBackPtr = reBackPtr->fail;
                    }
                    //让该结点的失败指针也指向root
                    if (reBackPtr == nullptr) {
                        cur->next[i]->fail = root;
                    }
                }
                Queue[uBound++] = cur->next[i];//每处理一个结点，都让该结点的所有孩子依次入队
            }
        }
    }
}

int query(Node *root) { //i为主串指针，p为模式串指针
    int i, ch, count = 0;
    Node *cur = root;
    int len = strlen(mainStr);
    for (i = 0; i < len; i++) {
        ch = mainStr[i] - 'a';
        //由失败指针回溯查找，判断s[i]是否存在于Trie树中
        while (cur->next[ch] == nullptr && cur != root) {
            cur = cur->fail;
        }
        //cur->next[ch]!=nullptr;
        cur = cur->next[ch];//找到后p指针指向该结点
        if (cur == nullptr) {//若指针返回为空，则没有找到与之匹配的字符
            cur = root;
        }
        Node *temp = cur;//匹配该结点后，沿其失败指针回溯，判断其它结点是否匹配
        while (temp != root)//匹配结束控制
        {
            if (temp->cnt >= 0)//判断该结点是否被访问
            {
                count += temp->cnt;//由于cnt初始化为 0，所以只有cnt>0时才统计了单词的个数
                temp->cnt = -1;//标记已访问过
            } else {//结点已访问，退出循环
                break;
            }
            temp = temp->fail;//回溯 失败指针 继续寻找下一个满足条件的结点
        }
    }
    return count;
}










