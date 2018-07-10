


#include <iostream>
#include <map>

using namespace std;
int n;
int input[120005];
map<int, int> MAP;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        MAP[input[i]]++;
    }
    int cntDelNum = 0;
    for (int i = 0; i < n; i++) {
        bool isFindPair = false;
        for (int j = 0; j < 31; j++) {
            int pairNum = (1 << j) - input[i];
            if (MAP[pairNum] > 1 || (MAP[pairNum] == 1 && pairNum != input[i])) {
                isFindPair = true;
            }
        }
        if (!isFindPair) {
            cntDelNum++;
        }
    }
    cout << cntDelNum << endl;
    return 0;
}