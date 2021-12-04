#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, M, ans = 0;
    vector<int> nums;
    
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (int i=0; i<N-2; i++) {
        for (int j=i+1; j<N-1; j++) {
            for (int k=j+1; k<N; k++) {
                int sum = nums[i]+nums[j]+nums[k];
                ans = sum <= M? max(ans, sum): ans;
            }
        }
    }

    cout << ans;
    return 0;
}
