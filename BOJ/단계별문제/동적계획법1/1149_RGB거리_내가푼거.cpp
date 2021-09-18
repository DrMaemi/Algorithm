#include <iostream>
#include <vector>

#define MAX 1000
#define parent(x) (x-1)/2
using namespace std;

int n;
vector<int> sums, stack;
int costs[MAX][3];

void print_arr(vector<int> arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void print_all(vector<int> arr, int pos) {
    cout << "pos: " << pos << "\n";
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void dfs(int pos) {
    if (pos == n) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += costs[i][stack[i]];
        }
        sums.push_back(sum);
        cout << "sum: " << sum << "\n";
        return;
    }
    for (int i=0; i<3; i++) {
        if (pos != 0 && i == stack[pos-1]) continue;
        stack.push_back(i);
        print_all(stack, pos);
        dfs(pos+1);
        stack.pop_back();
    }
    return;
}

void swap(vector<int> &arr, int p, int q) {
    int temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}

void min_heapify(vector<int> &arr) {
    int size = arr.size();
    if (size < 2) return;
    int parent, child;
    for (int i=1; i<size; i++) {
        child = i;
        while (child != 0) {
            parent = parent(child);
            if (arr[parent] > arr[child]) {
                swap(arr, parent, child);
                child = parent;
            }
            else break;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin >> costs[i][j];
        }
    }
    dfs(0);
    cout << "After dfs(), vector<int> sums:\n";
    print_arr(sums);
    min_heapify(sums);
    cout << "After min_heapify(), vector<int> sums:\n";
    print_arr(sums);
    cout << sums[0];
    return 0;
}