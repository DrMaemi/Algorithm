#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 0;
vector<int> nums;

void f(int depth, int pos, int sum) {
    if (depth == 3) {
        ans = sum <= M? max(ans, sum): ans;
        return;
    }

    for (int i=pos; i<N; i++)
        f(depth+1, i+1, sum+nums[i]);
}

int main() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    f(0, 0, 0);
    cout << ans;

    return 0;
}
