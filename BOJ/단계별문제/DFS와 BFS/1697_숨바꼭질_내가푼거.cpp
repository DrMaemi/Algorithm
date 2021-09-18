#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int N, K;
queue<int> q;
bool visited[MAX] = { false, };

int pop_front() {
    int pos = q.front();
    q.pop();
    return pos;
}

bool is_valid_pos(int pos) {
    if (pos < 0 || MAX <= pos || visited[pos])
        return false;
    return true;
}

int solve() {
    int answer = 0;
    bool found = false;
    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            int pos = pop_front();
            if (pos == K) {
                found = true;
                break;
            }
            if (is_valid_pos(pos-1)) {
                q.push(pos-1);
                visited[pos-1] = true;
            }
            if (is_valid_pos(pos+1)) {
                q.push(pos+1);
                visited[pos+1] = true;
            }
            if (is_valid_pos(2*pos)) {
                q.push(2*pos);
                visited[2*pos] = true;
            }
        }
        if (found) break;
        answer++;
    }
    return answer;
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    q.push(N); visited[N] = true;
    cout << solve();
    return 0;
}