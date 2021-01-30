#include <iostream>
#include <vector>

#define MAX 500
#define parent(x) (x-1)/2

using namespace std;

vector<vector<int>> triangle;
int sums[MAX][MAX] = { 0, };
int depth;

int Find_Max(int* arr) {
    int _max = 0;
    for (int i=0; i<depth; i++) {
        if (_max < arr[i]) {
            _max = arr[i];
        }
    }
    return _max;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> depth;
    for (int i=0; i<depth; i++) {
        vector<int> buffer;
        int temp;
        for (int j=0; j<=i; j++) {
            cin >> temp;
            buffer.push_back(temp);
        }
        triangle.push_back(buffer);
    }
    sums[0][0] = triangle[0][0];
    for (int i=1; i<depth; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0) {
                sums[i][j] = sums[i-1][j]+triangle[i][j];
            }
            else if (j == i) {
                sums[i][j] = sums[i-1][j-1]+triangle[i][j];
            }
            else {
                sums[i][j] = max(sums[i-1][j-1], sums[i-1][j])+triangle[i][j];
            }
        }
    }
    cout << Find_Max(sums[depth-1]);
    return 0;
}