// DrMaemi - 8176KB, 676ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> A;

    cin >> N;

    for (int i=0; i<N; i++) {
        int tmp;
        
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());

    for (int i=0; i<N; i++)
        cout << A[i] << "\n";

    return 0;
}