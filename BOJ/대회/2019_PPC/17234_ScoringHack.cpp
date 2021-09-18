#include <iostream>
#include <queue>
using namespace std;
typedef struct player {
    int s;
    int t;
} pl;
typedef struct pair {
    pl me;
    pl op;
} p;

int n, a, b, answer;
queue<p> q;
int visited[600][600][10];

p q_pop() {
    p fr = q.front();
    q.pop(); return fr;
}

p win(p state) {
    state.me.s += a;
    state.op.s += b;
    return state;
}

p lose(p state) {
    state.me.s += b;
    state.op.s += a;
    return state;
}

p cheat_w(p state) {
    state.me.s *= 2; state.me.t++;
    state.op.s += b;
    return state;
}

p cheat_l(p state) {
    state.me.s *= 2; state.me.t++;
    state.op.s += a;
    return state;
}

bool is_valid(p state) {
    if (n+a <= state.me.s || n+a <= state.op.s || (answer+1)/10 < state.me.t)
        return false;
    if (visited[state.me.s][state.op.s][state.me.t])
        return false;
    visited[state.me.s][state.op.s][state.me.t] = true;
    return true;
}

bool is_finished(p state) {
    if (n <= state.me.s || n <= state.op.s)
        return true;
    return false;
}

int solve() {
    answer = 0; p next; bool finished = false;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            p state = q_pop();
            if (is_finished(state)) {
                finished = true; break;
            }
            next = win(state);
            if (is_valid(next)) q.push(next);
            next = lose(state);
            if (is_valid(next)) q.push(next);
            next = cheat_w(state);
            if (is_valid(next)) q.push(next);
            next = cheat_l(state);
            if (is_valid(next)) q.push(next);
        }
        if (finished) break;
        answer++;
    }
    return answer;
}

int main(void) {
    cin >> n >> a >> b;
    pl me = {0, 0}, op = {0, 0};
    p init = {me, op};
    q.push(init);
    cout << solve();
    return 0;
}