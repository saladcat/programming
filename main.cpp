
#include <iostream>

using namespace std;

int main() {
    int x = 1, y = 0;
    if (!x) { y++; }
    else if (x == 0) {
        if (x) { y += 2; }
        else { y += 3; }
    }
    cout << y << endl;
    return 0;
}