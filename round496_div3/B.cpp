//
// Created by zhu on 2018/7/9.
//

#include <iostream>
#include <string.h>

#define MAX 200005
using namespace std;
char str1[MAX];
char str2[MAX];

int main() {
    cin >> str1 >> str2;
    strrev(str1);
    strrev(str2);
    int output = strlen(str1) + strlen(str2);
    int i = 0;
    while (str1[i] == str2[i] && (i < strlen(str1) && i < strlen(str2))) {
        output -= 2;
        i++;
    }
    cout << output << endl;
    return 0;
}