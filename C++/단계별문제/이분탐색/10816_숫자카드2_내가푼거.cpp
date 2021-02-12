#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500000
#define parent(x) (x-1)/2

int N, M;
int cnt = 0;
int* numbers;
int* targets;

int* malloc_1d_arr(int size) {
    int* _1d_arr = (int*)malloc(sizeof(int)*size);
    return _1d_arr;
}

void input() {
    cin >> N;
    numbers = malloc_1d_arr(N);
    for (int i=0; i<N; i++) {
        cin >> numbers[i];
    }
    cin >> M;
    targets = malloc_1d_arr(M);
    for (int i=0; i<M; i++) {
        cin >> targets[i];
    }
}

int solve(int target) {
    int lowerbound_idx, upperbound_idx;
    int start, mid, end;
    start = 0; end = N-1;
    while (start <= end) {
        mid = (start+end)/2;
        if (target <= numbers[mid]) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    lowerbound_idx = end;
    start = 0; end = N-1;
    while (start <= end) {
        mid = (start+end)/2;
        if (numbers[mid] <= target) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    upperbound_idx = start;
    int answer = upperbound_idx-lowerbound_idx;
    if (!answer) {
        if (numbers[lowerbound_idx+1] == target) {
            return 1;
        }
    }
    return answer-1;
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    input();
    sort(numbers, numbers+N);
    for (int i=0; i<M; i++) {
        cout << solve(targets[i]) << " ";
    }
    return 0;
}