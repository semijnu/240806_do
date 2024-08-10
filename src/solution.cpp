#include <iostream>
#include <vector>
using namespace std;

bool isRobotReturnOrigin(vector<char> instructions) {
    int x = 0, y = 0, dir = 0;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    for (char instruction : instructions) {
        if (instruction == 'G') {
            x += directions[dir][0];
            y += directions[dir][1];
        } else {
            dir = (dir + (instruction == 'L' ? 3 : 1)) % 4;
        }
    }
    
    return x == 0 && y == 0;
}

int main() {
    vector<char> instructions = {'G', 'L', 'G', 'R', 'G', 'G', 'L', 'R', 'G'};
    cout << (isRobotReturnOrigin(instructions) ? "True" : "False") << endl;
    return 0;
}