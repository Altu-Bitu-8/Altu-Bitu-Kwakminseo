#include <iostream>
#include <deque>
using namespace std;

int N, K;
deque<int> durability;
deque<bool> robot;

void rotate() {
    durability.push_front(durability.back());
    durability.pop_back();
    robot.push_front(robot.back());
    robot.pop_back();
    robot[N - 1] = false;
}

void move_robots() {
    for (int i = N - 2; i >= 0; i--) {
        if (robot[i] && !robot[i + 1] && durability[i + 1] > 0) {
            robot[i] = false;
            robot[i + 1] = true;
            durability[i + 1]--;
        }
    }
    robot[N - 1] = false;
}

void add_robot() {
    if (!robot[0] && durability[0] > 0) {
        robot[0] = true;
        durability[0]--;
    }
}

int count_zero_durability() {
    int count = 0;
    for (int d : durability)
        if (d == 0) count++;
    return count;
}

int main() {
    cin >> N >> K;
    durability.resize(2 * N);
    robot.resize(N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> durability[i];
    }

    int step = 0;
    while (true) {
        step++;
        rotate();
        move_robots();
        add_robot();
        if (count_zero_durability() >= K) break;
    }

    cout << step << '\n';
    return 0;
}