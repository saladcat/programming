//
// Created by 朱世杨 on 2019-03-23.
//
// k个数组
// 每个数组是n个元素的有序序列
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>

#define KMAX 100;
#define NMAX 100;
int k, n;
using namespace std;

struct Node {
    int queueIndex;
    int value;

    bool operator<(const Node &node) {
        return this->value < node.value;
    }

};

int main(void) {
    cin >> k >> n;
    priority_queue<Node> priQue;
    vector<list<int> > input;
    vector<int> res;
    for (int i = 0; i < k; i++) {
        list<int> line;
        int tempNum;
        for (int j = 0; j < n; j++) {
            cin >> tempNum;
            line.push_back(tempNum);
        }
        input.push_back(line);
    }

    for (int i = 0; i < k; i++) {
        int tempNum = input[k].front();
        input[k].pop_front();
        auto ptr = new Node();
        ptr->queueIndex = k;
        ptr->value = tempNum;
        priQue.push(*ptr);
    }

    while (!priQue.empty()) {
        Node node = priQue.top();
        priQue.pop();
        res.push_back(node.value);
        if (!input[node.queueIndex].empty()) {
            int tempNum = input[node.queueIndex].front();
            auto ptr = new Node();
            ptr->queueIndex = node.queueIndex;
            ptr->value = tempNum;
            priQue.push(*ptr);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}